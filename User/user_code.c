#include "user_code.h"


/************************************************************************/
/* ��ֲ�������ʱע��ĵط���
��̨Pitch���е�Ƕ���λд������Ҫ���ݲ���ֵ�޸�
��̨���л�е�Ƕ�д������Ҫ���ݲ���ֵ�޸ġ�


*/
/************************************************************************/
void Init(void) {
	
	USART2_QuickInit(115200);   //����2--DR16ң����
	USART6_QuickInit(115200);   //����6--��λ��
	USART6_RXDMA_Config((uint32_t)ANO_rxBuff, ANO_PACKSIZE);
	
	DR16_RemoteInit();

	CAN2_QuickInit();
	
	M2006s_Init();


	TIM6_CounterMode(89, 9999);//����תʱ��


}



void Test(void) {


		delay_ms(50);
//		Debug_ANOSendData_V3(M3508s[2].targetSpeed, M3508s[2].realSpeed,0,0);

}


