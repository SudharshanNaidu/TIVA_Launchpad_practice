#define	SYSCTL_RCGCUART_R 				(*((volatile unsigned long*) 0x400FE618 ))
	
// Uart 3
#define UART3_CTL_R 							(*((volatile unsigned long*) (0x4000F000 + 0x030)))
#define UART3_IBRD_R 							(*((volatile unsigned long*) (0x4000F000 + 0x024)))
#define UART3_FBRD_R							(*((volatile unsigned long*) (0x4000F000 + 0x028)))
#define UART3_LCRH_R 							(*((volatile unsigned long*) (0x4000F000 + 0x02C)))
#define UART3_CC_R 								(*((volatile unsigned long*) (0x4000F000 + 0xFC8)))
#define UART3_FR_R 								(*((volatile unsigned long*) (0x4000F000 + 0x018)))
#define UART3_DR_R 								(*((volatile unsigned long*) (0x4000F000 + 0x000)))
// Uart 3 interrupt configuration
#define UART3_INT_MASK_R 								(*((volatile unsigned long*) (0x4000F000 + 0x038)))
#define UART3_RIS_R 								(*((volatile unsigned long*) (0x4000F000 + 0x03C)))
#define UART3_MIS_R 								(*((volatile unsigned long*) (0x4000F000 + 0x040)))
#define UART3_INT_CLEAR_R 								(*((volatile unsigned long*) (0x4000F000 + 0x044)))
#define UART3_FIFO_LS_R 								(*((volatile unsigned long*) (0x4000F000 + 0x034)))
// NVIC Configuration
#define NVIC_EN1_R			(*((volatile unsigned long*) (0XE000E104)))
#define NIVC_EN1_INT33  0X08000000
//Macro
#define UART_FR_RXFE 0x00000010 // UART Receive FIFO Empty
#define UART_FR_TXFF 0x00000020 // UART Transmit FIFO Full

void UART_INIT (void);
void UART_Tx(unsigned char data);
void UART_Tx_String (char *pt );
