#include "../include/spi.h"

void SPIInit(char spcrVal)
{
    SPIInitHW(spcrVal);
}

unsigned char SPI_ReadByte(unsigned char _data)
{
         SPDR = _data;
         //P3_5_bit = 0;
         while(SPIF_bit == 0);
         //P3_5_bit = 1;
         return SPDR;
         //char value = SPSR >> 7;
}

void SPI_WriteByte(unsigned char _data)
{
        // put here the code for writing the byte that will be exchanged during the SPI transaction
}