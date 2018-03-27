#ifndef _VOLTMETER_H_
#define _VOLTMETER_H_

#include "../../support/API/include/timer.h"
#include "../../support/API/include/interrupts.h"
#include "../../support/API/include/display.h"
#include "../../support/API/include/mcp3204.h"
#include "../../support/API/include/spi.h"

/**
 * @brief
This function initialises all modules used by Voltmeter. Those
 *          modules are: -Display
 *                       -A/D converter
 *                       -SPI
 *                       -Timer
 *
 * @param [IN] - No input params
 *
 * @ret [No return value]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
void initVoltmeter(void);

/**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
char refreshDisplayTime(char);

/**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
unsigned int mesProccess(char*);

/**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
 char signalLight(float, float);
 
/**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
 void dispVoltage(unsigned int, char);
 
 /**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
 void incrScale(void);
 
  /**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
 void decrScale(void);
 
#endif