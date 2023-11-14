#define F_CPU 8000000UL
#include <avr/io.h>
#include  <util/delay.h>

#define button_1 PC0
#define button_2 PC1

#define leftMotor_1 PC2
#define leftMotor_2 PC3
#define rightMotor_1 PC4
#define rightMotor_2 PC5

int main(){
	/*
	DDRC &= ~(1<<button_1); //PC pin as an input
	DDRC &= ~(1<<PC1); //PC pin as a input
	
	DDRC |= (1<<leftMotor_1);
	DDRC |= (1<<leftMotor_2);
	DDRC |= (1<<rightMotor_1);
	DDRC |= (1<<rightMotor_2);
	
	while(1){
		if((PINC & (1<<button_1)) == 0){
			PORTC |= (1<<leftMotor_1);
			PORTC &= ~(1<<leftMotor_2);
		}else{
			PORTC &= ~(1<<leftMotor_1);
			PORTC |= (1<<leftMotor_2);
		}
		if((PINC & (1<<button_2)) == 0){
			PORTC |= (1<<rightMotor_1);
			PORTC &= ~(1<<rightMotor_2);
		}else{
			PORTC &= ~(1<<rightMotor_1);
			PORTC |= (1<<rightMotor_2);
		}
		
	}
	*/
	
	DDRC = 0x00;
	DDRC = 0xFC
	while(1){
		if(PINC & 0x02){
			PORTC |= 0x04;
			PORTC &= 0x08;
		}else{
			PORTC &= 0x04;
			PORTC |= 0x08;
		}
	}
	
}

	
	
	