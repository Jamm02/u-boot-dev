// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (C) 2021 Moteen Shah <moteenshah.02@gmail.com>
 */

#ifndef _SUNXI_CLOCK_NCATV2_H
#define _SUNXI_CLOCK_NCATV2_H

#ifndef __ASSEMBLY__
#include <linux/bitops.h>
#endif

#define SUNXI_MMC0_BASE 0x4020000

struct sunxi_ccm_reg {
	u32 pll6_cfg;		/* 0x020 pll6 (periph0) control */
};

/* pll6 bit field */
#define SUNXI_CCM_BASE			0x2001000UL
#define CCM_PLL6_CTRL_N_SHIFT		8
#define CCM_PLL6_CTRL_N_MASK		(0xff << CCM_PLL6_CTRL_N_SHIFT)
#define CCM_PLL6_CTRL_M_SHIFT		1
#define CCM_PLL6_CTRL_M_MASK		0x1
#define CCM_PLL6_CTRL_P0_SHIFT		16
#define CCM_PLL6_CTRL_P0_MASK   	0x7

/* MMC clock bit field */
#define CCM_MMC_CTRL_M(x)		((x) - 1)
#define CCM_MMC_CTRL_N(x)		((x) << 8)
#define CCM_MMC_CTRL_OSCM24		(0x0 << 24)
#define CCM_MMC_CTRL_PLL6		(0x1 << 24)
#define CCM_MMC_CTRL_PLL_PERIPH2X2	(0x2 << 24)
#define CCM_MMC_CTRL_ENABLE		(0x1 << 31)

#define CCM_MMC_CTRL_OCLK_DLY(a)	((void) (a), 0)
#define CCM_MMC_CTRL_SCLK_DLY(a)	((void) (a), 0)

#ifndef __ASSEMBLY__
unsigned int clock_get_pll6(void)
{
	struct sunxi_ccm_reg *const ccm =
		(struct sunxi_ccm_reg *)0x2001000UL;

	uint32_t rval = readl(&ccm->pll6_cfg);
	int n = ((rval & CCM_PLL6_CTRL_N_MASK) >> CCM_PLL6_CTRL_N_SHIFT) + 1;
	int m = ((rval >> 1) & 0x1) + 1;
	int p0 = ((rval >> 16) & 0x7) + 1;
	/* The register defines PLL6-2X, not plain PLL6 */
	return 24000000 / n / m / p0;
}
#endif

#endif /*_SUNXI_CLOCK_NCATV2_H*/ 
