/* linux/include/asm-arm/arch-w90p910/spi.h
 *
 * Copyright (c) 2006 Simtec Electronics
 *	Ben Dooks <ben@simtec.co.uk>
 *
 * W90P910 - SPI Controller platform_device info
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef __ASM_ARCH_SPI_H
#define __ASM_ARCH_SPI_H __FILE__

struct w90p910_spi_info;
struct spi_board_info;

struct w90p910_spi_info {
	unsigned long		 pin_cs;	/* simple gpio cs */

	unsigned long		 board_size;
	struct spi_board_info	*board_info;

	void (*set_cs)(struct w90p910_spi_info *spi, int cs, int pol);
};


#endif /* __ASM_ARCH_SPI_H */
