#ifndef _MCP3204_HW_H_
#define _MCP3204_HW_H_


/****************************************************
*        Function used to initialize the ADC module
*
*        Arguments:
*                - mode: 0 - differential, 1 - single
*                - channel: 0-3
*
*        Returns: nothing
*****************************************************/
void MCP3204_Init(unsigned char mode, unsigned char channel);

/****************************************************
*        Function used to set the mode of the ADC module
*
*        Arguments:
*                - mode: 0 - differential, 1 - single
*
*        Returns: nothing
*****************************************************/
void MCP3204_SetMode(unsigned char mode);

/****************************************************
*        Function used to set the channel of the ADC module
*
*        Arguments:
*                - channel: 0-3
*
*        Returns: nothing
*****************************************************/
void MCP3204_SetChannel(unsigned char channel);

/****************************************************
*        Function used to set the CS bit for ADC module
*
*          The CS/SHDN pin is used to initiate communication
*          with the device when pulled low and will end a conversion
*          and put the device in low power standby when
*           pulled high. The CS/SHDN pin must be pulled high
*           between conversions.
*
*        Arguments:
*
*        Returns: nothing
*****************************************************/
void MCP3204_CS_On();
void MCP3204_CS_Off();
unsigned int getCmd();

#endif