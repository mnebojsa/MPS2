#include "../include/timer.h"

#define PRESCALER   (8)

static long tcount =0;

unsigned long milis()
{
     return tcount;
}

void initTC()
{
    char idata TCmode;
    char idata TCONreg;
    
    TCmode = ENABLE_TC0 |
             T0_AUTO_RELOAD;
    
    TCONreg = ENABLE_T0 |
              C1_INTR_ON_FALLING_EDGE |
              C0_INTR_ON_FALLING_EDGE;
    // Set initial count value
    tcount = 0;
    // Set timer 0 (gate disable, interval timer, auto-reload mode)
    setTCMode(TCmode);
    // Set auto-reload value to get 100us base tick
    TH0 = TIMER_100u;
    //
    TCCntrl(TCONreg);
    // Enable interrupts (sets EA and ET0)
    //register timer/counter 0 intr handler function
    registerIntrTC0(T0IntrHandler);
}

void setTCMode(char TCmode)
{
    TMOD = 0;
    TMOD = TCmode;
}

void TCCntrl(char TCONreg)
{
    TCON = TCONreg;
}

void setTimerVal(char timer,char timerVal)
{
    if(0 == timer)
    {
        TH0 = timer;
    }
    else if(1 == timer)
    {
        TH1 = timer;
    }
}

void T0IntrHandler(void)
{ 
    static unsigned int ticks = 0;
    //increases tcount after 1[ms]
    if (ticks++ >= PRESCALER)
    {
        tcount++;
        ticks = 0;
    }
}

void T1IntrHandler()
{
    //write this function when needed
}