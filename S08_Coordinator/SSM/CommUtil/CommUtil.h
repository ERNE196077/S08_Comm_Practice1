/************************************************************************************
* Includes the Comm Utils - .
*
* (c) Copyright 2011, Freescale, Inc. All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
************************************************************************************/
#ifndef _COMM_UTIL_H_
#define _COMM_UTIL_H_


#ifdef PROCESSOR_MC13238C
  #include "CDC_Interface.h"
#else
  #include "Uart_Interface.h"
#endif


#define gNoComm_c    0 
#define gCommUart_c  1
#define gCommUsb_c   2

#ifndef gComm_Type_d
  #ifdef PROCESSOR_MC13238C
    #define gComm_Type_d  gCommUsb_c
  #else
    #define gComm_Type_d  gCommUart_c
  #endif
#endif


#if (gComm_Type_d == gCommUart_c)

  #define Comm_Transmit              UartX_Transmit
  #define Comm_IsTxActive            UartX_IsTxActive
  #define Comm_SetRxCallBack         UartX_SetRxCallBack
  #define Comm_GetByteFromRxBuffer   UartX_GetByteFromRxBuffer    
  #define Comm_TxCompleteFlag        UartX_TxCompleteFlag
  #define Comm_RxBufferByteCount     UartX_RxBufferByteCount
  #define Comm_SetBaud               UartX_SetBaud

#elif (gComm_Type_d == gCommUsb_c)

  #define Comm_Transmit              CDC_Transmit
  #define Comm_IsTxActive            CDC_IsTxActive
  #define Comm_SetRxCallBack         CDC_SetRxCallBack
  #define Comm_GetByteFromRxBuffer   CDC_GetByteFromRxBuffer                                
  #define Comm_TxCompleteFlag        gCDC_TxCompleteFlag
  #define Comm_RxBufferByteCount     gCDCRxBufferByteCount
  #define Comm_SetBaud(baud)

#else

  #define Comm_Transmit(a,b,c)         FALSE       
  #define Comm_IsTxActive()            FALSE
  #define Comm_SetRxCallBack             
  #define Comm_GetByteFromRxBuffer(a)  FALSE                         
  #define Comm_TxCompleteFlag        
  #define Comm_RxBufferByteCount     
  #define Comm_SetBaud(baud)
  
#endif
    
/************************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Private prototypes
*************************************************************************************/
/************************************************************************************
*************************************************************************************
* Private type definitions
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/

/* If you have to print a hex number you can choose between 
   BigEndian=1/LittleEndian=0, newline, commas or spaces (between bytes) */
enum {
  gPrtHexBigEndian_c = 1<<0,
  gPrtHexNewLine_c   = 1<<1,
  gPrtHexCommas_c    = 1<<2,
  gPrtHexSpaces_c    = 1<<3
};

typedef enum {
	gNoBlock_d  = 0,
	gAllowToBlock_d
}commUtilBlock_t;

/************************************************************************************
*************************************************************************************
* Public memory declarations
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/
/************************************************************************************
* Function that prints out a string on the communication interface COMM.  
* String needs to be 0-terminated.
* If the Circular Tx List is full and the user called this function the
* data will be lost. Try to see if a transmission is pending before 
* sending  data or do not sent more than tx buffer length bytes using 
* consecutive CommUtil_Print.

* Interface assumptions:
*   None
*   
* Return value:
*   None
* 
************************************************************************************/

void CommUtil_Print(uint8_t* pString, commUtilBlock_t allowToBlock);

/************************************************************************************
* Function that prints out one byte on the communication interface as a hexdecimal string.
* E.g. the byte 0x5E is printed as the string "5E". It is up to the user to add
* decorations before or after the string is printed. 
* Example:
*   CommUtil_Print("Number is: 0x");
*   CommUtil_PrintHex(0x5E,1,0);
*   CommUtil_Print("\r\n");
*   This will result in "Number is 0x5E" being printed over the Comm with line shift.
*   
* Interface assumptions:
*   None
*   
* Return value:
*   None
* 
************************************************************************************/

void CommUtil_PrintHex(uint8_t *hex, uint8_t len, uint8_t flags);

/************************************************************************************
* Function that sends data to the communication from the supplied buffer. 
* If the Circular Tx List is full and the user called this function the
* data will be lost. Try to see if a transmission is pending before 
* sending  data or do not sent more than tx buffer length bytes using 
* consecutive CommUtil_Print.
* 
* Interface assumptions:
*   None
*   
* Return value:
*   Number of bytes copied to the buffer
* 
************************************************************************************/

void CommUtil_Tx(uint8_t * pData, uint8_t length);

#endif /* _COMM_UTIL_H_ */


