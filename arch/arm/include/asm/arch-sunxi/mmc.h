/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2007-2011
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Aaron <leafy.myeh@allwinnertech.com>
 *
 * MMC register definition for allwinner sunxi platform.
 */

#ifndef _ARCH_SUNXI_MMC_H
#define _ARCH_SUNXI_MMC_H

struct mmc *sunxi_mmc_init(int sdc_no);
#endif /* _SUNXI_MMC_H */
