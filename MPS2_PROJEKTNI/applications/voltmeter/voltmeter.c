#include "voltmeter.h"

volatile char scale;
char* idata currScale[] ={"[mV]", "[V]", "[kV]"};
bit signalLed at P0_0_bit;

static int data manualChange;
static void helloMsg()
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
        Delay_ms(10);
    }

    Delay_ms(1000);
    LcdCmd(_LCD_CLEAR);
}

void idata initVoltmeter()
{
    char IEval;
    char masterMode0;
    manualChange = 0;
    signalLed = 1;

    IEval = _EN_INTR |           //enable interrupts
            _EN_EX_1_INTR |      //enable extern 1 interrupt
            _EN_TC0_INTR |       //enable TC0interrupts
            _EN_EX_0_INTR;

    masterMode0 = SPI_INTR_EN |
                  SPI_EN | 
                  SPI_MSB | 
                  SPI_MASTER |
                  SPI_SCK_IDLE_L |
                  SPI_SCK_PHASE_L |
                  SPI_CLK_RATE_1;
                  
    initSPI(masterMode0);
    MCP3204_Init(0,0);
    initLcd();
    intrEn(IEval);
    initTC();
    registerIntrEx0(incrScaleIntrHandler);
    registerIntrEx1(decrScaleIntrHandler);
    helloMsg();
    signalLed = 0;
}

void dispVoltage(float mesuredVal, char scale)
{
    char  mesuredVal2txt[5];
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
     sprintf(mesuredVal2txt, "%.3f", temp);
     LcdCmd(_LCD_CLEAR);
     LcdPutString(1, 1, mesuredVal2txt);
     LcdPutString(1, 12, currScale[scale]);
     LcdCmd(_LCD_CURSOR_OFF);
}

float mesProccess(char* scale)
{
    float sample = 0.0;
    MCP3204_SetChannel(0);

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
     scale += (scale < 2)?1:0;
     manualChange = 1;
}

void decrScaleIntrHandler(void)
{
     scale -=(scale > 0)?1:0;
     manualChange = 1;
}