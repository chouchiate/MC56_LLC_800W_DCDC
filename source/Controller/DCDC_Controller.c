/** 
 ******************************************************************************
 * @file	    : DCDC_Controller.c
 * @version	  : V0.0.1
 * @date	    : 2022.07.25
 * @author	  : aidan.lu
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

#include "DCDC_Controller.h"


/* Private Typedef -----------------------------------------------------------*/
/* Private Prototype ---------------------------------------------------------*/
/* Private Define ------------------------------------------------------------*/
/* Private Enum --------------------------------------------------------------*/
/* Private Marco -------------------------------------------------------------*/
/* Private Variable ----------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
frac16_t gFrequency = FRAC16(0.0);

frac16_t gVoltageCommand;
bool_t gStopIntegFlag;

frac16_t gVdc;
frac16_t gIdc;
frac16_t gVbat;
frac16_t gIllc;

volatile frac16_t gCV_Ref = VBAT_50V_INDEX;
GFLIB_CTRL_PI_P_AW_T_A32 gVoltagePiParams;
frac16_t gCV_Command = FRAC16(0.0);

frac16_t gCC_Ref = FRAC16(1.0);
GFLIB_CTRL_PI_P_AW_T_A32 gCurrentPiParams;
frac16_t gCC_Command = FRAC16(0.0);

uint8_t gBurstTurnOn = 0;

/* Import Variable -----------------------------------------------------------*/
/* Import Function -----------------------------------------------------------*/
/* Private Function ----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/

/**
  * @brief	
  * @note	
  * @param	
  * @retval	
  * @return	
  */ 
void DCDC_Init(void){
  gVoltagePiParams.a32PGain = DCDC_CV_P_GAIN;
  gVoltagePiParams.a32IGain = DCDC_CV_I_GAIN;
  gVoltagePiParams.f16LowerLim = DCDC_CV_LOWER_LIMIT;
  gVoltagePiParams.f16UpperLim = DCDC_CV_UPPER_LIMIT;
  gVoltagePiParams.f16InErrK_1 = 0;
  gVoltagePiParams.f32IAccK_1 = 0;

  gCurrentPiParams.a32PGain = DCDC_CC_P_GAIN;
  gCurrentPiParams.a32IGain = DCDC_CV_I_GAIN;
  gCurrentPiParams.f16LowerLim = DCDC_CV_LOWER_LIMIT;
  gCurrentPiParams.f16UpperLim = DCDC_CV_UPPER_LIMIT;
  gCurrentPiParams.f16InErrK_1 = 0;
  gCurrentPiParams.f32IAccK_1 = 0;

  gStopIntegFlag = 0;
}
