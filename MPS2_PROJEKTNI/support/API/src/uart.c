#include "uart.h"

#define fosc 10000

static int baud_rate;
static int th1_c;
static unsigned char output;

void UART_Config(unsigned long baudrate)
{
     TMOD |= 0x20;
     SCON = 0x50;
     TR1_bit = 0;
     TH1 = (int)(256 - (10000000/(12.0*32.0*baudrate)));
     TR1_bit = 1;
//   REN_bit = 1 omogucava prijem serijskih podataka
//   REN_bit = 0 onemogucava prijem serijskih podataka
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