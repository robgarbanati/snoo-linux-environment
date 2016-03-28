/* linux/include/asm/arch-w90p910/regs0watchdog.h
 *
 * Copyright (c) 2003 Simtec Electronics <linux@simtec.co.uk>
 *		      http://www.simtec.co.uk/products/SWLINUX/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * W90P910 Watchdog timer control
 *
 *  Changelog:
 *    21-06-2003     BJD     Created file
 *    12-03-2004     BJD     Updated include protection
 *    10-03-2005     LCVR    Changed W90P910_VA to W90P9XX_VA
*/


#ifndef __ASM_ARCH_REGS_WATCHDOG_H
#define __ASM_ARCH_REGS_WATCHDOG_H "$Id: watchdog.h,v 1.2 2003/04/29 13:31:09 ben Exp $"

#define W90XXXX_WDOGREG(x) ((x) + W90XXXX_VA_WATCHDOG)

#define W90XXXX_WTCON	   W90XXXX_WDOGREG(0x00)
#define W90XXXX_WTDAT	   W90XXXX_WDOGREG(0x04)
#define W90XXXX_WTCNT	   W90XXXX_WDOGREG(0x08)

/* the watchdog can either generate a reset pulse, or an
 * interrupt.
 */

#define W90XXXX_WTCON_RSTEN   (0x01)
#define W90XXXX_WTCON_INTEN   (1<<2)
#define W90XXXX_WTCON_ENABLE  (1<<5)

#define W90XXXX_WTCON_DIV16   (0<<3)
#define W90XXXX_WTCON_DIV32   (1<<3)
#define W90XXXX_WTCON_DIV64   (2<<3)
#define W90XXXX_WTCON_DIV128  (3<<3)

#define W90XXXX_WTCON_PRESCALE(x) ((x) << 8)
#define W90XXXX_WTCON_PRESCALE_MASK (0xff00)

#endif /* __ASM_ARCH_REGS_WATCHDOG_H */


