#ifndef _TIMER_H_
#define _TIMER_H_

#include "interrupts.h"
//TMOD register
#define ENABLE_TC1 (0x80)
#define ENABLE_TC0 (0x08)
// timer modes
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
 * The function is used to init timer/counter
 * Currently it is written to set Timer  to work in auto reload mode
 * this function should be repaired for further usage
 *
 * @param [No  input params]
 *
 * @ret [No  valureturne]
 */
void initTC(void);

/**
 * @brief
 * The function is used to set timer mode if the module is used as timer. It
 * writes coresponding values in TMOD register. Values that should be used are
 * defined in this file
 *
 * @param [IN] - char TCmode - timer mode
 *
 * @ret [No return value]
 */
void setTCMode(char TCmode);

/**
 * @brief
 * The function returns value of global static variable that is updated after
 * each timer interrupt
 *
 * @param [No  input params]
 *
 * @ret [OUT] - unsigned long - value updated after each timer interrupt
 */
unsigned long milis(void);
 
/**
 * @brief
 * The function updates TCON register
 *
 * @param [IN] - char TCONreg - valu to write in TCON register
 *
 * @ret [No return value]
 */
void TCCntrl(char TCONreg);

/**
 * @brief
 * The function sets timer/counter values - useful in autoreload mode
 *
 * @param [IN] - char timer    - timer  or 1
 * @param [IN] - char timerVal - value to write in timer
 *
 * @ret [No return value]
 */
void setTimerVal(char timer,char timerVal);

/**
 * @brief
 * The interrupt handler functions that should be registerd to timer interrupts
 *
 * @param [No  input params]
 *
 * @ret [No  valureturne]
 */
void T0IntrHandler(void);
void T1IntrHandler(void);

#endif