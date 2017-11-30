#include "sys.h"


//�������ĵ������������������ҵ�CDH_read_dataa�������ܣ�
Fencha_struct front_cdh16,back_cdh16,backl_cdh8,backr_cdh8;//����һ��Fencha_struct���͵�ȫ�ֱ���
Fencha_struct findtemp={0,0,0,0,0,0};//�����������еĽṹ�����鶨��

//16λ�ŵ������ݴ�����

//dst:�ŵ�����ԭʼ16���Ƶ�16λ��
//num:����ʱ�����������������1~15��
//dir:�ֲ淽��1����ֲ棬2���ҷֲ�
//����ֵ��Fencha_struct�ṹ��

Fencha_struct FindSpace(u16 dst,u8 num,u8 dir)
{
	u16 i=0,dirr=dir;
	u16 p=~dst,numr=0,numl=0;
	Fencha_struct find;
	AA:	
	find.zeroNum = 0;
	find.zeroContinue = 0;
	find.Num = 0;
	find.Distance = 0;
	find.Error = 0;
	//������Ч��ĸ���
	for(i=0;i<16;i++)
	{
		if((p>>i)&0x0001)
		{
			find.Num++;
		}
	}
	//�ж��ұ�0�ĸ���
	for(i=0;i<16;i++)
	{
		if(((p>>i)&0x0001)==0)
		{
			numr++;
		}
		else
		{
			i=16;//ֱ���˳�
		}
	}
	
	//�ж����0�ĸ���
	for(i=0;i<16;i++)
	{
		if(((p<<i)&0x8000)==0)
		{
			numl++;
		}
		else
		{
			i=16;//ֱ���˳�
		}
	}		
	//����0�ĸ�����������0���ֵ�λ��
	for(i=numr;i<(16-numl);i++)
	{
		if(((p>>i)&0x0001)==0)
		{
			find.zeroLoctaion[find.zeroNum]=i;
			find.zeroNum++;
		}
	}
		
	//�ж϶ϵ��Ƿ�����
	if(find.zeroNum>0)
	{
		find.zeroContinue = 1;
		if(find.zeroNum>1)
		{
			for(i = 0;i<(find.zeroNum-1);i++)
			{
				if(find.zeroLoctaion[i+1]-find.zeroLoctaion[i]==1)
				{
					continue;
				}
				else
				{
					find.zeroContinue++;
				}
			}
		}
	}
	//������Ч���������λ�õľ���
	if(find.Num==0)//û�ҵ���Ч�㣬���뷵��0
	{
		find.Distance = 16;
		find.Error = 1;		
	}

	else
	{
		if(find.zeroNum>0)//�жϵ㣬����0
		{
			if(find.zeroContinue==1)//һ���ֲ�
			{
				if(dirr==2)//�ҷֲ�
				{
					for(i=numr;i<16;i++)
					{
						if((p>>i)&0x0001)
						{
							p = p&(~(0x0001<<i));
						}
						else
						{
							i = 16;
						}
					}
					goto AA;
				}
				else if(dirr==1)//��ֲ�
				{
					for(i=numl;i<16;i++)
					{
						if((p<<i)&0x8000)
						{
							p = p&(~(0x8000>>i));
						}
						else
						{
							i = 16;
						}
					}
					goto AA;
				}
				else
				{
					find.Error = 1;
				}
			}
			
		}
		else//�������
		{
			if(find.Num<=num)
			{				
				find.Distance = numl - numr ;
			}
			else
			{
				find.Error = 1;
			}
		}
	}
	
	findtemp = find;
	return find;

}
//8λ�ŵ������ݴ�����
//dst:�ŵ�����ԭʼ16���Ƶ�8λ��
//num:����ʱ�����������������1~7��
//dir:�ֲ淽��1����ֲ棬2���ҷֲ�
//����ֵ��Fencha_struct�ṹ��

Fencha_struct FindSpace1(u8 dst,u8 num,u8 dir)
{
	u8 i=0,dirr=dir;
	u8 p=~dst,numr=0,numl=0;
	Fencha_struct find;
	AA:	
	find.zeroNum = 0;
	find.zeroContinue = 0;
	find.Num = 0;
	find.Distance = 0;
	find.Error = 0;
	//������Ч��ĸ���
	for(i=0;i<8;i++)
	{
		if((p>>i)&0x01)
		{
			find.Num++;
		}
	}
	//�ж��ұ�0�ĸ���
	for(i=0;i<8;i++)
	{
		if(((p>>i)&0x01)==0)
		{
			numr++;
		}
		else
		{
			i=8;//ֱ���˳�
		}
	}
	
	//�ж����0�ĸ���
	for(i=0;i<8;i++)
	{
		if(((p<<i)&0x80)==0)
		{
			numl++;
		}
		else
		{
			i=8;//ֱ���˳�
		}
	}		
	//����0�ĸ�����������0���ֵ�λ��
	for(i=numr;i<(8-numl);i++)
	{
		if(((p>>i)&0x01)==0)
		{
			find.zeroLoctaion[find.zeroNum]=i;
			find.zeroNum++;
		}
	}
		
	//�ж϶ϵ��Ƿ�����
	if(find.zeroNum>0)
	{
		find.zeroContinue = 1;
		if(find.zeroNum>1)
		{
			for(i = 0;i<(find.zeroNum-1);i++)
			{
				if(find.zeroLoctaion[i+1]-find.zeroLoctaion[i]==1)
				{
					continue;
				}
				else
				{
					find.zeroContinue++;
				}
			}
		}
	}
	//������Ч���������λ�õľ���
	if(find.Num==0)//û�ҵ���Ч�㣬���뷵��0
		find.Error = 1;
	else
	{
//		if((findtemp.zeroNum==0)&&(find.zeroNum>4)&&(findtemp.Num>0))
//		{
//				if(find.zeroLoctaion[find.zeroNum/2]>=9)
//					dirr = 2;
//				else
//					dirr = 1;
//		}
		if(find.zeroNum>0)//�жϵ㣬����0
		{
			if(find.zeroContinue==1)//һ���ֲ�
			{
				if(dirr==2)//�ҷֲ�
				{
					for(i=numr;i<8;i++)
					{
						if((p>>i)&0x01)
						{
							p = p&(~(0x01<<i));
						}
						else
						{
							i = 8;
						}
					}
					goto AA;
				}
				else if(dirr==1)//��ֲ�
				{
					for(i=numl;i<8;i++)
					{
						if((p<<i)&0x80)
						{
							p = p&(~(0x80>>i));
						}
						else
						{
							i = 8;
						}
					}
					goto AA;
				}
				else
				{
					find.Error = 1;
				}
			}
			
		}
		else//�������
		{
			if(find.Num<=num)
			{
				find.Distance = numl - numr + 8;
			}
			else
			{
				find.Error = 1;
			}
		}
	}
	
	findtemp = find;
	return find;

}

