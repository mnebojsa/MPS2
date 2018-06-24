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
    
    MCP3204_CS = 1;
    MCP3204_CS = 0;
    //variable given as argument is command sent to AD convertor
    //value recived rom convertor is always return value  from SPI_BTransfer func
    //configuration byte is sent for each transfer
    SPI_ByteTransfer(cmd >> 8);
    //AD convertor gives back 12 bit information in two steps.
    //First step - 4 higher bits of sample value - 0f=0000 1111
    read_h = SPI_ByteTransfer(cmd) & 0x0f;
    //2nd step - 8 lower bits of information are recived, no command is sent to
    read_l = SPI_ByteTransfer(0);
    MCP3204_CS = 1;

    readVal = (read_h << 8) | read_l;
    MCP3204_CS = 0;
    retVal = readVal * DELTA_VAL;
    
    return retVal;
}