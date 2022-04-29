/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   FCNTL.h
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
*              definitions used for Disk Control.
*
*
* SPECIAL CONSIDERATIONS:
*	        <None>
*
* AUTHOR:      R. Greenthal
*
*
* CREATION DATE:  Feb 05,2004
*
* REVISION HISTORY
*    Name           Date         Description
*    ------------   ----------   ----------------------------------------------
*    R. Greenthal   02/05/2004   Initial, added peek & poke
*    R. Greenthal   0x/0x/2004   
*
*******************************************************************************
*/

#ifndef __FCNTL_H 
#define __FCNTL_H 

/*
 *=========================== CONSTANTS & MACROS ===============================
 */

#define O_RDONLY	0x0000		// Open as Read ONLY
#define O_WRONLY	0x0001		// Open as Write ONLY
#define O_RDWR		0x0002		// Open as Read &/or Write
#define O_CREAT		0x0100		// Create a New File
#define O_TRUNC		0x0200		//
#define O_EXCL		0x0400		//
#define O_APPEND	0x0800		// Open an existing File & Append to the end of it
#define	O_TEXT		0x1000		// Open as ASCII Text (Character) Read &/or Write (needs more)
#define O_BINARY    	0x8000		// TBD Binary Byte Read &/or Write


/*
 *================================== TYPES =====================================
 */

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif


extern struct _dev {
	void *fd;
	short	mode;
} *_devtab;

extern short _numdev;


/*
 *============================= FUNCTION PROTOTYPES ============================
 */


void _abort(void);
int close(int);
int creat(const char *_name, int _mode);
void _exit(int _code);
long lseek(int, long, int);
int open(const char * _name, int _mode);
size_t read(int, void *, size_t);
int unlink(const char *);
size_t write(int, void *, size_t);

//int access(char *, int);


#define PEEK(a) (*(char *)(a))
#define peek(a) (*(char *)(a))
#define PEEKB(a) (*(char *)(a))
#define peekb(a) (*(char *)(a))
#define PEEKW(a) (*(int *)(a))
#define peekw(a) (*(int *)(a))
#define PEEKL(a) (*(long *)(a))
#define peekl(a) (*(long *)(a))
//#define PEEKLL(a) (*(long long *)(a))
//#define peekll(a) (*(long long *)(a))

#define POKE(a,b) (*(unsigned char *)(a))=(b)
#define poke(a,b) (*(unsigned char *)(a))=(b)
#define POKEB(a,b) (*(unsigned char *)(a))=(b)
#define pokeb(a,b) (*(unsigned char *)(a))=(b)
#define POKEW(a,b) (*(unsigned int *)(a))=(b)
#define pokew(a,b) (*(unsigned int *)(a))=(b)
#define POKEL(a,b) (*(unsigned long *)(a))=(b)
#define pokel(a,b) (*(unsigned long *)(a))=(b)
//#define POKELL(a,b) (*(unsigned long long *)(a))=(b)
//#define pokell(a,b) (*(unsigned long long *)(a))=(b)



#endif /* FCNTL_H */
#pragma Pop (List)

/**************************************************/
/*    End of File FCNTL.H                         */
/**************************************************/

