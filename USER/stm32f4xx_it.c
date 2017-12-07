/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    04-August-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sys.h"
/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}
void  DMA1_Stream3_IRQHandler(void)//����3����DMA�ж�
{
    if(DMA_GetITStatus(DMA1_Stream3, DMA_IT_TCIF3))
    {
		DMA_ClearITPendingBit(DMA1_Stream3, DMA_IT_TCIF3);
		DMA_Cmd(DMA1_Stream3, DISABLE);
    }
}
void  DMA1_Stream6_IRQHandler(void)//����2����DMA�ж�
{
    if(DMA_GetITStatus(DMA1_Stream6, DMA_IT_TCIF6))
    {
		DMA_ClearITPendingBit(DMA1_Stream6, DMA_IT_TCIF6);
		DMA_Cmd(DMA1_Stream6, DISABLE);
    }
}
void  DMA1_Stream4_IRQHandler(void)//����4DMA�����ж�
{
    if(DMA_GetITStatus(DMA1_Stream4, DMA_IT_TCIF4))
    {
		USART_ITConfig(UART4, USART_IT_TC, ENABLE);//��������ʱ�����봮��4DMA�жϣ��򿪴���4�����ж�

		DMA_ClearITPendingBit(DMA1_Stream4, DMA_IT_TCIF4);
		DMA_Cmd(DMA1_Stream4, DISABLE);
    }
}
void  DMA2_Stream0_IRQHandler(void)//AD DMA�ж�
{
	long  sum = 0;
	u8 count,i;
	if(DMA_GetITStatus(DMA2_Stream0,DMA_IT_TCIF0) != RESET)
	{

	   for(i=0;i<3;i++)
	   {
			for ( count=0;count<30;count++)
			{
			sum += AD_Value[count][i];
			}
			After_filter[i]=sum/30;
			sum=0;
	   }

	  DMA_ClearITPendingBit(DMA2_Stream0,DMA_IT_TCIF0);
	}
}
void  DMA2_Stream7_IRQHandler(void)//����6����DMA�ж�
{
    if(DMA_GetITStatus(DMA2_Stream7, DMA_IT_TCIF7))
    {
		DMA_ClearITPendingBit(DMA2_Stream7, DMA_IT_TCIF7);
		DMA_Cmd(DMA2_Stream7, DISABLE);
		send_ok = 1;
    }
}
void USART2_IRQHandler(void)             
{
	char *p;
	char dst[4]={0,0,0,0};
	char *l="$";
    u8 i=0;	
#if SYSTEM_SUPPORT_OS 	
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET) 
	{
		DMA_Cmd(DMA1_Stream5,DISABLE);
		rece2_index = USART2->SR;
		rece2_index = USART2->DR; //���IDLE��־
		rece2_index = UART_RX_LEN - DMA_GetCurrDataCounter(DMA1_Stream5); 
		DMA1_Stream5->NDTR = UART_RX_LEN;
		//�����ر�
		//rece_buf
		if(rece2_index>0)
		{
			p=strstr(rece2_buf,l);
			if(p)
			{
				dst[0]=p[15];
				dst[1]=p[16];
				dst[2]=p[17];
				for(i=0;i<rece2_index;i++)
				rece2_buf[i]=0;
				rece2_index=0;
				keynumber=(dst[0]-0x30)*100+(dst[1]-0x30)*10+(dst[2]-0x30);
				PLC_Data[1]=keynumber;
				All_flag.beep_flag=1;
			}
		} 
		DMA_Cmd(DMA1_Stream5, ENABLE);
	}
#if SYSTEM_SUPPORT_OS 	
	OSIntExit();  											 
#endif
} 
void USART3_IRQHandler(void)             
{

#if SYSTEM_SUPPORT_OS 	
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART3, USART_IT_IDLE) != RESET) 
	{
		DMA_Cmd(DMA1_Stream1,DISABLE);
		rece3_index = USART3->SR;
		rece3_index = USART3->DR; //���IDLE��־
		rece3_index = UART_RX_LEN - DMA_GetCurrDataCounter(DMA1_Stream1); 
		DMA1_Stream1->NDTR = UART3_RX_LEN;
		
		if(YaoKong.YaoKong_OR_KongZhiHe == 0)
		{
			send3_buf[0] = 1;//ң������Чָʾ
			send3_buf[1] = 1;
			send3_buf[2] = 2;
			Uart3_Start_DMA_Tx(3);
		}
		else
		{
			send3_buf[0] = 1;//ң������Чָʾ
			send3_buf[1] = 2;
			send3_buf[2] = 3;
			Uart3_Start_DMA_Tx(3);				
		}
		YaoKong.DongZuo = rece3_buf[0];
		YaoKong.SuDu = rece3_buf[1];
		YaoKong.XingZou_OR_ShengJiang = rece3_buf[2]&0x01;
		YaoKong.ZhiXing_OR_XieXing = rece3_buf[2]&0x02;
		YaoKong.XiaJiang = rece3_buf[2]&0x04;
		YaoKong.JiTing = rece3_buf[2]&0x08;
		YaoKong.KuaiSu_OR_ManSu = rece3_buf[2]&0x10;
		YaoKong.QiSheng = rece3_buf[2]&0x20;
		YaoKong.YaoGan_Key = rece3_buf[2]&0x40;
		YaoKong.KaiGuanLiang = rece3_buf[2];
		FangXiang = ~FangXiang;	

		DMA_Cmd(DMA1_Stream1, ENABLE);
	}
#if SYSTEM_SUPPORT_OS 	
	OSIntExit();  											 
#endif
}
void UART4_IRQHandler(void)                
{
#if SYSTEM_SUPPORT_OS 	
	OSIntEnter();    
#endif
	if(USART_GetITStatus(UART4, USART_IT_IDLE) != RESET) 
	{
		DMA_Cmd(DMA1_Stream2,DISABLE);
        rece_index = UART4->SR; 
        rece_index = UART4->DR; 
        rece_index = UART_RX_LEN - DMA_GetCurrDataCounter(DMA1_Stream2); 
        DMA1_Stream2->NDTR = UART_RX_LEN;
		if(rece_index>0)
		{
			if(receBuf[0]==0x01||receBuf[0]==0x00)
			{
				AnalyzeRecieve();
				if(receBuf[0]==0x01)
				send_comm();
			}
		} 		
        DMA_Cmd(DMA1_Stream2, ENABLE);
	} 
	if(USART_GetITStatus(UART4, USART_IT_TC)!= RESET)//���������ʱ���봮��4�жϣ��ı�485���ͽ��շ���
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);//�ı�485Ϊ����
		NVIC_ClearPendingIRQ(UART4_IRQn);//����жϱ�־
		USART_ClearITPendingBit(UART4,USART_IT_TC);//�������4������ɱ�־��־
	}
#if SYSTEM_SUPPORT_OS 	
	OSIntExit();  											 
#endif
} 
void USART6_IRQHandler(void)             
{
#if SYSTEM_SUPPORT_OS 	
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART6, USART_IT_IDLE) != RESET) 
	{
		DMA_Cmd(DMA2_Stream1,DISABLE);
		rece6_index = USART6->SR;
		rece6_index = USART6->DR; //���IDLE��־
		rece6_index = UART6_RX_LEN - DMA_GetCurrDataCounter(DMA2_Stream1); 
		DMA2_Stream1->NDTR = UART6_RX_LEN;
		receive_ok = 1;
//		DMA_Cmd(DMA2_Stream1, ENABLE);
	} 
#if SYSTEM_SUPPORT_OS 	
	OSIntExit();  											 
#endif
} 
/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
//void PendSV_Handler(void)
//{
//}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
//void SysTick_Handler(void)
//{
// 
//}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
