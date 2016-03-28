/* linux/include/asm-arm/arch-W90XXXX/regs-nand.h
 *
 * Copyright (c) 2004,2005 Simtec Electronics <linux@simtec.co.uk>
 *		      http://www.simtec.co.uk/products/SWLINUX/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * W90XXXX NAND register definitions
 *
 *  Changelog:
 *    18-Aug-2004    BJD     Copied file from 2.4 and updated
 *    01-May-2005    BJD     Added definitions for s3c2440 controller
*/

#ifndef __ASM_ARM_REGS_NAND
#define __ASM_ARM_REGS_NAND "$Id: nand.h,v 1.3 2003/12/09 11:36:29 ben Exp $"


#define W90XXXX_NFREG(x) (x)

#define W90XXXX_NFCONF  W90XXXX_NFREG(0x00)
#define W90XXXX_NFCMD   W90XXXX_NFREG(0x04)
#define W90XXXX_NFADDR  W90XXXX_NFREG(0x08)
#define W90XXXX_NFDATA  W90XXXX_NFREG(0x0C)
#define W90XXXX_NFSTAT  W90XXXX_NFREG(0x10)
#define W90XXXX_NFECC   W90XXXX_NFREG(0x14)


#define W90XXXX_NFCONF_EN          (1<<15)
#define W90XXXX_NFCONF_512BYTE     (1<<14)
#define W90XXXX_NFCONF_4STEP       (1<<13)
#define W90XXXX_NFCONF_INITECC     (1<<12)
#define W90XXXX_NFCONF_nFCE        (1<<11)
#define W90XXXX_NFCONF_TACLS(x)    ((x)<<8)
#define W90XXXX_NFCONF_TWRPH0(x)   ((x)<<4)
#define W90XXXX_NFCONF_TWRPH1(x)   ((x)<<0)

#define W90XXXX_NFSTAT_BUSY        (1<<0)


#endif /* __ASM_ARM_REGS_NAND */

