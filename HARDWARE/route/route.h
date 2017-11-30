#ifndef __ROUTE_H
#define __ROUTE_H
#include "sys.h"
#include "Modbus_slave.h"
#include "w25qxx.h"
//////////////////flash�ڴ����//////////////////////////////////////////////////////////////////

//�����ʵ���������ø����洢�����
//ϵͳ����
#define SystemParaNum 101  //ϵͳ��Ϣ����������0�����ж�flash�Ƿ񱻳�ʼ��������״̬�Ƿ�����
extern u16 SystemParameter[SystemParaNum];//ϵͳ����

//·��: ��500��·����ÿ��·��100��վ�㣬ÿ��վ��16����Ϣ��ÿ����Ϣ2���ֽ�
#define RouteNum 500  //·������
#define StationNum 100 //ÿ��·������վ����
#define StaiionInfor 20 //ÿ��վ�������Ϣ��

#define RouteStationNumAdress(n) SystemParaNum+n-1  //ÿ��·������վ������Ϣ��ַ
#define NowRouteInforAdress(n)       RouteStationNumAdress(RouteNum)+1+StationNum*StaiionInfor*(n-1)  //��ǰ·����Ϣ��ַ
#define NowStationInforAdress(m,n)    NowRouteInforAdress(m)+StaiionInfor*(n)//��ǰ·������ǰվ����Ϣ��ַ
extern u16 RouteStationNum[RouteNum]; 		//ÿ��·������վ����
extern u16 NowRouteInfor[StationNum][StaiionInfor];   //��ǰ·����Ϣ
//extern u16 StationInfor[StaiionInfor];          //����վ����Ϣ       

//����: ��500�����̣�ÿ������100����ÿ��5����Ϣ��ÿ����Ϣ2���ֽ�
#define ProcessNum 500  //��������
#define StepNum 100 //ÿ�����̰�������
#define StepInfor 3 //ÿ��������Ϣ��

#define ProcessStepNumAdress(n)   NowRouteInforAdress(RouteNum+1)+n  //ÿ�����̰���������Ϣ��ַ
#define NowProcessInforAdress(n)  ProcessStepNumAdress(ProcessNum)+1+StepNum*StepInfor*(n-1)  //��ǰ������Ϣ��ַ
#define NowStepInforAdress(m,n)  NowProcessInforAdress(m)+StepInfor*(n)  //��ǰ���̡���ǰ������Ϣ��ַ
extern u16 ProcessStepNum[ProcessNum]; 		   //ÿ�����̰�������
extern u16 NowProcessInfor[StepNum][StepInfor];  //��ǰ������Ϣ
//extern u16 NowStepInfor[StepInfor];              //����������Ϣ

extern u16 HmiProcessNumFlag; //��һ�����̺ţ��ж����̱仯��
extern u16 HmiRouteNumFlag; //��һ��·���ţ��ж�·���仯��
extern u16 HmiRouteCopiedNumTemp;//������·������ʱ����
extern u16 HmiProcessCopiedNumTemp;//���������̺���ʱ����


//////////////////////////��������ַӳ���/////////////////////////////////////////////////////////////////////

#define HmiScreenSetGet                 PLC_Data[15]   //���û�ȡ�����������
#define ZiDongMoShiJieMian   			3   //�Զ�ģʽ����
#define FuZhiLuJingTanChuJieMian        11   //·�����Ƶ�������  
#define ZhiXingLuJingJieMian            18  //ִ��·������
#define LuJingGuiHuaJieMian             5  //·���滮����
#define LuJingSheZhiJieMian           	16  //·�����ý���
#define QueDingChaRuLuJingJieMian     	6   //ȷ������·������
#define QueDingShanChuLuJingJieMian   	7   //ȷ��ɾ��·������

#define LiuChengGuiHuaJieMian           10   //���̹滮����
#define LiuChengSheZhiJieMian           15   //�������ý���
#define ZhiXingLiuChengJieMian          19   //ִ�����̽���


#define FuZhiLiuChengTanChuJieMian      12   //�������̵�������
#define QueDingChaRuLiuChengJieMian     14   //ȷ���������̽���
#define QueDingShanChuLiuChengJieMian   13   //ȷ��ɾ�����̽���
#define QuXiaoRenWuJieMian              20   //ȡ���������


#define HmiScreenControlMode PLC_OutPut[19]   //����ģʽ�ֶ����Զ�
#define HmiShouZiDongYinCang 		PLC_OutPut[20]   //���Զ�����
#define HmiQiDong 			PLC_OutPut[21]   //����
#define HmiTinZhi 			PLC_OutPut[22]   //ֹͣ

#define HmiScreenRunState    PLC_Data[96]   //����״̬  ������ֹͣ

#define HmiRfidNum           HmiRoadData6 //�ر��

#define HmiRoadData1         PLC_Data[13] //Զ�̺��� Ĭ��Ϊ0 0������1����2����
#define HmiRoadData2         PLC_Data[10] //��·����ֲ� 0������1����ֲ� 2���ҷֲ�	
#define HmiRoadData3         PLC_Data[75] //ͻ�����
#define HmiRoadData4         PLC_Data[76] //��ת����	
#define HmiRoadData5         PLC_Data[21] //��λĬ��ѡ������ 0������ 1������ 2������ 3������   	       
#define HmiRoadData6         PLC_Data[1] //�ر�	
#define HmiRoadData7         PLC_Data[4] //����	0��ֹͣ	1��ǰ��	2:����	3������  4��ͨ��
#define HmiRoadData8         PLC_Data[5] //0���Զ� 1���ֶ�
#define HmiRoadData9         PLC_Data[6] //ʱ��

#define LuJingZongShu        PLC_Data[17] //·������
#define LiuChengZongShu        PLC_Data[74] //·������

#define HmiRouteNum          PLC_Data[27] //·����
#define HmiStationNum        PLC_Data[19] //վ����
#define HmiStationSerialNum  PLC_Data[18] //վ�����
#define HmiRouteEnter        PLC_Data[12] //ȷ��1��ȡ��2
#define HmiStationLast       PLC_Data[71] //��һ��1
#define HmiStationNext       PLC_Data[71] //��һ��2
#define HmiRoutemode         PLC_Data[11] //ģʽ���鿴0������1�����2������3������4��ɾ��5
#define HmiRouteCopiedNum    PLC_Data[52] //������·����
#define HmiRouteCopiedCount  PLC_Data[53] //������վ����
#define HmiNextRfidNum       PLC_Data[30] //��һ���ر�
#define ZhiXingLuJingQueDing PLC_Data[65] //ִ��·��ȷ����ť



//////���̹滮
#define HmiProcessNum          PLC_Data[54] //���̺�
#define HmiStepNum             PLC_Data[55] //���̲���
#define HmiProcessSerialNum    PLC_Data[56] //�������
#define HmiProcessStartNum     PLC_Data[57] //��ʼ·����
#define HmiProcessAction       PLC_Data[58] //���̶���
#define HmiProcessStopNum      PLC_Data[59] //ѭ���ͽ�������

#define HmiProcessEnter        PLC_Data[61] //ȷ��1��ȡ��2

#define HmiProcessLast         PLC_Data[60] //��һ��
#define HmiProcessNext         PLC_Data[60] //��һ��

#define HmiProcessMode         PLC_Data[62] //ģʽ���鿴0������1�����2������3������4��ɾ��5

#define HmiProcessCopiedNum    PLC_Data[63] //���������̺�
#define HmiProcessCopiedCount  PLC_Data[64] //���������̲���

#define HmiProcessMessage      PLC_Data[69] //���̹滮������ʾ��Ϣ

#define HmiTask                PLC_Data[66] //ִ������ ������0 ִ��·��1 ִ������2
#define HmiTaskState           PLC_Data[70] //����״̬������״̬
#define ZhiXingLiuChengQueDing PLC_Data[67] //ִ������ȷ����ť
#define QuXiaoRenWuQueDing     PLC_Data[68] //ȡ������ȷ����ť

#define CheHao     			   PLC_Data[72] //����
//---------------ϵͳ------------//
//��ϵͳ��ȡһ������ num:����λ��
extern u16 GetOneParameterFromSystem(u16 num);

//��ȡ����ϵͳ������������Ĭ������SystemParameter
extern void GetAllParameterFromSystem(void);

//����һ��������ϵͳ value:����ֵ num:�������
extern void SetOneParameterToSystem(u16 value,u16 num);

//�������в�����ϵͳ ��SystemParameter��������ݴ���Flash
extern void SetAllParameterToSystem(void);

//---------------·��------------//
//��ȡ·������վ���� num:·����
extern u16 GetRouteStationNum(u16 num);

//��������·��������վ����
extern void SetAllStationNum(void);

//��ȡ·����Ϣ,num:·����
extern void GetRouteData(u16 num);

//����·����Ϣ,num:·����
extern void SetRouteData(u16 num);

//����վ����Ϣ,num:·���ţ�stationnum
void SetStationData(u16 num,u16 stationnum);

//����·��վ�����ݵ�����
extern void UpdataStationToHmi(void);

//����·��վ�����ݵ���ǰ(��ǰ����)
void UpdataStationToNow(void);

//����·��վ�����ݵ�����
extern void ClearStationToHmi(void);

//---------------����------------//

//���漰�����������ݣ���ǰ������������Ϣ��
extern void	SetProcessData(void);

//��ȡ���̰�������
extern u16	GetProcessStepNum(u16 num);

//�����������̰�������
extern void SetAllStepNum(void);

//��ȡ�������������ݣ���ǰ������������Ϣ��
extern void	GetProcessData(void);

//��ȡ������ָ���������ݣ�ָ����������Ϣ��
extern void	GetProcessDataFrom(u16 num);
	
//�����������ݵ�����
extern void UpdataProcessToHmi(void);

//�����������ݵ�����
extern void ClearStepToHmi(void);

//���뼰�����������ݣ���ǰ������������Ϣ��
extern void	InsertProcessData(void);

//ɾ���������������ݣ���ǰ������������Ϣ��
extern void	DeleteProcessData(void);

//�Զ�������ʾ��Ϣ����
extern void HmiAutoReload(void);






#endif
