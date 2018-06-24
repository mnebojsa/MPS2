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

typedef void (*InterruptFxn)(void);

/**
 * @brief
 * The function is used to enable interrupts globali. It sets value of IE reg
 *
 * @param [IN] - char IEval -value to be written into IE reg
 *
 * @ret [No return value]
 */
void idata intrEn(char IEval);

/**
 * @brief
 * Interrupt register functions - used to register applications specific
 * functions to interrupt routines available
 *
 * @param [IN] - InterruptFxn arg - function to be called when interrupt happends
 *
 * @ret [No return value]
 */
void idata registerIntrEx0(InterruptFxn arg);
void idata registerIntrEx1(InterruptFxn arg);
void idata registerIntrTC0(InterruptFxn arg);
void idata registerIntrTC1(InterruptFxn arg);

#endif