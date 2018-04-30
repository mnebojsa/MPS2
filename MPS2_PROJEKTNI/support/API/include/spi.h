#ifndef _SPI_H_
#define _SPI_H_

#define SPI_INTR_EN (0X80)
#define SPI_EN (0X40)
#define SPI_LSB (0X20)
#define SPI_MSB (0X00)
#define SPI_MASTER (0X10)
#define SPI_SLAVE (0X00)
#define SPI_SCK_IDLE_H (0X08)
#define SPI_SCK_IDLE_L (0X00)
#define SPI_SCK_PHASE_H (0X08)
#define SPI_SCK_PHASE_L (0X00)
#define SPI_CLK_RATE_0 (0X00)
#define SPI_CLK_RATE_1 (0X01)
#define SPI_CLK_RATE_2 (0X02)
#define SPI_CLK_RATE_3 (0X03)

#define MASTER_MODE_0 (SPI_INTR_EN |SPI_EN | SPI_MSB | SPI_MASTER |\
                       SPI_SCK_IDLE_L | SPI_SCK_PHASE_L | SPI_CLK_RATE_1)

void idata initSPI(char spcrVal);
unsigned char SPI_ByteTransfer(char _data);

#endif