/** 
 ******************************************************************************
 * @file	: LLC_Fault.h
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
#ifndef _LLC_FAULT_H_
#define _LLC_FAULT_H_

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
extern FaultFlag_t gSysFaultFlag;

/* Public Function -----------------------------------------------------------*/
extern void LLC_StateMachine_FaultMain(void);
//extern void TurnOffAllGatePin(void);
//extern void DisabelOffAllPwm();


static inline void LLC_StateMachine_FaultInner(void){}

static inline void LLC_StateMachine_FaultOutter(void){
 // gCommandRatio = COMMAND_RATIO;
  // gCurrent_1_2_K = CURRENT_1_2_K;
  // gCurrentK_3_4 = CURRENT_3_4_K;
  // gVdcControllerRatio = VDC_RATIO;

  // gVoltagePiParams.a32PGain = PFC_V_P_GAIN1;
  // gVoltagePiParams.a32IGain = PFC_V_I_GAIN1;
  // gVoltagePiParams.f16LowerLim = PFC_V_LOWER_LIMIT;
  // gVoltagePiParams.f16UpperLim = PFC_V_UPPER_LIMIT;
  gVoltagePiParams.f16InErrK_1 = 0;
  gVoltagePiParams.f32IAccK_1 = 0;

	// gCurrent_1_2_PiParams.a32PGain = PFC_I_P_GAIN1;
	// gCurrent_1_2_PiParams.a32IGain = PFC_I_I_GAIN1;
	// gCurrent_1_2_PiParams.f16LowerLim = PFC_I_LOWER_LIMIT;
	// gCurrent_1_2_PiParams.f16UpperLim = PFC_I_UPPER_LIMIT;
	// gCurrent_1_2_PiParams.f16InErrK_1 = 0;
	// gCurrent_1_2_PiParams.f32IAccK_1 = 0;

	// gCurrent_3_4_PiParams.a32PGain = PFC_I_P_GAIN1;
	// gCurrent_3_4_PiParams.a32IGain = PFC_I_I_GAIN1;
	// gCurrent_3_4_PiParams.f16LowerLim = PFC_I_LOWER_LIMIT;
	// gCurrent_3_4_PiParams.f16UpperLim = PFC_I_UPPER_LIMIT;
	// gCurrent_3_4_PiParams.f16InErrK_1 = 0;
	// gCurrent_3_4_PiParams.f32IAccK_1 = 0;
  
  gStopIntegFlag = 0;

  Config_Prim_PWM_PinAsGpioLow();
  ConfigSR_PWM_PinAsGpioLow();
//  DisabelOffAllPwm();
  ChangeState(LLC_FAULT_LOCK_STATE);
}
#endif
