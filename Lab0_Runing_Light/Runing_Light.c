unsigned char LEDS at P0;
bit directionFlag;

void main()
{
     // turn off all diodes exept the first one
     LEDS = 0x01;
     // set the initial direction
     directionFlag = 1;
     while(1)
     {
             if (directionFlag)
                LEDS = LEDS << 1;
             else
                 LEDS = LEDS >> 1;
             if (LEDS == 0x80)
                directionFlag = 0;
             if (LEDS == 0x01)
                directionFlag = 1;
             Delay_ms(100);
     }
}