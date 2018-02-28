#ifndef _KEYPAD_H_
#define _KEYPAD_H_

// returns:
// 0xFF -> Ako nista nije stisnuto
// 0 - 9 -> Stisnuti tasteri 0 - 9
// 10 - 13 -> Stisnuti tasteri A - D
// 14 - Taster *
// 15 - Taster #
char scanKeypad();


#endif