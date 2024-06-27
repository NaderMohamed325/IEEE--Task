
#ifndef  STM32F446xx_H_
#define  STM32F446xx_H_



/************************		MEMORIES BASE ADRESSES		************************/

#define  FLASH_BASE_ADDRESS    0x08000000U
#define  SRAM_BASE_ADDRESS     0x20000000U
#define  ROM_BASE_ADDRESS      0x1FFF0000U


/************************		AHB1 BASE ADRESSES		************************/

#define  GPIOA_BASE_ADDRESS    0X40020000U          
#define  GPIOB_BASE_ADDRESS    0X40020400U              
#define  GPIOC_BASE_ADDRESS    0X40020800U              
#define  GPIOD_BASE_ADDRESS    0X40020C00U              
#define  GPIOE_BASE_ADDRESS    0X40021000U              
#define  GPIOF_BASE_ADDRESS    0X40021400U              
#define  GPIOG_BASE_ADDRESS    0X40021800U              
#define  GPIOH_BASE_ADDRESS    0X40021C00U              
          
#define  RCC_BASE_ADDRESS      0x40023800U

#define  SYSTICK_BASE_ADDRESS  0xE000E010U

#define  DMA1_BASE_ADDRESS     0x40026000U
#define  DMA2_BASE_ADDRESS     0x40026400U

/************************		AHB2 BASE ADRESSES		************************/


/************************		AHB3 BASE ADRESSES		************************/


/************************		APB1 BASE ADRESSES		************************/

#define     USART2_BASE_ADDRESS      0x40004400U
#define     USART3_BASE_ADDRESS      0x40004800U
#define     UART4_BASE_ADDRESS       0x40004C00U
#define     UART5_BASE_ADDRESS       0x40005000U

#define     SPI2_BASE_ADDRESS        0x40003800U
#define     SPI3_BASE_ADDRESS        0x40003C00U

#define     I2C1_BASE_ADDRESS        0x40005400U
#define     I2C2_BASE_ADDRESS        0x40005800U
#define     I2C3_BASE_ADDRESS        0x40005C00U
/************************		APB2 BASE ADRESSES		************************/

#define     USART1_BASE_ADDRESS      0x40011000U
#define     USART6_BASE_ADDRESS      0x40011400U

#define     SPI1_BASE_ADDRESS        0x40013000U
#define     SPI4_BASE_ADDRESS        0x40013400U

/************************		GPIO RESISTER STRUCTURE		************************/

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_RegDef_t;


/************************		RCC RESISTER STRUCTURE		************************/

typedef struct
{
	volatile uint32_t HSI_ON:1;
	volatile uint32_t HSI_RDY:1;
	uint32_t 		  CR_RESERVER_BITS1:1;
	volatile uint32_t HSI_TRIM:5;
	volatile uint32_t HSI_CAL:8;
	volatile uint32_t HSE_ON:1;
	volatile uint32_t HSE_RDY:1;
	volatile uint32_t HSE_BYP:1;
	volatile uint32_t CSS_ON:1;
	uint32_t 		  CR_RESERVER_BITS2:4;
	volatile uint32_t PLL_ON:1;
	volatile uint32_t PLL_RDY:1;
	volatile uint32_t PLLI2S_ON:1;
	volatile uint32_t PLLI2S_RDY:1;
	volatile uint32_t PLLSAI_ON:1;
	volatile uint32_t PLLSA_RDY:1;
}RCC_CR_S;

typedef union
{
	volatile uint32_t RCC_CR;
	RCC_CR_S RCC_CR_S;
}RCC_CR_U;


typedef struct
{
	volatile uint32_t PLLM:6;
	volatile uint32_t PLLN:9;
	uint32_t 		  PLLCFGR_RESERVER_BITS1:1;
	volatile uint32_t PLLP:2;
	uint32_t 		  PLLCFGR_RESERVER_BITS2:4;
	volatile uint32_t PLLSRC:1;
	uint32_t 		  PLLCFGR_RESERVER_BITS3:1;
	volatile uint32_t PLLQ:4;
	volatile uint32_t PLLR:3;
}RCC_PLLCFGR_S;

typedef union
{
	volatile uint32_t RCC_PLLCFGR;
	RCC_PLLCFGR_S RCC_PLLCFGR_S;
}RCC_PLLCFGR_U;


typedef struct
{
	volatile uint32_t SW:2;
	volatile uint32_t SWS:2;
	volatile uint32_t HPRE:4;
	uint32_t 		  CFGR_RESERVER_BITS1:2;
	volatile uint32_t PPRE1:3;
	volatile uint32_t PPRE2:3;
	volatile uint32_t RTCPRE:5;
	volatile uint32_t MCO1:2;
	uint32_t 		  CFGR_RESERVER_BITS2:1;
	volatile uint32_t MCO1_PRE:3;
	volatile uint32_t MCO2_PRE:3;
	volatile uint32_t MCO2:2;
}RCC_CFGR_S;

typedef union
{
	volatile uint32_t RCC_CFGR;
	RCC_CFGR_S RCC_CFGR_S;
}RCC_CFGR_U;


typedef struct
{
	volatile uint32_t LSI_RDYF:1;
	volatile uint32_t LSE_RDYF:1;
	volatile uint32_t HSI_RDYF:1;
	volatile uint32_t HSE_RDYF:1;
	volatile uint32_t PLL_RDYF:1;
	volatile uint32_t PLLI2S_RDYF:1;
	volatile uint32_t PLLSAI_RDYF:1;
	volatile uint32_t CSSF:1;
	volatile uint32_t LSI_RDYIE:1;
	volatile uint32_t LSE_RDYIE:1;
	volatile uint32_t HSI_RDYIE:1;
	volatile uint32_t HSE_RDYIE:1;
	volatile uint32_t PLL_RDYIE:1;
	volatile uint32_t PLLI2S_RDYIE:1;
	volatile uint32_t PLLSAI_RDYIE:1;
	uint32_t 		  CIR_RESERVER_BITS1:1;
	volatile uint32_t LSI_RDYC:1;
	volatile uint32_t LSE_RDYC:1;
	volatile uint32_t HSI_RDYC:1;
	volatile uint32_t HSE_RDYC:1;
	volatile uint32_t PLL_RDYC:1;
	volatile uint32_t PLLI2S_RDYC:1;
	volatile uint32_t PLLSAI_RDYC:1;
	volatile uint32_t CSSC:1;
}RCC_CIR_S;

typedef union
{
	volatile uint32_t RCC_CIR;
	RCC_CIR_S RCC_CIR_S;
}RCC_CIR_U;


typedef struct
{
	volatile uint32_t GPIOA_RST:1;
	volatile uint32_t GPIOB_RST:1;
	volatile uint32_t GPIOC_RST:1;
	volatile uint32_t GPIOD_RST:1;
	volatile uint32_t GPIOE_RST:1;
	volatile uint32_t GPIOF_RST:1;
	volatile uint32_t GPIOG_RST:1;
	volatile uint32_t GPIOH_RST:1;
	uint32_t 		  AHB1RSTR_RESERVER_BITS1:4;
	volatile uint32_t CRC_RST:1;
	uint32_t          AHB1RSTR_RESERVER_BITS2:8;
	volatile uint32_t DMA1_RST:1;
	volatile uint32_t DMA2_RST:1;
	uint32_t          AHB1RSTR_RESERVER_BITS3:6;
	volatile uint32_t OTGHS_RST:1;
}RCC_AHB1RSTR_S;

typedef union
{
    volatile uint32_t RCC_AHB1RSTR;
    RCC_AHB1RSTR_S RCC_AHB1RSTR_S;
}RCC_AHB1RSTR_U;


typedef struct
{
	volatile uint32_t DCMI_RST:1;
	uint32_t 		  AHB2RSTR_RESERVER_BITS1:6;
	volatile uint32_t OTGFS_RST:1;
}RCC_AHB2RSTR_S;

typedef union
{
    volatile uint32_t RCC_AHB2RSTR;
    RCC_AHB2RSTR_S RCC_AHB2RSTR_S;
}RCC_AHB2RSTR_U;


typedef struct
{
	volatile uint32_t FMC_RST:1;
	volatile uint32_t QSPI_RST:1;
}RCC_AHB3RSTR_S;

typedef union
{
    volatile uint32_t RCC_AHB3RSTR;
    RCC_AHB3RSTR_S RCC_AHB3RSTR_S;
}RCC_AHB3RSTR_U;


typedef struct
{
	volatile uint32_t TIM2_RST:1;
	volatile uint32_t TIM3_RST:1;
	volatile uint32_t TIM4_RST:1;
	volatile uint32_t TIM5_RST:1;
	volatile uint32_t TIM6_RST:1;
	volatile uint32_t TIM7_RST:1;
	volatile uint32_t TIM12_RST:1;
	volatile uint32_t TIM13_RST:1;
	volatile uint32_t TIM14_RST:1;
	uint32_t 		  APB1RST_RESERVER_BITS1:2;
	volatile uint32_t WWDG_RST:1;
	uint32_t 		  APB1RST_RESERVER_BITS2:2;
	volatile uint32_t SPI2_RST:1;
	volatile uint32_t SPI3_RST:1;
	volatile uint32_t SPDIFRX_RST:1;
	volatile uint32_t USART2_RST:1;
	volatile uint32_t USART3_RST:1;
	volatile uint32_t UART4_RST:1;
	volatile uint32_t UART5_RST:1;
	volatile uint32_t I2C1_RST:1;
	volatile uint32_t I2C2_RST:1;
	volatile uint32_t I2C3_RST:1;
	volatile uint32_t FMPI2C1_RST:1;
	volatile uint32_t CAN1_RST:1;
	volatile uint32_t CAN2_RST:1;
	volatile uint32_t CEC_RST:1;
	volatile uint32_t PWR_RST:1;
	volatile uint32_t DAC_RST:1;
}RCC_APB1RSTR_S;

typedef union
{
    volatile uint32_t RCC_APB1RSTR;
    RCC_APB1RSTR_S RCC_APB1RSTR_S;
}RCC_APB1RSTR_U;


typedef struct
{
	volatile uint32_t TIM1_RST:1;
	volatile uint32_t TIM8_RST:1;
	uint32_t 		  APB2RST_RESERVER_BITS1:2;
	volatile uint32_t USART1_RST:1;
	volatile uint32_t USART6_RST:1;
	uint32_t 		  APB2RST_RESERVER_BITS2:2;
	volatile uint32_t ADC_RST:1;
	uint32_t 		  APB2RST_RESERVER_BITS3:2;
	volatile uint32_t SDIO_RST:1;
	volatile uint32_t SPI1_RST:1;
	volatile uint32_t SPI4_RST:1;
	volatile uint32_t SYSCFG_RST:1;
	uint32_t 		  APB2RST_RESERVER_BITS4:1;
	volatile uint32_t TIM9_RST:1;
	volatile uint32_t TIM10_RST:1;
	volatile uint32_t TIM11_RST:1;
	uint32_t 		  APB2RST_RESERVER_BITS5:3;
	volatile uint32_t SAI1_RST:1;
	volatile uint32_t SAI2_RST:1;
}RCC_APB2RSTR_S;

typedef union
{
    volatile uint32_t RCC_APB2RSTR;
    RCC_APB2RSTR_S RCC_APB2RSTR_S;
}RCC_APB2RSTR_U;


typedef struct
{
	volatile uint32_t GPIOA_EN:1;
	volatile uint32_t GPIOB_EN:1;
	volatile uint32_t GPIOC_EN:1;
	volatile uint32_t GPIOD_EN:1;
	volatile uint32_t GPIOE_EN:1;
	volatile uint32_t GPIOF_EN:1;
	volatile uint32_t GPIOG_EN:1;
	volatile uint32_t GPIOH_EN:1;
	uint32_t 		  AHB1ENR_RESERVER_BITS1:4;
	volatile uint32_t CRC_EN:1;
	uint32_t          AHB1ENR_RESERVER_BITS2:5;
	volatile uint32_t BKPSRAM_EN:1;
	uint32_t          AHB1ENR_RESERVER_BITS3:2;
	volatile uint32_t DMA1_EN:1;
	volatile uint32_t DMA2_EN:1;
	uint32_t          AHB1ENR_RESERVER_BITS4:6;
	volatile uint32_t OTGHS_EN:1;
	volatile uint32_t OTGHSULPI_EN:1;
}RCC_AHB1ENR_S;

typedef union
{
    volatile uint32_t RCC_AHB1ENR;
    RCC_AHB1ENR_S RCC_AHB1ENR_S;
}RCC_AHB1ENR_U;


typedef struct
{
	volatile uint32_t DCMI_EN:1;
	uint32_t 		  AHB2ENR_RESERVER_BITS1:6;
	volatile uint32_t OTGFS_EN:1;
}RCC_AHB2ENR_S;

typedef union
{
    volatile uint32_t RCC_AHB2ENR;
    RCC_AHB2ENR_S RCC_AHB2ENR_S;
}RCC_AHB2ENR_U;


typedef struct
{
	volatile uint32_t FMC_EN:1;
	volatile uint32_t QSPI_EN:1;
}RCC_AHB3ENR_S;

typedef union
{
    volatile uint32_t RCC_AHB3ENR;
    RCC_AHB3ENR_S RCC_AHB3ENR_S;
}RCC_AHB3ENR_U;


typedef struct
{
	volatile uint32_t TIM2_EN:1;
	volatile uint32_t TIM3_EN:1;
	volatile uint32_t TIM4_EN:1;
	volatile uint32_t TIM5_EN:1;
	volatile uint32_t TIM6_EN:1;
	volatile uint32_t TIM7_EN:1;
	volatile uint32_t TIM12_EN:1;
	volatile uint32_t TIM13_EN:1;
	volatile uint32_t TIM14_EN:1;
	uint32_t 		  APB1ENR_RESERVER_BITS1:2;
	volatile uint32_t WWDG_EN:1;
	uint32_t 		  APB1ENR_RESERVER_BITS2:2;
	volatile uint32_t SPI2_EN:1;
	volatile uint32_t SPI3_EN:1;
	volatile uint32_t SPDIFRX_EN:1;
	volatile uint32_t USART2_EN:1;
	volatile uint32_t USART3_EN:1;
	volatile uint32_t UART4_EN:1;
	volatile uint32_t UART5_EN:1;
	volatile uint32_t I2C1_EN:1;
	volatile uint32_t I2C2_EN:1;
	volatile uint32_t I2C3_EN:1;
	volatile uint32_t FMPI2C1_EN:1;
	volatile uint32_t CAN1_EN:1;
	volatile uint32_t CAN2_EN:1;
	volatile uint32_t CEC_EN:1;
	volatile uint32_t PWR_EN:1;
	volatile uint32_t DAC_EN:1;
}RCC_APB1ENR_S;

typedef union
{
    volatile uint32_t RCC_APB1ENR;
    RCC_APB1ENR_S RCC_APB1ENR_S;
}RCC_APB1ENR_U;


typedef struct
{
	volatile uint32_t TIM1_EN:1;
	volatile uint32_t TIM8_EN:1;
	uint32_t 		  APB2ENR_RESERVER_BITS1:2;
	volatile uint32_t USART1_EN:1;
	volatile uint32_t USART6_EN:1;
	uint32_t 		  APB2ENR_RESERVER_BITS2:2;
	volatile uint32_t ADC1_EN:1;
	volatile uint32_t ADC2_EN:1;
	volatile uint32_t ADC3_EN:1;
	volatile uint32_t SDIO_EN:1;
	volatile uint32_t SPI1_EN:1;
	volatile uint32_t SPI4_EN:1;
	volatile uint32_t SYSCFG_EN:1;
	uint32_t 		  APB2ENR_RESERVER_BITS3:1;
	volatile uint32_t TIM9_EN:1;
	volatile uint32_t TIM10_EN:1;
	volatile uint32_t TIM11_EN:1;
	uint32_t 		  APB2ENR_RESERVER_BITS4:3;
	volatile uint32_t SAI1_EN:1;
	volatile uint32_t SAI2_EN:1;
}RCC_APB2ENR_S;

typedef union
{
    volatile uint32_t RCC_APB2ENR;
    RCC_APB2ENR_S RCC_APB2ENR_S;
}RCC_APB2ENR_U;


typedef struct
{
	volatile uint32_t GPIOA_LPEN:1;
	volatile uint32_t GPIOB_LPEN:1;
	volatile uint32_t GPIOC_LPEN:1;
	volatile uint32_t GPIOD_LPEN:1;
	volatile uint32_t GPIOE_LPEN:1;
	volatile uint32_t GPIOF_LPEN:1;
	volatile uint32_t GPIOG_LPEN:1;
	volatile uint32_t GPIOH_LPEN:1;
	uint32_t 		  AHB1LPENR_RESERVER_BITS1:4;
	volatile uint32_t CRC_LPEN:1;
	uint32_t          AHB1LPENR_RESERVER_BITS2:2;
	volatile uint32_t FLITF_LPEN:1;
	volatile uint32_t SRAM1_LPEN:1;
	volatile uint32_t SRAM2_LPEN:1;
	volatile uint32_t BKPSRAM_LPEN:1;
	uint32_t          AHB1LPENR_RESERVER_BITS3:2;
	volatile uint32_t DMA1_LPEN:1;
	volatile uint32_t DMA2_LPEN:1;
	uint32_t          AHB1LPENR_RESERVER_BITS4:6;
	volatile uint32_t OTGHS_LPEN:1;
	volatile uint32_t OTGHSULPI_LPEN:1;
}RCC_AHB1LPENR_S;

typedef union
{
    volatile uint32_t RCC_AHB1LPENR;
    RCC_AHB1LPENR_S RCC_AHB1LPENR_S;
}RCC_AHB1LPENR_U;


typedef struct
{
	volatile uint32_t DCMI_LPEN:1;
	uint32_t 		  AHB2LPENR_RESERVER_BITS1:6;
	volatile uint32_t OTGFS_LPEN:1;
}RCC_AHB2LPENR_S;

typedef union
{
    volatile uint32_t RCC_AHB2LPENR;
    RCC_AHB2LPENR_S RCC_AHB2LPENR_S;
}RCC_AHB2LPENR_U;


typedef struct
{
	volatile uint32_t FMC_LPEN:1;
	volatile uint32_t QSPI_LPEN:1;
}RCC_AHB3LPENR_S;

typedef union
{
    volatile uint32_t RCC_AHB3LPENR;
    RCC_AHB3LPENR_S RCC_AHB3LPENR_S;
}RCC_AHB3LPENR_U;


typedef struct
{
	volatile uint32_t TIM2_LPEN:1;
	volatile uint32_t TIM3_LPEN:1;
	volatile uint32_t TIM4_LPEN:1;
	volatile uint32_t TIM5_LPEN:1;
	volatile uint32_t TIM6_LPEN:1;
	volatile uint32_t TIM7_LPEN:1;
	volatile uint32_t TIM12_LPEN:1;
	volatile uint32_t TIM13_LPEN:1;
	volatile uint32_t TIM14_LPEN:1;
	uint32_t 		  APB1LPENR_RESERVER_BITS1:2;
	volatile uint32_t WWDG_LPEN:1;
	uint32_t 		  APB1LPENR_RESERVER_BITS2:2;
	volatile uint32_t SPI2_LPEN:1;
	volatile uint32_t SPI3_LPEN:1;
	volatile uint32_t SPDIFRX_LPEN:1;
	volatile uint32_t USART2_LPEN:1;
	volatile uint32_t USART3_LPEN:1;
	volatile uint32_t UART4_LPEN:1;
	volatile uint32_t UART5_LPEN:1;
	volatile uint32_t I2C1_LPEN:1;
	volatile uint32_t I2C2_LPEN:1;
	volatile uint32_t I2C3_LPEN:1;
	volatile uint32_t FMPI2C1_LPEN:1;
	volatile uint32_t CAN1_LPEN:1;
	volatile uint32_t CAN2_LPEN:1;
	volatile uint32_t CEC_LPEN:1;
	volatile uint32_t PWR_LPEN:1;
	volatile uint32_t DAC_LPEN:1;
}RCC_APB1LPENR_S;

typedef union
{
    volatile uint32_t RCC_APB1LPENR;
    RCC_APB1LPENR_S RCC_APB1LPENR_S;
}RCC_APB1LPENR_U;


typedef struct
{
	volatile uint32_t TIM1_LPEN:1;
	volatile uint32_t TIM8_LPEN:1;
	uint32_t 		  APB2LPENR_RESERVER_BITS1:2;
	volatile uint32_t USART1_LPEN:1;
	volatile uint32_t USART6_LPEN:1;
	uint32_t 		  APB2LPENR_RESERVER_BITS2:2;
	volatile uint32_t ADC1_LPEN:1;
	volatile uint32_t ADC2_LPEN:1;
	volatile uint32_t ADC3_LPEN:1;
	volatile uint32_t SDIO_LPEN:1;
	volatile uint32_t SPI1_LPEN:1;
	volatile uint32_t SPI4_LPEN:1;
	volatile uint32_t SYSCFG_LPEN:1;
	uint32_t 		  APB2LPENR_RESERVER_BITS3:1;
	volatile uint32_t TIM9_LPEN:1;
	volatile uint32_t TIM10_LPEN:1;
	volatile uint32_t TIM11_LPEN:1;
	uint32_t 		  APB2LPENR_RESERVER_BITS4:3;
	volatile uint32_t SAI1_LPEN:1;
	volatile uint32_t SAI2_LPEN:1;
}RCC_APB2LPENR_S;

typedef union
{
    volatile uint32_t RCC_APB2LPENR;
    RCC_APB2LPENR_S RCC_APB2LPENR_S;
}RCC_APB2LPENR_U;


typedef struct
{
	volatile uint32_t LSE_ON:1;
	volatile uint32_t LSE_RDY:1;
	volatile uint32_t LSE_BYP:1;
	volatile uint32_t LSE_MOD:1;
	uint32_t 		  BDCR_RESERVER_BITS1:4;
	volatile uint32_t RTC_SEL:2;
	uint32_t 		  BDCR_RESERVER_BITS2:5;
	volatile uint32_t RTC_EN:1;
	volatile uint32_t BD_RST:1;
}RCC_BDCR_S;

typedef union
{
    volatile uint32_t RCC_BDCR;
    RCC_BDCR_S RCC_BDCR_S;
}RCC_BDCR_U;


typedef struct
{
	volatile uint32_t LSI_ON:1;
	volatile uint32_t LSI_RDY:1;
	uint32_t 		  CSR_RESERVER_BITS1:22;
	volatile uint32_t RMVF:1;
	volatile uint32_t BOR_RSTF:1;
	volatile uint32_t PIN_RSTF:1;
	volatile uint32_t POR_RSTF:1;
	volatile uint32_t SFT_RSTF:1;
	volatile uint32_t IWDG_RSTF:1;
	volatile uint32_t WWDG_RSTF:1;
	volatile uint32_t LPWR_RSTF:1;
}RCC_CSR_S;

typedef union
{
    volatile uint32_t RCC_CSR;
    RCC_CSR_S RCC_CSR_S;
}RCC_CSR_U;


typedef struct
{
	volatile uint32_t MOD_PER:13;
	volatile uint32_t INC_STEP:15;
	uint32_t 		  SSCGR_RESERVER_BITS1:2;
	volatile uint32_t SPREAD_SEL:1;
	volatile uint32_t SSCG_EN:1;
}RCC_SSCGR_S;

typedef union
{
    volatile uint32_t RCC_SSCGR;
    RCC_SSCGR_S RCC_SSCGR_S;
}RCC_SSCGR_U;


typedef struct
{
	volatile uint32_t PLLI2SM:6;
	volatile uint32_t PLLI2SN:9;
	uint32_t 		  PLLI2SCFGR_RESERVER_BITS1:1;
	volatile uint32_t PLLI2SP:2;
	uint32_t 		  PLLI2SCFGR_RESERVER_BITS2:6;
	volatile uint32_t PLLI2SQ:4;
	volatile uint32_t PLLI2SR:3;
}RCC_PLLI2SCFGR_S;

typedef union
{
    volatile uint32_t RCC_PLLI2SCFGR;
    RCC_PLLI2SCFGR_S RCC_PLLI2SCFGR_S;
}RCC_PLLI2SCFGR_U;


typedef struct
{
	volatile uint32_t PLLSAIM:6;
	volatile uint32_t PLLSAIN:9;
	uint32_t 		  PLLSAICFGR_RESERVER_BITS1:2;
	volatile uint32_t PLLSAIP:2;
	uint32_t 		  PLLSAICFGR_RESERVER_BITS2:6;
	volatile uint32_t PLLSAIQ:4;
}RCC_PLLSAICFGR_S;

typedef union
{
    volatile uint32_t RCC_PLLSAICFGR;
    RCC_PLLSAICFGR_S RCC_PLLSAICFGR_S;
}RCC_PLLSAICFGR_U;


typedef struct
{
	volatile uint32_t PLLIS2DIVQ:5;
	uint32_t 		  DCKCFGR_RESERVER_BITS1:3;
	volatile uint32_t PLLSAIDIVQ:5;
	uint32_t 		  DCKCFGR_RESERVER_BITS2:7;
	volatile uint32_t SAI1SRC:2;
	volatile uint32_t SAI2SRC:2;
	volatile uint32_t TIMPRE:1;
	volatile uint32_t I2S1SRC:2;
	volatile uint32_t I2S2SRC:2;
}RCC_DCKCFGR_S;

typedef union
{
    volatile uint32_t RCC_DCKCFGR;
    RCC_DCKCFGR_S RCC_DCKCFGR_S;
}RCC_DCKCFGR_U;


typedef struct
{
	volatile uint32_t AHB2APB1_CKEN:1;
	volatile uint32_t AHB2APB2_CKEN:1;
	volatile uint32_t CM4DBG_CKEN:1;
	volatile uint32_t SPARE_CKEN:1;
	volatile uint32_t SRAM_CKEN:1;
	volatile uint32_t FLITF_CKEN:1;
	volatile uint32_t RCC_CKEN:1;
}RCC_CKGATENR_S;

typedef union
{
    volatile uint32_t RCC_CKGATENR;
    RCC_CKGATENR_S RCC_CKGATENR_S;
}RCC_CKGATENR_U;


typedef struct
{
	uint32_t 		  DCKCFGR2_RESERVER_BITS1:22;
	volatile uint32_t FMPI2C1SEL:2;
	uint32_t 		  DCKCFGR2_RESERVER_BITS2:2;
	volatile uint32_t CEC_SEL:1;
	volatile uint32_t CK48M_SEL:1;
	volatile uint32_t SDIO_SEL:1;
	volatile uint32_t SPDIFRX_SEL:1;
}RCC_DCKCFGR2_S;

typedef union
{
    volatile uint32_t RCC_DCKCFGR2;
    RCC_DCKCFGR2_S RCC_DCKCFGR2_S;
}RCC_DCKCFGR2_U;



typedef struct
{
	RCC_CR_U RCC_CR_U;
	RCC_PLLCFGR_U RCC_PLLCFGR_U;
	RCC_CFGR_U RCC_CFGR_U;
	RCC_CIR_U RCC_CIR_U;
	RCC_AHB1RSTR_U RCC_AHB1RSTR_U;
	RCC_AHB2RSTR_U RCC_AHB2RSTR_U;
	RCC_AHB3RSTR_U RCC_AHB3RSTR_U;
	uint32_t RCC_Reserved1;
	RCC_APB1RSTR_U RCC_APB1RSTR_U;
	RCC_APB2RSTR_U RCC_APB2RSTR_U;
	uint32_t RCC_Reserved2[2];
	RCC_AHB1ENR_U RCC_AHB1ENR_U;
	RCC_AHB2ENR_U RCC_AHB2ENR_U;
	RCC_AHB3ENR_U RCC_AHB3ENR_U;
	uint32_t RCC_Reserved3;
	RCC_APB1ENR_U RCC_APB1ENR_U;
	RCC_APB2ENR_U RCC_APB2ENR_U;
	uint32_t RCC_Reserved4[2];
	RCC_AHB1LPENR_U RCC_AHB1LPENR_U;
	RCC_AHB2LPENR_U RCC_AHB2LPENR_U;
	RCC_AHB3LPENR_U RCC_AHB3LPENR_U;
	uint32_t RCC_Reserved5;
	RCC_APB1LPENR_U RCC_APB1LPENR_U;
	RCC_APB2LPENR_U RCC_APB2LPENR_U;
	uint32_t RCC_Reserved6[2];
	RCC_BDCR_U RCC_BDCR_U;
	RCC_CSR_U RCC_CSR_U;
	uint32_t RCC_Reserved7[2];
	RCC_SSCGR_U RCC_SSCGR_U;
	RCC_PLLI2SCFGR_U RCC_PLLI2SCFGR_U;
	RCC_PLLSAICFGR_U RCC_PLLSAICFGR_U;
	RCC_DCKCFGR_U RCC_DCKCFGR_U;
	RCC_CKGATENR_U RCC_CKGATENR_U;
	RCC_DCKCFGR2_U RCC_DCKCFGR2_U;
}RCC_RegDef_t;

/************************		DMA RESISTER STRUCTURE		************************/

typedef struct
{
	volatile uint32_t DMA_SxCR;
	volatile uint32_t DMA_SxNDTR;
	volatile uint32_t DMA_SxPAR;
	volatile uint32_t DMA_SxM0AR;
	volatile uint32_t DMA_SxM1AR;
	volatile uint32_t DMA_SxFCR;
}DMA_StreamRegDef_t;

typedef struct
{
    volatile uint32_t DMA_LISR;
    volatile uint32_t DMA_HISR;
    volatile uint32_t DMA_LIFCR;
    volatile uint32_t DMA_HIFCR;
    DMA_StreamRegDef_t StreamReg[8];
}DMA_RegDef_t;



/************************		SysTick RESISTER STRUCTURE		************************/

typedef struct
{
	volatile uint32_t SYST_CSR;
	volatile uint32_t SYST_RVR;
	volatile uint32_t SYST_CVR;
	volatile uint32_t SYST_CALIB;
}SysTick_RegDef_t;


/************************		USART RESISTER STRUCTURE		************************/

typedef struct
{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;
}USART_RegDef_t;

/************************		SPI RESISTER STRUCTURE		************************/

typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;
}SPI_RegDef_t;

/************************		I2C RESISTER STRUCTURE		************************/

typedef struct
{
	volatile uint32_t I2C_CR1;
	volatile uint32_t I2C_CR2;
	volatile uint32_t I2C_OAR1;
	volatile uint32_t I2C_OAR2;
	volatile uint32_t I2C_DR;
	volatile uint32_t I2C_SR1;
	volatile uint32_t I2C_SR2;
	volatile uint32_t I2C_CCR;
	volatile uint32_t I2C_TRISE;
	volatile uint32_t I2C_FLTR;
}I2C_RegDef_t;



/************************		GPIO Peripheral Definitions		************************/
#define GPIOA          ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB          ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC          ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD          ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE          ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF          ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG          ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
#define GPIOH          ((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)

/************************		RCC Peripheral Definitions		************************/
#define RCC            ((RCC_RegDef_t*)RCC_BASE_ADDRESS)

/************************		SysTick Peripheral Definitions		************************/
#define SYSTICK        ((SysTick_RegDef_t*)SYSTICK_BASE_ADDRESS)

/************************		NVIC Peripheral Definitions		************************/
#define NVIC_ISER      ((volatile uint32_t*)0xE000E100)
#define NVIC_ICER      ((volatile uint32_t*)0XE000E180)
#define NVIC_ISPR      ((volatile uint32_t*)0XE000E200)
#define NVIC_ICPR      ((volatile uint32_t*)0XE000E280)
#define NVIC_IABR      ((volatile uint32_t*)0xE000E300)
#define NVIC_IPR       ((volatile uint8_t*)0xE000E400)
#define NVIC_STIR      ((volatile uint32_t*)0xE000EF00)

/************************		SCB Peripheral Definitions		************************/
#define SCB_ACTLR      (*(volatile uint32_t*)0xE000E008)
#define SCB_CPUID      (*(volatile uint32_t*)0xE000ED00)
#define SCB_ICSR       (*(volatile uint32_t*)0xE000ED04)
#define SCB_VTOR       (*(volatile uint32_t*)0xE000ED08)
#define SCB_AIRCR      (*(volatile uint32_t*)0xE000ED0C)
#define SCB_SCR        (*(volatile uint32_t*)0xE000ED10)
#define SCB_CCR        (*(volatile uint32_t*)0xE000ED14)
#define SCB_SHPR       ((volatile uint8_t*)0xE000ED18)
#define SCB_SHCSR      (*(volatile uint32_t*)0xE000ED24)
#define SCB_CFSR       (*(volatile uint32_t*)0xE000ED28)
#define SCB_MMSR       (*(volatile uint32_t*)0xE000ED28)
#define SCB_BFSR       (*(volatile uint32_t*)0xE000ED29)
#define SCB_UFSR       (*(volatile uint32_t*)0xE000ED2A)
#define SCB_HFSR       (*(volatile uint32_t*)0xE000ED2C)
#define SCB_MMAR       (*(volatile uint32_t*)0xE000ED34)
#define SCB_BFAR       (*(volatile uint32_t*)0xE000ED38)
#define SCB_AFSR       (*(volatile uint32_t*)0xE000ED3C)

/************************		SysCFG Peripheral Definitions		************************/
#define SYSCFG_EXTICR      ((volatile uint32_t*)0x40013808)

/************************		EXTI Peripheral Definitions		************************/
#define EXTI_IMR      (*(volatile uint32_t*)0x40013C00)
#define EXTI_EMR      (*(volatile uint32_t*)0x40013C04)
#define EXTI_RTSR     (*(volatile uint32_t*)0x40013C08)
#define EXTI_FTSR     (*(volatile uint32_t*)0x40013C0C)
#define EXTI_SWIER    (*(volatile uint32_t*)0x40013C10)
#define EXTI_PR       (*(volatile uint32_t*)0x40013C14)

/************************		DMA Peripheral Definitions		************************/
#define DMA1          ((DMA_RegDef_t*)DMA1_BASE_ADDRESS)
#define DMA2          ((DMA_RegDef_t*)DMA2_BASE_ADDRESS)

/************************		USART Peripheral Definitions		************************/
#define USART1          ((USART_RegDef_t*)USART1_BASE_ADDRESS)
#define USART2          ((USART_RegDef_t*)USART2_BASE_ADDRESS)
#define USART3          ((USART_RegDef_t*)USART3_BASE_ADDRESS)
#define UART4           ((USART_RegDef_t*)UART4_BASE_ADDRESS)
#define UART5           ((USART_RegDef_t*)UART5_BASE_ADDRESS)
#define USART6          ((USART_RegDef_t*)USART6_BASE_ADDRESS)

/************************		SPI Peripheral Definitions		************************/
#define SPI1          ((SPI_RegDef_t*)SPI1_BASE_ADDRESS)
#define SPI2          ((SPI_RegDef_t*)SPI2_BASE_ADDRESS)
#define SPI3          ((SPI_RegDef_t*)SPI3_BASE_ADDRESS)
#define SPI4          ((SPI_RegDef_t*)SPI4_BASE_ADDRESS)

/************************		I2C Peripheral Definitions		************************/
#define I2C1          ((I2C_RegDef_t*)I2C1_BASE_ADDRESS)
#define I2C2          ((I2C_RegDef_t*)I2C2_BASE_ADDRESS)
#define I2C3          ((I2C_RegDef_t*)I2C3_BASE_ADDRESS)







#endif
