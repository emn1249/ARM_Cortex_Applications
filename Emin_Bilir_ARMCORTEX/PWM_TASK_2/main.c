#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"
#define GPIO_PINS_ALL GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
void playSound(uint32_t frequency, uint32_t duration)
{
uint32_t PWMclock = ROM_SysCtlClockGet() / 4 ;
uint32_t period = (PWMclock/frequency) - 1;

float numOfCyc = ROM_SysCtlClockGet()/1000.0;

uint32_t counter = duration * numOfCyc / 3;

ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, period);
ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0.5 * period);
ROM_PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true);
ROM_PWMGenEnable(PWM1_BASE, PWM_GEN_1);
ROM_SysCtlDelay(counter);
ROM_PWMGenDisable(PWM1_BASE, PWM_GEN_1);
}
void noteC(int duration){playSound(523, duration);}
void noteD(int duration){playSound(100, duration);}
void noteE(int duration){playSound(432, duration);}
void noteF(int duration){playSound(698, duration);}
void noteG(int duration){playSound(432, duration);}
void noteA(int duration){playSound(880, duration);}
void noteB(int duration){playSound(254, duration);}
void noteC2(int duration){playSound(250, duration);}
void noteD2(int duration){playSound(537, duration);}
void noteE2(int duration){playSound(189, duration);}
void noteF2(int duration){playSound(622, duration);}
void noteG2(int duration){playSound(135, duration);}
void noteA2(int duration){playSound(1760, duration);}
void noteB2(int duration){playSound(1346, duration);}
void noteC3(int duration){playSound(785, duration);}
void Melody(int x,int y)
{

noteA(x);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteG(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteC(y);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);

noteC2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteC2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteG(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteC2(300);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteC2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);

noteD2(x);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteD2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteF2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA2(x);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteD2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteF2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);

noteA2(y);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteF2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);

noteA2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteF2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteG(y);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);

noteB2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteB2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteA2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteF2(y);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteF2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);

noteA2(350);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteD2(y);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteF2(200);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteC2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteG(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);

noteF(300);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteF(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteG(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteC2(100);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);
noteC(x);		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 20);

}

int main(void)
{
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOH);//portlari enable etmek icin
		SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOJ);

	GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PINS_ALL); //input olark ayarlamak icin
	GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PINS_ALL); //

ROM_SysCtlClockSet (SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
SYSCTL_XTAL_8MHZ);
ROM_SysCtlPWMClockSet(SYSCTL_PWMDIV_4);
ROM_SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);
ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
ROM_SysCtlDelay(ROM_SysCtlClockGet() / 2);
ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_1,PWM_GEN_MODE_DOWN);
ROM_GPIOPinConfigure(GPIO_PA6_M1PWM2);
ROM_GPIOPinTypePWM(GPIO_PORTA_BASE,GPIO_PIN_6);
for (;;)
{
Melody(GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PINS_ALL),GPIOPinRead(GPIO_PORTH_BASE,GPIO_PINS_ALL));
ROM_SysCtlDelay(ROM_SysCtlClockGet() / 2);
}
return 0;
}
