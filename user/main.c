#include "stm32f10x.h"
#include "SysTick.h"
unsigned char state=0;

void initGPIO()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//GPIO_ResetBits(GPIOA,GPIO_Pin_8);
}
void initSysTick()
{
	SysTick_MODE_Set(clock_AHBdvi8,Tick_enab,SysTick_Enab);
	SysTick_SET_VAL(0xffffff);
}
int main(void)
{
	uint32_t num=0; 
  initGPIO();	
	initSysTick();
	while(1);
}

void SysTick_Handler(void)  
{
		GPIO_WriteBit(GPIOA,GPIO_Pin_8,state);
		state=~state;
}
