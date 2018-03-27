#include "../include/timer_hw.h"

/*Parameters of Counter-Timer  */
char TCMode;

/*Timer-Counter Control     */
char TControl;

void setTC()
{
    TMOD = 0x00;
    TMOD = ENABLE_T1 | ENABLE_T2;
}

void setT0Val(int tVal)
{
     TH0 = tVal;
}

setTimerVal(int timer,int IEVal)
{
     IE = IEVal;
     if(0 == timer)
     {
         IT0_bit = 1;
     }
     else if (1 == timer)
     {
         IT1_bit = 1;
     }
     else
     {
         /*MISRA  */
     }
}
