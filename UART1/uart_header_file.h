#ifndef UART_HEADER_FILE_H_INCLUDED
#define UART_HEADER_FILE_H_INCLUDED
#include<math.h>
#include<avr/io.h>

#define disable     0
#define reserved    1
#define even        0
#define odd         1
void uart_initialize(uint16_t ubbr ,uint8_t stopbit,uint8_t frame_bit,char PARITY_EVEN_OR_ODD,uint8_t uart_intrupt_reciever)
{int baurd =ceil(F_CPU/(16*(ubbr+1)));
baurd=(baurd/10)*10;

UBRR0H = (unsigned char)(baurd>>8);// GREATER than 256 will be stored in UBRROH;
UBRR0L = (unsigned char)baurd;// LESSER than 256 will be stored in UBRROL;

/*Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);

/* 2stop bit */
if(stopbit==2)
UCSR0C = (1<<USBS0);
else
UCSR0C &= ~(1<<USBS0);

//PARITY MODE
if(PARITY_EVEN_OR_ODD==even) UCSR0C |=1<<UPM00;
if(PARITY_EVEN_OR_ODD==odd) UCSR0C |=1<<UPM00 | 1<<UPM01;

/* Set frame format: 8data */

if(frame_bit==6) UCSR0C |= (1<<UCSZ00); // NO OF BITS 6;
if(frame_bit==7) UCSR0C |= (2<<UCSZ00); // NO OF BITS 7;
if(frame_bit==8) UCSR0C |= (3<<UCSZ00); // NO OF BITS 8;
if(frame_bit==9) UCSR0C |= (7<<UCSZ00); // NO OF BITS 9;

/*uart reciever intrupt enabel*/
if(uart_intrupt_reciever) UCSR0B |=1<<RXEN0;
}
void uart_transmitter(unsigned char data)
{

        /* Wait for empty transmit buffer */
        while (!(UCSR0A & (1<<UDRE0)));

        /* Put data into buffer, sends the data */
        UDR0 = data;
}
unsigned char uart_reciever()
{
        /* Wait for data to be received */
        while (!(UCSR0A & (1<<RXC0)));

        /* Get and return received data from buffer */
        return UDR0;
}


#endif // UART_HEADER_FILE_H_INCLUDED
