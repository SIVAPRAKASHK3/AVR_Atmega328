#include <avr/io.h>
#include <avr/delay.h>
#define LCD_CONTROL     PORTB
#define ddr_control     DDRB
#define LCD_PIN         PORTD
#define ddr_pin         DDRD
#define REGIS_SELECT    3
#define READ_WRITE      2
#define ENABLE          1
void text(unsigned char commands);
void cursour(unsigned char commands);
void on_off();
int main(void)
{
    ddr_control |= 1<<REGIS_SELECT |1<<READ_WRITE |1<<ENABLE ;
    _delay_ms(15);
cursour(0x01);
_delay_ms(2);
cursour(0x38);
_delay_us(50);
cursour(0b00001110);
_delay_us(50);

text('Z');
text(0x42);
text(0x43);
//text(0x44);
    while(1)
    {
    }
}
void busy_check(){
ddr_pin=0;
LCD_PIN |=1<<READ_WRITE;
LCD_PIN &=~ 1<<REGIS_SELECT;
while(LCD_PIN >=0x80)
{
    on_off();
}
ddr_pin=0xFF;
}

void on_off(){
LCD_CONTROL |=1<<ENABLE;
//asm volatile ("nop");
//asm volatile ("nop");
LCD_CONTROL &=~1<<ENABLE;
}

void cursour(unsigned char commands)
{
busy_check();
LCD_CONTROL |=1<<ENABLE;
LCD_PIN =commands;        //LCD_CONTROL IS PORTD
LCD_CONTROL &=~(1<<READ_WRITE);
LCD_CONTROL &=~(1<<REGIS_SELECT);
//on_off();
LCD_CONTROL &=~1<<ENABLE;
LCD_PIN=0;

}

void text(unsigned char commands)
{
busy_check();
LCD_CONTROL |=1<<ENABLE;
LCD_PIN =commands;
LCD_CONTROL &=~(1<<READ_WRITE);
LCD_CONTROL |=1<<REGIS_SELECT;
//on_off();
LCD_CONTROL &=~1<<ENABLE;
LCD_PIN=0;
}
