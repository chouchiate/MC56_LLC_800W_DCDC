/** 
 ******************************************************************************
 * @file	: PushPull_Stop.h
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
#ifndef _PUSHPULL_STOP_H_
#define _PUSHPULL_STOP_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "mlib.h"
#include "fsl_common.h"
#include "fsl_sim.h"
#include "fsl_gpio.h"
#include "fsl_xbara.h"
#include "pin_mux.h"
#include "fsl_qsci.h"

#include "DCDC_Controller.h"
#include "StateMachine.h"
#include "pin_config.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
extern void PushPull_StateMachine_StopMain(void);
//extern void TurnOffAllGatePin(void);
//extern void DisabelOffAllPwm();

static inline void PushPull_StateMachine_StopInner(void){}

static inline void PushPull_StateMachine_StopOutter(void){
  ConfigSR_PWM_PinAsGpioLow();
  ChangeState(PUSHPULL_IDLE_STATE);
}
#endif
