#ifndef __TLC5620_H
#define __TLC5620_H

#include "sys.h"

#define TLC5620RNG 1//��ѹ�ı���

#define DADATA PGout(0)	//TLC5620 DAת������DATAλ
#define DACLK  PGout(1)	//TLC5620 DAת������CLKλ
#define DALOAD PEout(7)	//TLC5620 DAת������LOADλ
#define DALDAC PEout(8)	//TLC5620 DAת������LDACλ

void TLC5620_Init(void);//��ʼ��		 	
void TLC5620_OUT(u8 CHn,double date);//
void TLC5620_OUTnum(u8 CHn,u8 date);
#endif
