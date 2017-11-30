#ifndef __CDHDATA_H
#define __CDHDATA_H	 
#include "sys.h"

typedef struct 		
{
	u8 zeroNum;			//�ŵ����յ�ĸ���
	u8 zeroLoctaion[16];//�ŵ����յ��λ��
	u8 zeroContinue;	//�ϵ��Ƿ�����
	
	u8 Num;				//��Ч�㣨�ŵ��������㣩�ĸ���
	int Distance;		//��Ч�������ĵľ���
	u8 Error;			//�쳣�㣨���졢�ֲ��һЩ���ڿ��ǵ�����Χ�ڵ������ʱ����ֵ
}Fencha_struct;				


extern u8 n,a;
extern Fencha_struct front_cdh16,back_cdh16,backl_cdh8,backr_cdh8; //�ⲿ����һ��Fencha_struct���͵�ȫ�ֱ���
extern Fencha_struct findtemp;//�����������еĽṹ�������ⲿ����


Fencha_struct FindSpace(u16 dst,u8 num,u8 dir);//16λ�����⵽�ŵ��������ݺ���
Fencha_struct FindSpace1(u8 dst,u8 num,u8 dir);//8λ�����⵽�ŵ��������ݺ���
 				    
#endif
