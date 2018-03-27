#include "../include/timer.h"

long prescaler;
static int delay;
long tcount;
void InitTimer()
{
    /* set initial count value     */
    tcount = 0;
    /* set prescaler to obtain 500ms period   */
    prescaler = 1000;
    /* set timer 0 (gate disable, interval timer, auto-reload mode) */
    /*setTMOD(0x02);   */
    /* set auto-reload value to get 100us base tick  */
    setTimerVal(0,TIMER_100u);
    /* enable interrupts (sets EA and ET0)  */
    setIEVal(0x87);
    /* run the timer   */
    TR0_bit = 1;

    delay = 2;
}

void startTimer()
{
        int temp = 5;
        setTC();
}

void startCounter()
{
        
}

void enableinterrupt()
{
        
}

void count_up() iv IVT_ADDR_ET0 {
    static long ticks = 0;
    IE = 0x00;
    if (ticks++ >= delay*prescaler)
    {
        tcount++;
        ticks = 0;
    }
    IE = 0x87;
}

unsigned long milis()
{
     //return count;
     return 1;
}

/*

volatile unsigned long count;
long prescaler;

void InitTimer()
{
     // Set initial count value
     count = 0;
     // Set prescaler to obtain 1 ms period
     prescaler = 10;
     // Set timer 0 (gate disable, interval timer, auto-reload mode)
     TMOD = 0x02;
     // Set auto-reload value to get 100us base tick
     TH0 = 136;
     // Enable interrupts (sets EA and ET0)
     IE = 0x82;
     // Run the timer
     TR0_bit = 1;
}

void count_up() iv IVT_ADDR_ET0
{
     static long ticks = 0;

     if (ticks++ >= prescaler)
     {
         count++;
         ticks = 0;
     }
}

unsigned long milis()
{
     return count;
}

*/