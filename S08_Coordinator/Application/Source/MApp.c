/*****************************************************************************
*  MyWirelessApp Demo Non Beacon Coordinator application.
*
* (c) Copyright 2008, Freescale, Inc. All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
*****************************************************************************/

#include "MApp.h"
#include "Sound.h"
#include "NVM_Interface.h"

/************************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
************************************************************************************/

/* If there are too many pending packets to be send over the air, */
/* receive mMaxKeysToReceive_c chars. */
/* The chars will be send over the air when there are no pending packets*/
#define mMaxKeysToReceive_c 32

/************************************************************************************
*************************************************************************************
* Private prototypes
*************************************************************************************
************************************************************************************/

/* Forward declarations of helper functions */
static void    App_CommRxCallBack(void);
static uint8_t App_StartScan(uint8_t scanType);
static void    App_HandleScanEdConfirm(nwkMessage_t *pMsg);
static uint8_t App_StartCoordinator(void);
static uint8_t App_HandleMlmeInput(nwkMessage_t *pMsg);
static uint8_t App_SendAssociateResponse(nwkMessage_t *pMsgIn);
static void    App_HandleMcpsInput(mcpsToNwkMessage_t *pMsgIn);
static void    App_TransmitCommData(void);
static uint8_t App_WaitMsg(nwkMessage_t *pMsg, uint8_t msgType);
#if (gMC1323xMatrixKBD_d == TRUE)
static void    App_HandleKeys(uint8_t events, uint8_t pressedKey);
#else
static void    App_HandleKeys(key_event_t events);
#endif //gMC1323xMatrixKBD_d


/************************************************************************************
*************************************************************************************
* Private type definitions
*************************************************************************************
************************************************************************************/


/************************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
************************************************************************************/

/* The short address and PAN ID of the coordinator*/
static const uint8_t maShortAddress[2] = { (mDefaultValueOfShortAddress_c & 0xff), (mDefaultValueOfShortAddress_c >> 8)};
static const uint8_t maPanId[2] = { (mDefaultValueOfPanId_c & 0xff), (mDefaultValueOfPanId_c >> 8)};


/* The current logical channel (frequency band) */
static uint8_t mLogicalChannel;

/* Data request packet for sending serial input to the coordinator */
static nwkToMcpsMessage_t *mpPacket;

/* The MSDU handle is a unique data packet identifier */
static uint8_t mMsduHandle;

/* NEWCODE: Pointer to Package Button State */
static nwkToMcpsMessage_t *mpGenericPkg;
/* NEWCODE: Pointer to Package Button State */
static uint8_t maDeviceShortAddress[2];

/* Number of pending data packets */
static uint8_t mcPendingPackets;

/* Application input queues */
static anchor_t mMlmeNwkInputQueue;
static anchor_t mMcpsNwkInputQueue;

static EndDevListItem_t AssociatedDevices[5];
static uint16_t AssocDevCounter;


/************************************************************************************
*************************************************************************************
* Public memory declarations
*************************************************************************************
************************************************************************************/

/* The current state of the applications state machine */
uint8_t gState;

/* This data set contains application variables to be preserved across resets */
NvDataItemDescription_t const gaNvAppDataSet[] = {
  {NULL, 0}       /* Required end-of-table marker. */
};

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

void DeepSleepWakeupStackProc(void);

/*****************************************************************************
* Initialization function for the App Task. This is called during
* initialization and should contain any application specific initialization
* (ie. hardware initialization/setup, table initialization, power up
* notificaiton.
*
* Interface assumptions: None
*
* Return value: None
*
*****************************************************************************/

void MApp_init(void)
{ 
  
  /* The initial application state */
  gState = stateInit;
  /* Reset number of pending packets */
  mcPendingPackets = 0;   
  /* Number of devices associated - Max 5 */
  AssocDevCounter = 0; 

  /* Initialize the MAC 802.15.4 extended address */
  Init_MacExtendedAddress();
  /* register keyboard callback function */
  KBD_Init(App_HandleKeys);
  /* Initialize SPI Module */
  SPI_Init();
  /* initialize LCD Module */
  LCD_Init();
  /* initialize LED Module */
  LED_Init();
  /* Initialize the LPM module */
  PWRLib_Init();
  /* Initialize the serial terminal interface so that we can print out status messages */
  Comm_SetBaud(gUartDefaultBaud_c);
  Comm_SetRxCallBack(App_CommRxCallBack);
  
  /* initialize buzzer (NCB, SRB only) */  
  BuzzerInit();  
  /* Prepare input queues.*/
  MSG_InitQueue(&mMlmeNwkInputQueue); 
  MSG_InitQueue(&mMcpsNwkInputQueue);
  /* Enable MCU interrupts */
  IrqControlLib_EnableAllIrqs();
  /*signal app ready*/  
  Led1Flashing();
  Led2Flashing();
  Led3Flashing();
  Led4Flashing();
    
  CommUtil_Print("\n\rPress any switch on board to start running the application.\n\r", gAllowToBlock_d);  
  LCD_ClearDisplay();
  LCD_WriteString(1,"Press any key");
  LCD_WriteString(2,"to start.");
}

/*****************************************************************************
*Mac Application Task event processor.  This function is called to
* process all events for the task. Events include timers, messages and any
* other user defined events
*
* Interface assumptions: None
*
* Return value: None
*****************************************************************************/
/* The Application Task */
void AppTask(event_t events)
{
  /* Pointer for storing the messages from MLME */
  void *pMsgIn;
  /* Stores the error/success code returned by some functions. */
  uint8_t ret;  
  pMsgIn = NULL;
  
  /* Dequeue the MLME message */
  if (events & gAppEvtMessageFromMLME_c)
  {
    /* Get the message from MLME */
    pMsgIn = MSG_DeQueue(&mMlmeNwkInputQueue);
    
    /* Any time a beacon might arrive. Always handle the beacon frame first */
    if (pMsgIn)
    {               
      ret = App_WaitMsg(pMsgIn, gNwkBeaconNotifyInd_c);
      if(ret == errorNoError)
      {
        /* ALWAYS free the beacon frame contained in the beacon notify indication.*/
        /* ALSO the application can use the beacon payload.*/
        MSG_Free(((nwkMessage_t *)pMsgIn)->msgData.beaconNotifyInd.pBufferRoot);
        CommUtil_Print("Received an MLME-Beacon Notify Indication\n\r", gAllowToBlock_d);
      }
    }
  }
  /* The application state machine */
  switch(gState)
  {
  case stateInit:    
    /* Print a welcome message to the serial terminal interface */
    CommUtil_Print("\n\rMyWirelessApp Demo Non Beacon Coordinator application is initialized and ready.\n\r\n\r", gAllowToBlock_d);            
    /* Goto Energy Detection state. */
    gState = stateScanEdStart;
    TS_SendEvent(gAppTaskID_c, gAppEvtDummyEvent_c);
    break;
    
  case stateScanEdStart:
    /* Start the Energy Detection scan, and goto wait for confirm state. */
    CommUtil_Print("Initiating the Energy Detection Scan\n\r", gAllowToBlock_d);
    /*Print the message on the LCD also*/
    LCD_ClearDisplay();
    LCD_WriteString(1,"Starting Energy");
    LCD_WriteString(2,"Detection Scan");  
    ret = App_StartScan(gScanModeED_c);
    if(ret == errorNoError)
    {
      gState = stateScanEdWaitConfirm;
    }
    break;
    
  case stateScanEdWaitConfirm:
    /* Stay in this state until the MLME Scan confirm message arrives,
       and has been processed. Then goto Start Coordinator state. */
    if (events & gAppEvtMessageFromMLME_c)
    {
      if (pMsgIn)
      {
        ret = App_WaitMsg(pMsgIn, gNwkScanCnf_c);
        if(ret == errorNoError)
        {
          /* Process the ED scan confirm. The logical
             channel is selected by this function. */
          App_HandleScanEdConfirm(pMsgIn);
          /* Go to the Start Coordinator state */
          gState = stateStartCoordinator;
          TS_SendEvent(gAppTaskID_c, gAppEvtStartCoordinator_c);
        }
      }      
    }        
    break;
    

  case stateStartCoordinator:
    if (events & gAppEvtStartCoordinator_c)
    {
      /* Start up as a PAN Coordinator on the selected channel. */
      CommUtil_Print("\n\rStarting as PAN coordinator on channel 0x", gAllowToBlock_d);
      CommUtil_PrintHex(&mLogicalChannel, 1, FALSE);
      CommUtil_Print("\n\r", gAllowToBlock_d);
      /*print a message on the LCD also*/
      LCD_ClearDisplay();
      LCD_WriteString(1,"Starting");
      LCD_WriteString(2,"PAN coordinator");    
    
      ret = App_StartCoordinator();
      if(ret == errorNoError)
      {
        /* If the Start request was sent successfully to
           the MLME, then goto Wait for confirm state. */
        gState = stateStartCoordinatorWaitConfirm;
      }
    }
    break; 

  case stateStartCoordinatorWaitConfirm:
    /* Stay in this state until the Start confirm message
           arrives, and then goto the Listen state. */
    if (events & gAppEvtMessageFromMLME_c)
    {
      if (pMsgIn)
      {        
        ret = App_WaitMsg(pMsgIn, gNwkStartCnf_c);
        if(ret == errorNoError)
        {
          CommUtil_Print("Started the coordinator with PAN ID 0x", gAllowToBlock_d);
          CommUtil_PrintHex((uint8_t *)maPanId, 2, 0);
          CommUtil_Print(", and short address 0x", gAllowToBlock_d);
          CommUtil_PrintHex((uint8_t *)maShortAddress, 2, 0);
          CommUtil_Print(".\n\r\n\rReady to send and receive data over the serial terminal interface.\n\r\n\r", gAllowToBlock_d);
          /*print a message on the LCD also*/
          LCD_ClearDisplay();
          LCD_WriteString(1,"Ready to send");
          LCD_WriteString(2,"and receive data");    
          gState = stateListen;
          TS_SendEvent(gAppTaskID_c, gAppEvtDummyEvent_c);
        }
      }
    }
    break; 
    
  case stateListen:
    /* Stay in this state forever. 
       Transmit the data received on serial terminal interface */
    if (events & gAppEvtMessageFromMLME_c)
    {
      /* Get the message from MLME */
      if (pMsgIn)
      {      
        /* Process it */
        ret = App_HandleMlmeInput(pMsgIn);
        /* Messages from the MLME must always be freed. */
      }
    }

    if (events & gAppEvtRxFromComm_c)
    {      
      /* get byte from serial terminal interface */
      //App_TransmitCommData();       /* Commented as only APP_ACK was requested */
    
    }  
    break;
  }
  
  if (pMsgIn)
  {
    /* Messages must always be freed. */ 
    MSG_Free(pMsgIn);
  }
  
  if (events & gAppEvtMessageFromMCPS_c)
  {      
     /* Get the message from MCPS */
    pMsgIn = MSG_DeQueue(&mMcpsNwkInputQueue);
    if (pMsgIn)
    {
      /* Process it */
      App_HandleMcpsInput(pMsgIn);
      /* Messages from the MCPS must always be freed. */
      MSG_Free(pMsgIn);
    }
  }  
  
  
  /* Check for pending messages in the Queue */ 
  if(MSG_Pending(&mMcpsNwkInputQueue))
    TS_SendEvent(gAppTaskID_c, gAppEvtMessageFromMCPS_c);
  if(MSG_Pending(&mMlmeNwkInputQueue))
    TS_SendEvent(gAppTaskID_c, gAppEvtMessageFromMLME_c);  
}



/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/

/*****************************************************************************
* App_CommRxCallBack
*
* This callback is triggered when a new byte is received over the Serial Interface
*
*****************************************************************************/
static void App_CommRxCallBack(void) 
{
  uint8_t pressedKey;
	if(stateListen == gState){
   // TS_SendEvent(gAppTaskID_c, gAppEvtRxFromComm_c);
  }else{
	 // (void)Comm_GetByteFromRxBuffer(&pressedKey);
  }
}

/******************************************************************************
* The App_StartScan(scanType) function will start the scan process of the
* specified type in the MAC. This is accomplished by allocating a MAC message,
* which is then assigned the desired scan parameters and sent to the MLME
* service access point.
* The function may return either of the following values:
*   errorNoError:          The Scan message was sent successfully.
*   errorInvalidParameter: The MLME service access point rejected the
*                          message due to an invalid parameter.
*   errorAllocFailed:      A message buffer could not be allocated.
*
******************************************************************************/
static uint8_t App_StartScan(uint8_t scanType)
{
  mlmeMessage_t *pMsg;
  mlmeScanReq_t *pScanReq;

  CommUtil_Print("Sending the MLME-Scan Request message to the MAC...", gAllowToBlock_d);

  /* Allocate a message for the MLME (We should check for NULL). */
  pMsg = MSG_AllocType(mlmeMessage_t);
  if(pMsg != NULL)
  {
    /* This is a MLME-SCAN.req command */
    pMsg->msgType = gMlmeScanReq_c;
    /* Create the Scan request message data. */
    pScanReq = &pMsg->msgData.scanReq;
    /* gScanModeED_c, gScanModeActive_c, gScanModePassive_c, or gScanModeOrphan_c */
    pScanReq->scanType = scanType;
    /* ChannelsToScan & 0xFF - LSB, always 0x00 */
    pScanReq->scanChannels[0] = (uint8_t)((mDefaultValueOfChannel_c)     & 0xFF);
    /* ChannelsToScan>>8 & 0xFF  */
    pScanReq->scanChannels[1] = (uint8_t)((mDefaultValueOfChannel_c>>8)  & 0xFF);
    /* ChannelsToScan>>16 & 0xFF  */
    pScanReq->scanChannels[2] = (uint8_t)((mDefaultValueOfChannel_c>>16) & 0xFF);
    /* ChannelsToScan>>24 & 0xFF - MSB */
    pScanReq->scanChannels[3] = (uint8_t)((mDefaultValueOfChannel_c>>24) & 0xFF);
    /* Duration per channel 0-14 (dc). T[sec] = (16*960*((2^dc)+1))/1000000.
       A scan duration of 3 on 16 channels approximately takes 2 secs. */
    pScanReq->scanDuration = 3;
#ifdef gMAC2006_d
    pScanReq->securityLevel = 0;
#endif //gMAC2006_d    
    
    /* Send the Scan request to the MLME. */
    if(MSG_Send(NWK_MLME, pMsg) == gSuccess_c)
    {
      CommUtil_Print("Done\n\r", gAllowToBlock_d);
      return errorNoError;
    }
    else
    {
      CommUtil_Print("Invalid parameter!\n\r", gAllowToBlock_d);
      return errorInvalidParameter;
    }
  }
  else
  {
    /* Allocation of a message buffer failed. */
    CommUtil_Print("Message allocation failed!\n\r", gAllowToBlock_d);
    return errorAllocFailed;
  }
}


/******************************************************************************
* The App_HandleScanEdConfirm(nwkMessage_t *pMsg) function will handle the
* ED scan confirm message received from the MLME when the ED scan has completed.
* The message contains the ED scan result list. This function will search the
* list in order to select the logical channel with the least energy. The
* selected channel is stored in the global variable called 'mLogicalChannel'.
*
******************************************************************************/
static void App_HandleScanEdConfirm(nwkMessage_t *pMsg)
{  
  uint8_t n, minEnergy;
  uint8_t *pEdList;
  uint8_t ChannelMask;

  CommUtil_Print("Received the MLME-Scan Confirm message from the MAC\n\r", gAllowToBlock_d);
    
  /* Get a pointer to the energy detect results */
  pEdList = pMsg->msgData.scanCnf.resList.pEnergyDetectList;
  
  /* Set the minimum energy to a large value */
  minEnergy = 0xFF;

  /* Select default channel */
  mLogicalChannel = 11;
 
  /* Search for the channel with least energy */
  for(n=0; n<16; n++)
  {
    ChannelMask = n + 11;
	if((pEdList[n] < minEnergy)&&((uint8_t)((mDefaultValueOfChannel_c>>ChannelMask) & 0x1)))
    {
      minEnergy = pEdList[n];
      /* Channel numbering is 11 to 26 both inclusive */
      mLogicalChannel = n + 11; 
    }
  }
  
  /* Print out the result of the ED scan */
  CommUtil_Print("ED scan returned the following results:\n\r  [", gAllowToBlock_d);
  CommUtil_PrintHex(pEdList, 16, gPrtHexBigEndian_c | gPrtHexSpaces_c);
  CommUtil_Print("]\n\r\n\r", gAllowToBlock_d);
  
  /* Print out the selected logical channel */
  CommUtil_Print("Based on the ED scan the logical channel 0x", gAllowToBlock_d);
  CommUtil_PrintHex(&mLogicalChannel, 1, 0);
  CommUtil_Print(" was selected\n\r", gAllowToBlock_d);
  
  /* The list of detected energies must be freed. */
  MSG_Free(pEdList);
}

/******************************************************************************
* The App_StartScan(scanType) function will start the scan process of the
* specified type in the MAC. This is accomplished by allocating a MAC message,
* which is then assigned the desired scan parameters and sent to the MLME
* service access point. The MAC PIB attributes "macShortAddress", and 
* "macAssociatePermit" are modified.
*
* The function may return either of the following values:
*   errorNoError:          The Scan message was sent successfully.
*   errorInvalidParameter: The MLME service access point rejected the
*                          message due to an invalid parameter.
*   errorAllocFailed:      A message buffer could not be allocated.
*
******************************************************************************/
static uint8_t App_StartCoordinator(void)
{
  /* Message for the MLME will be allocated and attached to this pointer */
  mlmeMessage_t *pMsg;

  CommUtil_Print("Sending the MLME-Start Request message to the MAC...", gAllowToBlock_d);
  
  /* Allocate a message for the MLME (We should check for NULL). */
  pMsg = MSG_AllocType(mlmeMessage_t);
  if(pMsg != NULL)
  {
    /* Pointer which is used for easy access inside the allocated message */
    mlmeStartReq_t *pStartReq;
    /* Return value from MSG_send - used for avoiding compiler warnings */
    uint8_t ret;
    /* Boolean value that will be written to the MAC PIB */
    uint8_t boolFlag;
    
    /* Set-up MAC PIB attributes. Please note that Set, Get,
       and Reset messages are not freed by the MLME. */
    
    /* We must always set the short address to something
       else than 0xFFFF before starting a PAN. */
    pMsg->msgType = gMlmeSetReq_c;
    pMsg->msgData.setReq.pibAttribute = gMPibShortAddress_c;
    pMsg->msgData.setReq.pibAttributeValue = (uint8_t *)maShortAddress;
    ret = MSG_Send(NWK_MLME, pMsg);
    
    /* We must set the Association Permit flag to TRUE 
       in order to allow devices to associate to us. */
    pMsg->msgType = gMlmeSetReq_c;
    pMsg->msgData.setReq.pibAttribute = gMPibAssociationPermit_c;
    boolFlag = TRUE;
    pMsg->msgData.setReq.pibAttributeValue = &boolFlag;
    ret = MSG_Send(NWK_MLME, pMsg);
    
    /* This is a MLME-START.req command */
    pMsg->msgType = gMlmeStartReq_c;
    
    /* Create the Start request message data. */
    pStartReq = &pMsg->msgData.startReq;
    /* PAN ID - LSB, MSB. The example shows a PAN ID of 0xBEEF. */
    FLib_MemCpy(pStartReq->panId, (void *)maPanId, 2);
    /* Logical Channel - the default of 11 will be overridden */
    pStartReq->logicalChannel = mLogicalChannel;
    /* Beacon Order - 0xF = turn off beacons */
    pStartReq->beaconOrder = 0x0F;  
    /* Superframe Order - 0xF = turn off beacons */
    pStartReq->superFrameOrder = 0x0F;
    /* Be a PAN coordinator */
    pStartReq->panCoordinator = TRUE;
    /* Dont use battery life extension */
    pStartReq->batteryLifeExt = FALSE;
    /* This is not a Realignment command */
    pStartReq->coordRealignment = FALSE;
    /* Dont use security */
#ifndef gMAC2006_d    
    pStartReq->securityEnable = FALSE;
#else
    pStartReq->coordRealignSecurityLevel = 0;
    pStartReq->beaconSecurityLevel = 0;
#endif //gMAC2006_d        
      
    /* Send the Start request to the MLME. */
    if(MSG_Send(NWK_MLME, pMsg) == gSuccess_c)
    {
      CommUtil_Print("Done\n\r", gAllowToBlock_d);
      return errorNoError;
    }
    else
    {
      /* One or more parameters in the Start Request message were invalid. */
      CommUtil_Print("Invalid parameter!\n\r", gAllowToBlock_d);
      return errorInvalidParameter;
    }
  }
  else
  {
    /* Allocation of a message buffer failed. */
    CommUtil_Print("Message allocation failed!\n\r", gAllowToBlock_d);
    return errorAllocFailed;
  }
}

/******************************************************************************
* The App_SendAssociateResponse(nwkMessage_t *pMsgIn) will create the response
* message to an Associate Indication (device sends an Associate Request to its
* MAC. The request is transmitted to the coordinator where it is converted into
* an Associate Indication). This function will extract the devices long address,
* and various other flags from the incoming indication message for building the
* response message.
*
* The function may return either of the following values:
*   errorNoError:          The Associate Response message was sent successfully.
*   errorInvalidParameter: The MLME service access point rejected the
*                          message due to an invalid parameter.
*   errorAllocFailed:      A message buffer could not be allocated.
*
******************************************************************************/
static uint8_t App_SendAssociateResponse(nwkMessage_t *pMsgIn)
{
  mlmeMessage_t *pMsg;
  mlmeAssociateRes_t *pAssocRes;
  uint16_t i;
  uint8_t FoundFlag = 0;
 
  CommUtil_Print("Sending the MLME-Associate Response message to the MAC...", gAllowToBlock_d);
 
  /* Allocate a message for the MLME */
  pMsg = MSG_AllocType(mlmeMessage_t);
  if(pMsg != NULL)
  {
    /* This is a MLME-ASSOCIATE.res command */
    pMsg->msgType = gMlmeAssociateRes_c;
    
    /* Create the Associate response message data. */
    pAssocRes = &pMsg->msgData.associateRes;
    
    /* Assign a short address to the device. In this example we simply
       choose 0x0001. Though, all devices and coordinators in a PAN must have
       different short addresses. However, if a device do not want to use 
       short addresses at all in the PAN, a short address of 0xFFFE must
       be assigned to it. */

      /* Check if ED requester was already registered */

      for (i = 0; i < AssocDevCounter; ++i)
      {
        /* If ED was already registered associate the same address and set the flag */
        if(FLib_MemCmp(AssociatedDevices[i].ExtendedAddress,pMsgIn->msgData.associateInd.deviceAddress,8)){
          FoundFlag++;
          break;
        }
      }

      if(FoundFlag){
        FLib_MemCpy(pAssocRes->assocShortAddress, AssociatedDevices[i].ShortAddress, 2);
        FLib_MemCpy(pAssocRes->deviceAddress, AssociatedDevices[i].ExtendedAddress, 8);

      }else{


        if(pMsgIn->msgData.associateInd.capabilityInfo & gCapInfoAllocAddr_c)
        {
          /* Assign a unique short address less than 0xfffe if the device requests so. */
          uint16_t tmpAddr = AssocDevCounter + 1;
          FLib_MemCpy(pAssocRes->assocShortAddress, &tmpAddr, 2);
        }
        else
        {
          /* A short address of 0xfffe means that the device is granted access to
             the PAN (Associate successful) but that long addressing is used.*/
          pAssocRes->assocShortAddress[0] = 0xFE;
          pAssocRes->assocShortAddress[1] = 0xFF;

        }


        /* Get the 64 bit address of the device requesting association. */
        FLib_MemCpy(pAssocRes->deviceAddress, pMsgIn->msgData.associateInd.deviceAddress, 8);

        /* Save Short and Extended address inside the local array */
        FLib_MemCpy(AssociatedDevices[AssocDevCounter].ShortAddress, pAssocRes->assocShortAddress, 2);
        FLib_MemCpy(AssociatedDevices[AssocDevCounter].ExtendedAddress, pAssocRes->deviceAddress, 8);
        AssociatedDevices[AssocDevCounter].RxOnWhenIdle = pMsgIn->msgData.associateInd.capabilityInfo & gCapInfoRxWhenIdle_c ? 0x1 : 0x0;
        AssociatedDevices[AssocDevCounter].DeviceType = pMsgIn->msgData.associateInd.capabilityInfo & gCapInfoDeviceFfd_c ? 0x1 : 0x0;
        /* Association granted. May also be gPanAtCapacity_c or gPanAccessDenied_c. */

      }

      pAssocRes->status = gSuccess_c;
      /* Do not use security */
      #ifndef gMAC2006_d    
          pAssocRes->securityEnable = FALSE;
      #else
          pAssocRes->securityLevel = 0;
      #endif //gMAC2006_d    
          
      
      /* Send the Associate Response to the MLME. */
      if(MSG_Send(NWK_MLME, pMsg) == gSuccess_c)
      {
        CommUtil_Print("Done\n\r", gAllowToBlock_d);
        
        /* Print association information */
        if(FoundFlag)
          CommUtil_Print("\n\r************************************\n\r\n\rWelcome back old friend\n\rShort Address: 0x", gAllowToBlock_d);
        else{
          CommUtil_Print("\n\r************************************\n\r\n\rI see you are new, welcome!\n\rShort Address: 0x", gAllowToBlock_d);
          i = AssocDevCounter++;
        }
        CommUtil_PrintHex((uint8_t *)AssociatedDevices[i].ShortAddress, 2, 0);
        CommUtil_Print("\n\rLong Address: 0x", gAllowToBlock_d);
        CommUtil_PrintHex((uint8_t *)AssociatedDevices[i].ExtendedAddress, 8, 0);
        if(AssociatedDevices[i].RxOnWhenIdle)
          CommUtil_Print("\n\rRX On When Idle: Yes", gAllowToBlock_d);
        else
          CommUtil_Print("\n\rRX On When Idle: No", gAllowToBlock_d);
        if(AssociatedDevices[i].DeviceType)
          CommUtil_Print("\n\rDevice Type: FFD", gAllowToBlock_d);
        else
          CommUtil_Print("\n\rDevice Type: RFD", gAllowToBlock_d);
        CommUtil_Print("\n\r\n\r************************************\n\r", gAllowToBlock_d);
        
        return errorNoError;
      }
      else
      {
        /* One or more parameters in the message were invalid. */
        CommUtil_Print("Invalid parameter!\n\r", gAllowToBlock_d);
        return errorInvalidParameter;
      }
    
  }
  else
  {
    /* Allocation of a message buffer failed. */
    CommUtil_Print("Message allocation failed!\n\r", gAllowToBlock_d);
    return errorAllocFailed;
  }
}

/******************************************************************************
* The App_HandleMlmeInput(nwkMessage_t *pMsg) function will handle various
* messages from the MLME, e.g. (Dis)Associate Indication.
*
* The function may return either of the following values:
*   errorNoError:   The message was processed.
*   errorNoMessage: The message pointer is NULL.
******************************************************************************/
static uint8_t App_HandleMlmeInput(nwkMessage_t *pMsg)
{
  if(pMsg == NULL)
    return errorNoMessage;
  
  /* Handle the incoming message. The type determines the sort of processing.*/
  switch(pMsg->msgType) {
  case gNwkAssociateInd_c:
    CommUtil_Print("Received an MLME-Associate Indication from the MAC\n\r", gAllowToBlock_d);
    /* A device sent us an Associate Request. We must send back a response.  */
    return App_SendAssociateResponse(pMsg);
    break;
    
  case gNwkCommStatusInd_c:
    /* Sent by the MLME after the Association Response has been transmitted. */
    CommUtil_Print("Received an MLME-Comm-Status Indication from the MAC\n\r", gAllowToBlock_d);
    break;
  }
  return errorNoError;
}

/******************************************************************************
* The App_HandleMcpsInput(mcpsToNwkMessage_t *pMsgIn) function will handle 
* messages from the MCPS, e.g. Data Confirm, and Data Indication.
*
******************************************************************************/
static void App_HandleMcpsInput(mcpsToNwkMessage_t *pMsgIn)
{
	uint8_t i;
	uint8_t *btnValue;
  switch(pMsgIn->msgType)
  {
    /* The MCPS-Data confirm is sent by the MAC to the network 
       or application layer when data has been sent. */
  case gMcpsDataCnf_c:
    if(mcPendingPackets)
      mcPendingPackets--;
    break;
  
  case gMcpsDataInd_c:
    /* The MCPS-Data indication is sent by the MAC to the network 
       or application layer when data has been received. We simply 
       copy the received data to the serial terminal interface. */



  /* NEWCODE: Check for Button Data */
    if(FLib_MemCmp(pMsgIn->msgData.dataInd.pMsdu,"Counter:",8)){
    	btnValue = (uint8_t *)pMsgIn->msgData.dataInd.pMsdu;
    	btnValue += 8;
      TurnOffLeds();
      switch(*btnValue){
        case '1':
         Led1On();
        break;
        case '2':
         Led2On();
        break;
        case '3':
         Led3On();
        break;
        case '4':
         Led4On();
        break;
      }

      CommUtil_Print("Source Addres : 0x", gAllowToBlock_d);
      CommUtil_PrintHex((uint8_t *)pMsgIn->msgData.dataInd.srcAddr, 2, 0);
      CommUtil_Print("\r\n", gAllowToBlock_d);
      CommUtil_Print("Link Quality : 0x", gAllowToBlock_d);
      CommUtil_PrintHex((uint8_t *)pMsgIn->msgData.dataInd.mpduLinkQuality, 1, 0);          
      CommUtil_Print("\r\n", gAllowToBlock_d);
      CommUtil_Print("Data : ", gAllowToBlock_d);
      CommUtil_Tx(pMsgIn->msgData.dataInd.pMsdu, pMsgIn->msgData.dataInd.msduLength);
      CommUtil_Print("\r\n", gAllowToBlock_d);
      
      for (i = 0; i < AssocDevCounter; ++i)
      {
        if(FLib_MemCmp(AssociatedDevices[i].ShortAddress,pMsgIn->msgData.dataInd.srcAddr,2)){
          genericDataTransfer("APP_ACK", 7,AssociatedDevices[i] );
          CommUtil_Print("APP_ACK Sent to Device\r\n", gAllowToBlock_d);
          CommUtil_Print("******************************\r\n", gAllowToBlock_d);
        }
      }
      

    }
    /* NEWCODE: Check for Button Data */
    break;
  }
}

/******************************************************************************
* The App_WaitMsg(nwkMessage_t *pMsg, uint8_t msgType) function does not, as
* the name implies, wait for a message, thus blocking the execution of the
* state machine. Instead the function analyzes the supplied message to determine
* whether or not the message is of the expected type.
* The function may return either of the following values:
*   errorNoError: The message was of the expected type.
*   errorNoMessage: The message pointer is NULL.
*   errorWrongConfirm: The message is not of the expected type.
*
******************************************************************************/
static uint8_t App_WaitMsg(nwkMessage_t *pMsg, uint8_t msgType)
{
  /* Do we have a message? If not, the exit with error code */
  if(pMsg == NULL)
    return errorNoMessage;

  /* Is it the expected message type? If not then exit with error code */
  if(pMsg->msgType != msgType)
    return errorWrongConfirm;

  /* Found the expected message. Return with success code */
  return errorNoError;
}

/******************************************************************************
* The App_TransmitCommData() function will perform (single/multi buffered)
* data transmissions of data received by the serial terminal interface. Data could also come from
* other sources such as sensors etc. This is completely determined by the
* application. The constant mDefaultValueOfMaxPendingDataPackets_c determine the maximum
* number of packets pending for transmission in the MAC. A global variable
* is incremented each time a data packet is sent to the MCPS, and decremented
* when the corresponding MCPS-Data Confirm message is received. If the counter
* reaches the defined maximum no more data buffers are allocated until the
* counter is decreased below the maximum number of pending packets.
*
* The function uses the device information, that was stored when the device,
* associated to us, for building an MCPS-Data Request message. The message
* is sent to the MCPS service access point in the MAC.
******************************************************************************/
static void App_TransmitCommData(void)
{   
  static uint8_t keysBuffer[mMaxKeysToReceive_c];
  static uint8_t keysReceived = 0;
  static char *appAck = "APP_ACK";
  uint16_t i = 0;
  /* get data from serial terminal interface */
  if( keysReceived < mMaxKeysToReceive_c) 
  { 
    if(Comm_GetByteFromRxBuffer(&keysBuffer[keysReceived])) 
    {
    keysReceived++;
    }
  }
  /* Use multi buffering for increased TX performance. It does not really
     have any effect at a UART baud rate of 19200bps but serves as an
     example of how the throughput may be improved in a real-world 
     application where the data rate is of concern. */
  if( (mcPendingPackets < mDefaultValueOfMaxPendingDataPackets_c) && (mpPacket == NULL) ) 
  {
    /* If the maximum number of pending data buffes is below maximum limit 
       and we do not have a data buffer already then allocate one. */
    mpPacket = MSG_Alloc(gMaxRxTxDataLength_c);
  }

  if(mpPacket != NULL)
  {


      for (i = 0; i < AssocDevCounter; ++i)
      {

        if(!AssociatedDevices[i].DeviceType){
          genericDataTransfer((uint8_t *)appAck, 7,AssociatedDevices[i] );
        }


              /* get data from serial terminal interface */        
        mpPacket->msgData.dataReq.pMsdu = (uint8_t*)(&(mpPacket->msgData.dataReq.pMsdu)) + sizeof(uint8_t*);
        FLib_MemCpy(mpPacket->msgData.dataReq.pMsdu, (uint8_t*) keysBuffer, keysReceived);

        /* Data was available in the serial terminal interface receive buffer. Now create an
           MCPS-Data Request message containing the serial terminal interface data. */
        mpPacket->msgType = gMcpsDataReq_c;
        /* Create the header using device information stored when creating 
           the association response. In this simple example the use of short
           addresses is hardcoded. In a real world application we must be
           flexible, and use the address mode required by the given situation. */
        FLib_MemCpy(mpPacket->msgData.dataReq.dstAddr, AssociatedDevices[i].ShortAddress, 2);
        FLib_MemCpy(mpPacket->msgData.dataReq.srcAddr, (void *)maShortAddress, 2);
        FLib_MemCpy(mpPacket->msgData.dataReq.dstPanId, (void *)maPanId, 2);
        FLib_MemCpy(mpPacket->msgData.dataReq.srcPanId, (void *)maPanId, 2);
        mpPacket->msgData.dataReq.dstAddrMode = gAddrModeShort_c;
        mpPacket->msgData.dataReq.srcAddrMode = gAddrModeShort_c;
        mpPacket->msgData.dataReq.msduLength = keysReceived;
        

        /* Transfer Options in case of FFD / RFD */
        if(AssociatedDevices[i].DeviceType)
          /* Request MAC level acknowledgement of the data packet */
          mpGenericPkg->msgData.dataReq.txOptions = gTxOptsAck_c;         /* Direct Transfer for FFD Device */
        else
          /* Request MAC level acknowledgement of the data packet and transmit Indirectly */
          mpGenericPkg->msgData.dataReq.txOptions = gTxOptsAck_c | gTxOptsIndirect_c;     /* Indirect Transfer for RFD device */

        /* Give the data packet a handle. The handle is
           returned in the MCPS-Data Confirm message. */
        mpPacket->msgData.dataReq.msduHandle = mMsduHandle++;
        #ifdef gMAC2006_d
              mpPacket->msgData.dataReq.securityLevel = 0;
        #endif //gMAC2006_d      
        
        /* Send the Data Request to the MCPS */
        (void)MSG_Send(NWK_MCPS, mpPacket);
        /* Prepare for another data buffer */
        mpPacket = NULL;
        mcPendingPackets++;
        /* Receive another pressed keys */
        keysReceived = 0;


      }


  }
  
  /* If the keysBuffer[] wasn't send over the air because there are too many pending packets, */
  /* try to send it later   */
  if (keysReceived)
  {
  //TS_SendEvent(gAppTaskID_c, gAppEvtRxFromComm_c);
  }
}

/*****************************************************************************
* Function to handle a generic key press. Called for all keys.
*****************************************************************************/
static void App_HandleGenericKey(void)
{
  if(gState == stateInit)
  {
    StopLed1Flashing();
    StopLed2Flashing();
    StopLed3Flashing();
    StopLed4Flashing();
    Led1Off();
    Led2Off();
    Led3Off();
    Led4Off();
    LCD_ClearDisplay();
    LCD_WriteString(1,"Application");
    LCD_WriteString(2,"    started");     
    TS_SendEvent(gAppTaskID_c, gAppEvtDummyEvent_c);       
  }
}

/*****************************************************************************
* Handles all key events for this device.
* Interface assumptions: None
* Return value: None
*****************************************************************************/
#if (gMC1323xMatrixKBD_d == TRUE)
static void App_HandleKeys(uint8_t events, uint8_t pressedKey)   
{
 (void)events;
 (void)pressedKey;
 App_HandleGenericKey();
}
#else
static void App_HandleKeys(key_event_t events)
{
  switch ( events ) 
    { 
      case gKBD_EventSW1_c:
      case gKBD_EventSW2_c:
      case gKBD_EventSW3_c:
      case gKBD_EventSW4_c:
      case gKBD_EventLongSW1_c:
      case gKBD_EventLongSW2_c:
      case gKBD_EventLongSW3_c:
      case gKBD_EventLongSW4_c:
       App_HandleGenericKey();
       break;  
    }    
}                                                      
#endif //gMC1323xMatrixKBD_d
/*****************************************************************************
* The DeepSleepWakeupStackProc(void) function is called each time the 
* application exits the DeepSleep mode .
* 
* Return value:
*     None
*****************************************************************************/
void DeepSleepWakeupStackProc(void){
  return;
}

/******************************************************************************
* The following functions are called by the MAC to put messages into the
* Application's queue. They need to be defined even if they are not used
* in order to avoid linker errors.
******************************************************************************/

uint8_t MLME_NWK_SapHandler(nwkMessage_t * pMsg)
{
  /* Put the incoming MLME message in the applications input queue. */
  MSG_Queue(&mMlmeNwkInputQueue, pMsg);
  TS_SendEvent(gAppTaskID_c, gAppEvtMessageFromMLME_c);
  return gSuccess_c;
}

uint8_t MCPS_NWK_SapHandler(mcpsToNwkMessage_t *pMsg)
{
  /* Put the incoming MCPS message in the applications input queue. */
  MSG_Queue(&mMcpsNwkInputQueue, pMsg);
  TS_SendEvent(gAppTaskID_c, gAppEvtMessageFromMCPS_c);
  return gSuccess_c;
}

uint8_t ASP_APP_SapHandler(aspToAppMsg_t *pMsg)
{
  /* If the message is not handled anywhere it must be freed. */
  MSG_Free(pMsg);
  return gSuccess_c;
}

/******************************************************************************/

/* NEWCODE: Added function to send package over the air with the active button number */

static void genericDataTransfer(uint8_t *ptrPDU, uint8_t lengthPDU, EndDevListItem_t dstDevice ){

  if( (mcPendingPackets < mDefaultValueOfMaxPendingDataPackets_c) && (mpGenericPkg == NULL) ) 
  {
    /* If the maximum number of pending data buffes is below maximum limit 
       and we do not have a data buffer already then allocate one. */
    mpGenericPkg = MSG_Alloc(gMaxRxTxDataLength_c);
  }

  if(mpGenericPkg != NULL)
  {
    /* get data from serial terminal interface */        
      mpGenericPkg->msgData.dataReq.pMsdu = (uint8_t*)(&(mpGenericPkg->msgData.dataReq.pMsdu)) + sizeof(uint8_t*);
      FLib_MemCpy(mpGenericPkg->msgData.dataReq.pMsdu, (uint8_t*) ptrPDU, 9);
      /* Data was available in the serial terminal interface receive buffer. Now create an
         MCPS-Data Request message containing the serial terminal interface data. */
      mpGenericPkg->msgType = gMcpsDataReq_c;
      /* Create the header using coordinator information gained during 
         the scan procedure. Also use the short address we were assigned
         by the coordinator during association. */
      FLib_MemCpy(mpGenericPkg->msgData.dataReq.dstAddr, dstDevice.ShortAddress, 2);
      FLib_MemCpy(mpGenericPkg->msgData.dataReq.srcAddr, (void *)maShortAddress, 2);
      FLib_MemCpy(mpGenericPkg->msgData.dataReq.dstPanId, (void *)maPanId, 2);
      FLib_MemCpy(mpGenericPkg->msgData.dataReq.srcPanId, (void *)maPanId, 2);
      mpGenericPkg->msgData.dataReq.dstAddrMode = gAddrModeShort_c;
      mpGenericPkg->msgData.dataReq.srcAddrMode = gAddrModeShort_c;
      mpGenericPkg->msgData.dataReq.msduLength = lengthPDU;

      /* Transfer Options in case of FFD / RFD */
      //if(dstDevice.DeviceType)
        /* Request MAC level acknowledgement of the data packet */
      //  mpGenericPkg->msgData.dataReq.txOptions = gTxOptsAck_c;         /* Direct Transfer for FFD Device */
     // else
        /* Request MAC level acknowledgement of the data packet and transmit Indirectly */
        mpGenericPkg->msgData.dataReq.txOptions = gTxOptsAck_c | gTxOptsIndirect_c;     /* Indirect Transfer for RFD device */

      /* Give the data packet a handle. The handle is
         returned in the MCPS-Data Confirm message. */
      mpGenericPkg->msgData.dataReq.msduHandle = mMsduHandle++;
  #ifdef gMAC2006_d
        mpGenericPkg->msgData.dataReq.securityLevel = 0;
  #endif //gMAC2006_d      
      
      /* Send the Data Request to the MCPS */
      (void)MSG_Send(NWK_MCPS, mpGenericPkg);
      mcPendingPackets++;
      /* Prepare for another data buffer */
      mpGenericPkg = NULL;
  }
}

/* NEWCODE: Added function to send package over the air with the active button number */
