#ifndef _MCP3204_H_
#define _MCP3204_H_


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

#endif