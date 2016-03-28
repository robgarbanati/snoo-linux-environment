/* linux/include/asm/arch-w90p910/regs-adc.h
 *
 * Copyright (c) 2004 Shannon Holland <holland@loser.net>
 *
 * This program is free software; yosu can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * W90P910 ADC registers
 *
 *  Changelog:
 *    27-09-2004     SAH     Created file
*/

#ifndef __ASM_ARCH_REGS_ADC_H
#define __ASM_ARCH_REGS_ADC_H "regs-adc.h"

#define W90P910_ADCREG(x) (x)

#define W90P910_ADCCON	   W90P910_ADCREG(0x00)
#define W90P910_ADCTSC	   W90P910_ADCREG(0x04)
#define W90P910_ADCDLY	   W90P910_ADCREG(0x08)
#define W90P910_ADCDAT0	   W90P910_ADCREG(0x0C)
#define W90P910_ADCDAT1	   W90P910_ADCREG(0x10)


/* ADCCON Register Bits */
#define W90P910_ADCCON_ECFLG		(1<<15)
#define W90P910_ADCCON_PRSCEN		(1<<14)
#define W90P910_ADCCON_PRSCVL(x)	(((x)&0xFF)<<6)
#define W90P910_ADCCON_PRSCVLMASK	(0xFF<<6)
#define W90P910_ADCCON_SELMUX(x)	(((x)&0x7)<<3)
#define W90P910_ADCCON_MUXMASK		(0x7<<3)
#define W90P910_ADCCON_STDBM		(1<<2)
#define W90P910_ADCCON_READ_START	(1<<1)
#define W90P910_ADCCON_ENABLE_START	(1<<0)
#define W90P910_ADCCON_STARTMASK	(0x3<<0)


/* ADCTSC Register Bits */
#define W90P910_ADCTSC_YM_SEN		(1<<7)
#define W90P910_ADCTSC_YP_SEN		(1<<6)
#define W90P910_ADCTSC_XM_SEN		(1<<5)
#define W90P910_ADCTSC_XP_SEN		(1<<4)
#define W90P910_ADCTSC_PULL_UP_DISABLE	(1<<3)
#define W90P910_ADCTSC_AUTO_PST		(1<<2)
#define W90P910_ADCTSC_XY_PST		(0x3<<0)

/* ADCDAT0 Bits */
#define W90P910_ADCDAT0_UPDOWN		(1<<15)
#define W90P910_ADCDAT0_AUTO_PST	(1<<14)
#define W90P910_ADCDAT0_XY_PST		(0x3<<12)
#define W90P910_ADCDAT0_XPDATA_MASK	(0x03FF)

/* ADCDAT1 Bits */
#define W90P910_ADCDAT1_UPDOWN		(1<<15)
#define W90P910_ADCDAT1_AUTO_PST	(1<<14)
#define W90P910_ADCDAT1_XY_PST		(0x3<<12)
#define W90P910_ADCDAT1_YPDATA_MASK	(0x03FF)

#endif /* __ASM_ARCH_REGS_ADC_H */


