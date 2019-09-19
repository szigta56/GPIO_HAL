/*
 * myassert.h
 *
 *  Created on: 2019. szept. 16.
 *      Author: szigta56
 */

#ifndef SRC_GPIO_HAL_MYASSERT_H_
#define SRC_GPIO_HAL_MYASSERT_H_


#include <stdint.h>

typedef int8_t status;

#include "mygpio.h"

//**********************************ERROR CODES********************************

#define  NO_ERROR                   ( 0)
#define  INCORRECT_PIN              (-1)
#define  INCORRECT_CHANNEL          (-2)
#define  INCORRECT_PORT_ADDRESS     (-3)
#define  INCORRECT_INTERRUPT_TYPE   (-4)
#define  INCORRECT_DIRECTION        (-5)
#define  INCORRECT_VALUE            (-6)

//**********************************ASSERT MACROS FOR ERROR HANDLING********************************

#define ASSERT_PORT(port)    		(!((PS_GPIO==port) | (PL_PORT0==port) | (PL_PORT1==port)))
#define ASSERT_PIN(pinNum)          (!((PS_PIN20==pinNum) | (PS_PIN21==pinNum) | (PS_PIN0==pinNum) | (PL_PIN0==pinNum)))
#define ASSERT_CHANNEL(channel)     (!((channel==PS_BANK0) | (channel == PS_BANK1) | (channel==PL_CH1) | (channel==PL_CH2)))
#define ASSERT_VALUE(value)         (!((value==PS_PIN_HIGH) | (value==PS_PIN_LOW) | (value==PL_PIN_HIGH)| (value==PL_PIN_LOW)))
#define ASSERT_INTERRUPT(type)      (!((type==PS_INTR_NONE) | (type==PS_INTR_RISING) | (type==PS_INTR_FALLING) | (type==PS_INTR_BOTH) | (type==PS_INTR_LEVEL)|\
									(type==PL_INTR_NONE) | (type==PL_INTR_RISING) | (type==PL_INTR_FALLING) | (type==PL_INTR_BOTH) | (type==PL_INTR_LEVEL)))
#define ASSERT_DIRECTION(direction) (!((direction==PS_OUTPUT)| (direction==PS_INPUT)| (direction==PL_OUTPUT)| (direction==PL_OUTPUT)))                                   

#endif /* SRC_GPIO_HAL_MYASSERT_H_ */
