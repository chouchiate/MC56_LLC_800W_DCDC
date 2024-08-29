/** 
 ******************************************************************************
 * @file	  : StateMachine.h
 * @version	: V0.0.1
 * @date	  : 2022.05.04
 * @author	: aidan.lu
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

#include "fsl_qsci.h"

#include "StateMachine.h"
#include "LLC_Idle.h"
#include "LLC_Running.h"
#include "LLC_HW_Init.h"
#include "LLC_Stop.h"
#include "LLC_Run.h"
#include "LLC_Fault.h"
#include "LLC_FaultLock.h"
#include "LLC_SoftStart.h"

#include "PushPull_Idle.h"
#include "PushPull_Running.h"
#include "PushPull_HW_Init.h"
#include "PushPull_Stop.h"
#include "PushPull_Run.h"
#include "PushPull_Fault.h"
#include "PushPull_FaultLock.h"
#include "PushPull_SoftStart.h"

/* Private Typedef -----------------------------------------------------------*/
typedef struct{
  char* command;
  fnGeneral exec;
  u8 response_size;
}CommandTable_t;

/* Private Prototype ---------------------------------------------------------*/
static void ChangeToHwInitState(void* param);
static void ChangeToStopState(void* param);
static void ChangeToIdleStatus(void* param);
static void ChangeToRunStatus(void* param);
static void ChangeToSoftStartStatus(void* param);
static void ChangeToRunningStatus(void* param);
static void ChangeToFaultStatus(void* param);
static StateMachine_t StateMachine_NoneEnter(void);
static void StateMachine_NoneOp(void);

void ParsingRecvString2(void);
/* Private Define ------------------------------------------------------------*/
/* Private Enum --------------------------------------------------------------*/
/* Private Marco -------------------------------------------------------------*/
/* Private Variable ----------------------------------------------------------*/
static const CommandTable_t CommandTable[] = {
    {"State = HW_INIT", ChangeToHwInitState, 3},
    {"State = STOP", ChangeToStopState, 3},
    {"State = IDLE", ChangeToIdleStatus, 3},
    {"State = RUN", ChangeToRunStatus, 3},
    {"State = SOFTSTART", ChangeToSoftStartStatus, 3},
    {"State = RUNNING", ChangeToRunningStatus, 3},
    {"State = FAULT", ChangeToFaultStatus, 3}
};

/* Public Variable -----------------------------------------------------------*/
StateMachine_t gState = LLC_HW_INIT_STATE;
const StatusMachineFunc_t gStateMachineList[] = {
    //LLC_HW_INIT_STATE
    {LLC_StateMachine_HwInitMain, StateMachine_NoneOp, StateMachine_NoneOp},

    //LLC_STOP_STATE
    {LLC_StateMachine_StopMain, LLC_StateMachine_StopInner, LLC_StateMachine_StopOutter}, 

    //LLC_IDLE_STATE
    {LLC_StateMachine_IdleMain, StateMachine_NoneOp, LLC_StateMachine_IdleOutter},

    //LLC_RUN_STATE
    {LLC_StateMachine_RunMain, LLC_StateMachine_RunInner, LLC_StateMachine_RunOutter},

    //LLC_SOFT_START_STATE
    {LLC_StateMachine_SoftStartMain, LLC_StateMachine_SoftStartInner, LLC_StateMachine_SoftStartOutter},

    //LLC_RUNNING_STATE
    {LLC_StateMachine_RunningMain, LLC_StateMachine_RunningInner, LLC_StateMachine_RunningOutter},

    //LLC_FAULT_STATE
    {LLC_StateMachine_FaultMain, LLC_StateMachine_FaultInner, LLC_StateMachine_FaultOutter},

    //LLC_FAULT_LOCK_STATE
    {LLC_StateMachine_FaultLockMain, LLC_StateMachine_FaultLockInner, LLC_StateMachine_FaultLockOutter},

    //PUSHPULL_HW_INIT_STATE
    {PushPull_StateMachine_HwInitMain, StateMachine_NoneOp, StateMachine_NoneOp},

    //PUSHPULL_STOP_STATE
    {PushPull_StateMachine_StopMain, PushPull_StateMachine_StopInner, PushPull_StateMachine_StopOutter}, 

    //PUSHPULL_IDLE_STATE
    {PushPull_StateMachine_IdleMain, StateMachine_NoneOp, PushPull_StateMachine_IdleOutter},

    //PUSHPULL_RUN_STATE
    {PushPull_StateMachine_RunMain, PushPull_StateMachine_RunInner, PushPull_StateMachine_RunOutter},

    //PUSHPULL_SOFT_START_STATE
    {PushPull_StateMachine_SoftStartMain, PushPull_StateMachine_SoftStartInner, PushPull_StateMachine_SoftStartOutter},

    //PUSHPULL_RUNNING_STATE
    {PushPull_StateMachine_RunningMain, PushPull_StateMachine_RunningInner, PushPull_StateMachine_RunningOutter},

    //PUSHPULL_FAULT_STATE
    {PushPull_StateMachine_FaultMain, PushPull_StateMachine_FaultInner, PushPull_StateMachine_FaultOutter},

    //PUSHPULL_FAULT_LOCK_STATE
    {PushPull_StateMachine_FaultLockMain, PushPull_StateMachine_FaultLockInner, PushPull_StateMachine_FaultLockOutter}

};
u16 gEnterSoftStartCount = 0;
u32 gEnterRunningCount = 0;
u32 gMainRunningCount = 0;
FaultFlag_t gSysFaultFlag = {0};

/* Import Variable -----------------------------------------------------------*/
extern bool gRecvDone;
extern u8 gRecvIndex;
extern u8 gRecvCommadString[16];

/* Import Function -----------------------------------------------------------*/

/* Private Function ----------------------------------------------------------*/
static void ChangeToHwInitState(void* param){
  byte* packet = (byte*)param;

  packet[0] = 'O';
  packet[1] = 'K';
  ChangeState(LLC_HW_INIT_STATE);
}

static void ChangeToStopState(void* param){
  byte* packet = (byte*)param;

  packet[0] = 'O';
  packet[1] = 'K';
  ChangeState(LLC_STOP_STATE);
}

static void ChangeToIdleStatus(void* param){
  byte* packet = (byte*)param;

  packet[0] = 'O';
  packet[1] = 'K';
  ChangeState(LLC_IDLE_STATE);
}

static void ChangeToRunStatus(void* param){
  byte* packet = (byte*)param;

  packet[0] = 'O';
  packet[1] = 'K';
  ChangeState(LLC_RUN_STATE);
}

static void ChangeToSoftStartStatus(void* param){
  byte* packet = (byte*)param;

  packet[0] = 'O';
  packet[1] = 'K';
  ChangeState(LLC_SOFT_START_STATE);
}

static void ChangeToRunningStatus(void* param){
  byte* packet = (byte*)param;

  packet[0] = 'O';
  packet[1] = 'K';
  ChangeState(LLC_RUNNING_STATE);
}

static void ChangeToFaultStatus(void* param){
  byte* packet = (byte*)param;

  packet[0] = 'O';
  packet[1] = 'K';
  ChangeState(LLC_FAULT_STATE);
}

static StateMachine_t StateMachine_NoneEnter(void){

}

static void StateMachine_NoneOp(void){

}

/* Public Function -----------------------------------------------------------*/
/**
  * @brief	
  * @note	
  * @param	
  * @retval	
  * @return	
  */ 
void ParsingRecvString2(void){
//    if(gRecvDone == TRUE){
//        u8 packet[] = {'N', 'G', '\n'};
//        u8 response_size = sizeof(packet);
//        gRecvDone = FALSE;

//        for(u8 j=0; j<ELEMEMT_NUMBER(CommandTable); j++){
//            char* string = CommandTable[j].command;
//            if(strcmp((const char *)gRecvCommadString, string) == 0){
//                if( CommandTable[j].exec != NULL){
//                    CommandTable[j].exec(packet);
//                    response_size = CommandTable[j].response_size;
//                    break;
//                }
//            }
//        }
//        QSCI_WriteBlocking(QSCI0, packet, response_size);
//        gRecvIndex = 0;
//    }
}
