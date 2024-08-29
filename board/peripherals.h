/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_device_registers.h"
#include "Cpu.h"
#include "fsl_common.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* BOARD_InitPeripherals defines for XBARA */
/* XBARA_CTRL0: STS1=0, EDGE1=0, IEN1=0, DEN1=0, STS0=0, EDGE0=0, IEN0=0, DEN0=0 */
#define XBARA_CTRL0_INIT 0x0U
/* XBARA_CTRL1: STS3=0, EDGE3=0, IEN3=0, DEN3=0, STS2=0, EDGE2=0, IEN2=0, DEN2=0 */
#define XBARA_CTRL1_INIT 0x0U
/* Definition of peripheral ID */
#define PWMA_PERIPHERAL PWMA
/* Definition of clock source of submodule 0 frequency in Hertz */
#define PWMA_SM0_SM_CLK_SOURCE_FREQ_HZ 100000000U
/* Definition of submodule 0 counter clock source frequency in Hertz - PWMA_SM0_SM_CLK_SOURCE_FREQ_HZ divided by prescaler */
#define PWMA_SM0_COUNTER_CLK_SOURCE_FREQ_HZ 100000000U
/* Definition of clock source of submodule 1 frequency in Hertz */
#define PWMA_SM1_SM_CLK_SOURCE_FREQ_HZ 100000000U
/* Definition of submodule 1 counter clock source frequency in Hertz - PWMA_SM1_SM_CLK_SOURCE_FREQ_HZ divided by prescaler */
#define PWMA_SM1_COUNTER_CLK_SOURCE_FREQ_HZ 100000000U
/* PWMA_SM0INIT: INIT=0 */
#define PWMA_SM0INIT_INIT 0x0U
/* PWMA_SM0CTRL2: DBGEN=0, WAITEN=0, INDEP=0, PWM23_INIT=0, PWM45_INIT=0, PWMX_INIT=0, INIT_SEL=0, FRCEN=0, FORCE_SEL=4, RELOAD_SEL=0, CLK_SEL=0 */
#define PWMA_SM0CTRL2_INIT 0x20U
/* PWMA_SM0CTRL: LDFQ=1, HALF=0, FULL=1, COMPMODE=0, PRSC=0, SPLIT=0, LDMOD=0, DBLX=0, DBLEN=0 */
#define PWMA_SM0CTRL_INIT 0x1400U
/* PWMA_SM0VAL0: VAL0=0 */
#define PWMA_SM0VAL0_INIT 0x0U
/* PWMA_SM0FRACVAL1: FRACVAL1=0 */
#define PWMA_SM0FRACVAL1_INIT 0x0U
/* PWMA_SM0VAL1: VAL1=999 */
#define PWMA_SM0VAL1_INIT 0x3E7U
/* PWMA_SM0FRACVAL2: FRACVAL2=0 */
#define PWMA_SM0FRACVAL2_INIT 0x0U
/* PWMA_SM0VAL2: VAL2=0 */
#define PWMA_SM0VAL2_INIT 0x0U
/* PWMA_SM0FRACVAL3: FRACVAL3=0 */
#define PWMA_SM0FRACVAL3_INIT 0x0U
/* PWMA_SM0VAL3: VAL3=499 */
#define PWMA_SM0VAL3_INIT 0x1F3U
/* PWMA_SM0FRACVAL4: FRACVAL4=0 */
#define PWMA_SM0FRACVAL4_INIT 0x0U
/* PWMA_SM0VAL4: VAL4=0 */
#define PWMA_SM0VAL4_INIT 0x0U
/* PWMA_SM0FRACVAL5: FRACVAL5=0 */
#define PWMA_SM0FRACVAL5_INIT 0x0U
/* PWMA_SM0VAL5: VAL5=0 */
#define PWMA_SM0VAL5_INIT 0x0U
/* PWMA_SM0FRCTRL: FRAC_PU=0, FRAC45_EN=0, FRAC23_EN=0, FRAC1_EN=0 */
#define PWMA_SM0FRCTRL_INIT 0x0U
/* PWMA_SM0OCTRL: POLA=0, POLB=0, PWMAFS=0, PWMBFS=0 */
#define PWMA_SM0OCTRL_INIT 0x0U
/* PWMA_SM0STS: REF=0, RF=0, CFA1=0, CFA0=0, CFB1=0, CFB0=0, CFX1=0, CFX0=0, CMPF=0 */
#define PWMA_SM0STS_INIT 0x0U
/* PWMA_SM0INTEN: REIE=0, RIE=0, CA1IE=0, CA0IE=0, CB1IE=0, CB0IE=0, CX1IE=0, CX0IE=0, CMPIE=0 */
#define PWMA_SM0INTEN_INIT 0x0U
/* PWMA_SM0TCTRL: PWAOT0=1, PWBOT1=1, TRGFRQ=1, OUT_TRIG_EN=1 */
#define PWMA_SM0TCTRL_INIT 0xD001U
/* PWMA_SM0DISMAP0: DIS0B=3, DIS0A=3 */
#define PWMA_SM0DISMAP0_INIT 0xFF33U
/* PWMA_SM0DISMAP1: DIS1B=0, DIS1A=0 */
#define PWMA_SM0DISMAP1_INIT 0xFF00U
/* PWMA_SM0DTCNT0: DTCNT0=20 */
#define PWMA_SM0DTCNT0_INIT 0x14U
/* PWMA_SM0DTCNT1: DTCNT1=20 */
#define PWMA_SM0DTCNT1_INIT 0x14U
/* PWMA_SM1INIT: INIT=0 */
#define PWMA_SM1INIT_INIT 0x0U
/* PWMA_SM1CTRL2: DBGEN=0, WAITEN=0, INDEP=1, PWM23_INIT=0, PWM45_INIT=0, PWMX_INIT=0, INIT_SEL=2, FRCEN=0, FORCE_SEL=7, RELOAD_SEL=1, CLK_SEL=0 */
#define PWMA_SM1CTRL2_INIT 0x223CU
/* PWMA_SM1CTRL: LDFQ=0, HALF=0, FULL=1, COMPMODE=0, PRSC=0, SPLIT=0, LDMOD=0, DBLX=0, DBLEN=0 */
#define PWMA_SM1CTRL_INIT 0x400U
/* PWMA_SM1VAL0: VAL0=0 */
#define PWMA_SM1VAL0_INIT 0x0U
/* PWMA_SM1FRACVAL1: FRACVAL1=0 */
#define PWMA_SM1FRACVAL1_INIT 0x0U
/* PWMA_SM1VAL1: VAL1=999 */
#define PWMA_SM1VAL1_INIT 0x3E7U
/* PWMA_SM1FRACVAL2: FRACVAL2=0 */
#define PWMA_SM1FRACVAL2_INIT 0x0U
/* PWMA_SM1VAL2: VAL2=0 */
#define PWMA_SM1VAL2_INIT 0x0U
/* PWMA_SM1FRACVAL3: FRACVAL3=0 */
#define PWMA_SM1FRACVAL3_INIT 0x0U
/* PWMA_SM1VAL3: VAL3=0 */
#define PWMA_SM1VAL3_INIT 0x0U
/* PWMA_SM1FRACVAL4: FRACVAL4=0 */
#define PWMA_SM1FRACVAL4_INIT 0x0U
/* PWMA_SM1VAL4: VAL4=0 */
#define PWMA_SM1VAL4_INIT 0x0U
/* PWMA_SM1FRACVAL5: FRACVAL5=0 */
#define PWMA_SM1FRACVAL5_INIT 0x0U
/* PWMA_SM1VAL5: VAL5=0 */
#define PWMA_SM1VAL5_INIT 0x0U
/* PWMA_SM1FRCTRL: FRAC_PU=0, FRAC45_EN=0, FRAC23_EN=0, FRAC1_EN=0 */
#define PWMA_SM1FRCTRL_INIT 0x0U
/* PWMA_SM1OCTRL: POLA=0, POLB=0, PWMAFS=0, PWMBFS=0 */
#define PWMA_SM1OCTRL_INIT 0x0U
/* PWMA_SM1STS: REF=0, RF=0, CFA1=0, CFA0=0, CFB1=0, CFB0=0, CFX1=0, CFX0=0, CMPF=0 */
#define PWMA_SM1STS_INIT 0x0U
/* PWMA_SM1INTEN: REIE=0, RIE=0, CA1IE=0, CA0IE=0, CB1IE=0, CB0IE=0, CX1IE=0, CX0IE=0, CMPIE=0 */
#define PWMA_SM1INTEN_INIT 0x0U
/* PWMA_SM1TCTRL: PWAOT0=0, PWBOT1=0, TRGFRQ=0, OUT_TRIG_EN=0 */
#define PWMA_SM1TCTRL_INIT 0x0U
/* PWMA_SM1DISMAP0: DIS0B=3, DIS0A=3 */
#define PWMA_SM1DISMAP0_INIT 0xFF33U
/* PWMA_SM1DISMAP1: DIS1B=0, DIS1A=0 */
#define PWMA_SM1DISMAP1_INIT 0xFF00U
/* PWMA_SM1DTCNT0: DTCNT0=20 */
#define PWMA_SM1DTCNT0_INIT 0x14U
/* PWMA_SM1DTCNT1: DTCNT1=20 */
#define PWMA_SM1DTCNT1_INIT 0x14U
/* PWMA_SM1PHASEDLY: PHASEDLY=0 */
#define PWMA_SM1PHASEDLY_INIT 0x0U
/* PWMA_OUTEN: PWMA_EN=3, PWMB_EN=3, PWMX_EN=0 */
#define PWMA_OUTEN_INIT 0x330U
/* PWMA_MASK: UPDATE_MASK=0, MASKA=0, MASKB=0, MASKX=0 */
#define PWMA_MASK_INIT 0x0U
/* PWMA_SWCOUT: SM1OUT23=0, SM1OUT45=0, SM0OUT23=0, SM0OUT45=0 */
#define PWMA_SWCOUT_INIT 0x0U
/* PWMA_DTSRCSEL: SM1SEL23=0, SM1SEL45=0, SM0SEL23=0, SM0SEL45=0 */
#define PWMA_DTSRCSEL_INIT 0x0U
/* PWMA_MCTRL: IPOL=0, RUN=0, LDOK=0 */
#define PWMA_MCTRL_INIT 0x0U
/* PWMA_MCTRL2: MONPLL=0 */
#define PWMA_MCTRL2_INIT 0x0U
/* PWMA_FCTRL0: FLVL=3, FAUTO=0, FSAFE=0, FIE=0 */
#define PWMA_FCTRL0_INIT 0x3000U
/* PWMA_FSTS0: FHALF=0, FFULL=3 */
#define PWMA_FSTS0_INIT 0x30U
/* PWMA_FFILT0: GSTR=0, FILT_CNT=0, FILT_PER=0 */
#define PWMA_FFILT0_INIT 0x0U
/* PWMA_FTST0: FTEST=0 */
#define PWMA_FTST0_INIT 0x0U
/* PWMA_FCTRL20: NOCOMB=0 */
#define PWMA_FCTRL20_INIT 0x0U
/* PWMA_FCTRL1: FLVL=0, FAUTO=0, FSAFE=0, FIE=0 */
#define PWMA_FCTRL1_INIT 0x0U
/* PWMA_FSTS1: FHALF=0, FFULL=0 */
#define PWMA_FSTS1_INIT 0x0U
/* PWMA_FFILT1: GSTR=0, FILT_CNT=0, FILT_PER=0 */
#define PWMA_FFILT1_INIT 0x0U
/* PWMA_FTST1: FTEST=0 */
#define PWMA_FTST1_INIT 0x0U
/* PWMA_FCTRL21: NOCOMB=0 */
#define PWMA_FCTRL21_INIT 0x0U
/* OUTEN register mask */
#define PWMA_OUTEN_INIT_MASK 0x333U
/* MASK register mask */
#define PWMA_MASK_INIT_MASK 0x3333U
/* SWCOUT register mask */
#define PWMA_SWCOUT_INIT_MASK 0xFU
/* DTSRCSEL register mask */
#define PWMA_DTSRCSEL_INIT_MASK 0xFFU
/* MCTRL register mask */
#define PWMA_MCTRL_INIT_MASK 0x3333U
/* Gives information whether SM0 fractional block is available */
#define PWMA_SM0_FRACTIONAL_BLOCK_AVAILABLE 
/* Gives information whether SM1 fractional block is available */
#define PWMA_SM1_FRACTIONAL_BLOCK_AVAILABLE 
/* Gives information whether SM2 fractional block is available */
#define PWMA_SM2_FRACTIONAL_BLOCK_AVAILABLE 
/* Gives information whether SM3 fractional block is available */
#define PWMA_SM3_FRACTIONAL_BLOCK_AVAILABLE 

/* QSCI0_RATE: SBRL=54, FRAC_SBR=2 */
#define QSCI0_RATE_INIT 0x1B2U
/* QSCI0_CTRL1: LOOP=0, SWAI=0, RSRC=0, M=0, WAKE=0, POL=0, PE=0, PT=0, TEIE=0, TIIE=0, RFIE=0, REIE=0, TE=0, RE=0, RWU=0 */
#define QSCI0_CTRL1_INIT 0x0U
/* QSCI0_CTRL2: TFWM=0, RFWM=0, FIFO_EN=0, RIEIE=0, LINMODE=0, RIIE=0, TDE=0, RDE=0 */
#define QSCI0_CTRL2_INIT 0x0U
/* QSCI0_CTRL3: SBRH=0, SHEN=0 */
#define QSCI0_CTRL3_INIT 0x0U
/* BOARD_InitPeripherals defines for ADC */
/* Definition of peripheral ID */
#define ADC_PERIPHERAL ADC
/* Definition of the clock source */
#define ADC_CLOCK_SOURCE ADC_CLK_SRC
/* ADC interrupt vector ID (number). */
#define ADC_A_IRQN kADC12_CC0_VECTORn
/* ADC interrupt priority register (interrupt priority register/bitfield index). */
#define ADC_A_IRQ ADC12_CC0_IRQn
/* ADC interrupt handler identifier. */
#define ADC_A_IRQHANDLER ivINT_ADC12_CC0
/* Definition of the minimal index of the samples related to the registers LOLIM2, HILIM2 and OFFST2. */
#define ADC_MIN_REGS2_INDEX 16U
/* ADC_CTRL1: DMAEN0=0, STOP0=0, START0=1, SYNC0=1, EOSIE0=1, ZCIE=0, LLMTIE=0, HLMTIE=0, CHNCFG_L=0, SMODE=5 */
#define ADC_CTRL1_INIT 0x3805U
/* ADC_CTRL2: DMAEN1=0, STOP1=0, START1=1, SYNC1=1, CHNCFG_H=0, SIMULT=1, DIV0=3 */
#define ADC_CTRL2_INIT 0x3043U
/* ADC_ZXCTRL1: ZCE7=0, ZCE6=0, ZCE5=0, ZCE4=0, ZCE3=0, ZCE2=0, ZCE1=0, ZCE0=0 */
#define ADC_ZXCTRL1_INIT 0x0U
/* ADC_ZXCTRL2: ZCE15=0, ZCE14=0, ZCE13=0, ZCE12=0, ZCE11=0, ZCE10=0, ZCE9=0, ZCE8=0 */
#define ADC_ZXCTRL2_INIT 0x0U
/* ADC_CLIST1: SAMPLE3=3, SAMPLE2=2, SAMPLE1=1, SAMPLE0=0 */
#define ADC_CLIST1_INIT 0x3210U
/* ADC_CLIST2: SAMPLE7=7, SAMPLE6=6, SAMPLE5=5, SAMPLE4=4 */
#define ADC_CLIST2_INIT 0x7654U
/* ADC_CLIST3: SAMPLE11=11, SAMPLE10=10, SAMPLE9=8, SAMPLE8=8 */
#define ADC_CLIST3_INIT 0xBA88U
/* ADC_CLIST4: SAMPLE15=15, SAMPLE14=14, SAMPLE13=13, SAMPLE12=12 */
#define ADC_CLIST4_INIT 0xFEDCU
/* ADC_SDIS: DS=63736 */
#define ADC_SDIS_INIT 0xF8F8U
/* ADC_LOLIM0: LLMT=0 */
#define ADC_LOLIM0_INIT 0x0U
/* ADC_LOLIM1: LLMT=0 */
#define ADC_LOLIM1_INIT 0x0U
/* ADC_LOLIM2: LLMT=0 */
#define ADC_LOLIM2_INIT 0x0U
/* ADC_LOLIM3: LLMT=0 */
#define ADC_LOLIM3_INIT 0x0U
/* ADC_LOLIM4: LLMT=0 */
#define ADC_LOLIM4_INIT 0x0U
/* ADC_LOLIM5: LLMT=0 */
#define ADC_LOLIM5_INIT 0x0U
/* ADC_LOLIM6: LLMT=0 */
#define ADC_LOLIM6_INIT 0x0U
/* ADC_LOLIM7: LLMT=0 */
#define ADC_LOLIM7_INIT 0x0U
/* ADC_LOLIM8: LLMT=0 */
#define ADC_LOLIM8_INIT 0x0U
/* ADC_LOLIM9: LLMT=0 */
#define ADC_LOLIM9_INIT 0x0U
/* ADC_LOLIM10: LLMT=0 */
#define ADC_LOLIM10_INIT 0x0U
/* ADC_LOLIM11: LLMT=0 */
#define ADC_LOLIM11_INIT 0x0U
/* ADC_LOLIM12: LLMT=0 */
#define ADC_LOLIM12_INIT 0x0U
/* ADC_LOLIM13: LLMT=0 */
#define ADC_LOLIM13_INIT 0x0U
/* ADC_LOLIM14: LLMT=0 */
#define ADC_LOLIM14_INIT 0x0U
/* ADC_LOLIM15: LLMT=0 */
#define ADC_LOLIM15_INIT 0x0U
/* ADC_HILIM0: HLMT=4095 */
#define ADC_HILIM0_INIT 0x7FF8U
/* ADC_HILIM1: HLMT=4095 */
#define ADC_HILIM1_INIT 0x7FF8U
/* ADC_HILIM2: HLMT=4095 */
#define ADC_HILIM2_INIT 0x7FF8U
/* ADC_HILIM3: HLMT=4095 */
#define ADC_HILIM3_INIT 0x7FF8U
/* ADC_HILIM4: HLMT=4095 */
#define ADC_HILIM4_INIT 0x7FF8U
/* ADC_HILIM5: HLMT=4095 */
#define ADC_HILIM5_INIT 0x7FF8U
/* ADC_HILIM6: HLMT=4095 */
#define ADC_HILIM6_INIT 0x7FF8U
/* ADC_HILIM7: HLMT=4095 */
#define ADC_HILIM7_INIT 0x7FF8U
/* ADC_HILIM8: HLMT=4095 */
#define ADC_HILIM8_INIT 0x7FF8U
/* ADC_HILIM9: HLMT=4095 */
#define ADC_HILIM9_INIT 0x7FF8U
/* ADC_HILIM10: HLMT=4095 */
#define ADC_HILIM10_INIT 0x7FF8U
/* ADC_HILIM11: HLMT=4095 */
#define ADC_HILIM11_INIT 0x7FF8U
/* ADC_HILIM12: HLMT=4095 */
#define ADC_HILIM12_INIT 0x7FF8U
/* ADC_HILIM13: HLMT=4095 */
#define ADC_HILIM13_INIT 0x7FF8U
/* ADC_HILIM14: HLMT=4095 */
#define ADC_HILIM14_INIT 0x7FF8U
/* ADC_HILIM15: HLMT=4095 */
#define ADC_HILIM15_INIT 0x7FF8U
/* ADC_OFFST0: OFFSET=0 */
#define ADC_OFFST0_INIT 0x0U
/* ADC_OFFST1: OFFSET=0 */
#define ADC_OFFST1_INIT 0x0U
/* ADC_OFFST2: OFFSET=0 */
#define ADC_OFFST2_INIT 0x0U
/* ADC_OFFST3: OFFSET=0 */
#define ADC_OFFST3_INIT 0x0U
/* ADC_OFFST4: OFFSET=0 */
#define ADC_OFFST4_INIT 0x0U
/* ADC_OFFST5: OFFSET=0 */
#define ADC_OFFST5_INIT 0x0U
/* ADC_OFFST6: OFFSET=0 */
#define ADC_OFFST6_INIT 0x0U
/* ADC_OFFST7: OFFSET=0 */
#define ADC_OFFST7_INIT 0x0U
/* ADC_OFFST8: OFFSET=0 */
#define ADC_OFFST8_INIT 0x0U
/* ADC_OFFST9: OFFSET=0 */
#define ADC_OFFST9_INIT 0x0U
/* ADC_OFFST10: OFFSET=0 */
#define ADC_OFFST10_INIT 0x0U
/* ADC_OFFST11: OFFSET=0 */
#define ADC_OFFST11_INIT 0x0U
/* ADC_OFFST12: OFFSET=0 */
#define ADC_OFFST12_INIT 0x0U
/* ADC_OFFST13: OFFSET=0 */
#define ADC_OFFST13_INIT 0x0U
/* ADC_OFFST14: OFFSET=0 */
#define ADC_OFFST14_INIT 0x0U
/* ADC_OFFST15: OFFSET=0 */
#define ADC_OFFST15_INIT 0x0U
/* ADC_PWR: PUDELAY=26, APD=0, PD1=0, PD0=0 */
#define ADC_PWR_INIT 0x1DA4U
/* ADC_CAL: SEL_VREFH_B=0, SEL_VREFL_B=0, SEL_VREFH_A=0, SEL_VREFL_A=0 */
#define ADC_CAL_INIT 0x0U
/* ADC_GC1: GAIN7=0, GAIN6=0, GAIN5=0, GAIN4=0, GAIN3=0, GAIN2=0, GAIN1=0, GAIN0=0 */
#define ADC_GC1_INIT 0x0U
/* ADC_GC2: GAIN15=0, GAIN14=0, GAIN13=0, GAIN12=0, GAIN11=0, GAIN10=0, GAIN9=0, GAIN8=0 */
#define ADC_GC2_INIT 0x0U
/* ADC_SCTRL: SC=0 */
#define ADC_SCTRL_INIT 0x0U
/* ADC_PWR2: DIV1=3 */
#define ADC_PWR2_INIT 0x300U
/* ADC_CTRL3: UPDEN_H=0, UPDEN_L=0, DMASRC=0 */
#define ADC_CTRL3_INIT 0x0U
/* ADC_SCHLTEN: SCHLTEN=0 */
#define ADC_SCHLTEN_INIT 0x0U
/* ADC_ZXCTRL3: ZCE19=0, ZCE18=0, ZCE17=0, ZCE16=0 */
#define ADC_ZXCTRL3_INIT 0x0U
/* ADC_CLIST5: SEL_INTERNAL_1=0, SEL_TEMP_1=0, SEL_INTERNAL_0=0, SEL_TEMP_0=0, SAMPLE19=3, SAMPLE18=2, SAMPLE17=1, SAMPLE16=0 */
#define ADC_CLIST5_INIT 0xE4U
/* ADC_SDIS2: DS=15 */
#define ADC_SDIS2_INIT 0xFFFFU
/* ADC_LOLIM216: LLMT=0 */
#define ADC_LOLIM216_INIT 0x0U
/* ADC_LOLIM217: LLMT=0 */
#define ADC_LOLIM217_INIT 0x0U
/* ADC_LOLIM218: LLMT=0 */
#define ADC_LOLIM218_INIT 0x0U
/* ADC_LOLIM219: LLMT=0 */
#define ADC_LOLIM219_INIT 0x0U
/* ADC_HILIM216: HLMT=4095 */
#define ADC_HILIM216_INIT 0x7FF8U
/* ADC_HILIM217: HLMT=4095 */
#define ADC_HILIM217_INIT 0x7FF8U
/* ADC_HILIM218: HLMT=4095 */
#define ADC_HILIM218_INIT 0x7FF8U
/* ADC_HILIM219: HLMT=4095 */
#define ADC_HILIM219_INIT 0x7FF8U
/* ADC_OFFST216: OFFSET=0 */
#define ADC_OFFST216_INIT 0x0U
/* ADC_OFFST217: OFFSET=0 */
#define ADC_OFFST217_INIT 0x0U
/* ADC_OFFST218: OFFSET=0 */
#define ADC_OFFST218_INIT 0x0U
/* ADC_OFFST219: OFFSET=0 */
#define ADC_OFFST219_INIT 0x0U
/* ADC_GC3: GAIN19=0, GAIN18=0, GAIN17=0, GAIN16=0 */
#define ADC_GC3_INIT 0x0U
/* ADC_SCTRL2: SC=0 */
#define ADC_SCTRL2_INIT 0x0U
/* ADC_SCHLTEN2: SCHLTEN=0 */
#define ADC_SCHLTEN2_INIT 0x0U
/* BOARD_InitPeripherals defines for DACA */
/* Definition of peripheral ID. */
#define DACA_PERIPHERAL DACA
/* Definition of theDACAclock source frequency in Hertz */
#define DACA_CLK_SOURCE_FREQ_HZ 100000000U
/* DACA_CTRL0: FILT_EN=1, SYNCEDGE=0, WTMK_LVL=1, DMA_EN=0, HSLS=0, AUTO=0, SYNC_EN=0, FORMAT=0, PDN=0 */
#define DACA_CTRL0_INIT 0x1100U
/* DACA_DATAREG_FMT0: DATA=0 */
#define DACA_DATAREG_FMT0_INIT 0x0U
/* DACA_CTRL1: FILT_CNT=29 */
#define DACA_CTRL1_INIT 0x1DU
/* BOARD_InitPeripherals defines for DACB */
/* Definition of peripheral ID. */
#define DACB_PERIPHERAL DACB
/* Definition of theDACBclock source frequency in Hertz */
#define DACB_CLK_SOURCE_FREQ_HZ 100000000U
/* DACB_CTRL0: FILT_EN=1, SYNCEDGE=0, WTMK_LVL=1, DMA_EN=0, HSLS=0, AUTO=0, SYNC_EN=0, FORMAT=0, PDN=0 */
#define DACB_CTRL0_INIT 0x1100U
/* DACB_DATAREG_FMT0: DATA=0 */
#define DACB_DATAREG_FMT0_INIT 0x0U
/* DACB_CTRL1: FILT_CNT=29 */
#define DACB_CTRL1_INIT 0x1DU
/* Definition of peripheral ID */
#define CMPA_PERIPHERAL CMPA
/* CMPA_CR0: FILTER_CNT=0, HYSTCTR=0 */
#define CMPA_CR0_INIT 0x0U
/* CMPA_CR1: SE=0, WE=0, PMODE=1, INV=0, COS=0, OPE=0, EN=1 */
#define CMPA_CR1_INIT 0x11U
/* CMPA_FPR: FILT_PER=0 */
#define CMPA_FPR_INIT 0x0U
/* CMPA_SCR: DMAEN=0, IER=1, IEF=1 */
#define CMPA_SCR_INIT 0x18U
/* CMPA_DACCR: VOSEL=176 */
#define CMPA_DACCR_INIT 0xB0U
/* CMPA_MUXCR: DACEN=1, VRSEL=0, PSEL=0, MSEL=7 */
#define CMPA_MUXCR_INIT 0x87U
/* CMPA interrupt vector ID (number). */
#define CMPA_IRQN kCMPA_VECTORn
/* CMPA interrupt priority register (interrupt priority register/bitfield index). */
#define CMPA_IRQ CMPA_IRQn
/* CMPA interrupt handler identifier. */
#define CMPA_IRQHANDLER ivINT_CMPA
/* Definition of peripheral ID */
#define CMPB_PERIPHERAL CMPB
/* CMPB_CR0: FILTER_CNT=0, HYSTCTR=0 */
#define CMPB_CR0_INIT 0x0U
/* CMPB_CR1: SE=0, WE=0, PMODE=1, INV=0, COS=0, OPE=0, EN=1 */
#define CMPB_CR1_INIT 0x11U
/* CMPB_FPR: FILT_PER=0 */
#define CMPB_FPR_INIT 0x0U
/* CMPB_SCR: DMAEN=0, IER=1, IEF=0 */
#define CMPB_SCR_INIT 0x10U
/* CMPB_DACCR: VOSEL=249 */
#define CMPB_DACCR_INIT 0xF9U
/* CMPB_MUXCR: DACEN=1, VRSEL=0, PSEL=3, MSEL=7 */
#define CMPB_MUXCR_INIT 0x9FU
/* CMPB interrupt vector ID (number). */
#define CMPB_IRQN kCMPB_VECTORn
/* CMPB interrupt priority register (interrupt priority register/bitfield index). */
#define CMPB_IRQ CMPB_IRQn
/* CMPB interrupt handler identifier. */
#define CMPB_IRQHANDLER ivINT_CMPB
/* I2C0_A1: AD=0 */
#define I2C0_A1_INIT 0x0U
/* I2C0_F: MULT=0, ICR=0 */
#define I2C0_F_INIT 0x0U
/* I2C0_C1: IICEN=0, IICIE=0, MST=0, TX=0, TXAK=0, DMAEN=0 */
#define I2C0_C1_INIT 0x0U
/* I2C0_C2: GCAEN=0, ADEXT=0, HDRS=0, RMEN=0, AD=0 */
#define I2C0_C2_INIT 0x0U
/* I2C0_FLT: SHEN=0, FLT=15 */
#define I2C0_FLT_INIT 0xFU
/* I2C0_SMB: FACK=0, ALERTEN=0, SIICAEN=0, TCKSEL=0 */
#define I2C0_SMB_INIT 0x0U
/* I2C0_SLTH: SSLT=0 */
#define I2C0_SLTH_INIT 0x0U
/* I2C0_SLTL: SSLT=0 */
#define I2C0_SLTL_INIT 0x0U
/* QSCI1_RATE: SBRL=54, FRAC_SBR=2 */
#define QSCI1_RATE_INIT 0x1B2U
/* QSCI1_CTRL1: LOOP=0, SWAI=0, RSRC=0, M=0, WAKE=0, POL=0, PE=0, PT=0, TEIE=0, TIIE=0, RFIE=0, REIE=0, TE=0, RE=0, RWU=0 */
#define QSCI1_CTRL1_INIT 0x0U
/* QSCI1_CTRL2: TFWM=0, RFWM=0, FIFO_EN=0, RIEIE=0, LINMODE=0, RIIE=0, TDE=0, RDE=0 */
#define QSCI1_CTRL2_INIT 0x0U
/* QSCI1_CTRL3: SBRH=0, SHEN=0 */
#define QSCI1_CTRL3_INIT 0x0U
/* BOARD_InitPeripherals defines for PIT0 */
/* Definition of peripheral ID. */
#define PIT0_PERIPHERAL PIT0
/* Definition of the PIT0 clock source frequency in Hertz */
#define PIT0_CLK_SOURCE_FREQ_HZ 100000000U
/* Definition of the PIT0 counter clock source frequency in Hertz divided by prescaler */
#define PIT0_COUNTER_CLK_SOURCE_FREQ_HZ 100000000U
/* Definition of the PIT0 counter roll-over frequency in Hertz */
#define PIT0_ROLLOVER_FREQ_HZ 15361U
/* PIT0_CTRL: SLAVE=0, CLKSEL=0, PRESCALER=0, PRIE=0, CNT_EN=1 */
#define PIT0_CTRL_INIT 0x1U
/* PIT0_MOD: MODULO_VALUE=6509 */
#define PIT0_MOD_INIT 0x196DU

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
