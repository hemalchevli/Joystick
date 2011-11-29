/*****************************************************************
FILENAME 	: Joy
Target	 	: ATmega128
Frequency	: 16Mhz
Compiler 	: avr-gcc
Author   	: Hemal M. Chevli (hemal_chevli@yahoo.com)
Description	: This is sample application which uses the joystick
              and displays the values of X and Y on the LCD
Date        : 9th March 2011
*****************************************************************/
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include "LCD_MEGA.H"
void ADC_init(void);

void ADC_init(void)
{
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescalar to 128 - 125KHz sample rate @ 16MHz 
	ADMUX |= (1 << REFS0); // Set ADC reference to AVCC 
	ADMUX |= (1 << ADLAR); // Left adjust ADC result to allow easy 8 bit reading 
    
   ADCSRA |= (1 << ADFR);  // Set ADC to Free-Running Mode 
   ADCSRA |= (1 << ADEN);  // Enable ADC 
   ADCSRA |= (1 << ADSC);  // Start A2D Conversions 
}
int main(void)
{
	lcd_init();	
	ADC_init();	
   for(;;)  // Loop Forever 
   { 
   		//_delay_ms(200);
		ADMUX = (1<<REFS1) | (1<<REFS0) | (1<<ADLAR) |(1<<MUX0);//To select channel 1(x-axis)
		lcd_gotoxy1(0);
		lcd_string("X=");
		lcd_showvalue(ADCH);
		
		//_delay_ms(200);
		ADMUX = (1<<REFS1) | (1<<REFS0) | (1<<ADLAR) |(1<<MUX1);//To select channel 2(Y-axis)
		lcd_gotoxy2(0);
		lcd_string("Y=");
		lcd_showvalue(ADCH);
		
	} 
} 



