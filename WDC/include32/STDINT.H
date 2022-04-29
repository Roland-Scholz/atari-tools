/*******************************************************************************
* FILE NAME:   STDINT.h
*
* TITLE:       This function prototypes and data type definitions for the Standard Int Types.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Standard Int Types.
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
*    R. Greenthal   03/15/2004   Initial
*                   0x/xx/2004	 Added 
*
*******************************************************************************
*/

#ifndef _STDINT_H
#define _STDINT_H


/*
 *=========================== CONSTANTS & MACROS ===============================
 */


#ifndef uint32_t

#if SIZEOF_INT == 4
#define uint32_t unsigned int
#define int32_t int
#elif SIZEOF_SHORT == 4
#define uint32_t unsigned short
#define int32_t short
#elif SIZEOF_LONG == 4
#define uint32_t unsigned long
#define int32_t long
#endif

#endif/* !uint32_t */

#ifndef uint16_t
 
#if SIZEOF_INT == 2
#define uint16_t unsigned int
#define int16_t int
#elif SIZEOF_SHORT == 2
#define uint16_t unsigned short
#define int16_t short
#elif SIZEOF_LONG == 2
#define uint16_t unsigned long
#define int16_t long
#endif
 
#endif/* !uint16_t */
 


/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */









#endif /* End of _STDINT_H */
#pragma Pop (List)

/**************************************
	End of File STDINT.H
***************************************/
