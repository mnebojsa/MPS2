#ifndef _DISPLAY_H_
#define _DISPLAY_H_

//#define FIRST_ROW   (1)
//#define SECOND_ROW  (2)

//#include "../../hw/include/display_hw.h"

/******************************************************************************/
/* \brief   This function initialises Display. It is wrapper for              */
/*          Microelektronika init function                                    */
/*                                                                            */
/*                                                                            */
/* \param   void          No input params                                     */
/*                                                                            */
/* \return  void          No return value                                     */
/******************************************************************************/
void displayInit(void);

/******************************************************************************/
/* \brief   This function takes float value of measured value and displays it */
/*                                                                            */
/* \param   float         valToDisplay      Value that will be displayed      */
/* \param   int           scale             scale for                         */
/*                                                                            */
/* \return  void          No return value                                     */
/******************************************************************************/
void display(char row, char column, char* txt);

/******************************************************************************/
/* \brief   This function takes float value of measured value and displays it */
/*                                                                            */
/* \param   float         valToDisplay      Value that will be displayed      */
/* \param   int           scale             scale for                         */
/*                                                                            */
/* \return  void          No return value                                     */
/******************************************************************************/
void dispCmd(char* txtCmd);


#endif