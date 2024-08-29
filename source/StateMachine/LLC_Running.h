/** 
 ******************************************************************************
 * @file	: LLC_Running.h
 * @version	: V0.0.1
 * @date	: 2022.05.23
 * @author	: aidan.lu
 ******************************************************************************
 *
 *
 *
 ****************************************************************************** 
 */
 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _LLC_RUNNING_H_
#define _LLC_RUNNING_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "includes.h"
#include "fsl_common.h"
#include "fsl_sim.h"
#include "fsl_gpio.h"
#include "fsl_xbara.h"
#include "pin_mux.h"
#include "fsl_qsci.h"

#include "DCDC_Controller.h"
#include "StateMachine.h"
#include "LLC_Fault.h"
#include "pin_config.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
extern void LLC_StateMachine_RunningMain(void);

#pragma section CODES_IN_RAM begin
static inline void LLC_StateMachine_RunningInner(void){}

static inline void LLC_StateMachine_RunningOutter(void){
  if(gOnOffToggle || !gGpioFlag){
      gOnOffToggle = 0;
      ChangeState(LLC_STOP_STATE);
  }

  DCDC_VoltageControlLoop();

  // BURST MODE HYSTERSIS BETWEEN gVdc = (BURST_MODE_OFF_INDEX) AND (VBAT_58V_INDEX)
  if(gVdc >= BURST_MODE_OFF_INDEX){
    if(gBurstTurnOn == 0){
      gBurstTurnOn = 1;
      Config_Prim_PWM_PinAsGpioLow();
      ConfigSR_PWM_PinAsGpioLow();
    }
  }else if(gVdc < VBAT_58V_INDEX){
    if(gBurstTurnOn == 1){
      gBurstTurnOn = 0;
      Config_Prim_PWM_PinAsPWM();
      ConfigSR_PWM_PinAsPWM();
    }
  }
  /*
  
  */

  Update_PWM(gFrequency);
}
#pragma section CODES_IN_RAM end
#endif
