#define F_CPU 8000000UL


#include <avr/io.h>
#include <util/delay.h>


char receive(){
	while((UCSRA & 0x80) == 0){
		return UDR;
	}
}

void cmd(char a){
	PORTC = a;
	PORTD = 0x20;
	_delay_ms(100);
	PORTD = 0x00;
}

void data(char a){
	PORTC = a;
	PORTD = 0xA0;
	_delay_ms(100);
	PORTD = 0x80;
}

int main(){
	char a;
	DDRC = 0xFF; DDRD = 0xE0;
	PORTC = 0x00; PORTD = 0x00;
	UCSRA = 0x00; UCSRB = 0x18; UCSRC = 0x06;
	UBRRH = 0x00; UBRRL = 0x33;
	cmd(0x38); cmd(0x80); cmd(0x01);
	cmd(0x0E); cmd(0x06);
	while(1){
		a = receive();
		cmd(0x80); cmd(0x01);
		data(a);
	}
}