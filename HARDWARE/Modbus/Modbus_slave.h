#ifndef __Modbus_slave_H
#define	__Modbus_slave_H	 
#include "sys.h"
//extern  u16   Word[64];       //������Ѱַ����32��short�� ,�з�����
//extern 	u8    Bit[32];        // ����λѰַ����10-31�ڲ�λ��0-9�����
//extern 	u8  inputBit[32];
//extern 	u16 *pw;
//extern 	u8 *pb;
//extern 	u16 sendlength;

void AnalyzeRecieve(void);                              
void send_comm(void);
void Recirve_01(void);
void Recirve_02(void);
void Recirve_03(void);
void Recirve_04(void);
void Recirve_05(void);
void Recirve_06(void);
void Recirve_10(void);
void errorsend(u8 func,u8 type);
u16 CalcCrc(unsigned char *chData,unsigned short uNo);
//extern u8  Reciver_bit;//����λ��һ
extern u8 PLC_InPut[64];//PLC����״̬�Ĵ���
extern u8 PLC_OutPut[128];//PLC���״̬�Ĵ���
extern u16 PLC_Data[128];//PLC���ݼĴ���
#endif
