#include "../include/interrupts.h"

static InterruptFxn pt2Handler[4] = {(void*)0, (void*)0, (void*)0, (void*)0};

void idata registerIntrEx0(InterruptFxn arg)
{
    pt2Handler[0] = arg;
}

void idata registerIntrEx1(InterruptFxn arg)
{
    pt2Handler[1] = arg;
}

void idata registerIntrTC0(InterruptFxn arg)
{
    pt2Handler[2] = arg;
}

void idata registerIntrTC1(InterruptFxn arg)
{
    pt2Handler[3] = arg;
}

void idata intrEn(char IEval)
{
    IE = IEval;
    //set priorities
    IP = 0x0a;
}

void extIntr0() iv IVT_ADDR_EX0 ilevel 0 ics ICS_AUTO
{
    char regVal;
    regVal = IE;
    IE = regVal & 0b01111111;
    pt2Handler[0]();
    IE = regVal | 0b10000000;
}

void extIntr1() iv IVT_ADDR_EX1 ilevel 0 ics ICS_AUTO
{
    char regVal;
    regVal = IE;
    IE = regVal & 0b01111111;
    pt2Handler[1]();
    IE = regVal | 0b10000000;
}

void tc0() iv IVT_ADDR_ET0 ilevel 0 ics ICS_AUTO
{
    char regVal;
    regVal = IE;
    IE = regVal & 0b01111111;
    pt2Handler[2]();
    IE = regVal | 0b10000000;
}

void tc1() iv IVT_ADDR_ET1 ilevel 0 ics ICS_AUTO
{  /*
    char regVal;
    regVal = IE;
    IE = 0;
    pt2Handler[3]();
    IE = regVal;  */
}