/*
 */

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{

    // Insert code
DDRB |=(1<<PIN2)|(1<<PIN4);
DDRB &=~(1<<PIN3); // setting port b pin 3 as input
//DDRB = 00000001;
PORTB |=(1<<PIN3);
PORTB ^=(1<<PIN2);
int press=0;
int release=0;
int valid =0;
while(1)
    {
        if(bit_is_clear(PINB,3)){
           press++;
           if(press>200)
          {
       	if(valid==0){
            PORTB ^=(1<<PIN2);
		    PORTB ^=(1<<PIN4);
		   valid=1;
        }
		   press=0;
        }
        }
        else{
          release++;
          if(release>200){
          valid=0;
          release=0;}
        }
    }
    return 0;
}
