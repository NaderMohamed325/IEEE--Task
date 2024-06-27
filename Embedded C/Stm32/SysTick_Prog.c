
#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"

#include "SysTick_Interface.h"
#include "SysTick_prv.h"



static uint8_t u8FCPU_ValueMHZ;
static Fptr SysTick_Fptr;

/***********************************************************
* @fn SysTick_Init
* @Brief The sysTick timer initialization function
* @Param[in] clk : The systick clock source, Options at @SysTickClkSrc_t enum
* @Param[in] u8ClkValueMHZ : Clock source value in MHZ
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t SysTick_Init(SysTickClkSrc_t clk, uint8_t u8ClkValueMHZ)
{
	ErrorStatus_t ErrorState=UNKNOWN;
	/*Checking valid clock source and exception values*/
	if(clk>SYSTICK_PROCESSOR_CLK || u8ClkValueMHZ>MAX_CLOCK) ErrorState=OUT_OF_RANGE;
	else
	{
		/*Setting clock source*/
		SYSTICK->SYST_CSR &= ~(SYSTICK_BIT_ACCESS<<CLKSOURCE);
		SYSTICK->SYST_CSR |=  (clk<<CLKSOURCE);
		/*Taking the clock source value*/
		u8FCPU_ValueMHZ=u8ClkValueMHZ;

		ErrorState=OK;
	}
	return ErrorState;
}

/***********************************************************
* @fn SysTick_Delayus
* @Brief Delay with sysTick timer function
* @Param[in] u32LocalTime : The delay time in microseconds
* @retval void
***********************************************************/
void SysTick_Delayus(uint32_t u32LocalTime_us)
{
	/*Checking the usage of clock source divider*/
	if(((SYSTICK->SYST_CSR>>CLKSOURCE)&1)==0)
	{
		/*setting the time value in the register*/
		SYSTICK->SYST_RVR=u32LocalTime_us*u8FCPU_ValueMHZ/SYSTICK_EXCLOCK_DIV;
	}
	else
	{
		/*setting the time value in the register*/
		SYSTICK->SYST_RVR=u32LocalTime_us*u8FCPU_ValueMHZ;
	}
	/*Enable Counting*/
	SYSTICK->SYST_CSR|=SYSTICK_BIT_ACCESS<<ENABLE;
	/*Waiting till finishing counting*/
	while(!(((SYSTICK->SYST_CSR)>>COUNTFLAG)&SYSTICK_BIT_ACCESS));
	/*Disable Counting*/
	SYSTICK->SYST_CSR&=~(SYSTICK_BIT_ACCESS<<ENABLE);
}

/***********************************************************
* @fn SysTick_Delayms
* @Brief Delay with sysTick timer function
* @Param[in] u32LocalTime : The delay time in milliseconds
* @retval void
***********************************************************/
void SysTick_Delayms(uint32_t u32LocalTime_ms)
{
	/*Calling the microsecond delay function after transferring milliseconds into microseconds*/
	SysTick_Delayus(u32LocalTime_ms*TIME_MS_TO_US);
}

/***********************************************************
* @fn SysTick_InterruptTimer
* @Brief using sysTick timer exception
* @Param[in] u32LocalTime : The delay time in microseconds
* @retval void
***********************************************************/
void SysTick_InterruptTimer_ms(uint32_t u32LocalTime_ms)
{
	/*Checking the usage of clock source divider*/
	if(((SYSTICK->SYST_CSR>>CLKSOURCE)&1)==0)
	{
		/*setting the time value in the register*/
		SYSTICK->SYST_RVR=u32LocalTime_ms*TIME_MS_TO_US*u8FCPU_ValueMHZ/SYSTICK_EXCLOCK_DIV;
	}
	else
	{
		/*setting the time value in the register*/
		SYSTICK->SYST_RVR=u32LocalTime_ms*TIME_MS_TO_US*u8FCPU_ValueMHZ;
	}
	/*Enabling exception*/
	SYSTICK->SYST_CSR |=  (SYSTICK_BIT_ACCESS<<TICKINT);
	/*Enable Counting*/
	SYSTICK->SYST_CSR|=SYSTICK_BIT_ACCESS<<ENABLE;
}

/***********************************************************
* @fn SysTick_DisableInterrupt
* @Brief Disabling sysTick timer exception
* @Param void
* @retval void
***********************************************************/
void SysTick_DisableInterrupt(void)
{
	/*Disabling exception*/
	SYSTICK->SYST_CSR &= ~(SYSTICK_BIT_ACCESS<<TICKINT);
}

/***********************************************************
* @fn Systick_InterruptSetCallBack
* @Brief Disabling sysTick timer exception
* @Param[in] Local_Fptr: the callback function
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t Systick_InterruptSetCallBack(Fptr Local_Fptr)
{
	ErrorStatus_t ErrorState=UNKNOWN;
	/*Ensuring pointer is not null pointer*/
	if(Local_Fptr==NullPtr)
	{
		ErrorState=NULLPTR;
	}
	else
	{
		/*Setting the value of the global pointer to function*/
		SysTick_Fptr=Local_Fptr;
		ErrorState=OK;
	}

	return ErrorState;
}


/**********************************		IRQs	 ********************************/
void SysTick_Handler(void)
{
	if(SysTick_Fptr!=NullPtr)
	{
		SysTick_Fptr();
	}
}






