/******************************************************************************
* This header file is for the MC1319x EVB port mappings.
*
* (c) Copyright 2006, Freescale, Inc. All rights reserved.
*
* 
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
******************************************************************************/

#ifndef _TARGET_MC1323x_USB_R2_
#define _TARGET_MC1323x_USB_R2_
#include "IoConfig.h"

////////////////////////////////////////
/////// Define LED port mapping ////////
////////////////////////////////////////
  #define LED_PORT            PTAD
 
  #define LED1_PIN            0x01
  #define LED2_PIN            0x10
  #define LED3_PIN            0x00
  #define LED4_PIN            0x00
 
  #define LED_MASK       (LED1_PIN | LED2_PIN)
  
  ////////////////////////////////////////
  /////// Define PORT PINS mapping ///////
  ////////////////////////////////////////
  #define PORT_PINS         PTAD
  #define PORT1_PIN         0x01
  #define PORT2_PIN         0x10
  #define PORT3_PIN         0x01
  #define PORT4_PIN         0x02
  #define PORT_PINS_MASK    (PORT1_PIN | PORT2_PIN | PORT3_PIN | PORT4_PIN)



  #define LED1ON            LED_PORT &= ~LED1_PIN;
  #define LED1OFF           LED_PORT |= LED1_PIN;
  #define LED1TOGGLE        LED_PORT ^= LED1_PIN;

  #define LED2ON            LED_PORT &= ~LED2_PIN;
  #define LED2OFF           LED_PORT |= LED2_PIN;
  #define LED2TOGGLE        LED_PORT ^= LED2_PIN;

  #define LED3ON            ;
  #define LED3OFF           ;
  #define LED3TOGGLE        ;
  
  #define LED4ON            ;
  #define LED4OFF           ;
  #define LED4TOGGLE        ;

  // Turn off LEDs
  #define TURN_OFF_LEDS     LED1OFF;\
                            LED2OFF;

  // Turn on LEDs
  #define TURN_ON_LEDS      LED1ON;\
                            LED2ON;



////////////////////////////////////////
////// Define PCB switch mapping ///////
////////////////////////////////////////

  #define KBI_ENABLE_MATRIX FALSE  
     
  #define SWITCH_PORT        PTBD
  #define mSWITCH1_MASK      0x01
  #define mSWITCH_MASK      (mSWITCH1_MASK)
  #define mSWITCH_PORT_GET  ((SWITCH_PORT & mSWITCH_MASK) ^ mSWITCH_MASK)

  
  //define UART handshake pins
  #define gSCI1RTSPort_c  PTDD
  #define gSCI1RTSPin_c   0x04
  /* Set the pin direction OUTPUT*/
     
  #define gSCI1CTSPort_c  PTBD
  #define gSCI1CTSPin_c   0x80
  /* Set the pin direction INPUT*/
  
////////////////////////////////////////
///// Define HW port/pin mapping ///////
////////////////////////////////////////

  

 // Define HW port mapping (Refer to MCU IO spreadsheet or schematic for details)
  #define gPinPullUpEnable_c     0x01
  #define gPinPullUpDisable_c    0x00
  
  #define gPinDirectionOutput_c  0x01
  #define gPinDirectionInput_c   0x00
  
  #define gPinLevelHigh_c        0x01
  #define gPinLevelLow_c         0x00
  
  #define gPinDriveStrengthHigh  0x01
  #define gPinDriveStrengthLow   0x00
  
  #define gPinSlewRateEnable     0x01
  #define gPinSlewRateDisable    0x00
  
  #define PORT_SETUP(b7, b6, b5, b4, b3, b2, b1, b0)    (uint8_t)( ((b7) << 7) | ((b6) << 6) | ((b5) << 5) | ((b4) << 4) | ((b3) << 3) | ((b2) << 2) | ((b1) << 1) | (b0))
  
  
  
  /* Port A. Add pins for application if needed */  
  #define  mSETUP_PORT_A    PTAD  = PORT_SETUP(\
                                                 gPinLevelLow_c,           /* Port A, Pin 7 */ \
                                                 gPinLevelLow_c,           /* Port A, Pin 6 */ \
                                                 gPinLevelLow_c,           /* Port A, Pin 5 */ \
                                                 gPinLevelLow_c,           /* Port A, Pin 4 -> LED_2 */ \
                                                 gPinLevelLow_c,           /* Port A, Pin 3 */ \
                                                 gPinLevelLow_c,           /* Port A, Pin 2 */ \
                                                 gPinLevelLow_c,           /* Port A, Pin 1 */ \
                                                 gPinLevelLow_c            /* Port A, Pin 0 -> LED_1 */ \
                                               );\
                            PTAPE = PORT_SETUP(\
                                                 gPinPullUpDisable_c,      /* Port A, Pin 7 */ \
                                                 gPinPullUpDisable_c,      /* Port A, Pin 6 */ \
                                                 gPinPullUpDisable_c,      /* Port A, Pin 5 */ \
                                                 gPinPullUpDisable_c,      /* Port A, Pin 4 -> LED_2 */ \
                                                 gPinPullUpDisable_c,      /* Port A, Pin 3 */ \
                                                 gPinPullUpDisable_c,      /* Port A, Pin 2 */ \
                                                 gPinPullUpDisable_c,      /* Port A, Pin 1 */ \
                                                 gPinPullUpDisable_c       /* Port A, Pin 0 -> LED_1 */ \
                                              );\
                            PTADD = PORT_SETUP(\
                                                 gPinDirectionInput_c,     /* Port A, Pin 7 */ \
                                                 gPinDirectionInput_c,     /* Port A, Pin 6 */ \
                                                 gPinDirectionInput_c,     /* Port A, Pin 5 */ \
                                                 gPinDirectionOutput_c,    /* Port A, Pin 4 -> LED_2 */ \
                                                 gPinDirectionInput_c,     /* Port A, Pin 3 */ \
                                                 gPinDirectionInput_c,     /* Port A, Pin 2 */ \
                                                 gPinDirectionInput_c,     /* Port A, Pin 1 */ \
                                                 gPinDirectionOutput_c     /* Port A, Pin 0 -> LED_1 */ \
                                              );\
                            PTADS = PORT_SETUP(\
                                                 gPinDriveStrengthLow,     /* Port A, Pin 7 */ \
                                                 gPinDriveStrengthLow,     /* Port A, Pin 6 */ \
                                                 gPinDriveStrengthLow,     /* Port A, Pin 5 */ \
                                                 gPinDriveStrengthLow,     /* Port A, Pin 4 -> LED_2 */ \
                                                 gPinDriveStrengthLow,     /* Port A, Pin 3 */ \
                                                 gPinDriveStrengthLow,     /* Port A, Pin 2 */ \
                                                 gPinDriveStrengthLow,     /* Port A, Pin 1 */ \
                                                 gPinDriveStrengthLow      /* Port A, Pin 0 -> LED_1 */ \
                                              );                                              

  /* Port B. Add pins for application if needed */  
  #define  mSETUP_PORT_B    PTBD  = PORT_SETUP(\
                                                 gPinLevelLow_c,           /* Port B, Pin 7 -> UART CTS */ \
                                                 gPinLevelLow_c,           /* Port B, Pin 6 */ \
                                                 gPinLevelLow_c,           /* Port B, Pin 5 */ \
                                                 gPinLevelLow_c,           /* Port B, Pin 4 */ \
                                                 gPinLevelLow_c,           /* Port B, Pin 3 */ \
                                                 gPinLevelLow_c,           /* Port B, Pin 2 */ \
                                                 gPinLevelLow_c,           /* Port B, Pin 1 */ \
                                                 gPinLevelLow_c            /* Port B, Pin 0 -> KBI1P0 */ \
                                              );\
                            PTBPE = PORT_SETUP(\
                                                 gPinPullUpEnable_c,       /* Port B, Pin 7 -> UART CTS */ \
                                                 gPinPullUpDisable_c,      /* Port B, Pin 6 */ \
                                                 gPinPullUpDisable_c,      /* Port B, Pin 5 */ \
                                                 gPinPullUpDisable_c,      /* Port B, Pin 4 */ \
                                                 gPinPullUpDisable_c,      /* Port B, Pin 3 */ \
                                                 gPinPullUpDisable_c,      /* Port B, Pin 2 */ \
                                                 gPinPullUpDisable_c,      /* Port B, Pin 1 */ \
                                                 gPinPullUpEnable_c        /* Port B, Pin 0 -> KBI1P0 */ \
                                              );\
                            PTBDD = PORT_SETUP(\
                                                 gPinDirectionInput_c,     /* Port B, Pin 7 -> UART CTS */ \
                                                 gPinDirectionInput_c,     /* Port B, Pin 6 */ \
                                                 gPinDirectionInput_c,     /* Port B, Pin 5 */ \
                                                 gPinDirectionInput_c,     /* Port B, Pin 4 */ \
                                                 gPinDirectionInput_c,     /* Port B, Pin 3 */ \
                                                 gPinDirectionInput_c,     /* Port B, Pin 2 */ \
                                                 gPinDirectionInput_c,     /* Port B, Pin 1 */ \
                                                 gPinDirectionInput_c      /* Port B, Pin 0 -> KBI1P0 */ \
                                              );\
                            PTBDS = PORT_SETUP(\
                                                 gPinDriveStrengthLow,     /* Port B, Pin 7 -> UART CTS */ \
                                                 gPinDriveStrengthLow,     /* Port B, Pin 6 */ \
                                                 gPinDriveStrengthLow,     /* Port B, Pin 5 */ \
                                                 gPinDriveStrengthLow,     /* Port B, Pin 4 */ \
                                                 gPinDriveStrengthLow,     /* Port B, Pin 3 */ \
                                                 gPinDriveStrengthLow,     /* Port B, Pin 2 */ \
                                                 gPinDriveStrengthLow,     /* Port B, Pin 1 */ \
                                                 gPinDriveStrengthLow      /* Port B, Pin 0 */ \
                                              );                                             
                                                                                                                               
  /* Port C. Add pins for application if needed */                                                                                         
  #define  mSETUP_PORT_C    PTCD  = PORT_SETUP(\
                                                 gPinLevelLow_c,           /* Port C, Pin 7 */ \
                                                 gPinLevelLow_c,           /* Port C, Pin 6 */ \
                                                 gPinLevelLow_c,           /* Port C, Pin 5 */ \
                                                 gPinLevelLow_c,           /* Port C, Pin 4 */ \
                                                 gPinLevelLow_c,           /* Port C, Pin 3 */ \
                                                 gPinLevelLow_c,           /* Port C, Pin 2 */ \
                                                 gPinLevelLow_c,           /* Port C, Pin 1 */ \
                                                 gPinLevelLow_c            /* Port C, Pin 0 */ \
                                              );\
                            PTCPE = PORT_SETUP(\
                                                 gPinPullUpDisable_c,      /* Port C, Pin 7 */ \
                                                 gPinPullUpDisable_c,      /* Port C, Pin 6 */ \
                                                 gPinPullUpDisable_c,      /* Port C, Pin 5 */ \
                                                 gPinPullUpDisable_c,      /* Port C, Pin 4 */ \
                                                 gPinPullUpDisable_c,      /* Port C, Pin 3 */ \
                                                 gPinPullUpDisable_c,      /* Port C, Pin 2 */ \
                                                 gPinPullUpDisable_c,      /* Port C, Pin 1 */ \
                                                 gPinPullUpDisable_c       /* Port C, Pin 0 */ \
                                              );\
                            PTCDD = PORT_SETUP(\
                                                 gPinDirectionInput_c,     /* Port C, Pin 7 */ \
                                                 gPinDirectionInput_c,     /* Port C, Pin 6 */ \
                                                 gPinDirectionInput_c,     /* Port C, Pin 5 */ \
                                                 gPinDirectionInput_c,     /* Port C, Pin 4 */ \
                                                 gPinDirectionInput_c,     /* Port C, Pin 3 */ \
                                                 gPinDirectionInput_c,     /* Port C, Pin 2 */ \
                                                 gPinDirectionInput_c,     /* Port C, Pin 1 */ \
                                                 gPinDirectionInput_c      /* Port C, Pin 0 */ \
                                               );\
                            PTCDS = PORT_SETUP(\
                                                 gPinDriveStrengthLow,     /* Port C, Pin 7 */ \
                                                 gPinDriveStrengthLow,     /* Port C, Pin 6 */ \
                                                 gPinDriveStrengthLow,     /* Port C, Pin 5 */ \
                                                 gPinDriveStrengthLow,     /* Port C, Pin 4 */ \
                                                 gPinDriveStrengthLow,     /* Port C, Pin 3 */ \
                                                 gPinDriveStrengthLow,     /* Port C, Pin 2 */ \
                                                 gPinDriveStrengthLow,     /* Port C, Pin 1 */ \
                                                 gPinDriveStrengthLow      /* Port C, Pin 0 */ \
                                              );                                               
                            
  /* Port D. Add pins for application if needed */  
  #define  mSETUP_PORT_D    PTDD  = PORT_SETUP(\
                                                 gPinLevelLow_c,           /* Port D, Pin 7 */ \
                                                 gPinLevelLow_c,           /* Port D, Pin 6 */ \
                                                 gPinLevelLow_c,           /* Port D, Pin 5 */ \
                                                 gPinLevelLow_c,           /* Port D, Pin 4 */ \
                                                 gPinLevelLow_c,           /* Port D, Pin 3 */ \
                                                 gPinLevelLow_c,           /* Port D, Pin 2 */ \
                                                 gPinLevelLow_c,           /* Port D, Pin 1 */ \
                                                 gPinLevelLow_c            /* Port D, Pin 0 */ \
                                              );\
                            PTDPE = PORT_SETUP(\
                                                 gPinPullUpDisable_c,      /* Port D, Pin 7 */ \
                                                 gPinPullUpDisable_c,      /* Port D, Pin 6 */ \
                                                 gPinPullUpDisable_c,      /* Port D, Pin 5 */ \
                                                 gPinPullUpDisable_c,      /* Port D, Pin 4 */ \
                                                 gPinPullUpDisable_c,      /* Port D, Pin 3 */ \
                                                 gPinPullUpDisable_c,      /* Port D, Pin 2 */ \
                                                 gPinPullUpDisable_c,      /* Port D, Pin 1 */ \
                                                 gPinPullUpDisable_c       /* Port D, Pin 0 */ \
                                              );\
                            PTDDD = PORT_SETUP(\
                                                 gPinDirectionInput_c,     /* Port D, Pin 7 */ \
                                                 gPinDirectionInput_c,     /* Port D, Pin 6 */ \
                                                 gPinDirectionInput_c,     /* Port D, Pin 5 */ \
                                                 gPinDirectionInput_c,     /* Port D, Pin 4 */ \
                                                 gPinDirectionInput_c,     /* Port D, Pin 3 */ \
                                                 gPinDirectionOutput_c,    /* Port D, Pin 2-> RTS */ \
                                                 gPinDirectionInput_c,     /* Port D, Pin 1   */ \
                                                 gPinDirectionInput_c      /* Port D, Pin 0   */ \
                                               );\
                            PTDDS = PORT_SETUP(\
                                                 gPinDriveStrengthLow,     /* Port D, Pin 7 */ \
                                                 gPinDriveStrengthLow,     /* Port D, Pin 6 */ \
                                                 gPinDriveStrengthLow,     /* Port D, Pin 5 */ \
                                                 gPinDriveStrengthLow,     /* Port D, Pin 4 */ \
                                                 gPinDriveStrengthLow,     /* Port D, Pin 3 */ \
                                                 gPinDriveStrengthLow,     /* Port D, Pin 2 */ \
                                                 gPinDriveStrengthLow,     /* Port D, Pin 1 */ \
                                                 gPinDriveStrengthLow      /* Port D, Pin 0 */ \
                                              );                                                
 

  /* Port D. Add pins for application if needed */  
  #define  mSETUP_PORT_E 
  
  /* Port D. Add pins for application if needed */  
  #define  mSETUP_PORT_F
  
  /* Port D. Add pins for application if needed */  
  #define  mSETUP_PORT_G

#endif /* _TARGET_MC1323x_USB_R2_ */