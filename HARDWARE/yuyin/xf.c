#include "sys.h"

/**************оƬ��������*********************/
u8 XFS_StopCom[]={0xFD,0X00,0X01,0X02};		//ֹͣ�ϳ�
u8 XFS_SuspendCom[]={0XFD,0X00,0X01,0X03};//��ͣ�ϳ�
u8 XFS_RecoverCom[]={0XFD,0X00,0X01,0X04};//�ָ��ϳ�
u8 XFS_ChackCom[]={0XFD,0X00,0X01,0X21};	//״̬��ѯ
u8 XFS_PowerDownCom[]={0XFD,0X00,0X01,0X88};//����POWER DOWN ״̬����
//����ѡ��
u8 XIAO_YAN[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x6D,0x33,0x5D};//����С��
u8 XU_JIU[]={0xFD,0x00,0x07,0x01,0x01,0x5B,0x6D,0x35,0x31,0x5D};//�������
u8 YU_DUO[]={0xFD,0x00,0x07,0x01,0x01,0x5B,0x6D,0x35,0x32,0x5D};//�������
u8 XIAO_PING[]={0xFD,0x00,0x07,0x01,0x01,0x5B,0x6D,0x35,0x33,0x5D};//����СƼ
u8 LAO_YA[]={0xFD,0x00,0x07,0x01,0x01,0x5B,0x6D,0x35,0x34,0x5D};//��������Ѽ
u8 XIAO_BAO[]={0xFD,0x00,0x07,0x01,0x01,0x5B,0x6D,0x35,0x35,0x5D};//������С��
//����ѡ��
u8 YIN_LIANG0[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x30,0x5D};//����
u8 YIN_LIANG1[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x31,0x5D};//1
u8 YIN_LIANG2[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x32,0x5D};//2
u8 YIN_LIANG3[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x33,0x5D};//3
u8 YIN_LIANG4[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x34,0x5D};//4
u8 YIN_LIANG5[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x35,0x5D};//5
u8 YIN_LIANG6[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x36,0x5D};//6
u8 YIN_LIANG7[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x37,0x5D};//7
u8 YIN_LIANG8[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x38,0x5D};//8
u8 YIN_LIANG9[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x76,0x39,0x5D};//9

//����ѡ��
u8 YIN_SU0[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x30,0x5D};//����
u8 YIN_SU1[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x31,0x5D};//1
u8 YIN_SU2[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x32,0x5D};//2
u8 YIN_SU3[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x33,0x5D};//3
u8 YIN_SU4[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x34,0x5D};//4
u8 YIN_SU5[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x35,0x5D};//5
u8 YIN_SU6[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x36,0x5D};//6
u8 YIN_SU7[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x37,0x5D};//7
u8 YIN_SU8[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x38,0x5D};//8
u8 YIN_SU9[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x73,0x39,0x5D};//9

//���ѡ��
u8 YIN_DIAO0[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x30,0x5D};//���
u8 YIN_DIAO1[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x31,0x5D};//1
u8 YIN_DIAO2[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x32,0x5D};//2
u8 YIN_DIAO3[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x33,0x5D};//3
u8 YIN_DIAO4[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x34,0x5D};//4
u8 YIN_DIAO5[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x35,0x5D};//5
u8 YIN_DIAO6[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x36,0x5D};//6
u8 YIN_DIAO7[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x37,0x5D};//7
u8 YIN_DIAO8[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x38,0x5D};//8
u8 YIN_DIAO9[]={0xFD,0x00,0x06,0x01,0x01,0x5B,0x74,0x39,0x5D};//9

/***********************************************/


/************************************************************************
���������� ���ڷ����ַ�������
��ڲ����� 	*DAT���ַ���ָ��
�� �� ֵ�� none
����˵���� API ���ⲿʹ�ã�ֱ�ۣ�
**************************************************************************/
void PrintCom(u8 *DAT,u16 len)
{
	u16 i;
	if(PLC_OutPut[11])//���������Ŀ���
	{
		/* TC TXE ��־λ�ڸ�λ��ʱ����1 */  
		/*��һ���ȡSR�Ĵ������ڶ���дDR�Ĵ���*/  
		/* ����������������״η��͵ĵ�һ���ַ��ᶪʧ */ 
//		USART_GetFlagStatus(USART1, USART_FLAG_TC);
		for(i=0;i<len;i++)
		{
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
			USART_SendData(USART1, *DAT++);
			
		}	
	}
	else 
	{
		;
	}
}


/***********************************************************
* ��    �ƣ�  YS-XFS5051 �ı��ϳɺ���
* ��    �ܣ�  ���ͺϳ��ı���XFS5051оƬ���кϳɲ���
* ��ڲ�����  *HZdata:�ı�ָ����� 
* ���ڲ�����
* ˵    ���� ������ֻ�����ı��ϳɣ��߱���������ѡ��Ĭ�ϲ�����9600bps��					 
* ���÷��������� SYN_FrameInfo���������Ƶ��ӡ�����
**********************************************************/
void speek(u8 *HZdata)
{
/****************��Ҫ���͵��ı�**********************************/ 
		u8 Frame_Info[100]; //������ı�����
		u16 HZ_Length;  

		HZ_Length =strlen((const char *)HZdata); 			//��Ҫ�����ı��ĳ���
 		 
/*****************֡�̶�������Ϣ**************************************/           
		 Frame_Info[0] = 0xFD ; 			//����֡ͷFD
		 Frame_Info[1] = 0x00 ; 			//�������������ȵĸ��ֽ�
		 Frame_Info[2] = HZ_Length+2; //�������������ȵĵ��ֽ�
		 Frame_Info[3] = 0x01 ; 			//���������֣��ϳɲ�������		 		 
		 Frame_Info[4] = 0x01;        //�ı������ʽ��GBK 
	
/*******************����֡��Ϣ***************************************/		  
     memcpy(&Frame_Info[5], HZdata, HZ_Length);
		 PrintCom(Frame_Info,5+HZ_Length); //����֡����
}


/***********************************************************
* ��    �ƣ� void  main(void)
* ��    �ܣ� ������	�������
* ��ڲ����� *Info_data:�̶���������Ϣ���� 
* ���ڲ�����
* ˵    �����������������ã�ֹͣ�ϳɡ���ͣ�ϳɵ����� ��Ĭ�ϲ�����9600bps��					 
* ���÷�����ͨ�������Ѿ�������������������á� 
**********************************************************/
void YS_XFS_Set(u8 *Info_data)
{
	u8 Com_Len;
	Com_Len =strlen((const char *)Info_data);
	PrintCom(Info_data,Com_Len);
}
//����ѡ��
void rensheng(u8 num)
{
	switch(num)
	{
		case 0:PrintCom(XIAO_YAN,9); 	osdelay_ms(10);	speek("��ã�����С�࣬�ܸ���Ϊ������");break;
		case 1:PrintCom(XU_JIU,10);		osdelay_ms(10);	speek("��ã�������ã��ܸ���Ϊ������");break;
		case 2:PrintCom(YU_DUO,10);		osdelay_ms(10);	speek("��ã�������࣬�ܸ���Ϊ������");break;
		case 3:PrintCom(XIAO_PING,10);	osdelay_ms(10);	speek("��ã�����СƼ���ܸ���Ϊ������");break;
		case 4:PrintCom(LAO_YA,10);		osdelay_ms(10);	speek("��ã���������Ѽ���ܸ���Ϊ������");break;
		case 5:PrintCom(XIAO_BAO,10);	osdelay_ms(10);	speek("��ã�������С�����ܸ���Ϊ������");break;
	}                                                                         
} 
//����ѡ��
void yinling(u8 num)
{
	switch(num)
	{
		case 0:PrintCom(YIN_LIANG2,9);osdelay_ms(10);speek("��������");break;
		case 1:PrintCom(YIN_LIANG5,9);osdelay_ms(10);speek("��������");break;
		case 2:PrintCom(YIN_LIANG9,9);osdelay_ms(10);speek("��������");break;
	}                                                                        
}  
//����Ĭ������
void set_yinling(u8 num)
{
	switch(num)
	{
		case 0:PrintCom(YIN_LIANG2,9);osdelay_ms(10);break;
		case 1:PrintCom(YIN_LIANG5,9);osdelay_ms(10);break;
		case 2:PrintCom(YIN_LIANG9,9);osdelay_ms(10);break;
	}                                                                        
}
//����ѡ��
void yusu(u8 num)
{
	switch(num)
	{
		case 0:PrintCom(YIN_SU0,9);osdelay_ms(10);speek("��������Ϊ0�ĸ���");break;
		case 1:PrintCom(YIN_SU1,9);osdelay_ms(10);speek("��������Ϊ1�ĸ���");break;
		case 2:PrintCom(YIN_SU2,9);osdelay_ms(10);speek("��������Ϊ2�ĸ���");break;
		case 3:PrintCom(YIN_SU3,9);osdelay_ms(10);speek("��������Ϊ3�ĸ���");break;
		case 4:PrintCom(YIN_SU4,9);osdelay_ms(10);speek("��������Ϊ4�ĸ���");break;
		case 5:PrintCom(YIN_SU5,9);osdelay_ms(10);speek("��������Ϊ5�ĸ���");break;
		case 6:PrintCom(YIN_SU6,9);osdelay_ms(10);speek("��������Ϊ6�ĸ���");break;
		case 7:PrintCom(YIN_SU7,9);osdelay_ms(10);speek("��������Ϊ7�ĸ���");break;
		case 8:PrintCom(YIN_SU8,9);osdelay_ms(10);speek("��������Ϊ8�ĸ���");break;
		case 9:PrintCom(YIN_SU9,9);osdelay_ms(10);speek("��������Ϊ9�ĸ���");break;
	}                                                                         
}
//���ѡ��
void yudiao(u8 num)
{
	switch(num)
	{
		case 0:PrintCom(YIN_DIAO0,9);osdelay_ms(10);speek("�������Ϊ0�ĸ���");break;
		case 1:PrintCom(YIN_DIAO1,9);osdelay_ms(10);speek("�������Ϊ1�ĸ���");break;
		case 2:PrintCom(YIN_DIAO2,9);osdelay_ms(10);speek("�������Ϊ2�ĸ���");break;
		case 3:PrintCom(YIN_DIAO3,9);osdelay_ms(10);speek("�������Ϊ3�ĸ���");break;
		case 4:PrintCom(YIN_DIAO4,9);osdelay_ms(10);speek("�������Ϊ4�ĸ���");break;
		case 5:PrintCom(YIN_DIAO5,9);osdelay_ms(10);speek("�������Ϊ5�ĸ���");break;
		case 6:PrintCom(YIN_DIAO6,9);osdelay_ms(10);speek("�������Ϊ6�ĸ���");break;
		case 7:PrintCom(YIN_DIAO7,9);osdelay_ms(10);speek("�������Ϊ7�ĸ���");break;
		case 8:PrintCom(YIN_DIAO8,9);osdelay_ms(10);speek("�������Ϊ8�ĸ���");break;
		case 9:PrintCom(YIN_DIAO9,9);osdelay_ms(10);speek("�������Ϊ9�ĸ���");break;
	}                                                                         
}

                                        

