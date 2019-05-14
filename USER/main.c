#include "stm32f10x.h"
#include "delay.h"
#include "stdio.h"
#include "ucosii_task.h"

int main(void)
{
  delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	OSInit();     //��ʼ��UCOSII
	task_start();
	OSStart();    //������ʼ����
	
}





