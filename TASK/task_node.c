#include "task_node.h"
#include "task_uart.h"
#include "gps.h"
#include "delay.h"


extern vu16 USART2_RX_STA;
extern u8 USART2_RX_BUF[USART2_MAX_RECV_LEN]; 					//串口2,发送缓存区,用于接收到的GPS数据
extern u8 USART1_TX_BUF[USART2_MAX_RECV_LEN]; 					//串口1,发送缓存区,用于备份usart2接收到的GPS数据
void GPS_Init(void)
{
	u16 i,rxlen;
	u8 key=0XFF;
	myusart2_init(38400);
		if(SkyTra_Cfg_Rate(5)!=0)	//设置定位信息更新速度为5Hz,顺便判断GPS模块是否在位. 
	{
		do
		{
			myusart2_init(9600);			//初始化串口3波特率为9600
	  	SkyTra_Cfg_Prt(3);			//重新设置模块的波特率为38400
			myusart2_init(38400);			//初始化串口3波特率为38400
      key=SkyTra_Cfg_Tp(100000);	//脉冲宽度为100ms
		}while(SkyTra_Cfg_Rate(5)!=0&&key!=0);//配置SkyTraF8-BD的更新速率为5Hz
	 
		delay_ms(500);
		
		if(USART2_RX_STA&0X8000)		//接收到一次数据了
		{
			rxlen=USART2_RX_STA&0X7FFF;	//得到数据长度
			for(i=0;i<rxlen;i++)USART1_TX_BUF[i]=USART2_RX_BUF[i];	   
 			USART2_RX_STA=0;		   	//启动下一次接收
			USART1_TX_BUF[i]=0;			//自动添加结束符
			GPS_Analysis(&gpsx,(u8*)USART1_TX_BUF);//分析字符串
			Gps_Msg_Show();				//显示信息	
			if(upload)printf("\r\n%s\r\n",USART1_TX_BUF);//发送接收到的数据到串口1
 		}
	
	}
}