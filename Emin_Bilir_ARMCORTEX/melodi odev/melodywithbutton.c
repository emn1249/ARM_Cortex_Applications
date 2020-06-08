#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/pin_map.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "inc/hw_gpio.h"


void playsound(uint32_t frekans, uint32_t zaman)
{
uint32_t PWMclock = ROM_SysCtlClockGet() / 4 ; 
uint32_t periyod = (PWMclock/frekans) - 1; 
float numOfCyc = ROM_SysCtlClockGet()/1000.0; 
uint32_t counter = zaman * numOfCyc / 3; 
ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, periyod); 
ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,  0.5 * periyod);
ROM_PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true); 
ROM_PWMGenEnable(PWM1_BASE, PWM_GEN_1); 
ROM_SysCtlDelay(counter); 
ROM_PWMGenDisable(PWM1_BASE, PWM_GEN_1); 

}
void noteC(int y){playSound(523, y);}
void noteD(int y){playSound(587, y);}
void noteE(int y){playSound(659, y);}
void noteF(int y){playSound(698, y);}
void noteG(int y){playSound(784, y);}
void noteA(int y){playSound(880, y);}
void noteB(int y){playSound(988, y);}

void melodi_H_Button(int x)
{
noteC(x*100);	noteB(x*250);
noteG(x*350);	noteF(300);

}
void melodi_J_Button(int y)
{
noteA(y*100);	noteD(250);
noteE(y*200);	noteG(y*400);
}


int main(void)
{	
SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOH);//portlari enable etmek icin
SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOJ);

	GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PINS_ALL); //input olark ayarlamak icin
	GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PINS_ALL); //

		
ROM_SysCtlClockSet (SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);//saati direk crystal ile eşleştirmek için
ROM_SysCtlPWMClockSet(SYSCTL_PWMDIV_4);// Set the PWM clock configuration.
ROM_SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);//GPIOA ve PW1 aktif etmek 
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_1,PWM_GEN_MODE_DOWN);//saymak için configure etmek
ROM_GPIOPinConfigure(GPIO_PA6_M1PWM2);
ROM_GPIOPinTypePWM(GPIO_PORTA_BASE,GPIO_PIN_6);

	
for (;;)
{
melodi_H_Button(GPIOPinRead(GPIO_PORTH_BASE,GPIO_PINS_ALL));
melodi_J_Button(GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PINS_ALL));
ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);		
		

}

	return 0;


}

