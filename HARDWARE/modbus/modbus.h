#ifndef __modbus_H
#define __modbus_H
#include "stdio.h"
#include "stm32f10x.h" 

//modbus用的串口号
#define MODUBS_UART USART1

//
extern u16	Modbus_IO[];
extern u16	Modbus_RX_CNT;//接收计数器
extern u8	Modbus_RX_BUFF[200];//接收缓冲区2048字节
extern u8	Modbus_TX_BUFF[200];//接收缓冲区2048字节
extern u8	Modbus_FrameFlag;//帧结束标记
extern u16	Modbus_RX_EN;//接收倒计时

void Modbus_Service(void);
void Modbus_01_Solve(void);
void Modbus_03_Solve(void);
void Modbus_06_Solve(void);
void Modbus_16_Solve(void);
void Modbus_SendData(u8 *buff,u8 len);

//用于串口接收中断，进行组包
void Modbus_zubao(u8 Res);

//用于定时器，判断是否接收完成
void Modbus_Is_jieshou(void);
#endif
