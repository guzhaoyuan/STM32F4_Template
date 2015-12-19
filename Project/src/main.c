#include "button_rocker.h"
#include "cutterMove.h"
#include "motor.h"
#include "sizeInput.h"
#include "usart1.h"
/*
TODO：
调通摇杆  OK 直接读取ADC_value_filter[i]即可 存在两个问题：1.使用ADC1的IN10/11时其IN12/13会受到IN11的干扰，下拉至地亦无效
			ADC_value_filter[i]的值大约在0-4096之间 中间值为2095
			+1 板子的VCC断了。。。。
数码管显示

按键


*/
uint8_t Cutter_Init_Flag=0;  //判断是否回零点
uint8_t Cutter_Control_Flag=0;   //0---Manuallly 1---Automatically
CMD *cmd;
NODE *selflocation;
SIZE *size;

int main(){
	// cmd = (CMD*)malloc(sizeof(CMD)); 
	// selflocation = malloc(sizeof(NODE)); 
	// size = malloc(sizeof(SIZE));
	USART1_Config();
	// NVIC_Config();
	// Motor_Init();
	Rocker_Init();
	// Input_Init();
	// Cutter_Init();   //回零点
	// cmd->x_target=1;
	// cmd->y_target=1;
	// cmd->x_current=0;
	// cmd->y_current=0;
	// cmd->mode = 0;
	// cmd->speed = 60;
	// cmd->angle = 1;
	while (1)
	{  
		//printf("ADC=%d\r\n",ADC_value[0][0]);
		// printf("ADC1=%d\r\n",ADC_value_filter[0]);
		// printf("ADC2=%d\r\n",ADC_value_filter[1]);
		// printf("ADC3=%d\r\n",ADC_value_filter[2]);
		// printf("ADC4=%d\r\n",ADC_value_filter[3]);
		//Exec_Cmd(cmd);
		 // Stepper_Speed(stepper1 , -60);
		 // Stepper_Speed(stepper2 , -60);
		// Stepper_Speed(stepper2 , 0);
		// Delay(0x1FFFFFF);

		// Stepper_Speed(stepper2 , 60);
		// Stepper_Speed(stepper1 , 0);
		// Delay(0x1FFFFFF);
		
		// Stepper_Speed(stepper2 , 0);
		// Stepper_Speed(stepper1 , -60);
		// Delay(0x1FFFFFF);

		// Stepper_Speed(stepper2 , -60);
		// Stepper_Speed(stepper1 , 0);
		// Delay(0x1FFFFFF);
  		//DCMotor_Speed(50);
  		//Stepper_Speed(stepper1 , -50);
  		//Stepper_Speed(stepper2 , 50);
  		// Stepper_Speed(stepper3 , 50);
	}
}



