/**
 * @file project_main.c
 * @author Ragasri.K ()
 * @brief Project to Blink an LED when the person is seated and heater is in on position
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Insert code
    DDRB|=(1<<PB0);  //set B0=1
    DDRD&=~(1<<PD0); //clear bit
    PORTD|=(1<<PD0); //set bit
    DDRD&=~(1<<PD4); //clear bit
    PORTD|=(1<<PD4);  //set bit
    while(1)
    {
        if(!(PIND&(1<<PD0))){  //person is seated
            if(!(PIND&(1<<PD4))){ //heater is in on position
                 PORTB|=(1<<PB0);  //LED is ON
            }else {
                PORTB&=~(1<<PB0); //LED is OFF
            }

        }

        else{
            PORTB&=~(1<<PB0); //LED is OFF
        }
    }
    return 0;

}
