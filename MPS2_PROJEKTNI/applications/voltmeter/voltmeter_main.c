#include "../include/voltmeter.h"
sbit TASTER        at P3_2_bit;
sbit LED at P0_0_bit;
bit buttonPress;

void InitMCU()
{
        // turn off all LEDS
        P0 = 0x00;
        // define BUTTON pin as input
        TASTER = 1;
        // clear the flag buttonPress
        buttonPress = 0;
}

void main()
{
        // Initialize the uC
        InitMCU();

        mjau(5);
        while(1)
        {
                if(TASTER == 0)
                {
                        if (buttonPress == 0)
                        {
                                LED = ~LED;
                                buttonPress = 1;
                        }
                }
                else
                        buttonPress = 0;
         }
}