#pragma Off (List)
/*******************************************************************************
* FILE NAME:   SK_IO.ch
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

#ifndef SK_IO_H
#define SK_IO_H

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






#define CLI asm{cli;}	/* enable interrupt response */
#define SEI asm{sei;}	/* disable it */

#define BRK(n) asm{ brk n;} /* 65C02/65c816-BRK */

#define COP(n) asm{ cop n;} /* 65c816-COP */


//#define EnableIRQ(n)\
//  asm(" lda #$80\n"\
//      " tsb $fd01+"#n"*4\n")	/* enable interrupt of timer n */

//#define DisableIRQ(n)\
//  asm(" lda #$80\n"\
//      " trb $fd01+"#n"*4\n") /* disable it */


struct _VIA1{ 
  uchar ORB_IRB;		/* Input/Output Reg 'B' */
  uchar ORA_IRA;		/* Input/Output Reg 'A' */
  uchar DDRB;			/* Data Direction Reg 'B' */
  uchar DDRA;			/* Data Direction Reg 'A' */
  uchar T1CLO;			/* Timer #1 Counter Low */
  uchar T1CHI;			/* Timer #1 Counter High */
  uchar T1LLO;			/* Timer #1 Latch Low */
  uchar T1LHI;			/* Timer #1 Latch High */
  uchar T2CLO;			/* Timer #2 Counter Low */
  uchar T2CHI;			/* Timer #2 Counter High */
  uchar SR;			/* Shift Reg */
  uchar ACR;			/* Auxiliary Control Reg */
  uchar PCR;			/* Peripheral Control Reg */
  uchar IFR;			/* Interrupt Flag Reg */
  uchar IER;			/* Interrupt Enable Reg  */
  uchar ORANH_IRANH;		/* Input Reg 'A' No Handshake */
  };


struct _I2C{ 	/* One byte of the VIA */
  uchar clock:1;
  uchar sin:1;
  uchar sout:1;
  uchar nu:5;
  };

#endif /* SK_IO_H */
#pragma Pop (List)


