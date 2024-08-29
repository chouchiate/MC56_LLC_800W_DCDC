/**
 * @version:
 * @date: 2023.05.17
 * @author: Derick.Chou
*/

#include "includes.h"

u8 gGpioFlag = 0;
u8 gGpio0Debounce = 0;
u8 gGpio1Debounce = 0;

void initSysGpio(void) {
    gGpioFlag = 0;
    gGpio0Debounce = 0;
    gGpio1Debounce = 0;
}

void ScanButtons(void) {
    ScanGPIO0();
    ScanGPIO1();
}

void ScanGPIO0(void) {

    if (!GPIO_PinRead(GPIOA, kGPIO_Pin7)) {
        // pressed
        if (gGpio0Debounce < _TICK_100MSEC)
            gGpio0Debounce++;
        else 
            _SET_GPIO0_PRESSED_F;

    } else {
        // released
        if (gGpio0Debounce)
            gGpio0Debounce--;
        else
            _CLR_GPIO0_PRESSED_F;
    }
} 

void ScanGPIO1(void) {
    
    if (!GPIO_PinRead(GPIOA, kGPIO_Pin6)) {
        // pressed
        if (gGpio1Debounce < _TICK_100MSEC)
            gGpio1Debounce++;
        else 
            _SET_GPIO1_PRESSED_F;

    } else {
        // released
        if (gGpio1Debounce)
            gGpio1Debounce--;
        else
            _CLR_GPIO1_PRESSED_F;
    }
} 