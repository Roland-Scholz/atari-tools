/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   STDLIB.h
*
* TITLE:       This function prototypes and data type definitions for the
*               Standard Library Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Standard Library functions.
*
*
* SPECIAL CONSIDERATIONS:
*	        <None>
*
* AUTHOR:      R. Greenthal
*
*
* CREATION DATE:  March 31,2004
*
* REVISION HISTORY
*    Name           Date         Description
*    ------------   ----------   ----------------------------------------------
*    R. Greenthal   03/31/2004   Initial
*                   07/13/2004	 Removed ltostr, will add later & lltostr
*                   0x/xx/2004	  
*
*******************************************************************************
*/


#ifndef __STDLIB_H
#define __STDLIB_H


#ifndef _WCHAR_T
#include <stddef.h>		// Define size_t, wchar_t, NULL
#endif


# ifndef ERANGE
#define ERANGE 13
# endif


#define EXIT_FAILURE (-1)
#define EXIT_SUCCESS 0

#ifdef __FLOATS__
#define HUGE_VAL	1.797693134862316E+308
#endif

#define RAND_MAX 32767

#define	MB_CUR_MAX	1
#define	MB_LEN_MAX	1

			/* quotient and remainder for div() */
typedef struct {
	int quot;
	int rem;
} div_t;


			/* quotient and remainder for ldiv() */
typedef struct {
	long quot;
	long rem;
} ldiv_t;

			/* quotient and remainder for lldiv() */
/*
typedef struct {
	long long quot;
	long long rem;
} lldiv_t;
*/



struct int_sqrt {
      unsigned sqrt;
      unsigned frac;
};


void	abort(void);
int 	abs(int _j);
int 	atexit(void (*_func)(void));
double	atof(const char *);			// Ascii to Float
int	atoi(const char *_nptr);		// Ascii to Integer
long	atol(const char *_nptr);		// Converts string pointed to by nptr to long int representation
/*
long long int atoll(const char *_nptr);		// Converts string pointed to by nptr to long int representation
*/
void   *bsearch(const void *_key, const void *_base, size_t _nmemb, size_t _size,
					int (*_compar)(const void *, const void *));
void   *calloc(size_t _nmemb, size_t _size);
div_t	div(int _numer, int _denom);
void	exit(int _status);
void	free(void *_ptr);
char   *getenv(const char *_name);
long	labs(long int _j);
//long long int llabs( long long int j); 
ldiv_t	ldiv(long int _numer, long int _denom);
//lldiv_t	lldiv(long long int _numer, long long int _denom);
void   *malloc(size_t _size);
int	mblen(const char *_s, size_t _n);
size_t	mbstowcs(wchar_t *_pwcs, const char *_s, size_t _n);
int 	mbtowc(wchar_t *_pwc, const char *_s, size_t _n);
void	qsort(void *_base, size_t _nmemb, size_t _size,
					int (*_compar)(const void *, const void *));
int	rand(void);
void   *realloc(void *_ptr, size_t _size);
void	srand(unsigned int _seed);

#define strtodf strtof						// strtof is the same as strtodf

double	strtod(const char *_nptr, char **_endptr);		// converts the string pointed to a double
double	strtodf(const char *_nptr, char **_endptr);		// same as strtodf, but for float

long double strtold(const char *_nptr, char **_endptr);		// same as strtod, but for long double
long	strtol(const char *_nptr, char **_endptr, int _base);
unsigned long strtoul(const char *_nptr, char **_endptr, int _base);
/*
unsigned long long strtoull(const char *_nptr, char **_endptr, int _base);
*/
int 	system(const char *_string);
int 	wctomb(char *_s, wchar_t _wchar);
size_t 	wcstombs(char *_s, const wchar_t *_pwcs, size_t _n);



/*****************************/
/*    NON ANSI C functions   */
/*    System V Berkley       */
/*    UNIX/Linux             */
/*****************************/

int putenv (char *string);
int setenv (char *name, char *value, int replace);




/*****************************/
/*    NON ANSI C functions   */
/*****************************/
//int _atoi(ptr);				/* decode an integer */
int	atoib(char *s, int b);			/* Convert s to "unsigned" integer in base b. */
int	dtoi(char *decstr, int *);		/* convert signed decimal string to integer number */
void	ftoa(double _val, char *_buf, int, int);
//int	isatty(int );				/* Return "true" if fd is a device, else "false" */
int	iscons(int );				/* kludge.  need a way to tell what iocb is open on */
void	itoa(int value, char string[], int radix);	/* Converts integer to ASCII string */
int	itoab(int , char *, int );		/* Convert "unsigned" n to characters in s using base b */
char   *itoo(int , char str[], int );	 	/* converts number to octal string of length sz */
char   *ltoa(long val, char *buf, int base);	/* convert a long int to the specified numeric base, from 2 to 36. */
//char   *ltostr(long num, char *string, size_t max_chars, unsigned base);	/* Convert a long int to a String */

int	otoi(char *, int *);			/* convert unsigned octal string to integer number */
int    _parseline(char *line, int *);		/* line-parsing routine */
int	round_div(int n, int d);		/* Rounded integer division */
long	round_ldiv(long n, long d);		/* Rounded long integer division */

//char   *ultoa(unsigned long value, char *digits, int base);	/* Convert Unsigned Long (32 bits) to ASCII string */
//void	usqrt(unsigned long x, struct int_sqrts *q);		/* squar root of a "long" integer */
int	utoi(char *, int *);			/* convert unsigned decimal string to integer number */
int	xtoi(char *, int *);			/* convert hex string to integer number */



/*********************************************/
/* Should be in MALLOC.H or ALLOC.H          */
/*********************************************/
/************************/
/* NON ANSI C functions */
/************************/
#ifndef _ANSI
void far *farcalloc(unsigned long _nmemb, unsigned long _size);
void farfree(void far *_ptr);
void far *farmalloc(unsigned long _size);
void far *farrealloc(void far *_ptr, unsigned long _size);
#endif




#ifdef __FLOATS__
long double strtold(const char *_nptr, char **_endptr);
#endif


#endif	/* __STDLIB_H */

/**************************************************/
/*    End of File STDLIB.H                        */
/**************************************************/

