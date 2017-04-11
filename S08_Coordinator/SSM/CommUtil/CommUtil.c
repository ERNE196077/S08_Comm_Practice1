/************************************************************************************
* Includes the Comm Utils.
*
* (c) Copyright 2011, Freescale, Inc. All rights reserved.
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
*
************************************************************************************/
#include "EmbeddedTypes.h"
#include "CommUtil.h"

/******************************************************************************/
/******************************************************************************/

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
* Public memory declarations
*************************************************************************************
************************************************************************************/
 
/************************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

#if (gComm_Type_d != gNoComm_c)

/************************************************************************************/

void CommUtil_TxCallback(unsigned char const *pBuf)
{
  (void) pBuf;
}

/************************************************************************************/

void CommUtil_Tx(uint8_t * pData, uint8_t length)
{
  /* wait until module can insert message into Comm buffers */
  while(!Comm_Transmit((unsigned char const*)pData,(index_t)length,NULL));
  /* wait until tx complete */
  while (Comm_IsTxActive());      
}

/************************************************************************************/

void CommUtil_Print(uint8_t* pString, commUtilBlock_t allowToBlock)
{
  uint16_t i = 0;
  uint8_t*  pTmpString = pString ;
  
  while (*pTmpString != '\0') 
  {
    pTmpString++;
    i++;
  } 
  if(allowToBlock)
  {
    /* wait until module can insert message into Comm buffers and until tx completes */  
	CommUtil_Tx(pString,(uint8_t)i);
  }
  else
  {
    (void)Comm_Transmit((unsigned char const*)pString,(index_t)i,NULL);
  }
}

/************************************************************************************/

/* Trasform from hex to ascii */
static uint8_t HexToAscii(uint8_t hex)
{
  hex &= 0x0F;
  return hex + ((hex <= 9) ? '0' : ('A'-10));
}

/************************************************************************************/

void CommUtil_PrintHex(uint8_t *hex, uint8_t len, uint8_t flags)
{
  uint8_t i=0; 
  uint8_t hexString[6]; /* 2 bytes  - hexadecimal display 
                           1 byte   - separator ( comma)
						   1 byte   - separator ( space)
                           2 bytes  - new line (\n\r)  */
  
  if(! (flags & gPrtHexBigEndian_c))
   {
    hex = hex + (len-1);
   }
   
  while(len)
  {
    /* wait until previous hex print transmission is over */  
    while (Comm_IsTxActive());  
      
    /* start preparing the print of a new byte */
    i=0;
    hexString[i++] = HexToAscii((*hex)>>4);
    hexString[i++] = HexToAscii( *hex);

    if(flags & gPrtHexCommas_c)
     {
      hexString[i++] = ',';
     }
    if(flags & gPrtHexSpaces_c) 
     { 
      hexString[i++] = ' ';
     }
    hex = hex + (flags & gPrtHexBigEndian_c ? 1 : -1);
    len--;
    
    if((len == 0) && (flags & gPrtHexNewLine_c))
     {
      hexString[i++] = '\n';
      hexString[i++] = '\r';
     }
     /* transmit formatted byte */      
    (void)Comm_Transmit((unsigned char const*)hexString,(index_t)i,NULL);   
  }
  /* wait to complete the last transmission */
  while (Comm_IsTxActive());   
}

/************************************************************************************/

#else /* (gComm_Type_d != gNoComm_c) */

/************************************************************************************/
/* Create  dummy functions  */
/************************************************************************************/

void CommUtil_Print(char * pString, commUtilBlock_t allowToBlock)
{
  /* Avoid compiler warning */
  (void)pString;
  (void)allowToBlock;
}

/************************************************************************************/

void CommUtil_PrintHex(uint8_t *hex, uint8_t len, uint8_t flags)
{
  /* Avoid compiler warning */
  (void)hex;
  (void)len;
  (void)flags;
}

/************************************************************************************/

void CommUtil_Tx(uint8_t * pData, uint8_t length){
  /* Avoid compiler warning */
  (void)pData;
  (void)length;
}

/************************************************************************************/
#endif  /* (gComm_Type_d != gNoComm_c) */
