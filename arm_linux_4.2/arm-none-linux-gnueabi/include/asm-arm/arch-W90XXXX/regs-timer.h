/* linux/include/asm/arch-W90XXXX/regs-timer.h
 *
 * Copyright (c) 2006 winbond Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * W90XXXX Timer configuration
 *
 *  Changelog:
 *    22-08-2003     clyu     Created file
*/


#ifndef __ASM_ARCH_REGS_TIMER_H
#define __ASM_ARCH_REGS_TIMER_H "$Id: timer.h,v 1.4 2003/05/06 19:30:50 ben Exp $"

#define W90XXXX_TIMERREG(x) (W90XXXX_VA_TIMER + (x))

#define W90XXXX_TCSR0	      W90XXXX_TIMERREG(0x000)
#define W90XXXX_TCSR1	      W90XXXX_TIMERREG(0x004)
#define W90XXXX_TICR0	      W90XXXX_TIMERREG(0x008)
#define W90XXXX_TICR1	      W90XXXX_TIMERREG(0x00C)
#define W90XXXX_TDR0	      W90XXXX_TIMERREG(0x010)
#define W90XXXX_TDR1	      W90XXXX_TIMERREG(0x014)
#define W90XXXX_TISR	      W90XXXX_TIMERREG(0x018)
#define W90XXXX_WTCR	      W90XXXX_TIMERREG(0x01C)
#define W90XXXX_TCSR2	      W90XXXX_TIMERREG(0x020)
#define W90XXXX_TCSR3	      W90XXXX_TIMERREG(0x024)
#define W90XXXX_TICR2	      W90XXXX_TIMERREG(0x028)
#define W90XXXX_TICR3	      W90XXXX_TIMERREG(0x02C)
#define W90XXXX_TDR2	      W90XXXX_TIMERREG(0x030)
#define W90XXXX_TDR3	      W90XXXX_TIMERREG(0x034)
#define W90XXXX_TCSR4	      W90XXXX_TIMERREG(0x040)
#define W90XXXX_TICR4	      W90XXXX_TIMERREG(0x048)
#define W90XXXX_TDR4	      W90XXXX_TIMERREG(0x050)

#define WTCR_WTE			  0x0080
#define WTCR_WTIE			  0x0040
#define WTCR_WTIS			  0x0030
#define WTCR_WTIF			  0x0008
#define WTCR_WTRF			  0x0004
#define WTCR_WTRE			  0x0002
#define WTCR_WTR			  0x0001

#define WTIS0	0x00
#define WTIS1	0x01
#define WTIS2	0x02
#define WTIS3	0x03



#endif /*  __ASM_ARCH_REGS_TIMER_H */



