/*
 * mygpio.h
 *
 *  Created on: 2019. szept. 3.
 *      Author: szigta56
 */

#ifndef SRC_GPIO_HAL_MYGPIO_H_
#define SRC_GPIO_HAL_MYGPIO_H_

#include "../PL_HAL/pl_gpio.h"
#include "../PS_HAL/psgpio.h"



typedef enum
{
    INPUT,
    OUTPUT
}Dir_mode_t;

typedef enum
{
    PS_TYPE_GPIO,
    PL_TYPE_GPIO
}Gpio_type_t;

void Gpio_Init();
void Gpio_Write(void *port,Gpio_type_t type,uint8_t channel, uint8_t pinNum, uint8_t value);
uint8_t Gpio_Read(void *port,Gpio_type_t type,uint8_t channel, uint8_t pinNum);
void Gpio_SetDirection(void *port,Gpio_type_t type,uint8_t channel, uint8_t pinNum, uint8_t direction);

void Gpio_InterruptEnable(void *port,Gpio_type_t type,uint8_t channel,uint8_t pinNum);
void Gpio_InterruptDisable(void* port,Gpio_type_t,uint8_t channel,uint8_t pinNum);
void Gpio_ClearInterrupt(void* port,Gpio_type_t,uint8_t channel,uint8_t pinNum);



#endif /* SRC_GPIO_HAL_MYGPIO_H_ */
