#include "button_rocker.h"
#include "cutterMove.h"
#include "motor.h"
#include "sizeInput.h"

uint8_t Cutter_Init_Flag=0;  //判断是否回零点
uint8_t Cutter_Control_Flag=0;   //0---Manuallly 1---Automatically
CMD *cmd;
NODE *selflocation;
SIZE *size;

int main(){
	cmd = malloc(sizeof(CMD)); 
	selflocation = malloc(sizeof(NODE)); 
	size = malloc(sizeof(SIZE));
	USART1_Config();
	NVIC_Config();
	Motor_Init();
	Rocker_Init();
	Input_Init();
	Cutter_Init();   //回零点
	cmd->x_target=1;
	cmd->y_target=1;
	cmd->x_current=0;
	cmd->y_current=0;
	cmd->mode = 1;
	cmd->speed = 60;
	cmd->angle = 0;
	while (1)
	{  
		
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



