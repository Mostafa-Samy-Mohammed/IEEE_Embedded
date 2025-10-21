/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : GPIO_interface        ****************/
/**************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIOA                               0
#define GPIOB                               1
#define GPIOC                               2

#define GPIO_PIN0                           0
#define GPIO_PIN1                           1
#define GPIO_PIN2                           2
#define GPIO_PIN3                           3
#define GPIO_PIN4                           4
#define GPIO_PIN5                           5
#define GPIO_PIN6                           6
#define GPIO_PIN7                           7
#define GPIO_PIN8                           8
#define GPIO_PIN9                           9
#define GPIO_PIN10                          10


#define GPIO_LOW                            0
#define GPIO_HIGH                           1


#define GPIO_INPUT_ANALOG                   0b0000
#define GPIO_INPUT_FLOATING                 0b0100
#define GPIO_INPUT_PULL_UP_DOWN             0b1000


#define GPIO_OUTPUT_PUSH_PULL_10MHZ         0b0001
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ        0b0101

#define GPIO_OUTPUT_PUSH_PULL_2MHZ          0b0010
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ         0b0110

#define GPIO_OUTPUT_PUSH_PULL_50MHZ         0b0011
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ        0b0111


#define GPIO_AF_OUTPUT_PUSH_PULL_10MHZ      0b1001
#define GPIO_AF_OUTPUT_OPEN_DRAIN_10MHZ     0b1101

#define GPIO_AF_OUTPUT_PUSH_PULL_2MHZ       0b1010
#define GPIO_AF_OUTPUT_OPEN_DRAIN_2MHZ      0b1110

#define GPIO_AF_OUTPUT_PUSH_PULL_50MHZ      0b1011
#define GPIO_AF_OUTPUT_OPEN_DRAIN_50MHZ     0b1111


void MCAL_GPIO_SetPinMode(u8 copy_Port, u8 copy_Pin, u8 copy_Mode);
void MCAL_GPIO_SetPinValue(u8 copy_Port, u8 copy_Pin, u8 copy_Value);
u8 MCAL_GPIO_GetPinValue(u8 copy_Port, u8 copy_Pin);

#endif /* GPIO_INTERFACE_H */