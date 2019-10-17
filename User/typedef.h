#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H

#include <stdint.h>

#pragma anon_unions

/* 陀螺仪 */
typedef struct {
		float x;                 //浮点数pitch轴的方向向量
		float y;                 //浮点数Y轴方向向量
		float z;                 //浮点数yaw轴的转动速度
}Vector_t;

typedef struct {
	float Roll;                 //ROLL轴方向，当前的角度值
	float Pitch;                //PITCH轴方向
	float Yaw;                  //YAW轴方向
}Eular_t;




/* PID参数 */
typedef struct{
	float Target; 			        //设定目标值
	float Measured; 				    //测量值
	float err; 						      //本次偏差值
	float err_last; 				    //上一次偏差
	float err_beforeLast; 			//上上次偏差
	float Kp, Ki, Kd;				    //Kp, Ki, Kd控制系数
	float pwm; 						      //pwm输出
	uint32_t MaxOutput;				  //输出限幅
  uint32_t IntegralLimit;			//积分限幅 
}incrementalpid_t;

typedef struct{
	float Target; 					    //设定目标值
	float Measured; 				    //测量值
	float err; 						      //本次偏差值
	float err_last; 				    //上一次偏差
	float integral_err; 			  //所有偏差之和
	float Kp, Ki, Kd;				    //Kp, Ki, Kd控制系数
	float pwm; 						      //pwm输出
	uint32_t MaxOutput;				  //输出限幅
  uint32_t IntegralLimit;			//积分限幅 
}positionpid_t;

typedef struct {
	uint16_t realAngle;			//读回来的机械角度
	int16_t realSpeed;			//读回来的速度
	int16_t realCurrent;			//读回来的实际转矩电流
	int16_t targetSpeed;			//目标速度
	int32_t targetAngle;			//目标角度
	uint16_t lastAngle;			//上次的角度
	int32_t  totalAngle;			//累积总共角度
	int16_t  turnCount;			//转过的圈数
	uint8_t  temperture;        //读回来的电机温度

	positionpid_t Po_angle_pid;
	positionpid_t Po_speed_pid;
	incrementalpid_t In_speed_pid;
	incrementalpid_t In_angle_pid;

	int16_t  In_outCurrent;         //输出电流
	int16_t  In_PIDCurrent;
	int16_t  Po_outCurrent;
	int16_t  Po_PIDCurrent;
	
	uint8_t  M6020InfoUpdateFlag;		//信息读取更新标志
	uint16_t M6020InfoUpdateFrame;	//帧率
	uint8_t  M6020OffLineFlag;		  //设备离线标志
}M6020s_t;

typedef struct {
	float x;//xy坐标系中的x 的大小。
	float y;
	float radian;//与x轴正方向的弧度。
	float degrees;
	float distance;
}rocker_t;



typedef void TIM_SetComparex_f(TIM_TypeDef* TIMx, uint32_t Compare);


#endif /* __TYPEDEFS_H */
