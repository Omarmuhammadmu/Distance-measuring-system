/*
 ================================================================================================
 Name        : Distance measuring
 Author      : Omar Muhammad
 Description : Measuring distance using ultrasonic sensor
 Date        : 13/10/2022
 ================================================================================================
 */

#include "HAL/lcd.h"
#include "HAL/ultrasonic.h"
#include <avr/io.h>


int main(void)
{
	uint16 readDistance = 0; /* The distance read by the Ultrasonic module*/

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	LCD_init(); /* Initializing LCD Driver*/
	Ultrasonic_init(); /* Initializing Ultrasonic Driver*/

	/* Display this string "Distance=    cm " only once on LCD at the first row*/
	LCD_moveCursor(0,1);
	LCD_displayString("Distance=    cm");

	while(1)
	{
		/*Display the distance each time in the same place*/
		LCD_moveCursor(0,11);

		readDistance = Ultrasonic_readDistance();

		if(readDistance>=100)
		{
			LCD_intgerToString(readDistance);

		}
		else if (readDistance>=10)
		{
			LCD_intgerToString(readDistance);
			LCD_displayCharacter(' ');

		}
		else
		{
			LCD_intgerToString(readDistance);
			LCD_displayCharacter(' ');
			LCD_displayCharacter(' ');
		}

	}

	return 0;
}


