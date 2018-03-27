#include "../include/mcp3204.h"
#include "spi.h"

unsigned int cmd;
extern sfr sbit MCP3204_CS;

void ADCInit(unsigned char mode, unsigned char channel)
{
    MCP3204_Init(mode, channel);
    //SPI_Init();
}
/*
void MCP3204_SetMode(unsigned char mode)
{
     cmd &= 0xfdff;
     cmd |= mode << 9;
}
*/
void MCP3204_SetChannel(unsigned char channel)
{
     cmd &= 0xfe3f;
     cmd |= channel << 6;
}

unsigned int MCP3204_GetSample()
{
    unsigned int read;
    unsigned char read_h;
    unsigned char read_l;

    MCP3204_CS = 0;
    SPI_ReadByte(cmd >> 8);
    read_h = SPI_ReadByte(cmd) & 0x0f;
    read_l = SPI_ReadByte(0);
    MCP3204_CS = 1;

    read = (read_h << 8) | read_l;

    return read;
}
