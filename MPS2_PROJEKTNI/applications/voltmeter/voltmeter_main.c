#include "../include/voltmeter.h"

/******************************************************************************
 *                  defines
 /****************************************************************************/
#define REFRESH_TIME (1000)   /*  1000 [ms]  */

/******************************************************************************
 *                 extern varivables
 /****************************************************************************/
extern volatile char scale;
//extern bit signalLed at P0_0_bit;
/******************************************************************************
 *                 global varivables
 ******************************************************************************/
bit test at P0_1_bit;

int main()
{
    /* mesuredVal is variable used to accept mesured val sent from ADC */
//    float mesuredVal;
    /* Initialise all modules used for voltmeter */
    initVoltmeter();
    test = 0;
    while(1)
    {
        /* do the mesuring */
//        mesuredVal = mesProccess(&scale);
        /* if REFRESH_TIME is passed since last display refres - refresh the disp*/
//        if (1 == refreshDisplayTime(REFRESH_TIME))
        {
//            dispVoltage(mesuredVal, scale);
//            test= ~test;
//            delay_MS(1000);
        }
    }
    return 0;
}

