/* linux/include/asm/arch-W90XXXX/regs-lcd.h
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
 *    10-03-2005     LCVR    Changed W90XXXX_VA to W90P9XX_VA
*/


#ifndef ___ASM_ARCH_REGS_PCI_H
#define ___ASM_ARCH_REGS_PCI_H "$Id: lcd.h,v 1.3 2003/06/26 13:25:06 ben Exp $"

#define W90XXXX_PCIREG(x) ((x) + W90XXXX_VA_PCI)

/* LCD control registers */
#define W90XXXX_PCICTR	    W90XXXX_PCIREG(0x00)
#define W90XXXX_PCISTR	    W90XXXX_PCIREG(0x04)
#define W90XXXX_PCILATIMER  W90XXXX_PCIREG(0x08)
#define W90XXXX_PCICLK	    W90XXXX_PCIREG(0x0C)
#define W90XXXX_PCIINTEN    W90XXXX_PCIREG(0x10)
#define W90XXXX_PCIINT	    W90XXXX_PCIREG(0x14)
#define W90XXXX_PCI_CFGADDR W90XXXX_PCIREG(0x20)
#define W90XXXX_PCI_CFGDATA W90XXXX_PCIREG(0x24)
#define W90XXXX_PCIARB	    W90XXXX_PCIREG(0x4C)
#define W90XXXX_PCIBIST	    W90XXXX_PCIREG(0x50)

#define W90XXXX_PCI_IO_BASE		0xE0000000
#define W90XXXX_PCI_IO_END		0xE000FFFF
#define W90XXXX_PCI_IO_SIZE		0x10000		

#define W90XXXX_PCI_MEM_BASE	0xC0000000
#define W90XXXX_PCI_MEM_END		0xDFFFEFFFF
#define W90XXXX_PCI_MEM_SIZE	0x20000000		

#endif /* ___ASM_ARCH_REGS_PCI_H */



