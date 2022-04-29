/*******************************************************************************
* FILE NAME:   STDARG.h
*
* TITLE:       This function prototypes and data type definitions for the
*               Standard Arguments Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Standard Arguments functions.
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
*                   0x/xx/2004	 Added 
*
*******************************************************************************
*/


#ifndef __STDARG_H
#define __STDARG_H

#define _VA_LIST
typedef char *va_list;

#define va_start(ap, parmN) ((ap) = (char *)(&parmN + 1))
#define va_arg(ap, type) ((ap) += sizeof(type), ((type *)(ap))[-1])
#define va_end(ap)

#endif  // End of __STDARG_H

/**************************************************/
/*    End of File STDARG.H                        */
/**************************************************/

