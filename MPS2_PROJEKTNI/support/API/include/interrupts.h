#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#define _CLEAR_INTR_REG    (0X00)
#define _ENABLE_INTERRUPTS (0X80)
#define _EXTERN_0_INTR     (0x00)
#define _TC0_INTR          (0x00)


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
void idata intrEn();

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