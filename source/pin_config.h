/** 
 ******************************************************************************
 * @file	: pin_config.h
 * @version	: V0.0.1
 * @date	: 2023.01.06
 * @author	: aidan.lu
 ******************************************************************************
 *
 *
 *
 ****************************************************************************** 
 */
 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _PIN_CONFIG_H_
#define _PIN_CONFIG_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "fsl_common.h"
#include "fsl_gpio.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
extern void Pin_Init(void);

static inline void Config_Prim_PWM_PinAsGpioLow(void){
  /* GPIO functionality on pin GPIOE0, GPIOE1, GPIOE4, GPIOE5*/
  GPIOE->DR &= ~(kGPIO_Pin0|kGPIO_Pin1|kGPIO_Pin4|kGPIO_Pin5);
  GPIOE->DDR |= ((uint16_t)kGPIO_Pin0|kGPIO_Pin1|kGPIO_Pin4|kGPIO_Pin5);
  GPIOE->PER &= ~((uint16_t)kGPIO_Pin0|kGPIO_Pin1|kGPIO_Pin4|kGPIO_Pin5);
}

static inline void Config_Prim_PWM_PinAsPWM(void){
  /* GPIO functionality on pin GPIOE0, GPIOE1, GPIOE4, GPIOE5*/
  GPIOE->PER |= ((uint16_t)kGPIO_Pin0|kGPIO_Pin1|kGPIO_Pin4|kGPIO_Pin5);
}

static inline void ConfigSR_PWM_PinAsGpioLow(void){
  /* GPIO functionality on pin GPIOE2 ~ GPIOE3 */
  GPIOE->DR &= ~(kGPIO_Pin2|kGPIO_Pin3);
  GPIOE->DDR |= ((uint16_t)kGPIO_Pin2|kGPIO_Pin3);
  GPIOE->PER &= ~((uint16_t)kGPIO_Pin2|kGPIO_Pin3);
}

static inline void ConfigSR_PWM_PinAsPWM(void){
  /* GPIO functionality on pin GPIOE2 ~ GPIOE3*/
  GPIOE->PER |= ((uint16_t)kGPIO_Pin2|kGPIO_Pin3);
}
#endif
