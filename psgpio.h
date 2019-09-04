/*
 * ps_gpio.h
 *
 *  Created on: 2019. aug. 29.
 *      Author: szigta56
 */

#include "psgpio_cfg.h"


#ifndef SRC_PS_LED_HAL_PS_Gpio_H_
#define SRC_PS_LED_HAL_PS_Gpio_H_

void PS_Gpio_Init(const PS_GPIO_CFG_t *const Config);
void PS_Gpio_Write(PS_PORT_REG_t* port,uint8_t channel, uint8_t pinNum, Ps_Pin_state_t value );
Ps_Pin_state_t PS_Gpio_Read(PS_PORT_REG_t* port,uint8_t channel,uint8_t pinNum);
void PS_Gpio_SetDirection(PS_PORT_REG_t* port,uint8_t channel,uint8_t pinNum,Ps_Pin_mode_t direction);

void PS_Gpio_InterruptEnable(PS_PORT_REG_t* port,uint8_t channel,uint8_t pinNum);
void PS_Gpio_InterruptType(PS_PORT_REG_t* port,uint8_t channel,uint8_t pinNum,Ps_Intr_mode_t type);
void PS_Gpio_InterruptDisable(PS_PORT_REG_t* port,uint8_t channel,uint8_t pinNum);
void PS_Gpio_ClearInterrupt(PS_PORT_REG_t* port,uint8_t channel,uint8_t pinNum);

Ps_Pin_num_t  PS_Gpio_GetBankPinNum(uint8_t* channel,uint8_t pinNum);
void PS_Gpio_RegisterWrite(uint32_t Address, uint32_t Value);
uint32_t PS_Gpio_RegisterRead(uint32_t Address);

#endif /* SRC_PS_LED_HAL_PSPS_Gpio_H_ */

