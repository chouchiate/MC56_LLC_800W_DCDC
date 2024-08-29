/*******************************************************************************
*
 * Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
*
****************************************************************************//*!
*
* @brief  Subtraction of two products functions with 32-bit rounded fractional 
* 		  output in assembler for V3
* 
*******************************************************************************/
#ifndef _MLIB_MSU4RND_F32_ASMI_H_
#define _MLIB_MSU4RND_F32_ASMI_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Mul_F64_Asm.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/

/******************************************************************************
* Types
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/

/******************************************************************************
* Inline functions
******************************************************************************/

/***************************************************************************//*!
*
* @brief  	32-bit inputs 32-output vector multiply and subtract function
* 			with result rounding
*
* @param  	ptr			
* 
* @param  	in    		frac32_t f32MinMult1
*                         - Argument in [-1;1] in frac32_t
*                       frac32_t f32MinMult2
*                         - Argument in [-1;1] in frac32_t
*						frac32_t f32SubMult1
*                         - Argument in [-1;1] in frac32_t
*						frac32_t f32SubMult2
*                         - Argument in [-1;1] in frac32_t
*                       
*
* @return This function returns
*     - frac32_t value [-1;1]
*		
* @remarks 	This function returns the vector multiply and subtract of input values. 
* 			The input values as well as output value is considered as 32-bit fractional values. 
* 			The output saturation is not implemented in this function. 
* 			The output of the function is defined by the following equation:
* 			f32MinMult1 * f32MinMult2 - f32SubMult1 * f32SubMult2
*
*			SATURATION must be turned off!
*
****************************************************************************/
extern inline frac32_t MLIB_Msu4Rnd_F32_FAsmi(register frac32_t f32MinMult1, register frac32_t f32MinMult2, register frac32_t f32SubMult1, register frac32_t f32SubMult2)
{
	register frac32_t f32Val1, f32Val2;
	
	asm(.optimize_iasm on);

	asm(mpy64 f32MinMult1,f32MinMult2,f32MinMult1);		/* f32MinMult1:Y = f32MinMult1 * f32MinMult2 */
	
	asm(tfr	Y,f32Val2);									/* f32Val2 = Y */
	
	asm(mpy64 f32SubMult1,f32SubMult2,f32SubMult1);		/* f32SubMult1:Y = f32SubMult1 * f32SubMult2 */
	
	asm(sub f32SubMult1,f32MinMult1);					/* f32MinMult1 = f32MinMult1 - f32SubMult1 */
	
	asm(tfr Y,f32Val1);									/* f32Val1 = Y */  
	
	asm(tfr f32Val2,Y);									/* Y = f32Val2 */
	
	asm(sub f32Val1,Y);									/* Y = Y - f32Val1 */

	asm(nop);
	
	asm(lsrr.l #31,Y);									/* Y = highest bit of result lower 32 bits; for rounding */	

	asm(nop);
	
	asm(sbc Y,f32MinMult1);								/* f32MinMult1 = f32MinMult1 - Y */
	
//	asm(tfr f32MinMult1,f32Val2);
	
	asm(.optimize_iasm off);

	return f32MinMult1;	
}

/***************************************************************************//*!
*
* @brief  	32-bit inputs 32-output vector multiply and subtract saturated function
* 			with result rounding
*
* @param  	ptr			
* 
* @param  	in    		frac32_t f32MinMult1
*                         - Argument in [-1;1] in frac32_t
*                       frac32_t f32MinMult2
*                         - Argument in [-1;1] in frac32_t
*						frac32_t f32SubMult1
*                         - Argument in [-1;1] in frac32_t
*						frac32_t f32SubMult2
*                         - Argument in [-1;1] in frac32_t
*                       
*
* @return This function returns
*     - frac32_t value [-1;1]
*		
* @remarks 	This function returns the vector multiply and subtract of input values. 
* 			The input values as well as output value is considered as 32-bit fractional values. 
* 			The function saturates the output. 
* 			The output of the function is defined by the following equation:
* 			f32MinMult1 * f32MinMult2 - f32SubMult1 * f32SubMult2
*
*			SATURATION must be turned off!
*
****************************************************************************/
extern inline frac32_t MLIB_Msu4RndSat_F32_FAsmi(register frac32_t f32MinMult1, register frac32_t f32MinMult2, register frac32_t f32SubMult1, register frac32_t f32SubMult2)
{
	register frac32_t f32Val1, f32Val2;
	
	asm(.optimize_iasm on);

	asm(mpy64 f32MinMult1,f32MinMult2,f32MinMult1);		/* f32MinMult1:Y = f32MinMult1 * f32MinMult2 */
	
	asm(tfr	Y,f32Val2);									/* f32Val2 = Y */
	
	asm(mpy64 f32SubMult1,f32SubMult2,f32SubMult1);		/* f32SubMult1:Y = f32SubMult1 * f32SubMult2 */
	
	asm(sub f32SubMult1,f32MinMult1);					/* f32MinMult1 = f32MinMult1 - f32SubMult1 */
	
	asm(tfr Y,f32Val1);									/* f32Val1 = Y */  
	
	asm(tfr f32Val2,Y);									/* Y = f32Val2 */
	
	asm(sub f32Val1,Y);									/* Y = Y - f32Val1 */

	asm(nop);
	
	asm(lsrr.l #31,Y);									/* Y = highest bit of result lower 32 bits; for rounding */	

	asm(nop);
	
	asm(sbc Y,f32MinMult1);								/* f32MinMult1 = f32MinMult1 - Y */
	
	asm(sat f32MinMult1);								/* Saturation */
	
	asm(.optimize_iasm off);

	return f32MinMult1;	
}

#if defined(__cplusplus) 
} 
#endif 

#endif /* _MLIB_MSU4RND_F32_ASMI_H_ */
