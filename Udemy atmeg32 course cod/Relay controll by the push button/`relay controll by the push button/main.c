#define  F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(){
	/*DDRC = 0x04; //0000 0100
	PORTC = 0x00;
	while(1){
		if((PINC & 0x80) == 1){ //0x80 = 0000 1000
			PORTC = 0x00; //0000 0000
			
		}
		else{
			PORTC = 0x04; // 0000 0100
		}
	}
	*/
	DDRC &= ~(1<<3); //as an input
	DDRC |= (1<<2);	//as a output
	
	while (1){
		if((PINC & (1<<3)) == 0) PORTC |= (1<<2);
		else PORTC &= ~(1<<2); 
	}
}