#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h> 


void cmd(char a){
	PORTC = a;
	PORTD |= 0x20;
	_delay_ms(10);
	PORTD &= 0x00;
}

void data(char a){
	PORTC = a;
	PORTD |= 0xA0;
	_delay_ms(100);
	PORTD &= 0x80;
}

void display(char *a){
	while((*a) != '0'){
		data(*a);
		a++;
	}
}

int main(void)
{	
	int rv_adc = 0, k;
	double v_adc = 0.0;
    DDRA = 0x00; DDRC = 0xFF; DDRD = 0xFF;
	PORTA = 0x00; PORTC = 0x00; PORTD = 0x00;
	ADMUX = 0x60; ADCSRA = 0x87;
	cmd(0x38); cmd(0x80);
	cmd(0x01); cmd(0x0C);
    while (1) {
		ADCSRA |= 0x40;
		while((ADCSRA & 0x40) != 0);
		
		
		rv_adc = (ADCL >> 6) | (ADCH << 2);
		
		v_adc = (rv_adc * 5)/1023.0;
		k = v_adc*1000;
		
		display("RAW O/P: ");
		data((rv_adc / 1000)+48);
		data(((rv_adc / 100)%10)+48);
		data(((rv_adc/10)%10)+48);
		
		display("VOLTS: ");
		data((k/1000) + 48); data('.');
		data(((k/100)%10)+48);
		data((k%10)+48);
		display(" V ");
		cmd(0xC0); cmd(0x80);
	}

}

