//#define	SYSCTL_RCGC_GPIO_R 					(*((volatile unsigned long*) 0x400FE608 ))
	
//PC6 Bluetooth Transmitter
//PC7 Bluetooth Receiver
#define GPIO_PORTC_LOCK_R 					(*((volatile unsigned long*)(0x40006000 + 0x520)))
#define GPIO_PORTC_CR_R 						(*((volatile unsigned long*)(0x40006000 + 0x524)))
#define GPIO_PORTC_AFSEL_R 					(*((volatile unsigned long*)(0x40006000 + 0x420)))
#define GPIO_PORTC_PCTL_R 					(*((volatile unsigned long*)(0x40006000 + 0x52C)))
#define GPIO_PORTC_DEN_R 						(*((volatile unsigned long*)(0x40006000 + 0x51C)))

// ***************Right Ulrasonic Sensor***************
// PA2 => Echo, PA3 => Trigger, PF1 => Red
#define GPIO_PORTA_DATA_R 				(*(( volatile unsigned long *) 0x400073FC ))
#define GPIO_PORTA_DIR_R 					(*(( volatile unsigned long *) 0x40007400 ))
#define GPIO_PORTA_DEN_R 					(*(( volatile unsigned long *) 0x4000751C ))
	

#define GPIO_PORTF_DATA_R 				(*(( volatile unsigned long *) 0x400253FC ))
#define GPIO_PORTF_DIR_R 					(*(( volatile unsigned long *) 0x40025400 ))
#define GPIO_PORTF_DEN_R 					(*(( volatile unsigned long *) 0x4002551C ))

#define RED 0x02   	//

#define ECHO1 0x2  //PD0 Output of sensor
#define TRIGGER1 0x1               //PD1 input of sensor throught timer               


                          


    

    

#define delay_debounce 16000

void GPIO_INIT(void);
void delay(unsigned long counter);