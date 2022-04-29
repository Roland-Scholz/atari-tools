/* Copyright (C) 1993 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   MATH.h
*
* TITLE:       This function prototypes and data type definitions for the Math Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for General purpose Math functions.
*
*              Double precison floating point format:
*
*              6 6      5 5            0
*              3 2      2 1            0
*             ___________________________
*             |s|exponent|   fraction   |
*             +-+--------+--------------+
*
*
*              Single/Float precison floating point format:
*
*              3 3      2 2            0
*              1 0      X X            0
*             ___________________________
*             |s|exponent|   fraction   |
*             +-+--------+--------------+
*
*
*              Long Double precison floating point format:
*
*              1 1      1
*              2 2      X X            0
*              7 6      X X            0
*             ___________________________
*             |s|exponent|   fraction   |
*             +-+--------+--------------+
*
*
*
*
* SPECIAL CONSIDERATIONS:
*	        <None>
*
* AUTHOR:      R. Greenthal
*
*
* CREATION DATE:  November 17,2003
*
* REVISION HISTORY
*    Name           Date         Description
*    ------------   ----------   ----------------------------------------------
*    Jim Goodnow     1993         Initial
*    R. Greenthal   11/17/2003   Added Single Precision Math Functions
*                                 And templates for "long double" - 128 bit Math
*                                 
*                   01/21/2004	Added cadd, asinh, rad2deg, etc.
*                   01/29/2004	Added constants
*                   02/05/2004	Added more Gamma, FFT, & Bessel Functions
*                   02/18/2004	Added Integra...
*                   03/08/2004	Added Transcendental with built in Rad/Deg/Grad
*                   0x/xx/2004	Added 
*
*******************************************************************************
*/

#ifndef _MATH_H
#define _MATH_H



#include <sys/types.h>

/*
 *=========================== CONSTANTS & MACROS ===============================
 */


#ifndef _FLOAT_T
#define _FLOAT_T
typedef float	float_t;
#endif


#ifndef _DOUBLE_T
#define _DOUBLE_T
typedef double	double_t;
#endif

#define FP_INFINITE  2
#define FP_NAN       3
#define FP_NORMAL    1
#define FP_SUBNORMAL 1
#define FP_ZERO      4

#define FP_FAST_FMA 
 
#define FP_FAST_FMAF FP_FAST_FMA
#define FP_FAST_FMAL FP_FAST_FMA

#define FP_ILOGB0     -INT_MAX
#define FP_ILOGBNAN    INT_MAX


#define fpclassify(x) _fpclassify(x)
#define isfinite(x) _isfinite(x)
#define isinf(x) _isinf(x)
#define isnan(x) _isnan(x)
#define isnormal(x) _isfinite(x)
#define signbit(x) _signbit(x)

#define           NAN                  nan("255")




#define      SIGDIGLEN      36            // significant decimal digits
#define      DECSTROUTLEN   80            // max length for dec2str output
#define      FLOATDECIMAL   ((char)(0))
#define      FIXEDDECIMAL   ((char)(1))



/***********************************
	Limiting Constants Used by
	Double Precision Functions
************************************/

#define HUGE_VAL	1.797693134862316E+308
#define LOGHUGE		(709.778)
#define TINY_VAL	(2.2e-308)
#define LOGTINY		(-708.396)


// We are currently EQUATING long double & double
//#define         LONG_DOUBLE_SIZE     16		// 128 Bits/16 Bytes
#define           LONG_DOUBLE_SIZE     8		// 64 Bits/8 Bytes

#define           DOUBLE_SIZE          8		// 64 Bits/8 Bytes
//#define           HUGE_VAL             __inf()
#define           INFINITY             __inf()
//#define HUGE_VAL        INFINITY

#define HUGE_VALF  HUGE_VAL
#define HUGE_VALL  HUGE_VAL


/***********************************
	General Math Constants Used by
	Double Precision Functions
	(20 places to the Right of
	 the Decimal point)
************************************/

#define PI		3.14159265358979323846
#define PIOVR2		1.57079632679489661923		// PI/2
#define M_1_PI		0.318309886183790671538		// 1/PI
#define PI2		6.28318530717958647692		// 2*PI
#define SIN45		0.70710678118654752440		// SIN(45 degrees)
#define	SQRT2		1.41421356237309504880		// SQRT(2)
#define LN2		0.69314718055994530942		// Ln 2 constant
#define EULER		0.577215664901532860607		// Euler number
#define LN10		2.30258509299404568402		// ln(10)
#define SQRTPI		1.77245385090551602730		// sqrt(PI)
#define	LOG10E		0.43429448190325182765		// Log(e)
//#define 180_PI		57.2957795130823208768		// One Radian in degrees = 180/PI
//#define 
//#define	M_3PI_4		2.35619449019234492884698253745962716
//#define	M_3PI_8		1.17809724509617246442349126872981358
//#define	M_PI_4		0.78539816339744830961566084581987572
//#define	M_PI_8		0.39269908169872415480783042290993786
//#define	M_1_PI		0.31830988618379067153776752674502872
//#define	M_2_PI		0.63661977236758134307553505349005744
//#define	M_4_PI		1.27323954473516268615107010698011488
#define	M_E		2.71828182845904523536028747135266250	//constant "e"
//#define	M_1_SQRT2	0.70710678118654752440084436210484904
#define	LOGPI		1.14472988584940017414

/***********************************
	Limiting Constants Used by
	Single Precision Functions
************************************/

#define FLT_HUGE_VAL	1.797693135E+308f
#define FLT_LOGHUGE	709.778f
#define FLT_TINY_VAL	2.2e-308f
#define FLT_LOGTINY	-708.396f


/***********************************
	General Math Constants Used by
	Double Precision Functions
	(xx places to the Right of
	 the Decimal point)
************************************/

#define F_PI		3.141592653f
#define F_PIOVR2	1.570796327f		// PI/2
#define F_PI2		6.283185307f		// 2*PI
#define F_SIN45		0.707106781f		// SIN()
#define	F_SQRT2		1.414213562f		// SQRT(2)
#define F_LN2		0.693147181f		// Ln 2 constant
#define F_LN10		2.302585092f		// ln(10)
#define	F_LOG10E	0.434294481f		// Log(e)


/***********************************
	Limiting Constants Used by
	Long Double Precision Functions
************************************/

#define LDBL_HUGE_VAL	1.797693134862316E+308L
#define LDBL_LOGHUGE	709.778L
#define LDBL_TINY_VAL	2.2e-308L
#define LDBL_LOGTINY	-708.396L

/***********************************
	General Math Constants Used by
	Long Double Precision Functions
	(xx places to the Right of
	 the Decimal point)
************************************/

#define LDBL_PI		3.14159265358979323846L
#define LDBL_PI2	6.28318530717958647692L		// 2*PI
#define LDBL_PIOVR2	1.57079632679489661923L		// PI/2
#define LDBL_SIN45	0.70710678118654752440L		// SIN()
#define	LDBL_SQRT2	1.41421356237309504880L		// SQRT(2)
#define LDBL_LN2	0.69314718055994530942L		// Ln 2 constant
#define LDBL_LN10	2.30258509299404568402L		// ln(10)
#define	LDBL_LOG10E	0.43429448190325182765L		// Log(e)

//#define	M_PI		3.14159265358979323846264338327950288
//#define	M_2PI		6.28318530717958647692528676655900576
//#define	M_3PI_4		2.35619449019234492884698253745962716
//#define	M_PI_2		1.57079632679489661923132169163975144
//#define	M_3PI_8		1.17809724509617246442349126872981358
//#define	M_PI_4		0.78539816339744830961566084581987572
//#define	M_PI_8		0.39269908169872415480783042290993786
//#define	M_1_PI		0.31830988618379067153776752674502872
//#define	M_2_PI		0.63661977236758134307553505349005744
//#define	M_4_PI		1.27323954473516268615107010698011488
#define	M_E		2.71828182845904523536028747135266250	//constant "e"
//#define	M_LOG2E		1.44269504088896340735992468100189213
//#define	M_LOG10E	0.43429448190325182765112891891660508
//#define	M_LN2		0.69314718055994530941723212145817657
//#define	M_LN10		2.30258509299404568401799145468436421
//#define	M_SQRT2		1.41421356237309504880168872420969808
//#define	M_1_SQRT2	0.70710678118654752440084436210484904



/*
 *================================== TYPES =====================================
 */

#ifndef ERRNO
extern int errno;
#endif

struct exception {
    int type;      /* type of exception */
    char *name;    /* name of function */
    double arg1;   /* first argument to function */
    double arg2;   /* second argument to function */
    double retval; /* value to be returned if error is not fatal */
};

/* exception types */

#define DOMAIN    1   /* not in domain of function (i.e. number passed either to small or too large) */
#define SING      2   /* singularity (function not defined)(i.e. x/0) */
#define OVERFLOW  3   /* result too large */
#define UNDERFLOW 4   /* result too small */
#define TLOSS     5   /* total loss of precision */
#define PLOSS     6   /* partial loss of precision */




/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */



/************************************************************************************
 ************************************************************************************
		Double Precision Math Functions - (General ANSI Standard Functions)
*************************************************************************************
*************************************************************************************/


double acos(double);				// Arc Cosine
float acosf(float);
long double acosl(long double);

double acosh(double);				// Arc Hyperbolic Cosine
float acoshf(float);
long double acoshl(long double);

double asin(double);				// Arc Sine
float asinf(float);
long double asinl(long double);

double asinh(double);				// Arc Hyperbolic Sine
float asinhf(float);
long double asinhl(long double);

double atan(double);				// Arc Tangent
float atanf(float);
long double atanl(long double);

double atanh(double);				// Arc Hyperbolic Tangent
float atanhf(float);
long double atanhl(long double);

double atan2(double, double);			// Inverse tangent of y/x
float atan2f(float, float);
long double atan2l(long double, long double);

double atof(const char *);			// ASCII to Float

double cbrt(double );				// Cube Root
float cbrtf(float );
long double cbrtl(long double );

double ceil(double);				// Smallest integer >= argument (as double)
float ceilf(float );
long double ceill(long double );

double cos(double);				// Cosine of a Radian
float cosf(float);
long double cosl(long double);

double cosh(double);				// Hyperbolic Cosine
float coshf(float);
long double coshl(long double);

double cotan(double);				// Cotangent
float cotanf(float);
long double cotanl(long double);

double deg2rad(double );			// Degrees to Radians
float deg2radf(float );
long double deg2radl(long double);

//double drand(int n);				//

double exp(double);				// Natural ("e") Exponential (e^x)
float expf(float);
long double expl(long double);

double fabs(double);				// Floating Absolute value
float fabsf(float);
long double fabsl(long double);

double floor(double);				// Largest integer <= argument
float floorf(float );
long double floorl(long double );

double fma(double x, double y, double z);	// Calculate (x * y) + z
float fmaf(float x, float y, float z);		// Calculate (x * y) + z
long double fmal(long double x, long double y, long double z);

double fmod(double, double);			// Floating modulus
float fmodf(float, float);
long double fmodl(long double, long double);

double frexp(double, int *);			// Returns the mantissa of the floating point number
float frexpf(float, int *);
long double frexpl(long double, int *);

double hypot(double x, double y);		// Calculate the Hypotenuse
float hypotf(float x, float y);			// 
long double hypotl(long double x, long double y); //

double ipow(double x, int n);		        // return x^n where n is an integer???????????????

double ldexp(double, int);			// Returns the value of x times 2 raised to the exp power
float ldexpf(float, int);
long double ldexpl(long double, int);

//long _lrand()

double log(double);				// Logarithm base "e" or natural
float logf(float);
long double logl(long double);

double log10(double);				// Logarithm base 10
float log10f(float);
long double log10l(long double);

double modf(double, double *);			// Return integer and fractional parts of number
float modff(float, float *);
long double modfl(long double, long double *);

double pseries(double , double coef[], unsigned );	// Expand polynomial series - sum = coef[0]+x*coef[1]+x^2*coef[2]+...+x^(n-1)*coef[n-1]

#if 0
#define pow(x,y) power(x,y)			// same as "pow"
#endif
#if 0
#define powf(x,y) powerf(x,y)
#endif
#if 0
#define powl(x,y) powerl(x,y)
#endif

double pow(double, double);			// Calculates "x" to the "y" power
float powf(float, float);
long double powl(long double, long double);

double rad2deg(double );			// Radians to Degrees
float rad2degf(float );
long double rad2degl(long double);

double sin(double);				// Sine of a Radian
float sinf(float);
long double sinl(long double);

double sinh(double);				// Hyperbolic Sine
float sinhf(float);
long double sinhl(long double);

double sqrt(double);				// Square Root
float sqrtf(float);
long double sqrtl(long double);

double tan(double);				// Tangent (Sine/Cosine) 
float tanf(float);
long double tanl(long double);

double tanh(double);				// Hyperbolic Tangent
float tanhf(float);
long double tanhl(long double);

double tgamma(double x);			// gamma function of the argument
float tgammaf(float x);
long double tgammal(long double x);


//long double atoldl(const char *);







//*******************************************************************
// Gamma & Error Functions
//*******************************************************************
double erf(double );				// Error Function
float erff(float );

double erfc(double );				// Error Function 
float erfcf(float );

double ierfc(double );				// Inverse Error Function
float ierfcf(float );

double gamma(double );				// Gamma function
float gammaf(float );

double lgamma(double );				// Log Gamma function
float lgammaf(float );

//******************
// Bessel Functions
//******************
double j0(double x);				// First Bessel function of the first kind (Order 0)
double j1(double x);				// Second Bessel function of the first kind (Order 1)
double jn(int n, double x);			// Bessel Function Order n of the first kind
double y0(double x);				// First Bessel function of the second Kind (Order 0)
double y1(double x);				// Second Bessel function of the second Kind
double yn(int n, double x);			// Bessel Function Order n of the second kind

double besi0_(double x);			// Zeroth order modified bessel function of first kind.




//*************************
// Error handling Functions
//*************************
double _domerr(char *name, double arg1, double arg2);
double _tloss(char *name, double arg1, double arg2);
double _ploss(char *name, double arg1, double arg2);
double _rangerr(char *name, double arg1, double arg2, double dflt);
int matherr(struct exception *x);
void matherr_(char *funcname, int errnum);



/************************************************************************************
 ************************************************************************************
 ************************************************************************************
                   N O N   A N S I
 ************************************************************************************
 ************************************************************************************
 ************************************************************************************
 ***********************************************************************************/






//*******************
// Calculus Functions
//*******************
double *convolve(double *data, int ndata, double weights[], int nweights,
                    int ndec, int itype, int isym, int *length);
double *deriv(double *data, double delta, int ndata);
double *integrat(double *xin, double dx, int ndata);


//******************
// Lowpass Filter Functions
// Smoothing Functions
//******************
void lowpass(double weights[], int nweights, double fc, double dB, int half);	// Digital Lowpass filter of uniform time intervals (a Kaiser-Bessel window)
double *smooth(double *data, int ndata, int factor);	// a Kaiser lowpass filter (Reduces the high frequency noise)

//******************
// DSP/FFT Functions
//******************
double stopbnd_(double );			// Used by bandpass() 
void bandpass(double weights[], int nweights, double fh, double fl,
              double dB, int half);
// Subroutine computes power spectral density of complex array v[] of length
//  nv and returns it in the real array pw[] length npw.
//double *powspec(double *v, unsigned nv, unsigned npw, double *w);
// Computes power spectral density of real array




/********************************************************************/
/* This library is concerned entirely with angles in general and    */
/* trigonometric functions in particular.                           */
/********************************************************************/

#ifndef ANGLE_TYPE
#define ANGLE_TYPE
enum angle_type {RAD, DEG, GRAD};
#endif

/********************************************************************/
/* The following three routines 'normalize' the supplied angle to   */
/* be within limits appropiate for the trigonemetric routines.      */
/* normalize_radians ensures that the supplied angle is between -PI */
/* and +PI, normalize_degrees between -180.0 and +180.0 and         */
/* normalize_grade between -200.0 and +200.0.  NOTE - ALL the       */
/* normal trigonometric functions normalize the angle before use,   */
/* and the inverse functions after.                                 */
/********************************************************************/

void normalize_radians(double *radians);
void normalize_radiansf(float *radians);
void normalize_radiansl(long double *radians);

void normalize_degrees(double *degrees);
void normalize_degreesf(float *degrees);
void normalize_degreesl(long double *degrees);

void normalize_grade(double *grade);
void normalize_gradef(float *grade);
void normalize_gradel(long double *grade);

/********************************************************************/
/* These six routines enable conversion, of angles, between         */
/* radians, degrees and grade.  NOTE there is no need to normalize  */
/* the angle to be converted before calling any of these routines   */
/* as they all call the appropriate normalisation routine.          */
/********************************************************************/

double radians_to_degrees(double radians);
float radians_to_degreesf(float radians);
long double radians_to_degreesl(long double radians);

double radians_to_grade(double radians);
float radians_to_gradef(float radians);
long double radians_to_gradel(long double radians);

double degrees_to_radians(double degrees);
float degrees_to_radiansf(float degrees);
long double degrees_to_radiansl(long double degrees);

double degrees_to_grade(double degrees);
float degrees_to_gradef(float degrees);
long double degrees_to_gradel(long double degrees);

double grade_to_radians(double grade);
float grade_to_radiansf(float grade);
long double grade_to_radiansl(long double grade);

double grade_to_degrees(double grade);
float grade_to_degreesf(float grade);
long double grade_to_degreesl(long double grade);

/********************************************************************/
/* The following six routines are the normal trigonometric          */
/* functions.                                                       */
/********************************************************************/

double sine(double angle, enum angle_type atype);
float sinef(float angle, enum angle_type atype);
long double sinel(long double angle, enum angle_type atype);

double cosine(double angle, enum angle_type atype);
float cosinef(float angle, enum angle_type atype);
long double cosinel(long double angle, enum angle_type atype);

double tangent(double angle, enum angle_type atype);
float tangentf(float angle, enum angle_type atype);
long double tangentl(long double angle, enum angle_type atype);

double secant(double angle, enum angle_type atype);
float secantf(float angle, enum angle_type atype);
long double secantl(long double angle, enum angle_type atype);

double cosecant(double angle, enum angle_type atype);
float cosecantf(float angle, enum angle_type atype);
long double cosecantl(long double angle, enum angle_type atype);

double cotangent(double angle, enum angle_type atype);
float cotangentf(float angle, enum angle_type atype);
long double cotangentl(long double angle, enum angle_type atype);

/********************************************************************/
/* The following six routines are the normal inverse trigonometric  */
/* functions.                                                       */
/********************************************************************/

double arc_sine(double x, enum angle_type outtype);
float arc_sinef(float x, enum angle_type outtype);
long double arc_sinel(long double x, enum angle_type outtype);

double arc_cosine(double x, enum angle_type outtype);
float arc_cosinef(float x, enum angle_type outtype);
long double arc_cosinel(long double x, enum angle_type outtype);

double arc_tangent(double x, enum angle_type outtype);
float arc_tangentf(float x, enum angle_type outtype);
long double arc_tangentl(long double x, enum angle_type outtype);

double arc_secant(double x, enum angle_type outtype);
float arc_secantf(float x, enum angle_type outtype);
long double arc_secantl(long double x, enum angle_type outtype);

double arc_cosecant(double x, enum angle_type outtype);
float arc_cosecantf(float x, enum angle_type outtype);
long double arc_cosecantl(long double x, enum angle_type outtype);

double arc_cotangent(double x, enum angle_type outtype);
float arc_cotangentf(float x, enum angle_type outtype);
long double arc_cotangentl(long double x, enum angle_type outtype);

/********************************************************************/
/* The following six routines are the hyperbolic trigonometric      */
/* functions.                                                       */
/********************************************************************/

double hyperbolic_sine(double angle, enum angle_type atype);
float hyperbolic_sinef(float angle, enum angle_type atype);
long double hyperbolic_sinel(long double angle, enum angle_type atype);

double hyperbolic_cosine(double angle, enum angle_type atype);
float hyperbolic_cosinef(float angle, enum angle_type atype);
long double hyperbolic_cosinel(long double angle, enum angle_type atype);

double hyperbolic_tangent(double angle, enum angle_type atype);
float hyperbolic_tangentf(float angle, enum angle_type atype);
long double hyperbolic_tangentl(long double angle, enum angle_type atype);

double hyperbolic_secant(double angle, enum angle_type atype);
float hyperbolic_secantf(float angle, enum angle_type atype);
long double hyperbolic_secantl(long double angle, enum angle_type atype);

double hyperbolic_cosecant(double angle, enum angle_type atype);
float hyperbolic_cosecantf(float angle, enum angle_type atype);
long double hyperbolic_cosecantl(long double angle, enum angle_type atype);

double hyperbolic_cotangent(double angle, enum angle_type atype);
float hyperbolic_cotangentf(float angle, enum angle_type atype);
long double hyperbolic_cotangentl(long double angle, enum angle_type atype);

/********************************************************************/
/* The following six routines are the hyperbolic inverse            */
/* trigonometric functions.                                         */
/********************************************************************/

double hyperbolic_arc_sine(double x, enum angle_type outtype);
float hyperbolic_arc_sinef(float x, enum angle_type outtype);
long double hyperbolic_arc_sinel(long double x, enum angle_type outtype);

double hyperbolic_arc_cosine(double x, enum angle_type outtype);
float hyperbolic_arc_cosinef(float x, enum angle_type outtype);
long double hyperbolic_arc_cosinel(long double x, enum angle_type outtype);

double hyperbolic_arc_tangent(double x, enum angle_type outtype);
float hyperbolic_arc_tangentf(float x, enum angle_type outtype);
long double hyperbolic_arc_tangentl(long double x, enum angle_type outtype);

double hyperbolic_arc_secant(double x, enum angle_type outtype);
float hyperbolic_arc_secantf(float x, enum angle_type outtype);
long double hyperbolic_arc_secantl(long double x, enum angle_type outtype);

double hyperbolic_arc_cosecant(double x, enum angle_type outtype);
float hyperbolic_arc_cosecantf(float x, enum angle_type outtype);
long double hyperbolic_arc_cosecantl(long double x, enum angle_type outtype);

double hyperbolic_arc_cotangent(double x, enum angle_type outtype);
float hyperbolic_arc_cotangentf(float x, enum angle_type outtype);
long double hyperbolic_arc_cotangentl(long double x, enum angle_type outtype);

/********************************************************************/
/* The following four routines "complete" the standard library      */
/* functions.                                                       */
/********************************************************************/

double sech(double x);
float sechf(float x);
long double sechl(long double x);

double csch(double x);
float cschf(float x);
long double cschl(long double x);

double coth(double x);
float cothf(float x);
long double cothl(long double x);

double acoth(double x);
float acothf(float x);
long double acothl(long double x);



/************************************************************************************
 ************************************************************************************
		 (Special Embedded Functions)
                   NON ANSI
*************************************************************************************
*************************************************************************************/

char   *ecvt(double x, int digits, int *decimal, int *sign);	// Convert the Double Precision number to Character string
char   *fcvt(double x, int digits, int *decimal, int *sign);	// Convert the Double Precision number to Character string - almost same as ecvt - digits arg is diff
char   *gcvt(double x, int digits, char *buffer);		// Convert the Float Precision number to Character string

BOOL dtoa(char *szLabel, double dNumber, int nChars, BOOL bUseSciNot );

long Gcd(long a, long b);					// Greatest common divisor of a and b
//long long Gcd(long long a, long long b);

double Fac(long number);					// Factorial of a number
float Facf(int number);
//long double Facl(long long number);

#endif /* End of _MATH_H */
#pragma Pop (List)

/**************************************
	End of File MATH.H
***************************************/
