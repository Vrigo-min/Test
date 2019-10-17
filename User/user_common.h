#ifndef __USER_COMMON_H
#define __USER_COMMON_H

#define UsePid  0      //增量式
#define UsePID  1      //位置环

#include "stdio.h"
#include <stdbool.h>
#include <Math.h>
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "typedef.h"


//Algorithm
#include "PID.h"

//BSP层
#include "delay.h"
#include "NVIC.h"
#include "USART.h"
#include "TIM.h"
#include "CAN.h"

//Devices
#include "DR16_Remote.h"
#include "M2006_Motor.h"
#include "Debug_ANO.h"

//APPs



#endif


