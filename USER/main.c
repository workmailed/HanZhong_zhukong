#include "sys.h"

//����Щ���ȼ��������UCOSIII��5��ϵͳ�ڲ�����
//���ȼ�0���жϷ������������� OS_IntQTask()
//���ȼ�1��ʱ�ӽ������� OS_TickTask()
//���ȼ�2����ʱ���� OS_TmrTask()
//���ȼ�OS_CFG_PRIO_MAX-2��ͳ������ OS_StatTask()
//���ȼ�OS_CFG_PRIO_MAX-1���������� OS_IdleTask()
//�������ȼ�
#define START_TASK_PRIO		3
//�����ջ��С	
#define START_STK_SIZE 		512
//������ƿ�
OS_TCB StartTaskTCB;
//�����ջ	
CPU_STK START_TASK_STK[START_STK_SIZE];
//������
void start_task(void *p_arg);

//�������ȼ�
#define Transducer_TASK_PRIO		4
//�����ջ��С	
#define Transducer_STK_SIZE 		512
//������ƿ�
OS_TCB TransducerTaskTCB;
//�����ջ	
CPU_STK Transducer_TASK_STK[Transducer_STK_SIZE];
void Transducer_task(void *p_arg);


//�������ȼ�
#define Auto_TASK_PRIO		5
//�����ջ��С	
#define Auto_STK_SIZE 		512
//������ƿ�
OS_TCB AutoTaskTCB;
//�����ջ	
CPU_STK Auto_TASK_STK[Auto_STK_SIZE];
//������
void Auto_task(void *p_arg);

//�������ȼ�
#define Manual_TASK_PRIO		6
//�����ջ��С	
#define Manual_STK_SIZE 		512
//������ƿ�
OS_TCB ManualTaskTCB;
//�����ջ	
CPU_STK Manual_TASK_STK[Manual_STK_SIZE];
//������
void Manual_task(void *p_arg);

//�������ȼ�
#define FLOAT_TASK_PRIO		7
//�����ջ��С
#define FLOAT_STK_SIZE		512
//������ƿ�
OS_TCB	FloatTaskTCB;
//�����ջ
CPU_STK	FLOAT_TASK_STK[FLOAT_STK_SIZE];
//������
void float_task(void *p_arg);

//�������ȼ�
#define DEMO_TASK_PRIO		8
//�����ջ��С	
#define DEMO_STK_SIZE 		512
//������ƿ�
OS_TCB DEMOTaskTCB;
//�����ջ	
CPU_STK DEMO_TASK_STK[DEMO_STK_SIZE];
//������
void DEMO_task(void *p_arg);

//�������ȼ�
#define Task5_TASK_PRIO		9
//�����ջ��С	
#define Task5_STK_SIZE 		512
//������ƿ�
OS_TCB Task5_TaskTCB;
//�����ջ	
CPU_STK Task5_TASK_STK[Task5_STK_SIZE];
//������
void Task5_task(void *p_arg);


//�������ȼ�
#define Control_TASK_PRIO		10
//�����ջ��С	
#define Control_STK_SIZE 		512
//������ƿ�
OS_TCB ControlTaskTCB;
//�����ջ	
CPU_STK Control_TASK_STK[Control_STK_SIZE];
//������
void Control_task(void *p_arg);


//�������ȼ�
#define WIFI_TASK_PRIO		11
//�����ջ��С	
#define WIFI_STK_SIZE 		512
//������ƿ�
OS_TCB WIFITaskTCB;
//�����ջ	
CPU_STK WIFI_TASK_STK[WIFI_STK_SIZE];
//������
void WIFI_task(void *p_arg);


//�������ȼ�
#define Screen_TASK_PRIO		12
//�����ջ��С	
#define Screen_STK_SIZE 		512
//������ƿ�
OS_TCB ScreenTaskTCB;
//�����ջ	
CPU_STK Screen_TASK_STK[Screen_STK_SIZE];
//������
void Screen_task(void *p_arg);


//�������ȼ�
#define DEMO1_TASK_PRIO		13
//�����ջ��С	
#define DEMO1_STK_SIZE 		512
//������ƿ�
OS_TCB DEMO1TaskTCB;
//�����ջ	
CPU_STK DEMO1_TASK_STK[DEMO1_STK_SIZE];
//������
void DEMO1_task(void *p_arg);

//�������ȼ�
#define DEMO2_TASK_PRIO		14
//�����ջ��С	
#define DEMO2_STK_SIZE 		512
//������ƿ�
OS_TCB DEMO2TaskTCB;
//�����ջ	
CPU_STK DEMO2_TASK_STK[DEMO2_STK_SIZE];
//������
void DEMO2_task(void *p_arg);

//�������ȼ�
#define PID_TASK_PRIO		15
//�����ջ��С	
#define PID_STK_SIZE 		512
//������ƿ�
OS_TCB PIDTaskTCB;
//�����ջ	
CPU_STK PID_TASK_STK[PID_STK_SIZE];
//������
void PID_task(void *p_arg);

int main(void)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	
	delay_init(168);  	//ʱ�ӳ�ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�жϷ�������

	LED_Init();         //LED��ʼ��	
	DMA_adc1_Init();
	DMA_Uart4_Init();
	DMA_Uart2_Init();
	DMA_Uart6_Init();
	DMA_Uart3_Init();
	ADC1_Configuration();
	USART1_Configuration(9600);
	USART4_Configuration(9600);
	USART6_Configuration(115200);
	USART2_Configuration(9600);
	USART3_Configuration(9600);

	CAN1_Mode_Init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,6,CAN_Mode_Normal);//CAN1��ʼ����ͨģʽ,������500Kbps
	CAN2_Mode_Init(CAN_SJW_1tq,CAN_BS2_6tq,CAN_BS1_7tq,6,CAN_Mode_Normal);//CAN2��ʼ����ͨģʽ,������500Kbps
	IWDG_Init(4,500);
	TLC5620_Init();
	//���ͼ̵�����ͬ����Ϣ
	CAN2_Send_Msg(can_Sebuf,4);
	can_Sebuf[3]=0;
	
	send3_buf[0] = 1;//��ң�������͸�λ�ź�
	send3_buf[1] = 0;
	send3_buf[2] = 1;
	Uart3_Start_DMA_Tx(3);
		
	
	OSInit(&err);		//��ʼ��UCOSIII
	OS_CRITICAL_ENTER();//�����ٽ���
	//������ʼ����
	OSTaskCreate((OS_TCB 	* )&StartTaskTCB,		//������ƿ�
				 (CPU_CHAR	* )"start task", 		//��������
                 (OS_TASK_PTR )start_task, 			//������
                 (void		* )0,					//���ݸ��������Ĳ���
                 (OS_PRIO	  )START_TASK_PRIO,     //�������ȼ�
                 (CPU_STK   * )&START_TASK_STK[0],	//�����ջ����ַ
                 (CPU_STK_SIZE)START_STK_SIZE/10,	//�����ջ�����λ
                 (CPU_STK_SIZE)START_STK_SIZE,		//�����ջ��С
                 (OS_MSG_QTY  )0,					//�����ڲ���Ϣ�����ܹ����յ������Ϣ��Ŀ,Ϊ0ʱ��ֹ������Ϣ
                 (OS_TICK	  )0,					//��ʹ��ʱ��Ƭ��תʱ��ʱ��Ƭ���ȣ�Ϊ0ʱΪĬ�ϳ��ȣ�
                 (void   	* )0,					//�û�����Ĵ洢��
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, //����ѡ��
                 (OS_ERR 	* )&err);				//��Ÿú�������ʱ�ķ���ֵ
	OS_CRITICAL_EXIT();	//�˳��ٽ���	 
	OSStart(&err);  //����UCOSIII
	while(1);
}
//��ʼ������
void start_task(void *p_arg)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	p_arg = p_arg;

	CPU_Init();
#if OS_CFG_STAT_TASK_EN > 0u
   OSStatTaskCPUUsageInit(&err);  	//ͳ������                
#endif
	
#ifdef CPU_CFG_INT_DIS_MEAS_EN		//���ʹ���˲����жϹر�ʱ��
    CPU_IntDisMeasMaxCurReset();	
#endif

#if	OS_CFG_SCHED_ROUND_ROBIN_EN  //��ʹ��ʱ��Ƭ��ת��ʱ��
	 //ʹ��ʱ��Ƭ��ת���ȹ���,ʱ��Ƭ����Ϊ1��ϵͳʱ�ӽ��ģ���1*5=5ms
	OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);  
#endif		
	
	OS_CRITICAL_ENTER();	//�����ٽ���
	//����Transducer����
	OSTaskCreate((OS_TCB 	* )&TransducerTaskTCB,		
				 (CPU_CHAR	* )"Transducer task", 		
                 (OS_TASK_PTR )Transducer_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Transducer_TASK_PRIO,     
                 (CPU_STK   * )&Transducer_TASK_STK[0],	
                 (CPU_STK_SIZE)Transducer_STK_SIZE/10,	
                 (CPU_STK_SIZE)Transducer_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);								 
	
	//�����Զ�����
	OSTaskCreate((OS_TCB 	* )&AutoTaskTCB,		
				 (CPU_CHAR	* )"Auto task", 		
                 (OS_TASK_PTR )Auto_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Auto_TASK_PRIO,     	
                 (CPU_STK   * )&Auto_TASK_STK[0],	
                 (CPU_STK_SIZE)Auto_STK_SIZE/10,	
                 (CPU_STK_SIZE)Auto_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);				 
				 
	//���������������
	OSTaskCreate((OS_TCB 	* )&FloatTaskTCB,		
				 (CPU_CHAR	* )"float test task", 		
                 (OS_TASK_PTR )float_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )FLOAT_TASK_PRIO,     	
                 (CPU_STK   * )&FLOAT_TASK_STK[0],	
                 (CPU_STK_SIZE)FLOAT_STK_SIZE/10,	
                 (CPU_STK_SIZE)FLOAT_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	

	//��������������
	OSTaskCreate((OS_TCB 	* )&ScreenTaskTCB,		
				 (CPU_CHAR	* )"Screen task", 		
                 (OS_TASK_PTR )Screen_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Screen_TASK_PRIO,     	
                 (CPU_STK   * )&Screen_TASK_STK[0],	
                 (CPU_STK_SIZE)Screen_STK_SIZE/10,	
                 (CPU_STK_SIZE)Screen_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	

	//PID
	OSTaskCreate((OS_TCB 	* )&PIDTaskTCB,		
				 (CPU_CHAR	* )"PID task", 		
                 (OS_TASK_PTR )PID_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )PID_TASK_PRIO,     	
                 (CPU_STK   * )&PID_TASK_STK[0],	
                 (CPU_STK_SIZE)PID_STK_SIZE/10,	
                 (CPU_STK_SIZE)PID_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
	//Control
	OSTaskCreate((OS_TCB 	* )&ControlTaskTCB,		
				 (CPU_CHAR	* )"Control task", 		
                 (OS_TASK_PTR )Control_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )Control_TASK_PRIO,     	
                 (CPU_STK   * )&Control_TASK_STK[0],	
                 (CPU_STK_SIZE)Control_STK_SIZE/10,	
                 (CPU_STK_SIZE)Control_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
	//DEMO
	OSTaskCreate((OS_TCB 	* )&DEMOTaskTCB,		
				 (CPU_CHAR	* )"DEMO task", 		
                 (OS_TASK_PTR )DEMO_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )DEMO_TASK_PRIO,     	
                 (CPU_STK   * )&DEMO_TASK_STK[0],	
                 (CPU_STK_SIZE)DEMO_STK_SIZE/10,	
                 (CPU_STK_SIZE)DEMO_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);				 
	//DEMO1
	OSTaskCreate((OS_TCB 	* )&DEMO1TaskTCB,		
				 (CPU_CHAR	* )"DEMO1 task", 		
                 (OS_TASK_PTR )DEMO1_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )DEMO1_TASK_PRIO,     	
                 (CPU_STK   * )&DEMO1_TASK_STK[0],	
                 (CPU_STK_SIZE)DEMO1_STK_SIZE/10,	
                 (CPU_STK_SIZE)DEMO1_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);	
	//DEMO2
	OSTaskCreate((OS_TCB 	* )&DEMO2TaskTCB,		
				 (CPU_CHAR	* )"DEMO2 task", 		
                 (OS_TASK_PTR )DEMO2_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )DEMO2_TASK_PRIO,     	
                 (CPU_STK   * )&DEMO2_TASK_STK[0],	
                 (CPU_STK_SIZE)DEMO2_STK_SIZE/10,	
                 (CPU_STK_SIZE)DEMO2_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,					
                 (void   	* )0,				
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
                 (OS_ERR 	* )&err);
				 
	//�����ֶ�����
	OSTaskCreate((OS_TCB 	* )&ManualTaskTCB,		
				 (CPU_CHAR	* )"Manual task", 		
				 (OS_TASK_PTR )Manual_task, 			
				 (void		* )0,					
				 (OS_PRIO	  )Manual_TASK_PRIO,     	
				 (CPU_STK   * )&Manual_TASK_STK[0],	
				 (CPU_STK_SIZE)Manual_STK_SIZE/10,	
				 (CPU_STK_SIZE)Manual_STK_SIZE,		
				 (OS_MSG_QTY  )0,					
				 (OS_TICK	  )0,					
				 (void   	* )0,				
				 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
				 (OS_ERR 	* )&err);
				 
	OSTaskCreate((OS_TCB 	* )&WIFITaskTCB,		
				 (CPU_CHAR	* )"WIFI task", 		
				 (OS_TASK_PTR )WIFI_task, 			
				 (void		* )0,					
				 (OS_PRIO	  )WIFI_TASK_PRIO,     	
				 (CPU_STK   * )&WIFI_TASK_STK[0],	
				 (CPU_STK_SIZE)WIFI_STK_SIZE/10,	
				 (CPU_STK_SIZE)WIFI_STK_SIZE,		
				 (OS_MSG_QTY  )0,					
				 (OS_TICK	  )0,					
				 (void   	* )0,				
				 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
				 (OS_ERR 	* )&err);	
							 
	OSTaskCreate((OS_TCB 	* )&Task5_TaskTCB,		
				 (CPU_CHAR	* )"Task5 task", 		
				 (OS_TASK_PTR )Task5_task, 			
				 (void		* )0,					
				 (OS_PRIO	  )Task5_TASK_PRIO,     	
				 (CPU_STK   * )&Task5_TASK_STK[0],	
				 (CPU_STK_SIZE)Task5_STK_SIZE/10,	
				 (CPU_STK_SIZE)Task5_STK_SIZE,		
				 (OS_MSG_QTY  )0,					
				 (OS_TICK	  )0,					
				 (void   	* )0,				
				 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
				 (OS_ERR 	* )&err);
				 
	OS_TaskSuspend((OS_TCB*)&StartTaskTCB,&err);		//����ʼ����			 
	OS_CRITICAL_EXIT();	//�����ٽ���
}
//���Զ��л�
void Transducer_task(void *p_arg)
{
	p_arg = p_arg;
	HmiScreenControlMode = 1;
	while(1)
	{	
		delay(0,0,0,5); //��ʱ5ms
	}
}
//�Զ���ť���
void Auto_task(void *p_arg)
{
	p_arg = p_arg;
	while(1)
	{
		delay(0,0,0,5); //��ʱ5ms
	}
}
//�ֶ�����
void Manual_task(void *p_arg)
{
	p_arg = p_arg;
	while(1)
	{
		if(All_flag.flag_szd==1)
		{
			if(All_flag.speek_flag==0)
			{
				if((QianJin==0))//ǰ��
				{
					CanSend_data(1);					
					while(QianJin==0)
					{
						Motor_Zzhuan(1,SouDongSuDu);
						Motor_Zzhuan(2,SouDongSuDu);
						Motor_Zzhuan(3,SouDongSuDu);
						Motor_Zzhuan(4,SouDongSuDu);						
						delay(0,0,0,10);
					}	
					MotoStop(5);
		//			if((ZuoXuan==0))//����
		//			{
		//				Motor_Zzhuan(2,SouDongSuDu*1.5);
		//				Motor_Zzhuan(4,SouDongSuDu*1.5);
		//			}
		//			else if((YouXuan==0))//����
		//			{
		//				Motor_Zzhuan(1,SouDongSuDu*1.5);
		//				Motor_Zzhuan(3,SouDongSuDu*1.5);
		//			}			
				}
				else if((HouTui==0))//����
				{
					CanSend_data(2);
					while(HouTui==0)
					{
						Motor_Fzhuan(1,SouDongSuDu);
						Motor_Fzhuan(2,SouDongSuDu);
						Motor_Fzhuan(3,SouDongSuDu);
						Motor_Fzhuan(4,SouDongSuDu);						
						delay(0,0,0,10);
					}
					MotoStop(5);
		//			if((ZuoXuan==0))//����
		//			{
		//				Motor_Zzhuan(2,SouDongSuDu*1.5);
		//				Motor_Zzhuan(4,SouDongSuDu*1.5);
		//			}
		//			else if((YouXuan==0))//����
		//			{
		//				Motor_Zzhuan(1,SouDongSuDu*1.5);
		//				Motor_Zzhuan(3,SouDongSuDu*1.5);
		//			}
				}
				else if((ZuoYi==0))//����
				{
					CanSend_data(3);
					while(ZuoYi==0)
					{
						Motor_Fzhuan(1,SouDongSuDu);
						Motor_Zzhuan(2,SouDongSuDu);
						Motor_Zzhuan(3,SouDongSuDu);
						Motor_Fzhuan(4,SouDongSuDu);						
						delay(0,0,0,10);
					}
					MotoStop(5);
				}
				else if((YouYI==0))//����
				{
					CanSend_data(4);
					while(YouYI==0)
					{
						Motor_Zzhuan(1,SouDongSuDu);
						Motor_Fzhuan(2,SouDongSuDu);
						Motor_Fzhuan(3,SouDongSuDu);
						Motor_Zzhuan(4,SouDongSuDu);						
						delay(0,0,0,10);
					}
					MotoStop(5);
				}
				else if((ZuoShang==0))//����
				{
					CanSend_data(5);
					while(ZuoShang==0)
					{
						MotoStop(1);			
						Motor_Zzhuan(2,SouDongSuDu);
						Motor_Zzhuan(3,SouDongSuDu);
						MotoStop(4);						
						delay(0,0,0,10);
					}
					MotoStop(5);
				}
				else if((ZuoXia==0))//����
				{
					CanSend_data(6);
					while(ZuoXia==0)
					{
						Motor_Fzhuan(1,SouDongSuDu);
						MotoStop(2);
						MotoStop(3);
						Motor_Fzhuan(4,SouDongSuDu);						
						delay(0,0,0,10);
					}
					MotoStop(5);			
				}
				else if((YouShang==0))//����
				{
					CanSend_data(7);
					while(YouShang==0)
					{
						Motor_Zzhuan(1,SouDongSuDu);
						MotoStop(2);
						MotoStop(3);
						Motor_Zzhuan(4,SouDongSuDu);
						delay(0,0,0,10);
					}
					MotoStop(5);			
				}
				else if((YouXia==0))//����
				{
					CanSend_data(8);
					while(YouXia==0)
					{
						MotoStop(1);
						Motor_Fzhuan(2,SouDongSuDu);
						Motor_Fzhuan(3,SouDongSuDu);
						MotoStop(4);						
						delay(0,0,0,10);
					}
					MotoStop(5);			
				}
				else if((ZuoXuan==0))//����
				{
					CanSend_data(9);
					while(ZuoXuan==0)
					{
						Motor_Fzhuan(1,SouDongSuDu);
						Motor_Zzhuan(2,SouDongSuDu);
						Motor_Fzhuan(3,SouDongSuDu);
						Motor_Zzhuan(4,SouDongSuDu);						
						delay(0,0,0,10);
					}	
					MotoStop(5);			
				}
				else if((YouXuan==0))//����
				{
					CanSend_data(10);
					while(YouXuan==0)
					{
						Motor_Zzhuan(1,SouDongSuDu);
						Motor_Fzhuan(2,SouDongSuDu);
						Motor_Zzhuan(3,SouDongSuDu);
						Motor_Fzhuan(4,SouDongSuDu);						
						delay(0,0,0,10);
					}
					MotoStop(5);
				}			
			}		
		
		}
		delay(0,0,0,10); //��ʱ10ms	
	}
}
//���PID����
u8 cy_time=5;
void PID_task(void *p_arg)
{
	while(1)
	{
		delay(0,0,0,cy_time);
	}
}
//����������ص����澯���������λ��ͨѶ
void float_task(void *p_arg)
{
	u8 num=0;
	u16 num_beep=0;
	p_arg = p_arg;
	while(1)
	{	
		if(All_flag.beep_flag)
		{
			BEEP=1;
			num_beep++;
			if(num_beep==40)
			{
				num_beep = 0;
				BEEP=0;
				All_flag.beep_flag = 0;				
			}
		}
		num++;
		if(num==200)
		{
			LED1 = ~LED1;//���е�
			TongXunDeng=~TongXunDeng;//������ͨѶָʾ��
			num=0;
		}
		
		delay(0,0,0,5); //��ʱ5ms
	}
}
 //��������·�����̲�������
void Screen_task(void*p_arg)
{
    OS_ERR err ;
    u16 i=0,j=0 ;   
    //�û�������ʼ��
    JieMianHao=22 ;
    
    while(1)
    {
        switch(JieMianHao)
        {
            case 0 :
            break ;
			case 2 :
            break ;
            case ZiDongMoShiJieMian :
				while(JieMianHao==ZiDongMoShiJieMian)
				{
					osdelay_ms(10);
				}				
            break ;
            case 4 :
            break ;
			//·���滮����
            case LuJingGuiHuaJieMian :
            {			
				while(JieMianHao==LuJingGuiHuaJieMian||JieMianHao==QueDingChaRuLuJingJieMian||JieMianHao==QueDingShanChuLuJingJieMian
					||JieMianHao==FuZhiLuJingTanChuJieMian)
				{  
					//����·��
					while(JieMianHao==FuZhiLuJingTanChuJieMian)//���ڸ���·������
					{
						//������·����Ϊ��ʱ��1
						if(HmiRouteCopiedNum==0)
							HmiRouteCopiedNum=1;	
						if(HmiRouteCopiedNum>RouteNum)	
						{
							HmiRouteCopiedNum =1;
						}
						
						//����ı�����·���ű仯ʱ����
						if(HmiRouteCopiedNumTemp!=HmiRouteCopiedNum)
							HmiRouteCopiedCount = GetRouteStationNum(HmiRouteCopiedNum);
						
						
						//ȷ������
						if(HmiRoutemode==1)
						{
							//��ȡ��������Ϣ����ǰ
							GetRouteData(HmiRouteCopiedNum);
							
							//���沢���±�������Ϣ
							SetRouteData(HmiRouteNum);	
							
							UpdataStationToHmi();
							
							//���õ�ǰվ��Ϊ1
							if(HmiStationNum!=0)
								HmiStationSerialNum = 1;
							
							//�˳�����ģʽ
							HmiRoutemode=0;
						}
						osdelay_ms(10);
					}

					//���վ��
					if(HmiRoutemode==2)
					{ 
						//վ������һ
						HmiStationNum ++;
						//վ��ŵ���վ����
						HmiStationSerialNum = HmiStationNum;
						
						//�ر������
						keynumber = 0;		
						
						ClearStationToHmi();	
						
						while(HmiRoutemode==2)
						{
							//��������ر꣬���µ���ʾ��
							if(keynumber!=0)
							{
								HmiRfidNum = keynumber;//ˢ�µر��
							}										
							//ȷ��
							if(HmiRouteEnter==1)
							{
								HmiRouteEnter = 0;
								//����վ�����ݵ���ǰ����
								UpdataStationToNow();

								//����վ����Ϣ
								SetStationData(HmiRouteNum,HmiStationSerialNum-1);
								//�˳����ģʽ
								HmiRoutemode = 0;
							}
							else
							//ȡ��
							if(HmiRouteEnter==2)
							{
								HmiRouteEnter = 0;
								//վ������һ
								HmiStationNum--;
								//վ��ŵ���վ����
								HmiStationSerialNum = HmiStationNum;
								//�˳����ģʽ
								HmiRoutemode = 0;
							}
							osdelay_ms(10);
						}
					}
					//����վ��
					if(HmiRoutemode==3)
					{
						//վ������һ
						HmiStationNum ++;
						//վ���Ϊ��ʱ��һ
						if(HmiStationNum==0)
							HmiStationSerialNum = 1;
						
						//�ر������
						keynumber = 0;		
						
						ClearStationToHmi();										

						while(HmiRoutemode==3)
						{
							//��������ر꣬���µ���ʾ��
							if(keynumber!=0)
							{
								HmiRfidNum = keynumber;//ˢ�µر��
							}												
							
							//ȷ��
							if(HmiRouteEnter==1)
							{
								HmiRouteEnter = 0;
								
								//վ����Ϣ����ƶ�һ��λ�ã������뵱ǰվ����Ϣ
								for(i=HmiStationNum;i>=HmiStationSerialNum;i--)
								{
									for(j=0;j<StaiionInfor;j++)
									{
										NowRouteInfor[i][j] = NowRouteInfor[i-1][j];
									}
								}
								
								//����վ����Ϣ����ǰ
								UpdataStationToNow();
								
								//����·����Ϣ
								SetRouteData(HmiRouteNum);

								//�˳����ģʽ
								HmiRoutemode=	0;
							}
							else
							//ȡ��
							if(HmiRouteEnter==2)
							{
								HmiRouteEnter = 0;
								//վ������һ
								HmiStationNum--;
								//վ���Ϊ1ʱ����
								if(HmiStationSerialNum==1)
									HmiStationSerialNum = 0;
								//�˳����ģʽ
								HmiRoutemode=	0;
							}

							osdelay_ms(10);
						}

					}
					//����վ��
					if(HmiRoutemode==4)
					{
						keynumber = 0;
						while(HmiRoutemode==4)
						{
							//��������ر꣬���µ���ʾ��
							if(keynumber!=0)
							{
								HmiRfidNum = keynumber;//ˢ�µر��
							}			
							
							//ȷ��
							if(HmiRouteEnter==1)
							{
								HmiRouteEnter = 0;
								//����վ�����ݵ���ǰ����
								UpdataStationToNow();
								//���浱ǰվ������
								SetRouteData(HmiRouteNum);
								//�˳����ģʽ
								HmiRoutemode = 0;
							}
							else
							//ȡ��
							if(HmiRouteEnter==2)
							{
								HmiRouteEnter = 0;
								//���µ�����
								UpdataStationToHmi();
								//�˳����ģʽ
								HmiRoutemode=	0;
							}
							osdelay_ms(10);
						}
					}
				
					//ɾ��վ��
					if(HmiRoutemode==5)
					{
						if(HmiStationNum>0)
						{
							//��������������ǰ�ƶ�һλ
							if((HmiStationNum>0)&&((HmiStationNum)!=HmiStationSerialNum))
							{
								//վ����Ϣ��ǰ�ƶ�һ��λ��
								for(i=HmiStationSerialNum;i<HmiStationNum;i++)
								{
									for(j=0;j<StaiionInfor;j++)
									{
										NowRouteInfor[i-1][j] = NowRouteInfor[i][j];
									}
								}
							}

							HmiStationNum--;
							if(HmiStationNum==0)
								HmiStationSerialNum = 0;
							else if((HmiStationNum+1 )== HmiStationSerialNum)
								HmiStationSerialNum--;
							//����·����Ϣ
							SetRouteData(HmiRouteNum);
							
							//���½���
							UpdataStationToHmi();
						}	
						HmiRoutemode = 0;
					}
					
					//��ѯվ��
					if(HmiRoutemode==0)
					{
						//��·��վ��������0���������Ϊ0ʱ���������Ϊ1����������ʾ����
						if((HmiStationNum>0)&&(HmiStationSerialNum==0))
						{
							HmiStationSerialNum = 1;
							//���µ�����
							UpdataStationToHmi();
						}
						else
						if(HmiStationNum==0)
						{
							HmiStationSerialNum = 0;
						}
						
						//·���ű仯ʱ�����½���
						if(HmiRouteNumFlag != HmiRouteNum)
						{
							HmiRouteNumFlag = HmiRouteNum;
							//��ȡ·����Ϣ
							GetRouteData(HmiRouteNum);
							
							if(HmiStationNum>0)
								HmiStationSerialNum = 1;
							//���µ�����
							UpdataStationToHmi();
							
						}
						
						//��һ��
						if(HmiStationLast == 1)
						{
							HmiStationLast = 0;
							if(HmiStationSerialNum>1)
								HmiStationSerialNum--;
							else
								HmiStationSerialNum = HmiStationNum;
						}
						//��һ��
						if(HmiStationNext == 2)
						{
							HmiStationNext = 0;
							if(HmiStationSerialNum<HmiStationNum)
									HmiStationSerialNum++;
								else
									if(HmiStationSerialNum!=0)
										HmiStationSerialNum = 1;
						}
						
						if(HmiStationNum==0)		//û��վ��
						{
							//���վ����Ϣ
							ClearStationToHmi();
						}
						else
						{
							//����վ����Ϣ
							UpdataStationToHmi();
						}
					}
					osdelay_ms(10);
				}
			}
            break ;
			case 7 :
            case 6 :
			//���Խ�������
			case 8:
				while(JieMianHao==8)
				{		
					 SystemParameter[19] = PIDZhouQi;
					 SystemParameter[20] = SPID_P;
					 SystemParameter[21] = SPID_I ;
					 SystemParameter[22] = SPID_D;
					 SystemParameter[23] = QianHouJuLi;
					 SystemParameter[15] = ZiDongJiSu;
					 delay(0,0,0,10);					
				}			
				//�洢����ϵͳ����
				SetAllParameterToSystem();
			break;
			case 9 :
            //��������
            //
            while(JieMianHao==9)
            {				                            
				SystemParameter[9] = PLC_Data[22];//����
				SystemParameter[10] = PLC_Data[23];//����
				SystemParameter[11] = PLC_Data[24];//����
				SystemParameter[14] = SouDongSuDu;
				SystemParameter[15] = ZiDongJiSu;
				SystemParameter[16] = SouDongBiZhang;
				SystemParameter[17] = YuYinKaiGuan;
				SystemParameter[18] = YinLiang;
				SystemParameter[98] = LiuChengZongShu;
				SystemParameter[99] = LuJingZongShu;
				SystemParameter[25]	= CheHao;	
                delay(0,0,0,10);
            }
            //ѭ���������������
			//Your Save Code��
			//�洢����ϵͳ����
			SetAllParameterToSystem();			
            break ;
			//��������
			case LiuChengGuiHuaJieMian:
				{
						while(JieMianHao==LiuChengGuiHuaJieMian||JieMianHao==FuZhiLiuChengTanChuJieMian||JieMianHao==QueDingChaRuLiuChengJieMian
							||JieMianHao==QueDingShanChuLiuChengJieMian)
						{ 
							//�鿴ģʽ
							if(HmiProcessMode==0)
							{
								//��ǰ���̲�������0�����ҽ������Ϊ0ʱ���������Ϊ1����������ʾ����
								if((HmiStepNum>0)&&(HmiProcessSerialNum==0))
								{
									HmiProcessSerialNum = 1;
									GetProcessData();
								}
								else
								if(HmiStepNum==0)
								{
									HmiProcessSerialNum = 0;
									HmiProcessStartNum = 1;
									HmiProcessStopNum = 0;
									HmiProcessAction = 0;
								}
								
								//���̺ű仯ʱ�����½���
								if(HmiProcessNumFlag != HmiProcessNum)
								{
									HmiProcessNumFlag = HmiProcessNum;
									GetProcessData();
								}
								
								if(HmiProcessLast==1)//��һ��
								{
									HmiProcessLast = 0;
									if(HmiProcessSerialNum>1)
										HmiProcessSerialNum--;
									else
										HmiProcessSerialNum = HmiStepNum;
								}
								else
									if(HmiProcessNext==2)//��һ��
									{
										HmiProcessNext = 0;
										if(HmiProcessSerialNum<HmiStepNum)
											HmiProcessSerialNum++;
										else
											if(HmiProcessSerialNum!=0)
												HmiProcessSerialNum = 1;
									}
								if(HmiStepNum==0)
								{
									ClearStepToHmi();
								}
								else
								{
									UpdataProcessToHmi();
								}								
							}									
							//��������
							if(JieMianHao==FuZhiLiuChengTanChuJieMian)
							{
								while(JieMianHao==FuZhiLiuChengTanChuJieMian)
								{
									//���������̺�Ϊ��ʱ��1
									if(HmiProcessCopiedNum==0)
										HmiProcessCopiedNum=1;	
									//����ı��������̺ű仯ʱ����
									if(HmiProcessCopiedNumTemp!=HmiProcessCopiedNum)
										HmiProcessCopiedCount = GetProcessStepNum(HmiProcessCopiedNum);
									if(HmiProcessCopiedNum>ProcessNum)
									{
										HmiProcessCopiedNum = 1;
									}
									//ȷ������
									if(HmiProcessMode==1)
									{
										//��ȡ��������Ϣ����ǰ
										GetProcessDataFrom(HmiProcessCopiedNum);
										//���汻������Ϣ
										SetProcessData();	
										
										//���õ�ǰ���Ϊ1
										if(HmiStepNum!=0)
											HmiProcessSerialNum = 1;
									
										//�˳�����ģʽ
										HmiProcessMode = 0;
									}
									osdelay_ms(10);
								}
							}
							//�������
							if(HmiProcessMode==2)
							{
								//���̲�����һ
								HmiStepNum++;
								//��ŵ���������
								HmiProcessSerialNum = HmiStepNum;
								
								//��ʼ·����Ĭ��Ϊ0����1
								if(HmiProcessStartNum==0)
									HmiProcessStartNum = 1;
								
								ClearStepToHmi();
								
								while(HmiProcessMode==2)
								{
									switch(HmiProcessAction)
									{
										case 0://����ִ��
											break;
										case 1://˳��ִ�е�
											if(HmiProcessStopNum<=HmiProcessStartNum)
											{
												if(HmiProcessStartNum==ProcessNum)
													HmiProcessStopNum=HmiProcessStartNum;
												else
													HmiProcessStopNum=HmiProcessStartNum+1;
											}
											break;
										case 2://����ִ��
											if(HmiProcessStopNum>=HmiProcessStartNum)
											{
												if(HmiProcessStartNum==1)
													HmiProcessStopNum=HmiProcessStartNum;
												else
													HmiProcessStopNum=HmiProcessStartNum-1;
											}
											break;
										case 3://ѭ��ִ��
											if(HmiProcessStopNum==0)
											{
													HmiProcessStopNum=1;
											}
											break;
										default:break;
									}
									
									//ȷ��
									if(HmiProcessEnter==1)
									{
										HmiProcessEnter = 0;
										//���沢��������
										SetProcessData();
										
										//�˳����ģʽ
										HmiProcessMode = 0;
									}
									//ȡ��
									else if(HmiProcessEnter==2) 
									{
										HmiProcessEnter = 0;
										
										//���̲�����һ
										HmiStepNum--;
										//��ŵ���������
										HmiProcessSerialNum = HmiStepNum;
										
										//�˳����ģʽ
										HmiProcessMode = 0;
									}
									osdelay_ms(10);
								}
							}
							
							//��������
							if(HmiProcessMode==3)
							{
								//���̲�����һ
								HmiStepNum++;
								//���Ϊ��ʱ��һ
								if(HmiProcessSerialNum==0)
									HmiProcessSerialNum = 1;
								
								//��ʼ·����Ĭ��Ϊ0����1
								if(HmiProcessStartNum==0)
									HmiProcessStartNum = 1;
								
								ClearStepToHmi();
								
								while(HmiProcessMode==3)
								{
									switch(HmiProcessAction)
									{
										case 0://����ִ��
											break;
										case 1://˳��ִ�е�
											if(HmiProcessStopNum<=HmiProcessStartNum)
											{
												if(HmiProcessStartNum==ProcessNum)
													HmiProcessStopNum=HmiProcessStartNum;
												else
													HmiProcessStopNum=HmiProcessStartNum+1;
											}
											break;
										case 2://����ִ��
											if(HmiProcessStopNum>=HmiProcessStartNum)
											{
												if(HmiProcessStartNum==1)
													HmiProcessStopNum=HmiProcessStartNum;
												else
													HmiProcessStopNum=HmiProcessStartNum-1;
											}
											break;
										case 3://ѭ��ִ��
											if(HmiProcessStopNum==0)
											{
													HmiProcessStopNum=1;
											}
											break;
										default:break;
									}
									
									//ȷ��
									if(HmiProcessEnter==1)
									{
										HmiProcessEnter = 0;
										
										//���沢��������
										InsertProcessData();
										
										//�˳�����ģʽ
										HmiProcessMode = 0;
									}
									//ȡ��
									else if(HmiProcessEnter==2) 
									{
										HmiProcessEnter = 0;
										
										//���̲�����һ
										HmiStepNum--;
										//���Ϊ1ʱ��һ
										if(HmiProcessSerialNum==1)
											HmiProcessSerialNum = 0;
										
										//�˳����ģʽ
										HmiProcessMode = 0;
									}
									osdelay_ms(10);
								}
							}									
							//��������
							if(HmiProcessMode==4)
							{
								while(HmiProcessMode==4)
								{
									switch(HmiProcessAction)
									{
										case 0://����ִ��
											break;
										case 1://˳��ִ�е�
											if(HmiProcessStopNum<=HmiProcessStartNum)
											{
												if(HmiProcessStartNum==ProcessNum)
													HmiProcessStopNum=HmiProcessStartNum;
												else
													HmiProcessStopNum=HmiProcessStartNum+1;
											}
											break;
										case 2://����ִ��
											if(HmiProcessStopNum>=HmiProcessStartNum)
											{
												if(HmiProcessStartNum==1)
													HmiProcessStopNum=HmiProcessStartNum;
												else
													HmiProcessStopNum=HmiProcessStartNum-1;
											}
											break;
										case 3://ѭ��ִ��
											if(HmiProcessStopNum==0)
											{
													HmiProcessStopNum=1;
											}
											break;
										default:break;
									}
									
									//ȷ��
									if(HmiProcessEnter==1)
									{
										HmiProcessEnter = 0;
										//���沢��������
										SetProcessData();
										
										//�˳�����ģʽ
										HmiProcessMode = 0;
									}
									//ȡ��
									else if(HmiProcessEnter==2) 
									{
										HmiProcessEnter = 0;

										//�˳����ģʽ
										HmiProcessMode = 0;
									}
									osdelay_ms(10);
								}
							}									
							//ɾ������
							if(HmiProcessMode==5)
							{
								DeleteProcessData();
								//�˳�ɾ��ģʽ
								HmiProcessMode = 0;
							}
							osdelay_ms(10);
						}
				}
			break;
			//ȡ������
			case QuXiaoRenWuJieMian: 
			{		
				while(JieMianHao==QuXiaoRenWuJieMian)
				{
					if(QuXiaoRenWuQueDing==1)
					{
						QuXiaoRenWuQueDing = 0;
						All_flag.quxiaorenwu_flag = 1;
						HmiTask = 0;
						HmiTaskState = 0;
						//ͣ��
						All_flag.stopAsk = 1;
						dir = 0;
						All_flag.speek_flag = 0;
						All_flag.speek1_flag = 0;
						All_flag.speek3_flag = 0;
						//ɾ������
						OSTaskDel((OS_TCB*)&Task5_TaskTCB,&err);
						//���´�������
						OSTaskCreate((OS_TCB 	* )&Task5_TaskTCB,		
						(CPU_CHAR	* )"Task5 task", 		
									 (OS_TASK_PTR )Task5_task, 			
									 (void		* )0,					
									 (OS_PRIO	  )Task5_TASK_PRIO,     	
									 (CPU_STK   * )&Task5_TASK_STK[0],	
									 (CPU_STK_SIZE)Task5_STK_SIZE/10,	
									 (CPU_STK_SIZE)Task5_STK_SIZE,		
									 (OS_MSG_QTY  )0,					
									 (OS_TICK	  )0,					
									 (void   	* )0,				
									 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR, 
									 (OS_ERR 	* )&err);
					}
					osdelay_ms(10);
				}							
			}
			break;
			case LiuChengSheZhiJieMian: 
				{		
					//���·����Ϊ�㣬����һ
					if(HmiProcessNum==0)
					{
						HmiProcessNum = 1;
					}
				}
			break;
			case LuJingSheZhiJieMian: 
				{		
					//���·����Ϊ�㣬����һ
					if(HmiRouteNum==0)
					{
						HmiRouteNum = 1;
					}
				}
			break;
			//ִ��·��
			case ZhiXingLuJingJieMian:
				{		
					while(JieMianHao==ZhiXingLuJingJieMian)
					{
						if(ZhiXingLuJingQueDing==1)
						{
							//����·����
							SetOneParameterToSystem(HmiRouteNum,6);
							HmiTask = 1;
							SystemParameter[8] = HmiTask;
							//���������
							SetOneParameterToSystem(HmiTask,8);
							ZhiXingLuJingQueDing = 0;
							
							//�Զ�������ʾ��Ϣ����
							HmiAutoReload();
						}
						osdelay_ms(10);
					}
				}
			break;
			//ִ������
			case ZhiXingLiuChengJieMian: 
			{		
				while(JieMianHao==ZhiXingLiuChengJieMian)
				{
					if(ZhiXingLiuChengQueDing==1)
					{
						//�������̺�
						SetOneParameterToSystem(HmiProcessNum,7);
						HmiTask = 2;
						SystemParameter[8] = HmiTask;
						//���������
						SetOneParameterToSystem(HmiTask,8);
						ZhiXingLiuChengQueDing = 0;
						
						//����״̬Ϊ��������
						HmiTaskState = 5;
						
						//�Զ�������ʾ��Ϣ����
						HmiAutoReload();
					}
					osdelay_ms(10);
				}							
			}
			break;				
            default :
            break ;
        }
        delay(0,0,0,10);
    }
}
//�Զ�ִ��·��������
void Task5_task(void *p_arg)
{	
	p_arg = p_arg;

	while(1)
	{
		delay(0,0,0,5);
	}
}

//���Զ�ģʽ���ϴ���
void Control_task(void *p_arg)
{
	while(1)
	{
		ld_juli = QianHouJuLi;//ǰ�󵹳��״��������
		Manual_juli = QianHouJuLi;
		if(All_flag.flag_szd==0)//�Զ�
		{
			if(Jhwai_switch&&(All_flag.flag_qd==1))
			{				
				if(dir==0)//������
				{
					if(((QianZuoLeiDa<=ld_juli)||(QianYouLeiDa<=ld_juli)))
					{
						All_flag.speek_flag = 1;
						HmiTaskState = 2;
						MotoStop(5);
					}
					else if(((QianZuoLeiDa>ld_juli)&&(QianYouLeiDa>ld_juli)))
					{						
						All_flag.speek_flag = 0;
						HmiTaskState = 5;
						delay(0,0,1,0);
						All_flag.startAsk = 1;		
					}
				}
				else if(dir == 1)//����
				{
					if(((HouZuoLeiDa<=ld_juli)||(HouYouLeiDa<=ld_juli)))
					{
						All_flag.speek_flag = 1;						
						HmiTaskState = 2;
						MotoStop(5);
					}
					else if(((HouZuoLeiDa>ld_juli)&&(HouYouLeiDa>ld_juli)))
					{					
						All_flag.speek_flag = 0;
						HmiTaskState = 5;
						delay(0,0,1,0);
						All_flag.startAsk = 1;					
					}
				}
				else if(dir == 2)//����
				{
					if(((ZuoQianLeiDa<=ld_juli)||(ZuoHouLeiDa<=ld_juli)))
					{
						All_flag.speek_flag = 1;						
						HmiTaskState = 2;
						MotoStop(5);
					}
					else if(((ZuoQianLeiDa>ld_juli)&&(ZuoHouLeiDa>ld_juli)))
					{
						All_flag.speek_flag = 0;						
						HmiTaskState = 5;
						delay(0,0,1,0);
						All_flag.startAsk = 1;				
					}
				}
				else if(dir == 3)//����
				{
					if(((YouQianLeiDa<=ld_juli)||(YouHouLeiDa<=ld_juli)))
					{
						All_flag.speek_flag = 1;						
						HmiTaskState = 2;
						MotoStop(5);
					}
					else if(((YouQianLeiDa>ld_juli)&&(YouHouLeiDa>ld_juli)))
					{						
						All_flag.speek_flag = 0;
						HmiTaskState = 5;
						delay(0,0,1,0);
						All_flag.startAsk = 1;					
					}
				}
				else if(dir == 4)//����
				{
					if(((YouHouLeiDa<=ld_juli)||(ZuoQianLeiDa<=ld_juli)))
					{
						All_flag.speek_flag = 1;						
						HmiTaskState = 2;
						MotoStop(5);
					}
					else if(((YouHouLeiDa>ld_juli)&&(ZuoQianLeiDa>ld_juli)))
					{					
						All_flag.speek_flag = 0;
						HmiTaskState = 5;
						delay(0,0,1,0);
						All_flag.startAsk = 1;					
					}
				}
				else if(dir == 5)//����
				{
					if(((YouQianLeiDa<=ld_juli)||(ZuoHouLeiDa<=ld_juli)))
					{
						All_flag.speek_flag = 1;						
						HmiTaskState = 2;
						MotoStop(5);
					}
					else if(((YouQianLeiDa>ld_juli)&&(ZuoHouLeiDa>ld_juli)))
					{					
						All_flag.speek_flag = 0;
						HmiTaskState = 5;
						delay(0,0,1,0);
						All_flag.startAsk = 1;					
					}
				}				
			}			
		}
		else
		{
			if(SouDongBiZhang)
			{
				while(QianJin==0)
				{
					if((QianZuoLeiDa<Manual_juli)||(QianYouLeiDa<Manual_juli)||(QfangZ==0))
					{
						All_flag.speek_flag = 1;					
						MotoStop(5);							
					}
					else if((QianZuoLeiDa>Manual_juli)&&(QianYouLeiDa>Manual_juli)&&(QfangZ==1))
					{
						All_flag.speek_flag = 0;
					}
					delay(0,0,0,5);				
				}			
				
				while(HouTui==0)//����
				{
					if((HouZuoLeiDa<Manual_juli)||(HouYouLeiDa<Manual_juli)||(HfangZ==0))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);										
					}	
					else if((HouZuoLeiDa>Manual_juli)&&(HouYouLeiDa>Manual_juli)&&(HfangZ==1))
					{
						All_flag.speek_flag = 0;
					}	
					delay(0,0,0,5);				
				}			
				while(ZuoYi==0)//����
				{
					if(((ZuoQianLeiDa<Manual_juli)||(ZuoHouLeiDa<Manual_juli)))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);
					
					}	
					else if(((ZuoQianLeiDa>Manual_juli)&&(ZuoHouLeiDa>Manual_juli)))
					{
						All_flag.speek_flag = 0;
					}
					delay(0,0,0,5);				
				}
				while(YouYI==0)//����
				{
					if(((YouQianLeiDa<Manual_juli)||(YouHouLeiDa<Manual_juli)))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);
						
					}	
					else if(((YouQianLeiDa>Manual_juli)&&(YouHouLeiDa>Manual_juli)))
					{
						All_flag.speek_flag = 0;
					}
					delay(0,0,0,5);				
				}
				while(ZuoXuan==0)//����
				{
					if(( (ZuoQianLeiDa<Manual_juli)||(YouHouLeiDa<Manual_juli)))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);
						
					}
					else if(((YouHouLeiDa>Manual_juli)&&(ZuoQianLeiDa>Manual_juli)))
					{
						All_flag.speek_flag = 0;
					}
					delay(0,0,0,5);				
				}
				while(YouXuan==0)//����
				{
					if(((YouQianLeiDa<Manual_juli)||(ZuoHouLeiDa<Manual_juli) ))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);
						
					}	
					else if(((YouQianLeiDa>Manual_juli)&&(ZuoHouLeiDa>Manual_juli)))
					{
						All_flag.speek_flag = 0;
					}
					delay(0,0,0,5);				
				}
				while(ZuoShang==0)//����
				{
					if(((QianZuoLeiDa<Manual_juli)||(QianYouLeiDa<Manual_juli)||(ZuoQianLeiDa<Manual_juli)||(ZuoHouLeiDa<Manual_juli)))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);
						
					}
					else if(((QianZuoLeiDa>Manual_juli)&&(QianYouLeiDa>Manual_juli)&&(ZuoQianLeiDa>Manual_juli)&&(ZuoHouLeiDa>Manual_juli)))
					{
						All_flag.speek_flag = 0;
					}	
					delay(0,0,0,5);				
				}
				while(ZuoXia==0)//����
				{
					if(((HouZuoLeiDa<Manual_juli)||(HouYouLeiDa<Manual_juli)||(ZuoQianLeiDa<Manual_juli)||(ZuoHouLeiDa<Manual_juli)))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);
						
					}	
					else if(((HouZuoLeiDa>Manual_juli)&&(HouYouLeiDa>Manual_juli)&&(ZuoQianLeiDa>Manual_juli)&&(ZuoHouLeiDa>Manual_juli)))
					{
						All_flag.speek_flag = 0;
					}	
					delay(0,0,0,5);				
				}
				while(YouShang==0)//����
				{
					if(((QianZuoLeiDa<Manual_juli)||(QianYouLeiDa<Manual_juli)||(YouQianLeiDa<Manual_juli)||(YouHouLeiDa<Manual_juli)))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);
						
					}
					else if(((QianZuoLeiDa>Manual_juli)&&(QianYouLeiDa>Manual_juli)&&(YouQianLeiDa>Manual_juli)&&(YouHouLeiDa>Manual_juli)))
					{
						All_flag.speek_flag = 0;
					}	
					delay(0,0,0,5);				
				}
				while(YouXia==0)//����
				{
					if(((HouZuoLeiDa<Manual_juli)||(HouYouLeiDa<Manual_juli)||(YouQianLeiDa<Manual_juli)||(YouHouLeiDa<Manual_juli)))
					{
						All_flag.speek_flag = 1;						
						MotoStop(5);
						
					}
					else if(((HouZuoLeiDa>Manual_juli)&&(HouYouLeiDa>Manual_juli)&&(YouQianLeiDa>Manual_juli)&&(YouHouLeiDa>Manual_juli)))
					{
						All_flag.speek_flag = 0;
					}	
					delay(0,0,0,5);				
				}
				All_flag.speek_flag = 0;
			}			
		}			
		delay(0,0,0,5);
	}
}
//��������
void WIFI_task(void *p_arg)
{	
	while(1)
	{	
		delay(0,0,0,5);
	}
	
}
//�ж�ƽ�ƻ���ת�Ƿ�λ��λ
void DEMO_task(void *p_arg)
{
	while(1)
	{		
		delay(0,0,0,5);   
	}
}

//����
void DEMO1_task(void *p_arg)
{
	while(1)
	{	
		TLC5620_OUTnum(1,125);
		delay(0,0,0,200);      
	}
}
//ֹͣ
void DEMO2_task(void *p_arg)
{
	u16 num=0;
	while(1)
	{
		num++;
		if(num==40)
		{
			num=0;
			IWDG_Feed();//ι��
		}
		delay(0,0,0,5);      
	}
}

