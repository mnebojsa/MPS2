#include "../include/spi.h"

void idata initSPI(char spcrVal)
{
    SPCR = spcrVal;
}

char SPI_ByteTransfer(char _data)
{
    char regVal;
    regVal = IE;
    SPDR = _data;
    IE = regVal & 0b01111111;
    while(SPIF_bit == 0);
    IE = regVal | 0b10000000;
    return SPDR;
}