#define TM_BASE0 0x40030000

#define RCGC_TIMER_R0 *(volatile unsigned long *) 0x400FE604
#define RCGC_GPIO_R0 *(volatile unsigned long *) 0x400FE108
#define CLOCK_GPIOF0 0x00000002
#define SYS_CLOCK_FREQUENCY0 16000000


#define GPTM_CONFIG_R0 *(volatile unsigned long *) (TM_BASE0 + 0x000)
#define GPTM_TA_MODE_R0 *(volatile unsigned long *) (TM_BASE0 + 0x004)
#define GPTM_CONTROL_R0 *(volatile unsigned long *) (TM_BASE0 + 0x00C)
#define GPTM_INT_MASK_R0 *(volatile unsigned long *) (TM_BASE0 + 0x018)
#define GPTM_INT_CLEAR_R0 *(volatile unsigned long *) (TM_BASE0 + 0x024)
#define GPTM_TA_IL_R0 *(volatile unsigned long *) (TM_BASE0 + 0x028)
#define GPTM_TA_MATCH_R0 *(volatile unsigned long *) (TM_BASE0 + 0x030)
	
#define GPIO_PORTB_AFSEL_R0 *((volatile unsigned long *) 0x40005420)
#define GPIO_PORTB_PCTL_R0 *((volatile unsigned long *) 0x4000552C)
#define GPIO_PORTB_DEN_R0 *((volatile unsigned long *) 0x4000551C)
//#define GPIO_PORTB_LOCK_R0       (*((volatile unsigned long *)0x40005520))
//#define GPIO_PORTB_CR_R0         (*((volatile unsigned long *)0x40005524))	

#define TIM_16_BIT_CONFIG0 0x00000004
#define TIM_PERIODIC_MODE0 0x00000002
#define TIM_A_ENABLE0      0x00000001


#define TIM_PWM_MODE0      0x0000000A
#define TIM_CAPTURE_MODE0  0x00000004

#define TIM_A_INTERVAL0 16000
#define TIM_A_MATCH0 12000



void Timer0A_Init(void);