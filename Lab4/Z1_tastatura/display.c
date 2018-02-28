#include "display.h"

sbit DIS0_SEL at P1_0_bit;
sbit DIS1_SEL at P1_1_bit;
sbit DIS2_SEL at P1_2_bit;
sbit DIS3_SEL at P1_3_bit;
char DIGIT at P0;


const char displayValues[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};


void InitDisplay()
{
        DIGIT = 0x00;

        DIS0_SEL = 0;
        DIS1_SEL = 0;
        DIS2_SEL = 0;
        DIS3_SEL = 0;
        
        DIGIT = displayValues[0];
        
        DIS0_SEL = 1;
}

void setDigit(char value, char position)
{
     DIS0_SEL = 0;
     DIS1_SEL = 0;
     DIS2_SEL = 0;
     DIS3_SEL = 0;

     DIGIT = displayValues[value];

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

void clearDigit(char position)
{
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

}

void showNumber(int number)
{
     int i;
     char digit;
     for (i = 0; i < 4; i++)
     {
         digit = number % 10;
         number = number / 10;
         
         setDigit(digit, i);
         Delay_ms(1);
         clearDigit(i);
     }
}

void setMode(char mode)
{


}