
#ifndef SRC_PL_HAL_PL_GPIO_CFG_H_
#define SRC_PL_HAL_PL_GPIO_CFG_H_
#include <stdint.h>




// *****************BASEADDRESSES OF GPIO PORTS************************

#define PL_PORT0 ((PL_PORT_REG_t*) 0x41200000)  // PL_LED
#define PL_PORT1 ((PL_PORT_REG_t*) 0x41210000)  // PL_BUTTON

//****************** NUMBER OF CONFIGTABLE ELEMENTS********************
#define PL_CONFIG_ELEMENTS  0x03

// *****************REGISTER OFFSETS FROM GPIO BASEADDRESSES************

typedef enum
{
    PL_PIN0,
    PL_PIN_MAX_NUM
}Pl_Pin_num_t;

typedef enum
{
    PL_INPUT,
    PL_OUTPUT,
    PL_PIN_MODE_MAX
}Pl_Pin_mode_t;

typedef enum
{
    PL_PIN_LOW,
    PL_PIN_HIGH,
    PL_GPIO_PIN_STATE_MAX
}Pl_Pin_state_t;

typedef enum
{
    PL_INTR_NONE,
    PL_INTR_RISING,
    PL_INTR_FALLING,
    PL_INTR_BOTH,
	PL_INTR_LEVEL,
    PL_INTR_MODE_MAX
}Pl_Intr_mode_t;

typedef enum
{
    PL_CH1,
	PL_CH2,
    PL_CHANNEL_NUM_MAX
}Pl_Channel_num_t;


//*******************STRUCTURE OF REGISTERS*******************************************

typedef struct 
{
  //each field represents a memory mapped register with the individual offsets from the baseaddress

    uint32_t CH1_DATA_REG;                        /*!< 0x00000000 Port output data register */
    uint32_t CH1_TRI_REG;                         /*!< 0x00000004 Port direction register */
    uint32_t CH2_DATA_REG;                        /*!< 0x00000008 Port output data  register */
    uint32_t CH2_TRI_REG;
    uint32_t RESERVED [67];
    uint32_t GLOBAL_INTR_REG;
    uint32_t INTR_STATUS_REG;
    uint32_t RESERVED2[1];
    uint32_t INTR_ENABLE_REG;
												 /*!< 0x0000000C Port directon register */
} PL_PORT_REG_t;


typedef struct 
{
    PL_PORT_REG_t*     Port;
    Pl_Channel_num_t   Channel;
    Pl_Pin_num_t       Pin;
    Pl_Pin_mode_t      Direction;
    Pl_Pin_state_t     State;
    Pl_Intr_mode_t     Interrupt;
} PL_GPIO_CFG_t;

const PL_GPIO_CFG_t *const PL_Gpio_GetConfig(void);

#endif
