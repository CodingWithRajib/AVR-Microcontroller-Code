/*
 * 16x2 LCD display using 8bit.c
 *
 * Created: 07/11/2023 11:35:01
 * Author : rajib
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


/*
void cmd(char a){
	PORTC = a;
	PORTD = 0x20;  //0x0010 0000: RS=0 R/W=0 EN=1;
	_delay_us(500);
	PORTD = 0x00; //0x0000 00000: RS=0: R/W=0: EN=0;
}

void data(char a){
	PORTC = a;
	PORTD = 0xA0; //0x1010 0000: RS=1: RW=0: EN=1;
	_delay_us(500);
	PORTD = 0x80; //0x1000 0000: RS = 1: RW=0: EN=0:
}

void display(char *a){
	while((*a) != '\0'){
		data(*a);
		a++;
	}
}


int main(void)
{
	DDRC = 0xFF; //0x1111 1111 all pin as an output.
	DDRD = 0xE0; //0x1110 0000 this pin as an output
	PORTC = 0x00; //0x0000 0000 all pin low.
	PORTD = 0x00; //0x0000 0000 all pin low.
	
	cmd(0x38); //0x0011 1000 <<>> D0=0, D1=0, D2=1, D3=1, D4=1, D5=0, D6=0, D7=0
	cmd(0x80); //0x1000 0000 <<>> D0=1, D1=0, D2=0, D3=0, D4=0, D5=0, D6=0, D7=0
	cmd(0x01); //0x0000 0001 <<>> D0=0, D1=0, D2=0, D3=0, D4=0, D5=0, D6=0, D7=1
	cmd(0x0E); //0x0000 1110
	cmd(0x06); //0x0000 0110
	//data('R');
	display("rajib");
 
	
	

}

*/

void cmd(char a){
	PORTC = a;
	PORTD = 0x20;
	_delay_us(500);
	PORTD = 0x00;
}

void data(char a){
	PORTC = a;
	PORTD = 0xA0;
	_delay_us(500);
	PORTD = 0x80;
}

void display(char *a){
	while((*a) != '\0'){
		data(*a);
		a++;
	}
}

void lcd_init(){
	cmd(0x38);
	cmd(0x80);
	cmd(0x01);
	cmd(0x0E);
	cmd(0x06);
}


// this code for scrolling display
/***int main(){ 
	DDRC = 0xFF; DDRD = 0xE0;
	PORTC = 0x00;
	lcd_init();
	display("HELLOW");
	while(1){
		while((PIND & 0x01) == 0){
			cmd(0x1C);
			_delay_ms(1);
		}
		while((PIND & 0x02) == 0){
			cmd(0x18);
			_delay_ms(1);
		}
	}
***/
int main(){
	DDRC = 0xFF; DDRD = 0xE0;
	PORTC = 0x00;
	
	lcd_init();
	display("This counter");
}
