sbit TASTER at P3_2_bit;
unsigned char LEDS at P0;
bit directionFlag;
int delay_option;
bit buttonPress;

void InitMCU()
{
    // turn off all LEDS
    P0 = 0x01;
    // define BUTTON pin as input
    TASTER = 1;
    // clear the flag buttonPress
    buttonPress = 0;
    delay_option = 0;
    directionFlag = 1;
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
	
	if (directionFlag)
	{
	   LEDS = LEDS << 1;
	}
	else
	{
	    LEDS = LEDS >> 1;
        }

        switch(delay_option)
        {
            case 0 : Delay_MS(250);
                 break;
            case 1 : Delay_MS(500);
                 break;
            case 2 : Delay_MS(1000);
                 break;
        }

        if (LEDS == 0x80)
        {
           directionFlag = 0;
        }
	if (LEDS == 0x01)
	{
	   directionFlag = 1;
        }

    }
}