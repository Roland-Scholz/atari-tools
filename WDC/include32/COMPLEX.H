/*******************************************************************************
* FILE NAME:   COMPLEX.h
*
* TITLE:       This function prototypes and data type definitions for the Complex Math Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Complex Math functions.
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
*    R. Greenthal   03/15/2004   Initial
*                   0x/xx/2004	 Added 
*
*******************************************************************************
*/

#ifndef _COMPLEX_H
#define _COMPLEX_H


/*
 *=========================== CONSTANTS & MACROS ===============================
 */


/***********************************
	Special Structures Used by
	Double Precision Complex
	Math Functions
************************************/

typedef struct {double r; double i;} Complex;
typedef Complex far* Complex_Vector;
typedef Complex *Complex_Ptr;

/***********************************
	Special Structures Used by
	Single Precision Complex
	Math Functions
************************************/

typedef struct {float r; float i;} f_Complex;
typedef f_Complex far* f_Complex_Vector;


/***********************************
	Special Structures Used by
	Long Double Precision Complex
	Math Functions
************************************/

typedef struct {long double r; long double i;} ld_Complex;
typedef ld_Complex far* ld_Complex_Vector;



//typedef double _Complex Complex
//typedef float _Complex f_Complex
//typedef long double _Complex ld_Complex


/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */


//**************************
// Simple Complex Functions
//**************************
Complex complx(double , double );		// Convert 2 doubles to a Complex variable
f_Complex complxf(float , float );
ld_Complex Complxl(long double , long double );

double cabs(Complex );				// Absolute value of a Complex number
float cabsf(f_Complex );
long double cabsl(ld_Complex );

Complex cadd(Complex , Complex );		// Add two Complex numbers
f_Complex caddf(f_Complex , f_Complex );
ld_Complex caddl(ld_Complex , ld_Complex );

Complex csub(Complex , Complex );		// Subtract two Complex numbers
f_Complex csubf(f_Complex , f_Complex );
ld_Complex csubl(ld_Complex , ld_Complex );

Complex cmul(Complex , Complex );		// Multiply two Complex numbers
f_Complex cmulf(f_Complex , f_Complex );
ld_Complex cmull(ld_Complex , ld_Complex );

Complex cdiv(Complex , Complex );		// Divide two Complex numbers
f_Complex cdivf(f_Complex , f_Complex );
ld_Complex cdivl(ld_Complex , ld_Complex );

Complex conj(Complex );				// Conjugate of a Complex number
f_Complex conjf(f_Complex );			// Conjugate of a Complex number
ld_Complex conjl(ld_Complex );			// Conjugate of a Complex number

double creal(Complex z);			// Real part of a complex #
float crealf(f_Complex z);
long double creall(ld_Complex z);

double cimag(Complex z);			// Imaginary part of a complex #
float cimagf(f_Complex z);
long double cimagl(ld_Complex z);


//***********************************************
// Complex Functions
//***********************************************



double cmag(Complex );				// Magnitude of a Complex number
Complex cscalr(Complex , double );		// Multiply a complex number, x, by a real number, y



double carg(Complex z);				// Calculate the Complex argument
float cargf(f_Complex z);
long double cargl(ld_Complex z);

Complex cacos(Complex z);			// Complex circular arc cosine
f_Complex cacosf(f_Complex z);
ld_Complex cacosl(ld_Complex z);

Complex cacosh(Complex z);			// Complex inverse hyperbolic cosineComplex casin(Complex z);			// Complex circular arc sine
f_Complex cacoshf(f_Complex z);
ld_Complex cacoshl(ld_Complex z);

Complex casin(Complex z);			// Complex inverse sine
f_Complex casinf(f_Complex z);
ld_Complex casinl(ld_Complex z);

Complex casinh(Complex z);			// Complex inverse hyperbolic sine
f_Complex casinhf(f_Complex z);
ld_Complex casinhl(ld_Complex z);

Complex catan(Complex z);			// Complex circular arc tangent
f_Complex catanf(f_Complex z);
ld_Complex catanl(ld_Complex z);

Complex catanh(Complex z);			// Complex inverse hyperbolic tangent
f_Complex catanhf(f_Complex z);
ld_Complex catanhl(ld_Complex z);

Complex ccos(Complex z);			// Complex circular cosine
f_Complex ccosf(f_Complex z);
ld_Complex ccosl(ld_Complex z);

Complex ccosh(Complex z);			// Complex hyperbolic cosine
f_Complex ccoshf(f_Complex z);
ld_Complex ccoshl(ld_Complex z);

Complex ccot(Complex z);			// Complex circular cotangent
f_Complex ccotf(f_Complex z);
ld_Complex ccotl(ld_Complex z);

Complex cexp(Complex z);			// Exponential of the complex argument z
f_Complex cexpf(f_Complex z);
ld_Complex cexpl(ld_Complex z);

Complex clog(Complex z);			// Complex logarithm to the base e
f_Complex clogf(f_Complex z);
ld_Complex clogl(ld_Complex z);

Complex cpow(Complex a, Complex z);		// Complex power function
f_Complex cpowf(f_Complex a, f_Complex z);
ld_Complex cpowl(ld_Complex a, ld_Complex z);

Complex csin(Complex z);			// Complex circular sine
f_Complex csinf(f_Complex z);
ld_Complex csinl(ld_Complex z);

Complex csinh(Complex z);			// Complex hyperbolic sine
f_Complex csinhf(f_Complex z);
ld_Complex csinhl(ld_Complex z);

Complex csqrt(Complex );			// Square Root of a Complex number
f_Complex csqrtf(f_Complex );			
ld_Complex csqrtl(ld_Complex );	

Complex ctan(Complex z);			// Complex circular tangent
f_Complex ctanf(f_Complex z);
ld_Complex ctanl(ld_Complex z);

Complex ctanh(Complex z);			// Complex hyperbolic tangent
f_Complex ctanhf(f_Complex z);
ld_Complex ctanhl(ld_Complex z);

double modulus(Complex z);			// sqrt(z.real * z.real + z.imag * z.imag)
float modulusf(f_Complex z);
long double modulusl(ld_Complex z);

double phase(Complex z);			// atan(z.i / z.r)
float phasef(f_Complex z);
long double phasel(ld_Complex z);




//***********************************************
// DSP/FFT Functions
//***********************************************

void fft42(Complex_Vector data, unsigned n, int isign);	// Computes the FFT using a "radix-4+2" algorithm
void fft42f(f_Complex_Vector data, unsigned n, int isign);

void fftrad2(Complex_Vector data, unsigned n, int isign);




// Symmetric FIR bandpass filter using a Kaiser-Bessel window
//double *Cpowspec(Complex_Vector v, unsigned nv, unsigned npw, double *w);
//                     


#endif /* End of _COMPLEX_H */
#pragma Pop (List)

/**************************************
	End of File COMPLEX.H
***************************************/
