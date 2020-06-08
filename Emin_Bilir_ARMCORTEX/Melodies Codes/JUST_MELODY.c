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
void noteC(int duration){playSound(523, duration);}
void noteD(int duration){playSound(587, duration);}
void noteE(int duration){playSound(659, duration);}
void noteF(int duration){playSound(698, duration);}
void noteG(int duration){playSound(784, duration);}
void noteA(int duration){playSound(880, duration);}
void noteB(int duration){playSound(988, duration);}

#define coefficient 125
void part1()
{
	noteC(100);	noteA(220);
	noteB(350);	noteE(coefficient);	
}
void part2(int x)
{
	noteG(x);		noteA(40);
	noteD(2*coefficient);	noteB(180);	
}void part3(int y,int z)
{
	noteF(240);	noteC(3*coefficient);
	noteD(z);	noteE(y);	
}
int main(void)
{
	ROM_SysCtlClockSet (SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);//saati direk kristalden kullanabilmek için
	ROM_SysCtlPWMClockSet(SYSCTL_PWMDIV_4);//pwm ayarlamak için
	
	ROM_SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);//pwm ayarı yapmak için
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
	
	ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_1,PWM_GEN_MODE_DOWN);//pwm count down ayarlamak ve gpıo pin PA6 ayarlamak 
	ROM_GPIOPinConfigure(GPIO_PA6_M1PWM2);

	ROM_GPIOPinTypePWM(GPIO_PORTA_BASE,GPIO_PIN_6)//PA6 yı pwm olarak seçmek için

	for (;;)
	{
		
		part1();
		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 4);//delay between 2 function
		part2(450);
		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 6);
		part3(120,470);
		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);//finall loop delay

	}

	return 0;


}



