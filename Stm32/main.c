 /******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Wafdy
 * @brief          : Main program body
 ******************************************************************************/
 
 #include <stdint.h>
 #include "ErrType.h"
 #include "cnfg.h"
 
 #include "GPIO_Interface.h"
 #include "RCC_Interface.h"
 #include "SysTick_Interface.h"
 
 
void main(void)
{
	SysTick_Init(SYSTICK_PROCESSOR_CLK, AHB_CLK/1000000);
	RCC_AHB1EnableClock(AHB1_GPIOA);
	
	PinConfig_t LedConfig=
	{
		.Mode=OUTPUT,
		.OutputType=PUSH_PULL,
		.Pin=PIN5,
		.Port=PORTA,
		.PullType=NO_PULL
	};
	GPIO_u8PinInit(&LedConfig);
	
	while(1)
	{
		GPIO_u8TogglePinValue(PORTA, PIN5);
		SysTick_Delayms(500);
	}
}
