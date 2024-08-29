/** 
 ******************************************************************************
 * @file    : PushPull_HW_Init.h
 * @version : V0.0.1
 * @date	  : 2022.05.23
 * @author  : aidan.lu
 ******************************************************************************
 *
 *
 *
 ******************************************************************************
 */

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "Type.h"
#include "Common_Macro.h"

#include "fsl_pwm.h"

#include "DCDC_Controller.h"
#include "PushPull_HW_Init.h"
#include "PushPull_Fault.h"
#include "pin_config.h"

/* Private Typedef -----------------------------------------------------------*/
/* Private Prototype ---------------------------------------------------------*/
/* Private Define ------------------------------------------------------------*/
/* Private Enum --------------------------------------------------------------*/
/* Private Marco -------------------------------------------------------------*/
/* Private Variable ----------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Import Variable -----------------------------------------------------------*/
/* Import Function -----------------------------------------------------------*/
extern void ParsingRecvString2(void);

/* Private Function ----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/

/**
  * @brief	
  * @note	
  * @param	
  * @retval	
  * @return	
  */ 
void PushPull_StateMachine_HwInitMain(void){
  PWM_ClearFaultStatusFlags(PWMA, kPWM_FaultProtection0, 0x0F);

  ParsingRecvString2();
  // Init All Controller and PID parameter

  gSysFaultFlag.ovp = 0;
  gSysFaultFlag.uvp = 0;
  gSysFaultFlag.ocp = 0;
  gSysFaultFlag.otp = 0;

  ChangeState(PUSHPULL_IDLE_STATE);
}
