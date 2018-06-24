#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#define _LCD_FIRST_ROW             (0x80)
#define _LCD_SECOND_ROW            (0xC0)
#define _LCD_CLEAR                 (0x01)
#define _LCD_RETURN_HOME           (0x02)
#define _LCD_CURSOR_OFF            (0x0C)
//#define _LCD_UNDERLINE_ON          (0x00)
//#define _LCD_BLINK_CURSOR_ON       (0x00)
//#define _LCD_MOVE_CURSOR_LEFT      (0x00)
//#define _LCD_MOVE_CURSOR_RIGHT     (0x00)
//#define _LCD_TURN_ON               (0x00)
//#define _LCD_TURN_OFF              (0x00)
#define _LCD_SHIFT_LEFT            (0x18)
#define _LCD_SHIFT_RIGHT           (0x1C)

/**
 * @brief
 * This function initialises the display.
 *
 * @param [IN] - void          - No input params
 *
 * @ret [No return value]
 */
void idata initLcd(void);

/**
 * @brief
 * This function is used to set cursor possition on the display
 *
 * @param [IN] - char row     -row coordinate of display where txt is printed
 * @param [IN] - char column  -colmun coordinate of display where txt is printed
 *
 * @ret [No return value]
 */
void LcdSetCursor(char row, char colmun);

/**
 * @brief
 * This function prints character, given as input, on the current cursor 
 * possition on the display
 *
 * @param [IN] - char chr    -Value that will be displayed
 *
 * @ret [No return value]
 */
void LcdPutChar(char chr);
/**
 * @brief
 * This function takes prints string, given as input, on the display
 *
 * @param [IN] - char row     -row coordinate of display where txt is printed
 * @param [IN] - char column  -colmun coordinate of display where txt is printed
 * @param [IN] - char* txt    -Value that will be displayed
 *
 * @ret [No return value]
 */
void LcdPutString(int row, int column, char* txt);

/**
 * @brief
 * This function takes commands offten needed when using display. Commands 
 * available are :  _LCD_FIRST_ROW
 *                  _LCD_SECOND_ROW
 *                  _LCD_CLEAR
 *                  _LCD_RETURN_HOME
 *                  _LCD_CURSOR_OFF
 *                  _LCD_UNDERLINE_ON
 *                  _LCD_BLINK_CURSOR_ON
 *                  _LCD_MOVE_CURSOR_LEFT
 *                  _LCD_MOVE_CURSOR_RIGHT
 *                  _LCD_TURN_ON
 *                  _LCD_TURN_OFF
 *                  _LCD_SHIFT_LEFT
 *                  _LCD_SHIFT_RIGHT
 *
 * @param [IN] - char txtCmd    -symbolic command
 *
 * @ret [No return value]
 */
void LcdCmd(char txtCmd);

#endif