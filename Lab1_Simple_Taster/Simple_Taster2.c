sbit TASTER at P3_2_bit;
sbit LED at P0_0_bit;
int delay_option;
bit buttonPress;

void InitMCU()
{
    // turn off all LEDS
    P0 = 0x00;
    // define BUTTON pin as input
    TASTER = 1;
    // clear the flag buttonPress
    buttonPress = 0;
    delay_option = 0;
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
            delay_option = (delay_option++)%2;
            buttonPress = 1;
          }
        }
        else
        {
            buttonPress = 0;
        }
        LED = ~LED;
        switch(delay_option)
        {
               case 0 : Delay_MS(250);
                    break;
               case 1 : Delay_MS(500);
                    break;
               case 2 : Delay_MS(1000);
                    break;
        }
    }
}