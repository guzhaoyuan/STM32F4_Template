#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f4xx.h"
typedef uint8_t u8;
typedef uint16_t u16;


void delay_ms(u16 nms);
void delay_us(u32 nus);
void Delay_Init(u8 SYSCLK);

#define BIT(x)	(1 << (x))

extern u32 fac_ms;//全局变量
extern u8 fac_us;//全局变量


#endif

