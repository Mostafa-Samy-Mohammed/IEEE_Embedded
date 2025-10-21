/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.5                   ****************/
/*********** File Name : RCC_program           ****************/
/**************************************************************/

/****************************< LIB ****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************************< MCAL ****************************/
#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"

/*****************< Functions Implementations *****************/
Std_ReturnType MCAL_RCC_InitSysClk(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
    #if RCC_CLK_SRC == RCC_CLK_SRC_HSI
        SET_BIT(RCC_CR, RCC_CR_HSION);
        while(!GET_BIT(RCC_CR, 1));

        RCC_CFGR = 0x00000000;

        Local_FunctionStatus = E_OK;
    
    #elif RCC_CLK_SRC == RCC_CLK_SRC_HSE_RC
        SET_BIT(RCC_CR, 16);
        SET_BIT(RCC_CR, 18);
        while(!GET_BIT(RCC_CR, 17));

        RCC_CFGR = 0x00000001;

        Local_FunctionStatus = E_OK;

    #elif RCC_CLK_SRC == RCC_CLK_SRC_HSE_CRY
        SET_BIT(RCC_CR, 16);
        CLR_BIT(RCC_CR, 18);
        while(!GET_BIT(RCC_CR, 17));
    
        RCC_CFGR = 0x00000001;

        Local_FunctionStatus = E_OK;

    #elif RCC_CLK_SRC == RCC_CLK_SRC_PLL

        #if RCC_PLL_SRC == PLL_HALF_HSI
            SET_BIT(RCC_CR, 0);
            while(!GET_BIT(RCC_CR, 1));
            
            RCC_CFGR = 0x00000002;
            
            Local_FunctionStatus = E_OK;
        
        #elif RCC_PLL_SRC == PLL_HALF_HSE
            SET_BIT(RCC_CR, 16);
            SET_BIT(RCC_CR, 18);
            while(!GET_BIT(RCC_CR, 17));
            
            RCC_CFGR = 0x00000002;
            
            Local_FunctionStatus = E_OK;
        
        #elif RCC_PLL_SRC == PLL_HSE
            SET_BIT(RCC_CR, 16);
            CLR_BIT(RCC_CR, 18);
            while(!GET_BIT(RCC_CR, 17));
            
            RCC_CFGR = 0x00000002;
            
            Local_FunctionStatus = E_OK;

        #else
            Local_FunctionStatus = E_NOT_OK;

            #error "Wrong RCC_CLK_SRC Configuration"

        #endif

    #else
        Local_FunctionStatus = E_NOT_OK;

        #error "Wrong RCC_CLK_SRC Configuration"

    #endif

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_EnablePeripheral(u8 copy_BusId, u8 copy_PerId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
    if(copy_PerId < 32)
    {
        switch (copy_BusId)
        {
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, copy_PerId);
            Local_FunctionStatus = E_OK;
            break;
        
        case RCC_APB1:
            SET_BIT(RCC_APB2ENR, copy_PerId);
            Local_FunctionStatus = E_OK;
            break;

        case RCC_APB2:
            SET_BIT(RCC_APB1ENR, copy_PerId);
            Local_FunctionStatus = E_OK;
            break;
        default:
            break;
        }
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
        /* error "Wrong Peripheral ID" */
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_DisablePeripheral(u8 copy_BusId, u8 copy_PerId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
    if(copy_PerId < 32)
    {
        switch (copy_BusId)
        {
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, copy_PerId);
            Local_FunctionStatus = E_OK;
            break;
        
        case RCC_APB1:
            CLR_BIT(RCC_APB2ENR, copy_PerId);
            Local_FunctionStatus = E_OK;
            break;

        case RCC_APB2:
            CLR_BIT(RCC_APB1ENR, copy_PerId);
            Local_FunctionStatus = E_OK;
            break;
        default:
            break;
        }
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
        /* error "Wrong Peripheral ID" */
    }

    return Local_FunctionStatus;
}

/**************< End of Function Implementations **************/