/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 5/9/2024              ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : UART_program          ****************/
/**************************************************************/

/****************************< LIB ****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************************< MCAL ****************************/
#include "UART_private.h"
#include "UART_interface.h"

/*****************< Functions Implementations *****************/
Std_ReturnType UART_Init(u8 copy_UartNumber, u32 copy_BaudRate, u8 copy_WordLength, u8 copy_StopBits, u8 copy_Parity, u8 copy_Mode, u8 copy_OverSampling)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(copy_UartNumber < 5)
    {
        // Baud Rate Configuration
        f32 Local_Fraction = (f32)(copy_BaudRate - (u32)copy_BaudRate) * 16;
        USART->BRR = (u32)(copy_BaudRate / 16);
        USART->BRR |= (u32)(Local_Fraction * 16) << 4;

        // Word Length Configuration
        if(copy_WordLength == UART_WORD_LENGTH_9)
        {
            SET_BIT(USART->CR1, 12);
        }

        // Stop Bits Configuration
        if(copy_StopBits == UART_STOP_BITS_0_5)
        {
            SET_BIT(USART->CR2, 12);
            SET_BIT(USART->CR2, 13);
        }
        else if(copy_StopBits == UART_STOP_BITS_2)
        {
            SET_BIT(USART->CR2, 13);
        }
        else if(copy_StopBits == UART_STOP_BITS_1_5)
        {
            SET_BIT(USART->CR2, 12);
        }

        // Parity Configuration
        if(copy_Parity == UART_PARITY_EVEN)
        {
            SET_BIT(USART->CR1, 10);
        }
        else if(copy_Parity == UART_PARITY_ODD)
        {
            SET_BIT(USART->CR1, 10);
            SET_BIT(USART->CR1, 9);
        }

        // Mode Configuration
        if(copy_Mode == UART_MODE_TX)
        {
            SET_BIT(USART->CR1, 3);
        }
        else if(copy_Mode == UART_MODE_RX)
        {
            SET_BIT(USART->CR1, 2);
        }
        else if(copy_Mode == UART_MODE_TX_RX)
        {
            SET_BIT(USART->CR1, 3);
            SET_BIT(USART->CR1, 2);
        }

        // Over Sampling Configuration
        if(copy_OverSampling == UART_OVERSAMPLING_8)
        {
            SET_BIT(USART->CR1, 15);
        }

        // Enable UART
        SET_BIT(USART->CR1, 13);

        Local_FunctionStatus = E_OK;
    }
    else
    {
        return Local_FunctionStatus;
    }

    return Local_FunctionStatus;
}

Std_ReturnType UART_SendData(u8 copy_UartNumber, u8 copy_Data)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(copy_UartNumber < 5)
    {
        USART->DR = copy_Data;
        while(GET_BIT(USART->SR, 6) == 0);
        Local_FunctionStatus = E_OK;
    }
    else
    {
        return Local_FunctionStatus;
    }

    return Local_FunctionStatus;
}

u8 UART_ReceiveData(u8 copy_UartNumber)
{
    u8 Local_ReceivedData = 0;

    if(copy_UartNumber < 5)
    {
        while(GET_BIT(USART->SR, 5) == 0);
        Local_ReceivedData = USART->DR;
    }
    else
    {
        return Local_ReceivedData;
    }

    return Local_ReceivedData;
}
