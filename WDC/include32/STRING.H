/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   STRING.h
*
* TITLE:       This function prototypes and data type definitions for the String Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for String functions.
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
*                   07/13/2004	 Removed ltostr, will add later & lltostr
*                   0x/xx/2004	  
*
*******************************************************************************
*/


#ifndef __STRING_H
#define __STRING_H

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef Boolean_T
typedef enum {Error_ = -1, Success_, False_ = 0, True_} Boolean_T;
#endif


void   *memchr(const void *_s, int _c, size_t _n);	// Returns a pointer to the first occurrence of c (converted to an unsigned char) in the first n bytes 
int 	memcmp(const void *_s1, const void *_s2, size_t _n); // Compares n bytes of two regions of memory, treating each byte as an unsigned character
void   *memcpy(void *_dst, const void *_src, size_t _num); // Copies num bytes from src buffer to memory location pointed by dst
void   *memmove(void *_dst,const void *_src, size_t _n); // Copies n bytes from memory areas src to dst
void   *memset(void *_s, int _c, size_t _n);		// Sets the first n bytes in memory area s to the value of c 

char   *strcat(char *_dst, const char *_src);		// Appends the src string to the dst string overwriting the `\0' character at the end of  dest, and  then  adds a terminating `\0' character
char   *strchr(const char *_s, int _c);			// Locates the first occurrence of c, cast to char, in the string pointed to by s
int 	strcmp(const char *_s1, const char *_s2);	// Compares the string pointed to by s1 to the string pointed to by s2
int 	strcoll(const char *_s1, const char *_s2);	// Compares the string pointed to by s1 to the string pointed to by s2, both interpreted as appropriate to the LC_COLLATE category of the current locale
char   *strcpy(char *_dst, const char *_src);		// Copies the string pointed to by src (including the terminating null character) into the array pointed to by dst. If copying occurs between objects that overlap, the behavior is undefined. 
size_t 	strcspn(const char *_s1, const char *_s2);	// Spans the initial part of the null-terminated string s1 as long as the characters from s do not occur in string s2
char   *strerror(int _errnum);				// Return string describing error code
//size_t	strftime(char *_s, size_t _maxsize, const char *_format,
//					const struct tm *_timeptr);	/* Much like a sprintf for time/date output */
size_t 	strlen(const char *_s);				// Caclulates the length of a string _s
char   *strncat(char *_dst, const char *_src, size_t _n); // Concatenates src to the end of dst, where n is the Max # of characters
int 	strncmp(const char *_s1, const char *_s2, size_t _n); 	// Compares s1 with s2 case insensetive, comparing n characters
char   *strncpy(char *_dst, const char *_src, size_t _n); // Copies up to n characters, including the terminating null character, from the string pointed to by src into the buffer pointed to by dst.
char   *strpbrk(const char *_s1, const char *_s2);	// Search a string for any of a set of characters
char   *strrchr(const char *_s, int _c);		// Locates the last occurrence of c, cast to char, in the string pointed to by s
size_t 	strspn(const char *_s1, const char *_s2);	// Determines the span (i.e. length) of the initial substring within the string
char   *strstr(const char *_s1, const char *_s2);	// Locate first occurrence of a substring within a string
char   *strtok(char *_s1, const char *_s2);		// Find the next token in s1(strToken). The set of characters in s2(strDelimit) specifies possible delimiters of the token to be found in strToken 
size_t 	strxfrm(char *_s1, const char *_s2, size_t _n); // Transforms the string pointed to by s2 and places the resulting string into the array pointed to by s1




/********************************************/
/* NON ANSI C functions                     */
/********************************************/
int     stricmp(char *str1, char *str2);		// Compare strings ignoring case

#define strsave(s) strdup(s)				// Makes a copy of the string pointed to by s
#define rindex(s,c) strrchr(s,c)			// Locates the last occurrence of c, cast to char, in the string pointed to by s
#define index(s,c) strchr(s,c)				// Locates the first occurrence of c, cast to char, in the string pointed to by s
#define strcmpi(s1, s2) stricmp(s1, s2)			// Compare strings s1 and s2, ignoring case
#define strncmp(s1, s2, n) strnicmp(s1, s2, n)		// Compares s1 with s2 case insensetive, comparing n characters

void 	bzero(char *ptr, int nbytes);			/* Copies n bytes, each with a value of zero, into string s */
void 	bcopy(const void *src, void *dst, int n);	/* Copies n bytes, from src into string dst */

int	getopt(int argc, char **argv, char *opts);		/* Parses command lines */

char   *itoo(int nbr, char str[], int sz);
//char   *ltostr(long num, char *string, size_t max_chars, unsigned base);	/* Convert a long int to a String */

void   *memccpy(void *_dst, const void *_src, int _c, size_t _n); /* Copies at most num bytes from source to dest, stopping if the character ch is copied */
int     memicmp(void *addr1, void *addr2, size_t n);	/* Compares the first cnt bytes of buf1 and buf2 without regard to the case of letters in the two buffers */
void	memrev(char  *buf, size_t count);		/* Reverse "count" bytes starting at "buf" (exchange two adjacent areas of storage which might be of two different lengths) */

char   *sstrdel(char *s, ...);				/* Delete multiple substrings */
char   *str27seg(char *string);				/* Convert numeric strings to 7-segment LED strings */
char   *strchcat(char *string, int ch, size_t buflen);	/* Append a character to a string */
char   *strdel(char *str, size_t posn, size_t len);	/* Removes specified characters from a string */
char   *strdelch(char *string, const char *lose);	/* Removes specified character(s) from a string */

char   *strdup(char *_s);				/* Makes a copy of the string pointed to by s */
char   *stristr(char *str1, char *str2);		/* Location of 1st occurance of str2 within str1 */
char   *strlwr(char *str);				/* Convert only Upper case Alpha characters to lower case */
int     strnicmp(char *str1, char *str2, size_t n);	/* Converts any uppercase letters in the given null-terminated string to lowercase. Other characters are not affected */
char   *strnset(char *str, int c, size_t n);		/* Sets a specified number of characters in a string to a given character */
char   *strrev(char *str);				/* Reverse the order of chatacters in a string */
char   *strrset (char *p, char *set);			/* Returns a ptr to last char from set in p, else 0 */
char   *strset(char *str, int c);			/* Fills the string pointed to by str with the character c */
void	strsort(char **v, unsigned n);			/* Shell sort an array of string pointers via strcmp() */
char   *strupr(char *str);				/* Convert only lower case Alpha characters to Upper case */
void 	swapmem(void *_s1, void *_s2, size_t _n);	/* Swaps n characters between the object pointed to by s1 and the object pointed to by s2 */


Boolean_T xstrcmp(const char *pat, const char *str);	/* Case Sensitve Simple string pattern matching functions using wildcards ('?' & '*'). */
Boolean_T xstricmp(const char *pat, const char *str);	/* Case Insensitve Simple string pattern matching functions using wildcards ('?' & '*'). */


#endif /* _STRING_H */

/**************************************************/
/*    End of File STRING.H                        */
/**************************************************/

