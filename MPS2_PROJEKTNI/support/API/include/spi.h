#ifndef _SPI_H_
#define _SPI_H_

#include "../../hw/include/spi_hw.h"

#define MASTER_MODE_0 (SPI_INTR_EN | SPI_EN | SPI_MSB | SPI_MASTER | SPI_SCK_IDLE_L | SPI_SCK_PHASE_L | SPI_CLK_RATE_1)

void SPIInit(char spcrVal);
unsigned char SPI_ReadByte(unsigned char _data);
void SPI_WriteByte(unsigned char _data);

#endif