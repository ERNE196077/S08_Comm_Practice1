/************************************************************************************
* This file holds HCS08 processor macros definitions and checks.
*
* (c) Copyright 2011, Freescale Semiconductor, Inc. All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*************************************************************************************/

#ifndef _HCS08_PREFIX_H_
#define _HCS08_PREFIX_H_

/* indicate endian-ness of this MCU */
#define gBigEndian_c TRUE

#if defined(PROCESSOR_MC13233C) || defined(PROCESSOR_MC13234C) || defined(PROCESSOR_MC13237C) || defined(PROCESSOR_MC13238C)
 #define PROCESSOR_MC1323X
#endif

#if defined(PROCESSOR_MC13233C) && (defined(PROCESSOR_MC13234C) || defined(PROCESSOR_MC13237C) || defined(PROCESSOR_MC13238C))
  #error "Error: Multiple MC1323x Processors defined"
#endif

#if defined(PROCESSOR_MC13234C) && (defined(PROCESSOR_MC13233C) || defined(PROCESSOR_MC13237C) || defined(PROCESSOR_MC13238C))
  #error "Error: Multiple MC1323x Processors defined"
#endif

#if defined(PROCESSOR_MC13237C) && (defined(PROCESSOR_MC13233C) || defined(PROCESSOR_MC13234C) || defined(PROCESSOR_MC13238C))
  #error "Error: Multiple MC1323x Processors defined"
#endif

#if defined(PROCESSOR_MC13238C) && (defined(PROCESSOR_MC13233C) || defined(PROCESSOR_MC13234C) || defined(PROCESSOR_MC13237C))
  #error "Error: Multiple MC1323x Processors defined"
#endif

#if ( defined(PROCESSOR_QE128) && defined(PROCESSOR_MC1323X))
 #error "Error: Configuration not supported"
#endif

#if (defined(PROCESSOR_QE128) || defined(PROCESSOR_MC1323X))
  #ifndef MEMORY_MODEL_BANKED
    #define MEMORY_MODEL_BANKED
  #endif

  #ifndef __BANKED__
    #error "Error: Banked memory model not configured. Please use the -Mb compiler switch."
  #endif
#endif 

#if (!defined(PROCESSOR_QE128) && !defined(PROCESSOR_MC1323X))
  #define PROCESSOR_HCS08
#endif

#endif //_HCS08_PREFIX_H_
