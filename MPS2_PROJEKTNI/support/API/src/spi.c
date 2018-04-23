#include "../include/spi.h"

void idata initSPI(char spcrVal)
{
    SPCR = 0x00;
    SPCR |= spcrVal;
}

unsigned char SPI_ByteTransfer(unsigned char _data)
{
    SPDR = _data;
    while(SPIF_bit == 0);
    return SPDR;
}