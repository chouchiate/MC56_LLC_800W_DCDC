/** 
 ******************************************************************************
 * @file	: PushPull_Run.h
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
#ifndef _PUSHPULL_RUN_H_
#define _PUSHPULL_RUN_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "mlib.h"
#include "fsl_common.h"
#include "fsl_sim.h"
#include "fsl_gpio.h"
#include "fsl_xbara.h"
#include "pin_mux.h"
#include "fsl_qsci.h"

#include "StateMachine.h"
#include "pin_config.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
// void ConfigGatePinAsPwm(void);
// void EnableAllPwm();
extern void PushPull_StateMachine_RunMain(void);

static inline void PushPull_StateMachine_RunInner(void){}

static inline void PushPull_StateMachine_RunOutter(void){
  if(gOnOffToggle){
      gOnOffToggle = 0;
      ChangeState(PUSHPULL_STOP_STATE);
  }

  gEnterSoftStartCount++;
  /*
    Outter() freq. is 15360 Hz
    //Stay Run state for 1 second
  */
  if(gEnterSoftStartCount >= 15360){
    gEnterSoftStartCount = 0;
    ConfigSR_PWM_PinAsPWM();
    // EnableAllPwm();
    ChangeState(PUSHPULL_SOFT_START_STATE);
  }
}
#endif
