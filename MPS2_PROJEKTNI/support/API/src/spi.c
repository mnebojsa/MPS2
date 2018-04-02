#include "../include/spi.h"

void InitSPI(char spcrVal)
{
    SPIInitHW(spcrVal);
}

unsigned char SPI_ReadByte(unsigned char _data)
{
    SPDR = _data;
    while(SPIF_bit == 0);
    return SPDR;
}

void SPI_WriteByte(unsigned char _data)
{
        // put here the code for writing the byte that will be exchanged during the SPI transaction
}