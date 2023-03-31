//按键驱动模块
//头文件
#ifndef __BSP_KEY_H
#define __BSP_KEY_H
//本模块包含的头文件
#include "stm32f4xx_hal.h"
/*********************************
    本模块自定义数据类型
**********************************/

//1.定义按键编号数据类型
typedef enum
{
    KEY0 = 0,
    KEY1 = 1,
    KEY2 = 2,
    KEY3 = 3,
    KEY4 = 4,
    KEY5 = 5,
    KEY6 = 6,
    KEY7 = 7,
}KEY_INDEX;

//2.定义按键按下电平的数据类型
typedef enum
{
    PULL_DOWN = 0,
    PULL_UP
}KEY_DRIVE;

//按键三个状态，数据类型
typedef enum 
{
	KEY_UP =0,
	KEY_DEBOUNCE,
	KEY_WAIT_RELEASE
}KEY_STATE;

//3.不同按键标志的数据类型
typedef enum
{
    UN = 0,
		EN
}KEY_FLAG;




/*********************************
    本模块提供给外部调用的函数
**********************************/



//指示灯配置函数
extern void BSP_KEY_Init(KEY_INDEX num, GPIO_TypeDef* port, uint16_t pin, KEY_DRIVE level);//按键初始化函数
extern uint8_t BSP_KEY_Scan(KEY_INDEX num);//按键扫描函数
extern uint8_t BSP_KEY_Read (KEY_INDEX num);//按键读取函数

#endif