
#ifndef  GPIO_INTERFACE_H_
#define  GPIO_INTERFACE_H_

//@GPIOPort_t
typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH,
	TOTAL_PORTS
}GPIOPort_t;

//@GPIOPin_t
typedef enum
{
	PIN0=0,
	PIN1,	
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	TOTAL_PINS
}GPIOPin_t;

//@GPIOMode_t
typedef enum
{
	INPUT=0,
	OUTPUT,
	ALTERNATE_FUNCTION,
	ANALOG,
}GPIOMode_t;

//@GPIOSpeed_t
typedef enum
{
	LOW_SPEED=0,
	MEDIUM_SPEED,
	FAST_SPEED,
	HIGH_SPEED,
}GPIOSpeed_t;

//@GPIOOutputType_t
typedef enum
{
	PUSH_PULL=0,
	OPEN_DRAIN,
}GPIOOutputType_t;

//@GPIOPullResistance_t
typedef enum
{
	NO_PULL=0,
	PULL_UP,
	PULL_DOWN,
}GPIOPullResistance_t;

//@GPIOPinVal_t
typedef enum
{
	PIN_LOW=0,
	PIN_HIGH,
}GPIOPinVal_t;

//@GPIOAltFunc_t
typedef enum
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,
	TOTAL_ALT_FUNCS
}GPIOAltFunc_t;

typedef struct
{
	GPIOPort_t Port;
	GPIOPin_t Pin;
	GPIOMode_t Mode;
	GPIOSpeed_t Speed;
	GPIOOutputType_t OutputType;
	GPIOPullResistance_t PullType;
	GPIOAltFunc_t AltFunc;
}PinConfig_t;


ErrorStatus_t GPIO_u8PinInit(const PinConfig_t* PinConfig);
ErrorStatus_t GPIO_u8SetPinValue(GPIOPort_t Port, GPIOPin_t pinNum, GPIOPinVal_t pinVal);
ErrorStatus_t GPIO_u8TogglePinValue(GPIOPort_t Port, GPIOPin_t pinNum);
ErrorStatus_t GPIO_u8ReadPinValue(GPIOPort_t Port, GPIOPin_t pinNum, GPIOPinVal_t* pinVal);



#endif
