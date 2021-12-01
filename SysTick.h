#ifndef _SysTick_H
#define _SysTick_H

#include "stm32f10x.h"

enum{clock_AHBdvi8,clock_AHB};//clksource

enum{SysTick_Disab,SysTick_Enab};//enable

enum{Tick_disab,Tick_enab};//ticklnt


void SysTick_MODE_Set(uint32_t clkSource,uint32_t tickInt,uint32_t Ena );
void SysTick_SET_VAL(uint32_t dat);

#endif