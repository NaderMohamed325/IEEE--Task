
#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"

#include "GPIO_Interface.h"
#include "GPIO_prv.h"



/***********************************************************
* @fn GPIO_u8PinInit
* @Brief The pin initialization function
* @Param[in] PinConfig : The initialization parameters struct for the pin
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t GPIO_u8PinInit(const PinConfig_t* PinConfig)
{
	ErrorStatus_t ErrorState=UNKNOWN;
	if(PinConfig!=NullPtr)
	{
		if(PinConfig->Port>=TOTAL_PORTS || PinConfig->Pin>=TOTAL_PINS || PinConfig->AltFunc>=TOTAL_ALT_FUNCS)
		{
			ErrorState=OUT_OF_RANGE;
		}
		else
		{
			GPIO_RegDef_t* GPIO_Port=NullPtr;
			/*Select the desired port*/
			switch(PinConfig->Port)
			{
				case PORTA:
					GPIO_Port=GPIOA;
					break;
				case PORTB:
					GPIO_Port=GPIOB;
					break;
				case PORTC:
					GPIO_Port=GPIOC;	
					break;
				case PORTD:
					GPIO_Port=GPIOD;
					break;
				case PORTE:
					GPIO_Port=GPIOE;	
					break;
				case PORTF:
					GPIO_Port=GPIOF;	
					break;
				case PORTG:
					GPIO_Port=GPIOG;	
					break;
				case PORTH:
					GPIO_Port=GPIOH;		
					break;
				default:
					break;
			}

			if(PinConfig->Mode==ALTERNATE_FUNCTION)
			{
				/*Select alternative function, Options at @GPIOAltFunc_t*/
				GPIO_Port->AFR[PinConfig->Pin/AFR_PINS_PER_REG]&=~((AFR_MASK)<<((PinConfig->Pin%AFR_PINS_PER_REG)*AFR_BIT_ACCESS));
				GPIO_Port->AFR[PinConfig->Pin/AFR_PINS_PER_REG]|=((PinConfig->AltFunc)<<((PinConfig->Pin%AFR_PINS_PER_REG)*AFR_BIT_ACCESS));
			}
			/*Select GPIO mode, Options at @GPIOMode_t*/
			GPIO_Port->MODER&=~((MODER_MASK)<<((PinConfig->Pin)*MODER_BIT_ACCESS));
			GPIO_Port->MODER|=((PinConfig->Mode)<<((PinConfig->Pin)*MODER_BIT_ACCESS));
			
			if(PinConfig->Mode!=ANALOG)
			{		
				/*Select pull resistance, Options at @GPIOPullResistance_t*/
				GPIO_Port->PUPDR&=~((PUPDR_MASK)<<((PinConfig->Pin)*PUPDR_BIT_ACCESS));
				GPIO_Port->PUPDR|=((PinConfig->PullType)<<((PinConfig->Pin)*PUPDR_BIT_ACCESS));
			}
			
			if(PinConfig->Mode==OUTPUT || PinConfig->Mode==ALTERNATE_FUNCTION)
			{
				/*Select output type, Options at @GPIOOutputType_t*/
				GPIO_Port->OTYPER&=~((OTYPER_MASK)<<(PinConfig->Pin));
				GPIO_Port->OTYPER|=((PinConfig->OutputType)<<(PinConfig->Pin));
				
				/*Select pin speed, Options at @GPIOSpeed_t*/
				GPIO_Port->OSPEEDR&=~((OSPEEDR_MASK)<<((PinConfig->Pin)*OSPEEDR_BIT_ACCESS));
				GPIO_Port->OSPEEDR|=((PinConfig->Speed)<<((PinConfig->Pin)*OSPEEDR_BIT_ACCESS));
			}
			ErrorState=OK;
		}
	}
	else
	{
		ErrorState=NULLPTR;
	}
	
	return ErrorState;
}

/***********************************************************
* @fn GPIO_u8SetPinValue
* @Brief The pin setting function
* @Param[in] Port : The port of the pin, Options at @GPIOPort_t enum
* @Param[in] pinNum : The pin number in the port, Options at @GPIOPin_t enum
* @Param[in] pinVal : The initalization value of the pin, Options at @GPIOPinVal_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t GPIO_u8SetPinValue(GPIOPort_t Port, GPIOPin_t pinNum, GPIOPinVal_t pinVal)
{
	ErrorStatus_t ErrorState=UNKNOWN;
	if(Port>=TOTAL_PORTS || pinNum>=TOTAL_PINS)
	{
		ErrorState=OUT_OF_RANGE;
	}
	else
	{
		GPIO_RegDef_t* GPIO_Port=NullPtr;
		/*Select the desired port*/
		switch(Port)
		{
			case PORTA:
				GPIO_Port=GPIOA;
				break;
			case PORTB:
				GPIO_Port=GPIOB;
				break;
			case PORTC:
				GPIO_Port=GPIOC;	
				break;
			case PORTD:
				GPIO_Port=GPIOD;
				break;
			case PORTE:
				GPIO_Port=GPIOE;	
				break;
			case PORTF:
				GPIO_Port=GPIOF;	
				break;
			case PORTG:
				GPIO_Port=GPIOG;	
				break;
			case PORTH:
				GPIO_Port=GPIOH;		
				break;
			default:
				break;
		}
		
		/*Assign the value to the pin*/
		GPIO_Port->ODR&=~((ODR_MASK)<<pinNum);
		GPIO_Port->ODR|=(pinVal<<pinNum);
		
		ErrorState=OK;
	}
	
	return ErrorState;
}

/***********************************************************
* @fn GPIO_u8TogglePinValue
* @Brief The pin toggling function
* @Param[in] Port : The port of the pin, Options at @GPIOPort_t enum
* @Param[in] pinNum : The pin number in the port, Options at @GPIOPin_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t GPIO_u8TogglePinValue(GPIOPort_t Port, GPIOPin_t pinNum)
{
	ErrorStatus_t ErrorState=UNKNOWN;
	if(Port>=TOTAL_PORTS || pinNum>=TOTAL_PINS)
	{
		ErrorState=OUT_OF_RANGE;
	}
	else
	{
		GPIO_RegDef_t* GPIO_Port=NullPtr;
		/*Select the desired port*/
		switch(Port)
		{
			case PORTA:
				GPIO_Port=GPIOA;
				break;
			case PORTB:
				GPIO_Port=GPIOB;
				break;
			case PORTC:
				GPIO_Port=GPIOC;	
				break;
			case PORTD:
				GPIO_Port=GPIOD;
				break;
			case PORTE:
				GPIO_Port=GPIOE;	
				break;
			case PORTF:
				GPIO_Port=GPIOF;	
				break;
			case PORTG:
				GPIO_Port=GPIOG;	
				break;
			case PORTH:
				GPIO_Port=GPIOH;		
				break;
			default:
				break;
		}
		
		/*Toggle the pin value*/
		GPIO_Port->ODR^=(ODR_BIT_ACCESS<<pinNum);
		
		ErrorState=OK;
	}
	
	return ErrorState;
}

/***********************************************************
* @fn GPIO_u8ReadPinValue
* @Brief The pin reading function
* @Param[in] Port : The port of the pin, Options at @GPIOPort_t enum
* @Param[in] pinNum : The pin number in the port, Options at @GPIOPin_t enum
* @Param[out] pinVal : The read value of the pin
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t GPIO_u8ReadPinValue(GPIOPort_t Port, GPIOPin_t pinNum, GPIOPinVal_t* pinVal)
{
	ErrorStatus_t ErrorState=UNKNOWN;
	if(Port>=TOTAL_PORTS || pinNum>=TOTAL_PINS)
	{
		ErrorState=OUT_OF_RANGE;
	}
	else if(pinVal==NullPtr)
	{
		ErrorState=NULLPTR;
	}
	else
	{
		GPIO_RegDef_t* GPIO_Port=NullPtr;
		/*Select the desired port*/
		switch(Port)
		{
			case PORTA:
				GPIO_Port=GPIOA;
				break;
			case PORTB:
				GPIO_Port=GPIOB;
				break;
			case PORTC:
				GPIO_Port=GPIOC;	
				break;
			case PORTD:
				GPIO_Port=GPIOD;
				break;
			case PORTE:
				GPIO_Port=GPIOE;	
				break;
			case PORTF:
				GPIO_Port=GPIOF;	
				break;
			case PORTG:
				GPIO_Port=GPIOG;	
				break;
			case PORTH:
				GPIO_Port=GPIOH;		
				break;
			default:
				break;
		}
		
		/*Read the pin value*/
		*pinVal=((GPIO_Port->IDR)>>pinNum)&IDR_BIT_ACCESS;
		
		ErrorState=OK;
	}
	
	return ErrorState;
}
