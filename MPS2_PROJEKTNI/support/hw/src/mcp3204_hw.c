#include "../include/mcp3204_hw.h"

sbit MCP3204_CS at P3_5_bit;
unsigned int cmd;

void MCP3204_Init(unsigned char mode, unsigned char channel)
{
    MCP3204_CS = 1;
    cmd = (mode << 9) | (channel << 6) | 0x0400;
}

void MCP3204_SetMode(unsigned char mode)
{
     cmd &= 0xfdff;
     cmd |= mode << 9;
}

void MCP3204_SetChannel(unsigned char channel)
{
     cmd &= 0xfe3f;
     cmd |= channel << 6;
}

int MCP3204_GetSample(void)
{
    int readVal;
    unsigned char read_h;
    unsigned char read_l;

    MCP3204_CS = 0;
    //8 konfiguracionih bita -. konfiguracija se radi za svaki transfer-tome sluzi cmd
    SPI_ReadByte(cmd >> 8);
    //4 prazna i 4 bitna bita 0f=0000 1111
    //ovde se salje cmd adc-u, a rima se byte podataka... nosi li cmd info
    read_h = SPI_ReadByte(cmd) & 0x0f;
    //8 bitnih bita ... strana 16
    read_l = SPI_ReadByte(0);
    MCP3204_CS = 1;

    readVal = (read_h << 8) | read_l;
    
    return readVal;
}