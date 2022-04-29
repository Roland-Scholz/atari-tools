/*******************************************************************************
* FILE NAME:   INTTYPES.h
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
* CREATION DATE:  March 27,2004
*
* REVISION HISTORY
*    Name           Date         Description
*    ------------   ----------   ----------------------------------------------
*    R. Greenthal   03/25/2004   Initial
*                   0x/xx/2004	 Added 
*
*******************************************************************************
*/

#ifndef _INTTYPES_H
#define _INTTYPES_H


/*
 *=========================== CONSTANTS & MACROS ===============================
 */

#ifndef _WCHAR_T
#define _WCHAR_T
typedef char wchar_t;
#endif


typedef signed char		int8_t;
typedef unsigned char		uint8_t;
typedef int			int16_t;
typedef unsigned int		uint16_t;
typedef long			int32_t;
typedef unsigned long		uint32_t;
//typedef long long		int64_t;
//typedef unsigned long long	uint64_t;
typedef int16_t			intptr_t;
typedef uint16_t		uintptr_t;

//typedef long long		intmax_t;	/* Max size of int */
//typedef unsigned long	long	uintmax_t;	/* Max size of uint */
typedef long			intmax_t;
typedef unsigned long		uintmax_t;


//#define	INTMAX_MAX		63	/* Max size of long long */
//#define	INTMAX_MIN		15	/* Max size of int */
//#define	UINTMAX_MAX		64	/* Max size of unsigned long long */
#define	INTMAX_MAX		31	/* Max size of long */
#define	INTMAX_MIN		15	/* Max size of int */
#define	UINTMAX_MAX		32	/* Max size of unsigned long */


/*
	type defined by this header (only)
*/

typedef struct
	{
	intmax_t	quot;		/* member order must match function */
	intmax_t	rem;
}imaxdiv_t;


#define	WCHAR_MIN		0


/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */




intmax_t strtoimax(register const char *nptr, wchar_t **endptr, register int base);
uintmax_t strtoumax(register const char *nptr, wchar_t **endptr, register int base);
intmax_t wcstoimax(register const char *nptr, wchar_t **endptr, register int base);
uintmax_t wcstoumax(register const wchar_t *nptr, wchar_t **endptr, register int base);

/***************/
/* Non ANSI    */
/***************/
intmax_t imaxabs(intmax_t j);
imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom);


#endif /* End of _INTTYPES_H */
#pragma Pop (List)

/**************************************
	End of File INTTYPES.H
***************************************/
