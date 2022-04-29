/*******************************************************************************
* FILE NAME:   WCTYPE.h
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
*              definitions used for wide character classification and
*              mapping utilities functions.
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

#ifndef __WCTYPE_H
#define __WCTYPE_H


/*
 *=========================== CONSTANTS & MACROS ===============================
 */

#ifndef _WCHAR_T
#include <stddef.h>		// Define size_t, wchar_t, NULL
#endif


#ifndef _WCTRANS_T
#define _WCTRANS_T
typedef unsigned long wctrans_t;
#endif


/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */





int iswalnum( wint_t wc); 
int iswalpha( wint_t wc); 
int iswcntrl( wint_t wc); 
int iswdigit( wint_t wc); 
int iswgraph( wint_t wc); 
int iswlower( wint_t wc); 
int iswprint( wint_t wc); 
int iswpunct( wint_t wc); 
int iswspace( wint_t wc); 
int iswupper( wint_t wc); 
int iswxdigit( wint_t wc); 
int iswctype( wint_t wc, wctype_t desc); 
int wctype( const char *property); 
wint_t towlower(wint_t wc); 
wint_t towupper(wint_t wc); 
wctrans_t wctrans( const char *property); 
wint_t towctrans( wint_t wc, wctrans_t desc); 


/****************************/
/*    NON ANSI - C99        */
/****************************/

int iswblank(wint_t wc);
int iswctrans(wint_t wc, unsigned int desc);


#endif /* End of __WCTYPE_H */

/**************************************
	End of File WCTYPE.H
***************************************/
