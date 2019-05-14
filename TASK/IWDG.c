#include "iwdg.h"




void IWDG_Init(u8 prer,u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //ȡ��IWDG_PR��IWDG_RLR�Ĵ�����д����
	IWDG_SetPrescaler(prer);                          //����Ԥ��Ƶϵ��
	IWDG_SetReload(rlr);                             //����IWDG��װ��ֵ T=((4*2^prer)*rlr)/40(��λms)
	IWDG_Enable();
}

void IWDG_Feed(void)  //ι��
{
	IWDG_ReloadCounter();
}

