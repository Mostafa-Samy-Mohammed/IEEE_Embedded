/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.6                   ****************/
/*********** File Name : RCC_config            ****************/
/**************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Macro to configure system clock source */
/* Options: RCC_CLK_SRC_HSI               */
/*          RCC_CLK_SRC_HSE_RC            */
/*          RCC_CLK_SRC_HSE_CRY           */
/*          RCC_CLK_SRC_PLL               */
#define RCC_CLK_SRC        RCC_CLK_SRC_HSI

#if RCC_CLK_SRC == RCC_CLK_SRC_PLL

/* Macro to configure PLL clock source */
/* Options: PLL_HALF_HSI                 */
/*          PLL_HALF_HSE                 */
#define RCC_PLL_SRC        PLL_HALF_HSE


/* Macro to configure PLL clock input */
/* Options: PLL_CLK_INPUT_x2             */
/*          PLL_CLK_INPUT_x3             */
/*          PLL_CLK_INPUT_x4             */
/*          PLL_CLK_INPUT_x5             */
/*          PLL_CLK_INPUT_x6             */
/*          PLL_CLK_INPUT_x7             */
/*          PLL_CLK_INPUT_x8             */
/*          PLL_CLK_INPUT_x9             */
/*          PLL_CLK_INPUT_x10            */
/*          PLL_CLK_INPUT_x11            */
/*          PLL_CLK_INPUT_x12            */
/*          PLL_CLK_INPUT_x13            */
/*          PLL_CLK_INPUT_x14            */
/*          PLL_CLK_INPUT_x15            */
/*          PLL_CLK_INPUT_x16            */
#define RCC_PLL_INPUT      PLL_CLK_INPUT_x2

/* Macro to configure AHB prescaler */
/* Options: AHB_SYSCLK_NOT_DIVIDED       */
/*          AHB_SYSCLK_DIVIDED_BY_2      */
/*          AHB_SYSCLK_DIVIDED_BY_4      */
/*          AHB_SYSCLK_DIVIDED_BY_8      */
/*          AHB_SYSCLK_DIVIDED_BY_16     */
/*          AHB_SYSCLK_DIVIDED_BY_64     */
/*          AHB_SYSCLK_DIVIDED_BY_128    */
/*          AHB_SYSCLK_DIVIDED_BY_256    */
/*          AHB_SYSCLK_DIVIDED_BY_512    */
#define RCC_AHB_PRESCALER  AHB_SYSCLK_NOT_DIVIDED

/* Macro to configure APB1 prescaler */
/* Options: APB1_HCLK_NOT_DIVIDED        */
/*          APB1_HCLK_DIVIDED_BY_2       */
/*          APB1_HCLK_DIVIDED_BY_4       */
/*          APB1_HCLK_DIVIDED_BY_8       */
/*          APB1_HCLK_DIVIDED_BY_16      */
#define RCC_APB1_PRESCALER APB1_HCLK_NOT_DIVIDED

/* Macro to configure APB2 prescaler */
/* Options: APB2_HCLK_NOT_DIVIDED        */
/*          APB2_HCLK_DIVIDED_BY_2       */
/*          APB2_HCLK_DIVIDED_BY_4       */
/*          APB2_HCLK_DIVIDED_BY_8       */
/*          APB2_HCLK_DIVIDED_BY_16      */
#define RCC_APB2_PRESCALER APB2_HCLK_NOT_DIVIDED

/* Macro to configure ADC prescaler */
/* Options: ADC_PCLK_DIVIDED_BY_2        */
/*          ADC_PCLK_DIVIDED_BY_4        */
/*          ADC_PCLK_DIVIDED_BY_6        */
/*          ADC_PCLK_DIVIDED_BY_8        */
/*          ADC_PCLK_DIVIDED_BY_16       */
#define RCC_ADC_PRESCALER  ADC_PCLK_DIVIDED_BY_2

/* Macro to configure MCO output */
/* Options: MCO_NO_CLK                   */
/*          MCO_SYS_CLK                  */
/*          MCO_HSE_CLK                  */
/*          MCO_HSI_CLK                  */
/*          MCO_PLL_CLK_DIVIDED_BY_2     */
#define RCC_MCO_OUTPUT     MCO_NO_CLK

/* Macros to configure USB Prescaler */
/* Options: USB_PLLCLK_DIVIDED_BY_HALF   */
/*          USB_PLLCLK_NOT_DIVIDED       */
#define RCC_USB_PRESCALER  USB_PLLCLK_DIVIDED_BY_HALF

#endif


#endif // RCC_CONFIG_H
