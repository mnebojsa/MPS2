#ifndef _VOLTMETER_H_
#define _VOLTMETER_H_

#include "../../support/API/include/timer.h"
#include "../../support/API/include/interrupts.h"
#include "../../support/API/include/display.h"
#include "../../support/API/include/ADConv.h"
#include "../../support/API/include/spi.h"

/**
 * @brief
 * This function initialises all modules used by Voltmeter. Those
 *          modules are: -Display
 *                       -A/D converter
 *                       -SPI
 *                       -Timer
 *                       -Interrupt
 *                       -Set Interrupt handlers
 * It should be called before any other API function.
 *
 * @param [IN] - No input params
 *
 * @ret [No return value]
 */
 
void idata initVoltmeter(void);

/**
 * @brief
 * The function is used to for messurment process. It gives back messured value
 * and sets automaticly right scale (where the parameter of the function is
 * a pointer to the scale variable)
 *
 * @param [IN] - *scale - pointer to the scale variable
 *
 * @ret [OUT] - returns value of samples (whole scale take 4096 samples if 
 *              MCP3204 is used). This is not measured value, but just
 *              reference value-where max value is 4096. Real mesured voltage
 *              is calculated using this value and Reference Voltage value
 *              (reference volltage value on A/D conv)
 */
float mesProccess(char* scale);
 
/**
 * @brief
 * Display float value (measured voltage here), on Display, in scale provided.
 * this function takes num of samples(that are returned by mesProccess function)
 * and displays real measured voltage (measured voltage is function of sample 
 * number and reference voltage on A/D convertor)
 *
 * @param [IN] - float mesuredVal - relative voltage level
 * @param [IN] - char scale - scale in which voltage is displayed
 *
 * @ret [No return value]
 */
 void dispVoltage(float mesuredVal, char scale);
 
 /**
 * @brief
 * This is external_interrupt_0 handler for Voltmetar app.
 * It is used to be registerd to extern interrupt in voltmetar Init function.
 * This function is used for manual scale changeing
 *
 * @param [IN] - No input parameters
 *
  * @ret [No return value]
 */
 void incrScaleIntrHandler(void);
 
 /**
 * @brief
 * This is external_interrupt_0 handler for Voltmetar app.
 * It is used to be registerd to extern interrupt in voltmetar Init function.
 * This function is used for manual scale changeing
 *
 * @param [IN] - No input parameters
 *
  * @ret [No return value]
 */
 void decrScaleIntrHandler(void);
 
#endif