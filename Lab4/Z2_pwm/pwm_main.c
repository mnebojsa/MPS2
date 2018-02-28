#include "pwm.h"

sbit TASTER	at P3_5_bit;
sbit PWM_pin at P0_0_bit;
bit buttonPress;
unsigned char intensity;

void InitMCU()
{
    // Initialize input pin
	TASTER = 1;
	buttonPress = 0;
	// Initialize the PWM module
	InitPwm();
	// Set the initial intensity (to 50%)
	intensity = 127;
	SetPwm(intensity);
	// Start the PWM module
	StartPwm();
}

void main()
{
    // Initialize the uC
    InitMCU();

	while(1)
    {
		if(TASTER == 0)
		{
			if (buttonPress == 0)
			{
				if(250 >= intensity)
				{
          				intensity += 10;
          				SetPwm(intensity);
          				buttonPress = 1;
				}
			}
		}else
		{
		     buttonPress = 0;
		}
    }
}