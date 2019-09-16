/*
 * psgpio_cfg.h
 *
 *  Created on: 2019. aug. 29.
 *      Author: szigta56
 */

#ifndef SRC_PS_HAL_PSGPIO_CFG_H_
#define SRC_PS_HAL_PSGPIO_CFG_H_

#include <stdint.h>

#define PS_GPIO ((PS_PORT_REG_t*) 0xE000A000)
#define MIO_BASE ((MIO_REG_t*) 0xF8000000)

#define PS_CONFIG_ELEMENTS  0x03

// *****************REGISTER OFFSETS FROM GPIO BASEADDRESSES************

typedef enum
{
    PS_PIN0,
    PS_PIN20=20,
    PS_PIN21=21,
    PS_PIN_MAX_NUM
}Ps_Pin_num_t;

typedef enum
{
    PS_INPUT,
    PS_OUTPUT,
    PS_PIN_MODE_MAX
}Ps_Pin_mode_t;

typedef enum
{
    PS_PIN_LOW,
    PS_PIN_HIGH,
    PS_GPIO_PIN_STATE_MAX
}Ps_Pin_state_t;

typedef enum
{
    PS_INTR_NONE,
    PS_INTR_RISING,
    PS_INTR_FALLING,
    PS_INTR_BOTH,
	PS_INTR_LEVEL,
    PS_INTR_MODE_MAX
}Ps_Intr_mode_t;

typedef enum
{
    PS_BANK0,
	PS_BANK1,
    PS_BANK_NUM_MAX
}Ps_Bank_num_t;


//*******************STRUCTURE OF REGISTERS*******************************************

typedef struct 
{
  //each field represents a memory mapped register with the individual offsets from the baseaddress
   uint32_t LOW_MASK_DATA_0;
   uint32_t HIGH_MASK_DATA_0;
   uint32_t LOW_MASK_DATA_1;
   uint32_t HIGH_MASK_DATA_1;
   uint32_t RESERVED0[12];
   uint32_t DATA_OUT_0;
   uint32_t DATA_OUT_1;
   uint32_t RESERVED1[6];
   uint32_t DATA_IN_0;
   uint32_t DATA_IN_1;
   uint32_t RESERVED2[103];
   uint32_t DIR_MODE_0;
   uint32_t OUT_ENABLE_0;
   uint32_t INTR_MASK_STATUS_0;
   uint32_t INTR_ENABLE_0;
   uint32_t INTR_DISABLE_0;
   uint32_t INTR_STATUS_0;
   uint32_t INTR_TYPE_0;
   uint32_t INTR_POLARITY_0;
   uint32_t INTR_BOTH_EDGE_0;
   uint32_t RESERVED[7];
   uint32_t DIR_MODE_1;
   uint32_t OUT_ENABLE_1;
   uint32_t INTR_MASK_STATUS_1;
   uint32_t INTR_ENABLE_1;
   uint32_t INTR_DISABLE_1;
   uint32_t INTR_STATUS_1;
   uint32_t INTR_TYPE_1;
   uint32_t INTR_POLARITY_1;
   uint32_t INTR_BOTH_EDGE_1;          											 
} PS_PORT_REG_t;

typedef struct 
{
   uint32_t RESERVED[448];
   uint32_t MIO_0;
   uint32_t MIO_1;
   uint32_t MIO_2;
   uint32_t MIO_3;
   uint32_t MIO_4;
   uint32_t MIO_5;
   uint32_t MIO_6;
   uint32_t MIO_7;
   uint32_t MIO_8;
   uint32_t MIO_9;
   uint32_t MIO_10;
   uint32_t MIO_11;
   uint32_t MIO_12;
   uint32_t MIO_13;
   uint32_t MIO_14;
   uint32_t MIO_15;
   uint32_t MIO_16;
   uint32_t MIO_17;
   uint32_t MIO_18;
   uint32_t MIO_19;
   uint32_t MIO_20;
   uint32_t MIO_21;
   uint32_t MIO_22;
   uint32_t MIO_23;
   uint32_t MIO_24;
   uint32_t MIO_25;
   uint32_t MIO_26;
   uint32_t MIO_27;
   uint32_t MIO_28;
   uint32_t MIO_29;
   uint32_t MIO_30;
   uint32_t MIO_31;
   uint32_t MIO_32;
   uint32_t MIO_33;
   uint32_t MIO_34;
   uint32_t MIO_35;
   uint32_t MIO_36;
   uint32_t MIO_37;
   uint32_t MIO_38;
   uint32_t MIO_39;
   uint32_t MIO_40;
   uint32_t MIO_41;
   uint32_t MIO_42;
   uint32_t MIO_43;
   uint32_t MIO_44;
   uint32_t MIO_45;
   uint32_t MIO_46;
   uint32_t MIO_47;
   uint32_t MIO_48;
   uint32_t MIO_49;
   uint32_t MIO_50;
   uint32_t MIO_51;
   uint32_t MIO_52;
   uint32_t MIO_53;  
}MIO_REG_t;

typedef struct 
{
    PS_PORT_REG_t*     Port;
    Ps_Bank_num_t	   Channel;
    Ps_Pin_num_t       Pin;
    Ps_Pin_mode_t      Direction;
    Ps_Pin_state_t     State;
    Ps_Intr_mode_t     Interrupt;
} PS_GPIO_CFG_t;

const PS_GPIO_CFG_t *const PS_Gpio_GetConfig(void);

#endif /* SRC_PS_LED_HAL_PSGPIO_CFG_H_ */

  
