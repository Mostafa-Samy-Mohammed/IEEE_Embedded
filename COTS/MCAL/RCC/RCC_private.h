/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : RCC_private           ****************/
/**************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/**
 * @defgroup RCC_Base_Address
 * @brief Base address of Reset and Clock Control (RCC) Registers.
 * @{
*/
#define RCC_Base_Address    0x40021000
/** @}*/ //End of RCC_Base_Address

/**
 * @defgroup RCC_Registers
 * @brief Structure for Resisters of RCC Peripherals.
 * @{
 */

typedef struct RCC_REGISTERS
{
    u32 CR;          /** RCC Control Register (CR) */
    u32 CFGR;        /** RCC Configuration Register (CFGR) */
    u32 CIR;         /** RCC Clock Interrupt Register (CIR) */
    u32 APB2RSTR;    /** RCC APB2 Peripheral Reset Register (APB2RSTR) */
    u32 APB1RSTR;    /** RCC APB1 Peripheral Reset Register (APB1RSTR) */
    u32 AHBENR;      /** RCC AHB Peripheral Clock Enable Register (AHBENR) */
    u32 APB2ENR;     /** RCC APB2 Peripheral Clock Enable Register (APB2ENR) */
    u32 APB1ENR;     /** RCC APB1 Peripheral Clock Enable Register (APB1ENR) */
    u32 BDCR;        /** RCC Backup Domain Control Register (BDCR) */
    u32 CSR;         /** RCC Control and Status Register (CSR) */

} RCC_REGISTER;
/** @} */ //End of RCC_Registers

/**
 * @defgroup RCC_Registers_Address
 * @brief Pointer to Registers addresses of RCC Peripherals.
 * @{
*/
#define RCC_REG             (*((RCC_REGISTER*)(RCC_Base_Address)))
/** @}*/ //End of RCC_Registers_Address

/**
 * @defgroup RCC_Registers_Bits
 * @brief Bits of RCC Registers.
 * @{
*/

/**
 * @brief RCC Control Register (CR) Bits
*/
#define HSION               0
#define HSIRDY              1
#define HSITRIM             3
#define HSICAL              8
#define HSEON               16
#define HSERDY              17
#define HSEBYP              18
#define CSSON               19
#define PLLON               24
#define PLLRDY              25

#define SW                  0
#define SWS                 2
#define HPRE                4
#define PPRE1               8
#define PPRE2               11
#define ADCPRE              14
#define PLLSRC              16
#define PLLXTPRE            17
#define PLLMUL              18
#define USBPRE              22
#define MCO                 24

#define LSIRDYF             0
#define LSERDYF             1
#define HSIRDYF             2
#define HSERDYF             3
#define PLLRDYF             4
#define CSSF                7
#define LSIRDYIE            8
#define LSERDYIE            9
#define HSIRDYIE            10
#define HSERDYIE            11
#define PLLRDYIE            12
#define LSIRDYC             16
#define LSERDYC             17
#define HSIRDYC             18
#define HSERDYC             19
#define PLLRDYC             20
#define CSSC                23

#define LSEON               0
#define LSERDY              1
#define LSEBYP              2
#define RTCSEL              8
#define RTCEN               15
#define BDRST               16

#define LSION               0
#define LSIRDY              1
#define RMVF                24
#define PINRSTF             26
#define PORRSTF             27
#define SFTRSTF             28
#define IWDGRSTF            29
#define WWDGRSTF            30
#define LPWRRSTF            31


#endif // RCC_PRIVATE_H
