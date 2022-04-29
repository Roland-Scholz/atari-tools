/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   SIGNAL.h
*
* TITLE:       This function prototypes and data type definitions for the Signal Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Signal functions.
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


#ifndef __SIGNAL_H
#define __SIGNAL_H

/* atomic-access data type: */
//typedef int	sig_atomic_t;		/* this type works nearly everywhere */

typedef char sig_atomic_t;


#define SIGINT	1		/* Interrupt (IRQ)? - interactive attention signal */
#define SIGTERM	2		/* Term - termination request */
#define SIGABRT	3		/* Abort - abnormal termination */
#define SIGFPE	4		/* Floating Point Signal(IRQ/COP) - erroneous arithmetic operation */
#define SIGILL	5		/* Illegal - invalid function image */
#define SIGSEGV	6		/* Segment violation - invalid access to storage */
#define SIGEND	7		/* End of SIG #'s */

#define _NUMSIG	6
#define _FSTSIG	1

#define SIG_DFL	((void (*)(int))0)	/* default */
#define SIG_IGN	((void (*)(int))1)	/* ignore */
#define SIG_ERR	((void (*)(int))-1)	/* error return from signal() */


void (*signal(int _sig, void (*_func)(int)))(int);
int raise(int _sig);


#define LOCK	asm{sei;}
#define UNLOCK	asm{cli;}

#endif /* End of __SIGNAL_H */

/**************************************************/
/*    End of File SIGNAL.H                        */
/**************************************************/

