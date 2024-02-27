
#ifndef  GPIO_PRV_H_
#define  GPIO_PRV_H_


#define  MODER_MASK           0b11  
#define  MODER_BIT_ACCESS     2U

#define  PUPDR_MASK           0b11  
#define  PUPDR_BIT_ACCESS     2U

#define  OTYPER_MASK          0b1

#define  OSPEEDR_MASK         0b11  
#define  OSPEEDR_BIT_ACCESS   2U

#define  AFR_MASK             0b1111  
#define  AFR_BIT_ACCESS       4U
#define  AFR_PINS_PER_REG     8U

#define  ODR_MASK             0b1
#define  ODR_BIT_ACCESS       1U

#define  IDR_BIT_ACCESS       1U


#endif
