/*
 * mygpio.c
 *
 *  Created on: 2019. szept. 3.
 *      Author: szigta56
 */

#include "myassert.h"
#include "mygpio.h"

static uint32_t volatile *const PS_Ports[]=
{
    (uint32_t *)PS_GPIO
};

static uint32_t volatile *const PL_Ports[]=
{
    (uint32_t*)PL_PORT0,
    (uint32_t*)PL_PORT1
};


status Gpio_Init()
{
    status errorStatus;

    errorStatus = PS_Gpio_Init(PS_Gpio_GetConfig());
    if(errorStatus) return errorStatus;

    errorStatus = PL_Gpio_Init(PL_Gpio_GetConfig());
    if(errorStatus) return errorStatus;

    else            return NO_ERROR;
}

status Gpio_Write(void *port,uint8_t channel, uint8_t pinNum, uint8_t value)
{   
    status errorStatus;
    Gpio_type_t type;
    type = GetPortType(port);
    
    if (type==PL_TYPE_GPIO)   
      { 
          errorStatus = PL_Gpio_Write(port,channel,pinNum,value);
          return errorStatus;
      }
    else if(type==PS_TYPE_GPIO)
    {
         errorStatus = PS_Gpio_Write(port,channel,pinNum,value);  
         return errorStatus;
    }   
    else  return INCORRECT_PORT_ADRESSS;

}

uint8_t Gpio_Read(void *port,Channel_num_t channel, uint8_t pinNum)
{
    
    Gpio_type_t type;
    type = GetPortType(port);

    if (type==PL_TYPE_GPIO)
    {
       return PL_Gpio_Read(port,channel,pinNum);
    }
    else if(type==PS_TYPE_GPIO)
    {
       return PS_Gpio_Read(port,channel,pinNum);
    }
    else return INCORRECT_PORT_ADRESSS;
}

status Gpio_SetDirection(void *port,Channel_num_t channel, uint8_t pinNum, uint8_t direction)
{
    status errorStatus;
    Gpio_type_t type;
    type = GetPortType(port);

    if (type==PL_TYPE_GPIO)
    {
        errorStatus = PL_Gpio_SetDirection(port,channel,pinNum,direction);
        return errorStatus;
    }
    else if(type==PS_TYPE_GPIO)
    {
        errorStatus = PS_Gpio_SetDirection(port,channel,pinNum,direction);
        return errorStatus;
    }
     else  return INCORRECT_PORT_ADRESSS;
}

void Gpio_InterruptEnable(void *port,Channel_num_t channel,uint8_t pinNum)
{
    Gpio_type_t type;
    type = GetPortType(port);

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

void Gpio_InterruptDisable(void *port,Channel_num_t channel,uint8_t pinNum)
{
    Gpio_type_t type;
    type = GetPortType(port);

    if (type==PL_TYPE_GPIO)
    {   
       PL_Gpio_InterruptDisable(port,channel);
    }
    else if(type==PS_TYPE_GPIO)
    {
        PS_Gpio_InterruptDisable(port,channel,pinNum);
    }
}

void Gpio_ClearInterrupt(void *port,Channel_num_t channel,uint8_t pinNum)
{
    Gpio_type_t type;
    type = GetPortType(port);

    if (type==PL_TYPE_GPIO)
    {   
       PL_Gpio_ClearInterrupt(port,channel);
    }
    else if(type==PS_TYPE_GPIO)
    {
        PS_Gpio_ClearInterrupt(port,channel,pinNum);
    }    

}

void Gpio_RegisterWrite(uint32_t Address, uint32_t Value)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   *RegisterPointer = Value;
}

uint32_t Gpio_RegisterRead(uint32_t Address)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   return *RegisterPointer;
}

Gpio_type_t GetPortType(void *port)
{
    uint8_t  i=0;

    for(i=0;i<PS_PORT_NUM;i++)
    {
        if(port==PS_Ports[i]) return PS_TYPE_GPIO;
    }
    for(i=0;i<PL_PORT_NUM;i++)
    {
        if(port==PL_Ports[i]) return PL_TYPE_GPIO;
    }

    return INCORRECT_PORT_ADRESSS;

}
