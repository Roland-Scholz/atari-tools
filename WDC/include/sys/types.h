/*******************************************************************************
* FILE NAME:   sys\types.h
*
* TITLE:       This function prototypes and data type definitions for the General Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for General purpose functions.
*              The <sys\types.h> header contains important data type definitions.
*              It is considered good programming practice to use these definitions, 
*              instead of the underlying base type.  By convention, all type names end 
*              with _t.

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
*    R. Greenthal   03/27/2004   Initial
*                   0x/xx/2004   Added 
*                   0x/xx/2004   Added 
*
*******************************************************************************
*/

#ifndef _TYPES_H
#define _TYPES_H


/* The type size_t holds all results of the sizeof operator.  At first glance,
 * it seems obvious that it should be an unsigned int, but this is not always 
 * the case. For example, MINIX-ST (68000) has 32-bit pointers and 16-bit
 * integers. When one asks for the size of a 70K struct or array, the result 
 * requires 17 bits to express, so size_t must be a long type.  The type 
 * ssize_t is the signed version of size_t.
 */

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

#ifndef _SSIZE_T
#define _SSIZE_T
typedef int ssize_t;
#endif

#ifndef _TIME_T
#define _TIME_T
typedef long time_t;		   /* time in sec since 1 Jan 1970 0000 GMT */
#endif

#ifndef _CLOCK_T
#define _CLOCK_T
typedef long clock_t;		   /* unit for system accounting */
#endif

#ifndef _SIGSET_T
#define _SIGSET_T
typedef unsigned long sigset_t;
#endif

/* Types used in disk, inode, etc. data structures. */
typedef short                dev_t;	   /* holds (major|minor) device pair */
typedef char                 gid_t;	   /* group id */
typedef unsigned short       ino_t; 	   /* i-node number */
typedef unsigned short       mode_t;	   /* file type and permissions bits */
typedef char                 nlink_t;	   /* number of links to a file */
typedef unsigned long        off_t;	   /* offset within a file */
typedef int                  pid_t;	   /* process id (must be signed) */
typedef short                uid_t;	   /* user id */
typedef unsigned long        zone_t;	   /* zone number */
typedef unsigned long        block_t;	   /* block number */
typedef unsigned long        bit_t;	   /* bit number in a bit map */
typedef unsigned short       zone1_t;	   /* zone number for V1 file systems */
typedef unsigned short       bitchunk_t; /* collection of bits in a bitmap */

typedef unsigned char        u8_t;	   /* 8 bit type */
typedef unsigned short       u16_t;	   /* 16 bit type */
typedef unsigned long        u32_t;	   /* 32 bit type */
//typedef unsigned long long   u64_t;	   /* 64 bit type */

typedef unsigned char        uchar;	   /* 8 bit type */
typedef unsigned short       uint;	   /* 16 bit type */
typedef unsigned long        ulong;	   /* 32 bit type */
//typedef unsigned long long   ull;	   /* 64 bit type */

//typedef unsigned char        UCHAR;	   /* 8 bit type */
//typedef unsigned short       UINT;	   /* 16 bit type */
//typedef unsigned long        ULONG;	   /* 32 bit type */
//typedef unsigned long long   ULL;	   /* 64 bit type */

typedef char                 i8_t;      /* 8 bit signed type */
typedef short                i16_t;      /* 16 bit signed type */
typedef long                 i32_t;      /* 32 bit signed type */
//typedef long long          i64_t;      /* 64 bit signed type */

#ifndef _FLOAT_T
#define _FLOAT_T
typedef float	float_t;
#endif


#ifndef _DOUBLE_T
#define _DOUBLE_T
typedef double	double_t;
#endif


/* Signal handler type, e.g. SIG_IGN */
#if defined(_ANSI)
typedef void (*sighandler_t) (int);
#else
typedef void (*sighandler_t)();
#endif

//*****************************
//*****************************
// Special 
//*****************************
//*****************************

#define TRUE	1
#define FALSE	0

#define true	1
#define false	0

#define bool	int
#define BOOL	int
#define _Bool	int		// 1999 C

#define EQ ==
#define GE >=
#define GT >
#define LE <=
#define LT <
#define NE !=

/*
**  Macros to manipulate bits in an array of char.
**  These macros assume CHAR_BIT is one of either 8, 16, or 32.
*/

#define MASK  CHAR_BIT-1
#define SHIFT ((CHAR_BIT==8)?3:(CHAR_BIT==16)?4:8)

#define BitOff(a,x)  ((void)((a)[(x)>>SHIFT] &= ~(1 << ((x)&MASK))))
#define BitOn(a,x)   ((void)((a)[(x)>>SHIFT] |=  (1 << ((x)&MASK))))
#define BitFlip(a,x) ((void)((a)[(x)>>SHIFT] ^=  (1 << ((x)&MASK))))
#define IsBit(a,x)   ((a)[(x)>>SHIFT]        &   (1 << ((x)&MASK)))


#endif /* _TYPES_H */


