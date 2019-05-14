#include "ucosii_task.h"

//开始任务
//设置任务优先级
#define START_TASK_PRIO 10 //开始任务的优先级设置为最低（数值最大）
//设置任务堆栈大小
#define START_STK_SIZE 64
//创建任务堆栈空间
OS_STK START_TASK_STK[START_STK_SIZE];//数据类型是OS_STK
//任务函数接口
void start_task(void *pdata);


//任务1



//任务2


//开始任务
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr=0;
	pdata =pdata;           //为了防止报错，具体原因不明
	OS_ENTER_CRITICAL();    //进入临界区（无法被中断打断）
	//OSTaskCreate(task1,(void *)0,(OS_STK*)&TASK1_STK[TASK1_STK_SIZE-1],TASK1_STK_PRIO);
	//OSTaskCreate(task2,(void *)0,(OS_STK*)&TASK1_STK[TASK1_STK_SIZE-1],TASK1_STK_PRIO);
	//OSTaskCreate(task3,(void *)0,(OS_STK*)&TASK1_STK[TASK1_STK_SIZE-1],TASK1_STK_PRIO);
	OSTaskSuspend(START_TASK_PRIO); //挂起起始任务
	OS_EXIT_CRITICAL();             //退出临界区（可以被中断打断）
	
}

 void task_start(void)
 {
	 OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO);//创建开始任务
 }


//任务1