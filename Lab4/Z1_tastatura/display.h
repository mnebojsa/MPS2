#ifndef _DISPLAY_H_
#define _DISPLAY_H_

// Sets the mode of the 7-segment display
// mode = COMMON_ANODE -> displays with common anode are used
// mode = COMMON_CATHODE -> displays with common cathode are used
// Usage: setMode(COMMON_CATHODE); -> sets the displays to work in common cathode mode
void setMode(char mode);

// Displays the specified value (must be in range 0-9) at the specified position (must be in range 0-3)
// Usage: setDigit(6, 3); -> displays the number 6 on the display at the position 3
void setDigit(char value, char position);

// Clears (turns off) the display at the specified position
// Usage: clearDigit(3); -> clears the digit on the display at the position 3
void clearDigit(char position);


void InitDisplay();

// Prikazuje 4-cifren broj na display-u pomocu multipleksiranja
// Potrebno je da se funkcija poziva periodicno u beskonacnoj petlji
void showNumber(int n);

#endif