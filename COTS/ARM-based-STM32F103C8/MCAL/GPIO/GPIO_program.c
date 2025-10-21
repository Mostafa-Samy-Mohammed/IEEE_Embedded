/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.5                   ****************/
/*********** File Name : GPIO_program          ****************/
/**************************************************************/

/****************************< LIB ****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************************< MCAL ****************************/
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"

/*****************< Functions Implementations *****************/
void MCAL_bGPIO_SetPinMode(u8 copy_Port, u8 copy_Pin, u8 copy_Mode)
{
    switch(copy_Port)
    {
        case GPIOA:
            if(copy_Pin < 8)
            {
                (GPIOA_REG)->CRL &= ~(0b1111 << (copy_Pin * 4));
                (GPIOA_REG)->CRL |= (copy_Mode << (copy_Pin * 4));
            }
            else if(copy_Pin < 16)
            {
                copy_Pin -= 8;
                (GPIOA_REG)->CRH &= ~(0b1111 << (copy_Pin * 4));
                (GPIOA_REG)->CRH |= (copy_Mode << (copy_Pin * 4));
            }
            break;

        case GPIOB:
            if(copy_Pin < 8)
            {
                (GPIOB_REG)->CRL &= ~(0b1111 << (copy_Pin * 4));
                (GPIOB_REG)->CRL |= (copy_Mode << (copy_Pin * 4));
            }
            else if(copy_Pin < 16)
            {
                copy_Pin -= 8;
                (GPIOB_REG)->CRH &= ~(0b1111 << (copy_Pin * 4));
                (GPIOB_REG)->CRH |= (copy_Mode << (copy_Pin * 4));
            }
            break;

        case GPIOC:
            if(copy_Pin < 8)
            {
                (GPIOC_REG)->CRL &= ~(0b1111 << (copy_Pin * 4));
                (GPIOC_REG)->CRL |= (copy_Mode << (copy_Pin * 4));
            }
            else if(copy_Pin < 16)
            {
                copy_Pin -= 8;
                (GPIOC_REG)->CRH &= ~(0b1111 << (copy_Pin * 4));
                (GPIOC_REG)->CRH |= (copy_Mode << (copy_Pin * 4));
            }
            break;
    }
}

void MCAL_GPIO_SetPinValue(u8 copy_Port, u8 copy_Pin, u8 copy_Value)
{
    switch(copy_Port)
    {
        case GPIOA:
            if(copy_Value)
                SET_BIT((GPIOA_REG)->ODR , copy_Pin);
            else
                CLR_BIT((GPIOA_REG)->ODR , copy_Pin);
            break;

        case GPIOB:
            if(copy_Value)
                SET_BIT((GPIOB_REG)->ODR , copy_Pin);
            else
                CLR_BIT((GPIOB_REG)->ODR , copy_Pin);
            break;

        case GPIOC:
            if(copy_Value)
                SET_BIT((GPIOC_REG)->ODR , copy_Pin);
            else
                CLR_BIT((GPIOC_REG)->ODR , copy_Pin);
            break;
    }
}

u8 MCAL_GPIO_GetPinValue(u8 copy_Port, u8 copy_Pin)
{
    u8 Local_Value;
    switch(copy_Port)
    {
        case GPIOA:
            Local_Value = GET_BIT((GPIOA_REG)->IDR , copy_Pin);
            break;

        case GPIOB:
            Local_Value = GET_BIT((GPIOB_REG)->IDR , copy_Pin);
            break;

        case GPIOC:
            Local_Value = GET_BIT((GPIOC_REG)->IDR , copy_Pin);
            break;
    }

    return Local_Value;
}
