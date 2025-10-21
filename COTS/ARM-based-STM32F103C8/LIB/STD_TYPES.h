/**************************************************************/
/*********** Author    : Mostafa Samy Mohammed ****************/
/*********** Date      : 29/8/2023             ****************/
/*********** Version   : 0.1                   ****************/
/*********** File Name : STD_TYPES             ****************/
/**************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char		    u8;
typedef unsigned short int  	u16;
typedef unsigned long int    	u32;

typedef signed char 		    s8;
typedef signed short int 		s16;
typedef signed long int 		s32;

typedef float  				    f16;
typedef double 				    f32;
typedef long double  		    f64;

typedef u8                      Std_ReturnType;

#define E_OK                    (Std_ReturnType)1
#define E_NOT_OK                (Std_ReturnType)0

#endif /* STD_TYPES_H_ */
