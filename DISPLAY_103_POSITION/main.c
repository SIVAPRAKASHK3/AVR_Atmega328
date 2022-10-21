
//include "lcd_defines.h"
#include <avr/delay.h>
#include <avr/io.h>
#include "lcd.c"
/*
#include <stdlib.h>

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
char str [4];
int row [4]={0,64,20,84};
*/
#include "lcd_defines.h"
#include "lcd_header.c"
int main(void)
{
lcd_initialization();
int i,j;//=0;
for(j=0;j<4;j++)
   for(i=0;i<20;i++)
   {
    CURSOUR_LOCATION(i,j);
   }
    while(1)
    {

    }

    return 0;
}






















/*
void STRING(char *INPUT)
{
    while(*INPUT!=0)
        TEXT(*INPUT++);      // S;CING CHARACTER BY CHARACTER AND SENDING TO TEXT
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

void CURSOUR_LOCATION(int i,int j){
                    CURSOUR(0x80+(i+row[j]));
                    STRING("X");
                    itoa((i+row[j]),str,10);
                    CURSOUR(0x80+97); // location (97) where need to show info
                    STRING(str);
                    _delay_ms(200);
                    CURSOUR(0x80+(i+row[j]));
                    STRING(" ");}
*/
