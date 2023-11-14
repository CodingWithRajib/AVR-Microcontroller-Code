#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


void transmit(char a){
	UDR = a;
	while((UCSRA & 0x40) == 0){
		_delay_ms(10);
	}
}

int main(){
	DDRD = 0x02; PORTD = 0x00;
	UCSRA = 0x00; UCSRB = 0x18; UCSRC = 0x06;
	UBRRH = 0x00; UBRRL = 0x33; //9600 bps for 8MHz crystal
	transmit('H');
	transmit('$');
	transmit('z');
	transmit('6');
	 while(1){
	 }
	
}
