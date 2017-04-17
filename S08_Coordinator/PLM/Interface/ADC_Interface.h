/*****************************************************************************
* Analog to digital converter module for MC13227C processor
*
* c) Copyright 2012, Freescale, Inc. All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*
*****************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "EmbeddedTypes.h"
#include "IrqControlLib.h"
#include "PortConfig.h"
#include "ADC.h"

/******************************************************************************
 ******************************************************************************
 * Public macros
 ******************************************************************************
 ******************************************************************************/

/*
 * Name: gADC_Enabled_d 
 * Description: enables/disables the ADC module functionality 
 *              and code generation
 */
 #ifndef gADC_Enabled_d
   #if defined (PROCESSOR_MC13237C) || defined (PROCESSOR_QE128)
     #define gADC_Enabled_d        FALSE
   #else
     #define gADC_Enabled_d        FALSE
   #endif
 #endif

/*
 * Name: gAdcTaskPriority_c 
 * Description: ADC task priority within Task Scheduler
 */
#ifndef gAdcTaskPriority_c
#define gAdcTaskPriority_c          0x07
#endif

 /* ADC sampling channel */
#ifndef gADCSamplingChannel_c 
#define gADCSamplingChannel_c       0x03
#endif

/* ADC internal bandgap reference voltage channel */
#ifndef gADCBandgapRefVoltageChannel_c
#define gADCBandgapRefVoltageChannel_c gADC_AD27_c
#endif

/* ADC internal temperature sensor channel */
#ifndef gADCTemperatureSensorChannel_c
#define gADCTemperatureSensorChannel_c gADC_AD26_c
#endif

/* ADC VRef High (mV) */
#ifndef gADC_VRef_H_c
#define gADC_VRef_H_c    3100
#endif

/* ADC VRef Low (mV) */
#ifndef gADC_VRef_L_c
#define gADC_VRef_L_c    0
#endif

/* Internal sensor voltage (expressed in microvolts) at T=25 degrees and Vdd = 3V */
#ifndef gADC_VTemp25_c
#define gADC_VTemp25_c    0x000AB310UL
#endif

/******************************************************************************
 ******************************************************************************
 * Public type definitions
 ******************************************************************************
 ******************************************************************************/
/*
 * Name: ADC_TemperatureSensor_t
 * Description:	Type definition used to store the internal sensor temperature
 */
typedef struct ADC_TemperatureSensor_tag
{
	uint16_t intValue; /* integer value */
	uint16_t decValue; /* decimal value */
	bool_t positiveSign; /* if TRUE the temperature is greater than 0 Celsius */
} ADC_TemperatureSensor_t;

/*
 * Name: pfConversionCompleteCallBack
 * Description:	Function pointer type definition used to store
 *              the user callback that will be called when a
 *              conversion completes 
 */
typedef void (*pfConversionCompleteCallBack)(void);

/*
 * Name: pfIntBandgapRefCallback
 * Description:	Function pointer type definition used to store
 *              the user callback that will be called when an
 *              internal bandgap reference conversion completes
 */
typedef void (*pfIntBandgapRefCallback)(uint16_t);

/*
 * Name: pfTempSensorCallback
 * Description:	Function pointer type definition used to store
 *              the user callback that will be called when an
 *              internal sensor temperature conversion completes
 */
typedef void (*pfTempSensorCallback)(ADC_TemperatureSensor_t*);

/******************************************************************************
 ******************************************************************************
 * Public functions
 ******************************************************************************
 ******************************************************************************/

/******************************************************************************
 * Name: ADC_ModuleInit
 * Description: Initialize the ADC module. 
 *              Sets a default configuration for the ADC module.
 * Parameters: -
 * Return: -
 ******************************************************************************/
extern void ADC_ModuleInit
(
	void
);

/******************************************************************************
 * Name: ADC_ModuleDeInit
 * Description: Reset the ADC module. 
 *              The configuration registers	are put to their initial values 
 *              The ADC task is destroyed
 *              The clock for the module is disabled
 * Parameters: -
 * Return: -
 ******************************************************************************/
extern void ADC_ModuleDeInit
(
		void
);

/******************************************************************************
 * Name:  ADC_StartConversion
 * Description: Starts a conversion by setting the channel. Also, it saves 
 *              the handler 
 *
 * Parameters: [IN] channelNo - channel number
 * 			   [IN] privateHandler - pointer to the ADC_Handler function
 * Return: -
 ******************************************************************************/
extern void ADC_StartConversion
(
		uint8_t channelNo,
		pfConversionCompleteCallBack privateHandler
);

/******************************************************************************
 * Name:  ADC_GetBandgapRefVoltage
 * Description: Initiate the A2D conversion of the internal bandgap reference
 *              voltage channel; The provided pointer, if not null, will be 
 *              called when the conversion completes. The result of the 
 *              conversion (i.e. the value of the internal bandgap reference
 *              voltage) is passed as callback function argument.
 * Parameters: [IN] handler - pointer to the callback function
 * Return: -
 ******************************************************************************/
extern void ADC_GetBandgapRefVoltage
(
		pfIntBandgapRefCallback handler
);

/******************************************************************************
 * Name:  ADC_GetTemperature
 * Description: Initiate the A2D conversion of the internal temperature sensor. 
 *              The provided pointer, if not null, will be  called when the 
 *              conversion completes. The result of the conversion is passed as 
 *              callback argument.
 * Parameters: [IN] handler - pointer to the callback function
 * Return: -
 ******************************************************************************/
extern void ADC_GetTemperature
(
		pfTempSensorCallback handler
);

/******************************************************************************
 * Name:  ADC_GetConversionResult
 * Description: Gets the result of the conversion from the ADC FIFO
 * Parameters: -
 * Return: conversion result
 ******************************************************************************/
extern uint16_t ADC_GetConversionResult
(
	void
);

/******************************************************************************
 * Name: ADC_GetRawData
 * Description: gets the raw data (channel and conversion result) from FIFO 
 *              and store it at the location indicated by the 
 *              pADC_FIFOData_t_Entry pointer 
 * Parameters: [OUT] pADC_FIFOData_t_Entry - pointer to a location where data
 *                                           will be stored
 * Return: TRUE if operation succeeded, FALSE  otherwise
 ******************************************************************************/
extern bool_t ADC_GetRawData
(
	ADC_FIFOData_t* pADC_FIFOData_t_Entry
);

/******************************************************************************
 * Name: ADC_IsConversionComplete
 * Description: Checks if conversion completed
 * Parameters: -           
 * Return: TRUE if the conversion is completed, FALSE  if the conversion is 
 *         in progress
 ******************************************************************************/
extern bool_t ADC_IsConversionComplete
(
	void
);

/******************************************************************************
 * Name: ADC_SetConfig
 * Description: Sets the ADC module configuration (see ADCConfig_t)
 * Parameters: [IN] pAdcConfig - pointer to ADCConfig_t structure
 * Return: gADCModuleBusy_c OR gADCNULLPointer_c OR  gADCNoError_c 
 *         (see ADCErr_t definition)
 ******************************************************************************/
extern ADCErr_t ADC_SetConfig
(
	const ADCConfig_t * pAdcConfig
);

/******************************************************************************
 * Name:  ADC_GetConfig
 * Description: Puts at the address indicated by pConfig the current ADC 
 *              configuration
 * Parameters: [OUT] pConfig - pointer to ADCConfig_t structure
 * Return: gADCNoError_c OR gADCNULLPointer_c (see ADCErr_t definition)
 ******************************************************************************/
extern ADCErr_t ADC_GetConfig
(
		ADCConfig_t* pConfig
);

/******************************************************************************
 * Name: ADC_ISR
 * Description: ADC module interrupt service routine
 * 			    Here the channel and the result are written. 
 * 				A push operation is made to put the information into the queue.
 * 
 * Parameters: -
 * Return: - 
 ******************************************************************************/
#ifdef MEMORY_MODEL_BANKED
#pragma CODE_SEG __NEAR_SEG NON_BANKED
#else
#pragma CODE_SEG DEFAULT
#endif /* MEMORY_MODEL_BANKED */
extern INTERRUPT_KEYWORD void ADC_ISR 
(
	void 
);
#pragma CODE_SEG DEFAULT

#endif /* ADC_INTERFACE_H_ */
