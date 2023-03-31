/*********************************
    本模块包含的头文件
**********************************/
#include "BSP_KEY.h"

/*********************************
    本模块的数据类型/宏以及变量定义
**********************************/

//数据类型，结构体实现
typedef struct 
{
    GPIO_TypeDef    *Port;  //端口号
    uint16_t        Pin;    //引脚号
    KEY_DRIVE       Level;  //驱动方式
		KEY_STATE				State;//
		KEY_FLAG 				Sig;		//有效标志
}KEY_TypeDef;

//按键数量的宏定义，默认为8
#define KEYn    8

//定义按键对象数组，用于存放每一个按键的编号，初始值赋为0
static KEY_TypeDef Keys[KEYn] = {0};


//按键配置函数：
void BSP_KEY_Init(KEY_INDEX num,  GPIO_TypeDef* port, uint16_t pin, KEY_DRIVE level)
{
    Keys[num].Port 	= port;
    Keys[num].Pin  	= pin;
    Keys[num].Level	= level;
		Keys[num].Sig  	= 0;
		Keys[num].State = KEY_UP;
}

//按键扫描函数
uint8_t BSP_KEY_Scan(KEY_INDEX num)
{
	switch(Keys[num].State)
	{
		case KEY_UP :
		{
			if(HAL_GPIO_ReadPin (Keys[num].Port, Keys[num].Pin)==GPIO_PIN_RESET )
			{
				Keys[num].State = KEY_DEBOUNCE ;
			}
			break ;	
		}
		
		
		case KEY_DEBOUNCE :
		{
			if(HAL_GPIO_ReadPin (Keys[num].Port, Keys[num].Pin)==GPIO_PIN_RESET)
			{
				Keys[num].State = KEY_WAIT_RELEASE ;
				Keys[num].Sig= 1;
			}
		
		else
		{
			Keys[num].State = KEY_UP ;
		}
		break ;
		}
		case KEY_WAIT_RELEASE :
		{
			if(HAL_GPIO_ReadPin (Keys[num].Port, Keys[num].Pin)==GPIO_PIN_SET)
			{
				Keys[num].State = KEY_UP ;
				//KeyFlag[num]=1;
			}
			break ;
		}
		default :break ;
		
	}
	return 0;
}



//缓冲区读取函数

uint8_t BSP_KEY_Read(KEY_INDEX num)
{
    if(Keys[num].Sig==GPIO_PIN_SET)
		{
			Keys[num].Sig=UN;
			return 1;
		}
			else
			
			return 0;
			
}

	



