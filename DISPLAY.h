/*
 * DISPLAY.h
 *
 * Author : difer_valencia
 */ 

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <avr/io.h>
#include <util/delay.h>

void POINT(int A); /*indicates the digit that uses a decimal point, if you are not going to use a decimal point, put a 0*/
void DISP_init(); /*initialize the displays on ports B for segments and C for each display*/
void DISP_SHOW(int M); /*shows the number on the display with a maximum 4 digits*/

#endif