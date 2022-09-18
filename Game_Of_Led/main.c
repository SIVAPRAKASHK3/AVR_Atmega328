void blink_led(int led_no);
void reset_led(int led_no);


#include <avr/io.h>
#include <util/delay.h>
int led[2];
int count[2];
int press_count[2];
int pin_number[4]={0,1,2,3};
int confident_press[2];
int confident_release[2];
int state[2]={1,1};
int main(void)
{

DDRC = 0b11111101;
DDRD = 0b11101111;

PORTC |=1<<PIN1;
PORTD |=1<<PIN4;
//PORTC |=1<<PIN1;

press_count[0]=2;
    while(1)
    {
      if(bit_is_clear(PINC,1))
       {
             blink_led(0);
        }
       else {
            reset_led(0);
        }
      if(bit_is_clear(PIND,4))
       {
             blink_led(1);
        }
        else{
            reset_led(1);
        }
        if(count[0]==4){
             PORTC |= 1<<6;
            break;
        }
        else if(count[1]==4){
            PORTD |= 1<<5;
            break;
        }
    }
    return 0;
}
void blink_led(int led){
int x;
confident_press[led]++;
if(confident_press[led]>500)
   {
    if(state[led]==1){
       if(led==0){
        togelel(0);
        count[led]++;
       }
       if(led==1){
        togelel_(1);
        count[led]++;
       }
       confident_press[led]=0;
       press_count[led]++;
        state[led]=0;}
    }
}
void reset_led(int num)
{
    confident_release[num]++;
    if(confident_release[num]>200)
    {
        state[num]=1;
        confident_release[num]=0;

    }
}

void togelel(int led)
{
   int x=0;
        x=press_count[led];
        PORTC |= 1<<x;
}

void togelel_(int led)
{
   int x=0;
        x=press_count[led];
        PORTD ^= 1<<x;
}

