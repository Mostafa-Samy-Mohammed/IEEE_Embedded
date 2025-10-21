/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.3                   ****************/
/*********** File Name : GPIO_private          ****************/
/**************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/**
 * @defgroup GPIO_Base_Addresses
 * @brief Base addresses of General Purpose Input/Output (GPIO) Ports Registers.
 * @{ 
*/
#define GPIOA_BASE_ADDRESS         0x40010800
#define GPIOB_BASE_ADDRESS         0x40010C00
#define GPIOC_BASE_ADDRESS         0x40011000
/** @} */ //End of GPIO_Base_Addresses

/**
 * @defgroup GPIO_Rgisters_Addresses
 * @brief Register addresses for GPIO registers.
 * @{
*/

/**************< REGISTERS FOR ALL PORT OF GPIO ***************/
typedef struct GPIO_REGISTERS
{
    volatile u32 CRL;        /**< CONFIGURATION REGISTER LOW */
    volatile u32 CRH;        /**< CONFIGURATION REGISTER HIGH */
    volatile u32 IDR;        /**< INPUT DATA REGISTER */
    volatile u32 ODR;        /**< OUTPUT DATA REGISTER */
    volatile u32 BSR;        /**< BIT SET/RESET REGISTER */
    volatile u32 BRR;        /**< BIT RESET REGISTER */
    volatile u32 LCK;        /**< CONFIGURATION LOCK REGISTER */

} GPIO_REGISTER;

/*********< REGISTERS ADDRESSES FOR ALL PORTs OF GPIO *********/
#define GPIOA_REG                  (GPIO_REGISTER*)(GPIOA_BASE_ADDRESS)
#define GPIOB_REG                  (GPIO_REGISTER*)(GPIOB_BASE_ADDRESS)
#define GPIOC_REG                  (GPIO_REGISTER*)(GPIOC_BASE_ADDRESS)

/** @} */ //End of GPIO_Registers_Addresses


#endif // GPIO_PRIVATE_H
