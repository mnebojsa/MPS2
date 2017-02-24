#include "display.h"

extern display7seg;
extern DIGIT;
int count;
bit buttonPress;
sbit TASTER_UP     at P3_2_bit;
sbit TASTER_DOWN   at P3_3_bit;
int i;
void main()
{
        // Initialize the uC
        InitMCU();
        count = 0;
        // define BUTTON pin as input
        TASTER_UP = 1;
        TASTER_DOWN = 1;
        // clear the flag buttonPress
        buttonPress = 0;
        // turn off the digit

        while(1)
        {
        
                // refresh the displayed value

                for(i = 0; i < 4; i++)
                {
                        /*//use this to check are all noumbers displayed correctly
                        count++;
                        if (count > 9999)
                                  count = 0;*/
                
                        if(TASTER_UP == 0)
                        {
                                if (buttonPress == 0)
                                {
                                        count++;

                                        // check for the overflow
                                        if (count > 9999)
                                                count = 0;
                                        buttonPress = 1;
                                }
                        }else if(TASTER_DOWN == 0)
                        {
                               if (buttonPress == 0)
                                {
                                        count--;

                                        // check for the overflow
                                        if (count <= 0)
                                                count = 9999;
                                        buttonPress = 1;
                                 }
                        }else
                        {
                                buttonPress = 0;
                        }
                        
                        switch(i)
                        {
                                 case  0:
                                     setDigit(count%10,i);
                                 break;
                                 case  1:
                                     setDigit((count%100)/10,i);
                                 break;
                                 case  2:
                                     setDigit((count/100)%10,i);
                                 break;
                                 case  3:
                                     setDigit((count/100)/10,i);
                                 break;

                        }
                        delay_MS(5);
                        clearDigit(i);
                        
                 }
         }
}