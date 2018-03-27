//timer functions
#ifndef _TIMER_H_
#define _TIMER_H_

#include "../../hw/include/timer_hw.h"

/******************************************************************************/
/* \brief   This function initialises all modules used by Voltmeter. Those    */
/*                                                                            */
/* \param   void          No input params                                     */
/*                                                                            */
/* \return  void          No return value                                     */
/******************************************************************************/
void InitTimer();

/******************************************************************************/
/* \brief   This function initialises all modules used by Voltmeter. Those    */
/*                                                                            */
/* \param   void          No input params                                     */
/*                                                                            */
/* \return  void          No return value                                     */
/******************************************************************************/
unsigned long milis();

void startTimer();
void startCounter();
void enableinterrupt();

#endif