/** 
 ******************************************************************************
 * @file Type.h
 * @version V0.0.1
 * @date 2020.03.16
 * @author aidan.lu
 ******************************************************************************
 *
 *
 *
 ****************************************************************************** 
 */
 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _TYPE_H_
#define _TYPE_H_

#include <stdbool.h>

/* Predefined Or Compiler Option ---------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
/* Hardware Configuration ----------------------------------------------------*/
/* Define --------------------------------------------------------------------*/
#ifdef PRIVATE
#undef PRIVATE
#endif
#define PRIVATE static

#ifdef PUBLIC
#undef PUBLIC
#endif
#define PUBLIC

#define IMPORT extern
#define EXPORT extern

#define _OUT
#define _IN
#define _BOTH
#define _EMPTY

#define OK 0
#define NO_ERROR 0


/* Enum ----------------------------------------------------------------------*/
/* Marco ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
typedef enum{
	LOW 	= 0,
	HIGH 	= 1,
	EXCEPTION = -1
}digital_signal_t;

typedef unsigned char byte;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef signed long length_t;

typedef void (*fnGeneral)(void*);


/* Public Variable -----------------------------------------------------------*/
/* Public Function -----------------------------------------------------------*/

#endif

