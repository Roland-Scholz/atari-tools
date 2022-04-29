/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   STDIO.h
*
* TITLE:       This function prototypes and data type definitions for the
*               Standard I/O Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Standard I/O functions.
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


#ifndef __STDIO_H
#define	__STDIO_H

#include <stdarg.h>


# ifndef _SIZE_T
# define _SIZE_T
  typedef unsigned long size_t;
# endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef FARNULL
   #define     FARNULL     ((void far *)0)
#endif


#define BUFSIZ 1024

#define EOF (-1)

#define L_tmpnam 40
#define FOPEN_MAX 20	/* must agree with FCntl.h */
#define FILENAME_MAX 126
#define TMP_MAX 25
//#define     TMP_MAX     32767


#define SEEK_SET 0	/* from beginning of file */
#define SEEK_CUR 1	/* from current position */
#define SEEK_END 2	/* from end of file */

#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])
#define stdaux (&_iob[3])
#define stdprn (&_iob[4])

typedef long int fpos_t;

typedef struct __stdio {
	unsigned char *_bp;			/* current position in buffer */
	unsigned char *_bend;		/* last character in buffer + 1 */
	unsigned char *_buff;		/* address of buffer */
	unsigned short _flags;		/* open mode, etc. */
	char _unit;					/* fd returned by open */
	unsigned char _bytbuf;		/* single byte buffer for unbuffered streams */
	size_t _buflen;				/* length of buffer */
	unsigned short _tmpnum;		/* name of file for temporaries */
} FILE;
extern FILE _iob[];



#define _IOMYBUF	0x0001	/* malloced buffer */
#define _IOEOF		0x0002	/* end-of-file encountered */
#define _IOERR		0x0004	/* error occurred */
#define _IOSTRNG	0x0008	/* special string stream */
#define _IOBIN		0x0010	/* file is binary ("b") */
#define _IOLBF		0x0020	/* line buffered */
#define _IOFBF		0x0040	/* fully buffered */
#define _IONBF		0x0080	/* completely unbuffered */
#define _IOCON		0x0100	/* console device */
#define _IOR		0x0200	/* stream opened in read mode */
#define _IOW		0x0400	/* stream opened in write mode */
#define _IORW		0x0800	/* stream opened in update mode */
#define _IOUNG		0x1000	/* ungetc was called */
#define _IOSYNC 	0x2000	/* MPW compatibility */
#define _IODIRTY	0x4000	/* buffer has been written */

int    _format(FILE *_stream, const char *format, va_list varg);		// Special Internal Functions for pharsing
int    _scan(FILE *_stream, const char *format, va_list varg);		// Special Internal Functions for pharsing

void 	clearerr(FILE *_stream);			// 
int 	fclose(FILE *_stream);				// 
int 	feof(FILE *_stream);				// 
int 	ferror(FILE *_stream);				// 
int 	fflush(FILE *_stream);				// 
int	fgetc(FILE *_stream);
int 	fgetpos(FILE *_stream, fpos_t *_pos);		// 
char   *fgets(char *_s, int _n, FILE *_stream);		// 
FILE   *fopen(const char *_filename, const char *_mode);
int 	fprintf(FILE *_stream, const char *format, ...);
int 	fputc(int _c, FILE *_stream);
int 	fputs(const char *_s, FILE *_stream);
size_t 	fread(void *_ptr, size_t _size, size_t _nmemb, FILE *_stream);
FILE   *freopen(const char *_filename, const char *_mode, FILE *_stream);
int 	fscanf(FILE *_stream, const char *format, ...);
int 	fseek(FILE *_stream, long int _offset, int _whence);
int 	fsetpos(FILE *_stream, const fpos_t *_pos);
long	ftell(FILE *_stream);
size_t 	fwrite(const void *_ptr, size_t _size, size_t _nmemb, FILE *_stream);
int 	getc(FILE *_stream);
int	getchar( void);
char   *gets(char *_s);
void 	perror(const char *_s);
int 	printf(const char *_format, ...);
int 	putc(int _c, FILE *_stream);
int	putchar( int c);
int 	puts(const char *_s);
int 	remove(const char *_filename);
int 	rename(const char *_old, const char *_new);
void 	rewind(FILE *_stream);
int 	scanf(const char *_format, ...);
void 	setbuf(FILE *_stream, char *_buf);
int 	setvbuf(FILE *_stream, char *_buf, int _mode, size_t _size);
//int	snprintf (char *str, size_t count, const char *format, ...);
int 	sprintf(char *str, const char *format, ...);
int 	sscanf(const char *str, const char *format, ...);
FILE   *tmpfile(void);
char   *tmpnam(char *_s);
int 	ungetc(int _c, FILE *_stream);
int 	vfprintf(FILE *_stream, const char *format, char *_arg);
//int	vfscanf(FILE *stream, const char *format, va_list ap); 
int 	vprintf(const char *_format, char *_arg);
//int	vscanf(const char *format, va_list ap); 
//int	vsnprintf(char *str, size_t size, const char *format, va_list ap);
int 	vsprintf(char *str, const char *format, char *arg);
//int vsscanf(const char *str, const char *format, va_list args); //Similar to sscanf with the variable argument list specified directly as for vprintf. 


//#ifndef STRING
//typedef struct {
//    int     length;
//    char    string[80];
//} STRING;
//#endif





int _filbuf(FILE *);
int _flsbuf(FILE *, int);

#ifdef __C_MACROS__
#define getc(fp)	((fp)->_bp < (fp)->_bend ? *(fp)->_bp++ :_filbuf((fp)))
#define putc(c,fp)	((fp)->_bp < (fp)->_bend ? *(fp)->_bp++ = (c) : \
										_flsbuf((fp),(int)(unsigned char)(c)))
#define getchar() getc(stdin)
#define putchar(c) putc((c), stdout)
#define clearerr(fp) ((void)((fp)->_flags &= ~(_IOERR|_IOEOF)))
#define feof(fp) ((fp)->_flags&_IOEOF)
#define ferror(fp) ((fp)->_flags&_IOERR)
#endif


/*****************************/
/*    NON ANSI C functions   */
/*    System V Berkley       */
/*    UNIX/Linux             */
/*****************************/


/*********************************/
/* NON ANSI C user-visible stuff */
/*********************************/
//int     fcloseall(void);
FILE   *fdopen(int, const char *);
#define fileno(fp) ((int)(fp)->_unit)	
//int     flushall(void);
//int     fputchar(int c);
//int	getw(FILE *_stream);
//int	putw(int _w, FILE *_stream);
//int     rmtmp(void);
//char   *tempnam(char *dir, char *prename);
//int     unlink(char *filename);
//ungetch(int c);			// Reverse action of getch (unbuffered input from keyboard)

			
#define puterr(c)	(putc((c),stderr))



#endif /* _STDIO_H */

/**************************************************/
/*    End of File STDIO.H                         */
/**************************************************/

