#ifndef _ADCONV_H_
#define _ADCONV_H_

#include "../../hw/include/mcp3204_hw.h"
/****************************************************
*        Function used to initialize the ADC module
*
*        Arguments:
*                - mode: 0 - differential, 1 - single
*                - channel: 0-3
*
*        Returns: nothing
*****************************************************/
void InitADC(unsigned char mode, unsigned char channel);

/****************************************************
*        Function used to set the mode of the ADC module
*
*        Arguments:
*                - mode: 0 - differential, 1 - single
*
*        Returns: nothing
*****************************************************/
void ADCSetMode(unsigned char mode);

/****************************************************
*        Function used to set the channel of the ADC module
*
*        Arguments:
*                - channel: 0-3
*
*        Returns: nothing
*****************************************************/
void ADCSetChannel(unsigned char channel);

/****************************************************
*        Function used to sample voltage on the selected
*        channel of the ADC module
*
*        Arguments: nothing
*
*        Returns: 12-bit digital sample (0-4096)
*****************************************************/
unsigned int ADCGetSample(void);

#endif