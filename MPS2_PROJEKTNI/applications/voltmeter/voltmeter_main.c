#include "../include/voltmeter.h"

/******************************************************************************
 *                     defines
 ******************************************************************************/
#define REFRESH_TIME (1000)   /*  1000 [ms]  */
#define DELTA        (0.001)  /* MINIMUM DETECT VOLTAGE */

/******************************************************************************
 *                 extern varivables
 ******************************************************************************/
extern volatile char scale;

/******************************************************************************
 *                 global varivables
 ******************************************************************************/
bit signalLed at P0_0_bit;

int main()
{
    /* variable that contains mesured value of voltage */
    //float mesuredVal;
    unsigned int mesuredVal;
    /*Initialise all modules used for voltmeter*/
    initVoltmeter();
    scale = 1;
    while(1)
    {
        mesuredVal = mesProccess(&scale);
      //  signalLed = signalLight(mesuredVal, DELTA);
      //  if (1 == refreshDisplayTime(REFRESH_TIME))
        {
            dispVoltage(mesuredVal, scale);
            delay_MS(300);
        }
    }
    return 0;
}