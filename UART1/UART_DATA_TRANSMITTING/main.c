/*#include <avr/io.h>

int main(void)
{
DDRB |=1<<PIN4 |1<<PIN5;
PORTB &=~(1<<PIN4);
DDRB &=~(1<<PIN3);
PORTB |=(1<<PIN3); //switch is high in inital state
uint8_t PRESSED=0;
int PRESS_CONFIDENT=0;
int RELEASE_CONFIDENT=0;
int BAURD=207;
UBRR0H =(unsigned char) (BAURD>>8);
UBRR0L =(unsigned char) (BAURD);
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
UCSR0C |= 1<<USBS0;
UCSR0C |=(3<<UCSZ00);
    while(1)
    {
        if(bit_is_clear(PINB,3))
        {
            PRESS_CONFIDENT++;
            RELEASE_CONFIDENT=0;
            if(PRESS_CONFIDENT>200 ){
                if(PRESSED==0)
                {     PRESSED=1;
                     PORTB ^=1<<PIN4;
                     while(!(UCSR0A &(1<<UDRE0))); //8BIT DATA TRANSFER
                     UDR0 =0b00001111;

                }
            PRESS_CONFIDENT=0;
        }}
        else
        {
            RELEASE_CONFIDENT++;
            PRESS_CONFIDENT=0;
            if(RELEASE_CONFIDENT >200)
            {
               if(PRESSED==1){
                PORTB ^=1<<PIN5;

                PRESSED=0;}
               RELEASE_CONFIDENT=0;
        }}
    }
    return 0;
}
*/

#include <avr/io.h>

int main(void)
{
DDRB |=1<<PIN4;
PORTB &=~(1<<PIN4);
DDRB |=1<<PIN5;
PORTB &=~(1<<PIN5);
DDRB &=~(1<<PIN3);
PORTB |=(1<<PIN3); //switch is high in inital state
uint8_t PRESSED=0;
int PRESS_CONFIDENT=0;
int RELEASE_CONFIDENT=0;
int BAURD=207;
UBRR0H =(unsigned char) (BAURD>>8);
UBRR0L =(unsigned char) (BAURD);
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
UCSR0C = 1<<USBS0;
UCSR0C =(3<<UCSZ00);
    while(1)
    {
        if(bit_is_clear(PIND,3))
        {
            PRESS_CONFIDENT++;
            RELEASE_CONFIDENT=0;
            if(PRESS_CONFIDENT>200 ){
                if(PRESSED==0)
                {     PRESSED=1;
                     PORTB ^=1<<PIN4;
                     while(!(UCSR0A &(1<<UDRE0))); //8BIT DATA TRANSFER
                     UDR0 =0b11110000;
                     PORTB ^=1<<PIN5;

                }
            PRESS_CONFIDENT=0;
        }}
        else
        {
            RELEASE_CONFIDENT++;
            PRESS_CONFIDENT=0;
            if(RELEASE_CONFIDENT >200)
            { //PORTD ^=1<<PIN4;
               RELEASE_CONFIDENT=0;
                PRESSED=0;
        }}
    }
    return 0;
}



//*/
