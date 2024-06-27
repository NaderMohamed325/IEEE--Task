

#ifndef  RCC_INTERFACE_H_
#define  RCC_INTERFACE_H_

//@SysClock_t
typedef enum
{
	SYS_HSI=0,
	SYS_HSE,
	SYS_PLLP,
	SYS_PLLR,
	TOTAL_SYSTEM_CLOCKS
}SysClock_t;

//@ClockSource_t
typedef enum
{
	LSI_CLOCK_SOURCE=0,
	LSE_CLOCK_SOURCE,
	HSI_CLOCK_SOURCE,
	HSE_CLOCK_SOURCE,
	PLL_CLOCK_SOURCE,
	PLLSAI_CLOCK_SOURCE,
	PLLI2S_CLOCK_SOURCE,
	TOTAL_CLOCK_SOURCES
}ClockSource_t;

//@BypassStatus_t
typedef enum
{
	COLCK_NOT_BYPASSED=0,
	COLCK_BYPASSED
}BypassStatus_t;

//@PLL_Source_t
typedef enum
{
	HSI_PLL_SOURCE=0,
	HSE_PLL_SOURCE,
	TOTAL_PLL_SOURCES
}PLL_Source_t;

//@PLLP_Divisor_t
typedef enum
{
	PLLP_2=0,
	PLLP_4,
	PLLP_6,
	PLLP_8,
}PLLP_Divisor_t;

//@PLLR_Divisor_t
typedef enum
{
	PLLR_2=2,
	PLLR_3,
	PLLR_4,	
	PLLR_5,
	PLLR_6,	
	PLLR_7,
}PLLR_Divisor_t;

//@AHB_Prescaler_t
typedef enum
{
	AHB_1=0,
	AHB_2=8,
	AHB_4,
	AHB_8,
	AHB_16,
	AHB_32,
	AHB_64,
	AHB_256,
	AHB_512,
}AHB_Prescaler_t;

//@APB_Prescaler_t
typedef enum
{
	APB_1=0,
	APB_2=4,
	APB_4,
	APB_8,
	APB_16,
}APB_Prescaler_t;

//@ClockStatus_t
typedef enum
{
	CLOCK_STATUS_OFF=0,
	CLOCK_STATUS_ON,
}ClockStatus_t;

//@AHB1_Peripheral_t
typedef enum
{
	AHB1_GPIOA=0,
	AHB1_GPIOB,
	AHB1_GPIOC,
	AHB1_GPIOD,
	AHB1_GPIOE,
	AHB1_GPIOF,
	AHB1_GPIOG,
	AHB1_GPIOH,
	AHB1_CRC=12,
	AHB1_BKPSRAM=18,
	AHB1_DMA1=21,
	AHB1_DMA2,
	AHB1_OTGHS=29,
	AHB1_OTGHSULPI
}AHB1_Peripheral_t;

//@AHB2_Peripheral_t
typedef enum
{
	AHB2_DCMIEN=0,
	AHB2_OTGFSEN=7,
}AHB2_Peripheral_t;

//@AHB3_Peripheral_t
typedef enum
{
	AHB3_FMCEN=0,
	AHB3_QSPIEN,
}AHB3_Peripheral_t;

//@APB1_Peripheral_t
typedef enum
{
	APB1_TIM2=0,
	APB1_TIM3,
	APB1_TIM4,
	APB1_TIM5,
	APB1_TIM6,
	APB1_TIM7,
	APB1_TIM12,
	APB1_TIM13,
	APB1_TIM14,
	APB1_WWDG=11,
	APB1_SPI2=14,
	APB1_SPI3,
	APB1_SPDIFRX,
	APB1_USART2,
	APB1_USART3,
	APB1_UART4,
	APB1_UART5,
	APB1_I2C1,
	APB1_I2C2,
	APB1_I2C3,
	APB1_FMPI2C1,
	APB1_CAN1,
	APB1_CAN2,
	APB1_CEC,
	APB1_PWR,
	APB1_DAC,
}APB1_Peripheral_t;

//@APB2_Peripheral_t
typedef enum
{
	APB2_TIM1=0,
	APB2_TIM8,
	APB2_USART1=4,
	APB2_USART6,
	APB2_ADC1=8,
	APB2_ADC2,
	APB2_ADC3,
	APB2_SDIO,
	APB2_SPI1,
	APB2_SPI4,
	APB2_SYSCFG,
	APB2_TIM9=16,
	APB2_TIM10,
	APB2_TIM11,
	APB2_SAI1=22,
	APB2_SAI2,
}APB2_Peripheral_t;



ErrorStatus_t RCC_SetSysClock(SysClock_t clk);
ErrorStatus_t RCC_SetClockStatus(ClockSource_t clk, ClockStatus_t stat, BypassStatus_t bypass);
ErrorStatus_t RCC_PLLMConfig(PLL_Source_t src, uint16_t u16Localpllm, uint16_t u16Localplln, PLLP_Divisor_t pllp_d, PLLR_Divisor_t pllr_d);
ErrorStatus_t RCC_AHBConfig(AHB_Prescaler_t AHB_Pre);
ErrorStatus_t RCC_APBConfig(APB_Prescaler_t APB1_Pre , APB_Prescaler_t APB2_Pre);
ErrorStatus_t RCC_AHB1EnableClock(AHB1_Peripheral_t peripheral);
ErrorStatus_t RCC_AHB1DisableClock(AHB1_Peripheral_t peripheral);
ErrorStatus_t RCC_AHB2EnableClock(AHB2_Peripheral_t peripheral);
ErrorStatus_t RCC_AHB2DisableClock(AHB2_Peripheral_t peripheral);
ErrorStatus_t RCC_AHB3EnableClock(AHB3_Peripheral_t peripheral);
ErrorStatus_t RCC_AHB3DisableClock(AHB3_Peripheral_t peripheral);
ErrorStatus_t RCC_APB1EnableClock(APB1_Peripheral_t peripheral);
ErrorStatus_t RCC_APB1DisableClock(APB1_Peripheral_t peripheral);
ErrorStatus_t RCC_APB2EnableClock(APB2_Peripheral_t peripheral);
ErrorStatus_t RCC_APB2DisableClock(APB2_Peripheral_t peripheral);


#endif
