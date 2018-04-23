//timer functions
#ifndef _TIMER_H_
#define _TIMER_H_

#include "interrupts.h"

#define ENABLE_T1 (0x80)
#define ENABLE_T2 (0x04)

/*timer modes       */
#define T0_MODE_0 (0x00)
#define T0_MODE_1 (0x10)
#define T0_AUTO_RELOAD (0x20)
#define T0_MODE_3 (0x30)

#define T1_MODE_0 (0x00)
#define T1_MODE_1 (0x01)
#define T1_AUTO_RELOAD (0x02)
#define T1_MODE_3 (0x03)


#define T0 (0)
#define T1 (1)
#define C0 (0)
#define C1 (1)
#define AUTO_RELOAD (0x55)
#define TIMER_100u (0x88)

/******************************************************************************/
/* \brief   This function initialises all modules used by Voltmeter. Those    */
/*                                                                            */
/* \param   void          No input params                                     */
/*                                                                            */
/* \return  void          No return value                                     */
/******************************************************************************/
void initTimer();
void setTCMode(char timer, char mode);
void setTimerVal(char timer,char timerVal);
void T0IntrHandler(void);
void T1IntrHandler(void);
unsigned long milis();
/******************************************************************************/
/* \brief   This function initialises all modules used by Voltmeter. Those    */
/*                                                                            */
/* \param   void          No input params                                     */
/*                                                                            */
/* \return  void          No return value                                     */
/******************************************************************************/

#endif