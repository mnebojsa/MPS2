#line 1 "D:/Fax/VIII Semestar/MPS II/zzz_git_labs/Lab2_Simple_Intterupts/Simple_Interrupts.c"
bit LEDS at P0_0_bit;
volatile char count;

void InitMCU()
{
 P0 = 0xFF;

 count = 0;

 IT0_bit = 1;
 IT1_bit = 1;

 IE = 0x85;
}

void main()
{

 InitMCU();

 while(1)
 {
 LEDS = ~LEDS;
 switch(count)
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

void btn_up() iv IVT_ADDR_EX0
{
 count++;
 if(count > 2)
 {
 count = 2;
 }
}

void btn_down() iv IVT_ADDR_EX1 {
 count--;
 if(count <= 0)
 {
 count = 0;
 }
}
