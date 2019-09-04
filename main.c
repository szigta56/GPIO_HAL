/*
 * main.c
 *
 *  Created on: 2019. szept. 4.
 *      Author: szigta56
 */

#include "mygpio.h"
#include "xscugic.h"

#define PORT0   PS_GPIO
#define PORT1   PL_LED
#define PORT2   PL_BUTTON

#define PS_RED_LED 	    PS_PIN20
#define PS_GREEN_LED 	PS_PIN21
#define PS_BUTTON	    PS_PIN0

#define PS_CH1          PS_BANK0
#define PS_CH2          PS_BANK1

#define PL_GREEN_LED    PL_CH1
#define PL_RED_LED      PL_CH2
#define PL_CH_WIDTH     1u

static XScuGic ScuGic;
static XScuGic_Config *ScuGic_ConfigPointer;

void Button_ISR(void *data);


int main ()
{

	Gpio_Init();
	Gpio_Write(PORT0,PS_TYPE_GPIO,PS_CH2,PS_RED_LED,1);
	//Gpio_SetDirection(PORT0,PS_TYPE_GPIO,PS_CH2,PS_GREEN_LED,INPUT);

	ScuGic_ConfigPointer = XScuGic_LookupConfig(XPAR_PS7_SCUGIC_0_DEVICE_ID);

	XScuGic_CfgInitialize(&ScuGic,ScuGic_ConfigPointer,XPAR_SCUGIC_0_CPU_BASEADDR);
	XScuGic_Connect(&ScuGic,52,&Button_ISR,PS_GPIO);
	XScuGic_Enable(&ScuGic,52);

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,(Xil_ExceptionHandler)XScuGic_InterruptHandler,&ScuGic);
	Xil_ExceptionEnable();

	for (;;)
	{

	}
	return 0;
}

void Button_ISR(void *data)
{

	Gpio_Write(PORT1,PL_TYPE_GPIO,PL_GREEN_LED,0,!Gpio_Read(PORT1,PL_TYPE_GPIO,PL_GREEN_LED,0));
	Gpio_ClearInterrupt(PORT0,PS_TYPE_GPIO,PS_BANK0,PS_BUTTON);

}

