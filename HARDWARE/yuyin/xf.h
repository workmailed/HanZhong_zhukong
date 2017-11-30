#ifndef __XF_H
#define __XF_H
#include "sys.h"
#include "usart.h"	

extern u8 XFS_StopCom[];//ֹͣ�ϳ�
extern u8 XFS_SuspendCom[];//��ͣ�ϳ�
extern u8 XFS_RecoverCom[];//�ָ��ϳ�
extern u8 XFS_ChackCom[];//״̬��ѯ
extern u8 XFS_PowerDownCom[];//����POWER DOWN ״̬����

extern u8 XIAO_YAN[];//����С��
extern u8 XU_JIU[];//�������
extern u8 YU_DUO[];//�������
extern u8 XIAO_PING[];//����СƼ
extern u8 LAO_YA[];//��������Ѽ
extern u8 XIAO_BAO[];//������С��
//����ѡ��
extern u8 YIN_LIANG0[];//����
extern u8 YIN_LIANG1[];//1
extern u8 YIN_LIANG2[];//2
extern u8 YIN_LIANG3[];//3
extern u8 YIN_LIANG4[];//4
extern u8 YIN_LIANG5[];//5
extern u8 YIN_LIANG6[];//6
extern u8 YIN_LIANG7[];//7
extern u8 YIN_LIANG8[];//8
extern u8 YIN_LIANG9[];//9

//����ѡ��
extern u8 YIN_SU0[];//����
extern u8 YIN_SU1[];//1
extern u8 YIN_SU2[];//2
extern u8 YIN_SU3[];//3
extern u8 YIN_SU4[];//4
extern u8 YIN_SU5[];//5
extern u8 YIN_SU6[];//6
extern u8 YIN_SU7[];//7
extern u8 YIN_SU8[];//8
extern u8 YIN_SU9[];//9

//���ѡ��
extern u8 YIN_DIAO0[];//���
extern u8 YIN_DIAO1[];//1
extern u8 YIN_DIAO2[];//2
extern u8 YIN_DIAO3[];//3
extern u8 YIN_DIAO4[];//4
extern u8 YIN_DIAO5[];//5
extern u8 YIN_DIAO6[];//6
extern u8 YIN_DIAO7[];//7
extern u8 YIN_DIAO8[];//8
extern u8 YIN_DIAO9[];//9


void speek(u8 *HZdata);
void YS_XFS_Set(u8 *Info_data);

void rensheng(u8 num);//����ѡ��
void yinling(u8 num);//����ѡ��
void yusu(u8 num);//����ѡ��
void yudiao(u8 num);//���ѡ��
void set_yinling(u8 num);
#endif

