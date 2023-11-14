/*
 * LED toggle.c
 *
 * Created: 18/08/2023 09:40:05 PM
 * Author : Dell
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB |= (1<<0) | (1<<1) | (1<<2);
	
    while (1) 
    {	PORTB |= (1<<1);
		PORTB |= (1<<0);
		_delay_ms(100);
		PORTB &= ~(1<<0);
		_delay_ms(1000);
		
    }
	return 0;
}

