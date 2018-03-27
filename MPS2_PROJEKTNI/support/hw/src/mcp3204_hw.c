//#include "../include/mcp3204_hw.h"

extern sfr sbit MCP3204_CS;
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