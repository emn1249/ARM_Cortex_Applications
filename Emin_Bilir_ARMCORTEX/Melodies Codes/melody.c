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


void playsound(uint32_t frequency, uint32_t duration)
{
	uint32_t PWMclock = ROM_SysCtlClockGet() / 4 ; // get the current PWM clock value
	uint32_t period = (PWMclock/frequency) - 1; // calculate the period for PWM signal
	float numOfCyc = ROM_SysCtlClockGet()/1000.0; // calculate number of cycles per ms
	uint32_t counter = duration * numOfCyc / 3; // calculate the counter for SysCtlDelay function;
	ROM_PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, period); // set the period of the PWM signal

	// Set the pulse width of PWM1 for a 50% duty cycle:
	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,  0.5 * period);
	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true); // enable PWM1 output
	ROM_PWMGenEnable(PWM1_BASE, PWM_GEN_1); // enable the PWM signal generation
	ROM_SysCtlDelay(counter); // add delay
	ROM_PWMGenDisable(PWM1_BASE, PWM_GEN_1); // disable the PWM signal generation

}
void noteC(int duration){playSound(523, duration);}
void noteD(int duration){playSound(587, duration);}
void noteE(int duration){playSound(659, duration);}
void noteF(int duration){playSound(698, duration);}
void noteG(int duration){playSound(784, duration);}
void noteA(int duration){playSound(880, duration);}
void noteB(int duration){playSound(988, duration);}
void Melody()
{
	noteC(300);noteD(300);noteE(300);
	noteF(300);noteG(300);noteA(300);
	noteB(600);
}
int main(void)
{
	// Set the clocking to run directly from the crystal.
	ROM_SysCtlClockSet (SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);
	// Set the PWM clock configuration.
	ROM_SysCtlPWMClockSet(SYSCTL_PWMDIV_4);
	// Enable GPIOA and PWM module 1
	ROM_SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
	// Configure the PWM generator for count down mode with immediate updates
	// to the parameters.
	ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_1,PWM_GEN_MODE_DOWN);
	//Configure the pin mux to select module 1 PWM generator 1 for GPIO pin PA6
	ROM_GPIOPinConfigure(GPIO_PA6_M1PWM2);
	// set the type of PA6 pin to PWM
	ROM_GPIOPinTypePWM(GPIO_PORTA_BASE,GPIO_PIN_6);
	for (;;)
	{
		// play the melody
		Melody();
		ROM_SysCtlDelay(ROM_SysCtlClockGet() / 2); // add delay
	}

return 0;



}
