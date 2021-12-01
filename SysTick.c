#include "stm32f10x.h"
#include "SysTick.h"

void SysTick_MODE_Set(uint32_t clkSource,uint32_t tickInt,uint32_t Ena ){

	SysTick->CTRL &=~(SysTick_CTRL_CLKSOURCE_Msk |SysTick_CTRL_TICKINT_Msk
	                  |SysTick_CTRL_ENABLE_Msk);
	if(clkSource){
		SysTick->CTRL |=SysTick_CTRL_CLKSOURCE_Msk;
	}
	else{
		SysTick->CTRL &=~SysTick_CTRL_CLKSOURCE_Msk;
	}
	if(tickInt){
	SysTick->CTRL |=SysTick_CTRL_TICKINT_Msk;
	}
	else{
	SysTick->CTRL &=~SysTick_CTRL_TICKINT_Msk;
	}
	if(Ena){
	SysTick->CTRL |=SysTick_CTRL_ENABLE_Msk;
	}
	else{
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
	}
}

void SysTick_SET_VAL(uint32_t dat)//timer  long
{
	SysTick->LOAD=dat;
}