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

void MCP3204_CS_On()
{
    MCP3204_CS = 0;
}

void MCP3204_CS_Off()
{
    MCP3204_CS = 1;
}

unsigned int getCmd()
{
    return cmd;
}
