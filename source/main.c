/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "includes.h"
#include "Common_Macro.h"
#include "Type.h"
#include "Debug.h"

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "peripherals.h"
#include "board.h"
#include "fsl_pwm.h"
#include "fsl_dac.h"
#include "fsl_device_registers.h"

#include "freemaster.h"
#include "freemaster_serial_qsci.h"

#include "DCDC_Controller.h"
#include "StateMachine.h"
#include "LLC_Fault.h"
#include "PushPull_Fault.h"

#include "gdflib.h"

#include "pin_config.h"

/* Predefined Or Compiler Option ---------------------------------------------*/
#define ENABLE_RECORD
#define MODEL_IS_LLC
//#define MODEL_IS_BATT_To_BULK380V

/* Private Typedef -----------------------------------------------------------*/
typedef enum {
  LLC = 1,
  PUSH_PULL
}Model_t;

typedef struct {
  frac16_t i_bat;
  frac16_t i_llc;
  frac16_t v_out_fb;

  frac16_t v_bat_fb; 
  frac16_t otp_s;
}ADC_t;


////////////////////////////////////////////////////////////////////////////////
// Local macros define what QSCI port is used
////////////////////////////////////////////////////////////////////////////////

#if 1
/* Use SCI_0 at Boot_SCI USB-to-serial port */
#define BOARD_FMSTR_UART_INSTANCE   0
#define BOARD_FMSTR_UART_CLOCK_NAME kCLOCK_QSCI0
#else
/* Use SCI_2 at OSBDM virtual serial port */
#define BOARD_FMSTR_UART_INSTANCE   2
#define BOARD_FMSTR_UART_CLOCK_NAME kCLOCK_QSCI2
#endif

/* SCI base address */
#define BOARD_FMSTR_UART_BASE_ADDR qsciBases[BOARD_FMSTR_UART_INSTANCE]

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define GA5_High()   Debug_Io_High(GPIOA, kGPIO_Pin5)
#define GA5_Low()    Debug_Io_Low(GPIOA, kGPIO_Pin5)
#define GA5_Toggle() Debug_Io_Toggle(GPIOA, kGPIO_Pin5)

#define GA6_High()   Debug_Io_High(GPIOA, kGPIO_Pin6)
#define GA6_Low()    Debug_Io_Low(GPIOA, kGPIO_Pin6)
#define GA6_Toggle() Debug_Io_Toggle(GPIOA, kGPIO_Pin6)

#define GA7_High()   Debug_Io_High(GPIOA, kGPIO_Pin7)
#define GA7_Low()    Debug_Io_Low(GPIOA, kGPIO_Pin7)
#define GA7_Toggle() Debug_Io_Toggle(GPIOA, kGPIO_Pin7)


/* The PWM base address */
// #define BOARD_PWM_BASEADDR  PWMA
#define PWM_SRC_CLK_DIV     kPWM_ClockPrescaleDivide1
// #define PWM_SRC_CLK_FREQ    (CLOCK_GetIpClkSrcFreq(kCLOCK_PWMACH0) / (1U << kPWM_ClockPrescaleDivide1))
#define PWM_IP_BUS_CLK_FREQ CLOCK_GetIpClkSrcFreq(kCLOCK_PWMACH0)
#define DEMO_FAULT_CHANNEL  0U
#define DEMO_FAULT_MAP              \
    (pwm_sm_fault_input_mapping_t)  \
    {                               \
        .bFaultInput0Mapping = true \
    }
/* Definition for default PWM frequency in HZ. */
#ifndef APP_DEFAULT_PWM_FREQUENCE
#define APP_DEFAULT_PWM_FREQUENCE (1000UL)
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void ADC_A_IRQHANDLER(void);
void PIT0_IRQHANDLER(void);
void CMPA_IRQHANDLER(void);
void CMPB_IRQHANDLER(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if defined(MODEL_IS_LLC)
static Model_t model = LLC;
static uint32_t Version = 0x01110003;
#else
static Model_t model = PUSH_PULL;
static uint32_t Version = 0x01090000;
#endif

static ADC_t gADC;

static uint32_t prvFrequency = 0;
static uint8_t prvRatio = 3;
static uint16_t Period = 0;
static uint16_t Pulse = 0;
static uint16_t gTargetAdc = 2048;

frac16_t f16InitVal;
GDFLIB_FILTER_MA_T_A32 psVoutParam;
GDFLIB_FILTER_MA_T_A32 psIbatParam;
GDFLIB_FILTER_MA_T_A32 psVbatParam;
GDFLIB_FILTER_MA_T_A32 psIllcParam;

// array of all QSCI base addresses
const QSCI_Type *qsciBases[] = QSCI_BASE_PTRS;

#ifdef ENABLE_RECORD
#define RECORD_LENGTH (256)
u16 gRecordIndex = 0;
u8 gRecordTrigger = 0;
static frac16_t i_bat_adc[RECORD_LENGTH];
static frac16_t i_llc_adc[RECORD_LENGTH];
static frac16_t v_out_fb_adc[RECORD_LENGTH];
static frac16_t v_bat_fb_adc[RECORD_LENGTH];
static frac16_t otp_s_adc[RECORD_LENGTH];

static frac16_t v_bat_filter[RECORD_LENGTH];
static frac16_t v_out_filter[RECORD_LENGTH];
static frac16_t i_llc_filter[RECORD_LENGTH];
static frac16_t i_bat_filter[RECORD_LENGTH];
static frac16_t gCommand[RECORD_LENGTH];
#endif


u8 gOnOffToggle = 0;

//! Note: All global variables accessed by FreeMASTER are defined in a shared
//! freemaster_example.c file

/*******************************************************************************
 * Code
 ******************************************************************************/
/* kADC12_CC0_VECTORn interrupt handler */
#pragma section CODES_IN_RAM begin
#pragma interrupt alignsp saveall
void ADC_A_IRQHANDLER(void) {
  uint16_t status_flags;
  /* Get and clear status interrupt flags */
  status_flags = ADC->STAT & ADC_STAT_EOSI0_MASK;
  ADC->STAT |= status_flags;
  
  /* End of scan */
  if((status_flags & ADC_STAT_EOSI0_MASK) != 0U) {
    /* Place your code here */
    gADC.i_bat = ADC->RSLT[0];
    gADC.i_llc = ADC->RSLT[1];
    gADC.v_out_fb = ADC->RSLT[2];

    gADC.v_bat_fb = ADC->RSLT[9];
    gADC.otp_s = ADC->RSLT[10];
    
    DAC_WriteDataFIFO(DACA, gADC.i_bat>>3);
    DAC_WriteDataFIFO(DACB, gADC.v_out_fb>>3);

    gVdc = GDFLIB_FilterMA_F16(gADC.v_out_fb, &psVoutParam);
    gIdc = GDFLIB_FilterMA_F16(gADC.i_bat, &psIbatParam);
    gVbat = GDFLIB_FilterMA_F16(gADC.v_bat_fb, &psVbatParam);
    gIllc = GDFLIB_FilterMA_F16(gADC.i_llc, &psIllcParam);

    gStateMachineList[gState].outter_loop();

    #ifdef ENABLE_RECORD
    i_bat_adc[gRecordIndex] = gADC.i_bat;
    i_llc_adc[gRecordIndex] = gADC.i_llc;
    v_out_fb_adc[gRecordIndex] = gADC.v_out_fb;
    v_bat_fb_adc[gRecordIndex] = gADC.v_bat_fb;
    otp_s_adc[gRecordIndex] = gADC.otp_s;

    v_out_filter[gRecordIndex] = gVdc;
    v_bat_filter[gRecordIndex] = gVbat;    
    i_llc_filter[gRecordIndex] = gIllc;
    i_bat_filter[gRecordIndex] = gIdc;

    gCommand[gRecordIndex] = gFrequency;

    gRecordIndex++;
    if(gRecordIndex == RECORD_LENGTH){
      gRecordIndex = 0;
      gRecordTrigger++;
    }
    #endif
  } 
}
#pragma interrupt off
#pragma section CODES_IN_RAM end


/* kCMPA_VECTORn interrupt handler */
#pragma section CODES_IN_RAM begin
#pragma interrupt alignsp saveall
void CMPA_IRQHANDLER(void) {  // OCP
  /* Get interrupt flags */
  uint8_t flags = CMPA->SCR & (CMP_SCR_CFR_MASK | CMP_SCR_CFF_MASK);
  /* Clear all interrupt flags */
  CMPA->SCR |= flags;
  /* Rising-edge on the comparison output occurence */
  if((flags & CMP_SCR_CFR_MASK) != 0U) {
    /* Place your code here */
    ChangeState(LLC_FAULT_STATE);
    gSysFaultFlag.ocp = 1;
  }
  /* Falling-edge on the comparison output occurence */
  if((flags & CMP_SCR_CFF_MASK) != 0U) {
    /* Place your code here */
    ChangeState(LLC_FAULT_STATE);
    gSysFaultFlag.ocp = 1;
  }
}
#pragma interrupt off
#pragma section CODES_IN_RAM end

/* kCMPB_VECTORn interrupt handler */
#pragma section CODES_IN_RAM begin
#pragma interrupt alignsp saveall
void CMPB_IRQHANDLER(void) {  // OVP
  /* Get interrupt flags */
  uint8_t flags = CMPB->SCR & (CMP_SCR_CFR_MASK | CMP_SCR_CFF_MASK);
  /* Clear all interrupt flags */
  CMPB->SCR |= flags;
  /* Rising-edge on the comparison output occurence */
  if((flags & CMP_SCR_CFR_MASK) != 0U) {
    /* Place your code here */
    ChangeState(LLC_FAULT_STATE);
    gSysFaultFlag.ovp = 1;
  }
  /* Falling-edge on the comparison output occurence */
  if((flags & CMP_SCR_CFF_MASK) != 0U) {
    /* Place your code here */
  }

}
#pragma interrupt off
#pragma section CODES_IN_RAM end

/*!
 * @brief Main function
 */
int main(void)
{
    /* Board pin, clock, debug console initial */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    // Init All HW Config
    Pin_Init();

    SetIRQBasePriority(0);

    if(model && Version)
    {
      /* Register communication module used by FreeMASTER driver. */
      FMSTR_SerialSetBaseAddress((QSCI_Type *)BOARD_FMSTR_UART_BASE_ADDR);

      FMSTR_Init();
    }

    PWM_SetPwmLdok(PWMA, kPWM_SubModule0Enable | kPWM_SubModule1Enable);

    /* Start the PWM generation counter for Submodules 0, 1 */
    PWM_EnableCounters(PWMA, kPWM_SubModule0Enable | kPWM_SubModule1Enable);

    DCDC_Init();
    gState = LLC_HW_INIT_STATE;

    /* Filter window = 2 ^ 5 = 32 points */
    psVoutParam.u16Sh = 5;
    psIbatParam.u16Sh = 5;
    psVbatParam.u16Sh = 5;
    psIllcParam.u16Sh = 5;
    GDFLIB_FilterMAInit_F16(FRAC16(0.0), &psVoutParam);
    GDFLIB_FilterMAInit_F16(FRAC16(0.0), &psIbatParam);
    GDFLIB_FilterMAInit_F16(FRAC16(0.0), &psVbatParam);
    GDFLIB_FilterMAInit_F16(FRAC16(0.0), &psIllcParam);

    initSysGpio();

    while (1U)
    {
      gMainRunningCount++;
      if (gMainRunningCount % 1536) {
        ScanButtons();
        if (gMainRunningCount >= 15360) {
          gMainRunningCount = 0;
        }
      }

      gStateMachineList[gState].main_loop();
      FMSTR_Poll();
    }
}
