#include "../include/display.h"
/*******************************************************************************
 *     LCD Functions for 4-bit mode
 ******************************************************************************/

/******************************************************************************
 *                  Lcd module connections                                     
 ******************************************************************************/

// Regisrer_select pin
//     for commands to LCD - set it to be low
//     to display data (char) it shuld be set to high voltage level
sbit LCD_RS at P2_0_bit;
// Enable pin
//    When writeing data to the LCD it will read the data on the falling
//    edge of this pin
sbit LCD_EN at P2_1_bit;

// Data pins
sbit LCD_D7 at P2_5_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D4 at P2_2_bit;


static void LcdDelay(int a)
{
    int j;
    int i;
    for(i=0;i<a;i++)
    {
        for(j=0;j<100;j++)
        {
        }
    }
}

static void LcdPort(char setPort)
{
    LCD_D4 = (setPort & 1)? 1: 0;
    LCD_D5 = (setPort & 2)? 1: 0;
    LCD_D6 = (setPort & 4)? 1: 0;
    LCD_D7 = (setPort & 8)? 1: 0;
}

void LcdCmd(char cmd)
{
/*
    // write to comand register
    LCD_RS = 0;
    
    LCD_EN  = 1;
    LcdPort((cmd & 0xf0) >> 4);
 //   LcdDelay(5);
    LCD_EN  = 0;
    
    LCD_EN  = 1;
    LcdPort(cmd & 0x0f);
 //   LcdDelay(5);
    LCD_EN  = 0;
*/
Lcd_Cmd(cmd);
}


void LcdSetCursor(char row, char colmun)
{
    char temp;
    temp = (1 == row)?(_LCD_FIRST_ROW + colmun):(_LCD_SECOND_ROW + colmun);
    LcdCmd(temp);
}

void initLcd()
{
//    LcdPort(0x00);
//    LcdDelay(200);
//
//    LCD_RS = 0;
//
//    LCD_EN  = 1;
//    LcdDelay(5);
//    LcdPort(0x03);
//    LCD_EN  = 0;
//
//    LcdDelay(50);
//
//    LCD_EN  = 1;
//    LcdPort(0x03);
//    LcdDelay(5);
//    LCD_EN  = 0;
//
//    LcdDelay(110);
//
//    LCD_EN  = 1;
//    LcdPort(0x03);
//    LcdDelay(5);
//    LCD_EN  = 0;

    //BF can be checked after the following instructions. When BF is not checked,
    //the waiting time between instructions is longer than the execution
    //instuction time.
    //    LcdCmd(0x02);
//    LCD_EN  = 1;
//    LcdPort(0x02);
//    LcdDelay(5);
//    LCD_EN  = 0;
    //Sets 4-bit operation and selects 1-line display and 5 ´ 8 dot character font.
    //4-bit operation starts from this step and resetting is necessary.*/
    //N F * *
    //    LcdCmd(0x28);
//    LCD_EN  = 1;
//    LcdPort(0x02);
//    LcdDelay(5);
//    LCD_EN  = 0;
//        LCD_EN  = 1;
//    LcdPort(0x08);
//    LcdDelay(5);
//    LCD_EN  = 0;
    //Turns on display and cursor. Entire display is in space mode
    //because of initialization.
    //    LcdCmd(0x0C);
//    LCD_EN  = 1;
//    LcdPort(0x00);
//    LcdDelay(5);
//    LCD_EN  = 0;
//        LCD_EN  = 1;
//    LcdPort(0x0C);
//    LcdDelay(5);
//    LCD_EN  = 0;
    // Display clear
    //    LcdCmd(0x01);
//    LCD_EN  = 1;
//    LcdPort(0x00);
//    LcdDelay(5);
//    LCD_EN  = 0;
//        LCD_EN  = 1;
//    LcdPort(0x01);
//    LcdDelay(5);
//    LCD_EN  = 0;
    //Entry mode set
    //Sets mode to increment the address by one and to shift the cursor to the 
    //right at the time of write to the DD/CGRAM. Display is not shifted
    //0 1 I/D S
    //    LcdCmd(0x06);
//    LCD_EN  = 1;
//    LcdPort(0x00);
//    LcdDelay(5);
//    LCD_EN  = 0;
//        LCD_EN  = 1;
//    LcdPort(0x01);
//    LcdDelay(5);
//    LCD_EN  = 0;
LCD_Init();
}

void LcdPutChar(char chr)
{ 
    // Register Select
    LCD_RS = 1; 
    // Data transfer
    LCD_EN = 1;
    LcdPort((chr & 0xf0) >> 4);
    LCD_EN = 0;

    LCD_EN = 1;
    LcdPort(chr & 0x0f);
    LCD_EN = 0;
}

void LcdPutString(int row, int colmun, char *txt)
{
/*    char loop;
    char temp;
        
    temp = (1 == row)?(0x80 + colmun):(0xC0 + colmun);
    
    LcdCmd(temp);
        
    for(loop=0;txt[loop]!='\0';loop++)
    {
        LcdPutChar(txt[loop]);
    } */
    LCD_Out(row,colmun, txt);
    
}