#include "display.h"


sbit DIS0_SEL at P1_0_bit;
sbit DIS1_SEL at P1_1_bit;
sbit DIS2_SEL at P1_2_bit;
sbit DIS3_SEL at P1_3_bit;
const char display7seg[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
char DIGIT at P0;
static int mode;

void InitMCU()
{

        // deselect displays
        DIS0_SEL = 0;
        DIS1_SEL = 0;
        DIS2_SEL = 0;
        DIS3_SEL = 0;
        // set initial value and select DIS0
        DIS0_SEL = 1;
        mode = 1;
}

// sets the mode of the 7-segment display
//                 mode = COMMON_ANODE -> displays with common anode are used
//                 mode = COMMON_CATHODE -> displays with common cathode are us
// Usage:
//                setMode(COMMON_CATHODE); -> sets the displays to work in common cathode mode
void setMode(char modei)
{
     mode = modei%2;
}

// displays the specified value (must be in range 0-9) at the specified position (must be in range 0-3)
// Usage:
//                setDigit(6, 3); -> displays the number 6 on the display at the position 3
void setDigit(char value, char position)
{
     if(0 == mode)
        {
        //display turns on with logial "0"
                switch(position)
                {
                        case 0:
                            DIS0_SEL = 0;
                        break;
                        case 1:
                            DIS1_SEL = 0;
                        break;
                        case 2:
                            DIS2_SEL = 0;
                        break;
                        case 3:
                            DIS3_SEL = 0;
                        break;
                }
                DIGIT = display7seg[value];
        }else if(1 == mode)
        {
        //display turns on with logial "1"
                switch(position)
                {
                        case 0:
                            DIS0_SEL = 1;
                        break;
                        case 1:
                            DIS1_SEL = 1;
                        break;
                        case 2:
                            DIS2_SEL = 1;
                        break;
                        case 3:
                            DIS3_SEL = 1;
                        break;
                }
                DIGIT = display7seg[value];
        }
}

// clears (turns off) the display at the specified position
// Usage:
//                clearDigit(3); -> clears the digit on the display at the position 3
void clearDigit(char position)
{
        if(1 == mode)
        {
        //display turns of with logial "0"
                switch(position)
                {
                        case 0:
                            DIS0_SEL = 0;
                        break;
                        case 1:
                            DIS1_SEL = 0;
                        break;
                        case 2:
                            DIS2_SEL = 0;
                        break;
                        case 3:
                            DIS3_SEL = 0;
                        break;
                }
        }else if(0 == mode)
        {
        //display turns of with logial "1"
                switch(position)
                {
                        case 0:
                            DIS0_SEL = 1;
                        break;
                        case 1:
                            DIS1_SEL = 1;
                        break;
                        case 2:
                            DIS2_SEL = 1;
                        break;
                        case 3:
                            DIS3_SEL = 1;
                        break;
                }
        }
}