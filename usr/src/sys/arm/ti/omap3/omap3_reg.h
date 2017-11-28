/*-
 * Copyright (c) 2011
 *	Ben Gray <ben.r.gray@gmail.com>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: releng/10.3/sys/arm/ti/omap3/omap3_reg.h 239281 2012-08-15 06:31:32Z gonzo $
 */

/*
 * Texas Instruments - OMAP3xxx series processors
 *
 * Reference:
 *  OMAP35x Applications Processor
 *   Technical Reference Manual
 *  (omap35xx_techref.pdf)
 *
 *
 * Note:
 *  The devices are mapped into address above 0xD000_0000 as the kernel space
 *  memory is at 0xC000_0000 and above.  The first 256MB after this is reserved
 *  for the size of the kernel, everything above that is reserved for SoC
 *  devices.
 *
 */
#ifndef _OMAP35XX_REG_H_
#define _OMAP35XX_REG_H_

#ifndef _LOCORE
#include <sys/types.h>		/* for uint32_t */
#endif




#define OMAP35XX_SDRAM0_START		0x80000000UL
#define OMAP35XX_SDRAM1_START		0xA0000000UL
#define	OMAP35XX_SDRAM_BANKS		2
#define	OMAP35XX_SDRAM_BANK_SIZE	0x20000000UL


/* Physical/Virtual address for SDRAM controller */

#define OMAP35XX_SMS_VBASE			0x6C000000UL
#define OMAP35XX_SMS_HWBASE			0x6C000000UL
#define	OMAP35XX_SMS_SIZE			0x01000000UL

#define OMAP35XX_SDRC_VBASE			0x6D000000UL
#define OMAP35XX_SDRC_HWBASE		0x6D000000UL
#define	OMAP35XX_SDRC_SIZE			0x01000000UL



/* Physical/Virtual address for I/O space */

#define	OMAP35XX_L3_VBASE			0xD0000000UL
#define	OMAP35XX_L3_HWBASE			0x68000000UL
#define	OMAP35XX_L3_SIZE			0x01000000UL

#define	OMAP35XX_L4_CORE_VBASE		0xE8000000UL
#define	OMAP35XX_L4_CORE_HWBASE		0x48000000UL
#define	OMAP35XX_L4_CORE_SIZE		0x01000000UL

#define	OMAP35XX_L4_WAKEUP_VBASE	0xE8300000UL
#define	OMAP35XX_L4_WAKEUP_HWBASE	0x48300000UL
#define	OMAP35XX_L4_WAKEUP_SIZE		0x00040000UL

#define	OMAP35XX_L4_PERIPH_VBASE	0xE9000000UL
#define	OMAP35XX_L4_PERIPH_HWBASE	0x49000000UL
#define	OMAP35XX_L4_PERIPH_SIZE		0x00100000UL


/*
 * L4-CORE Physical/Virtual addresss offsets
 */
#define	OMAP35XX_SCM_OFFSET			0x00002000UL
#define	OMAP35XX_CM_OFFSET			0x00004000UL
#define OMAP35XX_SDMA_OFFSET		0x00056000UL
#define	OMAP35XX_I2C3_OFFSET		0x00060000UL
#define	OMAP35XX_USB_TLL_OFFSET     0x00062000UL
#define	OMAP35XX_USB_UHH_OFFSET     0x00064000UL
#define	OMAP35XX_USB_EHCI_OFFSET    0x00064800UL


#define	OMAP35XX_UART1_OFFSET		0x0006A000UL
#define	OMAP35XX_UART2_OFFSET		0x0006C000UL
#define	OMAP35XX_I2C1_OFFSET		0x00070000UL
#define	OMAP35XX_I2C2_OFFSET		0x00072000UL
#define	OMAP35XX_MCBSP1_OFFSET		0x00074000UL
#define	OMAP35XX_GPTIMER10_OFFSET	0x00086000UL
#define	OMAP35XX_GPTIMER11_OFFSET	0x00088000UL
#define	OMAP35XX_MCBSP5_OFFSET		0x00096000UL
#define	OMAP35XX_MMU1_OFFSET		0x000BD400UL
#define	OMAP35XX_INTCPS_OFFSET		0x00200000UL


/*
 * L4-WAKEUP Physical/Virtual addresss offsets
 */
#define OMAP35XX_PRM_OFFSET			0x00006000UL
#define	OMAP35XX_GPIO1_OFFSET		0x00010000UL
#define	OMAP35XX_GPTIMER1_OFFSET	0x00018000UL



/*
 * L4-PERIPH Physical/Virtual addresss offsets
 */
#define	OMAP35XX_UART3_OFFSET		0x00020000UL
#define	OMAP35XX_MCBSP2_OFFSET		0x00022000UL
#define	OMAP35XX_MCBSP3_OFFSET		0x00024000UL
#define	OMAP35XX_MCBSP4_OFFSET		0x00026000UL
#define	OMAP35XX_SIDETONE_MCBSP2_OFFSET		0x00028000UL
#define	OMAP35XX_SIDETONE_MCBSP3_OFFSET		0x0002A000UL
#define	OMAP35XX_GPTIMER2_OFFSET	0x00032000UL
#define	OMAP35XX_GPTIMER3_OFFSET	0x00034000UL
#define	OMAP35XX_GPTIMER4_OFFSET	0x00036000UL
#define	OMAP35XX_GPTIMER5_OFFSET	0x00038000UL
#define	OMAP35XX_GPTIMER6_OFFSET	0x0003A000UL
#define	OMAP35XX_GPTIMER7_OFFSET	0x0003C000UL
#define	OMAP35XX_GPTIMER8_OFFSET	0x0003E000UL
#define	OMAP35XX_GPTIMER9_OFFSET	0x00040000UL
#define	OMAP35XX_GPIO2_OFFSET		0x00050000UL
#define	OMAP35XX_GPIO3_OFFSET		0x00052000UL
#define	OMAP35XX_GPIO4_OFFSET		0x00054000UL
#define	OMAP35XX_GPIO5_OFFSET		0x00056000UL
#define	OMAP35XX_GPIO6_OFFSET		0x00058000UL






/*
 * System Control Module
 */
#define	OMAP35XX_SCM_HWBASE				(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_SCM_OFFSET)
#define OMAP35XX_SCM_VBASE				(OMAP35XX_L4_CORE_VBASE + OMAP35XX_SCM_OFFSET)
#define OMAP35XX_SCM_SIZE				0x00001000UL

#define OMAP35XX_SCM_REVISION			0x00000000UL
#define OMAP35XX_SCM_SYSCONFIG			0x00000010UL
#define OMAP35XX_SCM_PADCONFS_BASE		0x00000030UL
#define OMAP35XX_SCM_DEVCONF0			0x00000274UL
#define OMAP35XX_SCM_MEM_DFTRW0			0x00000278UL




/*
 *
 */
#define	OMAP35XX_CM_HWBASE				(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_CM_OFFSET)
#define OMAP35XX_CM_VBASE				(OMAP35XX_L4_CORE_VBASE + OMAP35XX_CM_OFFSET)
#define OMAP35XX_CM_SIZE				0x00001500UL

#define OMAP35XX_CM_CORE_OFFSET			0x00000A00UL
#define OMAP35XX_CM_CORE_SIZE			0x00000100UL
#define OMAP35XX_CM_FCLKEN1_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0000UL)
#define OMAP35XX_CM_FCLKEN3_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0008UL)
#define OMAP35XX_CM_ICLKEN1_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0010UL)
#define OMAP35XX_CM_ICLKEN2_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0014UL)
#define OMAP35XX_CM_ICLKEN3_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0018UL)
#define OMAP35XX_CM_IDLEST1_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0020UL)
#define OMAP35XX_CM_IDLEST2_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0024UL)
#define OMAP35XX_CM_IDLEST3_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0028UL)
#define OMAP35XX_CM_AUTOIDLE1_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0030UL)
#define OMAP35XX_CM_AUTOIDLE2_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0034UL)
#define OMAP35XX_CM_AUTOIDLE3_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0038UL)
#define OMAP35XX_CM_CLKSEL_CORE			(OMAP35XX_CM_CORE_OFFSET + 0x0040UL)
#define OMAP35XX_CM_CLKSTCTRL_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x0048UL)
#define OMAP35XX_CM_CLKSTST_CORE		(OMAP35XX_CM_CORE_OFFSET + 0x004CUL)

#define OMAP35XX_CM_WKUP_OFFSET			0x00000C00UL
#define OMAP35XX_CM_WKUP_SIZE			0x00000100UL
#define OMAP35XX_CM_FCLKEN_WKUP			(OMAP35XX_CM_WKUP_OFFSET + 0x0000UL)
#define OMAP35XX_CM_ICLKEN_WKUP			(OMAP35XX_CM_WKUP_OFFSET + 0x0010UL)
#define OMAP35XX_CM_IDLEST_WKUP			(OMAP35XX_CM_WKUP_OFFSET + 0x0020UL)
#define OMAP35XX_CM_AUTOIDLE_WKUP		(OMAP35XX_CM_WKUP_OFFSET + 0x0030UL)
#define OMAP35XX_CM_CLKSEL_WKUP			(OMAP35XX_CM_WKUP_OFFSET + 0x0040UL)

#define OMAP35XX_CM_PLL_OFFSET			0x00000D00UL
#define OMAP35XX_CM_PLL_SIZE			0x00000100UL
#define OMAP35XX_CM_CLKEN_PLL			(OMAP35XX_CM_PLL_OFFSET + 0x0000UL)
#define OMAP35XX_CM_CLKEN2_PLL			(OMAP35XX_CM_PLL_OFFSET + 0x0004UL)
#define OMAP35XX_CM_IDLEST_CKGEN		(OMAP35XX_CM_PLL_OFFSET + 0x0020UL)
#define OMAP35XX_CM_IDLEST2_CKGEN		(OMAP35XX_CM_PLL_OFFSET + 0x0024UL)
#define OMAP35XX_CM_AUTOIDLE_PLL		(OMAP35XX_CM_PLL_OFFSET + 0x0030UL)
#define OMAP35XX_CM_AUTOIDLE2_PLL		(OMAP35XX_CM_PLL_OFFSET + 0x0034UL)
#define OMAP35XX_CM_CLKSEL1_PLL			(OMAP35XX_CM_PLL_OFFSET + 0x0040UL)
#define OMAP35XX_CM_CLKSEL2_PLL			(OMAP35XX_CM_PLL_OFFSET + 0x0044UL)
#define OMAP35XX_CM_CLKSEL3_PLL			(OMAP35XX_CM_PLL_OFFSET + 0x0048UL)
#define OMAP35XX_CM_CLKSEL4_PLL			(OMAP35XX_CM_PLL_OFFSET + 0x004CUL)
#define OMAP35XX_CM_CLKSEL5_PLL			(OMAP35XX_CM_PLL_OFFSET + 0x0050UL)
#define OMAP35XX_CM_CLKOUT_CTRL			(OMAP35XX_CM_PLL_OFFSET + 0x0070UL)

#define OMAP35XX_CM_PER_OFFSET			0x00001000UL
#define OMAP35XX_CM_PER_SIZE			0x00000100UL
#define OMAP35XX_CM_FCLKEN_PER			(OMAP35XX_CM_PER_OFFSET + 0x0000UL)
#define OMAP35XX_CM_ICLKEN_PER			(OMAP35XX_CM_PER_OFFSET + 0x0010UL)
#define OMAP35XX_CM_IDLEST_PER			(OMAP35XX_CM_PER_OFFSET + 0x0020UL)
#define OMAP35XX_CM_AUTOIDLE_PER 		(OMAP35XX_CM_PER_OFFSET + 0x0030UL)
#define OMAP35XX_CM_CLKSEL_PER			(OMAP35XX_CM_PER_OFFSET + 0x0040UL)
#define OMAP35XX_CM_SLEEPDEP_PER		(OMAP35XX_CM_PER_OFFSET + 0x0044UL)
#define OMAP35XX_CM_CLKSTCTRL_PER		(OMAP35XX_CM_PER_OFFSET + 0x0048UL)
#define OMAP35XX_CM_CLKSTST_PER			(OMAP35XX_CM_PER_OFFSET + 0x004CUL)

#define OMAP35XX_CM_USBHOST_OFFSET		0x00001400UL
#define OMAP35XX_CM_USBHOST_SIZE		0x00000100UL
#define OMAP35XX_CM_FCLKEN_USBHOST		(OMAP35XX_CM_USBHOST_OFFSET + 0x0000UL)
#define OMAP35XX_CM_ICLKEN_USBHOST		(OMAP35XX_CM_USBHOST_OFFSET + 0x0010UL)
#define OMAP35XX_CM_IDLEST_USBHOST		(OMAP35XX_CM_USBHOST_OFFSET + 0x0020UL)
#define OMAP35XX_CM_AUTOIDLE_USBHOST	(OMAP35XX_CM_USBHOST_OFFSET + 0x0030UL)
#define OMAP35XX_CM_SLEEPDEP_USBHOST	(OMAP35XX_CM_USBHOST_OFFSET + 0x0044UL)
#define OMAP35XX_CM_CLKSTCTRL_USBHOST	(OMAP35XX_CM_USBHOST_OFFSET + 0x0048UL)
#define OMAP35XX_CM_CLKSTST_USBHOST		(OMAP35XX_CM_USBHOST_OFFSET + 0x004CUL)




/*
 *
 */
#define	OMAP35XX_PRM_HWBASE				(OMAP35XX_L4_WAKEUP_HWBASE + OMAP35XX_PRM_OFFSET)
#define OMAP35XX_PRM_VBASE				(OMAP35XX_L4_WAKEUP_VBASE + OMAP35XX_PRM_OFFSET)
#define OMAP35XX_PRM_SIZE				0x00001600UL

#define OMAP35XX_PRM_CLKCTRL_OFFSET		0x00000D00UL
#define OMAP35XX_PRM_CLKCTRL_SIZE		0x00000100UL
#define OMAP35XX_PRM_CLKSEL				(OMAP35XX_PRM_CLKCTRL_OFFSET + 0x0040UL)
#define OMAP35XX_PRM_CLKOUT_CTRL		(OMAP35XX_PRM_CLKCTRL_OFFSET + 0x0070UL)

#define OMAP35XX_PRM_GLOBAL_OFFSET		0x00001200UL
#define OMAP35XX_PRM_GLOBAL_SIZE		0x00000100UL
#define OMAP35XX_PRM_CLKSRC_CTRL		(OMAP35XX_PRM_GLOBAL_OFFSET + 0x0070UL)





/*
 * Uarts
 */
#define	OMAP35XX_UART1_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_UART1_OFFSET)
#define	OMAP35XX_UART1_VBASE			(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_UART1_OFFSET)
#define	OMAP35XX_UART1_SIZE				0x00001000UL

#define	OMAP35XX_UART2_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_UART2_OFFSET)
#define	OMAP35XX_UART2_VBASE			(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_UART2_OFFSET)
#define	OMAP35XX_UART2_SIZE				0x00001000UL

#define OMAP35XX_UART3_HWBASE			(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_UART3_OFFSET)
#define OMAP35XX_UART3_VBASE			(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_UART3_OFFSET)
#define	OMAP35XX_UART3_SIZE				0x00001000UL




/*
 * I2C Modules
 */
#define	OMAP35XX_I2C1_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_I2C1_OFFSET)
#define	OMAP35XX_I2C1_VBASE				(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_I2C1_OFFSET)
#define	OMAP35XX_I2C1_SIZE				0x00000080UL

#define	OMAP35XX_I2C2_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_I2C2_OFFSET)
#define	OMAP35XX_I2C2_VBASE				(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_I2C2_OFFSET)
#define	OMAP35XX_I2C2_SIZE				0x00000080UL

#define	OMAP35XX_I2C3_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_I2C3_OFFSET)
#define	OMAP35XX_I2C3_VBASE				(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_I2C3_OFFSET)
#define	OMAP35XX_I2C3_SIZE				0x00000080UL

#define	OMAP35XX_I2C_IE					0x04
#define	OMAP35XX_I2C_STAT				0x08
#define	OMAP35XX_I2C_WE					0x0C
#define	OMAP35XX_I2C_SYSS				0x10
#define	OMAP35XX_I2C_BUF				0x14
#define	OMAP35XX_I2C_CNT				0x18
#define	OMAP35XX_I2C_DATA				0x1C
#define	OMAP35XX_I2C_SYSC				0x20
#define	OMAP35XX_I2C_CON				0x24
#define	OMAP35XX_I2C_OA0				0x28
#define	OMAP35XX_I2C_SA					0x2C
#define	OMAP35XX_I2C_PSC				0x30
#define	OMAP35XX_I2C_SCLL				0x34
#define	OMAP35XX_I2C_SCLH				0x38
#define	OMAP35XX_I2C_SYSTEST			0x3C
#define	OMAP35XX_I2C_BUFSTAT			0x40
#define	OMAP35XX_I2C_OA1				0x44
#define	OMAP35XX_I2C_OA2				0x48
#define	OMAP35XX_I2C_OA3				0x4C
#define	OMAP35XX_I2C_ACTOA				0x50
#define	OMAP35XX_I2C_SBLOCK				0x54



/*
 * McBSP Modules
 */
#define	OMAP35XX_MCBSP1_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_MCBSP1_OFFSET)
#define	OMAP35XX_MCBSP1_VBASE			(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_MCBSP1_OFFSET)
#define	OMAP35XX_MCBSP1_SIZE			0x00001000UL

#define	OMAP35XX_MCBSP2_HWBASE			(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_MCBSP2_OFFSET)
#define	OMAP35XX_MCBSP2_VBASE			(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_MCBSP2_OFFSET)
#define	OMAP35XX_MCBSP2_SIZE			0x00001000UL

#define	OMAP35XX_MCBSP3_HWBASE			(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_MCBSP3_OFFSET)
#define	OMAP35XX_MCBSP3_VBASE			(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_MCBSP3_OFFSET)
#define	OMAP35XX_MCBSP3_SIZE			0x00001000UL

#define	OMAP35XX_MCBSP4_HWBASE			(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_MCBSP4_OFFSET)
#define	OMAP35XX_MCBSP4_VBASE			(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_MCBSP4_OFFSET)
#define	OMAP35XX_MCBSP4_SIZE			0x00001000UL

#define	OMAP35XX_MCBSP5_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_MCBSP5_OFFSET)
#define	OMAP35XX_MCBSP5_VBASE			(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_MCBSP5_OFFSET)
#define	OMAP35XX_MCBSP5_SIZE			0x00001000UL

#define	OMAP35XX_MCBSP_DRR				0x0000
#define	OMAP35XX_MCBSP_DXR				0x0008
#define	OMAP35XX_MCBSP_SPCR2			0x0010
#define	OMAP35XX_MCBSP_SPCR1			0x0014
#define	OMAP35XX_MCBSP_RCR2				0x0018
#define	OMAP35XX_MCBSP_RCR1				0x001C
#define	OMAP35XX_MCBSP_XCR2				0x0020
#define	OMAP35XX_MCBSP_XCR1				0x0024
#define	OMAP35XX_MCBSP_SRGR2			0x0028
#define	OMAP35XX_MCBSP_SRGR1			0x002C
#define	OMAP35XX_MCBSP_MCR2				0x0030
#define	OMAP35XX_MCBSP_MCR1				0x0034
#define	OMAP35XX_MCBSP_RCERA			0x0038
#define	OMAP35XX_MCBSP_RCERB			0x003C
#define	OMAP35XX_MCBSP_XCERA			0x0040
#define	OMAP35XX_MCBSP_XCERB			0x0044
#define	OMAP35XX_MCBSP_PCR				0x0048
#define	OMAP35XX_MCBSP_RCERC			0x004C
#define	OMAP35XX_MCBSP_RCERD			0x0050
#define	OMAP35XX_MCBSP_XCERC			0x0054
#define	OMAP35XX_MCBSP_XCERD			0x0058
#define	OMAP35XX_MCBSP_RCERE			0x005C
#define	OMAP35XX_MCBSP_RCERF			0x0060
#define	OMAP35XX_MCBSP_XCERE			0x0064
#define	OMAP35XX_MCBSP_XCERF			0x0068
#define	OMAP35XX_MCBSP_RCERG			0x006C
#define	OMAP35XX_MCBSP_RCERH			0x0070
#define	OMAP35XX_MCBSP_XCERG			0x0074
#define	OMAP35XX_MCBSP_XCERH			0x0078
#define	OMAP35XX_MCBSP_RINTCLR			0x0080
#define	OMAP35XX_MCBSP_XINTCLR			0x0084
#define	OMAP35XX_MCBSP_ROVFLCLR			0x0088
#define	OMAP35XX_MCBSP_SYSCONFIG		0x008C
#define	OMAP35XX_MCBSP_THRSH2			0x0090
#define	OMAP35XX_MCBSP_THRSH1			0x0094
#define	OMAP35XX_MCBSP_IRQSTATUS		0x00A0
#define	OMAP35XX_MCBSP_IRQENABLE		0x00A4
#define	OMAP35XX_MCBSP_WAKEUPEN			0x00A8
#define	OMAP35XX_MCBSP_XCCR				0x00AC
#define	OMAP35XX_MCBSP_RCCR				0x00B0
#define	OMAP35XX_MCBSP_XBUFFSTAT		0x00B4
#define	OMAP35XX_MCBSP_RBUFFSTAT		0x00B8
#define	OMAP35XX_MCBSP_SSELCR			0x00BC
#define	OMAP35XX_MCBSP_STATUS			0x00C0



/*
 * USB TTL Module
 */
#define	OMAP35XX_USBTLL_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_USBTLL_OFFSET)
#define	OMAP35XX_USBTLL_VBASE			(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_USBTLL_OFFSET)
#define	OMAP35XX_USBTLL_SIZE			0x00001000UL

#define	OMAP35XX_USBTLL_REVISION						0x0000
#define	OMAP35XX_USBTLL_SYSCONFIG						0x0010
#define	OMAP35XX_USBTLL_SYSSTATUS						0x0014
#define	OMAP35XX_USBTLL_IRQSTATUS						0x0018
#define	OMAP35XX_USBTLL_IRQENABLE						0x001C
#define	OMAP35XX_USBTLL_TLL_SHARED_CONF					0x0030
#define	OMAP35XX_USBTLL_TLL_CHANNEL_CONF(i)				(0x0040 + (0x04 * (i)))
#define	OMAP35XX_USBTLL_ULPI_VENDOR_ID_LO(i)			(0x0800 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_VENDOR_ID_HI(i)			(0x0801 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_PRODUCT_ID_LO(i)			(0x0802 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_PRODUCT_ID_HI(i)			(0x0803 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_FUNCTION_CTRL(i)			(0x0804 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_FUNCTION_CTRL_SET(i)		(0x0805 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_FUNCTION_CTRL_CLR(i)		(0x0806 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_INTERFACE_CTRL(i)			(0x0807 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_INTERFACE_CTRL_SET(i)		(0x0808 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_INTERFACE_CTRL_CLR(i)		(0x0809 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_OTG_CTRL(i)				(0x080A + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_OTG_CTRL_SET(i)			(0x080B + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_OTG_CTRL_CLR(i)			(0x080C + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_EN_RISE(i)			(0x080D + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_EN_RISE_SET(i)		(0x080E + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_EN_RISE_CLR(i)		(0x080F + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_EN_FALL(i)			(0x0810 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_EN_FALL_SET(i)		(0x0811 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_EN_FALL_CLR(i)		(0x0812 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_STATUS(i)			(0x0813 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_LATCH(i)			(0x0814 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_DEBUG(i)					(0x0815 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_SCRATCH_REGISTER(i)		(0x0816 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_SCRATCH_REGISTER_SET(i)	(0x0817 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_SCRATCH_REGISTER_CLR(i)	(0x0818 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_EXTENDED_SET_ACCESS(i)		(0x082F + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_EN(i)		(0x0830 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_EN_SET(i)	(0x0831 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_EN_CLR(i)	(0x0832 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_STATUS(i)	(0x0833 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_LATCH(i)		(0x0834 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_UTMI_VSTATUS(i)			(0x0835 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_UTMI_VSTATUS_SET(i)		(0x0836 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_UTMI_VSTATUS_CLR(i)		(0x0837 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_USB_INT_LATCH_NOCLR(i)		(0x0838 + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_VENDOR_INT_EN(i)			(0x083B + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_VENDOR_INT_EN_SET(i)		(0x083C + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_VENDOR_INT_EN_CLR(i)		(0x083D + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_VENDOR_INT_STATUS(i)		(0x083E + (0x100 * (i)))
#define	OMAP35XX_USBTLL_ULPI_VENDOR_INT_LATCH(i)		(0x083F + (0x100 * (i)))


/*
 * USB Host Module
 */
#define	OMAP35XX_USB_TLL_HWBASE         (OMAP35XX_L4_CORE_HWBASE + OMAP35XX_USB_TLL_OFFSET)
#define	OMAP35XX_USB_TLL_VBASE          (OMAP35XX_L4_CORE_VBASE + OMAP35XX_USB_TLL_OFFSET)
#define OMAP35XX_USB_TLL_SIZE           0x00001000UL

#define	OMAP35XX_USB_EHCI_HWBASE        (OMAP35XX_L4_CORE_HWBASE + OMAP35XX_USB_EHCI_OFFSET)
#define	OMAP35XX_USB_EHCI_VBASE         (OMAP35XX_L4_CORE_VBASE + OMAP35XX_USB_EHCI_OFFSET)
#define OMAP35XX_USB_EHCI_SIZE          0x00000400UL

#define	OMAP35XX_USB_UHH_HWBASE         (OMAP35XX_L4_CORE_HWBASE + OMAP35XX_USB_UHH_OFFSET)
#define	OMAP35XX_USB_UHH_VBASE          (OMAP35XX_L4_CORE_VBASE + OMAP35XX_USB_UHH_OFFSET)
#define OMAP35XX_USB_UHH_SIZE           0x00000400UL





/*
 * SDRAM Controler (SDRC)
 *  PA 0x6D00_0000
 */

#define OMAP35XX_SDRC_SYSCONFIG			(OMAP35XX_SDRC_VBASE + 0x10)
#define OMAP35XX_SDRC_SYSSTATUS			(OMAP35XX_SDRC_VBASE + 0x14)
#define OMAP35XX_SDRC_CS_CFG			(OMAP35XX_SDRC_VBASE + 0x40)
#define OMAP35XX_SDRC_SHARING			(OMAP35XX_SDRC_VBASE + 0x44)
#define OMAP35XX_SDRC_ERR_ADDR			(OMAP35XX_SDRC_VBASE + 0x48)
#define OMAP35XX_SDRC_ERR_TYPE			(OMAP35XX_SDRC_VBASE + 0x4C)
#define OMAP35XX_SDRC_DLLA_CTRL			(OMAP35XX_SDRC_VBASE + 0x60)
#define OMAP35XX_SDRC_DLLA_STATUS		(OMAP35XX_SDRC_VBASE + 0x64)
#define OMAP35XX_SDRC_POWER_REG			(OMAP35XX_SDRC_VBASE + 0x70)
#define OMAP35XX_SDRC_MCFG(p)			(OMAP35XX_SDRC_VBASE + 0x80 + (0x30 * (p)))
#define OMAP35XX_SDRC_MR(p)				(OMAP35XX_SDRC_VBASE + 0x84 + (0x30 * (p)))
#define OMAP35XX_SDRC_EMR2(p)			(OMAP35XX_SDRC_VBASE + 0x8C + (0x30 * (p)))
#define OMAP35XX_SDRC_ACTIM_CTRLA(p)	(OMAP35XX_SDRC_VBASE + 0x9C + (0x28 * (p)))
#define OMAP35XX_SDRC_ACTIM_CTRLB(p)	(OMAP35XX_SDRC_VBASE + 0xA0 + (0x28 * (p)))
#define OMAP35XX_SDRC_RFR_CTRL(p)		(OMAP35XX_SDRC_VBASE + 0xA4 + (0x30 * (p)))
#define OMAP35XX_SDRC_MANUAL(p)			(OMAP35XX_SDRC_VBASE + 0xA8 + (0x30 * (p)))


/*
 * SDMA Offset
 *  PA 0x4805 6000
 */

#define	OMAP35XX_SDMA_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_SDMA_OFFSET)
#define	OMAP35XX_SDMA_VBASE				(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_SDMA_OFFSET)
#define	OMAP35XX_SDMA_SIZE				0x00001000UL



/*
 * Interrupt Controller Unit.
 *  PA 0x4820_0000
 */

#define	OMAP35XX_INTCPS_HWBASE			(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_INTCPS_OFFSET)
#define	OMAP35XX_INTCPS_VBASE			(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_INTCPS_OFFSET)
#define	OMAP35XX_INTCPS_SIZE			0x00001000UL

#define	OMAP35XX_INTCPS_SYSCONFIG		(OMAP35XX_INTCPS_VBASE + 0x10)
#define	OMAP35XX_INTCPS_SYSSTATUS		(OMAP35XX_INTCPS_VBASE + 0x14)
#define	OMAP35XX_INTCPS_SIR_IRQ			(OMAP35XX_INTCPS_VBASE + 0x40)
#define	OMAP35XX_INTCPS_SIR_FIQ			(OMAP35XX_INTCPS_VBASE + 0x44)
#define	OMAP35XX_INTCPS_CONTROL			(OMAP35XX_INTCPS_VBASE + 0x48)
#define	OMAP35XX_INTCPS_PROTECTION		(OMAP35XX_INTCPS_VBASE + 0x4C)
#define	OMAP35XX_INTCPS_IDLE			(OMAP35XX_INTCPS_VBASE + 0x50)
#define	OMAP35XX_INTCPS_IRQ_PRIORITY	(OMAP35XX_INTCPS_VBASE + 0x60)
#define	OMAP35XX_INTCPS_FIQ_PRIORITY	(OMAP35XX_INTCPS_VBASE + 0x64)
#define	OMAP35XX_INTCPS_THRESHOLD		(OMAP35XX_INTCPS_VBASE + 0x68)
#define OMAP35XX_INTCPS_ITR(n)			(OMAP35XX_INTCPS_VBASE + 0x80 + (0x20 * (n)))
#define OMAP35XX_INTCPS_MIR(n)			(OMAP35XX_INTCPS_VBASE + 0x84 + (0x20 * (n)))
#define OMAP35XX_INTCPS_MIR_CLEAR(n)	(OMAP35XX_INTCPS_VBASE + 0x88 + (0x20 * (n)))
#define OMAP35XX_INTCPS_MIR_SET(n)		(OMAP35XX_INTCPS_VBASE + 0x8C + (0x20 * (n)))
#define OMAP35XX_INTCPS_ISR_SET(n)		(OMAP35XX_INTCPS_VBASE + 0x90 + (0x20 * (n)))
#define OMAP35XX_INTCPS_ISR_CLEAR(n)	(OMAP35XX_INTCPS_VBASE + 0x94 + (0x20 * (n)))
#define OMAP35XX_INTCPS_PENDING_IRQ(n)	(OMAP35XX_INTCPS_VBASE + 0x98 + (0x20 * (n)))
#define OMAP35XX_INTCPS_PENDING_FIQ(n)	(OMAP35XX_INTCPS_VBASE + 0x9C + (0x20 * (n)))
#define OMAP35XX_INTCPS_ILR(m)			(OMAP35XX_INTCPS_VBASE + 0x100 + (0x4 * (m)))


#define	OMAP35XX_IRQ_EMUINT			0	/* MPU emulation(2) */
#define	OMAP35XX_IRQ_COMMTX			1	/* MPU emulation(2) */
#define	OMAP35XX_IRQ_COMMRX			2	/* MPU emulation(2) */
#define	OMAP35XX_IRQ_BENCH			3	/* MPU emulation(2) */
#define	OMAP35XX_IRQ_MCBSP2_ST		4	/* Sidetone MCBSP2 overflow */
#define	OMAP35XX_IRQ_MCBSP3_ST		5	/* Sidetone MCBSP3 overflow */
#define	OMAP35XX_IRQ_SSM_ABORT		6	/* MPU subsystem secure state-machine abort (2) */
#define	OMAP35XX_IRQ_SYS_NIRQ		7	/* External source (active low) */
#define	OMAP35XX_IRQ_RESERVED8		8	/* RESERVED */
#define	OMAP35XX_IRQ_SMX_DBG		9	/* SMX error for debug */
#define	OMAP35XX_IRQ_SMX_APP		10	/* SMX error for application */
#define	OMAP35XX_IRQ_PRCM_MPU		11	/* PRCM module IRQ */
#define	OMAP35XX_IRQ_SDMA0			12	/* System DMA request 0(3) */
#define	OMAP35XX_IRQ_SDMA1			13	/* System DMA request 1(3) */
#define	OMAP35XX_IRQ_SDMA2			14	/* System DMA request 2 */
#define	OMAP35XX_IRQ_SDMA3			15	/* System DMA request 3 */
#define	OMAP35XX_IRQ_MCBSP1			16	/* McBSP module 1 IRQ (3) */
#define	OMAP35XX_IRQ_MCBSP2			17	/* McBSP module 2 IRQ (3) */
#define	OMAP35XX_IRQ_SR1			18	/* SmartReflex™ 1 */
#define	OMAP35XX_IRQ_SR2			19	/* SmartReflex™ 2 */
#define	OMAP35XX_IRQ_GPMC			20	/* General-purpose memory controller module */
#define	OMAP35XX_IRQ_SGX			21	/* 2D/3D graphics module */
#define	OMAP35XX_IRQ_MCBSP3			22	/* McBSP module 3(3) */
#define	OMAP35XX_IRQ_MCBSP4			23	/* McBSP module 4(3) */
#define	OMAP35XX_IRQ_CAM0			24	/* Camera interface request 0 */
#define	OMAP35XX_IRQ_DSS			25	/* Display subsystem module(3) */
#define	OMAP35XX_IRQ_MAIL_U0		26	/* Mailbox user 0 request */
#define	OMAP35XX_IRQ_MCBSP5_IRQ1	27	/*  McBSP module 5 (3) */
#define	OMAP35XX_IRQ_IVA2_MMU		28	/* IVA2 MMU */
#define	OMAP35XX_IRQ_GPIO1_MPU		29	/* GPIO module 1(3) */
#define	OMAP35XX_IRQ_GPIO2_MPU		30	/* GPIO module 2(3) */
#define	OMAP35XX_IRQ_GPIO3_MPU		31	/* GPIO module 3(3) */
#define	OMAP35XX_IRQ_GPIO4_MPU		32	/* GPIO module 4(3) */
#define	OMAP35XX_IRQ_GPIO5_MPU		33	/* GPIO module 5(3) */
#define	OMAP35XX_IRQ_GPIO6_MPU		34	/* GPIO module 6(3) */
#define	OMAP35XX_IRQ_USIM			35	/* USIM interrupt (HS devices only) (4) */
#define	OMAP35XX_IRQ_WDT3			36	/* Watchdog timer module 3 overflow */
#define	OMAP35XX_IRQ_GPT1			37	/* General-purpose timer module 1 */
#define	OMAP35XX_IRQ_GPT2			38	/* General-purpose timer module 2 */
#define	OMAP35XX_IRQ_GPT3			39	/* General-purpose timer module 3 */
#define	OMAP35XX_IRQ_GPT4			40	/* General-purpose timer module 4 */
#define	OMAP35XX_IRQ_GPT5			41	/* General-purpose timer module 5(3) */
#define	OMAP35XX_IRQ_GPT6			42	/* General-purpose timer module 6(3) */
#define	OMAP35XX_IRQ_GPT7			43	/* General-purpose timer module 7(3) */
#define	OMAP35XX_IRQ_GPT8			44	/* General-purpose timer module 8(3) */
#define	OMAP35XX_IRQ_GPT9			45	/* General-purpose timer module 9 */
#define	OMAP35XX_IRQ_GPT10			46	/* General-purpose timer module 10 */
#define	OMAP35XX_IRQ_GPT11			47	/* General-purpose timer module 11 */
#define	OMAP35XX_IRQ_SPI4			48	/* McSPI module 4 */
#define	OMAP35XX_IRQ_SHA1MD5_2		49	/* SHA-1/MD5 crypto-accelerator 2 (HS devices only)(4) */
#define	OMAP35XX_IRQ_FPKA_IRQREADY_N	50	/* PKA crypto-accelerator (HS devices only) (4) */
#define	OMAP35XX_IRQ_SHA2MD5		51	/* SHA-2/MD5 crypto-accelerator 1 (HS devices only) (4) */
#define	OMAP35XX_IRQ_RNG			52	/* RNG module (HS devices only) (4) */
#define	OMAP35XX_IRQ_MG				53	/* MG function (3) */
#define	OMAP35XX_IRQ_MCBSP4_TX		54	/* McBSP module 4 transmit(3) */
#define	OMAP35XX_IRQ_MCBSP4_RX		55	/* McBSP module 4 receive(3) */
#define	OMAP35XX_IRQ_I2C1			56	/* I2C module 1 */
#define	OMAP35XX_IRQ_I2C2			57	/* I2C module 2 */
#define	OMAP35XX_IRQ_HDQ			58	/* HDQ / One-wire */
#define	OMAP35XX_IRQ_MCBSP1_TX		59	/* McBSP module 1 transmit(3) */
#define	OMAP35XX_IRQ_MCBSP1_RX		60	/* McBSP module 1 receive(3) */
#define	OMAP35XX_IRQ_I2C3			61	/* I2C module 3 */
#define	OMAP35XX_IRQ_McBSP2_TX		62	/* McBSP module 2 transmit(3) */
#define	OMAP35XX_IRQ_McBSP2_RX		63	/* McBSP module 2 receive(3) */
#define	OMAP35XX_IRQ_FPKA_IRQRERROR_N	64	/* PKA crypto-accelerator (HS devices only) (4) */
#define	OMAP35XX_IRQ_SPI1			65	/* McSPI module 1 */
#define	OMAP35XX_IRQ_SPI2			66	/* McSPI module 2 */
#define	OMAP35XX_IRQ_RESERVED67		67	/* RESERVED */
#define	OMAP35XX_IRQ_RESERVED68		68	/* RESERVED */
#define	OMAP35XX_IRQ_RESERVED69		69	/* RESERVED */
#define	OMAP35XX_IRQ_RESERVED70		70	/* RESERVED */
#define	OMAP35XX_IRQ_RESERVED71		71	/* RESERVED */
#define	OMAP35XX_IRQ_UART1			72	/* UART module 1 */
#define	OMAP35XX_IRQ_UART2			73	/* UART module 2 */
#define	OMAP35XX_IRQ_UART3			74	/* UART module 3 (also infrared)(3) */
#define	OMAP35XX_IRQ_PBIAS			75	/* Merged interrupt for PBIASlite1 and 2 */
#define	OMAP35XX_IRQ_OHCI			76	/* OHCI controller HSUSB MP Host Interrupt */
#define	OMAP35XX_IRQ_EHCI			77	/* EHCI controller HSUSB MP Host Interrupt */
#define	OMAP35XX_IRQ_TLL			78	/* HSUSB MP TLL Interrupt */
#define	OMAP35XX_IRQ_PARTHASH		79	/* SHA2/MD5 crypto-accelerator 1 (HS devices only) (4) */
#define	OMAP35XX_IRQ_RESERVED80		80	/* Reserved */
#define	OMAP35XX_IRQ_MCBSP5_TX		81	/* McBSP module 5 transmit(3) */
#define	OMAP35XX_IRQ_MCBSP5_RX		82	/* McBSP module 5 receive(3) */
#define	OMAP35XX_IRQ_MMC1			83	/* MMC/SD module 1 */
#define	OMAP35XX_IRQ_MS				84	/* MS-PRO™ module */
#define	OMAP35XX_IRQ_RESERVED85		85	/* Reserved */
#define	OMAP35XX_IRQ_MMC2			86	/* MMC/SD module 2 */
#define	OMAP35XX_IRQ_MPU_ICR		87	/* MPU ICR */
#define	OMAP35XX_IRQ_RESERVED		88	/* RESERVED */
#define	OMAP35XX_IRQ_MCBSP3_TX		89	/* McBSP module 3 transmit(3) */
#define	OMAP35XX_IRQ_MCBSP3_RX		90	/* McBSP module 3 receive(3) */
#define	OMAP35XX_IRQ_SPI3			91	/* McSPI module 3 */
#define	OMAP35XX_IRQ_HSUSB_MC_NINT	92	/* High-Speed USB OTG controller */
#define	OMAP35XX_IRQ_HSUSB_DMA_NINT	93	/* High-Speed USB OTG DMA controller */
#define	OMAP35XX_IRQ_MMC3			94	/* MMC/SD module 3 */
#define	OMAP35XX_IRQ_GPT12			95	/* General-purpose timer module 12 */




/*
 * General Purpose Timers
 */
#define OMAP35XX_GPTIMER1_VBASE     (OMAP35XX_L4_WAKEUP_VBASE + OMAP35XX_GPTIMER1_OFFSET)
#define OMAP35XX_GPTIMER1_HWBASE    (OMAP35XX_L4_WAKEUP_HWBASE + OMAP35XX_GPTIMER1_OFFSET)
#define OMAP35XX_GPTIMER2_VBASE     (OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER2_OFFSET)
#define OMAP35XX_GPTIMER2_HWBASE    (OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER2_OFFSET)
#define OMAP35XX_GPTIMER3_VBASE     (OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER3_OFFSET)
#define OMAP35XX_GPTIMER3_HWBASE    (OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER3_OFFSET)
#define OMAP35XX_GPTIMER4_VBASE     (OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER4_OFFSET)
#define OMAP35XX_GPTIMER4_HWBASE    (OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER4_OFFSET)
#define OMAP35XX_GPTIMER5_VBASE     (OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER5_OFFSET)
#define OMAP35XX_GPTIMER5_HWBASE    (OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER5_OFFSET)
#define OMAP35XX_GPTIMER6_VBASE     (OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER6_OFFSET)
#define OMAP35XX_GPTIMER6_HWBASE    (OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER6_OFFSET)
#define OMAP35XX_GPTIMER7_VBASE     (OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER7_OFFSET)
#define OMAP35XX_GPTIMER7_HWBASE    (OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER7_OFFSET)
#define OMAP35XX_GPTIMER8_VBASE     (OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER8_OFFSET)
#define OMAP35XX_GPTIMER8_HWBASE    (OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER8_OFFSET)
#define OMAP35XX_GPTIMER9_VBASE     (OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER9_OFFSET)
#define OMAP35XX_GPTIMER9_HWBASE    (OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER9_OFFSET)
#define OMAP35XX_GPTIMER10_VBASE    (OMAP35XX_L4_CORE_VBASE + OMAP35XX_GPTIMER10_OFFSET)
#define OMAP35XX_GPTIMER10_HWBASE   (OMAP35XX_L4_CORE_HWBASE + OMAP35XX_GPTIMER10_OFFSET)
#define OMAP35XX_GPTIMER11_VBASE    (OMAP35XX_L4_CORE_VBASE + OMAP35XX_GPTIMER11_OFFSET)
#define OMAP35XX_GPTIMER11_HWBASE   (OMAP35XX_L4_CORE_HWBASE + OMAP35XX_GPTIMER11_OFFSET)
#define OMAP35XX_GPTIMER12_VBASE    0x48304000UL   /* GPTIMER12 */
#define OMAP35XX_GPTIMER_SIZE       0x00001000UL



/* Timer register offsets */
#define OMAP35XX_GPTIMER_TIOCP_CFG	0x010
#define OMAP35XX_GPTIMER_TISTAT		0x014
#define OMAP35XX_GPTIMER_TISR		0x018
#define OMAP35XX_GPTIMER_TIER		0x01C
#define OMAP35XX_GPTIMER_TWER		0x020
#define OMAP35XX_GPTIMER_TCLR		0x024
#define OMAP35XX_GPTIMER_TCRR		0x028
#define OMAP35XX_GPTIMER_TLDR		0x02C
#define OMAP35XX_GPTIMER_TTGR		0x030
#define OMAP35XX_GPTIMER_TWPS		0x034
#define OMAP35XX_GPTIMER_TMAR		0x038
#define OMAP35XX_GPTIMER_TCAR1		0x03C
#define OMAP35XX_GPTIMER_TSICR		0x040
#define OMAP35XX_GPTIMER_TCAR2		0x044
#define OMAP35XX_GPTIMER_TPIR		0x048
#define OMAP35XX_GPTIMER_TNIR		0x04C
#define OMAP35XX_GPTIMER_TCVR		0x050
#define OMAP35XX_GPTIMER_TOCR		0x054
#define OMAP35XX_GPTIMER_TOWR		0x058

/* Bit values */
#define MAT_IT_FLAG		0x01
#define OVF_IT_FLAG		0x02
#define TCAR_IT_FLAG	0x04



/*
 * GPIO - General Purpose IO
 */

/* Base addresses for the GPIO modules */
#define	OMAP35XX_GPIO1_HWBASE		(OMAP35XX_L4_WAKEUP_HWBASE + OMAP35XX_GPIO1_OFFSET)
#define	OMAP35XX_GPIO1_VBASE		(OMAP35XX_L4_WAKEUP_VBASE  + OMAP35XX_GPIO1_OFFSET)
#define	OMAP35XX_GPIO1_SIZE			0x00001000UL
#define	OMAP35XX_GPIO2_HWBASE		(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO2_OFFSET)
#define	OMAP35XX_GPIO2_VBASE		(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO2_OFFSET)
#define	OMAP35XX_GPIO2_SIZE			0x00001000UL
#define	OMAP35XX_GPIO3_HWBASE		(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO3_OFFSET)
#define	OMAP35XX_GPIO3_VBASE		(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO3_OFFSET)
#define	OMAP35XX_GPIO3_SIZE			0x00001000UL
#define	OMAP35XX_GPIO4_HWBASE		(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO4_OFFSET)
#define	OMAP35XX_GPIO4_VBASE		(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO4_OFFSET)
#define	OMAP35XX_GPIO4_SIZE			0x00001000UL
#define	OMAP35XX_GPIO5_HWBASE		(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO5_OFFSET)
#define	OMAP35XX_GPIO5_VBASE		(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO5_OFFSET)
#define	OMAP35XX_GPIO5_SIZE			0x00001000UL
#define	OMAP35XX_GPIO6_HWBASE		(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO6_OFFSET)
#define	OMAP35XX_GPIO6_VBASE		(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO6_OFFSET)
#define	OMAP35XX_GPIO6_SIZE			0x00001000UL



/* Register offsets within the banks above */
#define OMAP35XX_GPIO_SYSCONFIG			0x010
#define OMAP35XX_GPIO_SYSSTATUS			0x014
#define OMAP35XX_GPIO_IRQSTATUS1		0x018
#define OMAP35XX_GPIO_IRQENABLE1		0x01C
#define OMAP35XX_GPIO_WAKEUPENABLE		0x020
#define OMAP35XX_GPIO_IRQSTATUS2		0x028
#define OMAP35XX_GPIO_IRQENABLE2		0x02C
#define OMAP35XX_GPIO_CTRL				0x030
#define OMAP35XX_GPIO_OE				0x034
#define OMAP35XX_GPIO_DATAIN			0x038
#define OMAP35XX_GPIO_DATAOUT			0x03C
#define OMAP35XX_GPIO_LEVELDETECT0		0x040
#define OMAP35XX_GPIO_LEVELDETECT1		0x044
#define OMAP35XX_GPIO_RISINGDETECT		0x048
#define OMAP35XX_GPIO_FALLINGDETECT		0x04C
#define OMAP35XX_GPIO_DEBOUNCENABLE		0x050
#define OMAP35XX_GPIO_DEBOUNCINGTIME	0x054
#define OMAP35XX_GPIO_CLEARIRQENABLE1	0x060
#define OMAP35XX_GPIO_SETIRQENABLE1		0x064
#define OMAP35XX_GPIO_CLEARIRQENABLE2	0x070
#define OMAP35XX_GPIO_SETIRQENABLE2		0x074
#define OMAP35XX_GPIO_CLEARWKUENA		0x080
#define OMAP35XX_GPIO_SETWKUENA			0x084
#define OMAP35XX_GPIO_CLEARDATAOUT		0x090
#define OMAP35XX_GPIO_SETDATAOUT		0x094


/*
 * MMC/SD/SDIO
 */

/* Base addresses for the MMC/SD/SDIO modules */
#define	OMAP35XX_MMCHS1_HWBASE		(OMAP35XX_L4_CORE_HWBASE + 0x0009C000)
#define	OMAP35XX_MMCHS1_VBASE		(OMAP35XX_L4_CORE_VBASE + 0x0009C000)
#define	OMAP35XX_MMCHS2_HWBASE		(OMAP35XX_L4_CORE_HWBASE + 0x000B4000)
#define	OMAP35XX_MMCHS2_VBASE		(OMAP35XX_L4_CORE_VBASE + 0x000B4000)
#define	OMAP35XX_MMCHS3_HWBASE		(OMAP35XX_L4_CORE_HWBASE + 0x000AD000)
#define	OMAP35XX_MMCHS3_VBASE		(OMAP35XX_L4_CORE_VBASE + 0x000AD000)
#define	OMAP35XX_MMCHS_SIZE			0x00000200UL

/* Register offsets within each of the MMC/SD/SDIO controllers */
#define OMAP35XX_MMCHS_SYSCONFIG	0x010
#define OMAP35XX_MMCHS_SYSSTATUS	0x014
#define OMAP35XX_MMCHS_CSRE			0x024
#define OMAP35XX_MMCHS_SYSTEST		0x028
#define OMAP35XX_MMCHS_CON			0x02C
#define OMAP35XX_MMCHS_PWCNT		0x030
#define OMAP35XX_MMCHS_BLK			0x104
#define OMAP35XX_MMCHS_ARG			0x108
#define OMAP35XX_MMCHS_CMD			0x10C
#define OMAP35XX_MMCHS_RSP10		0x110
#define OMAP35XX_MMCHS_RSP32		0x114
#define OMAP35XX_MMCHS_RSP54		0x118
#define OMAP35XX_MMCHS_RSP76		0x11C
#define OMAP35XX_MMCHS_DATA			0x120
#define OMAP35XX_MMCHS_PSTATE		0x124
#define OMAP35XX_MMCHS_HCTL			0x128
#define OMAP35XX_MMCHS_SYSCTL		0x12C
#define OMAP35XX_MMCHS_STAT			0x130
#define OMAP35XX_MMCHS_IE			0x134
#define OMAP35XX_MMCHS_ISE			0x138
#define OMAP35XX_MMCHS_AC12			0x13C
#define OMAP35XX_MMCHS_CAPA			0x140
#define OMAP35XX_MMCHS_CUR_CAPA		0x148
#define OMAP35XX_MMCHS_REV			0x1FC



#endif /* _OMAP35XX_REG_H_ */
