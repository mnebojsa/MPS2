#include "keypad.h"

char MATRIX at P0;

sbit COL1 at MATRIX.B0;
sbit COL2 at MATRIX.B1;
sbit COL3 at MATRIX.B2;
sbit COL4 at MATRIX.B3;

sbit ROW1 at MATRIX.B4;
sbit ROW2 at MATRIX.B5;
sbit ROW3 at MATRIX.B6;
sbit ROW4 at MATRIX.B7;

char scanKeypad()
{
     char button = 0xFF;
     
     MATRIX = 0xEF;

     if (COL1 == 0)
     {
        while(COL1 == 0) {}
        button = 1;
     }
     else if (COL2 == 0)
     {
        while(COL2 == 0) {}
        button = 2;
     }
     else if (COL3 == 0)
     {
        while(COL3 == 0) {}
        button = 3;
     }
     else if (COL4 == 0)
     {
        while(COL4 == 0) {}
        button = 10;
     }

     MATRIX = 0xDF;

     if (COL1 == 0)
     {
        while(COL1 == 0) {}
        button = 4;
     }
     else if (COL2 == 0)
     {
        while(COL2 == 0) {}
        button = 5;
     }
     else if (COL3 == 0)
     {
        while(COL3 == 0) {}
        button = 6;
     }
     else if (COL4 == 0)
     {
        while(COL4 == 0) {}
        button = 11;
     }

     MATRIX = 0xBF;

     if (COL1 == 0)
     {
        while(COL1 == 0) {}
        button = 7;
     }
     else if (COL2 == 0)
     {
        while(COL2 == 0) {}
        button = 8;
     }
     else if (COL3 == 0)
     {
        while(COL3 == 0) {}
        button = 9;
     }
     else if (COL4 == 0)
     {
        while(COL4 == 4) {}
        button = 12;
     }

     MATRIX = 0x7F;

     if (COL1 == 0)
     {
        while(COL1 == 0) {}
        button = 14;          // *
     }
     else if (COL2 == 0)
     {
        while(COL2 == 0) {}
        button = 0;
     }
     else if (COL3 == 0)
     {
        while(COL3 == 0) {}
        button = 15;         // #
     }
     else if (COL4 == 0)
     {
        while(COL4 == 0) {}
        button = 13;         // D
     }

     MATRIX = 0x00;

     return button;
}