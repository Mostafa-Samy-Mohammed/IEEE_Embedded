/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.5                   ****************/
/*********** File Name : RCC_private           ****************/
/**************************************************************/

/****************************< LIB ****************************/
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

#define RCC_REG             ((RCC_REGISTER*)(RCC_Base_Address))

/** @}*/ //End of RCC_Registers_Address

/**
 * @defgroup RCC_Registers_Bits
 * @brief Bit definitions of RCC Registers.
 * @{
*/

/**
 * @brief RCC Control Register (CR) Bits definitions.
*/
#define RCC_CR_HSION           0     /** Internal high-speed enable */
#define RCC_CR_HSIRDY          1     /** Internal high-speed clock ready */
#define RCC_CR_HSITRIM         3     /** Internal high-speed clock trimming */
#define RCC_CR_HSICAL          8     /** Internal high-speed clock calibration */
#define RCC_CR_HSEON           16    /** External high-speed enable */
#define RCC_CR_HSERDY          17    /** External high-speed ready */
#define RCC_CR_HSEBYP          18    /** External high-speed bypass */
#define RCC_CR_CSSON           19    /** Clock security system enable */
#define RCC_CR_PLLON           24    /** PLL enable */
#define RCC_CR_PLLRDY          25    /** PLL ready flag */

/**
 * @brief RCC Clock Configuration Register (CFGR) Bits definitions.
*/
#define RCC_CFGR_SW            0     /** System clock switch */
#define RCC_CFGR_SWS           2     /** System clock switch status */
#define RCC_CFGR_HPRE          4     /** AHB prescaler */
#define RCC_CFGR_PPRE1         8     /** APB low-speed prescaler (APB1) */
#define RCC_CFGR_PPRE2         11    /** APB high-speed prescaler (APB2) */
#define RCC_CFGR_ADCPRE        14    /** ADC prescaler */
#define RCC_CFGR_PLLSRC        16    /** PLL entry clock source */
#define RCC_CFGR_PLLXTPRE      17    /** HSE divider for PLL entry */
#define RCC_CFGR_PLLMUL        18    /** PLL multiplication factor */
#define RCC_CFGR_USBPRE        22    /** USB prescaler */
#define RCC_CFGR_MCO           24    /** Microcontroller clock output */

/**
 * @brief RCC Clock Interrupt Register (CIR) Bits definitions.
*/
#define RCC_CIR_LSIRDYF        0
#define RCC_CIR_LSERDYF        1
#define RCC_CIR_HSIRDYF        2
#define RCC_CIR_HSERDYF        3
#define RCC_CIR_PLLRDYF        4
#define RCC_CIR_CSSF           7
#define RCC_CIR_LSIRDYIE       8
#define RCC_CIR_LSERDYIE       9
#define RCC_CIR_HSIRDYIE       10
#define RCC_CIR_HSERDYIE       11
#define RCC_CIR_PLLRDYIE       12
#define RCC_CIR_LSIRDYC        16
#define RCC_CIR_LSERDYC        17
#define RCC_CIR_HSIRDYC        18
#define RCC_CIR_HSERDYC        19
#define RCC_CIR_PLLRDYC        20
#define RCC_CIR_CSSC           23

/**
 * @brief RCC Backup Domain Control Register (BDCR) Bits definitions.
*/
#define RCC_BDCR_LSEON         0
#define RCC_BDCR_LSERDY        1
#define RCC_BDCR_LSEBYP        2
#define RCC_BDCR_RTCSEL        8
#define RCC_BDCR_RTCEN         15
#define RCC_BDCR_BDRST         16

/**
 * @brief RCC Control/Status Register (CSR) Bits definitions.
*/
#define RCC_CSR_LSION          0
#define RCC_CSR_LSIRDY         1
#define RCC_CSR_RMVF           24
#define RCC_CSR_PINRSTF        26
#define RCC_CSR_PORRSTF        27
#define RCC_CSR_SFTRSTF        28
#define RCC_CSR_IWDGRSTF       29
#define RCC_CSR_WWDGRSTF       30
#define RCC_CSR_LPWRRSTF       31

/** @} */ //End of RCC_Registers_Bits

/**
 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */

#define RCC_HSI                0   /** High-Speed Internal Clock Source (HSI) */
#define RCC_HSE                1   /** High-Speed External Clock Source (HSE) */
#define RCC_PLL                2   /** Phase-Locked Loop Clock Source (PLL) */

/** @} */ //End of RCC_Clock_Source

/**
 * @defgroup RCC_PLL_Clock_Source
 * @{
*/

#define PLL_HALF_HSI           0
#define PLL_HALF_HSE           1
#define PLL_HSE                2

/** @} */ //End of RCC_PLL_Clock_Source

/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTAL_CLK       0   /** Crystal Oscillator Clock Type */
#define RCC_RC_CLK            1   /** RC Oscillator Clock Type */

/** @} */ //End of RCC_Clock_Type

/**
 * @defgroup PLL_Multiplication_Factor
 * @{
*/
#define PLL_CLK_INPUT_x2                0
#define PLL_CLK_INPUT_x3                1
#define PLL_CLK_INPUT_x4                2
#define PLL_CLK_INPUT_x5                3
#define PLL_CLK_INPUT_x6                4
#define PLL_CLK_INPUT_x7                5
#define PLL_CLK_INPUT_x8                6
#define PLL_CLK_INPUT_x9                7
#define PLL_CLK_INPUT_x10               8
#define PLL_CLK_INPUT_x11               9
#define PLL_CLK_INPUT_x12               10
#define PLL_CLK_INPUT_x13               11
#define PLL_CLK_INPUT_x14               12
#define PLL_CLK_INPUT_x15               13
#define PLL_CLK_INPUT_x16               14

/** @} */ //End of PLL_Multiplication_Factor

/**
 * @defgroup AHB_Prescaler_Factor
 * @{
*/
#define AHB_SYSCLK_NOT_DIVIDED          0
#define AHB_SYSCLK_DIVIDED_BY_2         8
#define AHB_SYSCLK_DIVIDED_BY_4         9
#define AHB_SYSCLK_DIVIDED_BY_8         10
#define AHB_SYSCLK_DIVIDED_BY_16        11
#define AHB_SYSCLK_DIVIDED_BY_64        12
#define AHB_SYSCLK_DIVIDED_BY_128       13
#define AHB_SYSCLK_DIVIDED_BY_256       14
#define AHB_SYSCLK_DIVIDED_BY_512       15

/** @} */ //End of AHB_Prescaler_Factor

/**
 * @defgroup APB1_Prescaler_Factor
 * @{
*/
#define APB1_HCLK_NOT_DIVIDED           0
#define APB1_HCLK_DIVIDED_BY_2          4
#define APB1_HCLK_DIVIDED_BY_4          5
#define APB1_HCLK_DIVIDED_BY_8          6
#define APB1_HCLK_DIVIDED_BY_16         7

/** @} */ //End of APB1_Prescaler_Factor

/**
 * @defgroup APB2_Prescaler_Factor
 * @{
*/
#define APB2_HCLK_NOT_DIVIDED           0
#define APB2_HCLK_DIVIDED_BY_2          4
#define APB2_HCLK_DIVIDED_BY_4          5
#define APB2_HCLK_DIVIDED_BY_8          6
#define APB2_HCLK_DIVIDED_BY_16         7

/** @} */ //End of APB2_Prescaler_Factor

/**
 * @defgroup ADC_Prescaler_Factor
 * @{
*/
#define ADC_PCLK_DIVIDED_BY_2           0
#define ADC_PCLK_DIVIDED_BY_4           2
#define ADC_PCLK_DIVIDED_BY_6           3
#define ADC_PCLK_DIVIDED_BY_8           4

/** @} */ //End of ADC_Prescaler_Factor

/**
 * @defgroup MCO_Clock_Source
 * @{
*/
#define MCO_NO_CLK                      0
#define MCO_SYS_CLK                     4
#define MCO_HSE_CLK                     5
#define MCO_HSI_CLK                     6
#define MCO_PLL_CLK_DIVIDED_BY_2        7

/** @} */ //End of MCO_Clock_Source

/**
 * @defgroup USB_Prescaler_Factor
 * @{
*/
#define USB_PLLCLK_DIVIDED_BY_ONEHALF   0
#define USB_PLLCLK_NOT_DIVIDED          1

/** @} */ //End of USB_Prescaler_Factor


#endif // RCC_PRIVATE_H
