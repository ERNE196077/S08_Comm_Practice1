/*
 * MyNewTask.c
 *
 *  Created on: Aug 10, 2016
 *      Author: B42931
 */

#include "MyNewTask.h"
#include "CommUtil.h"      /* Defines the interface of the demo serial terminal interface. */
#include "FunctionLib.h"


/* Global Variable to store our TimerID */
tmrTimerID_t myTimerID;
tsTaskID_t myNewTaskID;
char *strCounter1 = "Counter:1";
char *strCounter2 = "Counter:2";
char *strCounter3 = "Counter:3";
char *strCounter4 = "Counter:4";
char *tmpString;
		

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
				tmpString = strCounter1;
			break;
			case 2:
				Led2On();
				tmpString = strCounter2;
			break;
			case 3:
				Led3On();
				tmpString = strCounter3;
			break;
			case 4:
				Led4On();
				tmpString = strCounter4;
			break;
				
		}
		genericDataTransfer(tmpString, 9);
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

