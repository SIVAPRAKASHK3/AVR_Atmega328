/*
 */
#define F_CPU 8432000UL

#include <avr/io.h>
#include <avr/delay.h>
int main(void)
{

DDRD |=1<<PORTD;


    while(1)
    {
        PORTD ^=1<<PIN0;
        _delay_ms(10);
    }

    return 0;
}
