#ifndef __modbus_H
#define __modbus_H
#include "stdio.h"
#include "stm32f10x.h" 

//modbus�õĴ��ں�
#define MODUBS_UART USART1

//
extern u16	Modbus_IO[];
extern u16	Modbus_RX_CNT;//���ռ�����
extern u8	Modbus_RX_BUFF[200];//���ջ�����2048�ֽ�
extern u8	Modbus_TX_BUFF[200];//���ջ�����2048�ֽ�
extern u8	Modbus_FrameFlag;//֡�������
extern u16	Modbus_RX_EN;//���յ���ʱ

void Modbus_Service(void);
void Modbus_01_Solve(void);
void Modbus_03_Solve(void);
void Modbus_06_Solve(void);
void Modbus_16_Solve(void);
void Modbus_SendData(u8 *buff,u8 len);

//���ڴ��ڽ����жϣ��������
void Modbus_zubao(u8 Res);

//���ڶ�ʱ�����ж��Ƿ�������
void Modbus_Is_jieshou(void);
#endif
