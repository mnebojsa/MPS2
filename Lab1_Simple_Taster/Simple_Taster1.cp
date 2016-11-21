#line 1 "D:/Fax/VIII Semestar/MPS II/zzz_git_labs/Lab1_Simple_Taster/Simple_Taster1.c"
sbit TASTER at P3_2_bit;
bit buttonPress;
unsigned char LEDS at P0;
bit directionFlag;
void InitMCU()
{

 P0 = 0x00;

 TASTER = 1;

 buttonPress = 0;

 LEDS = 0x01;

 directionFlag = 1;
}

void main()
{

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
