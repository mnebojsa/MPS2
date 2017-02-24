#include "timer.h"

char LEDS at P0;
extern prescaler;

void main()
{
     long current;
     char direction;
    // Initialize the uC
    InitTimer();
    LEDS = 0x01;
    current = milis();
    direction = 0;
    while(1)
    {
            if(milis()-current >= del())
            {
                      if(0x80 >= LEDS && 0 == direction)
                      {
                              if(LEDS == 0x80)
                              {
                                      direction = 1;
                              }else
                              {
                                      direction = 0;
                                      LEDS *= 2;
                              }
                      }
                      if(0x01 <= LEDS && 1 == direction)
                      {
                              if(LEDS == 0x01)
                              {
                                      direction = 0;
                              }else
                              {
                                      direction = 1;
                                      LEDS /= 2;
                              }
                      }
                      current = milis();
            }
    }
}