/*******************************************************************************
* FILE NAME:   STDDEF.h
*
* TITLE:       This function prototypes and data type definitions for the Std Defs.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Standard Defs.
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

#ifndef __STDDEF_H 
#define __STDDEF_H

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

#ifndef _PTRDIFF_T
#define _PTRDIFF_T
#ifdef _LARGE_DATA
	typedef long ptrdiff_t;
#else
	typedef short ptrdiff_t;
#endif
#endif

#ifndef _WCHAR_T
#define _WCHAR_T
	typedef unsigned char wchar_t;
#endif

#ifndef _WINT_T
#define _WINT_T
        typedef unsigned int wint_t;         /* Wide character */
#endif

#ifndef _WCTYPE_T
#define _WCTYPE_T
        typedef unsigned int wctype_t;         /* Wide  */
#endif

#ifndef _WEOF
#define _WEOF
#define WEOF	(wint_t)(-1)
#endif /* _WEOF */


#ifndef NULL
#define NULL ((void *)0)
#endif


#ifndef ERRNO
extern int errno;
#endif

#define offsetof(type,memb) ((size_t)((unsigned long)&((type *)0)->memb))

#endif  // End of __STDDEF_H

/**************************************************/
/*    End of File STDDEF.H                        */
/**************************************************/

