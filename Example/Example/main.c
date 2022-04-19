/*
 * Ejemplo.c
 *
 * Author : difer
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "DISPLAY.h"
float H = 54.32;
int Z = 4;

int main(void)
{	
	DISP_init();
	while (1)
	{
		DISP_SHOW(Z);
	}
}


