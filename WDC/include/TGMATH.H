/* Copyright (C) 1993 by Zardoz Software, Inc. */
#pragma Off (List)
/*******************************************************************************
* FILE NAME:   TGMATH.h
*
* TITLE:       This function prototypes and data type definitions for the Wide Characters Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Wide Character functions.
*
*
* SPECIAL CONSIDERATIONS:
*	        <None>
*
* AUTHOR:      R. Greenthal
*
*
* CREATION DATE:  March 17,2004
*
* REVISION HISTORY
*    Name           Date         Description
*    ------------   ----------   ----------------------------------------------
*    R. Greenthal   03/25/2004   Initial
*                   0x/xx/2004	 Added 
*
*******************************************************************************
*/

#ifndef __TGMATH_H
#define __TGMATH_H


/* Include the needed headers.  */
#include <math.h>
#include <complex.h>


/*
 *=========================== CONSTANTS & MACROS ===============================
 */




/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */


// (sizeof(Val)!=sizeof(double))
// (sizeof(Val)==sizeof(_Complex))	This is the one we want, but _Complex isnt defined yet

#define __REAL_DOUBLE(x) (sizeof(Val)!=sizeof(double))
#define __REAL_FLOAT(x) (sizeof(Val)!=sizeof(float))
#define __REAL_LONG_DOUBLE(x) (sizeof(Val)!=sizeof(long double))

#define acos(Val)  ((sizeof(Val)!=sizeof(double)) ? cacos(Val) :  acos(Val))
#define acosf(Val)  ((sizeof(Val)!=sizeof(float)) ? cacosf(Val) :  acosf(Val))
#define acosl(Val)  ((sizeof(Val)!=sizeof(long double)) ? cacosl(Val) :  acosl(Val))

#define acosh(Val) ((sizeof(Val)!=sizeof(double)) ? cacosh(Val) : acosh(Val))
#define acoshf(Val) ((sizeof(Val)!=sizeof(float)) ? cacoshf(Val) : acoshf(Val))
#define acoshl(Val) ((sizeof(Val)!=sizeof(long double)) ? cacoshl(Val) : acoshl(Val))

#define asin(Val)  ((sizeof(Val)!=sizeof(double)) ? casin(Val) :  asin(Val))
#define asinf(Val)  ((sizeof(Val)!=sizeof(float)) ? casinf(Val) :  asinf(Val))
#define asinl(Val)  ((sizeof(Val)!=sizeof(long double)) ? casinl(Val) :  asinl(Val))

#define asinh(Val) ((sizeof(Val)!=sizeof(double)) ? casinh(Val) : asinh(Val))
#define asinhf(Val) ((sizeof(Val)!=sizeof(float)) ? casinhf(Val) : asinhf(Val))
#define asinhl(Val) ((sizeof(Val)!=sizeof(long double)) ? casinhl(Val) : asinhl(Val))

#define atan(Val)  ((sizeof(Val)!=sizeof(double)) ? catan(Val) :  atan(Val))
#define atanf(Val)  ((sizeof(Val)!=sizeof(float)) ? catanf(Val) :  atanf(Val))
#define atanl(Val)  ((sizeof(Val)!=sizeof(long double)) ? catanl(Val) :  atanl(Val))

#define atanh(Val) ((sizeof(Val)!=sizeof(double)) ? catanh(Val) : atanh(Val))
#define atanhf(Val) ((sizeof(Val)!=sizeof(float)) ? catanhf(Val) : atanhf(Val))
#define atanhl(Val) ((sizeof(Val)!=sizeof(long double)) ? catanhl(Val) : atanhl(Val))

#define cos(Val)   ((sizeof(Val)!=sizeof(double)) ? ccos(Val) :   cos(Val))
#define cosf(Val)   ((sizeof(Val)!=sizeof(float)) ? ccosf(Val) :   cosf(Val))
#define cosl(Val)   ((sizeof(Val)!=sizeof(long double)) ? ccosl(Val) :   cosl(Val))

#define cosh(Val)  ((sizeof(Val)!=sizeof(double)) ? ccosh(Val) :  cosh(Val))
#define coshf(Val)  ((sizeof(Val)!=sizeof(float)) ? ccoshf(Val) :  coshf(Val))
#define coshl(Val)  ((sizeof(Val)!=sizeof(long double)) ? ccoshl(Val) :  coshl(Val))

#define exp(Val)   ((sizeof(Val)!=sizeof(double)) ? cexp(Val) :   exp(Val))
#define expf(Val)   ((sizeof(Val)!=sizeof(float)) ? cexpf(Val) :   expf(Val))
#define expl(Val)   ((sizeof(Val)!=sizeof(long double)) ? cexpl(Val) :   expl(Val))

#define fabs(Val)  ((sizeof(Val)!=sizeof(double)) ? cabs(Val) :   fabs(Val))
#define fabsf(Val)  ((sizeof(Val)!=sizeof(float)) ? cabsf(Val) :   fabsf(Val))
#define fabsl(Val)  ((sizeof(Val)!=sizeof(long double)) ? cabsl(Val) :   fabsl(Val))

//#define log10(Val)   ((sizeof(Val)!=sizeof(double)) ? clog10(Val) :   log10(Val))
#define log(Val)   ((sizeof(Val)!=sizeof(double)) ? clog(Val) :   log(Val))
#define logf(Val)   ((sizeof(Val)!=sizeof(float)) ? clogf(Val) :   logf(Val))
#define logl(Val)   ((sizeof(Val)!=sizeof(long double)) ? clogl(Val) :   logl(Val))

#define pow(Val)   ((sizeof(Val)!=sizeof(double)) ? cpow(Val) :   pow(Val))
#define powf(Val)   ((sizeof(Val)!=sizeof(float)) ? cpowf(Val) :   powf(Val))
#define powl(Val)   ((sizeof(Val)!=sizeof(long double)) ? cpowl(Val) :   powl(Val))

#define sin(Val)   ((sizeof(Val)!=sizeof(double)) ? csin(Val) :   sin(Val))
#define sinf(Val)   ((sizeof(Val)!=sizeof(float)) ? csinf(Val) :   sinf(Val))
#define sinl(Val)   ((sizeof(Val)!=sizeof(long double)) ? csinl(Val) :   sinl(Val))

#define sinh(Val)  ((sizeof(Val)!=sizeof(double)) ? csinh(Val) :  sinh(Val))
#define sinhf(Val)  ((sizeof(Val)!=sizeof(float)) ? csinhf(Val) :  sinhf(Val))
#define sinhl(Val)  ((sizeof(Val)!=sizeof(long double)) ? csinhl(Val) :  sinhl(Val))

#define sqrt(Val)  ((sizeof(Val)!=sizeof(double)) ? csqrt(Val) :  sqrt(Val))
#define sqrtf(Val)  ((sizeof(Val)!=sizeof(float)) ? csqrtf(Val) :  sqrtf(Val))
#define sqrtl(Val)  ((sizeof(Val)!=sizeof(long double)) ? csqrtl(Val) :  sqrtl(Val))

#define tan(Val)   ((sizeof(Val)!=sizeof(double)) ? ctan(Val) :   tan(Val))
#define tanf(Val)   ((sizeof(Val)!=sizeof(float)) ? ctanf(Val) :   tanf(Val))
#define tanl(Val)   ((sizeof(Val)!=sizeof(long double)) ? ctanl(Val) :   tanl(Val))

#define tanh(Val)  ((sizeof(Val)!=sizeof(double)) ? ctanh(Val) :  tanh(Val))
#define tanhf(Val)  ((sizeof(Val)!=sizeof(float)) ? ctanhf(Val) :  tanhf(Val))
#define tanhl(Val)  ((sizeof(Val)!=sizeof(long double)) ? ctanhl(Val) :  tanhl(Val))



#endif /* End of _TGMATH_H */
#pragma Pop (List)

/**************************************
	End of File TGMATH.H
***************************************/
