/** 
 ******************************************************************************
 * @file    : LLC_FaultLock.h
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
#ifndef _LLC_FAULT_LOCK_H_
#define _LLC_FAULT_LOCK_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "includes.h"
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
extern void LLC_StateMachine_FaultLockMain(void);

static inline void LLC_StateMachine_FaultLockInner(void){}

static inline void LLC_StateMachine_FaultLockOutter(void){
  // if(PWM_GetFaultStatusFlags(PWMA, kPWM_FaultProtection0) != 0)
  //   return;

  if(!gGpioFlag){

    ChangeState(LLC_HW_INIT_STATE);
  }
}

#endif
