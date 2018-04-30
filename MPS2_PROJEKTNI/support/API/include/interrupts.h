#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

// IE register defines
#define _CLEAR_INTR_REG     (0X00)
#define _EN_INTR            (0X80)
#define _EN_SERIAL_INTR     (0X10)
#define _EN_TC1_INTR        (0X08)
#define _EN_EX_1_INTR       (0X04)
#define _EN_TC0_INTR        (0X02)
#define _EN_EX_0_INTR       (0X01)



//void intrEnHw(char arg);
char takeRegVal(char reg);
/**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
typedef void (*InterruptFxn)(void);

/**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
void idata intrEn(char IEval);

/**
 * @brief
 * The function allocates argc number of buffers. It filles buffers with
 * file content.
 * It should be called before any other API function.
 *
 * @param [IN] - argc - Number of file names in argv param
 * @param [IN] - argv - Array of file names
 *
 * @ret [CGuidelines_Handle]
 * Handle to CGuidelines object or null if any of argv files can not be opened
 * or if argc is less or equal to 0
 */
void idata registerIntrEx0(InterruptFxn arg);
void idata registerIntrEx1(InterruptFxn arg);
void idata registerIntrTC0(InterruptFxn arg);
void idata registerIntrTC1(InterruptFxn arg);
#endif