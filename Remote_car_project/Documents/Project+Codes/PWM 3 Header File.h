#define TM_BASE3 0x40033000

#define RCGC_TIMER_R3 *(volatile unsigned long *) 0x400FE604
#define RCGC_GPIO_R3 *(volatile unsigned long *) 0x400FE108
#define CLOCK_GPIOB3 0x00000002


#define GPTM_TA_PRESCALE_R3 *(volatile unsigned long *) (TM_BASE3 + 0x038)
#define GPTM_TA_PRESCALE_MATCH_R3 *(volatile unsigned long *) (TM_BASE3 + 0x040)
#define GPTM_CONFIG_R3 *(volatile unsigned long *) (TM_BASE3 + 0x000)
#define GPTM_TA_MODE_R3 *(volatile unsigned long *) (TM_BASE3 + 0x004)
#define GPTM_CONTROL_R3 *(volatile unsigned long *) (TM_BASE3 + 0x00C)
#define GPTM_INT_MASK_R3 *(volatile unsigned long *) (TM_BASE3 + 0x018)
#define GPTM_INT_CLEAR_R3 *(volatile unsigned long *) (TM_BASE3 + 0x024)
#define GPTM_TA_IL_R3 *(volatile unsigned long *) (TM_BASE3 + 0x028)
#define GPTM_TA_MATCH_R3 *(volatile unsigned long *) (TM_BASE3 + 0x030)
	
#define GPIO_PORTB_AFSEL_R3 *((volatile unsigned long *) 0x40005420)
#define GPIO_PORTB_PCTL_R3 *((volatile unsigned long *) 0x4000552C)
#define GPIO_PORTB_DEN_R3 *((volatile unsigned long *) 0x4000551C)
#define GPIO_PORTB_LOCK_R3       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTB_CR_R3         (*((volatile unsigned long *)0x40025524))		

#define TIM_16_BIT_CONFIG3 0x00000004
#define TIM_PERIODIC_MODE3 0x00000002
#define TIM_A_ENABLE3      0x00000001


#define TIM_PWM_MODE3      0x0000000A
#define TIM_CAPTURE_MODE3  0x00000004

#define TIM_A_INTERVAL3 16000
#define TIM_A_MATCH3 12000



void Timer3A_Init(void);