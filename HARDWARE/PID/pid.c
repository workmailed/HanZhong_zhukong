#include "sys.h"
struct Agv_Pid PID;
/***********************************************/
//PID������ʼ��
/***********************************************/
void PID_Init(void)
{
	PID.SetTarget = 0;
	PID.SumError = 0;
	PID.Error = 0;
	PID.LastError = 0;
	PID.PrevError = 0;
	PID.Kp = 1.2;
	PID.Ki = 1;
	PID.Kd = 0;
}
/******************************************************/
//λ��ʽPID����
//��ʽ:U(k) = Kp*[E(n)] + Ki*SumError + Kd*[E(n)-E(n-1)]
//����˵��:Error = E(n) 
/*******************************************************/
float PosPIDCalc(int NextTarget)
{
	float Error1;
	float Out;
//	PID.Error = PID.SetTarget - NextTarget;			//E(n)��ǰƫ��E(n)	
	PID.Error = NextTarget;
	PID.SumError +=PID.Error;							//SumError����

	Error1 = PID.Error - PID.LastError;					//[E(n)-E(n-1)]΢��

	PID.LastError = PID.Error;						//����ƫ��ֵ

	Out = PID.Kp*PID.Error + PID.Ki*PID.SumError + PID.Kd*Error1;	
	return(Out);
}

/***********************************************/
//����ʽPID����
//��ʽ:U(k+1)- u(K)=Kp*(E(n)-E(n-1)) + Ki*E(n) + Kd*(E(n)-2E(n-1)+E(n-2))
//����˵��:Error = E(n) ������ʵ�ʵ�ƫ����
/***********************************************/
float IncPIDCalc(int error)
{
	float Uk1;
	PID.Error = error;		//E(n)
	Uk1 = PID.Kp*(PID.Error - PID.LastError) + PID.Ki*PID.Error + PID.Kd*(PID.Error - 2*PID.LastError+PID.PrevError);
	PID.PrevError = PID.LastError;			//�������ֵ
	PID.LastError = PID.Error;	
	return(Uk1);
}
