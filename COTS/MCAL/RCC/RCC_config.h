/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.6                   ****************/
/*********** File Name : RCC_config            ****************/
/**************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and speed.
 * @{
 */

/**
 * @brief Options of system clock source.
 * @note There are 3 options available to be the source for system clock:
 *      - RCC_HSI:  High-Speed Internal Clock Source.
 *      - RCC_HSE:  High-Speed External Clock Source.
 *      - RCC_PLL:  Phase-Locked Loop Clock Source.
 *                  When using PLL as a system clock source it could multiplies
 *                  the frequency of an input clock source (HSI Or HSE) to generate
 *                  a higher frequency output.
*/
#define RCC_SYSCLK              RCC_PLL

/**
 * @brief Configure the clock source and type for RCC_SYSCLK when using RCC_PLL.
 * @note Choose the source options:
 *      - RCC_HSI:  High-Speed Internal Clock Source.
 *      - RCC_HSE:  High-Speed External Clock Source.
 * 
 * @note Choose the type option if the source is RCC_HSE:
 *      - RCC_RC_CLK     :  RC oscillator will be the source of the clock system.
 *      - RCC_CRYSTAL_CLK:  Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS          RCC_CRYSTAL_CLK

#elif RCC_SYSCLK == RCC_PLL

#define PLL_CLK_SRC             PLL_HSE
#define RCC_CLK_BYPASS          RCC_CRYSTAL_CLK

/**
 * @brief Configure the PLL Multiblication factor.
 * @note Choose one of the options:
 *      - 0000: PLL_CLK_INPUT_x2.
 * 	    - 0001: PLL_CLK_INPUT_x3.
 * 	    - 0010: PLL_CLK_INPUT_x4.
 * 	    - 0011: PLL_CLK_INPUT_x5.
 * 	    - 0100: PLL_CLK_INPUT_x6.
 * 	    - 0101: PLL_CLK_INPUT_x7.
 * 	    - 0110: PLL_CLK_INPUT_x8.
 * 	    - 0111: PLL_CLK_INPUT_x9.
 * 	    - 1000: PLL_CLK_INPUT_x10.
 * 	    - 1001: PLL_CLK_INPUT_x11.
 * 	    - 1010: PLL_CLK_INPUT_x12.
 * 	    - 1011: PLL_CLK_INPUT_x13.
 * 	    - 1100: PLL_CLK_INPUT_x14.
 * 	    - 1101: PLL_CLK_INPUT_x15.
 * 	    - 1110: PLL_CLK_INPUT_x16.
 * 	    - 1111: PLL_CLK_INPUT_x16.
 */
#define PLL_MUL_FACTOR          PLL_CLK_INPUT_x6

/**
 * @brief Configure the AHB Prescaler Factor.
 * @note Choose one of the options:
 *  	- 0xxx: AHB_SYSCLK_NOT_DIVIDED.
 *  	- 1000: AHB_SYSCLK_DIVIDED_BY_2.
 *  	- 1001: AHB_SYSCLK_DIVIDED_BY_4.
 *  	- 1010: AHB_SYSCLK_DIVIDED_BY_8.
 *  	- 1011: AHB_SYSCLK_DIVIDED_BY_16.
 *  	- 1100: AHB_SYSCLK_DIVIDED_BY_64.
 *  	- 1101: AHB_SYSCLK_DIVIDED_BY_128.
 *  	- 1110: AHB_SYSCLK_DIVIDED_BY_256.
 *  	- 1111: AHB_SYSCLK_DIVIDED_BY_512.
 */
#define AHB_PRESCALER_FACTOR    AHB_SYSCLK_NOT_DIVIDED  /** KEEP RESET VALUE */

/**
 * @brief Configure the APB1 Prescaler Factor.
 * @note Choose one of the options:
 *  	- 0xx: APB1_HCLK_NOT_DIVIDED.
 *  	- 100: APB1_HCLK_DIVIDED_BY_2.
 *  	- 101: APB1_HCLK_DIVIDED_BY_4.
 *  	- 110: APB1_HCLK_DIVIDED_BY_8.
 *  	- 111: APB1_HCLK_DIVIDED_BY_16.
 */
#define APB1_PRESCALER_FACTOR   APB1_HCLK_DIVIDED_BY_2

/**
 * @brief Configure the APB2 Prescaler Factor.
 * @note Choose one of the options:
 *  	- 0xx: APB2_HCLK_NOT_DIVIDED.
 *  	- 100: APB2_HCLK_DIVIDED_BY_2.
 *  	- 101: APB2_HCLK_DIVIDED_BY_4.
 *  	- 110: APB2_HCLK_DIVIDED_BY_8.
 *  	- 111: APB2_HCLK_DIVIDED_BY_16.
 */
#define APB2_PRECALER_FACTOR    APB2_HCLK_NOT_DIVIDED   /** KEEP RESET VALUE */

/**
 * @brief Configure the ADC Prescaler Factor.
 * @note Choose one of the options:
 *  	- 00: ADC_PCLK_DIVIDED_BY_2.
 *  	- 01: ADC_PCLK_DIVIDED_BY_4.
 *  	- 10: ADC_PCLK_DIVIDED_BY_6.
 *  	- 11: ADC_PCLK_DIVIDED_BY_8.
 */
#define ADC_PRESCALER_FACTOR    ADC_PCLK_DIVIDED_BY_2   /** KEEP RESET VALUE */

/**
 * @brief Configure the MCO Clock Source.
 * @note Choose one of the options:
 *  	- 0xx: MCO_NO_CLK.
 *  	- 100: MCO_SYS_CLK.
 *  	- 101: MCO_HSE_CLK.
 *  	- 110: MCO_HSI_CLK.
 *      - 111: MCO_PLL_CLK_DIVIDED_BY_2.
 */
#define MCO_CLK_SRC             MCO_SYS_CLK

/**
 * @brief Configure the USB Prescaler Factor.
 * @note Choose one of the options:
 *  	- 0: USB_PLLCLK_DIVIDED_By_1.5.
 *  	- 1: USB_PLLCLK_NOT_DIVIDED.
 */
#define USB_PRESCALER_FACTOR    USB_PLLCLK_NOT_DIVIDED

#else
    //error
#endif /**< RCC_SYSCLK */

/** @} */ //End of RCC_System_Clock_Config


#endif // RCC_CONFIG_H
