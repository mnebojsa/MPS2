/******************************************************************************
 *    timer_hw.h                                                            
 *                                                                          
 *                                                                          
 ******************************************************************************/
#ifndef _TIMER_HW_H_
#define _TIMER_HW_H_
 
/*following constants should be written in TMOD register in order to take action*/

/*enable timers  */
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

/*auto-reload value to get 100us base tick */
#define TIMER_100u (0x88)

void runT0(void);
void runT1(void);
void runC0(void);
void runC1(void);

void setTC();

/**
 *
 *
 *
 */
//void setTimerVal(int ,int);

/**
 *
 *
 *
 */
 void setIEVal(int);
 
#endif