#include "../include/interrupts_hw.h"

void intrEnHw(char arg)
{
    IE |= arg;
}

char takeRegVal(char reg)
{
    return reg;
}