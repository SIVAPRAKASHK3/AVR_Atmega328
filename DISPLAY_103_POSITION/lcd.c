#ifndef LCD_DEFINES_H_INCLUDED
#define LCD_DEFINES_H_INCLUDED

#include "lcd_defines.h"
void lcd_initialization(void);
void TEXT(unsigned char INPUT);
void STRING(char *INPUT);
void ROUTINE(void);
void BUSYCHECK(void);
void CURSOUR(unsigned char INPUT);
void TEXT(unsigned char INPUT);
char str [4];
int row [4]={0,64,20,84};

void lcd_initialization(void)
{
CONTROL_DDR |=1<< REGISTR_SEL | 1<<READ_WRITE |1<<ENABLE;
_delay_ms(15);
CURSOUR(0x01);// clear lcd display
_delay_ms(2);
CURSOUR(0x38); // set 8 bit 2 line for 1 line 0x30
_delay_us(50);
CURSOUR(0b00001110); // display on cursor on 0x0E
_delay_us(50);

}
void STRING(char *INPUT)
{
    while(*INPUT!=0)
        TEXT(*INPUT++);      // SLCING CHARACTER BY CHARACTER AND SENDING TO TEXT
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
    //CURSOUR(0x80+97); // location (97) where need to show info
    STRING(str);
    _delay_ms(200);
    CURSOUR(0x80+(i+row[j]));
    STRING(" ");
    }

void POSITION(){

}
#endif // LCD_DEFINES_H_INCLUDED
