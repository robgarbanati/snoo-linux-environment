/* linux/include/asm/arch-w90p910/regs-rtc.h
 *
 * Copyright (c) 2003 Simtec Electronics <linux@simtec.co.uk>
 *		      http://www.simtec.co.uk/products/SWLINUX/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * W90P910 Internal RTC register definition
 *
 *  Changelog:
 *    19-06-2003     BJD     Created file
 *    12-03-2004     BJD     Updated include protection
 *    15-01-2005     LCVR    Changed W90P910_VA to W90P9XX_VA (s3c2400 support)
*/

#ifndef __ASM_ARCH_REGS_RTC_H
#define __ASM_ARCH_REGS_RTC_H __FILE__

#define W90P910_RTCREG(x) ((x) + W90XXXX_VA_RTC)

#define W90P910_RTCCON	      W90P910_RTCREG(0x40)
#define W90P910_RTCCON_RTCEN  (1<<0)
#define W90P910_RTCCON_CLKSEL (1<<1)
#define W90P910_RTCCON_CNTSEL (1<<2)
#define W90P910_RTCCON_CLKRST (1<<3)

#define W90P910_TICNT	      W90P910_RTCREG(0x44)
#define W90P910_TICNT_ENABLE  (1<<7)

#define W90P910_RTCALM	      W90P910_RTCREG(0x50)
#define W90P910_RTCALM_ALMEN  (1<<6)
#define W90P910_RTCALM_YEAREN (1<<5)
#define W90P910_RTCALM_MONEN  (1<<4)
#define W90P910_RTCALM_DAYEN  (1<<3)
#define W90P910_RTCALM_HOUREN (1<<2)
#define W90P910_RTCALM_MINEN  (1<<1)
#define W90P910_RTCALM_SECEN  (1<<0)

#define W90P910_RTCALM_ALL \
  W90P910_RTCALM_ALMEN | W90P910_RTCALM_YEAREN | W90P910_RTCALM_MONEN |\
  W90P910_RTCALM_DAYEN | W90P910_RTCALM_HOUREN | W90P910_RTCALM_MINEN |\
  W90P910_RTCALM_SECEN


#define W90P910_ALMSEC	      W90P910_RTCREG(0x54)
#define W90P910_ALMMIN	      W90P910_RTCREG(0x58)
#define W90P910_ALMHOUR	      W90P910_RTCREG(0x5c)

#define W90P910_ALMDATE	      W90P910_RTCREG(0x60)
#define W90P910_ALMMON	      W90P910_RTCREG(0x64)
#define W90P910_ALMYEAR	      W90P910_RTCREG(0x68)

#define W90P910_RTCRST	      W90P910_RTCREG(0x6c)

#define W90P910_RTCSEC	      W90P910_RTCREG(0x70)
#define W90P910_RTCMIN	      W90P910_RTCREG(0x74)
#define W90P910_RTCHOUR	      W90P910_RTCREG(0x78)
#define W90P910_RTCDATE	      W90P910_RTCREG(0x7c)
#define W90P910_RTCDAY	      W90P910_RTCREG(0x80)
#define W90P910_RTCMON	      W90P910_RTCREG(0x84)
#define W90P910_RTCYEAR	      W90P910_RTCREG(0x88)


#endif /* __ASM_ARCH_REGS_RTC_H */
