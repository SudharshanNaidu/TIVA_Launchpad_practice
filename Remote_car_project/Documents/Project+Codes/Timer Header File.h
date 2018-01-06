#define SYSCTL_RCGCTIMER_R 				(*(( volatile unsigned long * ) 0x400FE65C ))
#define TIMER0_CTL_R							(*(( volatile unsigned long * ) 0x4004C00C ))
#define TIMER0_CFG_R				 			(*(( volatile unsigned long * ) 0x4004C000 ))
# define TIMER0_TAMR_R 						(*(( volatile unsigned long * ) 0x4004C004 ))
#define TIMER0_TAILR_R 						(*(( volatile unsigned long * ) 0x4004C028 ))
#define TIMER0_TAPR_R 						(*(( volatile unsigned long * ) 0x4004C038 ))
# define TIMER0_TBMR_R 						(*(( volatile unsigned long * ) 0x4004C008 ))
#define TIMER0_TBILR_R 						(*(( volatile unsigned long * ) 0x4004C02C ))
#define TIMER0_TBPR_R 						(*(( volatile unsigned long * ) 0x4004C03C ))
#define TIMER0_ICR_R 							(*(( volatile unsigned long * ) 0x4004C024 ))
#define TIMER0_IMR_R 							(*(( volatile unsigned long * ) 0x4004C018 ))
#define TIMER0_RIS_R 							(*(( volatile unsigned long * ) 0x4004C01C ))
	
// Macros
#define TIM0_CLK_EN 0x04// enable clock for Timer0
#define TIM0_EN 0x04  // disable Timer0 before setup
#define TIM_16_BIT_EN 0x4 // configure 16_bit timer mode
#define TIM_TAMR_PERIODIC_EN 0x2 // configure periodic mode
#define TIM_FREQ_10usec 0x9F // select prescalaer for
#define TIM0A_INT_CLR 0x1 // clear timeout interrupt
#define PORTS_CLK_EN 0x21 // enable clock for port F
#define LED_RED 0x04 // configure red led ( PF1 )
#define TIM0B_INT_CLR 0x0100 // clear timeout interrupt
#define EN0_INT20 0x00100000// enable interrupt 20
#define TOGGLE_PF3 0x08 // toggle red led ( PF1 )
#define GREEN_RED 0x08 // configure red led ( PF3 )

void GPIO_INIT(void);

float Right_Distance(void);  	 // Right Ultrasonic Sensor Port A


void delay(unsigned long count);
void delay_microsecond(unsigned int time);