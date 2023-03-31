/*********************************
    本模块包含的头文件
**********************************/
#include "stm32f4xx_hal.h"
#include "BSP_LED.h"

/*********************************
    本模块的数据类型/宏以及变量定义
**********************************/

//数据类型，结构体实现
typedef struct 
{
    GPIO_TypeDef    *Port;  //端口号
    uint16_t        Pin;    //引脚号
    LED_DRIVE       Level;  //驱动方式 
}LED_TypeDef;
//指示灯数量的宏定义，默认为8
#define LEDn    8
// 定义指示灯对象数组，用于存放每一个指示灯的属性。初始值赋为0
static LED_TypeDef Leds[LEDn] = {0};


//指示灯配置函数：
void BSP_LED_Config(LED_INDEX num,  GPIO_TypeDef* port, uint16_t pin, LED_DRIVE level)//(LEDO,GPIOA,GPIO_PIN_2,HIGH_LEVEL)
{
    Leds[num].Port = port;
    Leds[num].Pin  = pin;
    Leds[num].Level= level;
}


//指示灯开启函数
void BSP_LED_On(LED_INDEX num)
{
    if(Leds[num].Level==HIGH_LEVEL)
    {
        HAL_GPIO_WritePin( Leds[num].Port, Leds[num].Pin,GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin( Leds[num].Port, Leds[num].Pin,GPIO_PIN_RESET);
    }
    
}

//指示灯关闭函数
void BSP_LED_Off(LED_INDEX num)
{
    if(Leds[num].Level==HIGH_LEVEL)
    {
        HAL_GPIO_WritePin( Leds[num].Port, Leds[num].Pin,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin( Leds[num].Port, Leds[num].Pin,GPIO_PIN_SET);
    }
    
}

//指示灯翻转函数
void BSP_LED_Toggle(LED_INDEX num)
{
    
        HAL_GPIO_TogglePin( Leds[num].Port, Leds[num].Pin );
    
}

