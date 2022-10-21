/*
 */
#include <avr/delay.h>
#include <avr/io.h>
#define LCD_PIN         PORTD
#define PIN_DDR         DDRD
#define LCD_CONTROL     PORTB
#define CONTROL_DDR     DDRB
#define REGISTR_SEL     3       //ON - DISPLAY MODE OFF - CURSOUR MODE
#define READ_WRITE      1       //ON - DISPLAY GIVES INFO  OFF - TO DISPLAY STATUS
#define ENABLE          2
void TEXT(unsigned char INPUT);
void STRING(char *INPUT);
void ROUTINE();
void BUSYCHECK();
void CURSOUR(unsigned char INPUT);
void TEXT(unsigned char INPUT);
int main(void)
{
CONTROL_DDR |=1<< REGISTR_SEL | 1<<READ_WRITE |1<<ENABLE;
_delay_ms(15);
CURSOUR(0x01);// clear lcd display
_delay_ms(2);
CURSOUR(0x38); // set 8 bit 2 line for 1 line 0x30
_delay_us(50);
CURSOUR(0b00001110); // display on cursor on 0x0E
_delay_us(50);
TEXT('A');
STRING("HELLO input string is allowed");
    while(1)
    {

    }
    return 0;
}
void STRING(char *INPUT)
{
    while(*INPUT!=0)
        TEXT(*INPUT++);
}
void ROUTINE()
{
LCD_CONTROL  |=1<<ENABLE;
asm volatile("nop");
asm volatile("nop");
LCD_CONTROL &=~(1<<ENABLE);
}

void BUSYCHECK()      //CHECK LCD DISPLAY IS BUSY OR NOT
{
PIN_DDR =0;
LCD_CONTROL |=1<<READ_WRITE;
LCD_CONTROL &=~(1<<REGISTR_SEL);
while(LCD_PIN>=0x80)
{
    ROUTINE();
}
PIN_DDR =0xFF;
}

void CURSOUR(unsigned char INPUT)
{
BUSYCHECK();
LCD_PIN=INPUT;
LCD_CONTROL &=~(1<<READ_WRITE | 1<<REGISTR_SEL);
ROUTINE();
LCD_PIN=0;
}

void TEXT(unsigned char INPUT)
{
    BUSYCHECK();
    LCD_PIN=INPUT;
    LCD_CONTROL &=~(1<<READ_WRITE);
    LCD_CONTROL |=1<<REGISTR_SEL ;
    ROUTINE();
    LCD_PIN=0;
}
