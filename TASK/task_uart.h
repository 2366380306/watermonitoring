#ifndef _TASK_UART_H
#define _TASK_UART_H
#include "includes.h" 


#define USART2_MAX_RECV_LEN		600					//最大接收缓存字节数
#define USART2_MAX_SEND_LEN		600					//最大发送缓存字节数
#define USART2_RX_EN 			1					//0,不接收;1,接收.


void myusart1_init(u32 bound);
void myusart2_init(u32 bound);
void myusart3_init(u32 bound);




#endif
