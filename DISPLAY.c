/*
 * DISPLAY.c
 *
 * Author : difer_valencia
 */ 

#include "DISPLAY.h"
const char TABLE[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07, 0x7F, 0x6F};
const char TABLED[] = {0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87, 0xFF, 0xEF};
uint8_t DC = 0;
uint8_t PDC = 0;
uint8_t STATE = 0;
uint8_t N1;
uint8_t N2;
uint8_t N3;
uint8_t N4;
void POINT(int A){
	#warning "use the number betwwen 0 - 4"
	if(A == 0){
		DC = 0;
	}
	if(A!=0){
		DC = 1;
		PDC = A;
	}
	STATE = DC*PDC;
}
void DISP_init(){
	DDRC |= (1<<0x00)|(1<<0x01)|(1<<0x02)|(1<<0x03);
	PORTC |= (1<<0x00)|(1<<0x01)|(1<<0x02)|(1<<0x03);
	DDRB = 0xFF;
	PORTB = 0x00;
}
void DISP_SHOW(int M){	
	if(M < 10){
		N1 = M;
		PORTC&=~(1<<0x00);
		if(STATE == 1){
			PORTB = TABLED[N1];
			}else{			
			PORTB = TABLE[N1];
		}
	}
	if(M >= 10 && M < 100){
		N1 = M/10;
		N2 = M%10;
		PORTC&=~(1<<0x00);
		if(STATE == 1){
			PORTB = TABLED[N1];
			}else{			
			PORTB = TABLE[N1];
		}
		_delay_us(100);
		PORTC|=(1<<0x00);
		PORTB = 0x00;
		PORTC&=~(1<<0x01);
		if(STATE == 2){
			PORTB = TABLED[N2];
			}else{			
			PORTB = TABLE[N2];
		}
		_delay_us(100);
		PORTC|=(1<<0x01);
		PORTB = 0x00;
	}
	if(M>=100 && M <1000){
		N1 = M/100;
		N2 = (M/10)%10;
		N3 = M%10;
		PORTC&=~(1<<0x00);
		if(STATE == 1){
			PORTB = TABLED[N1];
			}else{			
			PORTB = TABLE[N1];
		}
		_delay_us(100);
		PORTC|=(1<<0x00);
		PORTB = 0x00;
		PORTC&=~(1<<0x01);
		if(STATE == 2){
			PORTB = TABLED[N2];
			}else{			
			PORTB = TABLE[N2];
		}
		_delay_us(100);
		PORTC|=(1<<0x01);
		PORTB = 0x00;
		PORTC&=~(1<<0x02);
		if(STATE  == 3){
			PORTB = TABLED[N3];
			}else{			
			PORTB = TABLE[N3];
		}
		_delay_us(100);
		PORTC|=(1<<0x02);
		PORTB = 0x00;
	}
	if(M>=1000 && M < 10000){
		N1 = M/1000;
		N2 = (M/100)%10;
		N3 = (M/10)%10;
		N4 = M%10;
		PORTC&=~(1<<0x00);
		if(STATE  == 1){
			PORTB = TABLED[N1];
			}else{			
			PORTB = TABLE[N1];
		}
		_delay_us(110);
		PORTC|=(1<<0x00);
		PORTB = 0x00;
		PORTC&=~(1<<0x01);
		if(STATE  == 2){
			PORTB = TABLED[N2];
			}else{			
			PORTB = TABLE[N2];
		}
		_delay_us(110);
		PORTC|=(1<<0x01);
		PORTB = 0x00;
		PORTC&=~(1<<0x02);
		if(STATE == 3){
			PORTB = TABLED[N3];
			}else{			
			PORTB = TABLE[N3];
		}
		_delay_us(110);
		PORTC|=(1<<0x02);
		PORTB = 0x00;
		PORTC&=~(1<<0x03);
		if(STATE == 4){
			PORTB = TABLED[N4];
			}else{			
			PORTB = TABLE[N4];
		}
		_delay_us(110);
		PORTC|=(1<<0x03);
		PORTB = 0x00;
	}
}