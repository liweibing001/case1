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
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
	LED_Init();			     //LED端口初始化
	//KEY_Init();          //初始化与按键连接的硬件接口
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

