#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect){
	PORTC ^= 0x01;
	_delay_ms(200);
}

ISR(INT1_vect){
	PORTC ^= 0x02;
	_delay_ms(100);
}

ISR(INT2_vect){
	PORTC ^= 0x04;
	_delay_ms(100);
}
int main(){
	DDRB = 0x00; DDRC=0x07; DDRD = 0x00;
	PORTB = 0x04; PORTC = 0x00; PORTD = 0x0C;
	GICR = 0xE0; MCUCR = 0x05; MCUCSR = 0x00;
	sei();
	while(1){
		PORTC ^= 0x04;
		_delay_ms(2000);
		}
	
}