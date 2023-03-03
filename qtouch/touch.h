/*============================================================================
Filename : touch.h
Project : QTouch Modular Library
Purpose : configuation macros for touch library

This file is part of QTouch Modular Library Release 7.5 application.

Important Note: Do not edit this file manually.
                Use QTouch Configurator within Atmel Start to apply any
                modifications to this file.

Usage License: Refer license.h file for license information
Support: Visit http://www.microchip.com/support/hottopics.aspx
               to create MySupport case.

------------------------------------------------------------------------------
Copyright (c) 2021 Microchip. All rights reserved.
------------------------------------------------------------------------------
============================================================================*/

#ifndef TOUCH_H
#define TOUCH_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *     include files
 *----------------------------------------------------------------------------*/

#include "touch_api_ptc.h"
#include "rtc.h"

/**********************************************************/
/******************* Acquisition controls *****************/
/**********************************************************/
/* Defines the Measurement Time in milli seconds.
 * Range: 1 to 255.
 * Default value: 20.
 */
#define DEF_TOUCH_MEASUREMENT_PERIOD_MS 10

/* Defines the Measurement Time in milli seconds.
 * Range: support[2, 4, 8, 16, 32, 64, 128, 256]
 * Default value 64
 * value 0 mean never measured in idle
 */
#define DEF_TOUCH_MEASUREMENT_IDLE_PERIOD_MS 64

/* Defines the Type of sensor
 * Default value: NODE_MUTUAL.
 */
#define DEF_SENSOR_TYPE NODE_SELFCAP_SHIELD

/* Set sensor calibration mode for charge share delay ,Prescaler or series resistor.
 * Range: CAL_AUTO_TUNE_NONE / CAL_AUTO_TUNE_RSEL / CAL_AUTO_TUNE_PRSC / CAL_AUTO_TUNE_CSD
 * Default value: CAL_AUTO_TUNE_NONE.
 */
#define DEF_PTC_CAL_OPTION CAL_AUTO_TUNE_NONE

/* Defines the interrupt priority for the PTC. Set low priority to PTC interrupt for applications having interrupt time
 * constraints. Range: 0 to 2 Default: 2 (Lowest Priority)
 */
#define DEF_PTC_INTERRUPT_PRIORITY None

/* Calibration option to ensure full charge transfer */
/* Bits 7:0 = XX | TT SELECT_TAU | X | CAL_OPTION */
#define DEF_PTC_TAU_TARGET CAL_CHRG_5TAU
#define DEF_PTC_CAL_AUTO_TUNE (uint8_t)((DEF_PTC_TAU_TARGET << CAL_CHRG_TIME_POS) | DEF_PTC_CAL_OPTION)

/* Set default bootup acquisition frequency.
 * Range: FREQ_SEL_0 - FREQ_SEL_15 , FREQ_SEL_SPREAD
 * Default value: FREQ_SEL_0.
 */
#define DEF_SEL_FREQ_INIT FREQ_SEL_0

/*----------------------------------------------------------------------------
 *     defines
 *----------------------------------------------------------------------------*/

 /* Pin map */
 /*
    PA(6)  Y0  XY(2) BTN0
    PA(7)  Y1  XY(3) BTN1

    1 button:
        Evsys sleep: 15uA
        Soft sleep: 22uA
 */

/**********************************************************/
/***************** Node Params   ******************/
/**********************************************************/
/* Acquisition Set 1 */
/* Defines the number of sensor nodes in the acquisition set
 * Range: 1 to 65535.
 * Default value: 1
 */
#define DEF_NUM_CHANNELS (2)

/* Defines mutual cap node parameter setting
 * {X-line, Y-line, Charge Share Delay, NODE_RSEL_PRSC(series resistor, prescaler), NODE_G(Analog Gain , Digital Gain),
 * filter level}
 */
/* Defines node parameter setting self cap
 * {Shield line, Y-line, Charge Share Delay, NODE_RSEL_PRSC(series resistor, prescaler), NODE_G(Analog Gain , Digital
 * Gain), filter level}
 */
#define NODE_0_PARAMS                                                                                                  \
  {                                                                                                                  \
    X_NONE, Y(2), 0, NODE_RSEL_PRSC(RSEL_VAL_0, PRSC_DIV_SEL_4), NODE_GAIN(GAIN_1, GAIN_1), FILTER_LEVEL_16         \
  }

#define NODE_1_PARAMS                                                                                                  \
    {                                                                                                                  \
        X_NONE, Y(3), 0, NODE_RSEL_PRSC(RSEL_VAL_0, PRSC_DIV_SEL_4), NODE_GAIN(GAIN_1, GAIN_1), FILTER_LEVEL_16         \
    }

#define PTC_SEQ_NODE_CFG1  {  \
  NODE_0_PARAMS,  \
  NODE_1_PARAMS   \
}

/**********************************************************/
/***************** Key Params   ******************/
/**********************************************************/
/* Defines the number of key sensors
 * Range: 1 to 65535.
 * Default value: 1
 */
#define DEF_NUM_SENSORS (DEF_NUM_CHANNELS)

/* Defines Key Sensor setting
 * {Sensor Threshold, Sensor Hysterisis, Sensor AKS}
 */
#define KEY_0_PARAMS                                                                                                   \
  {                                                                                                                  \
    130, HYST_25, NO_AKS_GROUP                                                                                     \
  }

#define QTLIB_KEY_CONFIGS_SET {  \
  KEY_0_PARAMS,  \
  KEY_0_PARAMS,  \
}

/* De-bounce counter for additional measurements to confirm touch detection
 * Range: 0 to 255.
 * Default value: 4.
 */
#define DEF_TOUCH_DET_INT 4

/* De-bounce counter for additional measurements to confirm away from touch signal
 * to initiate Away from touch re-calibration.
 * Range: 0 to 255.
 * Default value: 5.
 */
#define DEF_ANTI_TCH_DET_INT 20

/* Threshold beyond with automatic sensor recalibration is initiated.
 * Range: RECAL_100/ RECAL_50 / RECAL_25 / RECAL_12_5 / RECAL_6_25 / MAX_RECAL
 * Default value: RECAL_100.
 */
#define DEF_ANTI_TCH_RECAL_THRSHLD RECAL_100

/* Rate at which sensor reference value is adjusted towards sensor signal value
 * when signal value is greater than reference.
 * Units: 200ms
 * Range: 0-255
 * Default value: 20u = 4 seconds.
 */
#define DEF_TCH_DRIFT_RATE 1

/* Rate at which sensor reference value is adjusted towards sensor signal value
 * when signal value is less than reference.
 * Units: 200ms
 * Range: 0-255
 * Default value: 5u = 1 second.
 */
#define DEF_ANTI_TCH_DRIFT_RATE 2

/* Time to restrict drift on all sensor when one or more sensors are activated.
 * Units: 200ms
 * Range: 0-255
 * Default value: 20u = 4 seconds.
 */
#define DEF_DRIFT_HOLD_TIME 10

/* Set mode for additional sensor measurements based on touch activity.
 * Range: REBURST_NONE / REBURST_UNRESOLVED / REBURST_ALL
 * Default value: REBURST_UNRESOLVED
 */
#define DEF_REBURST_MODE REBURST_ALL

/* Sensor maximum ON duration upon touch.
 * Range: 0-255
 * Default value: 0
 */
#define DEF_MAX_ON_DURATION 250 //200ms

/**********************************************************/
/********* Frequency Hop Module ****************/
/**********************************************************/

/* sets the frequency steps for hop.
 * Range: 3 to 7.
 * Default value: 3
 */
#define NUM_FREQ_STEPS 3

/* PTC Sampling Delay Selection - 0 to 15 PTC CLK cycles */
#define DEF_MEDIAN_FILTER_FREQUENCIES FREQ_SEL_0, FREQ_SEL_7, FREQ_SEL_15

/**********************************************************/
/******************* Low-power parameters *****************/
/**********************************************************/
/* Enable or disable low-power scan
 * Range: 0 or 1
 * Default value: 1
 */
#define DEF_TOUCH_LOWPOWER_ENABLE 1u

/* Node selection for Low-power scan.
 * Range: 0 to (DEF_NUM_CHANNELS-1).
 * Default value: 0
 */
#ifdef DEF_TOUCH_LOWPOWER_SOFT
#define QTM_AUTOSCAN_NODE 0x3   /* sensor node mask */
#else
#define QTM_AUTOSCAN_NODE 0     /* sensor node */
#endif

/* Touch detection threshold for Low-power node.
 * Range: 10 to 255
 * Default value: 10
 */
#define QTM_AUTOSCAN_THRESHOLD 130

/* Defines the Auto scan trigger period.
 * The Low-power measurement period determine the interval between low-power touch measurement.
 * Range: NODE_SCAN_4MS to NODE_SCAN_4096MS
 * Default value: NODE_SCAN_64MS
 */
#define QTM_AUTOSCAN_TRIGGER_PERIOD NODE_SCAN_64MS

/* Waiting time (in millisecond) for the application to switch to low-power measurement after the last touch.
 * Range: 0 to 255, unit 200ms
 * Default value: 0(never timeout)
 */
#define DEF_TOUCH_ACTIVE_IDLE_TIMEOUT 20

/* Defines drift measurement period
 * During low-power measurement, it is recommended to perform periodic active measurement to perform drifting.
 * This parameter defines the measurement interval to perform drifting.
 * Range: 0 to 255 ( should be more than QTM_AUTOSCAN_TRIGGER_PERIOD) unit 200ms
  0: never drift
   Note: the maximum value will be limited by WDTDOG setting
 */
#define DEF_TOUCH_DRIFT_PERIOD_MS 10

/* Defines overflow measage of the measurement
 * During measurement, acquisition should be done before next measurement. If not, that means sampling interval is two fast or something wrong of the measurement
 * Range: count that notice overflow
  0 ~ 255
 */
#ifdef DEF_TOUCH_MEASUREMENT_OVERFLOW
#define DEF_TOUCH_MEASUREMENT_OVERFLOW_THRESHOLD 2
#define DEF_TOUCH_MEASUREMENT_OVERFLOW_FORCE_DONE 200
#endif

/**********************************************************/
/***************** Communication - Data Streamer ******************/
/**********************************************************/

// #define DEF_TOUCH_DATA_STREAMER_ENABLE 0u

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TOUCH_C
