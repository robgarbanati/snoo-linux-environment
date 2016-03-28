/* linux/include/asm/arch-W90XXXX/regs-clock.h
 *
 * Copyright (c) 2003,2004,2005 Simtec Electronics <linux@simtec.co.uk>
 *		      http://armlinux.simtec.co.uk/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * W90XXXX clock register definitions
 *
 *  Changelog:
 *    18-Aug-2004 Ben Dooks         Added 2440 definitions
 *    08-Aug-2004 Herbert Pötzl     Added CLKCON definitions
 *    19-06-2003  Ben Dooks         Created file
 *    12-03-2004  Ben Dooks         Updated include protection
 *    29-Sep-2004 Ben Dooks	    Fixed usage for assembly inclusion
 *    10-Feb-2005 Ben Dooks	    Fixed CAMDIVN address (Guillaume Gourat)
 *    10-Mar-2005 Lucas Villa Real  Changed W90XXXX_VA to W90P9XX_VA
 *    27-Aug-2005 Ben Dooks	    Add clock-slow info
 *    20-Oct-2005 Ben Dooks	    Fixed overflow in PLL (Guillaume Gourat)
 *    20-Oct-2005 Ben Dooks	    Add masks for DCLK (Guillaume Gourat)
*/

#ifndef __ASM_ARM_REGS_CLOCK
#define __ASM_ARM_REGS_CLOCK "$Id: clock.h,v 1.4 2003/04/30 14:50:51 ben Exp $"

#define W90XXXX_CLKREG(x) ((x) + W90XXXX_VA_CLKPWR)
#define W90XXXX_CKREG(x) ((x) + W90XXXX_VA_EBI)


#define W90XXXX_CLKEN			  W90XXXX_CLKREG(0x00)
#define W90XXXX_CLKSEL			W90XXXX_CLKREG(0x04)
#define W90XXXX_CLKDIV			W90XXXX_CLKREG(0x08)
#define W90XXXX_CLKPLL0			W90XXXX_CLKREG(0x0C)
#define W90XXXX_CLKPLL1			W90XXXX_CLKREG(0x10)
#define W90XXXX_CLKPMCON		W90XXXX_CLKREG(0x14)
#define W90XXXX_CLKIRQWAKECON		W90XXXX_CLKREG(0x18)
#define W90XXXX_CLKIRQWAKEFALG		W90XXXX_CLKREG(0x1C)
#define W90XXXX_CLKIPSRST		W90XXXX_CLKREG(0x20)
#define W90XXXX_CLKEN1		W90XXXX_CLKREG(0x24)
#define W90XXXX_CLKDIV1		W90XXXX_CLKREG(0x28)
#define W90XXXX_CKSKEW			(W90XXXX_VA_EBI + 0x2C)

#define PLL0		0x00
#define PLL1		0x01
#define EXTAL15M	0x03

/* Define PLL initialization data structure */
typedef struct PLL_INIT_STRUCT//zswan add it
{
unsigned int		pll0;
    unsigned int		pll1;
    unsigned int		cpu_src;
    unsigned int		ahb_clk;
    unsigned int		apb_clk;
} WB_PLL_T;


/* Define PLL freq. setting */
#define PLL_DISABLE	0x12B63
#define	PLL_66MHZ	0x2B63
#define	PLL_100MHZ	0x4F64
#define PLL_120MHZ	0x4F63
#define PLL_133MHZ	0x22A2
#define	PLL_166MHZ	0x4124
#define	PLL_200MHZ	0x4F24


/* Define CPU clock source */
#define CPU_FROM_PLL0			0
#define CPU_FROM_PLL1			1
#define CPU_FROM_PLL0_DIV_2		2
#define CPU_FROM_EXTAL15M		3


/* Define AHB clock */
#define	AHB_CPUCLK_1_1	0
#define	AHB_CPUCLK_1_2	1
#define	AHB_CPUCLK_1_4	2
#define	AHB_CPUCLK_1_8	3

/* Define APB clock */
#define APB_AHB_1_2		1
#define APB_AHB_1_4		2
#define APB_AHB_1_8		3

#ifndef __ASSEMBLY__

#include <asm/div64.h>

static inline unsigned int
W90XXXX_get_pll(unsigned int pllval, unsigned int baseclk)
{
	//unsigned int mdiv, pdiv, sdiv;
	uint64_t fvco = 0;

//	mdiv = pllval >> W90XXXX_CLKPLL0;

//	do_div(fvco, (pdiv + 2) << sdiv);

	return (unsigned int)fvco;
}

#endif /* __ASSEMBLY__ */


#endif /* __ASM_ARM_REGS_CLOCK */
