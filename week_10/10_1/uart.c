#include "uart.h"

void UART_Config(unsigned long baudrate)
{
	// put your UART initialization code here
}

short UART_IsRXComplete()
{
    if(RI_bit)
		return 1;
    else
		return 0;
}

short UART_IsTXEmpty()
{
    if(TI_bit)
		return 1;
    else
		return 0;
}

char UART_GetChar()
{
    RI_bit = 0;
	return SBUF;
}

void UART_PutChar(char _data)
{
	TI_bit = 0;
	SBUF = _data;
}

void UART_PutString(char* buffer)
{
    while((*buffer) != '\0')
    {
        UART_PutChar(*buffer);
        while(!UART_IsTXEmpty());
        buffer++;
    }
}