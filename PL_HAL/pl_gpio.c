#include "PL_GPIO.h"

void PL_Gpio_Init (const PL_GPIO_CFG_t *const Config)
{   
    uint8_t i;
    volatile PL_PORT_REG_t* port;
    volatile uint8_t pin;
    volatile uint8_t channel;
    volatile uint8_t interrupt;
    volatile uint8_t state;
    volatile uint8_t direction;
    
    for (i=0;i<PL_CONFIG_ELEMENTS;i++)
    {
        port = Config[i].Port;
        pin  = Config[i].Pin;
        channel = Config[i].Channel;
        interrupt= Config [i].Interrupt;
        state = Config[i].State;
        direction = Config[i].Direction;

        switch(channel)
        {
        case PL_CH1:

        	if(direction == PL_INPUT) 	port->CH1_TRI_REG |= 1<<pin;
        	else 					port ->CH1_TRI_REG &= ~(1<<pin);
  
        	if(state==PL_PIN_LOW)		port->CH1_DATA_REG &= ~(1<<pin);
        	else					port->CH1_DATA_REG |= 1<<pin;
        	break;

        case PL_CH2:

			if(direction == PL_INPUT)  port->CH2_TRI_REG |= 1<<pin;
			else					port ->CH2_TRI_REG &= ~(1<<pin);
			
			if(state==PL_PIN_LOW) 		port->CH2_DATA_REG &= ~(1<<pin);
			else					port->CH2_DATA_REG |= 1<<pin;
			break;
        }

        switch (interrupt)
        {
            case PL_INTR_NONE:
			PL_Gpio_InterruptDisable(port,channel);

            break;
            
            case PL_INTR_RISING:
                        
            break;
            
            case PL_INTR_FALLING:
            
            break;
            
            case PL_INTR_LEVEL:
             PL_Gpio_GlobalInterruptEnable(port);
             PL_Gpio_InterruptEnable(port,channel);

            break;

            case PL_INTR_BOTH:
            
            break;
        
        }
    }
}

void PL_Gpio_Write(PL_PORT_REG_t *port, uint8_t channel, uint8_t pinNum,Pl_Pin_state_t value )
{

    switch(channel)
    {
    case PL_CH1:
    	if(value==PL_PIN_HIGH) port->CH1_DATA_REG |= value << pinNum;
    	else 				  port->CH1_DATA_REG &= value << pinNum;
    	break;
    case PL_CH2:
    	if(value==PL_PIN_HIGH) port->CH2_DATA_REG |= value << pinNum;
    	else 				port->CH2_DATA_REG &= value << pinNum;
    	break;

    }
}

Pl_Pin_state_t PL_Gpio_Read(PL_PORT_REG_t* port,uint8_t channel,uint8_t pinNum)
{

	uint32_t tempReg=0;

	uint32_t pinMask = 1<<pinNum;

	switch(channel)
	{
	case PL_CH1:
		tempReg = port->CH1_DATA_REG;
		break;
	case PL_CH2:
		tempReg = port->CH2_DATA_REG;
		break;
	}
	return ((tempReg & pinMask)? PL_PIN_HIGH:PL_PIN_LOW);

}

void PL_Gpio_SetDirection(PL_PORT_REG_t* port,uint8_t channel,uint8_t pinNum,Pl_Pin_mode_t direction)
{
	switch (direction)
	{
		case PL_INPUT:
			if(channel == PL_CH1) 			port->CH1_TRI_REG |= 1<<pinNum;
        	else if(channel==PL_CH2) 		port ->CH2_TRI_REG |= 1<<pinNum;
		break;
		case PL_OUTPUT:
			if(channel == PL_CH1) 			port->CH1_TRI_REG &= ~(1<<pinNum);
        	else if(channel==PL_CH2) 		port ->CH2_TRI_REG &= ~(1<<pinNum);
		break;
	}

}

void PL_Gpio_GlobalInterruptEnable(PL_PORT_REG_t* port)
{
	static uint32_t enableMask = 0x80000000;

	port->GLOBAL_INTR_REG |= enableMask;

}

void PL_Gpio_InterruptEnable(PL_PORT_REG_t* port,uint8_t channel)
{
	 uint32_t enableMask = 0;
	 switch(channel)
	 {
	 case PL_CH1:
		 enableMask = 0x01;
		 break;
	 case PL_CH2:
		 enableMask = 0x02;
		 break;
	 }
	 port ->INTR_ENABLE_REG |= enableMask;
}
void PL_Gpio_InterruptDisable(PL_PORT_REG_t* port, uint8_t channel)
{
	uint32_t enableMask = 0;
	 switch(channel)
	 {
	 case PL_CH1:
		 enableMask = ~(1<<PL_CH1);
		 break;
	 case PL_CH2:
		 enableMask = ~(1<<PL_CH2);
		 break;
	 }
	 port ->INTR_ENABLE_REG &= enableMask;

}

void PL_Gpio_ClearInterrupt(PL_PORT_REG_t* port,uint8_t channel)
{
	 uint32_t clearMask=0;

	switch(channel)
	{
	case PL_CH1:
		clearMask = 0x01;
		break;
	case PL_CH2:
		clearMask = 0x02;
		break;
	}
	port ->INTR_STATUS_REG |= clearMask;
}

