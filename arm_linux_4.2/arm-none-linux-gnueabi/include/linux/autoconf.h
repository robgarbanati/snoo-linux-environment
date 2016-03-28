/*
 * Automatically generated C config: don't edit
 * Linux kernel version: 2.6.17
 * Thu Dec 13 23:29:40 2007
 */
#define AUTOCONF_INCLUDED
#define CONFIG_ARM 1
#define CONFIG_MMU 1
#define CONFIG_RWSEM_GENERIC_SPINLOCK 1
#define CONFIG_GENERIC_HWEIGHT 1
#define CONFIG_GENERIC_CALIBRATE_DELAY 1
#define CONFIG_VECTORS_BASE 0xffff0000

/*
 * Code maturity level options
 */
#define CONFIG_EXPERIMENTAL 1
#define CONFIG_BROKEN_ON_SMP 1
#define CONFIG_INIT_ENV_ARG_LIMIT 32

/*
 * General setup
 */
#define CONFIG_LOCALVERSION ""
#define CONFIG_LOCALVERSION_AUTO 1
#define CONFIG_SWAP 1
#define CONFIG_SYSVIPC 1
#define CONFIG_BSD_PROCESS_ACCT 1
#undef CONFIG_BSD_PROCESS_ACCT_V3
#define CONFIG_SYSCTL 1
#undef CONFIG_IKCONFIG
#undef CONFIG_RELAY
#define CONFIG_INITRAMFS_SOURCE ""
#define CONFIG_UID16 1
#define CONFIG_CC_OPTIMIZE_FOR_SIZE 1
#undef CONFIG_EMBEDDED
#define CONFIG_KALLSYMS 1
#undef CONFIG_KALLSYMS_EXTRA_PASS
#define CONFIG_HOTPLUG 1
#define CONFIG_PRINTK 1
#define CONFIG_BUG 1
#define CONFIG_ELF_CORE 1
#define CONFIG_BASE_FULL 1
#define CONFIG_FUTEX 1
#define CONFIG_EPOLL 1
#define CONFIG_SHMEM 1
#define CONFIG_SLAB 1
#undef CONFIG_TINY_SHMEM
#define CONFIG_BASE_SMALL 0
#undef CONFIG_SLOB

/*
 * Loadable module support
 */
#undef CONFIG_MODULES

/*
 * Block layer
 */
#undef CONFIG_BLK_DEV_IO_TRACE

/*
 * IO Schedulers
 */
#define CONFIG_IOSCHED_NOOP 1
#define CONFIG_IOSCHED_AS 1
#define CONFIG_IOSCHED_DEADLINE 1
#define CONFIG_IOSCHED_CFQ 1
#define CONFIG_DEFAULT_AS 1
#undef CONFIG_DEFAULT_DEADLINE
#undef CONFIG_DEFAULT_CFQ
#undef CONFIG_DEFAULT_NOOP
#define CONFIG_DEFAULT_IOSCHED "anticipatory"

/*
 * System Type
 */
#define CONFIG_ARCH_W90XXXX 1
#define CONFIG_CPU_W90P910 1
#undef CONFIG_CPU_W90P920
#undef CONFIG_CPU_W90N960
#define CONFIG_CPU_W90XXXX 1

/*
 * W90XXXX Boot
 */
#undef CONFIG_W90XXXX_BOOT_ERROR_RESET

/*
 * W90XXXX SET CPU/AHB/APB CLOCK
 */
#undef CONFIG_AHB_CPU_1_1
#define CONFIG_AHB_CPU_1_2 1
#define CONFIG_APB_AHB_1_2 1
#define CONFIG_CPU_FROM_PLL0 1
#undef CONFIG_CPU_FROM_PLL1
#undef CONFIG_CPU_FROM_PLL0_DIV_2
#undef CONFIG_CPU_FROM_EXTAL15M
#undef CONFIG_PLL0_66MHZ
#undef CONFIG_PLL0_100MHZ
#undef CONFIG_PLL0_133MHZ
#undef CONFIG_PLL0_166MHZ
#define CONFIG_PLL0_200MHZ 1
#define CONFIG_PLL1_66MHZ 1

/*
 * W90XXXX Setup
 */
#undef CONFIG_W90XXXX_DMA
#define CONFIG_W90XXXX_LOWLEVEL_UART_PORT 0

/*
 * Processor Type
 */
#define CONFIG_CPU_32 1
#define CONFIG_CPU_ARM926T 1
#define CONFIG_CPU_32v5 1
#define CONFIG_CPU_ABRT_EV5TJ 1
#define CONFIG_CPU_CACHE_VIVT 1
#define CONFIG_CPU_COPY_V4WB 1
#define CONFIG_CPU_TLB_V4WBI 1

/*
 * Processor Features
 */
#define CONFIG_ARM_THUMB 1
#undef CONFIG_CPU_ICACHE_DISABLE
#undef CONFIG_CPU_DCACHE_DISABLE
#undef CONFIG_CPU_DCACHE_WRITETHROUGH
#undef CONFIG_CPU_CACHE_ROUND_ROBIN

/*
 * Bus support
 */
#undef CONFIG_PCI

/*
 * PCCARD (PCMCIA/CardBus) support
 */
#undef CONFIG_PCCARD

/*
 * Kernel Features
 */
#undef CONFIG_PREEMPT
#undef CONFIG_NO_IDLE_HZ
#define CONFIG_HZ 100
#define CONFIG_AEABI 1
#define CONFIG_OABI_COMPAT 1
#undef CONFIG_ARCH_DISCONTIGMEM_ENABLE
#define CONFIG_SELECT_MEMORY_MODEL 1
#define CONFIG_FLATMEM_MANUAL 1
#undef CONFIG_DISCONTIGMEM_MANUAL
#undef CONFIG_SPARSEMEM_MANUAL
#define CONFIG_FLATMEM 1
#define CONFIG_FLAT_NODE_MEM_MAP 1
#undef CONFIG_SPARSEMEM_STATIC
#define CONFIG_SPLIT_PTLOCK_CPUS 4096
#define CONFIG_ALIGNMENT_TRAP 1

/*
 * Boot options
 */
#define CONFIG_ZBOOT_ROM_TEXT 0x0
#define CONFIG_ZBOOT_ROM_BSS 0x0
#define CONFIG_CMDLINE "root=/dev/ram0 console=ttyS0,115200n8 initrd=0xa00000,3490067 mem=32M"
#undef CONFIG_XIP_KERNEL

/*
 * Floating point emulation
 */

/*
 * At least one emulation must be selected
 */
#define CONFIG_FPE_NWFPE 1
#undef CONFIG_FPE_NWFPE_XP
#undef CONFIG_FPE_FASTFPE
#undef CONFIG_VFP

/*
 * Userspace binary formats
 */
#define CONFIG_BINFMT_ELF 1
#undef CONFIG_BINFMT_AOUT
#undef CONFIG_BINFMT_MISC

/*
 * Power management options
 */
#undef CONFIG_PM
#undef CONFIG_APM

/*
 * Networking
 */
#undef CONFIG_NET

/*
 * Device Drivers
 */

/*
 * Generic Driver Options
 */
#undef CONFIG_STANDALONE
#undef CONFIG_PREVENT_FIRMWARE_BUILD
#undef CONFIG_FW_LOADER

/*
 * Connector - unified userspace <-> kernelspace linker
 */

/*
 * Memory Technology Devices (MTD)
 */
#undef CONFIG_MTD

/*
 * Parallel port support
 */
#undef CONFIG_PARPORT

/*
 * Plug and Play support
 */

/*
 * Block devices
 */
#undef CONFIG_BLK_DEV_COW_COMMON
#define CONFIG_BLK_DEV_LOOP 1
#undef CONFIG_BLK_DEV_CRYPTOLOOP
#define CONFIG_BLK_DEV_RAM 1
#define CONFIG_BLK_DEV_RAM_COUNT 16
#define CONFIG_BLK_DEV_RAM_SIZE 8192
#define CONFIG_BLK_DEV_INITRD 1
#undef CONFIG_CDROM_PKTCDVD

/*
 * ATA/ATAPI/MFM/RLL support
 */
#undef CONFIG_IDE

/*
 * SCSI device support
 */
#undef CONFIG_RAID_ATTRS
#undef CONFIG_SCSI

/*
 * Multi-device support (RAID and LVM)
 */
#undef CONFIG_MD

/*
 * Fusion MPT device support
 */
#undef CONFIG_FUSION

/*
 * IEEE 1394 (FireWire) support
 */

/*
 * I2O device support
 */

/*
 * ISDN subsystem
 */

/*
 * Input device support
 */
#define CONFIG_INPUT 1

/*
 * Userland interfaces
 */
#define CONFIG_INPUT_MOUSEDEV 1
#undef CONFIG_INPUT_MOUSEDEV_PSAUX
#define CONFIG_INPUT_MOUSEDEV_SCREEN_X 1024
#define CONFIG_INPUT_MOUSEDEV_SCREEN_Y 768
#undef CONFIG_INPUT_JOYDEV
#undef CONFIG_INPUT_TSDEV
#undef CONFIG_INPUT_EVDEV
#undef CONFIG_INPUT_EVBUG
#undef CONFIG_INPUT_KEYPAD

/*
 * Input Device Drivers
 */
#undef CONFIG_INPUT_KEYBOARD
#undef CONFIG_INPUT_MOUSE
#undef CONFIG_INPUT_JOYSTICK
#undef CONFIG_INPUT_TOUCHSCREEN
#undef CONFIG_INPUT_MISC

/*
 * Hardware I/O ports
 */
#undef CONFIG_SERIO
#undef CONFIG_GAMEPORT

/*
 * Character devices
 */
#define CONFIG_VT 1
#define CONFIG_VT_CONSOLE 1
#define CONFIG_HW_CONSOLE 1
#undef CONFIG_SERIAL_NONSTANDARD
#undef CONFIG_W90P910_SC

/*
 * Serial drivers
 */
#undef CONFIG_SERIAL_8250

/*
 * Non-8250 serial port support
 */
#undef CONFIG_SERIAL_W90XXXX
#undef CONFIG_SERIAL_W90XXXX_PORT1
#undef CONFIG_SERIAL_W90P910_PORT1_FULL_MODERM_Y
#define CONFIG_SERIAL_W90P910_PORT1_FULL_MODERM_N 1
#undef CONFIG_SERIAL_W90P910_PORT3
#undef CONFIG_SERIAL_W90XXXX_PORT2
#undef CONFIG_SERIAL_W90P910_PORT4
#define CONFIG_UNIX98_PTYS 1
#undef CONFIG_LEGACY_PTYS

/*
 * IPMI
 */
#undef CONFIG_IPMI_HANDLER

/*
 * Watchdog Cards
 */
#undef CONFIG_WATCHDOG
#undef CONFIG_NVRAM
#undef CONFIG_W90XXXX_USB_CLIENT
#undef CONFIG_DTLK
#undef CONFIG_R3964

/*
 * Ftape, the floppy tape device driver
 */
#undef CONFIG_RAW_DRIVER

/*
 * TPM devices
 */
#undef CONFIG_TCG_TPM
#undef CONFIG_TELCLOCK
#undef CONFIG_I2C_W90XXXX
#undef CONFIG_TOUCHSCREEN_W90XXXX
#undef CONFIG_PS2MOUSE_W90XXXX

/*
 * I2C support
 */
#undef CONFIG_I2C

/*
 * SPI support
 */
#undef CONFIG_SPI
#undef CONFIG_SPI_MASTER

/*
 * Dallas's 1-wire bus
 */
#undef CONFIG_W1

/*
 * Hardware Monitoring support
 */
#undef CONFIG_HWMON
#undef CONFIG_HWMON_VID

/*
 * Misc devices
 */

/*
 * LED devices
 */
#undef CONFIG_NEW_LEDS

/*
 * LED drivers
 */

/*
 * LED Triggers
 */

/*
 * Multimedia devices
 */
#undef CONFIG_VIDEO_DEV
#define CONFIG_VIDEO_V4L2 1

/*
 * Digital Video Broadcasting Devices
 */

/*
 * Graphics support
 */
#undef CONFIG_FB

/*
 * Console display driver support
 */
#undef CONFIG_VGA_CONSOLE
#define CONFIG_DUMMY_CONSOLE 1

/*
 * Sound
 */
#undef CONFIG_SOUND

/*
 * USB support
 */
#define CONFIG_USB_ARCH_HAS_HCD 1
#define CONFIG_USB_ARCH_HAS_OHCI 1
#define CONFIG_USB_ARCH_HAS_EHCI 1
#undef CONFIG_USB
#undef CONFIG_USB_W90P910_OHCI
#undef CONFIG_USB_W90P910_EHCI

/*
 * NOTE: USB_STORAGE enables SCSI, and 'SCSI disk support'
 */

/*
 * USB Gadget Support
 */
#undef CONFIG_USB_GADGET

/*
 * MMC/SD Card support
 */
#undef CONFIG_MMC

/*
 * Real Time Clock
 */
#define CONFIG_RTC_LIB 1
#undef CONFIG_RTC_CLASS

/*
 * File systems
 */
#undef CONFIG_EXT2_FS
#undef CONFIG_EXT3_FS
#undef CONFIG_REISERFS_FS
#undef CONFIG_JFS_FS
#undef CONFIG_FS_POSIX_ACL
#undef CONFIG_XFS_FS
#undef CONFIG_MINIX_FS
#undef CONFIG_ROMFS_FS
#undef CONFIG_INOTIFY
#undef CONFIG_QUOTA
#define CONFIG_DNOTIFY 1
#undef CONFIG_AUTOFS_FS
#undef CONFIG_AUTOFS4_FS
#undef CONFIG_FUSE_FS

/*
 * CD-ROM/DVD Filesystems
 */
#undef CONFIG_ISO9660_FS
#undef CONFIG_UDF_FS

/*
 * DOS/FAT/NT Filesystems
 */
#undef CONFIG_MSDOS_FS
#undef CONFIG_VFAT_FS
#undef CONFIG_NTFS_FS

/*
 * Pseudo filesystems
 */
#undef CONFIG_PROC_FS
#define CONFIG_SYSFS 1
#undef CONFIG_TMPFS
#undef CONFIG_HUGETLB_PAGE
#define CONFIG_RAMFS 1
#undef CONFIG_CONFIGFS_FS

/*
 * Miscellaneous filesystems
 */
#undef CONFIG_ADFS_FS
#undef CONFIG_AFFS_FS
#undef CONFIG_HFS_FS
#undef CONFIG_HFSPLUS_FS
#undef CONFIG_BEFS_FS
#undef CONFIG_BFS_FS
#undef CONFIG_EFS_FS
#undef CONFIG_CRAMFS
#undef CONFIG_VXFS_FS
#undef CONFIG_HPFS_FS
#undef CONFIG_QNX4FS_FS
#undef CONFIG_SYSV_FS
#undef CONFIG_UFS_FS

/*
 * Partition Types
 */
#undef CONFIG_PARTITION_ADVANCED
#define CONFIG_MSDOS_PARTITION 1

/*
 * Native Language Support
 */
#undef CONFIG_NLS

/*
 * Profiling support
 */
#undef CONFIG_PROFILING

/*
 * Kernel hacking
 */
#undef CONFIG_PRINTK_TIME
#undef CONFIG_MAGIC_SYSRQ
#undef CONFIG_DEBUG_KERNEL
#define CONFIG_LOG_BUF_SHIFT 14
#define CONFIG_DEBUG_BUGVERBOSE 1
#undef CONFIG_DEBUG_FS
#define CONFIG_FRAME_POINTER 1
#undef CONFIG_UNWIND_INFO
#undef CONFIG_DEBUG_USER

/*
 * Security options
 */
#undef CONFIG_KEYS
#undef CONFIG_SECURITY

/*
 * Cryptographic options
 */
#undef CONFIG_CRYPTO

/*
 * Hardware crypto devices
 */

/*
 * Library routines
 */
#undef CONFIG_CRC_CCITT
#undef CONFIG_CRC16
#undef CONFIG_CRC32
#undef CONFIG_LIBCRC32C
