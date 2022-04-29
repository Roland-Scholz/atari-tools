/*******************************************************************************
* FILE NAME:   SEARCH.h
*
* TITLE:       This function prototypes and data type definitions for the Search Tree Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Search Tree functions.
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


#ifndef __SEARCH_H
#define __SEARCH_H



#ifndef size_t
typedef unsigned size_t;
#endif


void *bsearch(const void *_key, const void *_base, size_t _nmemb, size_t _size,
					int (*_compar)(const void *, const void *));
char *lfind(void *key, void *base, unsigned *number, unsigned size,
              int (*compare)(void *, void *));
char *lsearch(void *key, void *base, unsigned *number, unsigned size,
              int (*compare)(void *, void *));
void qsort(void *_base, size_t _nmemb, size_t _size,
						int (*_compar)(const void *, const void *));


#endif  // End of __SEARCH_H

/**************************************************/
/*    End of File SEARCH.H                        */
/**************************************************/

