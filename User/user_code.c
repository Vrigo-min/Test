#include "user_code.h"


/************************************************************************/
/* 移植代码测试时注意的地方：
云台Pitch轴机械角度限位写死，需要根据测试值修改
云台回中机械角度写死，需要根据测试值修改。


*/
/************************************************************************/
void Init(void) {
	
	USART2_QuickInit(115200);   //串口2--DR16遥控器
	USART6_QuickInit(115200);   //串口6--上位机
	USART6_RXDMA_Config((uint32_t)ANO_rxBuff, ANO_PACKSIZE);
	
	DR16_RemoteInit();

	CAN2_QuickInit();
	
	M2006s_Init();


	TIM6_CounterMode(89, 9999);//主运转时钟


}



void Test(void) {


		delay_ms(50);
//		Debug_ANOSendData_V3(M3508s[2].targetSpeed, M3508s[2].realSpeed,0,0);

}


