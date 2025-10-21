/****************************************/
/* Author	: Mostafa Samy Mohammed     */
/* Date		: 02-11-2024                */
/* Filename	: main.c                    */
/* Description	: main file             */
/****************************************/

/******************< LIB ****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*****************< MCAL ****************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "UART_interface.h"

/**
 * Smart garage door system main function implementation
 *  */
int main(void)
{
    MCAL_RCC_InitSysClk();
    
    // Enable GPIOA peripheral for IR sensors
    MCAL_RCC_EnablePeripheral(RCC_APB2, 2);

    MCAL_GPIO_SetPinMode(GPIOA, GPIO_PIN0, GPIO_INPUT_PULL_UP_DOWN);
    MCAL_GPIO_SetPinMode(GPIOA, GPIO_PIN1, GPIO_INPUT_PULL_UP_DOWN);

    // Enable Rx, Tx pins in GPIOA for UART1
    MCAL_GPIO_SetPinMode(GPIOA, GPIO_PIN9, GPIO_AF_OUTPUT_PUSH_PULL_50MHZ);
    MCAL_GPIO_SetPinMode(GPIOA, GPIO_PIN10, GPIO_INPUT_FLOATING);

    // Enable UART1 peripheral for communication
    MCAL_RCC_EnablePeripheral(RCC_APB2, 14);

    // Initialize UART1 with baud rate 9600, 8-bit word length, 1 stop bit, no parity, TX mode, oversampling 16
    UART_Init(1, 9600, UART_WORD_LENGTH_8, UART_STOP_BITS_1, UART_PARITY_NONE, UART_MODE_TX, UART_OVERSAMPLING_16);

    while(1)
    {
        // Check if the IR sensor 1 is triggered
        if(MCAL_GPIO_GetPinValue(GPIOA, GPIO_PIN0) == GPIO_HIGH)
        {
            // Send the command to open the garage door
            UART_SendData(1, 'O');
        }

        // Check if the IR sensor 2 is triggered
        if(MCAL_GPIO_GetPinValue(GPIOA, GPIO_PIN1) == GPIO_HIGH)
        {
            // Send the command to close the garage door
            UART_SendData(1, 'C');
        }
    }
    
}