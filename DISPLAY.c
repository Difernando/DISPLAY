/*
 * DISPLAY.c
 *
 * Author : difer_valencia
 * Original Repository : https://github.com/Difernando/DISPLAY.git
 */ 

#include "DISPLAY.h"
const char _TABLE_[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07, 0x7F, 0x6F};
const char _TABLED_[] = {0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87, 0xFF, 0xEF};
	float _M_=0;
	float _CD1_ = 0;
	int _control_ = 0;
	int _CD2_ = 0;
	
uint8_t _STATE_ = 0;
uint8_t _DC_ = 0;
uint8_t _N1_;
uint8_t _N2_;
uint8_t _N3_;
uint8_t _N4_;
void DISP_init(){
	cli();
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS00)|(1<<CS02);
	TIMSK0 |= (1<<OCIE0A);
	OCR0A = 0x09;
	
	DDRC |= (1<<0x00)|(1<<0x01)|(1<<0x02)|(1<<0x03);
	PORTC |= (1<<0x00)|(1<<0x01)|(1<<0x02)|(1<<0x03);
	DDRB = 0xFF;
	PORTB = 0x00;	
	DDRD|=(1<<0x00);
	sei();
}
void DISP_SHOW(float _N_){
	if(_N_<10.0){
		_M_ = _N_*1000.0;
		_DC_ = 1;
	}
	if(_N_>=10.0 && _N_ < 100.0){
		_M_ = _N_ *100.0;
		_DC_ = 2;
	}
	if(_N_>=100.0 && _N_<1000.0){
		_M_ = _N_ * 10.0;
		_DC_ = 3;
	}
	if(_N_>=1000.0){
		_M_ = _N_;
		_CD1_ = _N_ * 10.0;
		_CD2_ = (int) _CD1_;
		_control_ = _CD2_%10;
		if(_control_>0){
			_DC_ = 4;
		}
		if(_control_==0){
			_DC_ = 0;
		}			
	}

		_N1_ =(int) _M_/1000;
		_N2_ =(int) (_M_/100)%10;
		_N3_ =(int) (_M_/10)%10;
		_N4_ =(int) _M_%10;
		switch(_STATE_){
			case 0:
			PORTC&=~(1<<0x00);
			if(_DC_ == 1){
				PORTB = _TABLED_[_N1_];
			}else{
				PORTB = _TABLE_[_N1_];
			}
			break;
			case 1:
			PORTC|=(1<<0x00);
			PORTB = 0x00;
			PORTC&=~(1<<0x01);
			if(_DC_ == 2){
				PORTB = _TABLED_[_N2_];
				}else{
				PORTB = _TABLE_[_N2_];
			}
			break;
			case 2:
			PORTC|=(1<<0x01);
			PORTB = 0x00;
			PORTC&=~(1<<0x02);
			if(_DC_ == 3){
				PORTB = _TABLED_[_N3_];
				}else{
				PORTB = _TABLE_[_N3_];
			}
			break;
			case 3:
			PORTC|=(1<<0x02);
			PORTB = 0x00;
			PORTC&=~(1<<0x03);
			if(_DC_ == 4){
				PORTB = _TABLED_[_N4_];
				}else{
				PORTB = _TABLE_[_N4_];
			}
			break;
			case 4:
			PORTC|=(1<<0x03);
			PORTB = 0x00;
			_STATE_ = 0;
			break;
		}
}
ISR(TIMER0_COMPA_vect){
	_STATE_++;
}
