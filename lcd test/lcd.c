#include<reg52.h> //including sfr registers for ports of 89s52
#include<lcd.h>  // lcd header file 

//LCD Module Connections
sbit RS = P0^0;
sbit EN = P0^1;
sbit D4 = P2^0;
sbit D5 = P2^1;
sbit D6 = P2^2;
sbit D7 = P2^3;
//End LCD Module Connections
void Delay(int a)
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
void main()
{
  int i;
  Lcd_Init();
    Lcd_Clear();
  while(1)
  {
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("8051 LCD Interface");
    for(i=0;i<18;i++)
    {
      Delay(1000);
      Lcd_Shift_Left();
    }
    for(i=0;i<18;i++)
    {
      Delay(1000);
      Lcd_Shift_Right();
    }
    Lcd_Clear();
    Lcd_Set_Cursor(2,1);
    Lcd_Write_Char('S');
    Lcd_Write_Char('E');
    Delay(2000);
  }
}

