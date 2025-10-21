/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 5/9/2023              ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : NVIC_interface        ****************/
/**************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

typedef u8      IRQn_t;

Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_t IRQn);
Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_t IRQn);

u32 MCAL_NVIC_GetPendingIRQ(IRQn_t IRQn);
Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_t IRQn);
Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_t IRQn);

u32 MCAL_NVIC_GetActive(IRQn_t IRQn);

Std_ReturnType MCAL_NVIC_SetPriority(IRQn_t IRQn, u8 Copy_Priority);
u8 MCAL_NVIC_GetPriority(IRQn_t IRQn);

Std_ReturnType MCAL_NVIC_SetPriorityGrouping(IRQn_t IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority);


#endif /* NVIC_INTERFACE_H */
