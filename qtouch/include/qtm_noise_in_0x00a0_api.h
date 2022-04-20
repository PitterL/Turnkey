/* QTouch Modular Library Configuration */
/* Header file for application project - Acquisition library API */

#ifndef TOUCH_API_NOISE_IN_H
#define TOUCH_API_NOISE_IN_H


/* Include files */
#include <stdint.h>
#include "qtm_common_components_api.h"
#include "qtm_touch_key_0x0002_api.h"
  
/*----------------------------------------------------------------------------
 *     Structure Declarations
 *----------------------------------------------------------------------------*/

/* Noise In Module */
/* Configuration */
typedef struct 
{
  uint16_t num_key_sensors;             /* Number of sensors */
  uint8_t num_noises;             /* Number of noise sensors */
  uint8_t channel_hysteresis;    /* Percentage of threshold reduction to as detect state */
  uint8_t *noise_channel_select;        /* noisy channel nodes used to detect the noise */
}qtm_noise_in_config_t;

/* Status data */
typedef struct 
{
  uint8_t module_status;        /* Obligatory status: `QTM_KEY_DETECT` */  
  int16_t *noise_buffer;        /* Current noise delta value of the buffer */
}qtm_noise_in_data_t;

/* Container */
typedef struct 
{
  qtm_noise_in_data_t (*qtm_noise_in_data);
  qtm_noise_in_config_t (*qtm_noise_in_config);
  qtm_touch_key_data_t (*qtm_touch_key_data);
  qtm_touch_key_config_t (*qtm_touch_key_config);
} qtm_noise_in_control_t;


/*----------------------------------------------------------------------------
 *   prototypes
 *----------------------------------------------------------------------------*/
/*============================================================================
touch_ret_t qtm_noise_in(qtm_noise_in_control_t *qtm_noise_in_control);
------------------------------------------------------------------------------
Purpose: Runs freq hop process
Input  : Pointer to container structure
Output : touch_ret_t
Notes  : none
============================================================================*/
touch_ret_t qtm_noise_in(qtm_noise_in_control_t *qtm_noise_in_control);

/*============================================================================
uint16_t qtm_get_freq_hop_module_id(void)
------------------------------------------------------------------------------
Purpose: Returns the module ID
Input  : none
Output : Module ID
Notes  : none
============================================================================*/
uint16_t qtm_get_freq_hop_module_id(void);


/*============================================================================
uint8_t qtm_get_freq_hop_module_ver(void)
------------------------------------------------------------------------------
Purpose: Returns the module Firmware version
Input  : none
Output : Module ID - Upper nibble major / Lower nibble minor 
Notes  : none
============================================================================*/
uint8_t qtm_get_freq_hop_module_ver(void);


#endif    /* TOUCH_API_FREQ_HOP_H */
