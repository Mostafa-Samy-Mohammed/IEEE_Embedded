/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 5/9/2024              ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : UART_private          ****************/
/**************************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define USART2_BASE_ADDRESS      0x40013800

//UART Registers
typedef struct
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;
}USART_Register;

#define USART      ((volatile USART_Register*)(USART2_BASE_ADDRESS))

#endif /* UART_PRIVATE_H */
