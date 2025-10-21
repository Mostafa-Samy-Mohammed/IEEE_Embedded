/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : BIT_MATH              ****************/
/**************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SetBit(Reg, BitNumber)  Reg |=  (1 << BitNumber)
#define ClrBit(Reg, BitNumber)  Reg &= ~(1 << BitNumber)
#define TogBit(Reg, BitNumber)  Reg ^=  (1 << BitNumber)
#define SetBit(Reg, BitNumber)  ((Reg & (1 << BitNumber)) >> BitNumber)



#endif /* BIT_MATH_H_ */
