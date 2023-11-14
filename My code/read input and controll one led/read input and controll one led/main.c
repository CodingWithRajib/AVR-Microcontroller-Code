/*
 * read input and controll one led.c
 *
 * Created: 18/08/2023 11:31:37 PM
 * Author : Dell
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define button PD2
#define led1 PB1
#define led2 PB2

int main(void)
{
    DDRB |= (1<<led1) | (1<<led2);
	DDRD &= ~(1<<button);

	
    while (1) 
    {   
		PORTB |= (1<<led2);
		if(PIND & (1<<button)){
			PORTB |= (1<<led1);
			_delay_ms(500);
		}
		else{
			PORTB &= ~(1<<led1);
		}
		PORTB |= (1<<led2);
		_delay_ms(2000);
		PORTB &= ~(1<<led2);
		_delay_ms(2000);
	}
}

