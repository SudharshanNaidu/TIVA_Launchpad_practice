#define TM_BASE 0x40031000

#define RCGC_TIMER_R *(volatile unsigned long *) 0x400FE604
#define RCGC_GPIO_R *(volatile unsigned long *) 0x400FE108
#define CLOCK_GPIOB 0x00000002       //Port B clock control
#define SYS_CLOCK_FREQUENCY 16000000

//General purpose timer register definitions
//#define GPTM_TA_PRESCALE_R *(volatile unsigned long *) (TM_BASE + 0x038)
//#define GPTM_TA_PRESCALE_MATCH_R *(volatile unsigned long *) (TM_BASE + 0x040)
#define GPTM_CONFIG_R *(volatile unsigned long *) (TM_BASE + 0x000)
#define GPTM_TA_MODE_R *(volatile unsigned long *) (TM_BASE + 0x004)
#define GPTM_CONTROL_R *(volatile unsigned long *) (TM_BASE + 0x00C)
#define GPTM_INT_MASK_R *(volatile unsigned long *) (TM_BASE + 0x018)
#define GPTM_INT_CLEAR_R *(volatile unsigned long *) (TM_BASE + 0x024)
#define GPTM_TA_IL_R *(volatile unsigned long *) (TM_BASE + 0x028)
#define GPTM_TA_MATCH_R *(volatile unsigned long *) (TM_BASE + 0x030)
	
#define GPIO_PORTB_AFSEL_R *((volatile unsigned long *) 0x40005420)
#define GPIO_PORTB_PCTL_R *((volatile unsigned long *) 0x4000552C)
#define GPIO_PORTB_DEN_R *((volatile unsigned long *) 0x4000551C)

#define TIM_16_BIT_CONFIG 0x00000004
#define TIM_PERIODIC_MODE 0x00000002
#define TIM_A_ENABLE      0x00000001


#define TIM_PWM_MODE      0x0000000A
#define TIM_CAPTURE_MODE  0x00000004

#define TIM_A_INTERVAL 16000
#define TIM_A_MATCH 12000



void Timer1A_Init(void);