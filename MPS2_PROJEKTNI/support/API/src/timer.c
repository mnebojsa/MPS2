#include "../include/timer.h"

long prescaler;
static int idata delay;
static long ticks = 0;
long idata tcount;
bit test at P0_1_bit;
/*


void setTimerVal(char timer, char timerReladVal)
{
    if(T0 == timer)
    {
        setT0Val(timerReladVal);
    }
    else if(T1 == timer)
    {
        setT1Val(timerReladVal);
    }
    else
    {
        /* MISRA */
//    }
//}


void T0IntrHandler(void)
{


     if (ticks++ >= prescaler)
     {
         tcount++;
         ticks = 0;
     }
     if (tcount > delay)
     {
         tcount = 0;
         ticks = 0;
         test= ~test;
         delay_MS(50);
     }
}
/*
void T1IntrHandler()
{
    //setTimerVal(T1,TIMER_100u);
}

unsigned long milis()
{
     return tcount;
}
 */
/*

volatile unsigned long count;
long prescaler;
*/
void initTimer()
{
     // Set initial count value
     tcount = 0;
     // Set prescaler to obtain 1 ms period
     prescaler = 100000;
     delay = 10000;
     // Set timer 0 (gate disable, interval timer, auto-reload mode)
     TMOD = 0x02;
     // Set auto-reload value to get 100us base tick
     TH0 = 136;
     // Enable interrupts (sets EA and ET0)
     IE = 0x82;
     registerIntrTC0(T0IntrHandler);
     // Run the timer
     TR0_bit = 1;
     //registerIntrTC0(T0IntrHandler);
}
