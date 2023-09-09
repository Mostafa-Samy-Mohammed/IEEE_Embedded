/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : GPIO_private          ****************/
/**************************************************************/
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

/***********************< REGISTERS ADDRESSES FOR PORT A ***********************/
#define GPIOA_CRL            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x00)))      /**< PORT A CONFIGURATION REGISTER LOW */
#define GPIOA_CRH            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x04)))      /**< PORT A CONFIGURATION REGISTER HIGH */
#define GPIOA_IDR            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x08)))      /**< PORT A INPUT DATA REGISTER */
#define GPIOA_ODR            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x0C)))      /**< PORT A OUTPUT DATA REGISTER */
#define GPIOA_BSR            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x10)))      /**< PORT A BIT SET/RESET REGISTER */
#define GPIOA_BRR            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x14)))      /**< PORT A BIT RESET REGISTER */
#define GPIOA_LCK            (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x18)))      /**< PORT A CONFIGURATION LOCK REGISTER */

/***********************< REGISTERS ADDRESSES FOR PORT B ***********************/
#define GPIOB_CRL            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x00)))      /**< PORT B CONFIGURATION REGISTER LOW */
#define GPIOB_CRH            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x04)))      /**< PORT B CONFIGURATION REGISTER HIGH */
#define GPIOB_IDR            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x08)))      /**< PORT B INPUT DATA REGISTER */
#define GPIOB_ODR            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x0C)))      /**< PORT B OUTPUT DATA REGISTER */
#define GPIOB_BSR            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x10)))      /**< PORT B BIT SET/RESET REGISTER */
#define GPIOB_BRR            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x14)))      /**< PORT B BIT RESET REGISTER */
#define GPIOB_LCK            (*((volatile u32 *)(GPIO_PORTB_BASE_ADDRESS + 0x18)))      /**< PORT B CONFIGURATION LOCK REGISTER */

/***********************< REGISTERS ADDRESSES FOR PORT C ***********************/
#define GPIOC_CRL            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x00)))      /**< PORT C CONFIGURATION REGISTER LOW */
#define GPIOC_CRH            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x04)))      /**< PORT C CONFIGURATION REGISTER HIGH */
#define GPIOC_IDR            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x08)))      /**< PORT C INPUT DATA REGISTER */
#define GPIOC_ODR            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x0C)))      /**< PORT C OUTPUT DATA REGISTER */
#define GPIOC_BSR            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x10)))      /**< PORT C BIT SET/RESET REGISTER */
#define GPIOC_BRR            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x14)))      /**< PORT C BIT RESET REGISTER */
#define GPIOC_LCK            (*((volatile u32 *)(GPIO_PORTC_BASE_ADDRESS + 0x18)))      /**< PORT C CONFIGURATION LOCK REGISTER */

/** @} */ //End of GPIO_Registers_Addresses


#endif // GPIO_PRIVATE_H
