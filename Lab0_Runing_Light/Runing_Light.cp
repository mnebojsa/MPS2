#line 1 "D:/Fax/VIII Semestar/MPS II/zzz_git_labs/Lab0_Runing_Light/Runing_Light.c"
unsigned char LEDS at P0;
bit directionFlag;

void main()
{

 LEDS = 0x01;

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
