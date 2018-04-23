#include "../include/voltmeter.h"

volatile char scale;
char* idata currScale[] ={"[mV]", "[V]", "[kV]"};
static int idata manualChange;
bit signalLed at P0_0_bit;
/*
static void idata helloMsg()
{
    char idata txt1[] = "Easy 8051";
    char idata txt2[] = "VOLTMETAR";
    char idata i;

    LcdCmd(_LCD_CLEAR);
    LcdPutString(1, 16, txt1);
    LcdPutString(2, 18, txt2);
    LcdCmd(_LCD_CURSOR_OFF);

    for(i=0; i<15; i++)
    {
        LcdCmd(_LCD_SHIFT_LEFT);
        Delay_ms(300);
    }

    Delay_ms(1000);
    LcdCmd(_LCD_CLEAR);
}
*/
void idata initVoltmeter()
{
//    manualChange = 0;
//    signalLed = 1;

//    initSPI(MASTER_MODE_0);
//    MCP3204_Init(0,0);
//    initLcd();
    intrEn();
    initTimer();
//    registerIntrEx0(incrScaleIntrHandler);
//    registerIntrEx1(decrScaleIntrHandler);
//    helloMsg();
//    signalLed = 0;
}
/*
char refreshDisplayTime(char refreshTime)
{ 
     static long count;
     if (refreshTime >= (milis() - count))
     {
         count = milis();
         return 1;
     }
     else
     {
         return 0;
     }
} */
/*
void dispVoltage(float mesuredVal, char scale)
{
    char  mesuredVal2txt[15];
    float temp;

    temp = mesuredVal;
    switch (scale)
    {
         case 0:
             temp = mesuredVal*1000.0;
             break;
         case 1:
             temp = mesuredVal;
             break;
         case 2:
             temp = mesuredVal * 0.001;
             break;
         default:
             break;
     }

     FloatToStr(temp, mesuredVal2txt);
     LcdCmd(_LCD_CLEAR);
     LcdPutString(1, 1, mesuredVal2txt);
     LcdPutString(1, 12, currScale[scale]);
     LcdCmd(_LCD_CURSOR_OFF);
}


float mesProccess(char* scale)
{
    float sample = 0.0;
    MCP3204_Init(0,0);

    sample = MCP3204_GetSample();
    if (0 == manualChange)
    {
        if (sample < 1.0)
        {
            *scale = 0;
        } 
        else if (sample >= 1.0 && sample < 1000.0)
        {
            *scale = 1;
        }
        else
        {
            *scale = 2;
        }
    }
    return sample;
}

void incrScaleIntrHandler(void)
{
     scale++;
     manualChange = 1;
     scale = scale % 3;
}

void decrScaleIntrHandler(void)
{
     scale++;
     manualChange = 1;
     scale = scale % 3;
}
*/