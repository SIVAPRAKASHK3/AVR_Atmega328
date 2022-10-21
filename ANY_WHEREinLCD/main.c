/*
 */

#include <avr/io.h>
#include "lcd_header.h"
int main(void)
{

lcd_initialization();
POSITION(1,2,500,4);
_delay_ms(300);
POSITION(1,2,900,4);
    while(1)
    {


    }
    return 0;
}
