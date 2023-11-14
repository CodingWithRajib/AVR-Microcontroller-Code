#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(){
	DDRD = 0x0f; //0x0000 1111
	PORTD = 0x00;
	//int dley = 1000;
	//this wave drive mode:
	/*while (1)
	{
		for (int i = 0; i<128; i++)
		{
			PORTD = 0x01; //0x0000 0001
			_delay_us(dley); 
			PORTD = 0x02; //0x0000 0010
			_delay_us(dley);
			PORTD = 0x04; //0x0000 0100
			_delay_us(dley);
			PORTD = 0x08; //0x0000 1000
			_delay_us(dley);
		}
		_delay_us(1000);
	}
	*/
	
	//this code is full step mode:
	/*while(1){
		for(int i=0; i<120; i++){
			PORTD = 0x03;
			_delay_ms(3);
			PORTD = 0x06;
			_delay_ms(3);
			PORTD = 0x0C;
			_delay_ms(3);
			PORTD = 0x09;
			_delay_ms(3);
		}
		_delay_ms(100);
	}
	*/
	
	//this is half step mode:
	/*while(1){
		for(int i = 0; i<64; i++){
			PORTD = 0x01; //0x0000 0001
			_delay_ms(3);
			PORTD = 0x03; //0x0000 0011
			_delay_ms(3);
			PORTD = 0x02; //0x0000 0010
			_delay_ms(3);
			PORTD = 0x06; //0x0000 0110
			_delay_ms(3);
			PORTD = 0x04; //0x0000 0100
			_delay_ms(3);
			PORTD = 0x0C; //0x0000 1100
			_delay_ms(3);
			PORTD = 0x09; //0x0000 10001
			_delay_ms(3);
		}
		_delay_ms(100);
	}
	*/
	//this cod is microstep mode
	while(1){
		for(int i=0; i<3; i++){
			PORTD = 0x03; //0x0000 0011
			_delay_ms(3);
			PORTD = 0x2; //0x0000 0010
			_delay_ms(3);
			PORTD = 0x06;//0x0000 0110
			_delay_ms(3);
			PORTD = 0x04;//0x0000 0100
			_delay_ms(3);
			PORTD = 0x0C;//0x0000 1100
			_delay_ms(3);
			PORTD = 0x08;//0x0000 1000
			_delay_ms(3);
			PORTD = 0x09;//0x0000 1001
		}
		_delay_ms(100);
	}
	
	
}