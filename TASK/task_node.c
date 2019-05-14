#include "task_node.h"
#include "task_uart.h"
#include "gps.h"
#include "delay.h"


extern vu16 USART2_RX_STA;
extern u8 USART2_RX_BUF[USART2_MAX_RECV_LEN]; 					//����2,���ͻ�����,���ڽ��յ���GPS����
extern u8 USART1_TX_BUF[USART2_MAX_RECV_LEN]; 					//����1,���ͻ�����,���ڱ���usart2���յ���GPS����
void GPS_Init(void)
{
	u16 i,rxlen;
	u8 key=0XFF;
	myusart2_init(38400);
		if(SkyTra_Cfg_Rate(5)!=0)	//���ö�λ��Ϣ�����ٶ�Ϊ5Hz,˳���ж�GPSģ���Ƿ���λ. 
	{
		do
		{
			myusart2_init(9600);			//��ʼ������3������Ϊ9600
	  	SkyTra_Cfg_Prt(3);			//��������ģ��Ĳ�����Ϊ38400
			myusart2_init(38400);			//��ʼ������3������Ϊ38400
      key=SkyTra_Cfg_Tp(100000);	//������Ϊ100ms
		}while(SkyTra_Cfg_Rate(5)!=0&&key!=0);//����SkyTraF8-BD�ĸ�������Ϊ5Hz
	 
		delay_ms(500);
		
		if(USART2_RX_STA&0X8000)		//���յ�һ��������
		{
			rxlen=USART2_RX_STA&0X7FFF;	//�õ����ݳ���
			for(i=0;i<rxlen;i++)USART1_TX_BUF[i]=USART2_RX_BUF[i];	   
 			USART2_RX_STA=0;		   	//������һ�ν���
			USART1_TX_BUF[i]=0;			//�Զ���ӽ�����
			GPS_Analysis(&gpsx,(u8*)USART1_TX_BUF);//�����ַ���
			Gps_Msg_Show();				//��ʾ��Ϣ	
			if(upload)printf("\r\n%s\r\n",USART1_TX_BUF);//���ͽ��յ������ݵ�����1
 		}
	
	}
}