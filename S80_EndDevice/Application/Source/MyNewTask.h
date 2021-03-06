/*
 * MyNewTask.h
 *
 *  Created on: Aug 10, 2016
 *      Author: B42931
 */

#ifndef MYNEWTASK_H_
#define MYNEWTASK_H_

#include "TMR_Interface.h" /* Defines the interface of the Timer driver. */
#include "TS_Interface.h"  /* Defines the interface of the TaskScheduler. */
#include "Led.h"

/* Define the available Task's Events */
#define gMyNewTaskEvent1_c        (1 << 0)
#define gMyNewTaskEvent2_c        (1 << 1)
#define gMyNewTaskEvent3_c        (1 << 2)
#define gMyNewTaskCount1       (1 << 3)
#define gMyNewTaskCount2        (1 << 4)
#define gMyNewTaskCount3        (1 << 5)
#define gMyNewTaskCount4        (1 << 6)

/* New task priority. */
#define gMyNewTaskPriority_c                0x81

/****NEWCODE: ADDED DEFINES FOR BUTTON PRESS****/
#define switch1Value  0x1
#define switch2Value  0x2
#define switch3Value  0x3
#define switch4Value  0x4
/****NEWCODE: ADDED DEFINES FOR BUTTON PRESS****/


/* Prototypes: If not static, can be used outside of this file*/
void MyNewTask(event_t);
void MyNewTaskInit(void);
void MyTaskTimer_Stop(void);
void MyTaskButtonPress(uint8_t buttonPressed);

static void myTaskTimerCallback(tmrTimerID_t);
extern void genericDataTransfer(uint8_t *ptrPDU, uint8_t lengthPDU);


#endif /* MYNEWTASK_H_ */
