/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 5/9/2024              ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : UART_interface        ****************/
/**************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#define UART_PARITY_NONE                0
#define UART_PARITY_EVEN                1
#define UART_PARITY_ODD                 2

#define UART_STOP_BITS_1                0
#define UART_STOP_BITS_0_5              1
#define UART_STOP_BITS_2                2
#define UART_STOP_BITS_1_5              3

#define UART_WORD_LENGTH_8              0
#define UART_WORD_LENGTH_9              1

#define UART_MODE_TX                    0
#define UART_MODE_RX                    1
#define UART_MODE_TX_RX                 2

#define UART_OVERSAMPLING_16            0
#define UART_OVERSAMPLING_8             1

Std_ReturnType UART_Init(u8 copy_UartNumber, u32 copy_BaudRate, u8 copy_WordLength, u8 copy_StopBits, u8 copy_Parity, u8 copy_Mode, u8 copy_OverSampling);

Std_ReturnType UART_SendData(u8 copy_UartNumber, u8 copy_Data);

u8 UART_ReceiveData(u8 copy_UartNumber);

#endif /* UART_INTERFACE_H */
