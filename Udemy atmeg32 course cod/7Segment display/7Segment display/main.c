#define F_CPU 8000000UL


#include <avr/io.h>
#include <util/delay.h>



int main(){
	DDRD = 0x0F; 
	//uint8_t c[11] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	/*while(1){
		
		for(int i=0; i<11; i++){
			PORTD = c[i];
			_delay_ms(100);
		}
	}
	*/
	
	while(1){
		for(int i=0; i<10; i++){
			PORTD = (char)i;
			_delay_ms(50);
		}
	}

	/*PORTC = 0x0F;
	_delay_ms(100);
	PORTC = 
	*/
}
