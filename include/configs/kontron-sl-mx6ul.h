/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2018 Kontron Electronics GmbH
 *
 * Configuration settings for the Kontron i.MX6UL boards/SoMs.
 */
#ifndef __KONTRON_MX6UL_CONFIG_H
#define __KONTRON_MX6UL_CONFIG_H

#include <asm/arch/imx-regs.h>
#include <linux/sizes.h>

#include "mx6_common.h"
#ifdef CONFIG_SPL_BUILD
#include "imx6_spl.h"
#endif

/* RAM */
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM

#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE

#define CONFIG_SYS_UBOOT_BASE		CONFIG_SYS_TEXT_BASE

/* Board and environment settings */
#define CONFIG_MXC_UART_BASE		UART4_BASE
#define CONFIG_HOSTNAME			"kontron-mx6ul"

#ifdef CONFIG_USB_EHCI_HCD
#define CONFIG_MXC_USB_PORTSC		(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS		0
#endif

/* Boot order for distro boot */
#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 1) \
	func(MMC, mmc, 0) \
	func(UBIFS, ubifs, 0, UBI, boot) \
	func(USB, usb, 0) \
	func(PXE, pxe, na) \
	func(DHCP, dhcp, na)
#include <config_distro_bootcmd.h>

/* MMC Configs */
#ifdef CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	USDHC1_BASE_ADDR
#define CONFIG_SYS_FSL_USDHC_NUM	2
#endif

#define CONFIG_EXTRA_ENV_SETTINGS BOOTENV

#endif /* __KONTRON_MX6UL_CONFIG_H */
