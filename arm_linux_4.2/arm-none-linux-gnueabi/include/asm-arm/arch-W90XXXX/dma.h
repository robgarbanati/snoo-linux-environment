/* linux/include/asm-arm/arch-bast/dma.h
 *
 * Copyright (C) 2003,2004 Simtec Electronics
 *	Ben Dooks <ben@simtec.co.uk>
 *
 * Samsung W90P910X DMA support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Changelog:
 *  ??-May-2003 BJD   Created file
 *  ??-Jun-2003 BJD   Added more dma functionality to go with arch
 *  10-Nov-2004 BJD   Added sys_device support
*/

#ifndef __ASM_ARCH_DMA_H
#define __ASM_ARCH_DMA_H __FILE__

#include <linux/config.h>
#include <linux/sysdev.h>
#include "hardware.h"


/*
 * This is the maximum DMA address(physical address) that can be DMAd to.
 *
 */
#define MAX_DMA_ADDRESS		0x20000000
#define MAX_DMA_TRANSFER_SIZE   0x100000 /* Data Unit is half word  */


/* we have 4 dma channels */
#define W90P910_DMA_CHANNELS        (4)

/* types */

typedef enum {
	W90P910_DMA_IDLE,
	W90P910_DMA_RUNNING,
	W90P910_DMA_PAUSED
} w90p910_dma_state_t;


/* w90p910_dma_loadst_t
 *
 * This represents the state of the DMA engine, wrt to the loaded / running
 * transfers. Since we don't have any way of knowing exactly the state of
 * the DMA transfers, we need to know the state to make decisions on wether
 * we can
 *
 * W90P910_DMA_NONE
 *
 * There are no buffers loaded (the channel should be inactive)
 *
 * W90P910_DMA_1LOADED
 *
 * There is one buffer loaded, however it has not been confirmed to be
 * loaded by the DMA engine. This may be because the channel is not
 * yet running, or the DMA driver decided that it was too costly to
 * sit and wait for it to happen.
 *
 * W90P910_DMA_1RUNNING
 *
 * The buffer has been confirmed running, and not finisged
 *
 * W90P910_DMA_1LOADED_1RUNNING
 *
 * There is a buffer waiting to be loaded by the DMA engine, and one
 * currently running.
*/

typedef enum {
	W90P910_DMALOAD_NONE,
	W90P910_DMALOAD_1LOADED,
	W90P910_DMALOAD_1RUNNING,
	W90P910_DMALOAD_1LOADED_1RUNNING,
} w90p910_dma_loadst_t;

typedef enum {
	W90P910_RES_OK,
	W90P910_RES_ERR,
	W90P910_RES_ABORT
} w90p910_dma_buffresult_t;


typedef enum w90p910_dmasrc_e w90p910_dmasrc_t;

enum w90p910_dmasrc_e {
	W90P910_DMASRC_HW,      /* source is memory */
	W90P910_DMASRC_MEM      /* source is hardware */
};

/* enum w90p910_chan_op_e
 *
 * operation codes passed to the DMA code by the user, and also used
 * to inform the current channel owner of any changes to the system state
*/

enum w90p910_chan_op_e {
	W90P910_DMAOP_START,
	W90P910_DMAOP_STOP,
	W90P910_DMAOP_PAUSE,
	W90P910_DMAOP_RESUME,
	W90P910_DMAOP_FLUSH,
	W90P910_DMAOP_TIMEOUT,           /* internal signal to handler */
};

typedef enum w90p910_chan_op_e w90p910_chan_op_t;

/* flags */

#define W90P910_DMAF_SLOW         (1<<0)   /* slow, so don't worry about
					    * waiting for reloads */
#define W90P910_DMAF_AUTOSTART    (1<<1)   /* auto-start if buffer queued */

/* dma buffer */

typedef struct w90p910_dma_buf_s w90p910_dma_buf_t;

struct w90p910_dma_client {
	char                *name;
};

typedef struct w90p910_dma_client w90p910_dma_client_t;

/* w90p910_dma_buf_s
 *
 * internally used buffer structure to describe a queued or running
 * buffer.
*/

struct w90p910_dma_buf_s {
	w90p910_dma_buf_t   *next;
	int                  magic;        /* magic */
	int                  size;         /* buffer size in bytes */
	dma_addr_t           data;         /* start of DMA data */
	dma_addr_t           ptr;          /* where the DMA got to [1] */
	void                *id;           /* client's id */
};

/* [1] is this updated for both recv/send modes? */

typedef struct w90p910_dma_chan_s w90p910_dma_chan_t;

/* w90p910_dma_cbfn_t
 *
 * buffer callback routine type
*/

typedef void (*w90p910_dma_cbfn_t)(w90p910_dma_chan_t *, void *buf, int size,
				   w90p910_dma_buffresult_t result);

typedef int  (*w90p910_dma_opfn_t)(w90p910_dma_chan_t *,
				   w90p910_chan_op_t );

struct w90p910_dma_stats_s {
	unsigned long          loads;
	unsigned long          timeout_longest;
	unsigned long          timeout_shortest;
	unsigned long          timeout_avg;
	unsigned long          timeout_failed;
};

typedef struct w90p910_dma_stats_s w90p910_dma_stats_t;

/* struct w90p910_dma_chan_s
 *
 * full state information for each DMA channel
*/

struct w90p910_dma_chan_s {
	/* channel state flags and information */
	unsigned char          number;      /* number of this dma channel */
	unsigned char          in_use;      /* channel allocated */
	unsigned char          irq_claimed; /* irq claimed for channel */
	unsigned char          irq_enabled; /* irq enabled for channel */
	unsigned char          xfer_unit;   /* size of an transfer */

	/* channel state */

	w90p910_dma_state_t    state;
	w90p910_dma_loadst_t   load_state;
	w90p910_dma_client_t  *client;

	/* channel configuration */
	w90p910_dmasrc_t       source;
	unsigned long          dev_addr;
	unsigned long          load_timeout;
	unsigned int           flags;        /* channel flags */

	/* channel's hardware position and configuration */
	void __iomem           *regs;        /* channels registers */
	void __iomem           *addr_reg;    /* data address register */
	unsigned int           irq;          /* channel irq */
	unsigned long          dcon;         /* default value of DCON */

	/* driver handles */
	w90p910_dma_cbfn_t     callback_fn;  /* buffer done callback */
	w90p910_dma_opfn_t     op_fn;        /* channel operation callback */

	/* stats gathering */
	w90p910_dma_stats_t   *stats;
	w90p910_dma_stats_t    stats_store;

	/* buffer list and information */
	w90p910_dma_buf_t      *curr;        /* current dma buffer */
	w90p910_dma_buf_t      *next;        /* next buffer to load */
	w90p910_dma_buf_t      *end;         /* end of queue */

	/* system device */
	struct sys_device	dev;
};

/* the currently allocated channel information */
extern w90p910_dma_chan_t w90p910_chans[];

/* note, we don't really use dma_device_t at the moment */
typedef unsigned long dma_device_t;

/* functions --------------------------------------------------------------- */

/* w90p910_dma_request
 *
 * request a dma channel exclusivley
*/

extern int w90p910_dma_request(dmach_t channel,
			       w90p910_dma_client_t *, void *dev);


/* w90p910_dma_ctrl
 *
 * change the state of the dma channel
*/

extern int w90p910_dma_ctrl(dmach_t channel, w90p910_chan_op_t op);

/* w90p910_dma_setflags
 *
 * set the channel's flags to a given state
*/

extern int w90p910_dma_setflags(dmach_t channel,
				unsigned int flags);

/* w90p910_dma_free
 *
 * free the dma channel (will also abort any outstanding operations)
*/

extern int w90p910_dma_free(dmach_t channel, w90p910_dma_client_t *);

/* w90p910_dma_enqueue
 *
 * place the given buffer onto the queue of operations for the channel.
 * The buffer must be allocated from dma coherent memory, or the Dcache/WB
 * drained before the buffer is given to the DMA system.
*/

extern int w90p910_dma_enqueue(dmach_t channel, void *id,
			       dma_addr_t data, int size);

/* w90p910_dma_config
 *
 * configure the dma channel
*/

extern int w90p910_dma_config(dmach_t channel, int xferunit, int dcon);

/* w90p910_dma_devconfig
 *
 * configure the device we're talking to
*/

extern int w90p910_dma_devconfig(int channel, w90p910_dmasrc_t source,
				 int hwcfg, unsigned long devaddr);

/* w90p910_dma_getposition
 *
 * get the position that the dma transfer is currently at
*/

extern int w90p910_dma_getposition(dmach_t channel,
				   dma_addr_t *src, dma_addr_t *dest);

extern int w90p910_dma_set_opfn(dmach_t, w90p910_dma_opfn_t rtn);
extern int w90p910_dma_set_buffdone_fn(dmach_t, w90p910_dma_cbfn_t rtn);

/* DMA Register definitions */

#define W90P910_DMA_DISRC       (0x00)
#define W90P910_DMA_DISRCC      (0x04)
#define W90P910_DMA_DIDST       (0x08)
#define W90P910_DMA_DIDSTC      (0x0C)
#define W90P910_DMA_DCON        (0x10)
#define W90P910_DMA_DSTAT       (0x14)
#define W90P910_DMA_DCSRC       (0x18)
#define W90P910_DMA_DCDST       (0x1C)
#define W90P910_DMA_DMASKTRIG   (0x20)

#define W90P910_DISRCC_INC	(1<<0)
#define W90P910_DISRCC_APB	(1<<1)

#define W90P910_DMASKTRIG_STOP   (1<<2)
#define W90P910_DMASKTRIG_ON     (1<<1)
#define W90P910_DMASKTRIG_SWTRIG (1<<0)

#define W90P910_DCON_DEMAND     (0<<31)
#define W90P910_DCON_HANDSHAKE  (1<<31)
#define W90P910_DCON_SYNC_PCLK  (0<<30)
#define W90P910_DCON_SYNC_HCLK  (1<<30)

#define W90P910_DCON_INTREQ     (1<<29)

#define W90P910_DCON_CH0_XDREQ0	(0<<24)
#define W90P910_DCON_CH0_UART0	(1<<24)
#define W90P910_DCON_CH0_SDI	(2<<24)
#define W90P910_DCON_CH0_TIMER	(3<<24)
#define W90P910_DCON_CH0_USBEP1	(4<<24)

#define W90P910_DCON_CH1_XDREQ1	(0<<24)
#define W90P910_DCON_CH1_UART1	(1<<24)
#define W90P910_DCON_CH1_I2SSDI	(2<<24)
#define W90P910_DCON_CH1_SPI	(3<<24)
#define W90P910_DCON_CH1_USBEP2	(4<<24)

#define W90P910_DCON_CH2_I2SSDO	(0<<24)
#define W90P910_DCON_CH2_I2SSDI	(1<<24)
#define W90P910_DCON_CH2_SDI	(2<<24)
#define W90P910_DCON_CH2_TIMER	(3<<24)
#define W90P910_DCON_CH2_USBEP3	(4<<24)

#define W90P910_DCON_CH3_UART2	(0<<24)
#define W90P910_DCON_CH3_SDI	(1<<24)
#define W90P910_DCON_CH3_SPI	(2<<24)
#define W90P910_DCON_CH3_TIMER	(3<<24)
#define W90P910_DCON_CH3_USBEP4	(4<<24)

#define W90P910_DCON_SRCSHIFT   (24)
#define W90P910_DCON_SRCMASK	(7<<24)

#define W90P910_DCON_BYTE       (0<<20)
#define W90P910_DCON_HALFWORD   (1<<20)
#define W90P910_DCON_WORD       (2<<20)

#define W90P910_DCON_AUTORELOAD (0<<22)
#define W90P910_DCON_NORELOAD   (1<<22)
#define W90P910_DCON_HWTRIG     (1<<23)

#ifdef CONFIG_CPU_S3C2440
#define S3C2440_DIDSTC_CHKINT	(1<<2)

#define S3C2440_DCON_CH0_I2SSDO	(5<<24)
#define S3C2440_DCON_CH0_PCMIN	(6<<24)

#define S3C2440_DCON_CH1_PCMOUT	(5<<24)
#define S3C2440_DCON_CH1_SDI	(6<<24)

#define S3C2440_DCON_CH2_PCMIN	(5<<24)
#define S3C2440_DCON_CH2_MICIN	(6<<24)

#define S3C2440_DCON_CH3_MICIN	(5<<24)
#define S3C2440_DCON_CH3_PCMOUT	(6<<24)
#endif

#endif /* __ASM_ARCH_DMA_H */
