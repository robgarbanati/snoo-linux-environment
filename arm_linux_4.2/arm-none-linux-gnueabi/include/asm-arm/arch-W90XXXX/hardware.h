/* linux/include/asm-arm/arch-w90p910/hardware.h
 *
 * Copyright (c) 2006 Winbond Electronics
 *   shirley yu <clyu2@winbond.com>
 *
 * W90P910 - hardware
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Changelog:
 *   23-Aug-2006  clyu created file
*/

#ifndef __ASM_ARCH_HARDWARE_H
#define __ASM_ARCH_HARDWARE_H

#ifndef __ASSEMBLY__

/* external functions for GPIO support
 *
 * These allow various different clients to access the same GPIO
 * registers without conflicting. If your driver only owns the entire
 * GPIO register, then it is safe to ioremap/__raw_{read|write} to it.
*/

/* w90p910_gpio_cfgpin
 *
 * set the configuration of the given pin to the value passed.
 *
 * eg:
 *    w90p910_gpio_cfgpin(W90P910_GPA0, W90P910_GPA0_ADDR0);
 *    w90p910_gpio_cfgpin(W90P910_GPE8, W90P910_GPE8_SDDAT1);
*/

extern void w90p910_gpio_cfgpin(unsigned int pin, unsigned int function);

extern unsigned int w90p910_gpio_getcfg(unsigned int pin);

/* w90p910_gpio_getirq
 *
 * turn the given pin number into the corresponding IRQ number
 *
 * returns:
 *	< 0 = no interrupt for this pin
 *	>=0 = interrupt number for the pin
*/

extern int w90p910_gpio_getirq(unsigned int pin);

/* w90p910_gpio_irqfilter
 *
 * set the irq filtering on the given pin
 *
 * on = 0 => disable filtering
 *      1 => enable filtering
 *
 * config = W90P910_EINTFLT_PCLK or W90P910_EINTFLT_EXTCLK orred with
 *          width of filter (0 through 63)
 *
 *
*/

extern int w90p910_gpio_irqfilter(unsigned int pin, unsigned int on,
				  unsigned int config);

/* w90p910_gpio_pullup
 *
 * configure the pull-up control on the given pin
 *
 * to = 1 => disable the pull-up
 *      0 => enable the pull-up
 *
 * eg;
 *
 *   w90p910_gpio_pullup(W90P910_GPB0, 0);
 *   w90p910_gpio_pullup(W90P910_GPE8, 0);
*/

extern void w90p910_gpio_pullup(unsigned int pin, unsigned int to);

extern void w90p910_gpio_setpin(unsigned int pin, unsigned int to);

extern unsigned int w90p910_gpio_getpin(unsigned int pin);

extern unsigned int w90p910_modify_misccr(unsigned int clr, unsigned int chg);

#endif /* __ASSEMBLY__ */

#include <asm/sizes.h>
#include <asm/arch/map.h>
//#include <asm/arch/wblib.h>//zswan add it20070511
/* machine specific hardware definitions should go after this */

/* currently here until moved into config (todo) */
#define CONFIG_NO_MULTIWORD_IO
#define PCIMEM_BASE		0xC0000000//clyu
#define PCIBIOS_MIN_IO          0xE0000000//ZSWAN
#define PCIBIOS_MIN_MEM       0xC0000000//ZSWAN
#define pcibios_assign_all_busses()     0//ZSWAN
#endif /* __ASM_ARCH_HARDWARE_H */
