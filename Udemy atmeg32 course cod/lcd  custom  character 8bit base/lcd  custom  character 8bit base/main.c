#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>




void cmd(char a){
	DDRC = a;
	DDRD = 0x02;
	_delay_ms(10);
	DDRD = 0x00;
	_delay_ms(3);
}


void data(char a){
	DDRC = a;
	DDRD = 0xA0;
	_delay_ms(10);
	DDRD = 0x80;
	_delay_ms(3);
}


void lcd_init(){
	cmd(0x38); //8bit mode enable
	cmd(0x01); // clear the display screen
	cmd(0x0E); //Display on, cursor blinking
	cmd(0x80); //force the cursor to the beginning of the 1st time
}

void lcd_custom_character(){
	cmd(0x48); //address where customized character is to be stored
	
	data(0x00); data(0x0A); data(0x15); data(0x11);
	data(0x12); data(0x00); data(0x00); data(0x00);
	cmd(0x80);		//Location of LCD where the character is to be displayed
	data(0x01);		// Displaying the character created at address 0x50
	_delay_ms(100); 
	
	cmd(0x50);		//address where customized character is to be stored
	data(0x00); data(0x00); data(0x0A); data(0x00);
	data(0x04); data(0x00); data(0x0E); data(0x11);
	cmd(0x82);		//Location of lcd where the character is to be displayed
	data(0x02);		//Displaying  the character created at address 0x50
	_delay_ms(100);
}

int main(){
	DDRC = 0xFF; DDRD = 0xE0;
	PORTC = 0x00; PORTD = 0x00;
	lcd_init();
	lcd_custom_character();
	while(1){}
	
}