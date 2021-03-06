/************************************************************************************
* This file contains the Freescale HCS08 MCU register map for:
* - MC1323x
*
*
*
* (c) Copyright 2005, Freescale Semiconductor, Inc. All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
************************************************************************************/
#ifndef _IOCONFIG_MC1323x_H_
#define _IOCONFIG_MC1323x_H_


/***********  DIRECT ACCESS REGISTERS  ***********/
/* direct access registers addresses */
#define     PTAD        (*((volatile unsigned char *)(0x0000)))	/* I/O port A data register */
#define     PTAPE       (*((volatile unsigned char *)(0x1830)))	/* I/O port A pull-up enable register */
#define     PTASE       (*((volatile unsigned char *)(0x1831)))	/* I/O port A slew rate enable register */
#define     PTADS       (*((volatile unsigned char *)(0x1832)))	/* I/O port A drive strength register */
#define     PTADD       (*((volatile unsigned char *)(0x0001)))	/* I/O port A data direction register */

#define     PTBD        (*((volatile unsigned char *)(0x0002))) /* I/O port B data register */
#define     PTBPE       (*((volatile unsigned char *)(0x1834))) /* I/O port B pull-up enable register */
#define     PTBSE       (*((volatile unsigned char *)(0x1835))) /* I/O port B slew rate enable register */
#define     PTBDS       (*((volatile unsigned char *)(0x1836)))	/* I/O port B drive strength register */
#define     PTBDD       (*((volatile unsigned char *)(0x0003))) /* I/O port B data direction register */

#define     PTCD        (*((volatile unsigned char *)(0x0004))) /* I/O port C data register */	
#define     PTCPE       (*((volatile unsigned char *)(0x1838)))	/* I/O port C pull-up enable register */
#define     PTCSE       (*((volatile unsigned char *)(0x1839)))	/* I/O port C slew rate enable register */
#define     PTCDS       (*((volatile unsigned char *)(0x183A)))	/* I/O port C drive strength register */
#define     PTCDD       (*((volatile unsigned char *)(0x0005))) /* I/O port C data direction register */

#define     PTDD        (*((volatile unsigned char *)(0x0006)))	/* I/O port D data register */
#define     PTDPE       (*((volatile unsigned char *)(0x183C))) /* I/O port D pull-up enable register */
#define     PTDSE       (*((volatile unsigned char *)(0x183D)))	/* I/O port D slew rate enable register */
#define     PTDDS       (*((volatile unsigned char *)(0x183E)))	/* I/O port D drive strength register */
#define     PTDDD       (*((volatile unsigned char *)(0x0007)))	/* I/O port D data direction register */

#define     TPM1SC      (*((volatile unsigned char *)(0x0008)))	/* TPM1 status and control register */
#define     TPM1CNTH    (*((volatile unsigned char *)(0x0009)))	/* TPM1 counter (high half) */
#define     TPM1CNTL    (*((volatile unsigned char *)(0x000A)))	/* TPM1 counter (low half) */
#define     TPM1MODH    (*((volatile unsigned char *)(0x000B)))	/* TPM1 modulo register (high half) */
#define     TPM1MODL    (*((volatile unsigned char *)(0x000C)))	/* TPM1 modulo register(low half) */
#define     TPM1C0SC    (*((volatile unsigned char *)(0x000D)))	/* TPM1 channel 0 status and control */
#define     TPM1C0VH    (*((volatile unsigned char *)(0x000E)))	/* TPM1 channel 0 value register (high) */
#define     TPM1C0VL    (*((volatile unsigned char *)(0x000F)))	/* TPM1 channel 0 value register (low) */

#define     TPM2SC      (*((volatile unsigned char *)(0x0010)))	/* TPM2 status and control register */
#define     TPM2CNTH    (*((volatile unsigned char *)(0x0011)))	/* TPM2 counter (high half) */
#define     TPM2CNTL    (*((volatile unsigned char *)(0x0012)))	/* TPM2 counter (low half) */
#define     TPM2MODH    (*((volatile unsigned char *)(0x0013)))	/* TPM2 modulo register (high half) */
#define     TPM2MODL    (*((volatile unsigned char *)(0x0014)))	/* TPM2 modulo register(low half) */
#define     TPM2C0SC    (*((volatile unsigned char *)(0x0015)))	/* TPM2 channel 0 status and control */
#define     TPM2C0VH    (*((volatile unsigned char *)(0x0016)))	/* TPM2 channel 0 value register (high) */
#define     TPM2C0VL    (*((volatile unsigned char *)(0x0017)))	/* TPM2 channel 0 value register (low) */

#define     TPM3SC      (*((volatile unsigned char *)(0x0018)))	/* TPM3 status and control register */
#define     TPM3CNTH    (*((volatile unsigned char *)(0x0019)))	/* TPM3 counter (high half) */
#define     TPM3CNTL    (*((volatile unsigned char *)(0x001A)))	/* TPM3 counter (low half) */
#define     TPM3MODH    (*((volatile unsigned char *)(0x001B)))	/* TPM3 modulo register (high half) */
#define     TPM3MODL    (*((volatile unsigned char *)(0x001C)))	/* TPM3 modulo register(low half) */
#define     TPM3C0SC    (*((volatile unsigned char *)(0x001D)))	/* TPM3 channel 0 status and control */
#define     TPM3C0VH    (*((volatile unsigned char *)(0x001E)))	/* TPM3 channel 0 value register (high) */
#define     TPM3C0VL    (*((volatile unsigned char *)(0x001F)))	/* TPM3 channel 0 value register (low) */

#define     PP_AES_CTL1 (*((volatile unsigned char *)(0x0020)))	/* 802.15.4 Packet Processor AES Control1 */
#define     PP_AES_CTL2 (*((volatile unsigned char *)(0x0021)))	/* 802.15.4 Packet Processor AES Control2 */

#define     PP_ASM_D0   (*((volatile unsigned char *)(0x0022)))	/* 802.15.4 Packet Processor ASM Data_0 */
#define     PP_ASM_D1   (*((volatile unsigned char *)(0x0023)))	/* 802.15.4 Packet Processor ASM Data_1 */
#define     PP_ASM_D2   (*((volatile unsigned char *)(0x0024)))	/* 802.15.4 Packet Processor ASM Data_2 */
#define     PP_ASM_D3   (*((volatile unsigned char *)(0x0025)))	/* 802.15.4 Packet Processor ASM Data_3 */
#define     PP_ASM_D4   (*((volatile unsigned char *)(0x0026)))	/* 802.15.4 Packet Processor ASM Data_4 */
#define     PP_ASM_D5   (*((volatile unsigned char *)(0x0027)))	/* 802.15.4 Packet Processor ASM Data_5 */
#define     PP_ASM_D6   (*((volatile unsigned char *)(0x0028)))	/* 802.15.4 Packet Processor ASM Data_6 */
#define     PP_ASM_D7   (*((volatile unsigned char *)(0x0029)))	/* 802.15.4 Packet Processor ASM Data_7 */
#define     PP_ASM_D8   (*((volatile unsigned char *)(0x002A)))	/* 802.15.4 Packet Processor ASM Data_8 */
#define     PP_ASM_D9   (*((volatile unsigned char *)(0x002B)))	/* 802.15.4 Packet Processor ASM Data_9 */
#define     PP_ASM_DA   (*((volatile unsigned char *)(0x002C)))	/* 802.15.4 Packet Processor ASM Data_A */
#define     PP_ASM_DB   (*((volatile unsigned char *)(0x002D)))	/* 802.15.4 Packet Processor ASM Data_B */
#define     PP_ASM_DC   (*((volatile unsigned char *)(0x002E)))	/* 802.15.4 Packet Processor ASM Data_C */
#define     PP_ASM_DD   (*((volatile unsigned char *)(0x002F)))	/* 802.15.4 Packet Processor ASM Data_D */
#define     PP_ASM_DE   (*((volatile unsigned char *)(0x0030)))	/* 802.15.4 Packet Processor ASM Data_E */
#define     PP_ASM_DF   (*((volatile unsigned char *)(0x0031)))	/* 802.15.4 Packet Processor ASM Data_F */

#define     KBISC       (*((volatile unsigned char *)(0x0032)))	/* KBI1 status and control register */
#define     KBIPE       (*((volatile unsigned char *)(0x0033)))	/* KBI1 pin enable controls */
#define     KBIES       (*((volatile unsigned char *)(0x0034)))	/* KBI1 edge select register */

#define     KBI2SC      (*((volatile unsigned char *)(0x0035)))	/* KBI2 status and control register */
#define     KBI2PE      (*((volatile unsigned char *)(0x0036)))	/* KBI2 pin enable controls */
#define     KBI2ES      (*((volatile unsigned char *)(0x0037)))	/* KBI2 edge select register */

#define     SCI1BDH     (*((volatile unsigned char *)(0x0038)))	/* SCI baud rate register (high) */
#define     SCI1BDL     (*((volatile unsigned char *)(0x0039)))	/* SCI baud rate register (low byte) */
#define     SCI1C1      (*((volatile unsigned char *)(0x003A)))	/* SCI control register 1 */
#define     SCI1C2      (*((volatile unsigned char *)(0x003B)))	/* SCI control register 2 */
#define     SCI1S1      (*((volatile unsigned char *)(0x003C)))
#define     SCI1S2      (*((volatile unsigned char *)(0x003D)))
#define     SCI1C3      (*((volatile unsigned char *)(0x003E)))	/* SCI control register 3 */
#define     SCI1D       (*((volatile unsigned char *)(0x003F)))	/* SCI data register (low byte) */
#define     SCI1C4      (*((volatile unsigned char *)(0x1804))) /* SCI control register 4 */

#define     PP_PHY_TXP         (*((volatile         void **)(0x0040)))	/* 802.15.4 Packet Processor PHY TXD_ADR_PNTR (entire) */
#define     PP_PHY_TXPH        (*((volatile unsigned char *)(0x0040)))	/* 802.15.4 Packet Processor PHY TXD_ADR_PNTR (high) */
#define     PP_PHY_TXPL        (*((volatile unsigned char *)(0x0041)))	/* 802.15.4 Packet Processor PHY TXD_ADR_PNTR (low) */
#define     PP_PHY_RXP         (*((volatile         void **)(0x0042)))	/* 802.15.4 Packet Processor PHY RXD_ADR_PNTR (entire) */
#define     PP_PHY_RXPH        (*((volatile unsigned char *)(0x0042)))	/* 802.15.4 Packet Processor PHY RXD_ADR_PNTR (high) */
#define     PP_PHY_RXPL        (*((volatile unsigned char *)(0x0043)))	/* 802.15.4 Packet Processor PHY RXD_ADR_PNTR (low) */
#define     PP_PHY_CTL1        (*((volatile unsigned char *)(0x0044)))	/* 802.15.4 Packet Processor PHY CNTRL1 */
#define     PP_PHY_CTL2        (*((volatile unsigned char *)(0x0045)))	/* 802.15.4 Packet Processor PHY CNTRL2 */
#define     PP_PHY_CTL3        (*((volatile unsigned char *)(0x0046)))	/* 802.15.4 Packet Processor PHY CNTRL3 */
#define     PP_PHY_CTL4        (*((volatile unsigned char *)(0x0047)))	/* 802.15.4 Packet Processor PHY CNTRL4 */
#define     PP_PHY_SCTL        (*((volatile unsigned char *)(0x0048)))	/* 802.15.4 Packet Processor PHY SRC_CNTRL */
#define     PP_PHY_SADRSUMD    (*((volatile unsigned short*)(0x0049)))	/* 802.15.4 Packet Processor PHY SRC_ADDRS_SUM_DATA (entire) */
#define     PP_PHY_SADRSUMDH   (*((volatile unsigned char *)(0x0049)))	/* 802.15.4 Packet Processor PHY SRC_ADDRS_SUM_DATA (high) */
#define     PP_PHY_SADRSUMDL   (*((volatile unsigned char *)(0x004A)))	/* 802.15.4 Packet Processor PHY SRC_ADDRS_SUM_DATA (low) */
#define     PP_PHY_RXWTRMARK   (*((volatile unsigned char *)(0x004B)))	/* 802.15.4 Packet Processor PHY RX_WTR_MARK */
#define     PP_PHY_RXBYTECNT   (*((volatile unsigned char *)(0x004C)))	/* 802.15.4 Packet Processor PHY RX_BYTE_COUNT */
#define     PP_PHY_STATUS1     (*((volatile unsigned char *)(0x004D)))	/* 802.15.4 Packet Processor PHY STATUS1 */
#define     PP_PHY_STATUS2     (*((volatile unsigned char *)(0x004E)))	/* 802.15.4 Packet Processor PHY STATUS2 */
#define     PP_PHY_CCAINST     (*((volatile unsigned char *)(0x004F)))	/* 802.15.4 Packet Processor PHY CCA_INST */
#define     PP_PHY_CCAFNL      (*((volatile unsigned char *)(0x0050)))	/* 802.15.4 Packet Processor PHY CCAFNL */
#define     PP_PHY_EVENTTMR16  (*((volatile unsigned char *)(0x0051)))	/* 802.15.4 Packet Processor PHY EVENT_TMR [23:16] */
#define     PP_PHY_EVENTTMR8   (*((volatile unsigned char *)(0x0052)))	/* 802.15.4 Packet Processor PHY EVENT_TMR [15:8]  */
#define     PP_PHY_EVENTTMR0   (*((volatile unsigned char *)(0x0053)))	/* 802.15.4 Packet Processor PHY EVENT_TMR [7:0]   */
#define     PP_PHY_TIMESTMP16  (*((volatile unsigned char *)(0x0054)))	/* 802.15.4 Packet Processor PHY TIME_STAMP [23:16] */
#define     PP_PHY_TIMESTMP8   (*((volatile unsigned char *)(0x0055)))	/* 802.15.4 Packet Processor PHY TIME_STAMP [15:8]  */
#define     PP_PHY_TIMESTMP0   (*((volatile unsigned char *)(0x0056)))	/* 802.15.4 Packet Processor PHY TIME_STAMP [7:0]   */
#define     PP_PHY_T3CMP16     (*((volatile unsigned char *)(0x0057)))	/* 802.15.4 Packet Processor PHY T3CMP [23:16] */
#define     PP_PHY_T3CMP8      (*((volatile unsigned char *)(0x0058)))	/* 802.15.4 Packet Processor PHY T3CMP [15:8]  */
#define     PP_PHY_T3CMP0      (*((volatile unsigned char *)(0x0059)))	/* 802.15.4 Packet Processor PHY T3CMP [7:0]   */
#define     PP_PHY_TC2PRIME    (*((volatile unsigned short*)(0x005A)))	/* 802.15.4 Packet Processor PHY TC2PRIME [15:0]  */
#define     PP_PHY_TC2PRIMEH   (*((volatile unsigned char *)(0x005A)))	/* 802.15.4 Packet Processor PHY TC2PRIME [15:8]  */
#define     PP_PHY_TC2PRIMEL   (*((volatile unsigned char *)(0x005B)))	/* 802.15.4 Packet Processor PHY TC2PRIME [7:0]   */
#define     PP_PHY_SHRTADDR    (*((volatile unsigned short*)(0x005C)))	/* 802.15.4 Packet Processor PHY macShortAddrs [15:0]  */
#define     PP_PHY_SHRTADDRH   (*((volatile unsigned char *)(0x005C)))	/* 802.15.4 Packet Processor PHY macShortAddrs [15:8]  */
#define     PP_PHY_SHRTADDRL   (*((volatile unsigned char *)(0x005D)))	/* 802.15.4 Packet Processor PHY macShortAddrs [7:0]   */
#define     PP_PHY_PANID       (*((volatile unsigned short*)(0x005E)))	/* 802.15.4 Packet Processor PHY macPanId [15:0]  */
#define     PP_PHY_PANIDH      (*((volatile unsigned char *)(0x005E)))	/* 802.15.4 Packet Processor PHY macPanId [15:8]  */
#define     PP_PHY_PANIDL      (*((volatile unsigned char *)(0x005F)))	/* 802.15.4 Packet Processor PHY macPanId [7:0]   */

#define     PP_PHY_T1CMP16     (*((volatile unsigned char *)(0x1840)))	/* 802.15.4 Packet Processor PHY T1CMP [23:16] */
#define     PP_PHY_T1CMP8      (*((volatile unsigned char *)(0x1841)))	/* 802.15.4 Packet Processor PHY T1CMP [15:8] */
#define     PP_PHY_T1CMP0      (*((volatile unsigned char *)(0x1842)))	/* 802.15.4 Packet Processor PHY T1CMP [7:0] */
#define     PP_PHY_T2CMP16     (*((volatile unsigned char *)(0x1843)))	/* 802.15.4 Packet Processor PHY T2CMP [23:16] */
#define     PP_PHY_T2CMP8      (*((volatile unsigned char *)(0x1844)))	/* 802.15.4 Packet Processor PHY T2CMP [15:8] */
#define     PP_PHY_T2CMP0      (*((volatile unsigned char *)(0x1845)))	/* 802.15.4 Packet Processor PHY T2CMP [7:0] */
#define     PP_PHY_T4CMP16     (*((volatile unsigned char *)(0x1846)))	/* 802.15.4 Packet Processor PHY T4CMP [23:16] */
#define     PP_PHY_T4CMP8      (*((volatile unsigned char *)(0x1847)))	/* 802.15.4 Packet Processor PHY T4CMP [15:8] */
#define     PP_PHY_T4CMP0      (*((volatile unsigned char *)(0x1848)))	/* 802.15.4 Packet Processor PHY T4CMP [7:0] */
#define     PP_PHY_LO1FRAC     (*((volatile unsigned short*)(0x1849)))	/* 802.15.4 Packet Processor PHY LO1_FRAC [15:0] */
#define     PP_PHY_LO1FRACH    (*((volatile unsigned char *)(0x1849)))	/* 802.15.4 Packet Processor PHY LO1_FRAC [15:8] */
#define     PP_PHY_LO1FRACL    (*((volatile unsigned char *)(0x184A)))	/* 802.15.4 Packet Processor PHY LO1_FRAC [7:0] */
#define     PP_PHY_LO1INT      (*((volatile unsigned char *)(0x184B)))	/* 802.15.4 Packet Processor PHY LO1_INT */
#define     PP_PHY_PAPWRCTRL   (*((volatile unsigned char *)(0x184C)))	/* 802.15.4 Packet Processor PHY PA PWR CNTL */
#define     PP_PHY_LONGADR56   (*((volatile unsigned char *)(0x184D)))	/* 802.15.4 Packet Processor PHY MAC LONG ADDRS [63:56] */
#define     PP_PHY_LONGADR48   (*((volatile unsigned char *)(0x184E)))	/* 802.15.4 Packet Processor PHY MAC LONG ADDRS [55:48] */
#define     PP_PHY_LONGADR40   (*((volatile unsigned char *)(0x184F)))	/* 802.15.4 Packet Processor PHY MAC LONG ADDRS [47:40] */
#define     PP_PHY_LONGADR32   (*((volatile unsigned char *)(0x1850)))	/* 802.15.4 Packet Processor PHY MAC LONG ADDRS [39:32] */
#define     PP_PHY_LONGADR24   (*((volatile unsigned char *)(0x1851)))	/* 802.15.4 Packet Processor PHY MAC LONG ADDRS [31:24] */
#define     PP_PHY_LONGADR16   (*((volatile unsigned char *)(0x1852)))	/* 802.15.4 Packet Processor PHY MAC LONG ADDRS [23:16] */
#define     PP_PHY_LONGADR8    (*((volatile unsigned char *)(0x1853)))	/* 802.15.4 Packet Processor PHY MAC LONG ADDRS [15:8] */
#define     PP_PHY_LONGADR0    (*((volatile unsigned char *)(0x1854)))	/* 802.15.4 Packet Processor PHY MAC LONG ADDRS [7:0] */
#define     PP_PHY_MAXFRMLEN   (*((volatile unsigned char *)(0x1855)))	/* 802.15.4 Packet Processor PHY MAX FRAME LENGTH */
#define     PP_PHY_RXFRMFLT    (*((volatile unsigned char *)(0x1856)))	/* 802.15.4 Packet Processor PHY RX FRAME FILTER */
#define     PP_PHY_FRMREVTMR   (*((volatile unsigned char *)(0x1857)))	/* 802.15.4 Packet Processor PHY FRAME VER & TMR */
#define     PP_PHY_CCATHRSHD   (*((volatile unsigned char *)(0x1858)))	/* 802.15.4 Packet Processor PHY CCA THRESHOLD */
#define     PP_PHY_CCAOFSCMP   (*((volatile unsigned char *)(0x1859)))	/* 802.15.4 Packet Processor PHY CCA OFFSET CMP */
#define     PP_PHY_FSM         (*((volatile unsigned char *)(0x185A)))	/* 802.15.4 Packet Processor PHY FSM */
#define     PP_PHY_INDACCIDX   (*((volatile unsigned char *)(0x185B)))	/* 802.15.4 Packet Processor PHY INDIRECT ACCESS INDEX */
#define     PP_PHY_INDACCREG   (*((volatile unsigned char *)(0x185C)))	/* 802.15.4 Packet Processor PHY INDIRECT ACCESS REG */

#define     CMTCGH1     (*((volatile unsigned char *)(0x0060)))
#define     CMTCGL1     (*((volatile unsigned char *)(0x0061)))
#define     CMTCGH2     (*((volatile unsigned char *)(0x0062)))
#define     CMTCGL2     (*((volatile unsigned char *)(0x0063)))
#define     CMTOC       (*((volatile unsigned char *)(0x0064)))
#define     CMTMSC      (*((volatile unsigned char *)(0x0065)))
#define     CMTCMD1     (*((volatile unsigned char *)(0x0066)))
#define     CMTCMD2     (*((volatile unsigned char *)(0x0067)))
#define     CMTCMD3     (*((volatile unsigned char *)(0x0068)))
#define     CMTCMD4     (*((volatile unsigned char *)(0x0069)))

#define     IIC1A       (*((volatile unsigned char *)(0x006A)))	/* IIC1 address register */
#define     IIC1F       (*((volatile unsigned char *)(0x006B)))	/* IIC1 frequency divider register */
#define     IIC1C1      (*((volatile unsigned char *)(0x006C)))	/* IIC1 control register 1 */
#define     IIC1S       (*((volatile unsigned char *)(0x006D)))	/* IIC1 status register */
#define     IIC1D       (*((volatile unsigned char *)(0x006E)))	/* IIC1 data I/O register */
#define     IIC1C2      (*((volatile unsigned char *)(0x006F)))	/* IIC1 control register 2 */

#define     SPIC1       (*((volatile unsigned char *)(0x0070)))	/* SPI1 control register 1 */
#define     SPIC2       (*((volatile unsigned char *)(0x0071)))	/* SPI1 control register 2 */
#define     SPIBR       (*((volatile unsigned char *)(0x0072)))	/* SPI1 baud rate select */
#define     SPIS        (*((volatile unsigned char *)(0x0073)))	/* SPI1 status register */
#define     SPID        (*((volatile unsigned char *)(0x0075)))	/* SPI1 data register */

#define     IRQSC       (*((volatile unsigned char *)(0x0076)))	/* Interrupt Status and Control Register */

#define	    PPAGE   	  (*((volatile unsigned char *)(0x0078))) /* PPAGE Register */
#define     LAP2    	  (*((volatile unsigned char *)(0x0079))) /* LAP2 Register */
#define     LAP1    	  (*((volatile unsigned char *)(0x007A))) /* LAP1 Register */
#define     LAP0    	  (*((volatile unsigned char *)(0x007B))) /* LAP0 Register */
#define     LWP     	  (*((volatile unsigned char *)(0x007C))) /* LWP Register */
#define     LBP     	  (*((volatile unsigned char *)(0x007D))) /* LBP Register */
#define     LB      	  (*((volatile unsigned char *)(0x007E))) /* LB Register */
#define     LAPAB       (*((volatile unsigned char *)(0x007F))) /* LAPAB Register */

#define     SIMRS       (*((volatile unsigned char *)(0x1800)))	/* SIM reset status register */
#define     SIMC        (*((volatile unsigned char *)(0x1801)))	/* SIM control (BDC access only) */
#define     SIMOPT      (*((volatile unsigned char *)(0x1802)))	/* SIM options register (write once) */
#define     SIMOPT2     (*((volatile unsigned char *)(0x1803)))	/* SIM options register 2 (write once) */
#define     SIMTMR      (*((volatile unsigned char *)(0x1805)))	/* SIM Test Mode Register */
#define     SIMIDH      (*((volatile unsigned char *)(0x1806)))	/* SIM Part I.D. high (read-only) */
#define     SIMIDL      (*((volatile unsigned char *)(0x1807)))	/* SIM Part I.D. low (read-only) */

#define     SPMSC1      (*((volatile unsigned char *)(0x1808)))	/* System Power Management Status & Control 1 */
#define     SPMSC2      (*((volatile unsigned char *)(0x1809)))	/* System Power Management Status & Control 2 */
#define     SPMSC3      (*((volatile unsigned char *)(0x180B)))	/* System Power Management Status & Control 3 */

#define     SOMC1       (*((volatile unsigned char *)(0x180C)))	/* System Oscillator Management and Control Register 1 */
#define     SOMC2       (*((volatile unsigned char *)(0x180D)))	/* System Oscillator Management and Control Register 2 */

#define     SCGC1       (*((volatile unsigned char *)(0x180E)))	/* System Clock Gating Control 1 */
#define     SCGC2       (*((volatile unsigned char *)(0x180F)))	/* System Clock Gating Control 2 */

#define     DBGCAH      (*((volatile unsigned char *)(0x1810)))	/* DBG comparator register A (high) */
#define     DBGCAL      (*((volatile unsigned char *)(0x1811)))	/* DBG comparator register A (low) */
#define     DBGCBH      (*((volatile unsigned char *)(0x1812)))	/* DBG comparator register B (high) */
#define     DBGCBL      (*((volatile unsigned char *)(0x1813)))	/* DBG comparator register B (low) */
#define     DBGCCH      (*((volatile unsigned char *)(0x1814)))	/* DBG comparator register B (high) */
#define     DBGCCL      (*((volatile unsigned char *)(0x1815)))	/* DBG comparator register B (low) */
#define     DBGFH       (*((volatile unsigned char *)(0x1816)))	/* DBG FIFO register (high) */
#define     DBGFL       (*((volatile unsigned char *)(0x1817)))	/* DBG FIFO register (low) */
#define     DBGCAX      (*((volatile unsigned char *)(0x1818)))
#define     DBGCBX      (*((volatile unsigned char *)(0x1819)))
#define     DBGCCX      (*((volatile unsigned char *)(0x181A)))
#define     DBGFX       (*((volatile unsigned char *)(0x181B)))

#define     DBGC        (*((volatile unsigned char *)(0x181C)))	/* DBG control register */
#define     DBGT        (*((volatile unsigned char *)(0x181D)))	/* DBG trigger register */
#define     DBGS        (*((volatile unsigned char *)(0x181E)))	/* DBG status register */
#define     DBGCNT      (*((volatile unsigned char *)(0x181F)))

#define     FCDIV       (*((volatile unsigned char *)(0x1820)))	/* Flash/EE clock divider register */
#define     FOPT        (*((volatile unsigned char *)(0x1821)))	/* Flash/EE option register */
#define     FCNFG       (*((volatile unsigned char *)(0x1823)))	/* Flash/EE configuration register */
#define     FPROT       (*((volatile unsigned char *)(0x1824)))	/* Flash protection register */
#define     FSTAT       (*((volatile unsigned char *)(0x1825)))	/* Flash status register */
#define     FCMD        (*((volatile unsigned char *)(0x1826)))	/* Flash command register */

#define     RTCSC       (*((volatile unsigned char *)(0x1828)))	/* RTC Status and control register */
#define     RTCCNTL     (*((volatile unsigned char *)(0x1829)))	/* RTC Count register [7:0] */
#define     RTCMODL     (*((volatile unsigned char *)(0x182A)))	/* RTC Modulo register [7:0]  */
#define     RTCCNTH     (*((volatile unsigned char *)(0x182B)))	/* RTC Count register RTC [15:8]  */
#define     RTCMODH     (*((volatile unsigned char *)(0x182C)))	/* RTC Modulo register [15:8] */

#define     TPM4SC      (*((volatile unsigned char *)(0x1860)))	/* TPM4 status and control register */
#define     TPM4CNTH    (*((volatile unsigned char *)(0x1861)))	/* TPM4 counter (high half) */
#define     TPM4CNTL    (*((volatile unsigned char *)(0x1862))) /* TPM4 counter (low half) */
#define     TPM4MODH    (*((volatile unsigned char *)(0x1863))) /* TPM4 modulo register (high half) */
#define     TPM4MODL    (*((volatile unsigned char *)(0x1864))) /* TPM4 modulo register(low half) */
#define     TPM4C0SC    (*((volatile unsigned char *)(0x1865)))	/* TPM4 channel 0 status and control */
#define     TPM4C0VH    (*((volatile unsigned char *)(0x1866)))	/* TPM4 channel 0 value register (high) */
#define     TPM4C0VL    (*((volatile unsigned char *)(0x1867)))	/* TPM4 channel 0 value register (low) */

#define     LVDTRIM     (*((volatile unsigned char *)(0x186D)))	/* LVD TRIM  - write once register */

#if defined(PROCESSOR_MC13237C)

#define     ADCSC1      (*((volatile unsigned char *)(0x1870)))    /* ADC Status and Control Register 1 */
#define     ADCSC2      (*((volatile unsigned char *)(0x1871)))    /* ADC Status and Control Register 2 */
#define     ADCRH       (*((volatile unsigned char *)(0x1872)))    /* ADC Data Result High Register */
#define     ADCRL       (*((volatile unsigned char *)(0x1873)))    /* ADC Data Result Low Register */
#define     ADCCVH      (*((volatile unsigned char *)(0x1874)))    /* ADC Compare Value High Register */
#define     ADCCVL      (*((volatile unsigned char *)(0x1875)))    /* ADC Compare Value Low Register */
#define     ADCCFG      (*((volatile unsigned char *)(0x1876)))    /* ADC Configuration Register */
#define     ADCCTL1     (*((volatile unsigned char *)(0x1877)))    /* ADC Pin Control 1 Register */
//#define   ADCCTL2     (*((volatile unsigned char *)(0x1878)))    /* ADC Pin Control 2 Register */
//#define   ADCCTL3     (*((volatile unsigned char *)(0x1879)))    /* ADC Pin Control 3 Register */

#endif //PROCESSOR_MC13237C

#ifdef PROCESSOR_MC13238C

#pragma MESSAGE DISABLE C1106
/*** USBCTL0 - USB Control Register 0; 0x00001870 ***/
typedef union {
  unsigned char Byte;
  struct {
    unsigned char USBPHYEN    :1;                                       /* USB PHY Tranceiver Enable */
    unsigned char             :1; 
    unsigned char USBVREN     :1;                                       /* USB Voltage Regulator Enable */
    unsigned char DMODE       :1; 
    unsigned char LPRESF      :1;                                       /* Low-Power Resume Flag */
    unsigned char USBRESMEN   :1;                                       /* USB Low-Power Resume Event Enable */
    unsigned char USBPU       :1;                                       /* Pull Up Source */
    unsigned char USBRESET    :1;                                       /* USB Reset */
  } Bits;
} USBCTL0STR;

#define     _USBCTL0     (*((volatile USBCTL0STR *)(0x1870)))	/**/

#define USBCTL0                         _USBCTL0.Byte
#define USBCTL0_USBPHYEN                _USBCTL0.Bits.USBPHYEN
#define USBCTL0_USBVREN                 _USBCTL0.Bits.USBVREN
#define USBCTL0_DMODE                   _USBCTL0.Bits.DMODE
#define USBCTL0_LPRESF                  _USBCTL0.Bits.LPRESF
#define USBCTL0_USBRESMEN               _USBCTL0.Bits.USBRESMEN
#define USBCTL0_USBPU                   _USBCTL0.Bits.USBPU
#define USBCTL0_USBRESET                _USBCTL0.Bits.USBRESET

#define USBCTL0_USBPHYEN_MASK           1
#define USBCTL0_USBVREN_MASK            4
#define USBCTL0_DMODE_MASK              8
#define USBCTL0_LPRESF_MASK             16
#define USBCTL0_USBRESMEN_MASK          32
#define USBCTL0_USBPU_MASK              64
#define USBCTL0_USBRESET_MASK           128

/*** CTL - Control Register; 0x00001871 ***/
typedef union {
  unsigned char Byte;
  struct {
    unsigned char USBEN       :1;                                       /* USB Enable */
    unsigned char ODDRST      :1;                                       /* Odd Reset */
    unsigned char CRESUME     :1;                                       /* Resume Signaling */
    unsigned char             :1; 
    unsigned char             :1; 
    unsigned char TSUSPEND    :1;                                       /* Transaction Suspend */
    unsigned char             :1; 
    unsigned char             :1; 
  } Bits;
} CTLSTR;

#define     _CTL     (*((volatile CTLSTR *)(0x1871)))	/**/

#define CTL                             _CTL.Byte
#define CTL_USBEN                       _CTL.Bits.USBEN
#define CTL_ODDRST                      _CTL.Bits.ODDRST
#define CTL_CRESUME                     _CTL.Bits.CRESUME
#define CTL_TSUSPEND                    _CTL.Bits.TSUSPEND

#define CTL_USBEN_MASK                  1
#define CTL_ODDRST_MASK                 2
#define CTL_CRESUME_MASK                4
#define CTL_TSUSPEND_MASK               32


/*** STAT - Status Register; 0x00001872 ***/
typedef union {
  unsigned char Byte;
  struct {
    unsigned char             :1; 
    unsigned char             :1; 
    unsigned char IN          :1;                                       /* Odd/Even Transaction */
    unsigned char DEV_ENDP    :5;                                       /* Endpoint Number Bit 0 */
  } Bits;
} STATSTR;

#define     _STAT     (*((volatile STATSTR *)(0x1872)))	/**/

#define STAT                            _STAT.Byte
#define STAT_IN                         _STAT.Bits.IN
#define STAT_DEVENP                     _STAT.Bits.DEV_ENDP



#define STAT_IN_MASK                    4
#define STAT_DEVENP0_MASK               8
#define STAT_DEVENP1_MASK               16
#define STAT_DEVENP2_MASK               32
#define STAT_DEVENP3_MASK               64
#define STAT_DEVENP4_MASK               128
#define STAT_DEVENP_MASK                248
#define STAT_DEVENP_BITNUM              5


/*** INTENB - Interrupt Enable Register; 0x00001873 ***/
typedef union {
  unsigned char Byte;
  struct {
    unsigned char USBRST      :1;                                       /* USBRST Interrupt Enable */
    unsigned char ERROR       :1;                                       /* ERROR Interrupt Enable */
    unsigned char SOFTOK      :1;                                       /* SOFTOK Interrupt Enable */
    unsigned char TOKDNE      :1;                                       /* TOKDNE Interrupt Enable */
    unsigned char SLEEP       :1;                                       /* SLEEP Interrupt Enable */
    unsigned char RESUME      :1;                                       /* RESUME Interrupt Enable */
    unsigned char             :1; 
    unsigned char STALL       :1;                                       /* STALL Interrupt Enable */
  } Bits;
} INTENBSTR;


#define     _INTENB     (*((volatile INTENBSTR *)(0x1873)))	/**/

#define INTENB                          _INTENB.Byte
#define INTENB_USBRST                   _INTENB.Bits.USBRST
#define INTENB_ERROR                    _INTENB.Bits.ERROR
#define INTENB_SOFTOK                   _INTENB.Bits.SOFTOK
#define INTENB_TOKDNE                   _INTENB.Bits.TOKDNE
#define INTENB_SLEEP                    _INTENB.Bits.SLEEP
#define INTENB_RESUME                   _INTENB.Bits.RESUME
#define INTENB_STALL                    _INTENB.Bits.STALL

#define INTENB_USBRST_MASK              1
#define INTENB_ERROR_MASK               2
#define INTENB_SOFTOK_MASK              4
#define INTENB_TOKDNE_MASK              8
#define INTENB_SLEEP_MASK               16
#define INTENB_RESUME_MASK              32
#define INTENB_STALL_MASK               128

/*** INTSTAT - Interrupt Status Register; 0x00001874 ***/
typedef union {
  unsigned char Byte;
  struct {
    unsigned char USBRSTF     :1;                                       /* USB Reset Flag */
    unsigned char ERRORF      :1;                                       /* Error Flag */
    unsigned char SOFTOKF     :1;                                       /* SOF Token Flag */
    unsigned char TOKDNEF     :1;                                       /* Token Complete Flag */
    unsigned char SLEEPF      :1;                                       /* Sleep Flag */
    unsigned char RESUMEF     :1;                                       /* Resume Flag */
    unsigned char             :1; 
    unsigned char STALLF      :1;                                       /* Stall Flag */
  } Bits;
} INTSTATSTR;


#define     _INTSTAT     (*((volatile INTSTATSTR *)(0x1874)))	/**/

#define INTSTAT                         _INTSTAT.Byte
#define INTSTAT_USBRSTF                 _INTSTAT.Bits.USBRSTF
#define INTSTAT_ERRORF                  _INTSTAT.Bits.ERRORF
#define INTSTAT_SOFTOKF                 _INTSTAT.Bits.SOFTOKF
#define INTSTAT_TOKDNEF                 _INTSTAT.Bits.TOKDNEF
#define INTSTAT_SLEEPF                  _INTSTAT.Bits.SLEEPF
#define INTSTAT_RESUMEF                 _INTSTAT.Bits.RESUMEF
#define INTSTAT_STALLF                  _INTSTAT.Bits.STALLF

#define INTSTAT_USBRSTF_MASK            1
#define INTSTAT_ERRORF_MASK             2
#define INTSTAT_SOFTOKF_MASK            4
#define INTSTAT_TOKDNEF_MASK            8
#define INTSTAT_SLEEPF_MASK             16
#define INTSTAT_RESUMEF_MASK            32
#define INTSTAT_STALLF_MASK             128


/*** ERRENB - Error Interrupt Enable Register; 0x00001875 ***/
typedef union {
  unsigned char Byte;
  struct {
    unsigned char PIDERR      :1;                                       /* PIDERR Interrupt Enable */
    unsigned char CRC5        :1;                                       /* CRC5 Interrupt Enable */
    unsigned char CRC16       :1;                                       /* CRC16 Interrupt Enable */
    unsigned char DFN8        :1;                                       /* DFN8 Interrupt Enable */
    unsigned char BTOERR      :1;                                       /* BTOERR Interrupt Enable */
    unsigned char BUFERR      :1;                                       /* BUFERR Interrupt Enable */
    unsigned char             :1; 
    unsigned char BTSERR      :1;                                       /* BTSERR Interrupt Enable */
  } Bits;
} ERRENBSTR;


#define     _ERRENB     (*((volatile ERRENBSTR *)(0x1875)))	/**/

#define ERRENB                          _ERRENB.Byte
#define ERRENB_PIDERR                   _ERRENB.Bits.PIDERR
#define ERRENB_CRC5                     _ERRENB.Bits.CRC5
#define ERRENB_CRC16                    _ERRENB.Bits.CRC16
#define ERRENB_DFN8                     _ERRENB.Bits.DFN8
#define ERRENB_BTOERR                   _ERRENB.Bits.BTOERR
#define ERRENB_BUFERR                   _ERRENB.Bits.BUFERR
#define ERRENB_BTSERR                   _ERRENB.Bits.BTSERR

#define ERRENB_PIDERR_MASK              1
#define ERRENB_CRC5_MASK                2
#define ERRENB_CRC16_MASK               4
#define ERRENB_DFN8_MASK                8
#define ERRENB_BTOERR_MASK              16
#define ERRENB_BUFERR_MASK              32
#define ERRENB_BTSERR_MASK              128

/*** ERRSTAT - Error Interrupt Status Register; 0x00001876 ***/
typedef union {
  unsigned char Byte;
  struct {
    unsigned char PIDERRF     :1;                                       /* PID Error Flag */
    unsigned char CRC5F       :1;                                       /* CRC5 Error Flag */
    unsigned char CRC16F      :1;                                       /* CRC16 Error Flag */
    unsigned char DFN8F       :1;                                       /* Data Field Error Flag */
    unsigned char BTOERRF     :1;                                       /* Bus Turnaround Error Timeout Flag */
    unsigned char BUFERRF     :1;                                       /* Buffer Error Flag */
    unsigned char             :1; 
    unsigned char BTSERRF     :1;                                       /* Bit Stuff Error Flag */
  } Bits;
} ERRSTATSTR;


#define     _ERRSTAT     (*((volatile ERRSTATSTR *)(0x1876)))	/**/

#define ERRSTAT                         _ERRSTAT.Byte
#define ERRSTAT_PIDERRF                 _ERRSTAT.Bits.PIDERRF
#define ERRSTAT_CRC5F                   _ERRSTAT.Bits.CRC5F
#define ERRSTAT_CRC16F                  _ERRSTAT.Bits.CRC16F
#define ERRSTAT_DFN8F                   _ERRSTAT.Bits.DFN8F
#define ERRSTAT_BTOERRF                 _ERRSTAT.Bits.BTOERRF
#define ERRSTAT_BUFERRF                 _ERRSTAT.Bits.BUFERRF
#define ERRSTAT_BTSERRF                 _ERRSTAT.Bits.BTSERRF

#define ERRSTAT_PIDERRF_MASK            1
#define ERRSTAT_CRC5F_MASK              2
#define ERRSTAT_CRC16F_MASK             4
#define ERRSTAT_DFN8F_MASK              8
#define ERRSTAT_BTOERRF_MASK            16
#define ERRSTAT_BUFERRF_MASK            32
#define ERRSTAT_BTSERRF_MASK            128

#define     FRMNUMH     (*((volatile unsigned char *)(0x1877)))	/**/
#define     FRMNUML     (*((volatile unsigned char *)(0x1878)))	/**/
#define     FRMNUM      (*((volatile unsigned short *)(0x1877)))	/**/

#define     USBDEVC     (*((volatile unsigned char *)(0x1879)))	/**/

/*** ADDR - Address Register; 0x0000187A ***/
typedef union {
  unsigned char Byte;
  struct {
    unsigned char ADDR0       :1;                                       /* USB Address Bit 0 */
    unsigned char ADDR1       :1;                                       /* USB Address Bit 1 */
    unsigned char ADDR2       :1;                                       /* USB Address Bit 2 */
    unsigned char ADDR3       :1;                                       /* USB Address Bit 3 */
    unsigned char ADDR4       :1;                                       /* USB Address Bit 4 */
    unsigned char ADDR5       :1;                                       /* USB Address Bit 5 */
    unsigned char ADDR6       :1;                                       /* USB Address Bit 6 */
    unsigned char ADDRE       :1; 
  } Bits;
  struct {
    unsigned char grpADDR :7;
    unsigned char ADDRE   :1;
  } MergedBits;
} ADDRSTR;


#define     _ADDR     (*((volatile ADDRSTR *)(0x187A)))	/**/

#define ADDR                            _ADDR.Byte
#define ADDR_ADDR0                      _ADDR.Bits.ADDR0
#define ADDR_ADDR1                      _ADDR.Bits.ADDR1
#define ADDR_ADDR2                      _ADDR.Bits.ADDR2
#define ADDR_ADDR3                      _ADDR.Bits.ADDR3
#define ADDR_ADDR4                      _ADDR.Bits.ADDR4
#define ADDR_ADDR5                      _ADDR.Bits.ADDR5
#define ADDR_ADDR6                      _ADDR.Bits.ADDR6
#define ADDR_ADDRE                      _ADDR.Bits.ADDRE

#define ADDR_ADDR                       _ADDR.MergedBits.grpADDR

#define ADDR_ADDR0_MASK                 1
#define ADDR_ADDR1_MASK                 2
#define ADDR_ADDR2_MASK                 4
#define ADDR_ADDR3_MASK                 8
#define ADDR_ADDR4_MASK                 16
#define ADDR_ADDR5_MASK                 32
#define ADDR_ADDR6_MASK                 64
#define ADDR_ADDR_MASK                  127
#define ADDR_ADDRE_MASK                 128

#define ADDR_ADDR_BITNUM                0
#pragma MESSAGE DEFAULT C1106
#define     EPCTL0     (*((volatile unsigned char *)(0x187B)))	/**/
#define     EPCTL1     (*((volatile unsigned char *)(0x187C)))	/**/
#define     EPCTL2     (*((volatile unsigned char *)(0x187D)))	/**/
#define     EPCTL3     (*((volatile unsigned char *)(0x187E)))	/**/

#endif// ifdef PROCESSOR_MC13238C

#define     NVBACKKEY   (*((volatile unsigned char *)(0xFFB0)))	/* 8-byte backdoor comparison key */
#define     NVPROT     	(*((volatile unsigned char *)(0xFFBD)))	/* NV flash protection byte */
#define     NVOPT     	(*((volatile unsigned char *)(0xFFBF)))	/* NV flash options byte */

/* direct access registers bit definitions */
//  PP_PHY_CTL1
#define     PP_PHY_CTL1_TMRTRIGEN_BIT     (1<<7)
#define     PP_PHY_CTL1_SLOTTED_BIT       (1<<6)
#define     PP_PHY_CTL1_CCABFRTX_BIT      (1<<5)
#define     PP_PHY_CTL1_RXACKRQD_BIT      (1<<4)
#define     PP_PHY_CTL1_AUTOACK_BIT       (1<<3)
#define     PP_PHY_CTL1_XCVSEQ_MASK       (7<<0)

//  PP_PHY_CTL2
#define     PP_PHY_CTL2_CCA_TYPE_POS      3
#define     PP_PHY_CTL2_TRCV_MSK_BIT      (1<<7)
#define     PP_PHY_CTL2_TC3TMOUT_BIT      (1<<6)
#define     PP_PHY_CTL2_PANCORDNTR_BIT    (1<<5)
#define     PP_PHY_CTL2_CCA_TYPE_MASK     (3<<PP_PHY_CTL2_CCA_TYPE_POS)
#define     PP_PHY_CTL2_TMRLOAD_BIT       (1<<2)
#define     PP_PHY_CTL2_PROMISCUOUS_BIT   (1<<1)
#define     PP_PHY_CTL2_TC2PRIME_EN_BIT   (1<<0)

//  PP_PHY_CTL3
#define     PP_PHY_CTL3_CRC_MSK_BIT       (1<<7)
#define     PP_PHY_CTL3_LO1UNLOCK_MSK_BIT (1<<6)
#define     PP_PHY_CTL3_FLTR_FAIL_MSK_BIT (1<<5)
#define     PP_PHY_CTL3_RX_WMRK_MSK_BIT   (1<<4)
#define     PP_PHY_CTL3_CCA_MSK_BIT       (1<<3)
#define     PP_PHY_CTL3_RX_MSK_BIT        (1<<2)
#define     PP_PHY_CTL3_TX_MSK_BIT        (1<<1)
#define     PP_PHY_CTL3_SEQ_MSK_BIT       (1<<0)

//  PP_PHY_CTL4
#define     PP_PHY_CTL4_TMR4MSK_BIT       (1<<7)
#define     PP_PHY_CTL4_TMR3MSK_BIT       (1<<6)
#define     PP_PHY_CTL4_TMR2MSK_BIT       (1<<5)
#define     PP_PHY_CTL4_TMR1MSK_BIT       (1<<4)
#define     PP_PHY_CTL4_TMR4CMP_EN_BIT    (1<<3)
#define     PP_PHY_CTL4_TMR3CMP_EN_BIT    (1<<2)
#define     PP_PHY_CTL4_TMR2CMP_EN_BIT    (1<<1)
#define     PP_PHY_CTL4_TMR1CMP_EN_BIT    (1<<0)

//  PP_PHY_STATUS1
#define     PP_PHY_STATUS1_CRCVALID_BIT   (1<<7)
#define     PP_PHY_STATUS1_CCA_BIT        (1<<6)
#define     PP_PHY_STATUS1_SRCADDR_BIT    (1<<5)
#define     PP_PHY_STATUS1_PI_BIT         (1<<4)
#define     PP_PHY_STATUS1_TMR4_IRQ       (1<<3)
#define     PP_PHY_STATUS1_TMR3_IRQ       (1<<2)
#define     PP_PHY_STATUS1_TMR2_IRQ       (1<<1)
#define     PP_PHY_STATUS1_TMR1_IRQ       (1<<0)

//  PP_PHY_STATUS2
#define     PP_PHY_STATUS2_FRPEND_BIT     (1<<7)
#define     PP_PHY_STATUS2_LO1UNLOCK_IRQ  (1<<6)
#define     PP_PHY_STATUS2_FLTR_FAIL_IRQ  (1<<5)
#define     PP_PHY_STATUS2_RX_WMRK_IRQ    (1<<4)
#define     PP_PHY_STATUS2_CCA_IRQ        (1<<3)
#define     PP_PHY_STATUS2_RX_IRQ         (1<<2)
#define     PP_PHY_STATUS2_TX_IRQ         (1<<1)
#define     PP_PHY_STATUS2_SEQ_IRQ        (1<<0)

//  PP_PHY_FRMREVTMR
#define     PP_PHY_FRMREVTMR_TMPRSC_MASK  (7<<5)
#define     PP_PHY_FRMREVTMR_FRMVER_MASK  (3<<0)

//  PP_PHY_RXFRMFLT
#define     PP_PHY_RXFRMFLT_NS_FT_BIT     (1<<4)
#define     PP_PHY_RXFRMFLT_CMD_FT_BIT    (1<<3)
#define     PP_PHY_RXFRMFLT_ACK_FT_BIT    (1<<2)
#define     PP_PHY_RXFRMFLT_DATA_FT_BIT   (1<<1)
#define     PP_PHY_RXFRMFLT_BEACON_FT_BIT (1<<0)

//  PP_PHY_PAPWRCTRL
#define     PP_PHY_PAPWRCTRL_PALCRS_MASK  (3<<6)
#define     PP_PHY_PAPWRCTRL_PALFIN_MASK  (3<<4)
#define     PP_PHY_PAPWRCTRL_PADCRS_MASK  (3<<2)
#define     PP_PHY_PAPWRCTRL_PADFIN_MASK  (3<<0)

//  PP_PHY_SCTL
#define     PP_PHY_SCTL_INDEX_POS          4
#define     PP_PHY_SCTL_INDEX_MASK       (15<<PP_PHY_SCTL_INDEX_POS)
#define     PP_PHY_SCTL_ACK_FP_BIT        (1<<3)
#define     PP_PHY_SCTL_SRC_ADDR_EN_BIT   (1<<2)
#define     PP_PHY_SCTL_INDEX_EN_BIT      (1<<1)
#define     PP_PHY_SCTL_INDEX_DIS_BIT     (1<<0)

/* end of direct access registers bit definitions */

/***********  INDIRECT ACCESS REGISTERS  ***********/

// indirect access registers macros
#define     IoIndirectRead(addr)                    (PP_PHY_INDACCIDX = (addr), PP_PHY_INDACCREG)
#define     IoIndirectWrite(addr, data)              PP_PHY_INDACCIDX = (addr); PP_PHY_INDACCREG = (data)
#define     IoIndirectReadMultiple(addr,  data, n)   PP_PHY_INDACCIDX =((addr) | 0x80);{ uint8_t __macro_indx; for(__macro_indx = 0; __macro_indx<n; __macro_indx++) (data)[__macro_indx] = PP_PHY_INDACCREG;}
#define     IoIndirectWriteMultiple(addr, data, n)   PP_PHY_INDACCIDX = (addr) | 0x80; { uint8_t __macro_indx; for(__macro_indx = 0; __macro_indx<n; __macro_indx++) PP_PHY_INDACCREG = (data)[__macro_indx];}

/* indirect access registers addresses */
// ...
#define     PP_PHY_IAR_RESET              0x24
#define     PP_PHY_IAR_DIG_TESTMODE       0x59
#define     PP_PHY_IAR_FRACN_ACC          0x0A
// ...

/* indirect access registers bit definitions */
//  PP_PHY_IAR_RESET - 0x24
#define     PP_PHY_IAR_BIT_TRCV_RST       (1<<7)
#define     PP_PHY_IAR_BIT_R2RAM_RST      (1<<4)
#define     PP_PHY_IAR_BIT_EVTMR_RST      (1<<3)
#define     PP_PHY_IAR_BIT_TXMOD_RST      (1<<2)
#define     PP_PHY_IAR_BIT_RXMOD_RST      (1<<1)
#define     PP_PHY_IAR_BIT_SEQMGR_RST     (1<<0)

//  PP_PHY_IAR_DIG_TMUX - 0x58
#define     PP_PHY_IAR_BIT_TST_HF_EN      (1<<7)
#define     PP_PHY_IAR_BIT_TMUX_EN        (1<<6)
#define     PP_PHY_IAR_MASK_TMUX_PAGE     (0x3F)

//  PP_PHY_IAR_DIG_TESTMODE - 0x59
#define     PP_PHY_IAR_BIT_BER_EN         (1<<3)
#define     PP_PHY_IAR_BIT_FPGA_EN        (1<<2)
#define     PP_PHY_IAR_BIT_IDEAL_PSM_EN   (1<<1)
#define     PP_PHY_IAR_BIT_MODE_TMUX_EN   (1<<0)

/* end of indirect access registers bit definitions */


// PHY interrupt enable/disable mask
#define     PHY_IRQ_LIB_MASK  PP_PHY_CTL2_TRCV_MSK_BIT

#endif /* _IOCONFIG_MC1323x_H_ */
