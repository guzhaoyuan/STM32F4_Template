#ifndef _BUTTON_ROCKER_H
#define _BUTTON_ROCKER_H

#include "motor.h"
#include "stm32f4xx_dma.h"

#define PI 3.1415926

typedef struct cmd     //核心结构体，抽象封装所有的指令
{
	float x_target;  //自动指令
	float y_target;  //自动指令
	float x_current;  //自动指令
	float y_current;  //自动指令
	unsigned char mode; //0--Manually 1--Automatically
	unsigned char insert ;     //为简化控制，固定切深，仅保留切下(1)，抬起(0)二种状态
	float speed;     //手动指令   max=80
	float angle;     //手动指令
	float DCSpeed;   //DCBL Speed
}CMD;

void Rocker_Init(void);  //摇杆初始化
void Rocker_Cmd(CMD *cmd); //读取指令存入指令空间
void Exec_Cmd(CMD *cmd);    //执行命令，底层调用cuttermove的函数

 uint16_t ADC_value[32][4];
 uint16_t ADC_value_filter[4];
 uint8_t filter_Flag;    //0---filt NO 1---filt OK
 uint8_t ADC_middle;       //摇杆的静态值

#endif 