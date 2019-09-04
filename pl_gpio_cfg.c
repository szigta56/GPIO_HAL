#include "pl_gpio_cfg.h"



const PL_GPIO_CFG_t PL_GpioConfigTable[]=

{
//    Port     Channel 		Pin     Pin         Initital    Interrupt
//    number   number 		number  direction   state       type

	{ PL_LED,     PL_CH1, 		PL_PIN0,   PL_OUTPUT,    PL_PIN_LOW,     PL_INTR_NONE,     },
    { PL_LED,     PL_CH2, 		PL_PIN0,   PL_OUTPUT,    PL_PIN_LOW,     PL_INTR_NONE,     },
    { PL_BUTTON,  PL_CH1, 		PL_PIN0,   PL_INPUT,     PL_PIN_HIGH,    PL_INTR_LEVEL,     }

    
};

const PL_GPIO_CFG_t *const PL_Gpio_GetConfig()
{
    PL_GPIO_CFG_t *CfgPtr;
    
    CfgPtr = (PL_GPIO_CFG_t *)&PL_GpioConfigTable;
    
    return CfgPtr;
}
