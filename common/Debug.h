/** 
 ******************************************************************************
 * @file	Debug.h
 * @version V0.0.1
 * @date	2022.07.13
 * @author	aidan.lu
 ******************************************************************************
 *
 *
 *
 ****************************************************************************** 
 */
 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DEBUG_H_
#define _DEBUG_H_
/* Predefined Or Compiler Option ---------------------------------------------*/
#define ENABLE_DEBUG_IO


/* Includes ------------------------------------------------------------------*/
/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
#ifdef ENABLE_DEBUG_IO
#define Debug_Io_High(Port, Pin)  STATEMENT(Port->DR |= Pin;)
#define Debug_Io_Low(Port, Pin)   STATEMENT(Port->DR &= ~Pin;)
#define Debug_Io_Toggle(Port, Pin)  STATEMENT(Port->DR ^= Pin;)
#else
#define Debug_Io_High(Port, Pin)    {;}
#define Debug_Io_Low(Port, Pin)     {;}
#define Debug_Io_Toggle(Port, Pin)  {;}
#endif



/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/

#endif

