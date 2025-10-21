/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 5/9/2024              ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : NVIC_private          ****************/
/**************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

//NVIC Base Address
#define NVIC_BASE_ADDRESS      0xE000E100

//NVIC Registers
#define NVIC_ISER0      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000))
#define NVIC_ISER1      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x004))
#define NVIC_ISER2      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x008))

#define NVIC_ICER0      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x084))
#define NVIC_ICER2      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x088))

#define NVIC_ISPR0      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x104))
#define NVIC_ISPR2      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x108))

#define NVIC_ICPR0      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x184))
#define NVIC_ICPR2      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x188))

#define NVIC_IABR0      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x204))
#define NVIC_IABR2      *((volatile u32*)(NVIC_BASE_ADDRESS + 0x208))

//Interrupt Priority Registers
#define NVIC_IP         ((volatile u8*)(NVIC_BASE_ADDRESS + 0x300))

//Priority Grouping
#define NVIC_16GROUP_0SUB   0b011
#define NVIC_8GROUP_2SUB    0b100
#define NVIC_4GROUP_4SUB    0b101
#define NVIC_2GROUP_8SUB    0b110
#define NVIC_0GROUP_16SUB   0b111

//SCB_AIRCP Register Address
#define SCB_AIRCR       *((volatile u32*)(0xE000ED00 + 0x0C))

//SCB_AIRCP Key
#define SCB_AIRCR_KEY   0x05FA0000

#endif /* NVIC_PRIVATE_H */
