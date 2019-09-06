/*
 * mygpio.c
 *
 *  Created on: 2019. szept. 3.
 *      Author: szigta56
 */

#include "mygpio.h"


void Gpio_Init()
{
    PS_Gpio_Init(PS_Gpio_GetConfig());
    PL_Gpio_Init(PL_Gpio_GetConfig());
}

void Gpio_Write(void *port,Gpio_type_t type,uint8_t channel, uint8_t pinNum, uint8_t value)
{

    if (type==PL_TYPE_GPIO)
    {
        PL_Gpio_Write(port,channel,pinNum,value);
    }
    else if(type==PS_TYPE_GPIO)
    {
        PS_Gpio_Write(port,channel,pinNum,value);   
    }
}

uint8_t Gpio_Read(void *port,Gpio_type_t type,uint8_t channel, uint8_t pinNum)
{
    
    if (type==PL_TYPE_GPIO)
    {
       return PL_Gpio_Read(port,channel,pinNum);
    }
    else if(type==PS_TYPE_GPIO)
    {
       return PS_Gpio_Read(port,channel,pinNum);
    }
}

void Gpio_SetDirection(void *port,Gpio_type_t type,uint8_t channel, uint8_t pinNum, uint8_t direction)
{

    if (type==PL_TYPE_GPIO)
    {
        PL_Gpio_SetDirection(port,channel,pinNum,direction);
    }
    else if(type==PS_TYPE_GPIO)
    {
        PS_Gpio_SetDirection(port,channel,pinNum,direction);
    }
}

void Gpio_InterruptEnable(void *port,Gpio_type_t type,uint8_t channel,uint8_t pinNum)
{

    if (type==PL_TYPE_GPIO)
    {   
        PL_Gpio_GlobalInterruptEnable(port);
        PL_Gpio_InterruptEnable(port,channel);
    }
    else if(type==PS_TYPE_GPIO)
    {
        PS_Gpio_InterruptEnable(port,channel,pinNum);
    }
}

void Gpio_InterruptDisable(void *port,Gpio_type_t type,uint8_t channel,uint8_t pinNum)
{
    if (type==PL_TYPE_GPIO)
    {   
       PL_Gpio_InterruptDisable(port,channel);
    }
    else if(type==PS_TYPE_GPIO)
    {
        PS_Gpio_InterruptDisable(port,channel,pinNum);
    }
}

void Gpio_ClearInterrupt(void *port,Gpio_type_t type,uint8_t channel,uint8_t pinNum)
{
    if (type==PL_TYPE_GPIO)
    {   
       PL_Gpio_ClearInterrupt(port,channel);
    }
    else if(type==PS_TYPE_GPIO)
    {
        PS_Gpio_ClearInterrupt(port,channel,pinNum);
    }    

}


