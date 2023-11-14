/*
 * gpio program.c
 *
 * Created: 04/11/2023 21:48:22
 * Author : rajib
 */ 

#define  F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code
	DDRC= 0xFF; PORTC = 0x00;
    while (1) 
    {
		PORTC ^= 0xFF;
		_delay_ms(100);
    }
	 */
	
	DDRC = 0xff; 
	PORTC &= 0x00;
	PORTC |= 0x01;
	while(1){
		for(int i = 0; i<5; i++){
			PORTC <<= 1;
			_delay_ms(50);
		}
		for(int i = 0; i<5; i++){
			PORTC >>= 1;
			_delay_ms(50);
		}
	
	}
}

