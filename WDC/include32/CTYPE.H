/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   TGMATH.h
*
* TITLE:       This function prototypes and data type definitions for the Character Types.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Character Typess.
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


#ifndef __CTYPE_H
#define __CTYPE_H

extern char _ctype[];

#define	_U	0x01	/* Upper-case	*/
#define	_L	0x02	/* Lower-case	*/
#define	_D	0x04	/* Decimal-digit */
#define	_H	0x08	/* Hex-digit	*/
#define	_W	0x10	/* White-space	*/
#define	_C	0x20	/* Control char	*/
#define	_P	0x40	/* Punctuation	*/
#define	_B	0x80	/* Blank		*/

int isalnum(int _c);
int isalpha(int _c);
int iscntrl(int _c);
int isdigit(int _c);
int isgraph(int _c);
int islower(int _c);
int isprint(int _c);
int ispunct(int _c);
int isspace(int _c);
int isupper(int _c);
int isxdigit(int _c);
int tolower(int _c);
int toupper(int _c);
/**************************/
/*  NON-ANSI - Systtem V  */
/**************************/
int isascii(int _c);
//int  isatty(int fd);		//TBD
int	toascii(int );				/* return ASCII equivalent of c */ 

//#define iswhite(x)	((_ctype+1)[x]&(_W))		//TBD
//#define isodigit(x)	((_ctype+1)[x]&(_W))		//TBD Is Octal 0-7
//int _tolower(int c);
//int _toupper(int c);


#ifdef __C_MACROS__
#define isalpha(x)	((_ctype+1)[x]&(_L|_U))
#define isupper(x)	((_ctype+1)[x]&(_U))
#define islower(x)	((_ctype+1)[x]&(_L))
#define isdigit(x)	((_ctype+1)[x]&(_D))
#define isxdigit(x)	((_ctype+1)[x]&(_H))
#define isalnum(x)	((_ctype+1)[x]&(_L|_U|_D))
#define isspace(x)	((_ctype+1)[x]&(_W))
#define ispunct(x)	((_ctype+1)[x]&(_P))
#define iscntrl(x)	((_ctype+1)[x]&(_C))
#define isprint(x)	((_ctype+1)[x]&(_P|_L|_U|_D|_B))
#define isgraph(x)	((_ctype+1)[x]&(_P|_L|_U|_D))
#define isascii(x)	(((x)&0x80)==0)
//#define iswhite(x)	((_ctype+1)[x]&(_W))		//TBD
//#define isodigit(x)	((_ctype+1)[x]&(_W))		//TBD Is Octal 0-7
#endif

#define toascii(x) ((x)&0x7f)
#define _tolower(x) ((x)-'a'+'A')
#define _toupper(x) ((x)-'A'+'a')

#endif /* _CTYPE_H */


/**************************************************/
/*    End of File CTYPE.H                         */
/**************************************************/

