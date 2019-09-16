/*
 * psgpio_cfg.c
 *
 *  Created on: 2019. aug. 29.
 *      Author: szigta56
 */
#include "psgpio_cfg.h"

const PS_GPIO_CFG_t PS_GpioConfigTable[]=

{
//    Port     Channel 		Pin     Pin         Initital    Interrupt
//    number   number 		number  direction   state       type

	{  PS_GPIO, PS_BANK1,  	PS_PIN20,   PS_OUTPUT,    PS_PIN_LOW,    	PS_INTR_NONE,     },
    {  PS_GPIO, PS_BANK1,  	PS_PIN21,   PS_OUTPUT,    PS_PIN_LOW,    	PS_INTR_NONE,     },
    {  PS_GPIO, PS_BANK0,  	PS_PIN0,    PS_INPUT,     PS_PIN_HIGH,    	PS_INTR_RISING,   },
    
};


const PS_GPIO_CFG_t *const PS_Gpio_GetConfig()
{
    PS_GPIO_CFG_t *CfgPtr;
    
    CfgPtr = (PS_GPIO_CFG_t *)&PS_GpioConfigTable;
    
    return CfgPtr;
}
