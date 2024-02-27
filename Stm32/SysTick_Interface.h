

#ifndef  SYSTICK_INTERFACE_H_
#define  SYSTICK_INTERFACE_H_


/*@SysTickEnable_t*/
typedef enum
{
	SYSTICK_DISABLED=0,
	SYSTICK_ENABLED,
}SysTickEnable_t;


/*@SysTickClkSrc_t*/
typedef enum
{
	SYSTICK_EXTERNAL_CLK=0,
	SYSTICK_PROCESSOR_CLK,
}SysTickClkSrc_t;



ErrorStatus_t SysTick_Init(SysTickClkSrc_t clk, uint8_t u8ClkValueMHZ);
void SysTick_Delayus(uint32_t u32LocalTime);
void SysTick_Delayms(uint32_t u32LocalTime);
void SysTick_InterruptTimer_ms(uint32_t u32LocalTime_ms);
void SysTick_DisableInterrupt(void);
ErrorStatus_t Systick_InterruptSetCallBack(Fptr Local_Fptr);


#endif
