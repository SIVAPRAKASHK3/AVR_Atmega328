/*
 */
#include <avr/delay.h>
#include <avr/io.h>
int  timer=0;
int reset=0;

int main(void)
{

DDRD &=~(1<<PIN0);
DDRD |= (1<<PIN1)|(1<<PIN2);
int COUNT=0;
//PORTD |=1<<PIN0;
PORTD ^=1<<PIN1;
TCCR1B |=1<<CS10|1<<CS11; //PRESCALE 64
    while(1)
    {
        if(TCNT1>64600){
                TCNT1=0;
            PORTD^=1<<PIN1;  //EIGHT BLINK PIN1 LED EQUALS 1 PIN2 LED BLINK;
        if(COUNT>8){
             //_delay_ms(500);
               PORTD^=1<<PIN2;
               COUNT=0;}
                 COUNT++;
        }
    }
    return 0;
}
/*
  if((bit_is_clear(PIND,0))){
                timer++;
                if(timer>200){
            PORTD ^=1<<PIN1;
       PORTD ^=1<<PIN2;
            timer=0;
          //  _delay_ms(500);
        }}
        else{reset++;
                if(reset>200){
         //   PORTD ^=1<<PIN2;
            reset=0;
             //  _delay_ms(500);
            }


        }*/
