#include <stdio.h>
#include "headerfiles.h"
#include "prototypes.h"

volatile unsigned int switch_stat;
volatile long flag_stat=0,freq_status=0;
volatile unsigned int timing_monitor = 0;
volatile unsigned int bit_1 = 0;

void EXTI0_IRQHandler(void)
{
	timing_monitor = 0;//Clearing the timing_monitor variable. By using 'timing_monitor' variable we are going to count the time using Instruction Cycles Concept
	switch_stat = PORTA_IDR & (1<<0);//Checking the status of the PORTA 0th pin(i.e., switch)
	while(switch_stat == 1)//The Condition will be true until the switch is press
	{
		timing_monitor++;//Here we are incrementing the 'timing_monitor' variable to monitor the number of instruction cycles generated
		switch_stat = PORTA_IDR & (1<<0);//Checking the status of the PORTA 0th pin(i.e., switch)
	}
	switch_stat = PORTA_IDR & (1<<0);//Checking the status of the PORTA 0th pin(i.e., switch)
	Intr_Clean_Function();//External Interrupt Clear Function
}

static void Init_Function(void)
{
	RCC_AHB1ENR |= (1<<3)|(1<<0);//Enable System Clock For GPIOA and GPIOD
	PORTA_MODER &= 0x00000000;//Initially Clear all the bits in the MODE register for PORTA
	PORTD_MODER &= 0x00000000;//Initially Clear all the bits in the MODE register for PORTD
	PORTA_MODER |= (0<<1)|(0<<0);//SET Input Direction for PORTA 0th pin
	PORTD_MODER |= (1<<24)|(1<<26)|(1<<28)|(1<<30);//SET Output Direction for PORTD 12th, 13th, 14th and 15th pins
	PORTD_ODR = 0x0000;//Initially clear all the Output pins of PORTD
}

static void Intr_Function_Init(void)//External Interrupt Initialization Function
{
	RCC_APB2ENR |= RCC_APB2ENR_AFIOEN;//Enable the System Clock
	SYSCFG_EXTICR1 |= SYSCFG_EXTICR1_EXTI0_PA;//Enable External Interrupt_0 for PORT_A of PIN_0 (PA0)
	EXTI_RTSR |= (1<<0);//SET External Interrupt 0 in Rising Edge
	EXIT_IMR |= (1<<0);//SET External Interrupt Masking
	NVIC_ISER_BASE_ADDRESS |= (1<<EXTI0_IRQn);// SET Interrupt priority for NVIC
}

static void Intr_Clean_Function(void)//External Interrupt Clear Function
{
	EXIT_PR |= (1<<0);//SET To Clear the Pending Registers
}

static void Freq_Function(volatile short int n)//Frequency Function
{
	volatile unsigned int i;

	PORTD_ODR = 0x5000;//RED=1, GREEN=1, ORANGE=0, BLUE=0
	for(i=0;i<(n * n * 1000);i++);
	PORTD_ODR = 0x6000;//RED=1, GREEN=0, ORANGE=1, BLUE=0
	for(i=0;i<(n * n * 1000);i++);
	PORTD_ODR = 0xC000;//RED=1, GREEN=0, ORANGE=0, BLUE=1
	for(i=0;i<(n * n * 1000);i++);
	PORTD_ODR = 0x6000;//RED=1, GREEN=0, ORANGE=1, BLUE=0
	for(i=0;i<(n * n * 1000);i++);
}

static void Wiper_Enable_Disadble_Function(void)//Wiper Enable (or) Disable Function
{
	if ((timing_monitor > 50000) && (switch_stat == 0))//IF 'timing_monitor' reaches more than 50000 and if 'switch_stat' is 0
	{
		timing_monitor = 0;//Reset 'timing_monitor'

		if(bit_1 == 0)//Initially 'bit_1' variable will be 0. This condition will be used, to perform Wiper Enable (or) Disable task (any one) at a time
		{
			PORTD_ODR = 0x4000;//SET RED LED
			flag_stat = 1;//'flag_stat' variable ENABLE the Wiper
			bit_1 = 1;//SET 'bit_1' to 1
			freq_status = 0;// Initiate 'freq_status' to 0 (i.e., frequency speed)
		}
		else if(bit_1 == 1)
		{
			PORTD_ODR = 0x0000;//Clear PORTD
			flag_stat = 0;//Disable the Wiper
			bit_1 = 0;//Clear 'bit_1'
		}
	}
	else;
}

static void Wiper_Switching_Function(void)//Wiper Frequency Switching Function
{
	if ((timing_monitor>0) && (timing_monitor<50000) && (flag_stat == 1) && (switch_stat == 0))//IF timing_monitor greater than 0 and timing_monitor less than 50000 and if wiper is in Enable mode and Switch is OFF
	{
		timing_monitor = 0;//Reset 'timing_monitor'
		freq_status++;//SET the Wiper Frequency
		if (freq_status > 3)//IF switch pressed more than 3 times then it should be reset with 1
		{
			freq_status = 1;//Reset frequency
		}
		else;
	}
	else;
}

static void Wiper_Rotation(void)//Wiper Rotating Function
{
	if (flag_stat == 1)//IF Wiper got Enable
	{
		if (freq_status == 1)//IF Frequency_1 Selected
			Freq_Function(freq_status);//Passing Frequency_1 value as an argument to the Frequency Function
		else if (freq_status == 2)//IF Frequency_2 Selected
			Freq_Function(freq_status);//Passing Frequency_2 value as an argument to the Frequency Function
		else if (freq_status == 3)//IF Frequency_3 Selected
			Freq_Function(freq_status);//Passing Frequency_3 value as an argument to the Frequency Function
		else;
	}
	else;
}

int main()//Main Function
{
	/********************************************************************************
	 * NOTE: PRESS THE SWITCH MORE THAN 3 TO 4 SECONDS TO ENABLE (OR) DIABLE THE WIPER
	 * After Enabling the Wiper give minimum 10ms of duration to change the Frequency Speed
	 ********************************************************************************/

	Init_Function();//GPIO and Clock Initialization Function
	Intr_Function_Init();//External Interrupt Initialization Function
	while(1)
	{
		Wiper_Enable_Disadble_Function();//Wiper Enable (or) Disable Function
		Wiper_Switching_Function();//Wiper Frequency Switching Function
		Wiper_Rotation();//Wiper Rotating Function
	}
	return 0;
}
