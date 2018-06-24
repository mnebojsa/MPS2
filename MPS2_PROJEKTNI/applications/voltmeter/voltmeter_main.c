#include "voltmeter.h"

/******************************************************************************
 *                  defines
 *****************************************************************************/
#define REFRESH_TIME (1000)   /*  1000 [ms]  */

/******************************************************************************
 *                 extern varivables
 ****************************************************************************/
extern volatile char scale;

/******************************************************************************
 *                 global varivables
 ******************************************************************************/

int main()
{
    //mesuredVal is variable used to accept mesured val sent from ADC
    float idata mesuredVal;
    static unsigned long temp;
    static unsigned long idata count;
    
    //Initialise all modules used for voltmeter
    initVoltmeter();

    while(1)
    {
        //do the mesuring
        temp = milis();
        //if REFRESH_TIME is passed since last display refres - refresh the disp
        if (REFRESH_TIME <= (temp - count))
        {
            mesuredVal = mesProccess(&scale);
            count = temp;
            dispVoltage(mesuredVal, scale);
        }
    }
    return 0;
}