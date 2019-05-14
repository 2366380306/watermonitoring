#include "iwdg.h"




void IWDG_Init(u8 prer,u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //取消IWDG_PR和IWDG_RLR寄存器的写保护
	IWDG_SetPrescaler(prer);                          //设置预分频系数
	IWDG_SetReload(rlr);                             //设置IWDG重装载值 T=((4*2^prer)*rlr)/40(单位ms)
	IWDG_Enable();
}

void IWDG_Feed(void)  //喂狗
{
	IWDG_ReloadCounter();
}

