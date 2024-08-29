/**
 * @version:
 * @date: 2023.05.10
 * @author: Derick.Chou
*/


#include "includes.h"
#include "Debug.h"
#include "DCDC_Controller.h"

u16 gTickFlag = 0;

eTickType eCurrPPTick = _TICK_PUSHPULL_HOLDOFF;
u16 gPushPullBurstDuration = 0;

/**
 * pushpull burst tick logic
 * burst_on --> burst_off (countdown > 0) --> 
 * ...
 * burst_on --> burst_off (countdown = 0) -->
 * holdoff --> burst_on --> repeat
*/
void tickHandle(void) {

    initializeTicks();
}   


