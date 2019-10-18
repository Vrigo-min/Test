#include "user_code.h"


/************************************************************************/
/* ��ֲ�������ʱע��ĵط���
��̨Pitch���е�Ƕ���λд������Ҫ���ݲ���ֵ�޸�
��̨���л�е�Ƕ�д������Ҫ���ݲ���ֵ�޸ġ�


*/
/************************************************************************/
void Init(void) {
	//��ʼ��������˳�ʼ��״̬
	Devices_init();    //������BSP���ʼ��
	
	CAN2_QuickInit();
	delay_ms(2000);

	M2006s_Init();

	WolfOnline_init(115200);
	TIM6_CounterMode(89, 9999);//����תʱ��
  
	
}

//����BSP��Ӳ��GPIO�ȵĳ�ʼ��
void Devices_init(void)
{
	DR16_RemoteInit();
	WolfOnline_init(115200);//usart2

	USART2_QuickInit(115200);   //����2--DR16ң����
	USART6_QuickInit(115200);   //����6--��λ��
	USART6_RXDMA_Config((uint32_t)ANO_rxBuff, ANO_PACKSIZE);

}

void Test(void) {
	if (WolfOnline_Data.RunDigitalScreen == 1)
	{
		delay_ms(50);
//		Debug_ANOSendData_V3(M2006s[2].targetSpeed, M2006s[2].realSpeed,0,0);

	}
		
}


