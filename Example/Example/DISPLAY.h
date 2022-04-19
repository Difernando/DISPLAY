/*
 * DISPLAY.h
 *
 * Author : difer_valencia
 * Original Repository : https://github.com/Difernando/DISPLAY.git
 */ 

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <avr/io.h>
#include <avr/interrupt.h>

void DISP_init(); /*initialize the displays on ports B for segments and C for each display*/
void DISP_SHOW(float M); /*shows the number on the display with a maximum 4 digits*/

#endif