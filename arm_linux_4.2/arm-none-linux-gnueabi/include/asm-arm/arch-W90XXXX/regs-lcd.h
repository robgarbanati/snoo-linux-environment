/* linux/include/asm/arch-w90p910/regs-lcd.h
 *
 * Copyright (c) 2003 Simtec Electronics <linux@simtec.co.uk>
 *		      http://www.simtec.co.uk/products/SWLINUX/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 *
 *
 *  Changelog:
 *    12-06-2003     BJD     Created file
 *    26-06-2003     BJD     Updated LCDCON register definitions
 *    12-03-2004     BJD     Updated include protection
 *    10-03-2005     LCVR    Changed W90P910_VA to W90P9XX_VA
*/


#ifndef ___ASM_ARCH_REGS_LCD_H
#define ___ASM_ARCH_REGS_LCD_H "$Id: lcd.h,v 1.3 2003/06/26 13:25:06 ben Exp $"

#define W90P910_LCDREG(x) ((x) + W90XXXX_VA_LCD)

/* LCD control registers */
#define W90P910_LCDCON1	    W90P910_LCDREG(0x00)
#define W90P910_LCDCON2	    W90P910_LCDREG(0x04)
#define W90P910_LCDCON3	    W90P910_LCDREG(0x08)
#define W90P910_LCDCON4	    W90P910_LCDREG(0x0C)
#define W90P910_LCDCON5	    W90P910_LCDREG(0x10)

#define W90P910_LCDCON1_CLKVAL(x)  ((x) << 8)
#define W90P910_LCDCON1_MMODE	   (1<<7)
#define W90P910_LCDCON1_DSCAN4	   (0<<5)
#define W90P910_LCDCON1_STN4	   (1<<5)
#define W90P910_LCDCON1_STN8	   (2<<5)
#define W90P910_LCDCON1_TFT	   (3<<5)

#define W90P910_LCDCON1_STN1BPP	   (0<<1)
#define W90P910_LCDCON1_STN2GREY   (1<<1)
#define W90P910_LCDCON1_STN4GREY   (2<<1)
#define W90P910_LCDCON1_STN8BPP	   (3<<1)
#define W90P910_LCDCON1_STN12BPP   (4<<1)

#define W90P910_LCDCON1_TFT1BPP	   (8<<1)
#define W90P910_LCDCON1_TFT2BPP	   (9<<1)
#define W90P910_LCDCON1_TFT4BPP	   (10<<1)
#define W90P910_LCDCON1_TFT8BPP	   (11<<1)
#define W90P910_LCDCON1_TFT16BPP   (12<<1)
#define W90P910_LCDCON1_TFT24BPP   (13<<1)

#define W90P910_LCDCON1_ENVID	   (1)

#define W90P910_LCDCON1_MODEMASK    0x1E

#define W90P910_LCDCON2_VBPD(x)	    ((x) << 24)
#define W90P910_LCDCON2_LINEVAL(x)  ((x) << 14)
#define W90P910_LCDCON2_VFPD(x)	    ((x) << 6)
#define W90P910_LCDCON2_VSPW(x)	    ((x) << 0)

#define W90P910_LCDCON2_GET_VBPD(x) ( ((x) >> 24) & 0xFF)
#define W90P910_LCDCON2_GET_VFPD(x) ( ((x) >>  6) & 0xFF)
#define W90P910_LCDCON2_GET_VSPW(x) ( ((x) >>  0) & 0x3F)

#define W90P910_LCDCON3_HBPD(x)	    ((x) << 19)
#define W90P910_LCDCON3_WDLY(x)	    ((x) << 19)
#define W90P910_LCDCON3_HOZVAL(x)   ((x) << 8)
#define W90P910_LCDCON3_HFPD(x)	    ((x) << 0)
#define W90P910_LCDCON3_LINEBLANK(x)((x) << 0)

#define W90P910_LCDCON3_GET_HBPD(x) ( ((x) >> 19) & 0x7F)
#define W90P910_LCDCON3_GET_HFPD(x) ( ((x) >>  0) & 0xFF)

#define W90P910_LCDCON4_MVAL(x)	    ((x) << 8)
#define W90P910_LCDCON4_HSPW(x)	    ((x) << 0)
#define W90P910_LCDCON4_WLH(x)	    ((x) << 0)

#define W90P910_LCDCON4_GET_HSPW(x) ( ((x) >>  0) & 0xFF)

#define W90P910_LCDCON5_BPP24BL	    (1<<12)
#define W90P910_LCDCON5_FRM565	    (1<<11)
#define W90P910_LCDCON5_INVVCLK	    (1<<10)
#define W90P910_LCDCON5_INVVLINE    (1<<9)
#define W90P910_LCDCON5_INVVFRAME   (1<<8)
#define W90P910_LCDCON5_INVVD	    (1<<7)
#define W90P910_LCDCON5_INVVDEN	    (1<<6)
#define W90P910_LCDCON5_INVPWREN    (1<<5)
#define W90P910_LCDCON5_INVLEND	    (1<<4)
#define W90P910_LCDCON5_PWREN	    (1<<3)
#define W90P910_LCDCON5_ENLEND	    (1<<2)
#define W90P910_LCDCON5_BSWP	    (1<<1)
#define W90P910_LCDCON5_HWSWP	    (1<<0)

/* framebuffer start addressed */
#define W90P910_LCDSADDR1   W90P910_LCDREG(0x14)
#define W90P910_LCDSADDR2   W90P910_LCDREG(0x18)
#define W90P910_LCDSADDR3   W90P910_LCDREG(0x1C)

#define W90P910_LCDBANK(x)	((x) << 21)
#define W90P910_LCDBASEU(x)	(x)

#define W90P910_OFFSIZE(x)	((x) << 11)
#define W90P910_PAGEWIDTH(x)	(x)

/* colour lookup and miscellaneous controls */

#define W90P910_REDLUT	   W90P910_LCDREG(0x20)
#define W90P910_GREENLUT   W90P910_LCDREG(0x24)
#define W90P910_BLUELUT	   W90P910_LCDREG(0x28)

#define W90P910_DITHMODE   W90P910_LCDREG(0x4C)
#define W90P910_TPAL	   W90P910_LCDREG(0x50)

#define W90P910_TPAL_EN		(1<<24)

/* interrupt info */
#define W90P910_LCDINTPND  W90P910_LCDREG(0x54)
#define W90P910_LCDSRCPND  W90P910_LCDREG(0x58)
#define W90P910_LCDINTMSK  W90P910_LCDREG(0x5C)
#define W90P910_LCDINT_FIWSEL	(1<<2)
#define	W90P910_LCDINT_FRSYNC	(1<<1)
#define W90P910_LCDINT_FICNT	(1<<0)

#define W90P910_LPCSEL	   W90P910_LCDREG(0x60)

#define W90P910_TFTPAL(x)  W90P910_LCDREG((0x400 + (x)*4))

#endif /* ___ASM_ARCH_REGS_LCD_H */



