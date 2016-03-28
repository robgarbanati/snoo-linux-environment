/* linux/include/asm/arch-W90XXXX/regs-irq.h
 *
 * Copyright (c) 2006 Winbond Electronics
 * All rights reserved.
 *
 * shirley yu (clyu2@winbond.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 *
 *
 * Changelog:
 *  22-Aug-2006 clyu  Created file
 */


#ifndef ___ASM_ARCH_REGS_IRQ_H
#define ___ASM_ARCH_REGS_IRQ_H "$Id: irq.h,v 1.3 2003/03/25 21:29:06 ben Exp $"

/* interrupt controller */

#define W90XXXX_IRQREG(x)   ((x) + W90XXXX_VA_IRQ)

/* ----- Define	the interrupt controller registers ----- */
#define W90XXXX_AIC_SCR1	W90XXXX_IRQREG(0x004)		/* Source control register 7 (timer0) */
#define W90XXXX_AIC_SCR6	W90XXXX_IRQREG(0x018)		/* Source control register 6 (UART) */
#define W90XXXX_AIC_SCR7	W90XXXX_IRQREG(0x01C)		/* Source control register 7 (timer0) */
#define W90XXXX_AIC_SCR8	W90XXXX_IRQREG(0x020)		/* Source control register 8 (timer1) */
#define W90XXXX_AIC_ISR		W90XXXX_IRQREG(0x108)     	/* Interrupt status register */
#define W90XXXX_AIC_IPER	W90XXXX_IRQREG(0x10C)
#define W90XXXX_AIC_ISNR	W90XXXX_IRQREG(0x110)
#define W90XXXX_AIC_IMR		W90XXXX_IRQREG(0x114)		/* Interrupt mask register */
#define W90XXXX_AIC_GEN		W90XXXX_IRQREG(0x084)
#define W90XXXX_AIC_MECR	W90XXXX_IRQREG(0x120)		/* Mask enable command register */
#define W90XXXX_AIC_MDCR	W90XXXX_IRQREG(0x124)		/* Mask disable command register */
#define W90XXXX_AIC_SSCR	W90XXXX_IRQREG(0x128)		/* Source set command register */
#define W90XXXX_AIC_SCCR	W90XXXX_IRQREG(0x12C)
#define W90XXXX_AIC_EOSCR	W90XXXX_IRQREG(0x130)

/*zswan add it for grop at 2007/03/26*/

#define W90XXXX_AIC_GASR	W90XXXX_IRQREG(0x88)
#define W90XXXX_AIC_GSCR	W90XXXX_IRQREG(0x8C)

#endif /* ___ASM_ARCH_REGS_IRQ_H */
