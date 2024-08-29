/** 
 ******************************************************************************
 * @file	: PushPull_Running.h
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
#ifndef _PUSHPULL_RUNNING_H_
#define _PUSHPULL_RUNNING_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "fsl_common.h"
#include "fsl_sim.h"
#include "fsl_gpio.h"
#include "fsl_xbara.h"
#include "pin_mux.h"
#include "fsl_qsci.h"

#include "DCDC_Controller.h"
#include "StateMachine.h"
#include "PushPull_Fault.h"
#include "pin_config.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
extern void PushPull_StateMachine_RunningMain(void);

#pragma section CODES_IN_RAM begin
static inline void PushPull_StateMachine_RunningInner(void){}

static inline void PushPull_StateMachine_RunningOutter(void){
  if(gOnOffToggle){
      gOnOffToggle = 0;
      ChangeState(PUSHPULL_STOP_STATE);
  }
  
  DCDC_VoltageControlLoop();

  Update_PWM(gFrequency);
}
#pragma section CODES_IN_RAM end
#endif
