#include "../include/spi_hw.h"

void SPIInitHW(char spcrVal)
{
    SPCR = 0x00;
    SPCR |= spcrVal;
}
