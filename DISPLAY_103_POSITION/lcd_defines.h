//#ifndef LCD_DEFINES_H_INCLUDED
#define LCD_DEFINES_H_INCLUDED

#include <avr/delay.h>
#include <avr/io.h>
#include <stdlib.h>

#define LCD_PIN         PORTD
#define PIN_DDR         DDRD
#define LCD_CONTROL     PORTB
#define CONTROL_DDR     DDRB
#define REGISTR_SEL     3       //ON - DISPLAY MODE OFF - CURSOUR MODE
#define READ_WRITE      1       //ON - DISPLAY GIVES INFO  OFF - TO DISPLAY STATUS
#define ENABLE          2

//#endif // LCD_DEFINES_H_INCLUDED
