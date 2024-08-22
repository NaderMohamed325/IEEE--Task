#include "MCAL/gpio/gpio.h"
uint8_t counter = 0, first, second;
int main(void) {
	
	Port_Direction(C, Output); // Initialize port C as Output

	Pin_config_t Choose1, Choose2;
	Choose1.direction = Output;
	Choose1.logic = Low;
	Choose1.pin = 6;
	Choose1.port = D;
	Pin_logic_init(&Choose1);

	Choose2.direction = Output;
	Choose2.logic = Low;
	Choose2.pin = 7;
	Choose2.port = D;
	Pin_logic_init(&Choose2);

	while (1) {
		first = counter / 10;
		second = counter % 10;

		// Display first digit
		Choose1.logic = High;
		Choose2.logic = Low;
		Pin_logic_init(&Choose1);
		Pin_logic_init(&Choose2);
		Port_Set(C, first);

		_delay_ms(50);

		// Display second digit
		Choose1.logic = Low;
		Choose2.logic = High;
		Pin_logic_init(&Choose1);
		Pin_logic_init(&Choose2);
		Port_Set(C, second);

		_delay_ms(50);

		counter++;
		if (counter >= 100) {
			counter = 0;
		}
	}

	return 0;
}