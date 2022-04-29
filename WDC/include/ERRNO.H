/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   ERRNO.h
*
* TITLE:       This function prototypes and data type definitions for the Error Defs.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Error Defs.
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


#ifndef __ERRNO_H 
#define __ERRNO_H 

#ifndef ERRNO
extern int errno;
#endif

#define ENOENT		1		/* No such file or directory */
#define E2BIG		2		/* Argument list too long */
#define EBADF		3		/* Bad file descriptor */
#define ENOMEM		4		/* Not enough memory */
#define EEXIST		5		/* File (already) exists */
#define EINVAL		6		/* Invalid argument */
#define ENFILE		7		/* Too many open files in the system */
#define EMFILE		8		/* Too many open files in a process */
#define ENOTTY		9		/* Not a console device */
#define EACCES		10		/* Permission denied */
#define EIO		11		/* I/O error (physical, usually) */
#define ENOSPC		12		/* No space left on device */
#define ERANGE		13		/* (math) Result too large */
#define EDOM		14		/* (math) Argument domain error */
#define ENOEXEC		15		/* (f)exec format error */
#define EROFS		16		/* Read-only file system */
#define EXDEV		17		/* Cross-device rename */
#define EAGAIN		18		/* Nothing to read */

//New Error Numbers
#define EZERO		19		/* Zero */
#define EINVFNC		20		/* Invalid Function */
#define ENOPATH		21		/* No Path */
#define ECONTR		22		/* Cont */
#define EINVMEM		23		/* Invalid Nemory */
#define EINVENV		24		/* Invalid Enviroment */
#define EINVFMT		25		/* Invalid Format */
#define EINVACC		26		/* Invalid  */
#define EINVDAT		27		/* Invalid Data */
#define ENODEV 		28		/* No */
#define ECURDIR		29		/* Current Directory */
#define ENMFILE		30		/* N File */
#define EDEADLOCK	31		/*  */


/*--------------------------------------------------------------------
   define error constants (0 .. n)
   change matherr_.c when new error constants are added
  --------------------------------------------------------------------*/
#define E_NOERROR     0  /* No errors detected */
#define E_MALLOC      1  /* Not enough memory */
#define E_MSIZE       2  /* Array too large */
#define E_NULLPTR     3  /* NULL pointer (uninitialized pointer ) */
#define E_MSING       4  /* Singular Matrix (ie. determinant = 0) */
#define E_NEQNS       5  /* More unknowns than equations */
#define E_WINDOW      6  /* Invalid window type specified */
#define E_DOMERR      7  /* argument outside domain of function */
#define E_FACTOR      8  /* Argument 'factor' must be between 2 and 10 */
#define E_DECIMATE    9  /* Argument 'ndec' must be between 2 and 10 */
#define E_NOTENOUGH  10  /* Not enough input data,the input array must be longer*/
#define E_INTERP     11  /* Interpolated length must be >= input length */
#define E_LAGRANGE   12  /* Interpolation not defined at input value t */
#define E_NEGPROB    13  /* Negative probability undefined */
#define E_FFTSIZE    14  /* Data length must be >= FFT length */
#define E_FFTPOWER2  15  /* FFT length must be a power of two */
#define E_LIMITS     16  /* Limits on definite integral must be distinct */
#define E_ROUNDOFF   17  /* Rounding errors prohibit required accuracy */
#define E_STEPSIZE   18  /* Step size must be nonzero to estimate derivative*/
#define E_DISCRETE   19  /* k0 must be less than total number of objects n */
#define E_SAMEX      20  /* The input table has two identical x values */
#define E_ORDER      21  /* The polynomial order must be between 1 and 9 */
#define E_OPEN       22  /* Could not open file */
#define E_WRITE      23  /* Error writing to file */
#define E_READ       24  /* Error reading from file */
#define E_CURVES     25  /* Argument 'curves' must be between 1 and 9 */
#define E_HEADER     26  /* Invalid file header */
#define E_RSIZE      27  /* Sizeof(Real) in file != sizeof(Real) in program */
#define E_NO_MIN     28  /* Minimum probably does not exist */
#define E_DIVERGE    29  /* No convergence in LIMIT iterations */
#define E_GRAD_ERR   30  /* Encountered errors in calculating the gradient */
#define E_USERFUNC   31  /* User function called by least_sq returned error */
/* add additional error constants here */


/**************************/
/* non ANSI C definitions */
/**************************/
// MAY NEED TO DEFINE as a FIXED Size array with circular features so too many errors just get lost!
extern char *sys_errlist[];		// Array of System Errors encountered, needs to be limited!
extern int sys_nerr;			// Number of System Errors encountered

#endif  // End of __ERRNO_H


/**************************************************/
/*    End of File ERRNO.H                         */
/**************************************************/


