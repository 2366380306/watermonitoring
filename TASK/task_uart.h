#ifndef _TASK_UART_H
#define _TASK_UART_H
#include "includes.h" 


#define USART2_MAX_RECV_LEN		600					//�����ջ����ֽ���
#define USART2_MAX_SEND_LEN		600					//����ͻ����ֽ���
#define USART2_RX_EN 			1					//0,������;1,����.


void myusart1_init(u32 bound);
void myusart2_init(u32 bound);
void myusart3_init(u32 bound);




#endif
