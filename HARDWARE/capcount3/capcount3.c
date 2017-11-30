#include "sys.h"

//��ʱ��3ͨ��1���벶������
//arr���Զ���װֵ(TIM2,TIM3��32λ��!!)
//psc��ʱ��Ԥ��Ƶ��
void TIM3_CH1_Cap_Init1(u32 arr,u16 psc)
{
	TIM_ICInitTypeDef  TIM3_ICInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  		//TIM3ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTAʱ��	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7; 		//GPIOA6��7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;						//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;			//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 					//���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 						//����
	GPIO_Init(GPIOA,&GPIO_InitStructure); 									//��ʼ��PA

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM3); 	//PA6����λ��ʱ��3
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM3); 	//PA7����λ��ʱ��3

	TIM_TimeBaseStructure.TIM_Period=arr;   								//�Զ���װ��ֵ  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  							//��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);


	//��ʼ��TIM3���벶�����
	TIM3_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	ѡ������� 
	TIM3_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
	TIM3_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM3_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
	TIM3_ICInitStructure.TIM_ICFilter = 0xF;//IC1F=0000 ���������˲��� ���˲�
	TIM_ICInit(TIM3, &TIM3_ICInitStructure);

	//��ʼ��TIM3���벶�����
	TIM3_ICInitStructure.TIM_Channel = TIM_Channel_2; //CC1S=01 	ѡ������� 
	TIM3_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
	TIM3_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM3_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
	TIM3_ICInitStructure.TIM_ICFilter = 0xF;//IC1F=0000 ���������˲��� ���˲�
	TIM_ICInit(TIM3, &TIM3_ICInitStructure);


	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����

	TIM_ITConfig(TIM3,TIM_IT_CC1|TIM_IT_CC2,ENABLE);//����CC1IE�����ж�	

	TIM_Cmd(TIM3,ENABLE ); 	//ʹ�ܶ�ʱ��3
	
}

u32	count31=0,count32=0;	//���벶��ֵ
//��ʱ��3�жϷ������	 
void TIM3_IRQHandler(void)
{ 
	if (TIM_GetITStatus(TIM3, TIM_IT_CC1) != RESET) //����1���������¼�
	{	
		count31++;											//ÿ����ɹ�һ�ξͼ�����1
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC1); 		//����жϱ�־λ
	}	
	if (TIM_GetITStatus(TIM3, TIM_IT_CC2) != RESET) //����2���������¼�
	{	
		count32++;											//ÿ����ɹ�һ�ξͼ�����1
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC2); 		//����жϱ�־λ
	}			
}

