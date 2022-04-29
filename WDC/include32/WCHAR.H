/*******************************************************************************
* FILE NAME:   WCHAR.h
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
*    R. Greenthal   03/15/2004   Initial
*                   0x/xx/2004	 Added 
*
*******************************************************************************
*/

#ifndef __WCHAR_H
#define __WCHAR_H

#include <stdio.h>		// Define FILE

#ifndef _VA_LIST
#include <stdarg.h>		// Define va_list
#endif

#ifndef _WCHAR_T
#include <stddef.h>		// Define size_t, wint_t, wchar_t, NULL
#endif

#ifndef __TM
#include <time.h>		// Define tm
#endif




/*
 *=========================== CONSTANTS & MACROS ===============================
 */



typedef int	mbstate_t;



/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */


int fwprintf(FILE *stream, const wchar_t *format, ...); 
int fwscanf(FILE *stream, const wchar_t *format, ...); 
int swprintf( wchar_t *s, size_t n, const wchar_t *format, ...); 
int swscanf( const wchar_t *s, const wchar_t *format, ...); 
int vfwprintf(FILE *stream, const wchar_t *format, va_list arg);
int vfwscanf(FILE *stream, const wchar_t *format, va_list arg); 
int vswprintf( wchar_t *s, size_t n, const wchar_t *format, va_list arg); 
int vswscanf( const wchar_t *s, const wchar_t *format, va_list arg); 
int vwprintf( const wchar_t *format, va_list arg); 
int vwscanf(const wchar_t *format, va_list arg);
int wprintf( const wchar_t *format, ...); 
int wscanf( const wchar_t *format, ...); 
wint_t fgetwc( FILE *stream); 
wchar_t *fgetws( wchar_t *s, int n, FILE *stream); 
wint_t fputwc( wchar_t c, FILE *stream); 
int fputws( const wchar_t *s, FILE *stream); 
int fwide( FILE *stream, int mode); 
wint_t getwc( FILE *stream); 
wint_t getwchar( void); 
wint_t putwc( wchar_t c, FILE *stream); 
wint_t putwchar( wchar_t c); 
wint_t ungetwc( wint_t c, FILE *stream); 
double wcstod( const wchar_t *nptr, wchar_t **endptr); 
float wcstof( const wchar_t *nptr, wchar_t **endptr); 
long double wcstold( const wchar_t *nptr, wchar_t **endptr); 
long int wcstol( const wchar_t *nptr, wchar_t **endptr, int base); 
//long long int wcstoll( const wchar_t *nptr, wchar_t **endptr, int base); 
unsigned long int wcstoul( const wchar_t *nptr, wchar_t **endptr, int base); 
//unsigned long long int wcstoull( const wchar_t *nptr, wchar_t **endptr, int base); 
wchar_t *wcscpy( wchar_t *s1, const wchar_t *s2); 
wchar_t *wcsncpy( wchar_t *s1, const wchar_t *s2, size_t n); 
wchar_t *wcscat( wchar_t *s1, const wchar_t *s2); 
wchar_t *wcsncat( wchar_t *s1, const wchar_t *s2, size_t n); 
int wcscmp( const wchar_t *s1, const wchar_t *s2); 
int wcscoll( const wchar_t *s1, const wchar_t *s2); 
int wcsncmp( const wchar_t *s1, const wchar_t *s2, size_t n); 
size_t wcsxfrm( wchar_t *s1, const wchar_t *s2, size_t n); 
wchar_t *wcschr( const wchar_t *s, wchar_t c); 
size_t wcscspn( const wchar_t *s1, const wchar_t *s2); 
size_t wcslen( const wchar_t *s); 
wchar_t *wcspbrk( const wchar_t *s1, const wchar_t *s2); 
wchar_t *wcsrchr( const wchar_t *s, wchar_t c); 
size_t wcsspn( const wchar_t *s1, const wchar_t *s2); 
wchar_t *wcsstr( const wchar_t *s1, const wchar_t *s2); 
wchar_t *wcstok( wchar_t *s1, const wchar_t *s2, wchar_t **ptr); 
wchar_t *wmemchr( const wchar_t *s, wchar_t c, size_t n); 
int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n); 
wchar_t *wmemcpy( wchar_t *s1, const wchar_t *s2, size_t n); 
wchar_t *wmemmove( wchar_t *s1, const wchar_t *s2, size_t n); 
wchar_t *wmemset( wchar_t *s, wchar_t c, size_t n); 
size_t wcsftime( wchar_t *s, size_t maxsize, const wchar_t *format, const struct tm *timeptr); 
wint_t btowc( int c); //* 
int wctob( wint_t c); 
int mbsinit( const mbstate_t *ps); 
size_t mbrlen( const char *s, size_t n, mbstate_t *ps); 
size_t mbrtowc( wchar_t*  pwc, const char *s, size_t n, mbstate_t *ps); 
size_t wcrtomb( char *s, wchar_t wc, mbstate_t *ps); 
size_t mbsrtowcs( wchar_t *dst, const char **src, size_t len, mbstate_t *ps); 
size_t wcsrtombs( char *dst, const wchar_t **src, size_t len, mbstate_t *ps); 


#endif /* End of __WCHAR_H */

/**************************************
	End of File WCHAR.H
***************************************/
