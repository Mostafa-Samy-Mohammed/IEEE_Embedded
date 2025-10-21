/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.2                   ****************/
/*********** File Name : BIT_MATH              ****************/
/**************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* Set a certain bit in any register */
#define SET_BIT(REG, BIT)        REG |=  (1 << BIT)

/* Clear a certain bit in any register */
#define CLR_BIT(REG, BIT)        REG &= ~(1 << BIT)

/* Toggle a certain bit in any register */
#define TOG_BIT(REG, BIT)        REG ^=  (1 << BIT)

/* Check if a specific bit is set in any register and return true/false */
#define BIT_IS_SET(REG, BIT)     REG & (1 << BIT)

/* Check if a specific bit is cleared in any register and return true/false */
#define BIT_IS_CLEAR(REG, BIT)   !(REG & (1 << BIT))

/* Get the value of a certain bit in any register */
#define GET_BIT(REG, BIT)        (REG >> BIT) & 1

#endif /* BIT_MATH_H_ */
