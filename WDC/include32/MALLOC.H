#pragma Off (List)
/*******************************************************************************
* FILE NAME:   MALLOC.h
*
* TITLE:       This function prototypes and data type definitions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for General purpose RAM Allocation functions.
*
*
* SPECIAL CONSIDERATIONS:
*	        <None>
*
* AUTHOR:      R. Greenthal
*
*
* CREATION DATE:  Feb 11,2004
*
* REVISION HISTORY
*    Name           Date         Description
*    ------------   ----------   ----------------------------------------------
*    R. Greenthal   02/11/200   Initial
*
*******************************************************************************
*/

#ifndef _MALLOC_H
#define _MALLOC_H


/*
 *=========================== CONSTANTS & MACROS ===============================
 */



/*
 *================================== TYPES =====================================
 */

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef ALLOC_L_LEN
//int alloc_list_length;
//void *alloc_list[];
#endif

#ifndef	ALIGN_SIZE
#define	ALIGN_SIZE	sizeof(double)
#endif


#define SIZE_T_MAX ((size_t) ~0)
#define MALLOC_MAX SIZE_T_MAX
#define ARRAY_MAX SIZE_T_MAX


/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */


//int	  add_alloc_list(void *p);			//
void     *calloc(size_t _nmemb, size_t _size);		// Complex alloc
void far *farcalloc(unsigned long _nmemb, unsigned long _size);
void 	  farfree(void far *_ptr);			//
void far *farmalloc(unsigned long _size);		//
void far *farrealloc(void far *_ptr, unsigned long _size);
void	  free(void *_ptr);				//
void     *malloc(size_t _size);				//
//int pmalloc(int nbytes);				// Permanent alloc
//void     *realloc(void *_ptr, size_t _size);		//
int	  remove_alloc_list(void *p);			//
double   *valloc(double *address, unsigned npts);	//

//unsigned        stackavail(void);			// Check on how much STACK is Available


#endif /* End of _MALLOC_H */
#pragma Pop (List)

/**************************************
	End of File MALLOC.H
***************************************/

