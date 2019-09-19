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

/* 
    PL_RED_LED      on PORT1, Channel : CH2 PinNum: PIN3
    PL_GREEN_LED    on PORT1, Channel : CH1 PinNum: PIN3
    PL_BUTTON       on PORT2, Channel : CH1 PinNum: PIN3 

    PS_RED_LED      on PORT0, Channel : CH2 PinNum: PIN1
    PS_GREEN_LED    on PORT0, Channel : CH2 PinNum: PIN2
    PS_BUTTON       on PORT0, Channel : CH1 PinNum: PIN0

*/

#define PS_PORT_NUM  1u
#define PL_PORT_NUM  2u

#define PORT0 PS_GPIO
#define PORT1 PL_PORT0
#define PORT2 PL_PORT1

#define PIN0 PS_PIN0
#define PIN1 PS_PIN20
#define PIN2 PS_PIN21
#define PIN3 PL_PIN0

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

/*typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
    PIN16,
    PIN17,
    PIN18,
    PIN19,
    PIN20,
    PIN21,
    PIN22,
    PIN23,
    PIN24,
    PIN25,
    PIN26,
    PIN27,
    PIN28,
    PIN29,
    PIN30,
    PIN31
}Pin_num_t; */

typedef enum 
{
    CH1,
    CH2
}Channel_num_t;

typedef enum
{
    INTR_NONE,
    INTR_RISING,
    INTR_FALLING,
    INTR_BOTH,
    INTR_LEVEL,
    INTR_MODE_MAX
}Intr_type_t;

status Gpio_Init();
status Gpio_Write(void *port,Channel_num_t channel, uint8_t pinNum, uint8_t value);
uint8_t Gpio_Read(void *port,Channel_num_t channel, uint8_t pinNum);
status Gpio_SetDirection(void *port,Channel_num_t channel, uint8_t pinNum, Dir_mode_t direction);

status Gpio_InterruptEnable(void *port,Channel_num_t channel,uint8_t pinNum);
status Gpio_InterruptDisable(void *port,Channel_num_t channel,uint8_t pinNum);
status Gpio_ClearInterrupt(void *port,Channel_num_t channel,uint8_t pinNum);
status Gpio_SetInterruptType(void *port,Channel_num_t channel,uint8_t pinNum,Intr_type_t type);

void Gpio_RegisterWrite(uint32_t Address, uint32_t Value);
uint32_t Gpio_RegisterRead(uint32_t Address);

Gpio_type_t GetPortType(void *port);

#endif /* SRC_GPIO_HAL_MYGPIO_H_ */
