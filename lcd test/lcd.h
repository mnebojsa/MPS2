//LCD Functions for 4 & 8 bit modes

 /* Lcd module connections  */
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;

sbit LCD_D7 at P2_5_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D4 at P2_2_bit;
//End LCD Module Connections 


void Lcd_Delay(int a)
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



static void Lcd_Port(char setPort)
{
    LCD_D4 = (setPort & 1)? 1: 0;
    LCD_D5 = (setPort & 2)? 1: 0;
    LCD_D6 = (setPort & 4)? 1: 0;
    LCD_D7 = (setPort & 8)? 1: 0;
}

void Lcd_Cmd(char a)
{ 
    LCD_RS = 0;
    Lcd_Port(a);
    LCD_EN  = 1;
    Lcd_Delay(5);
    LCD_EN  = 0;
}

Lcd_Clear()
{
    Lcd_Cmd(0);
    Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b)
{
        char temp,z,y;
        if(a == 1)
        {
          temp = 0x80 + b;
                z = temp>>4;
                y = (0x80+b) & 0x0F;
                Lcd_Cmd(z);
                Lcd_Cmd(y);
        }
        else if(a == 2)
        {
                temp = 0xC0 + b;
                z = temp>>4;
                y = (0xC0+b) & 0x0F;
                Lcd_Cmd(z);
                Lcd_Cmd(y);
        }
}

void Lcd_Init()
{
        Lcd_Port(0x00);
        Lcd_Delay(200);
        ///////////// Reset process from datasheet /////////
//  Lcd_Cmd(0x03);
    LCD_RS = 0;
    Lcd_Port(0x03);
    LCD_EN  = 1;
    Lcd_Delay(5);
    LCD_EN  = 0;
        Lcd_Delay(50);

//  Lcd_Cmd(0x03);
    LCD_RS = 0;
    Lcd_Port(0x03);
    LCD_EN  = 1;
    Lcd_Delay(5);
    LCD_EN  = 0;
        Lcd_Delay(110);

//    Lcd_Cmd(0x03);
    LCD_RS = 0;
    Lcd_Port(0x03);
    LCD_EN  = 1;
    Lcd_Delay(5);
    LCD_EN  = 0;
  /////////////////////////////////////////////////////
  Lcd_Cmd(0x02);
        Lcd_Cmd(0x02);
  Lcd_Cmd(0x08);
        Lcd_Cmd(0x00);
        Lcd_Cmd(0x0C);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x06);
}

void Lcd_Write_Char(char a)
{
   char temp,y;
   temp = a&0x0F;
   y = a&0xF0;
         LCD_RS = 1;             // Register Select = 1
   Lcd_Port(y>>4);             //Data transfer
         LCD_EN = 1;
         Lcd_Delay(5);
         LCD_EN = 0;
         Lcd_Port(temp);
         LCD_EN = 1;
         Lcd_Delay(5);
         LCD_EN = 0;
}

void Lcd_Write_String(char *a)
{
        int i;
        for(i=0;a[i]!='\0';i++)
         Lcd_Write_Char(a[i]);
}

void Lcd_Shift_Right()
{
        Lcd_Cmd(0x01);
        Lcd_Cmd(0x0C);
}

void Lcd_Shift_Left()
{
        Lcd_Cmd(0x01);
        Lcd_Cmd(0x08);
}
//End LCD 4 Bit Interfacing Functions