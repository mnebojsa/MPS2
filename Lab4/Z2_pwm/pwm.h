#ifndef _PWM_H_
#define _PWM_H_

// Used to initialize the timer 1 for work in PWM mode
void InitPwm(void);

// Sets the PWM duty factor in the range 0 (0%) to 255 (100%)
// Usage:
//		SetPwm(127); -> sets approx. 50% duty factor
void SetPwm(unsigned char pwm_duty);

// Runs the PWM
void StartPwm(void);

// Stops the PWM
void StopPwm(void);

#endif