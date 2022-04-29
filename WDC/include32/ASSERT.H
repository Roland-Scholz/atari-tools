/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   ASSERT.h
*
* TITLE:       This function prototypes and data type definitions for the Assert Function.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Assert function.
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


#ifndef __ASSERT_H 
#define __ASSERT_H

#ifndef NDEBUG
void _assert(char *, char *, unsigned int);
#define assert(x) (x == 0 ? _assert(#x, __FILE__, __LINE__):(void)0)
#else
#define assert(x)	((void)0)
#endif

#endif  // End of __AAert_H


/**************************************************/
/*    End of File ASSERT.H                        */
/**************************************************/

