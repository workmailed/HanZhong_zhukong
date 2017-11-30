#include "sys.h"

//��ʱ��3ͨ��1���벶������
//arr���Զ���װֵ(TIM2,TIM9��32λ��!!)
//psc��ʱ��Ԥ��Ƶ��
void TIM9_CH1_Cap_Init1(u32 arr,u16 psc)
{
	TIM_ICInitTypeDef  TIM9_ICInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9,ENABLE);  		//TIM9ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//ʹ��PORTAʱ��	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6; 		//GPIOE6��7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;						//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;			//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 					//���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 						//����
	GPIO_Init(GPIOE,&GPIO_InitStructure); 									//��ʼ��PA

	GPIO_PinAFConfig(GPIOE,GPIO_PinSource5,GPIO_AF_TIM9); 	//PA6����λ��ʱ��3
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource6,GPIO_AF_TIM9); 	//PA7����λ��ʱ��3

	TIM_TimeBaseStructure.TIM_Period=arr;   								//�Զ���װ��ֵ  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  							//��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM9,&TIM_TimeBaseStructure);


	//��ʼ��TIM9���벶�����
	TIM9_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	ѡ������� 
	TIM9_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Falling;	//�����ز���
	TIM9_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM9_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
	TIM9_ICInitStructure.TIM_ICFilter = 0xF;//IC1F=0000 ���������˲��� ���˲�
	TIM_ICInit(TIM9, &TIM9_ICInitStructure);

	//��ʼ��TIM9���벶�����
	TIM9_ICInitStructure.TIM_Channel = TIM_Channel_2; //CC1S=01 	ѡ������� 
	TIM9_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
	TIM9_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM9_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
	TIM9_ICInitStructure.TIM_ICFilter = 0xF;//IC1F=0000 ���������˲��� ���˲�
	TIM_ICInit(TIM9, &TIM9_ICInitStructure);


	NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_TIM9_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����

	TIM_ITConfig(TIM9,TIM_IT_CC1|TIM_IT_CC2,ENABLE);//����CC1IE�����ж�	

	TIM_Cmd(TIM9,ENABLE ); 	//ʹ�ܶ�ʱ��9
	
}

u32	count91=0,count92=0;	//���벶��ֵ
//��ʱ��3�жϷ������	 
void TIM1_BRK_TIM9_IRQHandler(void)
{ 
	if (TIM_GetITStatus(TIM9, TIM_IT_CC1) != RESET) //����1���������¼�
	{	
		count91++;											//ÿ����ɹ�һ�ξͼ�����1
		TIM_ClearITPendingBit(TIM9, TIM_IT_CC1); 		//����жϱ�־λ
	}	
	if (TIM_GetITStatus(TIM9, TIM_IT_CC2) != RESET) //����1���������¼�
	{	
		count92++;											//ÿ����ɹ�һ�ξͼ�����1
		TIM_ClearITPendingBit(TIM9, TIM_IT_CC2); 		//����жϱ�־λ
	}			
}

