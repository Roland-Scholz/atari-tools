/* Copyright (C) 1993 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   SETJMP.h
*
* TITLE:       This function prototypes and data type definitions for the Setjmp Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Setjmp functions.
*
*              The <setjmp.h> header relates to the C phenomenon known as setjmp/longjmp.
*              It is used to escape out of the current situation into a previous one.
*              A typical example is in an editor, where hitting DEL breaks off the current
*              command and puts the editor back in the main loop, though care has to be
*              taken when the DEL occurs while executing a library function, since
*              some of them are not reentrant.
*
*
*
* SPECIAL CONSIDERATIONS:
*	        __SetJmp_Struct_802:		; Structure for SetJmp 
*               __SetJmp_PC	rmb	2	; actual Long Jump "to" address in code (16 bit Address)
*               __SetJmp_SP	rmb	1	; Don't need to save the Status Reg, X 0r Acc?
*               __SetJmp_Y	rmb	1	;Y Reg
*
*	        __SetJmp_Struct_816:		Structure for SetJmp 
*               __SetJmp_PC	rmb	3	Program Counter, actual Long Jump "to" address in code (24 bit Address)
*               __SetJmp_SP	rmb	2	Stack Pointer   Don't need to save the Status Reg, X 0r Acc?
*               __SetJmp_Y	rmb	2	Y Reg
*               __SetJmp_DP	rmb	2	Direct Page Reg
*               __SetJmp_DB	rmb	1	Data Bank Reg
*               Program Bank Reg (NOT NEEDED!!!)
*
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
*                   05/01/2004	 Added SetJmp_Struct Def  
*
*******************************************************************************
*/


#ifndef __SETJMP_H
#define __SETJMP_H


#if USING_134
#define __JBUFSIZE  (4*sizeof(char))					// 4 Bytes, Don't need to save Acc, X, & Status Reg
#elif USING_02
#define __JBUFSIZE  (4*sizeof(char))
#elif USING_265
#define __JBUFSIZE  (3*sizeof(char)+3*2*sizeof(char)+sizeof(char))	// 10 Bytes, Don't need to save Acc, X, & Status Reg
#elif USING_816
#define __JBUFSIZE  (3*sizeof(char)+3*2*sizeof(char)+sizeof(char))
#else
#asm
		EXIT         "Not Valid Processor: Use -DUSING_816, -DUSING_02, etc. ! ! ! ! ! ! ! ! ! ! ! !"
#endasm
#endif

#ifndef __JBUFSIZE
		EXIT         "Not Valid Processor: Use -DUSING_816, -DUSING_02, etc. ! ! ! ! ! ! ! ! ! ! ! !"
#endif


typedef char jmp_buf[__JBUFSIZE];

int setjmp(jmp_buf _env);
void longjmp(jmp_buf _env, int _val);

#endif  // End of __SETJMP_H

/**************************************************/
/*    End of File SETJMP.H                        */
/**************************************************/


