#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "modbus.h"
#include "timer.h"
#include "adc.h"

int main(void)
{		
	u16 t;  
	u16 len;	
	u16 times=0;
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	LED_Init();			     //LED�˿ڳ�ʼ��
	//KEY_Init();          //��ʼ���밴�����ӵ�Ӳ���ӿ�
	TIM3_Int_Init(7200-1,0);
	Adc_Init();
	
	while(1)
	{
		Modbus_Service();
		//delay_ms(100);
		LED0=Modbus_IO[0];
		//delay_ms(1000);
		Modbus_IO[1]=1;
		Modbus_IO[2]=2;
		Modbus_IO[3]=3;
	}	 
}

