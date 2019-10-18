#include "user_code.h"


/************************************************************************/
/* 移植代码测试时注意的地方：
云台Pitch轴机械角度限位写死，需要根据测试值修改
云台回中机械角度写死，需要根据测试值修改。


*/
/************************************************************************/
void Init(void) {
	//开始进入机器人初始化状态
	Devices_init();    //基本的BSP层初始化
	
	CAN2_QuickInit();
	delay_ms(2000);

	M2006s_Init();

	WolfOnline_init(115200);
	TIM6_CounterMode(89, 9999);//主运转时钟
  
	
}

//基础BSP，硬件GPIO等的初始化
void Devices_init(void)
{
	DR16_RemoteInit();
	WolfOnline_init(115200);//usart2

	USART2_QuickInit(115200);   //串口2--DR16遥控器
	USART6_QuickInit(115200);   //串口6--上位机
	USART6_RXDMA_Config((uint32_t)ANO_rxBuff, ANO_PACKSIZE);

}

void Test(void) {
	if (WolfOnline_Data.RunDigitalScreen == 1)
	{
		delay_ms(50);
//		Debug_ANOSendData_V3(M2006s[2].targetSpeed, M2006s[2].realSpeed,0,0);

	}
		
}


