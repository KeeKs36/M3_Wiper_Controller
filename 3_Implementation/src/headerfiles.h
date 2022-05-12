#define EXTI0_IRQn 6 //External Interrupt Priority Number

#define RCC_APB2ENR_AFIOEN 0x00000001

#define SYSCFG_EXTICR1_EXTI0_PA 0x0000 //System COnfig For External Interrupt 0 for PORTA

#define NVIC_ISER_BASE_ADDRESS *(volatile unsigned int *)(0xE000E100)// NVIC Interrupt SET
#define NVIC_ICER_BASE_ADDRESS *(volatile unsigned int *)(0xE000E180)// NVIC Interrupt Clear

#define PORTA_BASE_ADDRESS 0x40020000//PORTA Base Address
#define PORTA_IDR_OFFSET 0x10//PORTA IDR OFFSET Address
#define PORTA_IDR *(volatile unsigned int *)(PORTA_BASE_ADDRESS + PORTA_IDR_OFFSET)//PORTA_IDR

#define PORTD_BASE_ADDRESS 0x40020C00//PORTD Base Address
#define PORTD_ODR_OFFSET 0x14//PORTD IDR OFFSET Address
#define PORTD_ODR *(volatile unsigned int *)(PORTD_BASE_ADDRESS + PORTD_ODR_OFFSET)//PORTD_ODR

#define PORTA_MODER_OFFSET 0x00//PORTA_MODER_OFFSET
#define PORTA_MODER *(volatile unsigned int *)(PORTA_BASE_ADDRESS + PORTA_MODER_OFFSET)//PORTA_MODER

#define PORTD_MODER_OFFSET 0x00//PORTD_MODER_OFFSET
#define PORTD_MODER *(volatile unsigned int *)(PORTD_BASE_ADDRESS + PORTD_MODER_OFFSET)//PORTD_MODER

#define RCC_BASE_ADDRESS 0x40023800//RCC Base Address
#define RCC_AHB1ENR_OFFSET 0x30//RCC_AHB1ENR_OFFSET
#define RCC_AHB1ENR *(volatile unsigned int *)(RCC_BASE_ADDRESS + RCC_AHB1ENR_OFFSET)//RCC_AHB1ENR

#define RCC_APB2ENR_OFFSET 0x44//RCC_APB2ENR_OFFSET
#define RCC_APB2ENR *(volatile unsigned int *)(RCC_BASE_ADDRESS + RCC_APB2ENR_OFFSET)//RCC_APB2ENR

#define SYSCFG_BASE_ADDRESS 0x40013800// System Config Base Address
#define SYSCFG_EXTICR1_OFFSET 0x08//SYSCFG_EXTICR1_OFFSET
#define SYSCFG_EXTICR1 *(volatile unsigned int *)(SYSCFG_BASE_ADDRESS + SYSCFG_EXTICR1_OFFSET)//SYSCFG_EXTICR1

#define EXTI_BASE_ADDRESS 0x40013C00//External Interrupt Base Address
#define EXTI_RTSR_OFFSER 0x08//External Interrupt Rising edge offset
#define EXTI_RTSR *(volatile unsigned int *)(EXTI_BASE_ADDRESS + EXTI_RTSR_OFFSER)//EXTI_RTSR

#define EXIT_IMR_OFFSET 0x00//External Interrupt Masking
#define EXIT_IMR *(volatile unsigned int *)(EXTI_BASE_ADDRESS + EXIT_IMR_OFFSET)//EXIT_IMR

#define EXIT_PR_OFFSET 0x14//External Interrupt Pending Register Offset
#define EXIT_PR *(volatile unsigned int *)(EXTI_BASE_ADDRESS + EXIT_PR_OFFSET)//EXIT_PR

#define EXTI_FTSR_OFFSET 0x0C//External Interrupt Falling Edge OFFSETRT address
#define EXTI_FTSR *(volatile unsigned int *)(EXTI_BASE_ADDRESS + EXTI_FTSR_OFFSET)//EXTI_FTSR
