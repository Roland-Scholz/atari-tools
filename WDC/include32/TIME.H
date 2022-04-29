/* Copyright (C) 1992 by Zardoz Software, Inc. */
/*******************************************************************************
* FILE NAME:   TIME.h
*
* TITLE:       This function prototypes and data type definitions for the Time Functions.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Time functions.
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


#ifndef __TIME_H
#define __TIME_H

#include <sys\types.h>		// Defines 
#include <stddef.h>		// Defines size_t

#define CLOCKS_PER_SEC 100	/* clock() ticks per second */

#ifndef _TIME_T
#define _TIME_T
typedef long time_t;		   /* time in sec since 1 Jan 1970 0000 GMT */
#endif

#ifndef _CLOCK_T
#define _CLOCK_T
typedef long clock_t;		   /* unit for system accounting */
#endif



#define __TM
struct tm {
	int tm_sec;	/* seconds after the minute [0,60] */
	int tm_min;	/* minutes after the hour [0,59] */
	int tm_hour;	/* hours since midnight [0,23] */
	int tm_mday;	/* day of the month [1,31] */
	int tm_mon;	/* months since jan [0,11] */
	int tm_year;	/* years since 1900 */
	int tm_wday;	/* days since sunday [0,6] */
	int tm_yday;	/* days since jan 1 [0,365] */
	int tm_isdst;	/* pos if DST in effect; 0 if not; neg if can't tell */
	int tm_hsec;	/* hundreths of second; not in ANSI C */
};


struct date {
    int da_year;			//
    char da_day;			//
    char da_mon;			//
};

struct time {
    unsigned char ti_min;		//
    unsigned char ti_hour;		//
    unsigned char ti_hund;		//
    unsigned char ti_sec;		//
};


#define	RTC_yr		*( volatile uchar * )0x0030
#define	RTC_month	*( volatile uchar * )0x0031
#define	RTC_day		*( volatile uchar * )0x0032
#define	RTC_hr		*( volatile uchar * )0x0033
#define	RTC_min		*( volatile uchar * )0x0034
#define	RTC_sec		*( volatile uchar * )0x0035
#define	RTC_tenthsec	*( volatile uchar * )0x0036


/***********************/
/* ProtoType Functions */
/***********************/
char *asctime(const struct tm *timeptr);
clock_t clock(void);
char *ctime(const time_t *timer);
double difftime(time_t time1, time_t time2);
struct tm *gmtime(const time_t *timer);
struct tm *localtime(const time_t *timer);
time_t mktime(struct tm *timeptr);
time_t time(time_t *timer);
size_t strftime(char *s, size_t maxsize, const char *format,
					const struct tm *timeptr);


/*********************/
/* NON ANSI Standard */
/*********************/
//extern int   daylight;  /* non-zero if daylight savings time is used */
//extern long  timezone;  /* difference in seconds between GMT and local time */
//extern char *tzname[2]; /* standard/daylight savings time zone names */

//void ftime(struct timeb *timeptr);
//void getdate(struct date *datebuf);
//void gettime(struct time *timebuf);
//void setdate(struct date *datebuf);
//void settime(struct time *timebuf);
//int  stime(time_t *timer);
//void tzset(void);

#endif  // End of __TIME_H

/**************************************************/
/*    End of File TIME.H                       */
/**************************************************/

