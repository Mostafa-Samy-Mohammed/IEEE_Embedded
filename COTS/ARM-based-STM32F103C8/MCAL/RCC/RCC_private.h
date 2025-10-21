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


#define RCC_Base_Address    0x40021000


#define RCC_CR         *((volatile u32*)(RCC_Base_Address + 0x00))
#define RCC_CFGR       *((volatile u32*)(RCC_Base_Address + 0x04))
#define RCC_AHBENR     *((volatile u32*)(RCC_Base_Address + 0x14))
#define RCC_APB2ENR    *((volatile u32*)(RCC_Base_Address + 0x18))
#define RCC_APB1ENR    *((volatile u32*)(RCC_Base_Address + 0x1C))


#define RCC_CR_HSION                0
#define RCC_CR_HSIRDY               1
#define RCC_CR_HSITRIM              3
#define RCC_CR_HSICAL               8
#define RCC_CR_HSEON                16
#define RCC_CR_HSERDY               17
#define RCC_CR_HSEBYP               18
#define RCC_CR_CSSON                19
#define RCC_CR_PLLON                24
#define RCC_CR_PLLRDY               25

#define RCC_CFGR_SW                 0
#define RCC_CFGR_SWS                2
#define RCC_CFGR_HPRE               4
#define RCC_CFGR_PPRE1              8
#define RCC_CFGR_PPRE2              11
#define RCC_CFGR_ADCPRE             14
#define RCC_CFGR_PLLSRC             16
#define RCC_CFGR_PLLXTPRE           17
#define RCC_CFGR_PLLMUL             18
#define RCC_CFGR_USBPRE             22
#define RCC_CFGR_MCO                24

#define RCC_CIR_LSIRDYF             0
#define RCC_CIR_LSERDYF             1
#define RCC_CIR_HSIRDYF             2
#define RCC_CIR_HSERDYF             3
#define RCC_CIR_PLLRDYF             4
#define RCC_CIR_CSSF                7
#define RCC_CIR_LSIRDYIE            8
#define RCC_CIR_LSERDYIE            9
#define RCC_CIR_HSIRDYIE            10
#define RCC_CIR_HSERDYIE            11
#define RCC_CIR_PLLRDYIE            12
#define RCC_CIR_LSIRDYC             16
#define RCC_CIR_LSERDYC             17
#define RCC_CIR_HSIRDYC             18
#define RCC_CIR_HSERDYC             19
#define RCC_CIR_PLLRDYC             20
#define RCC_CIR_CSSC                23

#define RCC_BDCR_LSEON              0
#define RCC_BDCR_LSERDY             1
#define RCC_BDCR_LSEBYP             2
#define RCC_BDCR_RTCSEL             8
#define RCC_BDCR_RTCEN              15
#define RCC_BDCR_BDRST              16

#define RCC_CSR_LSION               0
#define RCC_CSR_LSIRDY              1
#define RCC_CSR_RMVF                24
#define RCC_CSR_PINRSTF             26
#define RCC_CSR_PORRSTF             27
#define RCC_CSR_SFTRSTF             28
#define RCC_CSR_IWDGRSTF            29
#define RCC_CSR_WWDGRSTF            30
#define RCC_CSR_LPWRRSTF            31


#define RCC_SYSCLK_HSI              0
#define RCC_SYSCLK_HSE              1
#define RCC_SYSCLK_PLL              2

#define PLL_HALF_HSI                0
#define PLL_HALF_HSE                1
#define PLL_HSE                     2

#define RCC_RC_NOT_BYPASS           0
#define RCC_CRYSTAL_BYPASS          1

#define PLL_CLK_INPUT_x2            0 
#define PLL_CLK_INPUT_x3            1 
#define PLL_CLK_INPUT_x4            2 
#define PLL_CLK_INPUT_x5            3 
#define PLL_CLK_INPUT_x6            4 
#define PLL_CLK_INPUT_x7            5 
#define PLL_CLK_INPUT_x8            6 
#define PLL_CLK_INPUT_x9            7 
#define PLL_CLK_INPUT_x10           8 
#define PLL_CLK_INPUT_x11           9 
#define PLL_CLK_INPUT_x12           10
#define PLL_CLK_INPUT_x13           11
#define PLL_CLK_INPUT_x14           12
#define PLL_CLK_INPUT_x15           13
#define PLL_CLK_INPUT_x16           14

#define AHB_SYSCLK_NOT_DIVIDED      0 
#define AHB_SYSCLK_DIVIDED_BY_2     8 
#define AHB_SYSCLK_DIVIDED_BY_4     9 
#define AHB_SYSCLK_DIVIDED_BY_8     10
#define AHB_SYSCLK_DIVIDED_BY_16    11
#define AHB_SYSCLK_DIVIDED_BY_64    12
#define AHB_SYSCLK_DIVIDED_BY_128   13
#define AHB_SYSCLK_DIVIDED_BY_256   14
#define AHB_SYSCLK_DIVIDED_BY_512   15

#define APB1_HCLK_NOT_DIVIDED       0
#define APB1_HCLK_DIVIDED_BY_2      4
#define APB1_HCLK_DIVIDED_BY_4      5
#define APB1_HCLK_DIVIDED_BY_8      6
#define APB1_HCLK_DIVIDED_BY_16     7

#define APB2_HCLK_NOT_DIVIDED       0
#define APB2_HCLK_DIVIDED_BY_2      4
#define APB2_HCLK_DIVIDED_BY_4      5
#define APB2_HCLK_DIVIDED_BY_8      6
#define APB2_HCLK_DIVIDED_BY_16     7

#define ADC_PCLK_DIVIDED_BY_2       0
#define ADC_PCLK_DIVIDED_BY_4       1
#define ADC_PCLK_DIVIDED_BY_6       2
#define ADC_PCLK_DIVIDED_BY_8       3

#define MCO_NO_CLK                  0
#define MCO_SYS_CLK                 1
#define MCO_HSE_CLK                 2
#define MCO_HSI_CLK                 3
#define MCO_PLL_CLK_DIVIDED_BY_2    4

#define USB_PLLCLK_DIVIDED_BY_HALF  0
#define USB_PLLCLK_NOT_DIVIDED      1


#endif // RCC_PRIVATE_H
