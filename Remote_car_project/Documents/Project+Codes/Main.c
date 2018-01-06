#include "timer.h"
#include "Uart.h" 
#include "GPIO.h"
#include "pwm.h"
#include "pwm1.h"
#include "pwm2.h"
#include "pwm3.h"
#define MAX_TIME 7500

#define SYSCTL_RCGC_GPIO_R (*((volatile unsigned long *)0x400FE608))
#define GPIO_PORTB_DATA_R (*((volatile  unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R (*((volatile unsigned long *)0x40005400))
//#define GPIO_PORTB_DEN_R (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_CLK_EN 0x02
#define GPIO_PORTB_PINS_EN 0xFF
#define DELAY 200

void GPIO_INIT(void)
{
    SYSCTL_RCGC_GPIO_R |=0x2F; // Enable clock for port A, B, C and F

    GPIO_PORTF_DEN_R |= RED; // Port F for Led
    GPIO_PORTF_DIR_R = RED;

    GPIO_PORTA_DIR_R = TRIGGER1; // Port A for Right Sensor
    GPIO_PORTA_DEN_R |= (ECHO1)|(TRIGGER1);


}
//void SystemInit(void){};



void UART_INIT (void)
{
    SYSCTL_RCGCUART_R |= 0x00000008; // Clock for UART 3
    SYSCTL_RCGC_GPIO_R |= 0x00000004; // Clock for port C
    GPIO_PORTC_DEN_R |= 0x000000C0; // Set Digital Enable on PC6 and PC7
    GPIO_PORTC_AFSEL_R |= 0x000000C0; // Set Alternate Func on PC6 and PC7 
    GPIO_PORTC_PCTL_R |= (0x01000000|0x10000000); // Set 6 HalfByte or 7 HalfByte
    UART3_CTL_R &= ~(0x00000001); // Disable Uart	
    UART3_IBRD_R = 104; // IBRD = int (16,000,000 / (16 * 9600)) = int (104.16406)	
    UART3_FBRD_R = 11 ; // FBRD = int (0.16406 * 64 + 0.5 ) = 11
    UART3_LCRH_R = (0x00000060); // 8 bit word Length or Enable Uart Fifo
    UART3_CC_R = 0x00000000; // Use System Clock for Uar
    UART3_CTL_R |= 0x00000001; //Enable Uart
    UART3_CTL_R |= 0x100; //Enable Transmitter
    UART3_CTL_R |= 0x200; // Enable Receiver
    UART3_INT_CLEAR_R &= ~(0X0780);
    UART3_INT_MASK_R |= 0X010;
    NVIC_EN1_R = NIVC_EN1_INT33;
}
// UART3 Interrupt Handler



// Output 8-bit to serial port
void UART_Tx(unsigned char data) 
{
    while ((UART3_FR_R & UART_FR_TXFF) != 0) ;
    UART3_DR_R = data ;
}

// Output a character string to serial port
void UART_Tx_String (char *pt )
{
    while (* pt )
    {
        UART_Tx(* pt ) ;
        pt++;
    }
}

void delay(unsigned long count)
{
    int i;
    for(i=0;i<count;i++);
}
void Timer0A_Init(void)

{
    //Timer configuration for PB6
    RCGC_GPIO_R0 |= CLOCK_GPIOF0;
    RCGC_TIMER_R0 |= 0x01;

    //GPIO_PORTB_LOCK_R0 = 0x4C4F434B;
    //GPIO_PORTB_CR_R0 |= 0x01;	
    GPIO_PORTB_AFSEL_R0 |= 0x00000040;
    GPIO_PORTB_PCTL_R0 |=  0x07000000;
    GPIO_PORTB_DEN_R0 |=   0x00000040;

    GPTM_CONTROL_R0 &= ~(TIM_A_ENABLE0);
    GPTM_CONFIG_R0 |= TIM_16_BIT_CONFIG0;



    GPTM_TA_MODE_R0 |= TIM_PWM_MODE0;
    GPTM_TA_MODE_R0 &= ~(TIM_CAPTURE_MODE0);
    GPTM_TA_IL_R0 = TIM_A_INTERVAL0;

    GPTM_TA_MATCH_R0 = TIM_A_MATCH0 ;

    GPTM_CONTROL_R0 |= TIM_A_ENABLE0;

}

void Timer1A_Init(void)

{
    //Timer configuration for PB4
    RCGC_GPIO_R |= CLOCK_GPIOB;
    RCGC_TIMER_R |= 0x02;

    GPIO_PORTB_AFSEL_R |= 0x00000010;
    GPIO_PORTB_PCTL_R |=  0x00070000;
    GPIO_PORTB_DEN_R |=   0x00000010;

    GPTM_CONTROL_R &= ~(TIM_A_ENABLE);
    GPTM_CONFIG_R |= TIM_16_BIT_CONFIG;



    GPTM_TA_MODE_R |= TIM_PWM_MODE;
    GPTM_TA_MODE_R &= ~(TIM_CAPTURE_MODE);
    GPTM_TA_IL_R = TIM_A_INTERVAL;

    GPTM_TA_MATCH_R = TIM_A_MATCH ;

    GPTM_CONTROL_R |= TIM_A_ENABLE;

}


void Timer2A_Init(void)

{
    //timer configuration for PB0
    RCGC_GPIO_R2 |= CLOCK_GPIOB2;
    RCGC_TIMER_R2 |= 0x04;

    GPIO_PORTB_AFSEL_R2 |= 0x00000001;
    GPIO_PORTB_PCTL_R2 |=  0x00000007;
    GPIO_PORTB_DEN_R2 |=   0x00000001;

    GPTM_CONTROL_R2 &= ~(TIM_A_ENABLE2);
    GPTM_CONFIG_R2 |= TIM_16_BIT_CONFIG2;



    GPTM_TA_MODE_R2 |= TIM_PWM_MODE2;
    GPTM_TA_MODE_R2 &= ~(TIM_CAPTURE_MODE2);
    GPTM_TA_IL_R2 = TIM_A_INTERVAL2;

    GPTM_TA_MATCH_R2 = TIM_A_MATCH2 ;

    GPTM_CONTROL_R2 |= TIM_A_ENABLE2;

}


void Timer3A_Init(void)

{
    // timer configuration for PB2
    RCGC_GPIO_R3 |= CLOCK_GPIOB3;
    RCGC_TIMER_R3 |= 0x08;
    //GPIO_PORTF_LOCK_R3 = 0x4C4F434B;
    //GPIO_PORTF_CR_R3 |= 0x04;	

    GPIO_PORTB_AFSEL_R3 |= 0x00000004;
    GPIO_PORTB_PCTL_R3 |=  0x00000700;
    GPIO_PORTB_DEN_R3 |=   0x00000004;

    GPTM_CONTROL_R3 &= ~(TIM_A_ENABLE3);
    GPTM_CONFIG_R3  |= TIM_16_BIT_CONFIG3;
    GPTM_TA_MODE_R3 |= TIM_PWM_MODE3;
    GPTM_TA_MODE_R3 &= ~(TIM_CAPTURE_MODE3);
    GPTM_TA_IL_R3 = TIM_A_INTERVAL3;

    GPTM_TA_MATCH_R3 = TIM_A_MATCH3 ;

    GPTM_CONTROL_R3 |= TIM_A_ENABLE3;

}



void Backward(int duty){
    GPTM_TA_MATCH_R0 = duty ;
    GPTM_TA_MATCH_R = 15999 ;
    GPTM_TA_MATCH_R2 = duty ;
    GPTM_TA_MATCH_R3 = 15999 ;

}

void Forward(int duty){
    GPTM_TA_MATCH_R0 = 15999 ;
    GPTM_TA_MATCH_R = duty ;
    GPTM_TA_MATCH_R2 = 15999 ;
    GPTM_TA_MATCH_R3 = duty ;

}


void Left  (int duty){
    GPTM_TA_MATCH_R0 = 15999 ;
    GPTM_TA_MATCH_R = duty ;
    GPTM_TA_MATCH_R2 = duty ;
    GPTM_TA_MATCH_R3 = 15999 ;

}


void Right(int duty){
    GPTM_TA_MATCH_R0 = duty ;
    GPTM_TA_MATCH_R = 15999 ;
    GPTM_TA_MATCH_R2 = 15999 ;
    GPTM_TA_MATCH_R3 = duty ;

}


void Stop(void){
    GPTM_TA_MATCH_R0 = 15999 ;
    GPTM_TA_MATCH_R = 15999 ;
    GPTM_TA_MATCH_R2 = 15999 ;
    GPTM_TA_MATCH_R3 = 15999 ;

}

void UART3_Handler(void) {
    int u=0,i=0,lu=0,ru=0;
    unsigned char rx_data;
    unsigned char c;
    while(1){
        UART3_INT_CLEAR_R &= ~(0X010);
        rx_data = UART3_DR_R;
        c=rx_data;	

        if(Right_Distance() < 5.0)
        {
            Stop();
            delay(10000);
            Backward(12000);
            delay(10000);
            Stop();
            u=1;
            lu=0;
            ru=0;
        }

        if(c == 'f' && u==0){	
            Forward(12000);
            lu=0;
            ru=0;
        }
        else
            if(c =='b'){
                u=0;
                Backward(12000);
            }
            else
                if(c =='l' && lu==0){
                    u=0;
                    ru=0;
                    lu=1;
                    Stop();
                    Left(13000);
                    delay(4600000);
                    Stop();
                }
                else
                    if(c =='g' && ru==0){
                        u=0;
                        ru=1;
                        lu=0;
                        Right(13000);
                        delay(4600000);
                        Stop();
                    }
                    else
                        if(c =='s'){
                            u=0;
                            lu=0;
                            ru=0;
                            Stop();
                        }
    }
}
void car_init(void)
{
    Timer0A_Init();
    Timer1A_Init();
    Timer2A_Init();
    Timer3A_Init();
}


void delay_microsecond(unsigned int time) // For Trigger
{
    int i;
    SYSCTL_RCGCTIMER_R |=TIM0_CLK_EN;
    TIMER0_CFG_R =0x04;
    TIMER0_TAMR_R =0x02;
    TIMER0_TAILR_R =16-1;
    TIMER0_ICR_R =0x1;
    TIMER0_CTL_R |=0x01;
    for(i=0; i<time; i++)
    {
        while ((TIMER0_RIS_R &0x1)==0);
        TIMER0_ICR_R =0x01;
    }

}
float Right_Distance(void) // Port A
{
    unsigned int counter=0;
    float distance=0;

    GPIO_PORTA_DATA_R &=~TRIGGER1;
    delay_microsecond(10);
    GPIO_PORTA_DATA_R |=TRIGGER1;
    delay_microsecond(10);
    GPIO_PORTA_DATA_R &=~TRIGGER1;
    delay_microsecond(10);
    counter=0;
    while ((GPIO_PORTA_DATA_R & ECHO1)==0)
    {
    }
    while (((GPIO_PORTA_DATA_R & ECHO1) !=0) & (counter< MAX_TIME))
    {
        counter++;
        delay_microsecond(1);
    }
    distance =(float)(counter *(float) 0.0170000);
    return distance;
}

int main(void)
{
    car_init();
    GPIO_INIT();

    SYSCTL_RCGC_GPIO_R |= GPIO_PORTB_CLK_EN;

    GPIO_PORTB_DIR_R|=GPIO_PORTB_PINS_EN;
    GPIO_PORTB_DEN_R  |= GPIO_PORTB_PINS_EN;
    UART_INIT();


    while(1)
    {

    }

}


