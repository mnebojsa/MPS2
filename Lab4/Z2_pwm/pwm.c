#include "pwm.h"

extern sfr sbit PWM_pin;
unsigned char duty;

void InitTimer()
{
     +  vg7+ // set timer 1 (gate disable, interval timer, mode 1)
    TMOD = 0x10;
    // set counter registers to the current duty
    TL1 = duty;
        TH1 = 255;
    // enable interrupts (sets EA and ET1)
    IE |= 0x88;
}

void InitPwm()
{
        // Initialize the 0% duty factor
        duty = 0;
        InitTimer();
}

void SetPwm(unsigned char pwm_duty)
{
        duty = pwm_duty;
}

void StartPwm()
{
        TR1_bit = 1;
}

void StopPwm()
{
        TR1_bit = 0;
}

void Timer1_ISR() iv IVT_ADDR_ET1 {
        // Stop the timer
        TR1_bit = 0;
        
        // Set the higher counter register
        TH1 = 255;
        
        if (PWM_pin)
    {
                PWM_pin = 0;
                TL1 = 255 - duty;
    }
        else
        {
                PWM_pin = 1;
                TL1 = duty;
        }
        
        // Start the timer
        TR1_bit = 1;
}