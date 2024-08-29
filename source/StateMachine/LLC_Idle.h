/** 
 ******************************************************************************
 * @file	: LLC_Idle.h
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
#ifndef _LLC_IDLE_H_
#define _LLC_IDLE_H_

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

#include "DCDC_Controller.h"
#include "StateMachine.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
extern void LLC_StateMachine_IdleMain(void);

static inline void LLC_StateMachine_IdleInner(void){}

static inline void LLC_StateMachine_IdleOutter(void){
//   gCV_Ref = gVdc;

  gEnterSoftStartCount = 0;
  gEnterRunningCount = 0;

  gFrequency = FRAC16(0.0);

  gVoltagePiParams.f16InErrK_1 = 0;
	gVoltagePiParams.f32IAccK_1 = 0;

  gBurstTurnOn = 0;
  // gCurrent_1_2_PiParams.f16InErrK_1 = 0;
	// gCurrent_1_2_PiParams.f32IAccK_1 = 0;

  // gCurrent_3_4_PiParams.f16InErrK_1 = 0;
	// gCurrent_3_4_PiParams.f32IAccK_1 = 0;

  if(gOnOffToggle || gGpioFlag){
    gOnOffToggle = 0;
    ChangeState(LLC_RUN_STATE);
  }
}
#endif
