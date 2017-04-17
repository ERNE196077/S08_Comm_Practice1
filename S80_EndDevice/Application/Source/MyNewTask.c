/*
 * MyNewTask.c
 *
 *  Created on: Aug 10, 2016
 *      Author: B42931
 */

#include "MyNewTask.h"
#include "CommUtil.h"      /* Defines the interface of the demo serial terminal interface. */
#include "802_15_4.h"


/* Global Variable to store our TimerID */
tmrTimerID_t myTimerID;
tsTaskID_t myNewTaskID;

/* NEWCODE: Pointer to Package Button State */
static nwkToMcpsMessage_t *mpBtnPacket;
/* NEWCODE: Pointer to Package Button State */

/* Local variable to store the current state of the LEDs */
static uint8_t ledsState;

/* Timer Callback prototype */
void myTaskTimerCallback(tmrTimerID_t timer);

/* myNewTask main function that will handle the events*/
void MyNewTask(event_t events)
{
	/* Depending on the received event */
	switch(events){
	case gMyNewTaskEvent1_c:
		TMR_StartTimer(myTimerID, 		/* Timer ID allocated in "MyNewTaskInit()", called in MApp_init.c during initialization */
				       gTmrIntervalTimer_c, /* Type of timer: INTERVAL */
				       3000, 				/* Timer's Timeout */
				       myTaskTimerCallback 	/* pointer to myTaskTimerCallback function */
				       );
		TurnOffLeds();	/* Ensure all LEDs are turned off */
		break;
	case gMyNewTaskEvent2_c:	/* Event called from myTaskTimerCallback */
		
		/****NEWCODE: CHANGE LED STATE****/
		ledsState = ++ledsState > 4 ? 1 : ledsState;
		TurnOffLeds();
		switch(ledsState){
			case 1:
				Led1On();
			break;
			case 2:
				Led2On();
			break;
			case 3:
				Led3On();
			break;
			case 4:
				Led4On();
			break;
				
		}
		/****NEWCODE: CHANGE LED STATE****/
		
		break;
	case gMyNewTaskEvent3_c:	/* Event to stop the timer */
		ledsState = 0;
		TurnOffLeds();
		TMR_StopTimer(myTimerID);
		break;
	default:
		break;
	}
}

/* This function is called in MApp_init.c during initialization ( main() )
 * It will INITIALIZE all required components for the task to work and then 
 * call an event for the new Task.*/
void MyNewTaskInit(void)
{
	/* Allocate in memory the timer*/
	myTimerID = TMR_AllocateTimer();
	ledsState = 0;
	/* Create the New Task */
	myNewTaskID = TS_CreateTask(gMyNewTaskPriority_c, MyNewTask);
	/* Send an Event to myNewTask with the first event */
	TS_SendEvent(myNewTaskID, gMyNewTaskEvent1_c); 
}

/* This is the function called by the Timer each time it expires */
static void myTaskTimerCallback(tmrTimerID_t timer)
{
	(void)timer; // this line is just to clear a warning
	TS_SendEvent(myNewTaskID, gMyNewTaskEvent2_c);
}

/* Public function to send an event to stop the timer */
void MyTaskTimer_Stop(void)
{
	TS_SendEvent(myNewTaskID, gMyNewTaskEvent3_c);
}

void MyTaskButtonPress(uint8_t buttonPressed){
	TMR_StopTimer(myTimerID);
	
	switch(buttonPressed){
        case switch1Value:
          CommUtil_Print("Switch 1 Pressed",gAllowToBlock_d);
          ledsState = 4;
          break;
        case switch2Value:
          CommUtil_Print("Switch 2 Pressed",gAllowToBlock_d);
          ledsState = 1;
          break;
        case switch3Value:
          CommUtil_Print("Switch 3 Pressed",gAllowToBlock_d);
          ledsState = 2;
          break;
        case switch4Value:
          CommUtil_Print("Switch 4 Pressed",gAllowToBlock_d);
          ledsState = 3;
        default:
          break;
    }


	TMR_StartTimer(myTimerID, 		/* Timer ID allocated in "MyNewTaskInit()", called in MApp_init.c during initialization */
				       gTmrIntervalTimer_c, /* Type of timer: INTERVAL */
				       3000, 				/* Timer's Timeout */
				       myTaskTimerCallback 	/* pointer to myTaskTimerCallback function */
				       );
	TS_SendEvent(myNewTaskID,gMyNewTaskEvent2_c);
}

/* NEWCODE: Added function to send package over the air with the active button number */

static uint8_t myTaskBtnStaSend(uint8_t btnStat){
  char *mpMsgPDU  = "Counter: ";
  FLib_MemCpy((uint8_t*) mpMsgPDU + 8, &btnStat, 1);

  if( (mcPendingPackets < mDefaultValueOfMaxPendingDataPackets_c) && (mpBtnPacket == NULL) ) 
  {
    /* If the maximum number of pending data buffes is below maximum limit 
       and we do not have a data buffer already then allocate one. */
    mpBtnPacket = MSG_Alloc(gMaxRxTxDataLength_c);
  }

  if(mpBtnPacket != NULL)
  {
    /* get data from serial terminal interface */        
      mpBtnPacket->msgData.dataReq.pMsdu = (uint8_t*)(&(mpBtnPacket->msgData.dataReq.pMsdu)) + sizeof(uint8_t*);
      FLib_MemCpy(mpBtnPacket->msgData.dataReq.pMsdu, (uint8_t*) mpMsgPDU, 9);
      /* Data was available in the serial terminal interface receive buffer. Now create an
         MCPS-Data Request message containing the serial terminal interface data. */
      mpBtnPacket->msgType = gMcpsDataReq_c;
      /* Create the header using coordinator information gained during 
         the scan procedure. Also use the short address we were assigned
         by the coordinator during association. */
      FLib_MemCpy(mpBtnPacket->msgData.dataReq.dstAddr, mCoordInfo.coordAddress, 8);
      FLib_MemCpy(mpBtnPacket->msgData.dataReq.srcAddr, maMyAddress, 8);
      FLib_MemCpy(mpBtnPacket->msgData.dataReq.dstPanId, mCoordInfo.coordPanId, 2);
      FLib_MemCpy(mpBtnPacket->msgData.dataReq.srcPanId, mCoordInfo.coordPanId, 2);
      mpBtnPacket->msgData.dataReq.dstAddrMode = mCoordInfo.coordAddrMode;
      mpBtnPacket->msgData.dataReq.srcAddrMode = mAddrMode;
      mpBtnPacket->msgData.dataReq.msduLength = 9;
      /* Request MAC level acknowledgement of the data packet */
      mpBtnPacket->msgData.dataReq.txOptions = gTxOptsAck_c;
      /* Give the data packet a handle. The handle is
         returned in the MCPS-Data Confirm message. */
      mpBtnPacket->msgData.dataReq.msduHandle = mMsduHandle++;
	#ifdef gMAC2006_d
	      mpBtnPacket->msgData.dataReq.securityLevel = 0;
	#endif //gMAC2006_d      
      
      /* Send the Data Request to the MCPS */
      (void)MSG_Send(NWK_MCPS, mpBtnPacket);
      /* Prepare for another data buffer */
      mpBtnPacket = NULL;
	}
}

/* NEWCODE: Added function to send package over the air with the active button number */