#ifndef _ADCONV_H_
#define _ADCONV_H_

#define REF_VOLTAGE (5.0)
#define DELTA_STEPS (4096.0)
#define DELTA_VAL   (REF_VOLTAGE / DELTA_STEPS)

/**
 * @brief
 * Function used to initialize the ADC module
 *
 * @param [IN] - unsigned char mode      -mode: 0 - differential,
 *                                              1 - single
 * @param [IN] - cunsigned char channel  -channel: 0-3
 *
 * @ret [No return value]
 */
void MCP3204_Init(unsigned char mode, unsigned char channel);

/**
 * @brief
 * Function used to set the mode of the ADC module
 *
 * @param [IN] - unsigned char mode      -mode: 0 - differential,
 *                                              1 - single
 *
 * @ret [No return value]
 */
void MCP3204_SetMode(unsigned char mode);

/**
 * @brief
 * Function used to set the channel of the ADC module
 *
 * @param [IN] - cunsigned char channel  -channel: 0-3
 *
 * @ret [No return value]
 */
void MCP3204_SetChannel(unsigned char channel);

/**
 * @brief
 * Function used to get sample from ADC module.
 * Returns voltage value sampled
 *
 * @param [IN] - void - no input parameters
 *
 * @ret [OUT]  - float - voltage value sampled
 */
float MCP3204_GetSample(void);

#endif