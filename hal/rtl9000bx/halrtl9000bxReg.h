#ifndef _HAL_RTL9000BX_REG_H_
#define _HAL_RTL9000BX_REG_H_

//IEEE Standard Register Mapping and Definitions
#define BMCR 0x00 //(Basic Mode Control Register
#define BMSR 0x01
#define PHYID1 0x02
#define PHYID2 0X03
#define PHYCR 0x09
#define PHYSR1 0xa
#define MACR 0x0D
#define MAADR 0x0E
#define PHYCR 0x18   
#define PHYSR2 0x1a
#define PHYSRAD 0x1b
#define PHYSRC 0x1c
#define GINSR 0x1d
#define PAGSR 0x1f

//page 0xa42 reg
#define PAGEA42 0xa42
#define PHYSFR 0x10
#define RTCTCR 0x11
#define GINER 0x12
#define GINMR 0x14
#define SLPCR 0x15
#define LKTCR 0x16
//page a47
#define PAGEA47 0xa47
#define GPSFR 0x15
#define RG_CONFIG 0x17
//page a58
#define PAGEA58 0xa58
#define PCR 0x15
//page a5a
#define PAGEA5A 0xa5a
#define SLPCAP 0x14
//page a60
#define PAGEA60 0xa60
#define PCSSTATE 0x10
#define SLR 0x11
#define PCR 0x14
//page a61
#define PAGEA61 0xa61
#define LKTR 0x10
//reg
#define  RTCTSR 0x8022
#define RTCTLR 0x8023
#define XDR 0xbc52
#define IPGR1 0xc800
#define IPCR2 0xc802
#define IPCR3 0xc810
#define IPCR4 0xc812
#define IEPCR 0xc814
#define SSCCR 0xd012
#define SAER  0xd030
#define RXDVCR 0xd050
#define RGTR 0xd082
#define LEDCR 0xd040
#define SPCR1 0xd096
#define SPCR2 0xd0b6
#define MSE 0xd100
#define WMSE 0xd102
#define PMSE 0xd104
#define SQI 0xd106
#define LTT 0xd110
#define LRT 0xd112
#define RRT 0xd114
#define LFL 0xd120
#define LED_PTP 0xd42a
#define OP_MODE 0xdf10
//PTP
#define PTP_CTL 0xe400
#define PTP_IER 0xe402
#define PTP_INSR 0xe404
#define PTP_CLK_CFG 0xe410
#define PTP_CFG_NS_LO 0xe412
#define PTP_CFG_S_LO 0xe416
#define PTP_CFG_S_MI 0xe418
#define PTP_CFG_S_HI 0xe41a
#define PTP_TAI_CFG 0XE420
#define PTP_TRIG_CFG 0xe422









#endif