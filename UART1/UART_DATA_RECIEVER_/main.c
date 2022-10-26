 #include <avr/io.h>
 int main()
 {
     DDRD |=1<PIN4;
        DDRD |=1<PIN5;

DDRD &=~(1<<PIN2);
     PORTD |=(1<<PIN4);
  //  PORTD |=1<PIN4;
//PORTD |=(1<<PIN2);
     unsigned char receiver;
     int BAURD=207;
UBRR0H =(unsigned char) (BAURD>>8);
UBRR0L =(unsigned char) (BAURD);
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
UCSR0C = 1<<USBS0;
UCSR0C =(3<<UCSZ00);
     while(1){
        //PORTD ^=1<<PIN4;
        while (!(UCSR0A & (1<<RXC0)));
        receiver = UDR0;
        if(receiver==0b11110000){
           PORTB ^=1<<PIN4;
        }
        else
        {
          PORTB ^=1<<PIN5;
        }

}}
