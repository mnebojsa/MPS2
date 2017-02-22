#include "timer.h"

char LEDS at P0;
extern count;
extern prescaler;

void main()
{
    // Initialize the uC
    InitTimer();

    while(1)
    {
            LEDS = ~count;
    }
}
