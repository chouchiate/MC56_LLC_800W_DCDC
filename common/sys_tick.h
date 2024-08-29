#ifndef __SYS_TICK_H__
#define __SYS_TICK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "Type.h"
#include "bit_op.h"

/**
 * gTickFlag bit map
 * bit0: _PP_BURST_EN_F => set when pp burst enable
 * bit1: _PP_BURST_ON_F => set when pp burst at on state
 * bit2: _PP_BURST_OFF_F => set when pp burst at off state
 * 
 * 
*/

#define _SET_PP_BURST_EN_F SET_BIT0(gTickFlag)
#define _CLR_PP_BURST_EN_F CLR_BIT0(gTickFlag)
#define _IS_PP_BURST_EN_F IS_BIT0_SET(gTickFlag)

#define _TICK_2MSEC         1
#define _TICK_10MSEC        5 // 2msec * 5 = 10ms
#define _TICK_20MSEC       10 // 2msec * 10 = 20ms
#define _TICK_40MSEC       20 // 2msec * 20 = 40ms
#define _TICK_100MSEC      50 // 2msec * 50 = 100ms
#define _PP_BURST_COUNT_MAX 5 
#define _PP_BURST_COUNT_FOREVER 0xff

typedef enum {
  _TICK_PUSHPULL_BURST_ON = 0,
  _TICK_PUSHPULL_BURST_OFF = 1,
  _TICK_PUSHPULL_HOLDOFF = 2,
} eTickType; 

extern eTickType eCurrPPTick;
extern u16 gTickFlag;

void tickHandle(void);

void initPPTick(void);
void initializeTicks(void);
void startTick(u16 duration, eTickType type);


#ifdef __cplusplus
}
#endif

#endif /* !__SYS_TICK_H__ */