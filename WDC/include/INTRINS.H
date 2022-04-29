#pragma Off (List)
/*******************************************************************************
* FILE NAME:   INTRINS.H
*
* TITLE:       This function prototypes and data type definitions for HW.
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for .
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
*    R. Greenthal   02/05/2004   Initial
*
*******************************************************************************
*/

#ifndef INTRINS_H
#define INTRINS_H

/*
 *=========================== CONSTANTS & MACROS ===============================
 */

/* None */

/*
 *================================== TYPES =====================================
 */

/* None */

/*
 *============================= FUNCTION PROTOTYPES ============================
 */




/*
Instructions that can be added to 'C' code 
*/
#define CLI asm{cli;}	/* enable interrupt response */
#define _atomic_ asm{cli;}	/* enable interrupt response */

#define SEI asm{sei;}	/* disable it */
#define _endatomic_ asm{sei;}	/* disable it */

#define BRK(n) asm{ brk n;} /* 65C02/65c816-BRK */
#define _TRAP_(n) asm{ brk n;} /* 65C02/65c816-BRK */

#define COP(n) asm{ cop n;} /* 65c816-COP */

#define IDLE asm{ wai;} /* 65c816-WAI */
#define WAIT asm{ wai;} /* 65c816-WAI */




// _crol_(x, b)		// Rotates a "char" Left so many bits
// _cror_(x, b)		// Rotates a "char" Right so many bits
// _irol_(x, b)		// Rotates a "int" Left so many bits
// _iror_(x, b)		// Rotates a "int" Right so many bits
// _lrol_(x, b)		// Rotates a "long" Left so many bits
// _lror_(x, b)		// Rotates a "long" Right so many bits


#endif /* INTRINS_H */

/**************************************************/
/*    End of File INTRINS.H                       */
/**************************************************/

