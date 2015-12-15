#include "button_rocker.h"
#include "cutterMove.h"
#include "motor.h"
#include "sizeInput.h"

uint8_t Cutter_Init_Flag=0;  //判断是否回零点
uint8_t Cutter_Control_Flag=0;   //0---Manuallly 1---Automatically

int main()
{
	//CMD *cmd=(*CMD)malloc(sizeof(CMD)); 
	//LOCATION *selflocation=(*LOCATION)malloc(sizeof(LOACTION)); 
	//SIZE *size=(*SIZE)malloc(sizeof(SIZE));
	Motor_Init();
	Rocker_Init();
	//Input_Init();
	Cutter_Init();   //回零点
	while (1)
	{   
  		//DCMotor_Speed(50);
  		//Stepper_Speed(stepper1 , -50);
  		//Stepper_Speed(stepper2 , 50);
  		// Stepper_Speed(stepper3 , 50);
	}
}



