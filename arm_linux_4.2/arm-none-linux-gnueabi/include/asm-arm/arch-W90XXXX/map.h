/* linux/include/asm-arm/arch-w90p910/map.h
 *
 * (c) 2006 Winbond Electronics
 *  shirley yu <clyu2@winbond.com>
 *  vincen  wan<zswan@winbond.com.tw>
 
 * W90P910 - Memory map definitions
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Changelog:
 *  22-Aug-2006 clyu   Created file
*/

#ifndef __ASM_ARCH_MAP_H
#define __ASM_ARCH_MAP_H

/* we have a bit of a tight squeeze to fit all our registers from
 * 0xF00000000 upwards, since we use all of the nGCS space in some
 * capacity, and also need to fit the W90P910 registers in as well...
 *
 * we try to ensure stuff like the IRQ registers are available for
 * an single MOVS instruction (ie, only 8 bits of set data)
 *
 * Note, we are trying to remove some of these from the implementation
 * as they are only useful to certain drivers...
 */

#ifndef __ASSEMBLY__
#define W90XXXX_ADDR(x)	  ((void __iomem *)0xF0000000 + (x))
#else
#define W90XXXX_ADDR(x)	  (0xF0000000 + (x))
#endif


#define AHB_IO_BASE		0xB0000000
#define APB_IO_BASE		0xB8000000
#define CLOCKPW_BASE	(APB_IO_BASE+0x200)
#define AIC_IO_BASE		(APB_IO_BASE+0x2000)
#define TIMER_IO_BASE	(APB_IO_BASE+0x1000)

/* interrupt controller is the first thing we put in, to make
 * the assembly code for the irq detection easier
 */

/*****************************************************************
*w90p910,w90p920,w90n960. All have the controller as follow:
******************************************************************/
#define W90XXXX_VA_IRQ	   W90XXXX_ADDR(0x00000000)
#define W90XXXX_PA_IRQ	   (0xB8002000)
#define W90XXXX_SZ_IRQ	   SZ_4K

#define W90XXXX_VA_GCR	   W90XXXX_ADDR(0x08002000)
#define W90XXXX_PA_GCR	   (0xB0000000)
#define W90XXXX_SZ_GCR	   SZ_4K

/* Clock and Power management */
#define W90XXXX_VA_CLKPWR (W90XXXX_VA_GCR+0x200)
#define W90XXXX_PA_CLKPWR  (0xB0000200)
#define W90XXXX_SZ_CLKPWR  SZ_4K

/* EBI management */
#define W90XXXX_VA_EBI  W90XXXX_ADDR(0x00001000)
#define W90XXXX_PA_EBI  (0xB0001000)
#define W90XXXX_SZ_EBI  SZ_4K


/* External MAC control */
#define W90XXXX_VA_EMC 	   W90XXXX_ADDR(0x00003000)
#define W90XXXX_PA_EMC 	   (0xB0003000)
#define W90XXXX_SZ_EMC 	   SZ_4K

/* GDMA control */
#define W90XXXX_VA_GDMA 	   W90XXXX_ADDR(0x00004000)
#define W90XXXX_PA_GDMA 	   (0xB0004000)
#define W90XXXX_SZ_GDMA 	   SZ_4K

/* USB host controller ----YCHUANG update here,by zswan add it 2007/03/09*/
#define W90XXXX_VA_USBEHCIHOST W90XXXX_ADDR(0x00005000)
#define W90XXXX_PA_USBEHCIHOST (0xB0005000)
#define W90XXXX_SZ_USBEHCIHOST SZ_4K

#define W90XXXX_VA_USBOHCIHOST W90XXXX_ADDR(0x00007000)
#define W90XXXX_PA_USBOHCIHOST (0xB0007000)
#define W90XXXX_SZ_USBOHCIHOST SZ_4K


/* UARTs */
#define W90XXXX_VA_UART	   W90XXXX_ADDR(0x08000000)
#define W90XXXX_PA_UART	   (0xB8000000)
#define W90XXXX_SZ_UART	   SZ_4K

/* Timers */
#define W90XXXX_VA_TIMER   W90XXXX_ADDR(0x08001000)
#define W90XXXX_PA_TIMER   (0xB8001000)
#define W90XXXX_SZ_TIMER   SZ_4K//SZ_1M

#define VA_IIC_BASE	   (W90XXXX_VA_IIC)

/* GPIO ports */
#define W90XXXX_VA_GPIO	   W90XXXX_ADDR(0x08003000)
#define W90XXXX_PA_GPIO	   (0xB8003000)
#define W90XXXX_SZ_GPIO	   SZ_4K


/* I2C hardware controller */
#define W90XXXX_VA_I2C	   W90XXXX_ADDR(0x08006000)
#define W90XXXX_PA_I2C	   (0xB8006000)
#define W90XXXX_SZ_I2C	   SZ_4K


#define W90XXXX_SDRAM_PA    (0x00000000)
/*****************************************************************
*w90p920,w90n960 have pci controller,but have not lcd,2d,smartcard
******************************************************************/
#ifdef CONFIG_CPU_W90P910//only 910 have lcd,2d,sm

/* LCD controller */
#define W90XXXX_VA_LCD	   W90XXXX_ADDR(0x00008000)
#define W90XXXX_PA_LCD	   (0xB0008000)
#define W90XXXX_SZ_LCD	   SZ_4K

/* 2D */
#define W90XXXX_VA_GE W90XXXX_ADDR(0x0000B000)
#define W90XXXX_PA_GE (0xB000B000)
#define W90XXXX_SZ_GE SZ_4K

/* Smart card host interface control register */
#define W90XXXX_VA_SC	   W90XXXX_ADDR(0x08005000)
#define W90XXXX_PA_SC	   (0xB8005000)
#define W90XXXX_SZ_SC	   SZ_4K

#else//920,960 have pci.

/* PCI interface controller */
#define W90XXXX_VA_PCI 	   W90XXXX_ADDR(0x00002000)
#define W90XXXX_PA_PCI 	   (0xB0002000)
#define W90XXXX_SZ_PCI 	   SZ_4K

#endif
/*****************************************************************
*w90n960 have not controller as follows,but 920,910 have them.
******************************************************************/
#ifndef CONFIG_CPU_W90N960//only 960 have not follows 

/* ATAPI */
#define W90XXXX_VA_ATAPI W90XXXX_ADDR(0x0000A000)
#define W90XXXX_PA_ATAPI (0xB000A000)
#define W90XXXX_SZ_ATAPI SZ_4K
/* ADC */
#define W90XXXX_VA_ADC	   W90XXXX_ADDR(0x0800A000)
#define W90XXXX_PA_ADC	   (0xB800A000)
#define W90XXXX_SZ_ADC	   SZ_4K

/* Keypad Interface Control Registers */
#define W90XXXX_VA_KPI	   W90XXXX_ADDR(0x08008000)
#define W90XXXX_PA_KPI	   (0xB8008000)
#define W90XXXX_SZ_KPI	   SZ_4K

/* PS2 Interface Control Registers */
#define W90XXXX_VA_PS2	   W90XXXX_ADDR(0x08009000)
#define W90XXXX_PA_PS2	   (0xB8009000)
#define W90XXXX_SZ_PS2	   SZ_4K

/* Pulse Width Modulation(PWM) Control Registers */
#define W90XXXX_VA_PWM	   W90XXXX_ADDR(0x08007000)
#define W90XXXX_PA_PWM	   (0xB8007000)
#define W90XXXX_SZ_PWM	   SZ_4K

/* RTC */
#define W90XXXX_VA_RTC	   W90XXXX_ADDR(0x08004000)
#define W90XXXX_PA_RTC	   (0xB8004000)
#define W90XXXX_SZ_RTC	   SZ_4K

/* Audio Controller controller */
#define W90XXXX_VA_ACTL	   W90XXXX_ADDR(0x00009000)
#define W90XXXX_PA_ACTL	   (0xB0009000)
#define W90XXXX_SZ_ACTL	   SZ_4K

/* DMA controller */
#define W90XXXX_VA_DMA	   W90XXXX_ADDR(0x0000c000)//zswan chang it 20070510,listen to lzxu
#define W90XXXX_PA_DMA	   (0xB000c000)
#define W90XXXX_SZ_DMA	   SZ_4K
/* FMI controller */
#define W90XXXX_VA_FMI	   W90XXXX_ADDR(0x0000d000)//zswan change it 20070301
#define W90XXXX_PA_FMI	   (0xB000d000)
#define W90XXXX_SZ_FMI	   SZ_4K

/* USB Device port */
#define W90XXXX_VA_USBDEV  W90XXXX_ADDR(0x00006000)
#define W90XXXX_PA_USBDEV  (0xB0006000)
#define W90XXXX_SZ_USBDEV  SZ_4K

#endif
/* Use a single interface for common resources between W90P9XX cpus */
#if 0
#define W90P9XX_PA_IRQ      W90P910_PA_IRQ
//#define W90P9XX_PA_USBHOST  W90P910_PA_USBHOST
#define W90P9XX_PA_USBEHCIHOST  W90P910_PA_USBEHCIHOST//zswan add it ,by YCHUANG UPDATE
#define W90P9XX_PA_USBOHCIHOST  W90P910_PA_USBOHCIHOST
#define W90P9XX_PA_DMA      W90P910_PA_DMA
#define W90P9XX_PA_CLKPWR   W90P910_PA_CLKPWR
#define W90P9XX_PA_GCR		W90P910_PA_GCR
#define W90P9XX_PA_EBI		W90P910_PA_EBI
#define W90P9XX_PA_LCD      W90P910_PA_LCD
#define W90P9XX_PA_UART     W90P910_PA_UART
#define W90P9XX_PA_TIMER    W90P910_PA_TIMER
#define W90P9XX_PA_USBDEV   W90P910_PA_USBDEV
#define W90P9XX_PA_I2C      W90P910_PA_I2C
#define W90P9XX_PA_GPIO     W90P910_PA_GPIO
#define W90P9XX_PA_RTC      W90P910_PA_RTC
#define W90P9XX_PA_SC      	W90P910_PA_SC
#define W90P9XX_PA_ADC      W90P910_PA_ADC
#define W90P9XX_PA_KPI      W90P910_PA_KPI
#define W90P9XX_PA_PS2      W90P910_PA_PS2
#endif

#endif /* __ASM_ARCH_MAP_H */
