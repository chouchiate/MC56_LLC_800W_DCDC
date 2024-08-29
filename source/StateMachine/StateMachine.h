/** 
 ******************************************************************************
 * @file	: StateMachine.h
 * @version	: V0.0.1
 * @date	: 2022.05.04
 * @author	: aidan.lu
 ******************************************************************************
 *
 *
 *
 ****************************************************************************** 
 */
 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "gflib.h"
#include "gdflib.h"
#include "mlib.h"

/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
#define ChangeState(x) gState = x

/* Typedef -------------------------------------------------------------------*/
typedef enum{
    LLC_HW_INIT_STATE,
    LLC_STOP_STATE,

	LLC_IDLE_STATE,
    LLC_RUN_STATE,
	LLC_SOFT_START_STATE,
	LLC_RUNNING_STATE,
    
	LLC_FAULT_STATE,
	LLC_FAULT_LOCK_STATE,

    PUSHPULL_HW_INIT_STATE,
    PUSHPULL_STOP_STATE,

	PUSHPULL_IDLE_STATE,
    PUSHPULL_RUN_STATE,
	PUSHPULL_SOFT_START_STATE,
	PUSHPULL_RUNNING_STATE,
    
	PUSHPULL_FAULT_STATE,
	PUSHPULL_FAULT_LOCK_STATE	
}StateMachine_t;

typedef struct{
	void (*main_loop)(void);
	void (*inner_loop)(void);
	void (*outter_loop)(void);
}StatusMachineFunc_t;

typedef struct{
  u16 ovp:1;  //bit 0
  u16 uvp:1;  //bit 1
  u16 ocp:1;  //bit 2
  u16 otp:1;  //bit 3
}FaultFlag_t;

/* Public Variable -----------------------------------------------------------*/
extern StateMachine_t gState;
const extern StatusMachineFunc_t gStateMachineList[21];
extern u16 gEnterSoftStartCount;
extern u32 gEnterRunningCount;
extern u32 gMainRunningCount;
extern u8 gOnOffToggle;

/* Public Function -----------------------------------------------------------*/

#endif
