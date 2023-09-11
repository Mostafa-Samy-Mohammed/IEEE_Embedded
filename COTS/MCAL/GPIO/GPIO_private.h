/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.3                   ****************/
/*********** File Name : GPIO_private          ****************/
/**************************************************************/

/****************************< LIB ****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/**
 * @defgroup GPIO_Base_Addresses
 * @brief Base addresses of General Purpose Input/Output (GPIO) Ports Registers.
 * @{ 
*/
#define GPIO_PortA_BASE_ADDRESS         0x40010800U
#define GPIO_PortB_BASE_ADDRESS         0x40010C00U
#define GPIO_PortC_BASE_ADDRESS         0x40011000U
/** @} */ //End of GPIO_Base_Addresses

/**
 * @defgroup GPIO_Rgisters_Addresses
 * @brief Register addresses for GPIO registers.
 * @{
*/

/**************< REGISTERS FOR ALL PORT OF GPIO ***************/
typedef struct GPIO_REGISTERS
{
    u32 CRL;        /**< CONFIGURATION REGISTER LOW */
    u32 CRH;        /**< CONFIGURATION REGISTER HIGH */
    u32 IDR;        /**< INPUT DATA REGISTER */
    u32 ODR;        /**< OUTPUT DATA REGISTER */
    u32 BSR;        /**< BIT SET/RESET REGISTER */
    u32 BRR;        /**< BIT RESET REGISTER */
    u32 LCK;        /**< CONFIGURATION LOCK REGISTER */

} GPIO_REGISTER;

/*********< REGISTERS ADDRESSES FOR ALL PORTs OF GPIO *********/
#define GPIO_PORTA_REG                  (GPIO_REGISTER*)(GPIO_PortA_BASE_ADDRESS)
#define GPIO_PORTB_REG                  (GPIO_REGISTER*)(GPIO_PortB_BASE_ADDRESS)
#define GPIO_PORTC_REG                  (GPIO_REGISTER*)(GPIO_PortC_BASE_ADDRESS)

/** @} */ //End of GPIO_Registers_Addresses


#endif // GPIO_PRIVATE_H
