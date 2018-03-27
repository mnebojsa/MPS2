#include "../include/display_hw.h"

 /* Lcd module connections  */
unsigned char d at P0;


void setDisplay()
{
    LCD_EN = 1;
    LCD_RS = 0;

/* brisemo sadrzaj displeja       */
    Delay_ms(50);
    d = 0x01;
    LCD_EN = 0;
    Delay_ms(90);
    LCD_EN = 1;

/*  podesavamo displej da radi kao dvoredni u 8 bitnom   */
    Delay_ms(50);
    d = 0x38;
    LCD_EN = 0;
    Delay_ms(50);
    LCD_EN = 1;

//ukljucujemo displej i kursor
    d = 0x0f;
    LCD_EN = 0;
    Delay_ms(50);
    LCD_EN = 1;

    LCD_EN=1;
}
