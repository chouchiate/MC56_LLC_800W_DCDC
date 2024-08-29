/** 
 ******************************************************************************
 * @file	    : pin_config.c
 * @version	  : V0.0.1
 * @date	    : 2023.01.06
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
/* Private Function ----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
/**
  * @brief	
  * @note	
  * @param	
  * @retval	
  * @return	
  */ 

void Pin_Init(void){
  Config_Prim_PWM_PinAsGpioLow();
  ConfigSR_PWM_PinAsGpioLow();  

  GPIO_PinSetDirection(GPIOA, kGPIO_Pin7, kGPIO_DigitalInput);
  GPIO_PinSetDirection(GPIOA, kGPIO_Pin6, kGPIO_DigitalInput);
  GPIO_PinSetDirection(GPIOA, kGPIO_Pin5, kGPIO_DigitalInput);
  
  GPIO_PinSetPullResistorMode(GPIOA, kGPIO_Pin7, kGPIO_PullUp);
  GPIO_PinSetPullResistorMode(GPIOA, kGPIO_Pin6, kGPIO_PullUp);
  GPIO_PinSetPullResistorMode(GPIOA, kGPIO_Pin5, kGPIO_PullUp);    
}