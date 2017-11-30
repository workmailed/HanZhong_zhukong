#ifndef __CAN_H
#define __CAN_H	 
#include "sys.h"	    

//CAN1����RX0�ж�ʹ��
#define CAN1_RX0_INT_ENABLE	1		//0,��ʹ��;1,ʹ��.								    
#define CAN2_RX0_INT_ENABLE	1										 							 				    
u8 CAN1_Mode_Init(u8 tsjw,u8 tbs2,u8 tbs1,u16 brp,u8 mode);//CAN��ʼ��
u8 CAN1_Send_Msg(u8* msg,u8 len);						//��������
u8 CAN1_Receive_Msg(u8 *buf);							//��������

u8 CAN2_Mode_Init(u8 tsjw,u8 tbs2,u8 tbs1,u16 brp,u8 mode);//CAN��ʼ��
u8 CAN2_Send_Msg(u8* msg,u8 len);						//��������
CanRxMsg CAN2_Receive_Msg(u8 *buf);							//��������
void CanSend(void);

extern u8 can_Sebuf[4];
extern u8 can_Rebuf[2];
extern u8 OutPut[10]; //can�����Ӧ�ڼ̵������ʮλ�Ĵ���
extern u8 Input[12];	//can�����Ӧ�ڼ̵������ʮλ�Ĵ���

extern u8 yuyin_flag;
extern u16 cdh_16_qian,cdh_16_hou;

//#define P24 OutPut[0]		//�ֱ�+24�л�
//#define N24 OutPut[1]   //�ֱ�GND�л�
//#define CBS OutPut[2]   //�������
//#define CBX OutPut[3]   //����½�
//#define JJC OutPut[4]   //�ӽ����ضϴ����һ��
//#define JJB OutPut[5]   //�ӽ����ضϲ����һ��
//#define FX1 OutPut[6]   //�泵��ʻ������ƶ�1
//#define FX2 OutPut[7]   //�泵��ʻ������ƶ�2
//#define ZPWM OutPut[8]  //ת��PWM
//#define FPWM OutPut[9]  //����PWM

#define HANDMODE Input[0]//�̵���������ֶ�
#define AUTOMODE Input[1]//�̵���������Զ�
#define START 	 Input[2]//ң�ص�����
#define MAIN 		 Input[3]//ң�ص��ܿ���
#define FRONT 	 Input[4]//ң�ص�ǰ��
#define BACK 		 Input[5]//ң�صĺ���
#define LIFT 		 Input[6]//ң�ص���
#define RIGHT 	 Input[7]//ң�ص���
#define UP 			 Input[8]//ң�ص���
#define DOWN 		 Input[9]//ң�ص���

typedef struct
{
	u8 DongZuo;
	u8 SuDu;
	u8 XingZou_OR_ShengJiang;
	u8 ZhiXing_OR_XieXing;
	u8 XiaJiang;
	u8 JiTing;
	u8 KuaiSu_OR_ManSu;
	u8 QiSheng;
	u8 YaoGan_Key;
}KongZhi;
extern KongZhi YaoKong;
#endif

















