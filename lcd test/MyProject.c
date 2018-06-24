#include<lcd.h>  // lcd header file

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
    //Lcd_Set_Cursor(1,1);
    Lcd_Write_String(1,1,"8051 LCD Interface");
    for(i=0;i<18;i++)
    {
      Delay(300);
      Lcd_Cmd(0x18);
    }
    for(i=0;i<18;i++)
    {
      Delay(300);
      Lcd_Cmd(0x1C);
    }
    Lcd_Cmd(0x01);
    Delay(50);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_Char('S');
    Lcd_Write_Char('E');
    Delay(2000);
  }
}





























//void initLCD(void)
//{
//    /* Wait for more than 15 ms after VCC rises to 4.5 V */
//    Delay_ms(50);
//    /* BF cannot be checked before this instruction. */
//    /* Function set (Interface is 8 bits long.) */
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 1;
//    LCD_D4 = 1;
//
//    /* Wait for more than 4.1 ms */
//    Delay_ms(10);
//
//    /* BF cannot be checked before this instruction. */
//    /* Function set (Interface is 8 bits long.) */
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 1;
//    LCD_D4 = 1;
//
//    /* Wait for more than 100 ms */
//    Delay_ms(120);
//
//    /* Function set (Set interface to be 4 bits long.)
//    Interface is 8 bits in length. */
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 1;
//    LCD_D4 = 1;
//
//    Delay_ms(10);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 1;
//    LCD_D4 = 0;
//
//    /* Function set (Interface is 4 bits long. Specify the
//       number of display lines and character font.)
//       The number of display lines and character font
//       cannot be changed after this point.  */
//
//    Delay_ms(20);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 1;
//    LCD_D4 = 0;
//
//    Delay_ms(20);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0; //N
//    LCD_D6 = 0; //F
//    LCD_D5 = 0; //*
//    LCD_D4 = 0; //*
//
//    /* Display off */
//
//    Delay_ms(20);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 0;
//    LCD_D4 = 0;
//
//    Delay_ms(20);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 1;
//    LCD_D6 = 0;
//    LCD_D5 = 0;
//    LCD_D4 = 0;
//
//    /* Display clear */
//
//    Delay_ms(20);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 0;
//    LCD_D4 = 0;
//
//    Delay_ms(20);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 0;
//    LCD_D4 = 1;
//
//    /* Entry mode set */
//
//    Delay_ms(20);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 0;
//    LCD_D5 = 0;
//    LCD_D4 = 0;
//
//    Delay_ms(20);
//
//    LCD_EN = 0;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 1;
//    LCD_D5 = 1;//I/D;
//    LCD_D4 = 0;//S;
//
//}
///*char row, char column, char out_char*/
//void LcdChr()
//{
//    LCD_EN = 1;
//    LCD_RS = 0;
//    LCD_D7 = 0;
//    LCD_D6 = 1;
//    LCD_D5 = 0;
//    LCD_D4 = 0;
//
//    Delay_ms(20);
//
//    LCD_EN = 1;
//    LCD_RS = 0;
//    LCD_D7 = 1;
//    LCD_D6 = 0;
//    LCD_D5 = 0;
//    LCD_D4 = 0;
//    /* Write data to CGRAM/DDRAM */
//
///*     LCD_RS=0;
//     Delay_ms(50);
//     LCD_EN=1;
//
//     if (column >= 0xff) {
//         return;
//     }
//
//     if(row == 1){
//         d = 0x80 + column;
//     } else if (row == 2){
//         d = 0xC0 + column;
//     } else {
//         return;
//     }
//
//     LCD_EN = 0;
//     Delay_ms(50);
//     LCD_EN = 1;
//
//     LCD_RS = 1;
//     d = out_char;
//     LCD_EN = 0;
//     Delay_ms(50);
//     LCD_EN = 1;   */
//}
///*
//void LcdOut(char row, char column, char* txt)
//{
//    char loop=0;
//    char tempCol = column;
//    char temp;
//
//    while('\0' != txt[loop])
//    {
//     LCD_EN = 1;
//     LCD_RS = 1;
//        temp = txt[loop];
//        LcdChr(row, tempCol, temp);
//        tempCol++;
//        loop++;
//    }
//}
//*/
//void main()
//{
//    initLCD();
//    Lcd_Init();
//    while(1)
//    {
//        LcdChr();
//        Delay_ms(1020);
//    }
//}