#include "timer.h"

long prescaler;
long count;
static int delay;

void InitTimer()
{
    // set initial count value
    count = 0;
    // set prescaler to obtain 500ms period
    prescaler = 1000;
    // set timer 0 (gate disable, interval timer, auto-reload mode)
    TMOD = 0x02;
    // set auto-reload value to get 100us base tick
    TH0 = 136;
    // enable interrupts (sets EA and ET0)
    IE = 0x87;
    // run the timer
    TR0_bit = 1;
    
    delay = 2;
}

unsigned long milis();

void count_up() iv IVT_ADDR_ET0 {
    static long ticks = 0;

    if (ticks++ >= delay*prescaler)
    {
        count++;
        ticks = 0;
    }
}

void delay_intr_up() iv IVT_ADDR_EX1
{
IE = 0x00;
     if(delay < 3)
     {
              delay++;
     }else
     {
              delay = 3;
     }
IE = 0x87;
}

void delay_intr_down() iv IVT_ADDR_EX0
{
IE = 0x00;
     if(delay > 1 )
     {
              delay-- ;
     }else
     {
              delay = 1;
     }
IE = 0x87;
}