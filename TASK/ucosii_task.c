#include "ucosii_task.h"

//��ʼ����
//�����������ȼ�
#define START_TASK_PRIO 10 //��ʼ��������ȼ�����Ϊ��ͣ���ֵ���
//���������ջ��С
#define START_STK_SIZE 64
//���������ջ�ռ�
OS_STK START_TASK_STK[START_STK_SIZE];//����������OS_STK
//�������ӿ�
void start_task(void *pdata);


//����1



//����2


//��ʼ����
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr=0;
	pdata =pdata;           //Ϊ�˷�ֹ��������ԭ����
	OS_ENTER_CRITICAL();    //�����ٽ������޷����жϴ�ϣ�
	//OSTaskCreate(task1,(void *)0,(OS_STK*)&TASK1_STK[TASK1_STK_SIZE-1],TASK1_STK_PRIO);
	//OSTaskCreate(task2,(void *)0,(OS_STK*)&TASK1_STK[TASK1_STK_SIZE-1],TASK1_STK_PRIO);
	//OSTaskCreate(task3,(void *)0,(OS_STK*)&TASK1_STK[TASK1_STK_SIZE-1],TASK1_STK_PRIO);
	OSTaskSuspend(START_TASK_PRIO); //������ʼ����
	OS_EXIT_CRITICAL();             //�˳��ٽ��������Ա��жϴ�ϣ�
	
}

 void task_start(void)
 {
	 OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO);//������ʼ����
 }


//����1