 /*
 */

#include <avr/io.h>
#include "lcd.h"
#include <avr/delay.h>
#include <avr/interrupt.h>
int main(void)
{

    // Insert code
lcd_initialization();
ADCSRA |=1<<ADPS2; //PRESCALLER
ADCSRA |=1<<ADIE;
ADCSRA |=1<<ADEN;
sei();
ADCSRA |=1<<ADSC;
    while(1)
    {

    }

    return 0;
}
ISR(ADC_vect){
uint8_t adcl = ADCL;
uint16_t TENBIT =ADCH<<8 | adcl;
POSITION(1,1,TENBIT,5);
_delay_ms(100);
ADCSRA |=1<<ADSC;
}
