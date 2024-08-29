#ifndef __SYS_GPIO_H__
#define __SYS_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "Type.h"
#include "bit_op.h"

/**
 * gTickFlag bit map
 * bit0: GPIO0_PRESSED_F
 * bit1: GPIO1_PRESSED_F
 * 
 * 
*/

#define _SET_GPIO0_PRESSED_F SET_BIT0(gGpioFlag)
#define _CLR_GPIO0_PRESSED_F CLR_BIT0(gGpioFlag)
#define _IS_GPIO0_PRESSED_SET_F IS_BIT0_SET(gGpioFlag)
#define _SET_GPIO1_PRESSED_F SET_BIT1(gGpioFlag)
#define _CLR_GPIO1_PRESSED_F CLR_BIT1(gGpioFlag)
#define _IS_GPIO1_PRESSED_SET_F IS_BIT1_SET(gGpioFlag)

extern u8 gGpioFlag;
extern u8 gGpio0Debounce;
extern u8 gGpio1Debounce;

void initSysGpio(void);
void ScanButtons(void);
void ScanGPIO0(void);
void ScanGPIO1(void);

#ifdef __cplusplus
}
#endif

#endif /* !__SYS_GPIO_H__ */