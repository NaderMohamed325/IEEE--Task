
#include "MCAL/gpio/gpio.h"
int main(void) {
	Pin_config_t Pin;
	Pin.direction=Output;
	Pin.logic=Low;
	Pin.port=C;


	while (1) {
		Pin.pin=0;
		Pin.logic=High;
		Pin_logic_init(&Pin);
		_delay_ms(2000);
		Pin.logic=Low;
		Pin_logic_init(&Pin);
		Pin.pin=1;
		Pin.logic=High;
		Pin_logic_init(&Pin);
		_delay_ms(2000);
		Pin.logic=Low;
		Pin_logic_init(&Pin);
		Pin.pin=2;
		Pin.logic=High;
		Pin_logic_init(&Pin);
		_delay_ms(2000);
		Pin.logic=Low;
		Pin_logic_init(&Pin);
	}

	return 0;
}