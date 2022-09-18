/*
 */

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
DDRB |=(1<<PIN2);
DDRB |=(1<<PIN4);
DDRB &=~(1<<PIN3);//INPUT PIN SET
 PORTB |=1<<PIN3; //SETTING B3 AS HIGH AT INITIAL WHILE PRESSING IT VALUE IS ZERO
    // Insert code
PORTB |=1<<PIN2;
    while(1)
    {
       // PORTB |=1<<PIN3;
        if(bit_is_clear(PINB,3)){
            PORTB ^=1<<PIN2;
            _delay_ms(500);
        }
       else if(!(bit_is_clear(PINB,3)))
        {
                 PORTB &=~(1<<PIN2);
             PORTB ^=1<<PIN4;
             _delay_ms(500);
        }

    }

    return 0;
}
