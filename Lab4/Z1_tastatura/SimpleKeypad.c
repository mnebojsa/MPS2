#include "display.h"
#include "keypad.h"

char but;
char butPrev;

void main()
{
     InitDisplay();

     while(1)
     {
         clearDigit(0);
         but = scanKeypad();

         if (but != 0xFF)
         {
             butPrev = but;
         }
         setDigit(butPrev, 0);
     }
}