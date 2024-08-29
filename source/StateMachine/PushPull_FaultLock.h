/** 
 ******************************************************************************
 * @file    : FaultLock.h
 * @version	: V0.0.1
 * @date    : 2022.05.30
 * @author	: aidan.lu
 ******************************************************************************
 *
 *
 *
 ****************************************************************************** 
 */
 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _PUSHPULL_FAULT_LOCK_H_
#define _PUSHPULL_FAULT_LOCK_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "mlib.h"
#include "fsl_common.h"
#include "fsl_sim.h"
#include "fsl_gpio.h"
#include "fsl_xbara.h"
#include "pin_mux.h"
#include "fsl_qsci.h"
#include "fsl_pwm.h"

#include "StateMachine.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
extern void PushPull_StateMachine_FaultLockMain(void);

static inline void PushPull_StateMachine_FaultLockInner(void){}

static inline void PushPull_StateMachine_FaultLockOutter(void){
  // if(PWM_GetFaultStatusFlags(PWMA, kPWM_FaultProtection0) != 0)
  //   return;

  if(gOnOffToggle){
    gOnOffToggle = 0;
    ChangeState(PUSHPULL_HW_INIT_STATE);
  }
}

#endif
