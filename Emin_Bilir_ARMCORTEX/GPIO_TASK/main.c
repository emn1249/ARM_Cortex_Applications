/*
 * main.c
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"

#define GPIO_PINS_ALL GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
int main(void)

{
	uint8_t countH = 0;
	uint8_t countJ = 0;


	ROM_SysCtlClockSet (SYSCTL_SYSDIV_20 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |SYSCTL_XTAL_8MHZ);

	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);//portlari enable etmek icin
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOJ);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOH);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOE);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOG);


	GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PINS_ALL); //output olarak ayartlamak icin
	GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PINS_ALL);
	GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PINS_ALL);

	GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_6|GPIO_PIN_7); //input olark ayarlamak icin
	GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_6|GPIO_PIN_7); //

	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOC);

		for(;;)
		{
			while(GPIOPinRead(GPIO_PORTH_BASE,GPIO_PIN_7) == GPIO_PIN_7)
			{
				countH=countH + 1;
				GPIOPinWrite (GPIO_PORTA_BASE, GPIO_PINS_ALL, countH);
				SysCtlDelay(SysCtlClockGet() / 20); // delay yapmak
			}
			while(GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_7) == GPIO_PIN_7)
			{
				countJ=countJ + 1;
				GPIOPinWrite (GPIO_PORTE_BASE,  0xFF, countJ);
				SysCtlDelay(SysCtlClockGet() / 20); // delay yapmak
			}

			if(countH>countJ){
			GPIOPinWrite (GPIO_PORTG_BASE, GPIO_PINS_ALL, countH-countJ);

			}
			else{
			GPIOPinWrite (GPIO_PORTG_BASE, GPIO_PINS_ALL, countJ-countH);
			}



		}


	return 0;
}
