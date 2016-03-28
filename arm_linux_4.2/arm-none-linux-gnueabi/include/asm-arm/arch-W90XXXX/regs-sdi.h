/* linux/include/asm/arch-w90p910/regs-sdi.h
 *
 * Copyright (c) 2004 Simtec Electronics <linux@simtec.co.uk>
 *		      http://www.simtec.co.uk/products/SWLINUX/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * W90P910 MMC/SDIO register definitions
 *
 *  Changelog:
 *    18-Aug-2004 Ben Dooks      Created initial file
 *    29-Nov-2004 Koen Martens   Added some missing defines, fixed duplicates
 *    29-Nov-2004 Ben Dooks	 Updated Koen's patch
*/

#ifndef __ASM_ARM_REGS_SDI
#define __ASM_ARM_REGS_SDI "regs-sdi.h"

#define W90P910_SDICON                (0x00)
#define W90P910_SDIPRE                (0x04)
#define W90P910_SDICMDARG             (0x08)
#define W90P910_SDICMDCON             (0x0C)
#define W90P910_SDICMDSTAT            (0x10)
#define W90P910_SDIRSP0               (0x14)
#define W90P910_SDIRSP1               (0x18)
#define W90P910_SDIRSP2               (0x1C)
#define W90P910_SDIRSP3               (0x20)
#define W90P910_SDITIMER              (0x24)
#define W90P910_SDIBSIZE              (0x28)
#define W90P910_SDIDCON               (0x2C)
#define W90P910_SDIDCNT               (0x30)
#define W90P910_SDIDSTA               (0x34)
#define W90P910_SDIFSTA               (0x38)
#define W90P910_SDIDATA               (0x3C)
#define W90P910_SDIIMSK               (0x40)

#define W90P910_SDICON_BYTEORDER      (1<<4)
#define W90P910_SDICON_SDIOIRQ        (1<<3)
#define W90P910_SDICON_RWAITEN        (1<<2)
#define W90P910_SDICON_FIFORESET      (1<<1)
#define W90P910_SDICON_CLOCKTYPE      (1<<0)

#define W90P910_SDICMDCON_ABORT       (1<<12)
#define W90P910_SDICMDCON_WITHDATA    (1<<11)
#define W90P910_SDICMDCON_LONGRSP     (1<<10)
#define W90P910_SDICMDCON_WAITRSP     (1<<9)
#define W90P910_SDICMDCON_CMDSTART    (1<<8)
#define W90P910_SDICMDCON_INDEX       (0xff)

#define W90P910_SDICMDSTAT_CRCFAIL    (1<<12)
#define W90P910_SDICMDSTAT_CMDSENT    (1<<11)
#define W90P910_SDICMDSTAT_CMDTIMEOUT (1<<10)
#define W90P910_SDICMDSTAT_RSPFIN     (1<<9)
#define W90P910_SDICMDSTAT_XFERING    (1<<8)
#define W90P910_SDICMDSTAT_INDEX      (0xff)

#define W90P910_SDIDCON_IRQPERIOD     (1<<21)
#define W90P910_SDIDCON_TXAFTERRESP   (1<<20)
#define W90P910_SDIDCON_RXAFTERCMD    (1<<19)
#define W90P910_SDIDCON_BUSYAFTERCMD  (1<<18)
#define W90P910_SDIDCON_BLOCKMODE     (1<<17)
#define W90P910_SDIDCON_WIDEBUS       (1<<16)
#define W90P910_SDIDCON_DMAEN         (1<<15)
#define W90P910_SDIDCON_STOP          (1<<14)
#define W90P910_SDIDCON_DATMODE	      (3<<12)
#define W90P910_SDIDCON_BLKNUM        (0x7ff)

/* constants for W90P910_SDIDCON_DATMODE */
#define W90P910_SDIDCON_XFER_READY    (0<<12)
#define W90P910_SDIDCON_XFER_CHKSTART (1<<12)
#define W90P910_SDIDCON_XFER_RXSTART  (2<<12)
#define W90P910_SDIDCON_XFER_TXSTART  (3<<12)

#define W90P910_SDIDCNT_BLKNUM_SHIFT  (12)

#define W90P910_SDIDSTA_RDYWAITREQ    (1<<10)
#define W90P910_SDIDSTA_SDIOIRQDETECT (1<<9)
#define W90P910_SDIDSTA_FIFOFAIL      (1<<8)	/* reserved on 2440 */
#define W90P910_SDIDSTA_CRCFAIL       (1<<7)
#define W90P910_SDIDSTA_RXCRCFAIL     (1<<6)
#define W90P910_SDIDSTA_DATATIMEOUT   (1<<5)
#define W90P910_SDIDSTA_XFERFINISH    (1<<4)
#define W90P910_SDIDSTA_BUSYFINISH    (1<<3)
#define W90P910_SDIDSTA_SBITERR       (1<<2)	/* reserved on 2410a/2440 */
#define W90P910_SDIDSTA_TXDATAON      (1<<1)
#define W90P910_SDIDSTA_RXDATAON      (1<<0)

#define W90P910_SDIFSTA_TFDET          (1<<13)
#define W90P910_SDIFSTA_RFDET          (1<<12)
#define W90P910_SDIFSTA_TXHALF         (1<<11)
#define W90P910_SDIFSTA_TXEMPTY        (1<<10)
#define W90P910_SDIFSTA_RFLAST         (1<<9)
#define W90P910_SDIFSTA_RFFULL         (1<<8)
#define W90P910_SDIFSTA_RFHALF         (1<<7)
#define W90P910_SDIFSTA_COUNTMASK      (0x7f)

#define W90P910_SDIIMSK_RESPONSECRC    (1<<17)
#define W90P910_SDIIMSK_CMDSENT        (1<<16)
#define W90P910_SDIIMSK_CMDTIMEOUT     (1<<15)
#define W90P910_SDIIMSK_RESPONSEND     (1<<14)
#define W90P910_SDIIMSK_READWAIT       (1<<13)
#define W90P910_SDIIMSK_SDIOIRQ        (1<<12)
#define W90P910_SDIIMSK_FIFOFAIL       (1<<11)
#define W90P910_SDIIMSK_CRCSTATUS      (1<<10)
#define W90P910_SDIIMSK_DATACRC        (1<<9)
#define W90P910_SDIIMSK_DATATIMEOUT    (1<<8)
#define W90P910_SDIIMSK_DATAFINISH     (1<<7)
#define W90P910_SDIIMSK_BUSYFINISH     (1<<6)
#define W90P910_SDIIMSK_SBITERR        (1<<5)	/* reserved 2440/2410a */
#define W90P910_SDIIMSK_TXFIFOHALF     (1<<4)
#define W90P910_SDIIMSK_TXFIFOEMPTY    (1<<3)
#define W90P910_SDIIMSK_RXFIFOLAST     (1<<2)
#define W90P910_SDIIMSK_RXFIFOFULL     (1<<1)
#define W90P910_SDIIMSK_RXFIFOHALF     (1<<0)

#endif /* __ASM_ARM_REGS_SDI */
