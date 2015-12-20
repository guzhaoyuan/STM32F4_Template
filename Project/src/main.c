#include "button_rocker.h"
#include "cutterMove.h"
#include "motor.h"
#include "sizeInput.h"
#include "usart1.h"
/*
TODO：
数码管显示

按键

系统时钟   已通过寄存器访问知其主频为100MHz  (修改了system_stm32f4xx.c)

*/
uint8_t Cutter_Init_Flag=0;  //判断是否回零点
uint8_t Cutter_Control_Flag=0;   //0---Manuallly 1---Automatically
CMD *cmd;
NODE *selflocation;
SIZE *size;


uint8_t tmp;
uint32_t pllv0;
uint32_t pllp;

int main(){
	// cmd = (CMD*)malloc(sizeof(CMD)); 
	// selflocation = malloc(sizeof(NODE)); 
	// size = malloc(sizeof(SIZE));
	//RCC_Config();
	
	RCC_HCLKConfig(RCC_HCLK_Div1);   //SysTick的时钟由AHB决定，现设为1分频（不分频）
	Delay_Init(168);
	//SysTick_Config(SystemCoreClock / 1000);

	// tmp=RCC_GetSYSCLKSource();
	//pllv0=((HSE_VALUE / (RCC->PLLCFGR & RCC_PLLCFGR_PLLM)) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6));
	//pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
	//RCC_ClocksTypeDef* RCC_Clocks;
	//RCC_GetClocksFreq(RCC_Clocks);
	USART1_Config();
	//printf("----------------------------------\r\n");
	// NVIC_Config();
	Motor_Init();
	Rocker_Init();
	//SysTick_Config();
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
		
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
		delay_ms(10);
		//delay_us(u32 nus);
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		delay_ms(10);
	//printf("%d\r\n",pllv0);
	//printf("%d\r\n",pllp);

		//printf("%d\r\n",RCC_Clocks->SYSCLK_Frequency);
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



