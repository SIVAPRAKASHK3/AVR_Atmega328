/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
sei();
DDRD |=1<<PIN1;
TCCR1B |=1<<CS10|1<<CS11|1<<WGM12; //TCCR1B BECAUSE THIS REGISTER ONLY HAS PRESCALER
TIMSK1 =1<<OCIE1A;
OCR1A =9999;
    // Insert code

    while(1)
    {

    }

    return 0;
}
ISR(VECTOR){
PORTD |=1<<PIN1;
}
