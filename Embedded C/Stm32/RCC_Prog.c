
#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"

#include "RCC_Interface.h"
#include "RCC_prv.h"


/***********************************************************
* @fn RCC_SetSysClock
* @Brief Function for setting the system clock
* @Param[in] clk : The source of the system clock, Options at @SysClock_t enum 
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_SetSysClock(SysClock_t clk)
{
	ErrorStatus_t LocalErrorState=UNKNOWN;
	if(clk>=TOTAL_SYSTEM_CLOCKS) LocalErrorState=OUT_OF_RANGE;
	else
	{
		((RCC->RCC_CFGR_U).RCC_CFGR_S).SW=clk;
		LocalErrorState=OK;
	}

	return LocalErrorState;
}


/***********************************************************
* @fn RCC_SetClockStatus
* @Brief Function for switch on or off each clock source
* @Param[in] clk : The clock source, Options at @ClockSource_t enum
* @Param[in] stat : clock status, Options at @ClockStatus_t enum
* @Param[in] bypass : bypass status, Options at @BypassStatus_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_SetClockStatus(ClockSource_t clk, ClockStatus_t stat, BypassStatus_t bypass)
{
	ErrorStatus_t LocalErrorState=UNKNOWN;
	uint16_t u16LocalTimeCounter=0;

	if(clk>=TOTAL_CLOCK_SOURCES || stat>=CLOCK_STATUS_ON)
	{
		LocalErrorState=OUT_OF_RANGE;
	}
	else
	{
		switch(clk)
		{
			case LSI_CLOCK_SOURCE:
				((RCC->RCC_CSR_U).RCC_CSR_S).LSI_ON=stat;
				while((!((RCC->RCC_CSR_U).RCC_CSR_S).LSI_RDY) && (u16LocalTimeCounter<RDY_CLK_RUNTIME)) u16LocalTimeCounter++;
				break;
			case LSE_CLOCK_SOURCE:
				((RCC->RCC_BDCR_U).RCC_BDCR_S).LSE_BYP=bypass;
				((RCC->RCC_BDCR_U).RCC_BDCR_S).LSE_ON=stat;
				while((!((RCC->RCC_BDCR_U).RCC_BDCR_S).LSE_RDY) && (u16LocalTimeCounter<RDY_CLK_RUNTIME)) u16LocalTimeCounter++;
				break;
			case HSI_CLOCK_SOURCE:
				((RCC->RCC_CR_U).RCC_CR_S).HSI_ON=stat;
				while((!((RCC->RCC_CR_U).RCC_CR_S).HSI_RDY) && (u16LocalTimeCounter<RDY_CLK_RUNTIME)) u16LocalTimeCounter++;
				break;
			case HSE_CLOCK_SOURCE:
				((RCC->RCC_CR_U).RCC_CR_S).HSE_BYP=bypass;
				((RCC->RCC_CR_U).RCC_CR_S).HSE_ON=stat;
				while((!((RCC->RCC_CR_U).RCC_CR_S).HSE_RDY) && (u16LocalTimeCounter<RDY_CLK_RUNTIME)) u16LocalTimeCounter++;
				break;
			case PLL_CLOCK_SOURCE:
				((RCC->RCC_CR_U).RCC_CR_S).PLL_ON=stat;
				while((!((RCC->RCC_CR_U).RCC_CR_S).PLL_RDY) && (u16LocalTimeCounter<RDY_CLK_RUNTIME)) u16LocalTimeCounter++;
				break;
			case PLLSAI_CLOCK_SOURCE:
				((RCC->RCC_CR_U).RCC_CR_S).PLLSAI_ON=stat;
				while((!((RCC->RCC_CR_U).RCC_CR_S).PLLSA_RDY) && (u16LocalTimeCounter<RDY_CLK_RUNTIME)) u16LocalTimeCounter++;
				break;
			case PLLI2S_CLOCK_SOURCE:
				((RCC->RCC_CR_U).RCC_CR_S).PLLI2S_ON=stat;
				while((!((RCC->RCC_CR_U).RCC_CR_S).PLLI2S_RDY) && (u16LocalTimeCounter<RDY_CLK_RUNTIME)) u16LocalTimeCounter++;
				break;
			default:
				break;
		}
		if(u16LocalTimeCounter>=RDY_CLK_RUNTIME) LocalErrorState=RUNTIME_OUT;
		else LocalErrorState=OK;
	}

	return LocalErrorState;
}


/***********************************************************
* @fn RCC_PLLMConfig
* @Brief Function for setting PLL status
* @Param[in] src : The source of the clock for PLL, Options at @PLL_Source_t enum
* @Param[in] pllm : The PLL divisor
* @Param[in] plln : The PLL multiplier
* @Param[in] pllp_d : The PLLP divisor, Options at @PLLP_Divisor_t enum
* @Param[in] pllr_d : The PLLR divisor, Options at @PLLR_Divisor_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_PLLMConfig(PLL_Source_t src, uint16_t u16Localpllm, uint16_t u16Localplln, PLLP_Divisor_t pllp_d, PLLR_Divisor_t pllr_d)
{
	ErrorStatus_t LocalErrorState=UNKNOWN;
	if(src>=TOTAL_PLL_SOURCES ||
	   u16Localpllm>PLLM_DIVISOR_MAX || u16Localpllm<PLLM_DIVISOR_MIN ||
	   u16Localplln>PLLN_MULTIRIPLIER_MAX || u16Localplln<PLLN_MULTIRIPLIER_MIN ||
	   pllp_d>PLLP_8 || pllr_d>PLLR_7)
	{
		LocalErrorState=OUT_OF_RANGE;
	}
	else
	{
		((RCC->RCC_PLLCFGR_U).RCC_PLLCFGR_S).PLLSRC=src;
		((RCC->RCC_PLLCFGR_U).RCC_PLLCFGR_S).PLLM=u16Localpllm;
		((RCC->RCC_PLLCFGR_U).RCC_PLLCFGR_S).PLLN=u16Localplln;
		((RCC->RCC_PLLCFGR_U).RCC_PLLCFGR_S).PLLP=pllp_d;
		((RCC->RCC_PLLCFGR_U).RCC_PLLCFGR_S).PLLR=pllr_d;
		LocalErrorState=OK;
	}

	return LocalErrorState;
}


/***********************************************************
* @fn RCC_AHBMConfig
* @Brief Function for setting AHB prescaler
* @Param[in] AHB_Pre : The AHB prescaler, Options at @AHB_Prescaler_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_AHBConfig(AHB_Prescaler_t AHB_Pre)
{
	ErrorStatus_t LocalErrorState=UNKNOWN;
	if(AHB_Pre>AHB_512) LocalErrorState=OUT_OF_RANGE;
	else
	{
		((RCC->RCC_CFGR_U).RCC_CFGR_S).HPRE=AHB_Pre;
		LocalErrorState=OK;
	}

	return LocalErrorState;
}


/***********************************************************
* @fn RCC_AHBMConfig
* @Brief Function for setting APB1 and ABP2 prescaler
* @Param[in] APB1_Pre : The APB1 prescaler, Options at @APB_Prescaler_t enum
* @Param[in] APB2_Pre : The ABP2 prescaler, Options at @APB_Prescaler_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_APBConfig(APB_Prescaler_t APB1_Pre , APB_Prescaler_t APB2_Pre)
{
	ErrorStatus_t LocalErrorState=UNKNOWN;
	if(APB1_Pre>APB_16 || APB2_Pre>APB_16) LocalErrorState=OUT_OF_RANGE;
	else
	{
		((RCC->RCC_CFGR_U).RCC_CFGR_S).PPRE1=APB1_Pre;
		((RCC->RCC_CFGR_U).RCC_CFGR_S).PPRE2=APB2_Pre;
		LocalErrorState=OK;
	}

	return LocalErrorState;
}


/***********************************************************
* @fn RCC_AHB1EnableClock
* @Brief Function for switching on the AHB1 peripherals
* @Param[in] peripheral : The AHB1 peripherals, Options at @AHB1_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_AHB1EnableClock(AHB1_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_AHB1ENR_U).RCC_AHB1ENR|=(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_AHB1DisableClock
* @Brief Function for switching off the AHB1 peripherals
* @Param[in] peripheral : The AHB1 peripherals, Options at @AHB1_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_AHB1DisableClock(AHB1_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_AHB1ENR_U).RCC_AHB1ENR&=~(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_AHB2EnableClock
* @Brief Function for switching on the AHB2 peripherals
* @Param[in] peripheral : The AHB2 peripherals, Options at @AHB2_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_AHB2EnableClock(AHB2_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_AHB2ENR_U).RCC_AHB2ENR|=(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_AHB2DisableClock
* @Brief Function for switching off the AHB2 peripherals
* @Param[in] peripheral : The AHB2 peripherals, Options at @AHB2_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_AHB2DisableClock(AHB2_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_AHB2ENR_U).RCC_AHB2ENR&=~(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_AHB3DisableClock
* @Brief Function for switching on the AHB3 peripherals
* @Param[in] peripheral : The AHB3 peripherals, Options at @AHB3_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_AHB3EnableClock(AHB3_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_AHB3ENR_U).RCC_AHB3ENR|=(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_AHB3DisableClock
* @Brief Function for switching off the AHB3 peripherals
* @Param[in] peripheral : The AHB3 peripherals, Options at @AHB3_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_AHB3DisableClock(AHB3_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_AHB3ENR_U).RCC_AHB3ENR&=~(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_APB1EnableClock
* @Brief Function for switching on the APB1 peripherals
* @Param[in] peripheral : The APB1 peripherals, Options at @APB1_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_APB1EnableClock(APB1_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_APB1ENR_U).RCC_APB1ENR|=(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_APB1EnableClock
* @Brief Function for switching off the APB1 peripherals
* @Param[in] peripheral : The APB1 peripherals, Options at @APB1_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_APB1DisableClock(APB1_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_APB1ENR_U).RCC_APB1ENR&=~(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_APB2EnableClock
* @Brief Function for switching on the APB2 peripherals
* @Param[in] peripheral : The APB2 peripherals, Options at @APB2_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_APB2EnableClock(APB2_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_APB2ENR_U).RCC_APB2ENR|=(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}


/***********************************************************
* @fn RCC_APB2EnableClock
* @Brief Function for switching off the APB2 peripherals
* @Param[in] peripheral : The APB2 peripherals, Options at @APB2_Peripheral_t enum
* @retval ErrorStatus_t, Options at @ErrorStatus_t enum
***********************************************************/
ErrorStatus_t RCC_APB2DisableClock(APB2_Peripheral_t peripheral)
{
	ErrorStatus_t LocalErrorState=OK;
	(RCC->RCC_APB2ENR_U).RCC_APB2ENR&=~(PERIPHERAL_BIT_ACCESS<<peripheral);
	return LocalErrorState;
}
