/* Copyright (C) 1993 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   FLOAT.H
*
* TITLE:       This File has data type definitions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes data type definitions used for MATH.H.
*
*
* SPECIAL CONSIDERATIONS:
*	        <None>
*
* AUTHOR:      R. Greenthal
*
*
* CREATION DATE:  Dec 25,2003
*
* REVISION HISTORY
*    Name           Date         Description
*    ------------   ----------   ----------------------------------------------
*    R. Greenthal   12/16/2003   Initial
*
*******************************************************************************
*/

#ifndef __FLOAT_H
#define __FLOAT_H

/*
 *=========================== CONSTANTS & MACROS ===============================
 */

/*--------------------------------------------------------------------------------
* / NAME   
* /           FLT_ROUNDS - rounding modes
* /
* / SYNOPSIS
* /           #define FLT_ROUNT {-1,0,1,2,3}
* /
* / DESCRIPTION
* /           FLT_ROUNDS indicates to the rounding mode for floats point values: 
* /           -1, undetermined 
* /           0 toward zero 
* /           1 to the nearest 
* /           2 towards positive infinity 
* /           3 towards negative infinity
* /
* / Notes
* /           The floating-point representation in apeNEXT is inasmach as 
* /           fixed hardware-impemented, we might not need to redefind its 
* /           rounding modes. But at this prestage we cannot exclude the need
* /           for rounding in certain claculation.
* /            
* /----------------------------------------------------------------------------*/
#ifndef FLT_ROUNDS
#define FLT_ROUNDS -1  
#endif



/*-------------------------------------------------------------------------------
* / NAME   
* /           FLT_EVAL_METHOD - evaluation formats
* /
* / SYNOPSIS
* /           #define FLT_EVAL_METHOD {-1,0,1,2}
* /
* / DESCRIPTION
* /           FLT_EVAL_METHOD defines the evaluation methos used to determine 
* /           the evaluation formats of all floating types. It defines the 
* /           precision/representation of operations proceeded with foating-point
* /       
* / RETURN VALUE
* /           None
* /
* / Notes           
* /           If-1, range and precision of evaluation are not determined.
* /           If 0, all operations and constants will be 
* /                 evaluated to the range and precisions of the current type.
* /           If 1, all operations and constants of types 
* /                 float and double will be evaluated to the range and precisions 
* /                 of double (long double will be evaluated as long double also).
* /                 Also the product of two floating_complex 
* /                 operands is represented in double _Complex format, 
* /                 and its parts are evaluated to double. 
* /           If 2, all operations and constants will be 
* /                 evaluated to the range and precision of long double.
* /
* /-----------------------------------------------------------------------------*/
#ifndef FLT_EVAL_METHOD
#define FLT_EVAL_METHOD 0
#endif


/*----------------------------------------------------------------------------------
* / NAME   
* /           FLT_RADIX - (base) radix representation of the exponent
* /
* / SYNOPSIS
* /           #define FLT_RADIX {2,8,10,16}
* /
* / DESCRIPTION
* /           FLT_RADIX is the radix of exponent representing (or the base) 
* /           typically defined as 2 (binary), 
* /           but there are other definitions like  8, 10, 16
* /              8  is octal,
* /              10 is the normal decimal, 
* /              16 is Hex, representations
* /
* / RETURN VALUE
* /           None
* /
* / Notes    
* /       
* /----------------------------------------------------------------------------*/
#ifndef FLT_RADIX
#define FLT_RADIX 2
#endif

/*--------------------------------------------------------------------------------
* / NAME   
* /           FLT_MANT_DIG - number of base-FLT_RADIX digits
* /
* / SYNOPSIS
* /
* / DESCRIPTION
* /           FLT_MANT_DIG defines the number of base-FLT_RADIX digits 
* /           in the floating-point significant p. 
* /
* / RETURN VALUE
* /           None
* /
* / Notes    
* /           It belongs to FLT_RADIX like DBL_MANT_DIG, LDBL_MANT_DIG.
* /           According to EC 60559 FLT_MANT_DIG has 53 bit 
* /           (where mantissa is always less than 1)
* / 
* /-----------------------------------------------------------------------------*/
#ifndef FLT_MANT_DIG 
#define FLT_MANT_DIG		24		// Number of Bits in the Mantissa
#endif


/*--------------------------------------------------------------------------------
* / NAME   
* /           DECIMAL_DIG -  number of decimals
* /
* / SYNOPSIS
* /           #define DECIMAL_DIG 
* /
* / DESCRIPTION
* /           Number of decimal digits, n, such that any floating-point 
* /           number in the widest supported floating type with pmax 
* /           radix b digits can be rounded to a floating-point number 
* /           with n decimal digits and back again without 
* /           change to the value.
* /              [p * log_{10} b]       if b is a power of 10
* /              [1 + p * log_{10} b]   otherwise
* /  
* / RETURN VALUE
* /           None
* /
* /-----------------------------------------------------------------------------*/
#undef DECIMAL_DIG
#if LDBL_MANT_DIG == 53
//#define DECIMAL_DIG  12
#define DECIMAL_DIG  17
#else
#define DECIMAL_DIG  36
#endif
 
/*--------------------------------------------------------------------------------
* / NAME   
* /           FLT_DIG - minimun negative interger for exponent in FLT_RADIX
* /
* / SYNOPSIS
* /
* / DESCRIPTION
* /           FLT_DIG is the minimum negative integer value, q, such that 
* /           any floaring-point number with q decimal digits can be rounded
* /           into a floating-point number with p radix b digits and back 
* /           again without change to the q decimal digits and the value
* /                p*log_{10} b     + 1 if b is a power of 10 
* /           [1 - p*log_{10} b]    + 0 otherwise
* /
* / RETURN VALUE
* /           None
* /
* / Notes    
* /           The value of this macro is supposed to be at least 6, 
* /           to satisfy ISO c
* /
* /-----------------------------------------------------------------------------*/
#ifndef FLT_DIG 
#define FLT_DIG			6		// The maximum number decimal digits (base-10) that can be represented without change after rounding
#endif


/*---------------------------------------------------------------------------------
* / NAME   
* /           FLT_MIN_EXP - minimun negative that FLT_RADIX to n-1
* /
* / SYNOPSIS
* /
* / DESCRIPTION  
* /           Minimum negative integer such that FLT_RADIX raised to that power 
* /           minus 1 is a normalized floating-point number e_{min}, 
* /
* / Notes    
* /
* /-----------------------------------------------------------------------------*/
#ifndef FLT_MIN_EXP 
#define	FLT_MIN_EXP		-125		//The min integer value for an exponent in base 10
#endif

/*---------------------------------------------------------------------------------
* / NAME   
* /           FLT_MIN_10_EXP - ninimum negative integer for exponent in base 10
* /
* / SYNOPSIS
* / DESCRIPTION  
* /            FLT_MIN_10_EXP is the minimum negative integer value for an 
* /            exponent in base 10 (float)
* /
* / Note
* /            Minimum int x such that 10**x is a normalised float 
* /            log_10 b^{e_min}
* /  
* /-----------------------------------------------------------------------------*/
#ifndef FLT_MIN_10_EXP 
#define FLT_MIN_10_EXP		-37		//The maximum integer value for an exponent in base 10
#endif

/*--------------------------------------------------------------------------------
* / NAME   
* /           FLT_MAX_10_EXP - maximum negative integer for exponent in base 10
* /
* / SYNOPSIS
* /
* / DESCRIPTION  
* /            FLT_MAX_10_EXP is the maximum negative integer value for an 
* /            exponent in base 10 (float)
* /
* / Note
* /            Maximum int x such that 10**x is a normalised float 
* /            log_10 ([1-b^{-p}] b^{e_max})
* /  
* /-----------------------------------------------------------------------------*/
#ifndef FLT_MAX_10_EXP 
#define FLT_MAX_10_EXP		+38		//The maximum integer value for an exponent in base 10
#endif

/*--------------------------------------------------------------------------------
* / NAME   
* /           FLT_MAX_EXP - maximun negative that FLT_RADIX to n-1
* /
* / SYNOPSIS
* /
* / DESCRIPTION  
* /           FLT_MAX_EXP the maximum number n such that base to the power 
* /           of n-1 (float). The minimum negative integer value for an 
* /           exponent in base FLT_RADIX
* /
* / Notes    
* /           Maximum negative integer such that FLT_RADIX raised to that power 
* /           minus 1 is a normalized floating-point number e_{min}, 
* /           In apeNEXT the exponent has 11 bit
* /
* /-----------------------------------------------------------------------------*/
#ifndef FLT_MAX_EXP
#define FLT_MAX_EXP		+128		//The maximum integer value for an exponent in base FLT_RADIX
#endif

/*---------------------------------------------------------------------------------
* / NAME   
* /           FLT_MAX - maximum normalized finite representable value 
* /                     of type float
* /
* / SYNOPSIS
* /
* / DESCRIPTION  
* /           Maximum floating-point value 
* /
* / Note
* /           (1-b^{p}) b^{e_{max}} 
* /           (1.-pow(2.,-52.))*pow(2.,1023) = 
* /            8.9884656743115775E+307 
* /
* /-----------------------------------------------------------------------------*/
#ifndef FLT_MAX 
#define FLT_MAX			3.40282347E+38F	//Maximum finite floating-point value
#endif 

/*---------------------------------------------------------------------------------
* / NAME   
* /           FLT_MIN - minimum normalized finite representable value 
* /                     of type float
* /
* / SYNOPSIS
* /
* / DESCRIPTION  
* /           Minimum floating-point value 
* /
* / Note
* /           b^{e_{min}-1} = pow(2., -1023)
* /
* /-----------------------------------------------------------------------------*/
#ifndef FLT_MIN 
#define	FLT_MIN			1.17549435E-38F	//Minimum floating-point value
#endif

/*--------------------------------------------------------------------------------
* / NAME   
* /           FLT_EPSELON - smallest number 
* /
* / SYNOPSIS
* /
* / DESCRIPTION  
* /           FLT_EPSILON is smallest number x such that 1.0+x!=1.0 defined as  
* /           Least significant digit representable for floating-point. 
* /
* / Note
* /           Difference between 1.0 and the least value greater that 
* /           1.0 that is reperesentable in the given floating-point type 
* /           (here double float)   
* /           b^{1-p}  pow(2.,1-52) = pow(2.,-51)
* / 
* /-----------------------------------------------------------------------------*/
#ifndef FLT_EPSILON  
#define FLT_EPSILON		1.19209290E-07F	//Least significant digit representable
#endif

/******************************************/
/* Double Precision Floating Point Limits */
/******************************************/

#define DBL_MANT_DIG	53		// Number of Bits in the Mantissa
#define DBL_EPSILON		2.2204460492503131E-16	//Least significant digit representable
#define DBL_DIG			15	// Number of Significant Digits
#define	DBL_MIN_EXP		-1021
#define	DBL_MIN			2.225073858507201E-308
#define DBL_MIN_10_EXP	-307
#define DBL_MAX_EXP		+1024
#define DBL_MAX			1.797693134862316E+308
#define DBL_MAX_10_EXP	+308

/***********************************************/
/* Long Double Precision Floating Point Limits */
/***********************************************/

#define LDBL_MANT_DIG	106		// Number of Bits in the Mantissa
#define LDBL_EPSILON	2.2204460492503131E-16L	//Least significant digit representable
#define LDBL_DIG		15	// Number of Significant Digits
#define	LDBL_MIN_EXP	-1021
#define	LDBL_MIN		2.225073858507201E-308L
#define LDBL_MIN_10_EXP	-307
#define LDBL_MAX_EXP	+1024
#define LDBL_MAX		1.797693134862316E+308L	// 0x7FEFFFFFFFFFFFFF, 0x7C8FFFFFFFFFFFFF
#define LDBL_MAX_10_EXP	+308

/* Follows IEEE standards for 128-bit floating point */
//#define	LDBL_MANT_DIG	113
//#define	LDBL_EPSILON	1.925929944387235853055977942584927319E-34L
//#define	LDBL_DIG	33
//#define	LDBL_MIN_EXP	(-16381)
//#define	LDBL_MIN	3.362103143112093506262677817321752603E-4932L
//#define	LDBL_MIN_10_EXP	(-4931)
//#define	LDBL_MAX_EXP	(+16384)
//#define	LDBL_MAX	1.189731495357231765085759326628007016E+4932L
//#define	LDBL_MAX_10_EXP	(+4932)

#endif /* FLOAT_H */
#pragma Pop (List)


/**************************************************/
/*    End of File FLOAT.H                         */
/**************************************************/

