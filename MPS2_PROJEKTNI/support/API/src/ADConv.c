#include "../include/ADConv.h"
#include "spi.h"

char  mesuredVal2txt[15];

void InitADC(unsigned char mode, unsigned char channel)
{
    MCP3204_Init(mode,channel);
}

void ADCSetMode(unsigned char mode)
{
    MCP3204_SetMode(mode);
}

void ADCSetChannel(unsigned char channel)
{
    MCP3204_SetChannel(channel);
}

unsigned int ADCGetSample()
{
    unsigned int cmd;
    unsigned int read;
    unsigned char read_h;
    unsigned char read_l;

    MCP3204_CS_On();
    cmd = getCmd();
    //8 praznih bita
    SPI_ReadByte(cmd >> 8);
    //4 prazna i 4 bitna bita 0f=0000 1111
    read_h = SPI_ReadByte(cmd) & 0x0f;
    //8 bitnih bita ... strana 16
    read_l = SPI_ReadByte(0);
    MCP3204_CS_Off();

    read = (read_h << 8) | read_l;

    return read;
}