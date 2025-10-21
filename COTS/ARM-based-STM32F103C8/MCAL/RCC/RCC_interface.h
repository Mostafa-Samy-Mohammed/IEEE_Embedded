/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.3                   ****************/
/*********** File Name : RCC_interface         ****************/
/**************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB         0
#define RCC_APB1        1
#define RCC_APB2        2

Std_ReturnType MCAL_RCC_InitSysClk(void);
Std_ReturnType MCAL_RCC_EnablePeripheral(u8 copy_BusId, u8 copy_PerId);
Std_ReturnType MCAL_RCC_DisablePeripheral(u8 copy_BusId, u8 copy_PerId);

#endif // RCC_INTERFACE_H