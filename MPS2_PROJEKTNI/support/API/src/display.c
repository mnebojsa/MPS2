#include "../include/display.h"

 /* Lcd module connections  */
extern sbit LCD_RS;
extern sbit LCD_EN;
sbit LCD_RS at P2.B0;
sbit LCD_EN at P2.B1;
sbit LCD_D7 at P2.B5;
sbit LCD_D6 at P2.B4;
sbit LCD_D5 at P2.B3;
sbit LCD_D4 at P2.B2;

void displayInit()
{
    /* set external interrupts (triggered on falling edge) in TCON register  */
    /* enable interrupts (sets EA, EX1 and EX0) in IE register     */
     IE = 0xff;
     LCD_Init();
}

void display(char row, char column, char* txt)
{
     Lcd_Out(row, column, txt);
}

void dispCmd(char* txtCmd)
{
    Lcd_Cmd(txtCmd);
}