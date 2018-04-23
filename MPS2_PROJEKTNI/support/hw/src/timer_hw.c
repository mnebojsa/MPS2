#include "../include/timer_hw.h"

void setTC()
{
    TMOD = 0x00;
    TMOD = ENABLE_T1 | ENABLE_T2;
}

void setT0Val(int tVal)
{
     TH0 = tVal;
}

void setT1Val(int tVal)
{
     TH1 = tVal;
}

