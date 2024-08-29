/** 
 ******************************************************************************
 * @file    : DCDC_Controller.h
 * @version	: V0.0.1
 * @date    : 2022.07.25
 * @author	: aidan.lu
 ******************************************************************************
 *
 *
 *
 ****************************************************************************** 
 */
 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DCDC_CONTROLLER_H_
#define _DCDC_CONTROLLER_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "fsl_pwm.h"

#include "gflib.h"
#include "gdflib.h"
#include "mlib.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
#define PWM_SRC_CLK_FREQ 100000000UL

#define DCDC_CV_UPPER_LIMIT    FRAC16(1.0) 	/* Constant Voltage controller upper limit */
#define DCDC_CV_LOWER_LIMIT    FRAC16(0.0)     /* Constant Voltage  controller lower limit */
#define DCDC_CV_P_GAIN         ACC32(0.0001)    /* Constant Voltage  controller proportional gain */
#define DCDC_CV_I_GAIN         ACC32(0.0015)    /* Constant Voltage  controller integral gain */

#define DCDC_CC_UPPER_LIMIT    FRAC16(1.0)  /* Constant Current controller upper limit */
#define DCDC_CC_LOWER_LIMIT    FRAC16(-1.0)     /* Constant Current controller lower limit */
#define DCDC_CC_P_GAIN         ACC32(0.0001)    /* Constant Current controller proportional gain */
#define DCDC_CC_I_GAIN         ACC32(0.0001)    /* Constant Current controller integral gain */

#define SOFT_START_TIME 1
#define VBAT_58V_INDEX FRAC16(0.911007)
// #define VBAT_58V_INDEX FRAC16(0.83099)
#define VBAT_50V_INDEX FRAC16(0.80609)

#define BURST_MODE_OFF_INDEX FRAC16(0.931007)
// #define BURST_MODE_OFF_INDEX FRAC16(0.860977)


  #define UP_FREQ (200000)
  #define LOW_FREQ (50000)

/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
#define FrequenceToWPMCounterValue(frequency) (uint16_t)(PWM_SRC_CLK_FREQ / frequency)

/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
extern frac16_t gFrequency;

extern frac16_t gVoltageCommand;
extern bool_t gStopIntegFlag;

extern frac16_t gVdc;
extern frac16_t gIdc;
extern frac16_t gVbat;
extern frac16_t gIllc;

extern volatile frac16_t gCV_Ref;
extern GFLIB_CTRL_PI_P_AW_T_A32 gVoltagePiParams;
extern frac16_t gCV_Command;

extern frac16_t gCC_Ref;
extern GFLIB_CTRL_PI_P_AW_T_A32 gCurrentPiParams;
extern frac16_t gCC_Command;

extern uint8_t gBurstTurnOn;

/* Public Function -----------------------------------------------------------*/
extern void DCDC_Init(void);

static inline void Update_PWM(frac16_t input){
  #define UP_FREQ_COUNT ((float)(PWM_SRC_CLK_FREQ/UP_FREQ))
  #define LOW_FREQ_COUNT ((float)(PWM_SRC_CLK_FREQ/LOW_FREQ))

  #define CONST FRAC16((LOW_FREQ_COUNT - UP_FREQ_COUNT) / 32767.0f)
  #define BASE FRAC16(UP_FREQ_COUNT/32767.0f)

  /* Make submodule 0 be a 50% duty cycle center-aligned PWM signal */
  /*
    0 -> UP_FREQ 
    1 -> LOW_FREQ
    
    Equ = BASE + input * CONST
  */  

  volatile register frac16_t Period;
  volatile register frac16_t tmp;
  volatile register frac16_t delay_count;
  volatile register uint16_t duty_round = 0;

  tmp = MLIB_Mul_F16(input, CONST);   // input * CONST
  Period = MLIB_Add_F16(BASE, tmp); // BASE + input * CONST

  PWMA->MCTRL |= PWM_MCTRL_CLDOK(3);  // SM0, SM1

  duty_round = (uint16_t)MLIB_Sh1R_F16(Period);  // duty is half period
  
  // update period for submodule0 and submodule1
  PWMA->SM[kPWM_SubModule0].VAL1 = Period;
  PWMA->SM[kPWM_SubModule1].VAL1 = Period;

  // LLC_1
  PWMA->SM[kPWM_SubModule0].VAL2 = 0;
  PWMA->SM[kPWM_SubModule0].VAL3 = duty_round;

// AE_ON_DT measure actual x1.35 to meet 200nsec spec
#define SR_ON_DT   (20+7)  // 200 is 200ns  (PWM clock is 100MHz, 20 = 200ns / (1/100MHz))
#define SR_OFF_DT  20  // 200 is 200ns  (PWM clock is 100MHz, 20 = 200ns / (1/100MHz))
#define SR_MAX_DT  500 // 500 is 5 us  (PWM clock is 100MHz, 500 = 5us / (1/100MHz))
  
  // submodule 1 share same DTCNT0 at default
  // modify deadtime for SR_ON by adding SR_ON_DT

  // SR deadtime control calcuation
  uint16_t SR_V2 = (uint16_t)SR_ON_DT + PWMA->SM[kPWM_SubModule0].DTCNT0;

  uint16_t SR_V3 = PWMA->SM[kPWM_SubModule0].VAL3 - (uint16_t)SR_OFF_DT;

  if (SR_V3 <= SR_V2) {
    // off condition, conduct with body diode?
    SR_V2 = 9999;
    SR_V3 = 0;
  } else {
    if ((SR_V3 - SR_V2) > SR_MAX_DT) {
      // constant SR ON Duration, at what operating freq? undefined
      // SR_V3 = SR_V2 + SR_MAX_DT;
    }
  }
  // update submodule1 (SR_PWM1) deadtime center-aligned duty
  PWMA->SM[kPWM_SubModule1].VAL2 = SR_V2;
  PWMA->SM[kPWM_SubModule1].VAL3 = SR_V3;
  // update submodule1 (SR_PWM2) deadtime center-aligned duty (+half period)
  PWMA->SM[kPWM_SubModule1].VAL4 = duty_round + PWMA->SM[kPWM_SubModule1].VAL2;
  PWMA->SM[kPWM_SubModule1].VAL5 = duty_round + PWMA->SM[kPWM_SubModule1].VAL3;

  PWM_SetPwmLdok(PWMA, kPWM_SubModule0Enable| kPWM_SubModule1Enable);
}

static void DCDC_VoltageControlLoop(void){
  frac16_t error =  MLIB_SubSat_F16(gCV_Ref, gVdc);
  gCV_Command = GFLIB_CtrlPIpAW_F16(error, &gStopIntegFlag, &gVoltagePiParams);

  // error =  MLIB_SubSat_F16(gCC_Ref, gIdc);
  // gCC_Command = GFLIB_CtrlPIpAW_F16(error, &gStopIntegFlag, &gCurrentPiParams);
  // gCC_Command = GFLIB_Limit_F16(gCC_Command, FRAC16(-0.99), FRAC16(0));
  // gVoltageCommand = MLIB_AddSat_F16(gCV_Command, gCC_Command);
  gVoltageCommand = MLIB_AddSat_F16(gCV_Command, FRAC16(0.0));
  
  gFrequency = gVoltageCommand;
}

static inline void Build_VBAT(){
  // static u16 base = 0;
  // static u32 delta = 0;

  // if(gVdc >= VBAT_58V_INDEX)
  // {
  //   // overshoot condition
  //   gVdcRef = VBAT_58V_INDEX;
  //   ChangeState(RUNNING_STATE);
  //   return;
  // }
  // /*
  //   Soft start time is 5 sec.
  // */
  // if(gEnterRunningCount == 0){
  //   base = gVdc;
  //   delta = VBAT_58V_INDEX - gVdc;
  // }
  // gEnterRunningCount++;
  // if(gEnterRunningCount >= (SOFT_START_TIME*15360UL)){/* 15360 is sample rate for 65Hz AC */
  //   gEnterRunningCount = 0;
  //   gVdcRef = VBAT_58V_INDEX;
  //   ChangeState(RUNNING_STATE);
  //   return;
  // }

  // gVdcRef = base + (delta*gEnterRunningCount)/(SOFT_START_TIME*15360UL);
  // if(gVdcRef >= VBAT_58V_INDEX)
  //   gVdcRef = VBAT_58V_INDEX;
}

#endif
