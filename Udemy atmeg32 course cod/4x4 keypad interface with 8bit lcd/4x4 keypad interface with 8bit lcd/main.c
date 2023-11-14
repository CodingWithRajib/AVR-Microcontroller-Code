#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void cmd(char a){
	PORTC = a;
	PORTD = 0x20;
	_delay_us(2000);
	PORTD = 0x00;
}

void data(char a){
	PORTC = a;
	PORTD = 0xA0;
	_delay_us(2000);
	PORTD = 0x80;
}

int keypad(){
	unsigned char k_in = 0xFF; int k_out = 255;
	
	PORTB = 0xEF;	//select 1st row 0x1110 1111
	_delay_us(10);
	k_in = PINB & 0x0F; //check button presses in 1st row 0x0000 0111
	if(k_in == 0x07) k_out = 1;			//1-0x07 = 0x0000 0111
	else if(k_in == 0x0B) k_out = 2;	//2-0x0000 1011;
	else if(k_in == 0x0D) k_out = 3;	//3-0x0000 1101;
	else if(k_in == 0x0E) k_out = 4;	//A-0x0000 1011;
	
	PORTB = 0xDF;	//select 2nd row 0x1101 1111
	_delay_us(10);
	k_in = PINB & 0x0F; //check button presses in 2nd row
	if(k_in == 0x07) k_out = 5;			//5-0x07 = 0x0000 0111
	else if(k_in == 0x0B) k_out = 6;	//6-0x0000 1011;
	else if(k_in == 0x0D) k_out = 7;	//7-0x0000 1101;
	else if(k_in == 0x0E) k_out = 8;	//B-0x0000 1011;
	
	PORTB = 0xBF;	//select 3rd row
	_delay_us(10);
	k_in = PINB & 0x0F; //check button presses in 3rd row
	if(k_in == 0x07) k_out = 9;			//1-0x07 = 0x0000 0111
	else if(k_in == 0x0B) k_out = 10;	//2-0x0000 1011;
	else if(k_in == 0x0D) k_out = 11;	//3-0x0000 1101;
	else if(k_in == 0x0E) k_out = 12;	//C-0x0000 1011;
	
	PORTB = 0x7F;	//select 4th row
	_delay_us(10);
	k_in = PINB & 0x0F; //check button presses in 4th row
	if(k_in == 0x07) k_out = 13;			//1-0x07 = 0x0000 0111
	else if(k_in == 0x0B) k_out = 14;	//2-0x0000 1011;
	else if(k_in == 0x0D) k_out = 15;	//3-0x0000 1101;
	else if(k_in == 0x0E) k_out = 16;	//D-0x0000 1011;
	
	return k_out;
}

void display(char *a){
	while((*a) != '\0'){
		data(*a);
		a++;
	}
}

/*
void lcd_init(){
	cmd(0x38);
	cmd(0x80);
	cmd(0x01);
	cmd(0x0E);
	cmd(0x06);
}
*/

/*int main(){
	DDRC = 0xFF; DDRD = 0xF0;
	PORTC = 0x00;
	lcd_init();
	
	
	while(1){
		display("This counter");
		_delay_ms(1000);
		cmd(0x01);
		_delay_ms(1000);
		
	}
}
*/

int main(){
	int k = 255;
	DDRD = 0xE0; DDRC = 0xFF; DDRB = 0xF0; //1111 0000
	PORTD = 0x00; PORTC = 0x00; PORTB = 0xFF;
	cmd(0x38); cmd(0x80); cmd(0x01);
	cmd(0x0E); cmd(0x06);
	while(1){
		k = keypad();
		if(k != 255){
			switch(k){
				case 1:
				cmd(0x01);
				data('7');
				break;
				
				case 2:
				cmd(0x01);
				data('8');
				break;
				
				case 3:
				cmd(0x01);
				data('9');
				break;
				
				case 4:
				cmd(0x01);
				data('/');
				break;
				
				case 5:
				cmd(0x01);
				data('4');
				break;
				
				case 6:
				cmd(0x01);
				data('5');
				break;
				
				case 7:
				cmd(0x01);
				data('6');
				break;
				
				case 8:
				cmd(0x01);
				data('*');
				break;
				
				case 9:
				cmd(0x01);
				data('1');
				break;
				
				case 10:
				cmd(0x01);
				data('2');
				break;
				
				case 11:
				cmd(0x01);
				data('3');
				break;
				
				case 12:
				cmd(0x01);
				data('-');
				break;
				
				case 13:
				cmd(0x01);
				display("ON/C");
				break;
				
				case 14:
				cmd(0x01);
				data('0');
				break;
				
				case 15:
				cmd(0x01);
				data('=');
				break;
				
				case 16:
				cmd(0x01);
				data('+');
				break;
			}
		}
		else
		continue;
		
		_delay_ms(300);
	}
}