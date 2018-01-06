#define TM_BASE2 0x40032000

#define RCGC_TIMER_R2 *(volatile unsigned long *) 0x400FE604
#define RCGC_GPIO_R2 *(volatile unsigned long *) 0x400FE108
#define CLOCK_GPIOB2 0x00000002
#define SYS_CLOCK_FREQUENCY2 16000000

#define GPTM_TA_PRESCALE_R2 *(volatile unsigned long *) (TM_BASE2 + 0x038)
#define GPTM_TA_PRESCALE_MATCH_R2 *(volatile unsigned long *) (TM_BASE2 + 0x040)
#define GPTM_CONFIG_R2 *(volatile unsigned long *) (TM_BASE2 + 0x000)
#define GPTM_TA_MODE_R2 *(volatile unsigned long *) (TM_BASE2 + 0x004)
#define GPTM_CONTROL_R2 *(volatile unsigned long *) (TM_BASE2 + 0x00C)
#define GPTM_INT_MASK_R2 *(volatile unsigned long *) (TM_BASE2 + 0x018)
#define GPTM_INT_CLEAR_R2 *(volatile unsigned long *) (TM_BASE2 + 0x024)
#define GPTM_TA_IL_R2 *(volatile unsigned long *) (TM_BASE2 + 0x028)
#define GPTM_TA_MATCH_R2 *(volatile unsigned long *) (TM_BASE2 + 0x030)
	
#define GPIO_PORTB_AFSEL_R2 *((volatile unsigned long *) 0x40005420)
#define GPIO_PORTB_PCTL_R2 *((volatile unsigned long *) 0x4000552C)
#define GPIO_PORTB_DEN_R2 *((volatile unsigned long *) 0x4000551C)

#define TIM_16_BIT_CONFIG2 0x00000004
#define TIM_PERIODIC_MODE2 0x00000002
#define TIM_A_ENABLE2      0x00000001


#define TIM_PWM_MODE2      0x0000000A
#define TIM_CAPTURE_MODE2  0x00000004

#define TIM_A_INTERVAL2 16000
#define TIM_A_MATCH2 12000



void Timer2A_Init(void);