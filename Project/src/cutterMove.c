/* 
* @Author: jeasinema
* @Date:   2015-12-06 22:24:59
* @Last Modified by:   JeasineMa
* @Last Modified time: 2015-12-20 01:32:00
*/

#include "cutterMove.h"
#include "button_rocker.h"
#include "motor.h"
#include "math.h"


extern uint8_t Cutter_Init_Flag;
extern uint8_t Cutter_Control_Flag;
static unsigned char drillPosition = 2 ;//1----down 2-----up
/*
Stepper1
X
|
|
|
|
|
|
|-----------------------------Y  Stepper2
*/
void Cutter_Move_Manually(float speed , float angle , float DCSpeed)   //传入速度角度和大小控制运动
{
	
	DCMotor_Speed(DCSpeed);
	Stepper_Speed(stepper1 , speed);
	//Stepper_Speed(stepper2 , speed*cos(angle));   
}

void Cutter_Move_Automatically(CMD *cmd)   //传入速度角度和大小控制运动
{
	float deltaX = cmd->x_target - cmd->x_current;
	float deltaY = cmd->y_target - cmd->y_current;
	float angle = atan((float)deltaY/(float)deltaX);
	Stepper_Speed(stepper1, cos(angle) * 60);
	Stepper_Speed(stepper2, sin(angle) * 60);
	float distance = sqrt(deltaX*deltaX + deltaY*deltaY);
	float delayTime = distance/60*0xFFFFFF;
	Delay(delayTime);
	//cutterStop();
}

void Cutter_Move_Drill(unsigned char flag)       		//1----down 2-----up
{
	if(flag==1)
	{
		if(drillPosition==2){
			Stepper_Speed(stepper3 , 30);
			Delay(0xFFFF); 				//TODO：确定准确的数值
			Stepper_Speed(stepper3 , 0);
		}
		drillPosition=1;
	}
	else 
	{
		if(drillPosition==1){
			Stepper_Speed(stepper3 , -30);
			Delay(0xFFFFFF);
			Stepper_Speed(stepper3 , 0);
		}
		drillPosition=2;
	}
}

void Cutter_Init(void)						//回原点
{
	Stepper_Speed(stepper1 , -60);
	Stepper_Speed(stepper2 , -60);
	while(!(Cutter_Init_Flag>=2));
	Cutter_Control_Flag=0;//手动模式使能
}

int whetherReachDestination(){
	return 0;
}

void cutterStop(void){
	Stepper_Speed(stepper1 , 0);
	Stepper_Speed(stepper2 , 0);
}

void EXTI0_IRQHandler(void)   //到达x最小
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		Cutter_Init_Flag+=1;
		//Cutter_Control_Flag=0;   //手动模式使能
		Stepper_Speed(stepper1 , 0);
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}


void EXTI1_IRQHandler(void)   //到达x最大
{
	if(EXTI_GetITStatus(EXTI_Line1) != RESET)
	{
		Cutter_Control_Flag=0;
		Stepper_Speed(stepper1 , -60);  //X方向电机反向
	}
	EXTI_ClearITPendingBit(EXTI_Line1);
}

void EXTI2_IRQHandler(void)  //到达y最小
{
	if(EXTI_GetITStatus(EXTI_Line2) != RESET)
	{
		Cutter_Init_Flag+=1;
		//Cutter_Control_Flag=0;
		Stepper_Speed(stepper2 , 0);
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}

void EXTI3_IRQHandler(void)  //到达y最大
{
	if(EXTI_GetITStatus(EXTI_Line3) != RESET)
	{
		Cutter_Control_Flag=0;
		Stepper_Speed(stepper2 , -60);
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}


void RCC_Config()
{
     uint32_t           PLL_M;      
     uint32_t           PLL_N;
     uint32_t           PLL_P;
     uint32_t           PLL_Q;
 
    /*配置前将所有RCC重置为初始值*/
     RCC_DeInit();
 
     /*这里选择 外部晶振（HSE）作为 时钟源，因此首先打开外部晶振*/
     RCC_HSEConfig(RCC_HSE_ON);
     /*等待外部晶振进入稳定状态*/
     while(RCC_WaitForHSEStartUp() != SUCCESS );
 
     /*
     **我们要选择PLL时钟作为系统时钟，因此这里先要对PLL时钟进行配置
     */
 
     /*选择外部晶振作为PLL的时钟源*/
    
     /* 到这一步为止，已有 HSE_VALUE = 8 MHz.
        PLL_VCO input clock = (HSE_VALUE or HSI_VALUE / PLL_M)，
        根据文档，这个值被建议在 1~2MHz，因此我们令 PLL_M = 8，
        即 PLL_VCO input clock = 1MHz */
     PLL_M         =    8;  
    
     /* 到这一步为止，已有 PLL_VCO input clock = 1 MHz.
        PLL_VCO output clock = (PLL_VCO input clock) * PLL_N,
        这个值要用来计算系统时钟，我们 令 PLL_N = 336,
        即 PLL_VCO output clock = 336 MHz.*/       
     PLL_N        =    168;
 
     /* 到这一步为止，已有 PLL_VCO output clock = 336 MHz.
        System Clock = (PLL_VCO output clock)/PLL_P ,
        因为我们要 SystemClock = 168 Mhz，因此令 PLL_P = 2.
        */
     PLL_P         =    1;
 
     /*这个系数用来配置SD卡读写，USB等功能，暂时不用，根据文档，暂时先设为7*/
     PLL_Q         =    7;
    
     /* 配置PLL并将其使能，获得 168Mhz 的 System Clock 时钟*/
     RCC_PLLConfig(RCC_PLLSource_HSE, PLL_M, PLL_N, PLL_P, PLL_Q);
     RCC_PLLCmd(ENABLE);
 
     /*到了这一步，我们已经配置好了PLL时钟。下面我们配置Syetem Clock*/
     /*选择PLL时钟作为系统时钟源*/
     RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
}


