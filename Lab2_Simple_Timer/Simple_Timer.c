char LEDS at P0;
volatile char count;
long prescaler;

void InitMCU()
{
    // set initial count value
    count = 0;
    // set prescaler to obtain 500ms period
    prescaler = 5000;
    // set timer 0 (gate disable, interval timer, auto-reload mode)
    TMOD = 0x02;
    // set auto-reload value to get 100us base tick
    TH0 = 136;
    // enable interrupts (sets EA and ET0)
    IE = 0x82;
    // run the timer
    TR0_bit = 1;
}

void main()
{
    // Initialize the uC
    InitMCU();

	while(1)
    {
		LEDS = count;
    }
}

void count_up() iv IVT_ADDR_ET0 {
	static long ticks = 0;

	if (ticks++ >= prescaler)
    {
		count++;
        ticks = 0;
    }
}