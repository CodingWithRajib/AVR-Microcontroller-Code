/*
 * Interrup for toggle led.c
 *
 * Created: 19/08/2023 04:02:07 PM
 * Author : Dell
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define buttonPin PD2
#define led1 PB0
#define led2 PB1

int main(void)
{	
	//set buttonPin pin ast an INPUT
	DDRD &= ~(1<<buttonPin);
	//set led1 as an OUTPUT
	DDRB |= (1<<led1) | (1<<led2);
	//configure interrupt
	EICRA |= (1<<ISC11); //interrupt on Falling edge
	EIMSK |= (1<<INT0); //Enable INT0 External intterrupt.
	sei(); //Global Interrupt enable
	
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1<<led2);
		_delay_ms(2000);
		PORTB &= ~(1<<led2);
		_delay_ms(2000);
    }
	return 0;
}

ISR(INT0_vect){
	if(PIND & (1<<buttonPin)){
		PORTB ^= (1<<led1);
	}
	while(PIND & (1<<buttonPin));
	
}