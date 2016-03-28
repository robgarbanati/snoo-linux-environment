/* linux/include/asm-arm/arch-w90p910/debug-macro.S
 *
 * Debugging macro include header
 *
 *  Copyright (C) 1994-1999 Russell King
 *  Copyright (C) 2005 Simtec Electronics
 *
 *  Moved from linux/arch/arm/kernel/debug.S by Ben Dooks
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Modifications:
 *     10-Mar-2005 LCVR  Changed W90P910_VA to W90P9XX_VA
*/

#include <asm/arch/map.h>
#include <asm/arch/regs-serial.h>
#include <asm/arch/regs-gpio.h>

#define W90P910_UART1_OFF (0x4000)
#define SHIFT_2440TXF (14-9)

		.macro addruart, rx
		mrc	p15, 0, \rx, c1, c0
		tst	\rx, #1
		ldreq	\rx, = W90P9XX_PA_UART
		ldrne	\rx, = W90P9XX_VA_UART
#if CONFIG_DEBUG_W90P910_UART != 0
		add	\rx, \rx, #(W90P910_UART1_OFF * CONFIG_DEBUG_W90P910_UART)
#endif
		.endm

		.macro	senduart,rd,rx
		str	\rd, [\rx, # W90P910_UTXH ]
		.endm

		.macro	busyuart, rd, rx
		ldr	\rd, [ \rx, # W90P910_UFCON ]
		tst	\rd, #W90P910_UFCON_FIFOMODE	@ fifo enabled?
		beq	1001f				@
		@ FIFO enabled...
1003:
		mrc	p15, 0, \rd, c1, c0
		tst	\rd, #1
		addeq	\rd, \rx, #(W90P9XX_PA_GPIO - W90P9XX_PA_UART)
		addne	\rd, \rx, #(W90P9XX_VA_GPIO - W90P9XX_VA_UART)
		bic	\rd, \rd, #0xff000
		ldr	\rd, [ \rd, # W90P910_GSTATUS1 - W90P910_GPIOREG(0) ]
		and	\rd, \rd, #0x00ff0000
		teq	\rd, #0x00440000		@ is it 2440?

		ldr	\rd, [ \rx, # W90P910_UFSTAT ]
		moveq	\rd, \rd, lsr #SHIFT_2440TXF
		tst	\rd, #W90P910_UFSTAT_TXFULL
		bne	1003b
		b	1002f

1001:
		@ busy waiting for non fifo
		ldr	\rd, [ \rx, # W90P910_UTRSTAT ]
		tst	\rd, #W90P910_UTRSTAT_TXFE
		beq	1001b

1002:		@ exit busyuart
		.endm

		.macro	waituart,rd,rx

		ldr	\rd, [ \rx, # W90P910_UFCON ]
		tst	\rd, #W90P910_UFCON_FIFOMODE	@ fifo enabled?
		beq	1001f				@
		@ FIFO enabled...
1003:
		mrc	p15, 0, \rd, c1, c0
		tst	\rd, #1
		addeq	\rd, \rx, #(W90P9XX_PA_GPIO - W90P9XX_PA_UART)
		addne	\rd, \rx, #(W90P9XX_VA_GPIO - W90P9XX_VA_UART)
		bic	\rd, \rd, #0xff000
		ldr	\rd, [ \rd, # W90P910_GSTATUS1 - W90P910_GPIOREG(0) ]
		and	\rd, \rd, #0x00ff0000
		teq	\rd, #0x00440000		@ is it 2440?

		ldr	\rd, [ \rx, # W90P910_UFSTAT ]
		andne	\rd, \rd, #W90P910_UFSTAT_TXMASK
		andeq	\rd, \rd, #S3C2440_UFSTAT_TXMASK
		teq	\rd, #0
		bne	1003b
		b	1002f

1001:
		@ idle waiting for non fifo
		ldr	\rd, [ \rx, # W90P910_UTRSTAT ]
		tst	\rd, #W90P910_UTRSTAT_TXFE
		beq	1001b

1002:		@ exit busyuart
		.endm
