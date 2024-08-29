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
* @brief  Accumulator subtraction from product with 16-bit fractional output in assembler
* 
*******************************************************************************/
#ifndef _MLIB_MNAC_F16_ASM_H_
#define _MLIB_MNAC_F16_ASM_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib_types.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/
#define MLIB_Mnac_F16_Asmi(f16Accum, f16Mult1, f16Mult2) MLIB_Mnac_F16_FAsmi(f16Accum, f16Mult1, f16Mult2)
#define MLIB_MnacSat_F16_Asmi(f16Accum, f16Mult1, f16Mult2) MLIB_MnacSat_F16_FAsmi(f16Accum, f16Mult1, f16Mult2)

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
* @brief  16-bit inputs 16-output accumulator subtraction from product function
*
* @param  ptr			
* 
* @param  in    		frac16_t f16Accum
*                         - Argument in [-1;1] in frac16_t, accumulator
*                       frac16_t f16Mult1
*                         - Argument in [-1;1] in frac16_t
*						frac16_t f16Mult2
*                         - Argument in [-1;1] in frac16_t
*                       
*
* @return This function returns
*     - frac16_t value [-1;1]
*		
* @remarks 	This function multiplies two fractional inputs and then the
* 			accumulator is subtracted from their product:
* 			result = f16Mult1 * f16Mult2 - f16Accum
* 			The function does not saturate the output if the saturation mode
* 			is turned off.
*
*			SATURATION required if saturation desirable!
*
****************************************************************************/
extern inline frac16_t MLIB_Mnac_F16_FAsmi(register frac16_t f16Accum, register frac16_t f16Mult1, register frac16_t f16Mult2)
{
	register frac32_t f32Acc;
	register frac16_t f16Out;
		
	asm(.optimize_iasm on);
		
	asm(move.w f16Accum,f32Acc);
	
	asm(neg f32Acc);						/* f32Acc = -f32Acc */
	
	asm(mac f16Mult1,f16Mult2,f32Acc);		/* f32Acc = f16Accum + f16Mult1 * f16Mult2 */
		
	asm(nop);
	
	asm(move.w f32Acc.1,f16Out);
		
	asm(.optimize_iasm off);
		
	return f16Out;
}

/***************************************************************************//*!
*
* @brief  16-bit inputs 16-output accumulator subtraction from product saturated function
*
* @param  ptr			
* 
* @param  in    		frac16_t f16Accum
*                         - Argument in [-1;1] in frac16_t, accumulator
*                       frac16_t f16Mult1
*                         - Argument in [-1;1] in frac16_t
*						frac16_t f16Mult2
*                         - Argument in [-1;1] in frac16_t
*                       
*
* @return This function returns
*     - frac16_t value [-1;1]
*		
* @remarks 	This function multiplies two fractional inputs and then the
* 			accumulator is subtracted from their product:
* 			result = f16Mult1 * f16Mult2 - f16Accum.
* 			The function saturates the output.
*
*			SATURATION INDEPENDENT!
*
****************************************************************************/
extern inline frac16_t MLIB_MnacSat_F16_FAsmi(register frac16_t f16Accum, register frac16_t f16Mult1, register frac16_t f16Mult2)
{
	register frac32_t f32Acc;
	register frac16_t f16Out;
	
	asm(.optimize_iasm on);
		
	asm(move.w f16Accum,f32Acc);
	
	asm(neg f32Acc);
		
	asm(mac f16Mult1,f16Mult2,f32Acc);		/* f32Acc = f16Accum + f16Mult1 * f16Mult2 */

	asm(nop);
	
	asm(sat f32Acc,f16Out);					/* Saturation */
		
	asm(.optimize_iasm off);
		
	return f16Out;
}

#if defined(__cplusplus) 
} 
#endif 

#endif /* _MLIB_MNAC_F16_ASM_H_ */
