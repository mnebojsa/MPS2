#include "../include/ADConv.h"
#include "../include/spi.h"

sbit MCP3204_CS at P3_5_bit;
int cmd;

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

float MCP3204_GetSample(void)
{
    int readVal;
    float retVal;
    char read_h;
    char read_l;

    MCP3204_CS = 0;
    //8 konfiguracionih bita -. konfiguracija se radi za svaki transfer-tome sluzi cmd
    SPI_ByteTransfer(cmd >> 8);
    //4 prazna i 4 bitna bita 0f=0000 1111
    //ovde se salje cmd adc-u, a rima se byte podataka... nosi li cmd info
    read_h = SPI_ByteTransfer(cmd) & 0x0f;
    //8 bitnih bita ... strana 16
    read_l = SPI_ByteTransfer(0);
    MCP3204_CS = 1;

    readVal = (read_h << 8) | read_l;
    MCP3204_CS = 0;
    retVal = readVal * DELTA_VAL;
    
    return retVal;
}

void boost()
{   char temp;
    MCP3204_CS = 0;
    //for(temp =1;temp<25;temp++);
    MCP3204_CS = 1;
}