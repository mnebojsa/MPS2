sbit TASTER	at P3_2_bit;
bit buttonPress;
unsigned char LEDS at P0;
bit directionFlag;
void InitMCU()
{
     // turn off all LEDS
     P0 = 0x00;
     // define BUTTON pin as input
     TASTER = 1;
     // clear the flag buttonPress
     buttonPress = 0;
     // turn off all diodes exept the first one
     LEDS = 0x01;
     // set the initial direction
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
                         if (directionFlag)
                            LEDS = LEDS << 1;
                         else
                             LEDS = LEDS >> 1;
                         if (LEDS == 0x80)
                            directionFlag = 0;
                         if (LEDS == 0x01)
                            directionFlag = 1;
                         buttonPress = 1;
                      }
            }
            else
            {
                buttonPress = 0;
            }
    }
}