/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 5/9/2023              ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : NVIC_program          ****************/
/**************************************************************/

/****************************< LIB ****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************************< MCAL ****************************/
#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"

/*****************< Functions Implementations *****************/
Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_t IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(IRQn < MAX_NUMBER_INTERRUPTS)
    {
        if(IRQn < 32)
        {
            NVIC_ISER0 = (1 << IRQn);
        }
        else if(IRQn < 64)
        {
            NVIC_ISER1 = (1 << (IRQn - 32));
        }
        else
        {
            NVIC_ISER2 = (1 << (IRQn - 64));
        }
    }
    else
    {
        return Local_FunctionStatus;
    }

    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_t IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(IRQn < MAX_NUMBER_INTERRUPTS)
    {
        if(IRQn < 32)
        {
            NVIC_ICER0 = (1 << IRQn);
        }
        else if(IRQn < 64)
        {
            NVIC_ICER1 = (1 << (IRQn - 32));
        }
        else
        {
            NVIC_ICER2 = (1 << (IRQn - 64));
        }
    }
    else
    {
        return Local_FunctionStatus;
    }

    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}

u32 MCAL_NVIC_GetPendingIRQ(IRQn_t IRQn)
{
    u32 Local_PendingStatus = 0;

    if(IRQn < MAX_NUMBER_INTERRUPTS)
    {
        if(IRQn < 32)
        {
            Local_PendingStatus = (NVIC_ISPR0 >> IRQn) & 1;
        }
        else if(IRQn < 64)
        {
            Local_PendingStatus = (NVIC_ISPR1 >> (IRQn - 32)) & 1;
        }
        else
        {
            Local_PendingStatus = (NVIC_ISPR2 >> (IRQn - 64)) & 1;
        }
    }

    return Local_PendingStatus;
}

Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_t IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(IRQn < MAX_NUMBER_INTERRUPTS)
    {
        if(IRQn < 32)
        {
            NVIC_ISPR0 = (1 << IRQn);
        }
        else if(IRQn < 64)
        {
            NVIC_ISPR1 = (1 << (IRQn - 32));
        }
        else
        {
            NVIC_ISPR2 = (1 << (IRQn - 64));
        }
    }
    else
    {
        return Local_FunctionStatus;
    }

    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_t IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(IRQn < MAX_NUMBER_INTERRUPTS)
    {
        if(IRQn < 32)
        {
            NVIC_ICPR0 = (1 << IRQn);
        }
        else if(IRQn < 64)
        {
            NVIC_ICPR1 = (1 << (IRQn - 32));
        }
        else
        {
            NVIC_ICPR2 = (1 << (IRQn - 64));
        }
    }
    else
    {
        return Local_FunctionStatus;
    }

    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_SetPriority(IRQn_t IQRn, u8 Copy_Priority)
{
    Std_ReturnType LocalFunctionStatus = E_NOT_OK;

    //Write the vector key to the SCB_AIRCR register to enable writing to the priority registers
    //Write selection of the split of group priority from subpriority to the SCB_AIRCR register
    SCB_AIRCR = SCB_AIRCR_KEY | (NVIC_0GROUP_16SUB << 8);

    if(IQRn < MAX_NUMBER_INTERRUPTS)
    {
        if(Copy_Priority < MAX_PRIORITY)
        {
            NVIC_IP[IQRn] = Copy_Priority;
            LocalFunctionStatus = E_OK;
        }
    }
    else
    {
        return LocalFunctionStatus;
    }

    return LocalFunctionStatus;
}

u8 MCAL_NVIC_GetPriority(IRQn_t IQRn)
{
    u8 LocalPriority = 0;

    if(IQRn < MAX_NUMBER_INTERRUPTS)
    {
        LocalPriority = NVIC_IP[IQRn];
    }

    return LocalPriority;
}

Std_ReturnType MCAL_NVIC_SetPriorityGrouping(IRQn_t IQRn, u8 Copy_GroupPriority, u8 Copy_SubPriority)
{
    Std_ReturnType LocalFunctionStatus = E_NOT_OK;

    u8 MaxGroupPriority;
    u8 MaxSubPriority;

    #if (NVIC_GROUP_SUB_PRIORITY == NVIC_16GROUP_0SUB)
        MaxGroupPriority = 16;
        MaxSubPriority = 0;
    #elif (NVIC_GROUP_SUB_PRIORITY == NVIC_8GROUP_2SUB)
        MaxGroupPriority = 8;
        MaxSubPriority = 2;
    #elif (NVIC_GROUP_SUB_PRIORITY == NVIC_4GROUP_4SUB)
        MaxGroupPriority = 4;
        MaxSubPriority = 4;
    #elif (NVIC_GROUP_SUB_PRIORITY == NVIC_2GROUP_8SUB)
        MaxGroupPriority = 2;
        MaxSubPriority = 8;
    #elif (NVIC_GROUP_SUB_PRIORITY == NVIC_0GROUP_16SUB)
        MaxGroupPriority = 0;
        MaxSubPriority = 16;
    #else
        #error "Wrong NVIC_GROUP_SUB_PRIORITY Configuration"
    #endif

    SCB_AIRCR = SCB_AIRCR_KEY | (NVIC_GROUP_SUB_PRIORITY << 8);

    if(IQRn < MAX_NUMBER_INTERRUPTS)
    {
        if(Copy_GroupPriority < MaxGroupPriority && Copy_SubPriority < MaxSubPriority)
        {
            NVIC_IP[IQRn] = (Copy_GroupPriority << 4) | Copy_SubPriority;
            LocalFunctionStatus = E_OK;
        }
    }
    else
    {
        return LocalFunctionStatus;
    }

    return LocalFunctionStatus;
}

u32 MCAL_NVIC_GetActive(IRQn_t IRQn)
{
    u32 Local_ActiveStatus = 0;

    if(IRQn < MAX_NUMBER_INTERRUPTS)
    {
        if(IRQn < 32)
        {
            Local_ActiveStatus = (NVIC_IABR0 >> IRQn) & 1;
        }
        else if(IRQn < 64)
        {
            Local_ActiveStatus = (NVIC_IABR1 >> (IRQn - 32)) & 1;
        }
        else
        {
            Local_ActiveStatus = (NVIC_IABR2 >> (IRQn - 64)) & 1;
        }
    }

    return Local_ActiveStatus;
}

/**************************************************************/
