#include "sys.h"


void TLC5620_Init(void)
{    	 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOG, ENABLE);//ʹ��GPIOFʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;//DACоƬ�˿ڳ�ʼ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIO

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//DACоƬ�˿ڳ�ʼ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ��GPIO

	DADATA=1;
	DACLK =1;
	DALOAD=1;
	DALDAC=1;
} 

/******************************
*DACоƬת������
*CHn ת����ͨ����:1,2,3,4
*��ת���ĵ�ѹֵ:0~5V֮����κ���ֵ
* A0 A1 RNG   D7~D0 ��11λ
******************************/
void TLC5620_OUT(u8 CHn,double date)
{
		u8 i=0,dat=0,datt=0;
		DACLK =0;
		DADATA=0;
		DALOAD=1;
		DALDAC=0;
		delay_us(2);
		for(i=0;i<3;i++)
		{
				switch(CHn)
				{
					case 1://00 x:Aͨ��1+x������
					{
						if(i==2)
						{
							DADATA=TLC5620RNG;
						}
						else 
						{
							DADATA=0;
						}
					}break;
					case 2://01 x:Bͨ��1+x������
					{
						if(i==2)
						{
							DADATA=TLC5620RNG;
						}
						else if(i==1)
						{
							DADATA=1;
						}
						else
						{
							DADATA=0;
						}
					}break;
					case 3://10 x:Cͨ��1+x������
					{
						if(i==2)
						{
							DADATA=TLC5620RNG;
						}
						else if(i==1)
						{
							DADATA=0;
						}
						else
						{
							DADATA=1;
						}
					}break;
					case 4://11 x:Dͨ��1+x������
					{
						if(i==2)
						{
							DADATA=TLC5620RNG;
						}
						else
						{
							DADATA=1;
						}
					}break;
				}
				DACLK =1;
				delay_us(2);
				DACLK =0;
				delay_us(2);
		}	
		datt=(u8)(date*255/(3.27*2.0));//��׼��ѹΪ3.3V���Ŵ�����
		for(i=0;i<8;i++)
		{
				dat=datt&0x80;//��λ������
				if(dat)
					DADATA=1;
				else 
					DADATA=0;
				DACLK =1;
				delay_us(2);
				DACLK =0;
				delay_us(2);
				datt<<=1;
		}
		DALOAD=0;		
		delay_us(1);
		DALOAD=1;		
		delay_us(1);
}

void TLC5620_OUTnum(u8 CHn,u8 date)
{
		u8 i=0,dat=0;
		DACLK =0;
		DADATA=0;
		DALOAD=1;
		DALDAC=0;
		delay_us(2);
		for(i=0;i<3;i++)
		{
				switch(CHn)
				{
					case 1://00 x:Aͨ��1+x������
					{
						if(i==2)
						{
							DADATA=TLC5620RNG;
						}
						else 
						{
							DADATA=0;
						}
					}break;
					case 2://01 x:Bͨ��1+x������
					{
						if(i==2)
						{
							DADATA=TLC5620RNG;
						}
						else if(i==1)
						{
							DADATA=1;
						}
						else
						{
							DADATA=0;
						}
					}break;
					case 3://10 x:Cͨ��1+x������
					{
						if(i==2)
						{
							DADATA=TLC5620RNG;
						}
						else if(i==1)
						{
							DADATA=0;
						}
						else
						{
							DADATA=1;
						}
					}break;
					case 4://11 x:Dͨ��1+x������
					{
						if(i==2)
						{
							DADATA=TLC5620RNG;
						}
						else
						{
							DADATA=1;
						}
					}break;
				}
				DACLK =1;
				delay_us(2);
				DACLK =0;
				delay_us(2);
		}	
//		datt=(u8)(date*255/(3.3*2.0));//��׼��ѹΪ3.3V���Ŵ�����
		for(i=0;i<8;i++)
		{
				dat=date&0x80;//��λ������
				if(dat)
					DADATA=1;
				else 
					DADATA=0;
				DACLK =1;
				delay_us(2);
				DACLK =0;
				delay_us(2);
				date<<=1;
		}
		DALOAD=0;		
		delay_us(1);
		DALOAD=1;		
		delay_us(1);
}


