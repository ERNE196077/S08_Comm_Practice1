/************************************************************************************
* This header file is for MyWirelessApp Demo Non Beacon Coordinator application.
*
* (c) Copyright 2008, Freescale, Inc.  All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
************************************************************************************/
#ifndef _MAPP_H_
#define _MAPP_H_

#include "MApp_init.h"
#include "ApplicationConf.h"
#include "802_15_4.h"      /* Include everything related to the 802.15.4 interface*/
#include "CommUtil.h"      /* Defines the interface of the demo serial terminal interface. */
#include "SPI_Interface.h" /* Defines the interface of the SPI driver. */
#include "Display.h"       /* Defines the interface of the LCD driver. */
#include "TMR_Interface.h" /* Defines the interface of the Timer driver. */
#include "TS_Interface.h"  /* Defines the interface of the TaskScheduler. */
#include "PWR_Interface.h" /* Defines the interface of the Low Power Module. */
#include "Led.h"           /* Defines the interface of the Led Module. */
#include "Keyboard.h"      /* Defines the interface of the Keyboard Module. */
#include "NV_Data.h"       /* Defines the interface of the Keyboard Module. */


/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/

/*Set the Coordinator short address */ 
#define mDefaultValueOfShortAddress_c     0xCAFE

/*Set the Coordinator PanID */ 
#define mDefaultValueOfPanId_c            0xBEEF

/* Maximum number of outstanding packets */
#define mDefaultValueOfMaxPendingDataPackets_c 2

/************************************************************************************
*************************************************************************************
* Private type definitions
*************************************************************************************
************************************************************************************/

/* The various states of the applications state machines. */
enum {
  stateInit,
  stateScanEdStart,
  stateScanEdWaitConfirm,
  stateStartCoordinator,
  stateStartCoordinatorWaitConfirm,
  stateListen
};

/* Events that are passed to the application task. 
   Are defined as byte masks to make possible 
   send multiple events to the task */

#define gAppEvtDummyEvent_c            (1 << 0)
#define gAppEvtRxFromComm_c            (1 << 1)
#define gAppEvtMessageFromMLME_c       (1 << 2)
#define gAppEvtMessageFromMCPS_c       (1 << 3)
#define gAppEvtStartCoordinator_c      (1 << 4)

/* Error codes */
enum {
  errorNoError,
  errorWrongConfirm,
  errorNotSuccessful,
  errorNoMessage,
  errorAllocFailed,
  errorInvalidParameter,
  errorNoScanResults
};

typedef struct _EndDevListItem_t_{
  uint8_t ShortAddress[2];
  uint8_t ExtendedAddress[8];
  uint8_t RxOnWhenIdle;       /* 0x1 == On When Idle  ::: 0x0 == Not On When Idle */
  uint8_t DeviceType;         /* 0x1 == FFD  ::: 0x0 == RFD */
}EndDevListItem_t;
/******************************************************************************
*******************************************************************************
* Public Prototypes
*******************************************************************************
******************************************************************************/
extern void MApp_init(void);
extern tsTaskID_t gAppTaskID_c;
static void genericDataTransfer(uint8_t *ptrPDU, uint8_t lengthPDU, EndDevListItem_t dstDevice );
/**********************************************************************************/

#endif /* _MAPP_H_ */
