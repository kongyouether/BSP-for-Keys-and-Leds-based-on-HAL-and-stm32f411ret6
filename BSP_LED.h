//指示灯驱动模块
//头文件
#ifndef __BSP_LED_H
#define __BSP_LED_H
//本模块包含的头文件
#include "stm32f4xx_hal.h"
/*********************************
    本模块自定义数据类型
**********************************/

//1.定义指示灯编号数据类型
typedef enum
{
    LED0 = 0,
    LED1 = 1,
    LED2 = 2,
    LED3 = 3,
    LED4 = 4,
    LED5 = 5,
    LED6 = 6,
    LED7 = 7,
}LED_INDEX;

//2.定义指示灯驱动方式数据类型
typedef enum
{
    LOW_LEVEL = 0,
    HIGH_LEVEL
}LED_DRIVE;

/*********************************
    本模块提供给外部调用的函数
**********************************/

//指示灯配置函数
extern void BSP_LED_Config(LED_INDEX num, GPIO_TypeDef* port, uint16_t pin, LED_DRIVE level);//指示灯配置函数
extern void BSP_LED_On (LED_INDEX num);//指示灯开启函数
extern void BSP_LED_Off (LED_INDEX num);//指示灯关闭函数
extern void BSP_LED_Toggle (LED_INDEX num);//指示灯反转函数
#endif