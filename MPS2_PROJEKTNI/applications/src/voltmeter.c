#include "../include/voltmeter.h"

volatile char scale;
char* currScale[]={"[uV]", "[mV]", "[V]", "[kV]"};
static int manualChange;

//FINISHED
static void helloMsg()
{
    char txt1[] = "Easy 8051";
    char txt2[] = "VOLTMETAR";
    char i;
  
    dispCmd(_LCD_CLEAR);
    display(1, 3, txt2);               // Write text in first row
    display(2, 5, txt1);
    dispCmd(_LCD_CURSOR_OFF);

  for(i=0; i<2; i++)
  {                         // Endless loop
    for(i=0; i<3; i++) {             // Move text to the left 7 times
      dispCmd(_LCD_SHIFT_RIGHT);
      Delay_ms(500);
    }

    for(i=0; i<5; i++) {             // Move text to the right 7 times
      dispCmd(_LCD_SHIFT_LEFT);
      Delay_ms(500);
    }

    for(i=0; i<2; i++) {             // Move text to the left 7 times
      dispCmd(_LCD_SHIFT_RIGHT);
      Delay_ms(500);
    }
  }

    dispCmd(_LCD_CLEAR);
    display(1, 3, txt2);               // Write text in first row
    display(2, 5, txt1);
    dispCmd(_LCD_CURSOR_OFF);
    
    Delay_ms(1000);
}

//FINISHED
void initVoltmeter()
{
    manualChange = 0;
    /* set initial count value   */
    //InitTimer();
    InitSPI(MASTER_MODE_0);
    InitADC(0,0);
    displayInit();
    intrEn();
    registerIntrEx0(incrScale);
    registerIntrEx1(decrScale);
    //helloMsg();
}

char refreshDisplayTime(char refreshTime)
{    static long count;
     if (refreshTime >= (milis() - count))
     {
         count = milis();
         return 1;
     } else
     {
         return 0;
     }

}

void dispVoltage(unsigned int mesuredVal, char scale)
{
     char  mesuredVal2txt[15];
     float temp = (float)mesuredVal;
     //unsigned int temp;
     //temp = mesuredVal;
/*     switch (scale)
     {
         case 0:
             temp = mesuredVal*1000000.0;
             break;
         case 1:
             temp = mesuredVal*1000.0;
             break;
         case 2:
             temp = mesuredVal;
             break;
         case 3:
             temp = mesuredVal*0.001;
             break;
         default:
             temp = mesuredVal;
             break;
     }  */

     //FloatToStr(temp, mesuredVal2txt);
     WordToStr((unsigned int)temp, mesuredVal2txt);
     dispCmd(_LCD_CLEAR);
     display(1, 3, mesuredVal2txt);
     Lcd_Out_Cp(" ");
     Lcd_Out_Cp(currScale[scale]);
     dispCmd(_LCD_CURSOR_OFF);
}


unsigned int mesProccess(char* scale)
{
     //float temp = 0.000254;
     unsigned int sample;
     
     ADCSetChannel(0);
     sample = ADCGetSample();
    /* if (0 == manualChange)
     {
         if (temp < 0.001)
         {
            *scale = 0;
         }*/ /*else if (temp >= 0.001 && temp < 1)
         {
             *scale = 1;
         } else if (temp >= 1 && temp < 1000)
         {
             *scale = 2;
         } else
         {
             *scale = 3;
         }
     } */
     return sample;
     //return 21;
}

char signalLight(float mesuredVal, float DELTA)
{
    char temp;
    temp =(DELTA <= mesuredVal)?'1':'0';
    return temp;
}

void incrScale()
{
     scale++;
     manualChange = 1;
     P0_0_bit = 0;
     scale = scale % 4;
}

void decrScale()
{
     scale++;
     manualChange = 1;
     P0_0_bit = 1;
     scale = scale % 4;
}