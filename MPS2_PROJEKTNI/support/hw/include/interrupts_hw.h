#ifndef _INTERRUPTS_HW_H_
#define _INTERRUPTS_HW_H_

#define _CLEAR_INTR_REG    (0X00)
#define _ENABLE_INTERRUPTS (0X80)
#define _EXTERN_0_INTR     (0x87)

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
void intrEnHw(char arg);
char takeRegVal(char reg);

#endif