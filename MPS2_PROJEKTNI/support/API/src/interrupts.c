#include "../include/interrupts.h"

static InterruptFxn pt2Handler[4] = {(void*)0, (void*)0, (void*)0, (void*)0};

void registerIntrEx0(InterruptFxn arg)
{
    pt2Handler[0] = arg;
}

void registerIntrEx1(InterruptFxn arg)
{
    pt2Handler[1] = arg;
}
/*
void registerIntrTC0(InterruptFxn arg)
{
    pt2Handler[2] = arg;
}

void registerIntrTC1(InterruptFxn arg)
{
    pt2Handler[3] = arg;
}
*/

//this will be implemented in interrupts_hw.c
void intrEn(void)
{
    intrEnHw(_CLEAR_INTR_REG);
    intrEnHw(_ENABLE_INTERRUPTS);
    intrEnHw(_EXTERN_0_INTR);
}

void extIntr0() iv IVT_ADDR_EX0 ilevel 0 ics ICS_AUTO
{
    char regVal;
    regVal = takeRegVal(IE);
    IE = 0;
    //intrEnHw(_CLEAR_INTR_REG);
    pt2Handler[0]();
    IE = regVal;
}

void extIntr1() iv IVT_ADDR_EX1 ilevel 0 ics ICS_AUTO
{
    char regVal;
    regVal = takeRegVal(IE);
    IE = 0;
    pt2Handler[1]();
    IE = regVal;
}

