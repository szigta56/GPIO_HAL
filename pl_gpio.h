#ifndef PL_GPIO_H_
#define PL_GPIO_H_

#include <stdint.h>

#include "pl_gpio_cfg.h"

void PL_Gpio_Init (const PL_GPIO_CFG_t *const Config);
void PL_Gpio_Write(PL_PORT_REG_t* port,uint8_t channel, uint8_t pinNum, Pl_Pin_state_t value );
Pl_Pin_state_t PL_Gpio_Read(PL_PORT_REG_t* port,uint8_t channel,uint8_t pinNum);
void PL_Gpio_SetDirection(PL_PORT_REG_t* port,uint8_t channel,uint8_t pinNum,Pl_Pin_mode_t direction);

void PL_Gpio_GlobalInterruptEnable(PL_PORT_REG_t* port);
void PL_Gpio_InterruptEnable(PL_PORT_REG_t* port, uint8_t channel);
void PL_Gpio_InterruptDisable(PL_PORT_REG_t* port, uint8_t channel);
void PL_Gpio_ClearInterrupt(PL_PORT_REG_t* port,uint8_t channel);

#endif


