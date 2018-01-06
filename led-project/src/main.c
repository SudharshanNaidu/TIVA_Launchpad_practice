#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "driverlib/gpio.h"
//#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/can.h"

#define LED_RED GPIO_PIN_1
#define LED_BLUE GPIO_PIN_2
#define LED_GREEN GPIO_PIN_3
#define SW2 GPIO_PIN_0
#define SW1 GPIO_PIN_4

int main()
{
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_RED|LED_BLUE|LED_GREEN);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, SW1);

    for (;;) {
        // set the red LED pin high, others low
        if (GPIOPinRead(GPIO_PORTF_BASE,SW1)) {
            GPIOPinWrite(GPIO_PORTF_BASE, LED_RED, LED_RED);
        } else {
            GPIOPinWrite(GPIO_PORTF_BASE, LED_RED, 0);
        }
    }
}

