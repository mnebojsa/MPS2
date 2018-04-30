//timer functions
#ifndef _TIMER_H_
#define _TIMER_H_

#include "interrupts.h"
//TMOD register
#define ENABLE_TC1 (0x80)
#define ENABLE_TC0 (0x08)
/* timer modes */
#define T1_MODE_0 (0x00)
#define T1_MODE_1 (0x10)
#define T1_AUTO_RELOAD (0x20)
#define T1_MODE_3 (0x30)
#define T0_MODE_0 (0x00)
#define T0_MODE_1 (0x01)
#define T0_AUTO_RELOAD (0x02)
#define T0_MODE_3 (0x03)

//TCON register
#define ENABLE_T1 (0x40)
#define ENABLE_T0 (0x10)
#define C1_INTR_ON_FALLING_EDGE (0x04)
#define C0_INTR_ON_FALLING_EDGE (0x01)

#define TIMER_100u (0x88)

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
void initTimer();

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
void setTCMode(char TCmode);

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
unsigned long milis();
 
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
void TCCntrl(char TCONreg);

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
void setTimerVal(char timer,char timerVal);

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
void T0IntrHandler();
void T1IntrHandler();

#endif