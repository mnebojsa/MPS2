#line 1 "D:/Fax/VIII Semestar/MPS II/zzz_git_labs/Lab1_Simple_Taster/Simple_Taster2.c"
sbit TASTER at P3_2_bit;
sbit LED at P0_0_bit;
int delay_option;
bit buttonPress;

void InitMCU()
{

 P0 = 0x00;

 TASTER = 1;

 buttonPress = 0;
 delay_option = 0;
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
