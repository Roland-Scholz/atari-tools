#pragma Off (List)
/*******************************************************************************
* FILE NAME:   Flash_SK_IO.ch
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

#ifndef Flash_SK_IO_H
#define Flash_SK_IO_H

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


struct _VIA2{ 
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



struct _UART16c450{ 
  uchar RHR_THR;		/* Transmit/Receive Holding Register */
  uchar IER;			/* Interrupt Enable Register */
  uchar FCR_ISR;		/* FIFO control Register/Interrupt Status Register */
  uchar LCR;			/* Interrupt Status Register */
  uchar MCR;			/* Modem Control Register */
  uchar LSR;			/* Line Status Register */
  uchar MSR;			/* Modem Status Register */
  uchar SCR;			/* Scratch pad Register */
  };

#define clock 1.84320E+06
//#define clock 3.686400e6
//#define clock 6.144000e6
//#define clock 7.372800e6
//#define clock 1.4743600e7

// UART 16c450 Type Baud Rates
#define _COM_300_ (clock/(16 * 300))-1
#define _COM_1200_ (clock/(16 * 1200))-1
#define _COM_2400_ (clock/(16 * 2400))-1
#define _COM_9600_ (clock/(16 * 9600))-1
#define _COM_19K_ (clock/(16 * 19200))-1
#define _COM_38K_ (clock/(16 * 38400))-1
#define _COM_56K_ (clock/(16 * 57600))-1
#define _COM_115K_ (clock/(16 * 115200))-1

//* Parity
#define _COM_NOPARITY_ 0
#define _COM_ODDPARITY_ 1
#define _COM_EVENPARITY_ 2

//* Stopbits
#define _COM_STOP1_ 0
#define _COM_STOP2_ 1
#define _COM_STOP1_5_ 1

//* word length
#define _COM_CHR5_ 0
#define _COM_CHR6_ 1
#define _COM_CHR7_ 2
#define _COM_CHR8_ 3

//* word Buffer length
#define _COM_FIFO1_ 0
#define _COM_FIFO4_ 1
#define _COM_FIFO8_ 2
#define _COM_FIFO14_ 3




struct _UART51{ 
  uchar rxd_txd;		/* Receiver register */
  uchar serial_status;		/* xmit & receive status reg */
  uchar serial_command;		/* command register */
  uchar serial_control;		/* rate & size control */
  };

#define RXD_READY	0x08	/* receiver ready bit mask */
#define TXD_READY	0x10	/* transmitter ready bit mask */
#define RXD_INT_ENABLE	0x02	/* receiver interrupt enable bit mask */
#define TXD_INT_ENABLE	0x04	/* transmitter interrupt enable bit mask */
#define RXD_ERROR	0x07	/* frame, overrun & parity error flags */

#define clock51 1.84320E+06
//#define clock51 3.686400e6
//#define clock51 6.144000e6
//#define clock51 7.372800e6
//#define clock51 1.4743600e7

// UART W65c51 Type Baud Rates
#define _COM51_300_ (clock51/(16 * 300))
#define _COM51_1200_ (clock51/(16 * 1200))
#define _COM51_2400_ (clock51/(16 * 2400))
#define _COM51_9600_ (clock51/(16 * 9600))
#define _COM51_19K_ (clock51/(16 * 19200))
#define _COM51_38K_ (clock51/(16 * 38400))
#define _COM51_56K_ (clock51/(16 * 57600))
#define _COM51_115K_ (clock51/(16 * 115200))



struct _134_TOD_Clock{ 
  uchar tenthsec;
  uchar sec;
  uchar min;
  uchar hr;
  uchar day;
  uchar month;
  uchar yr;
  uchar daywk:3;
  uchar nu1:5;
  uchar daylit:1;
  uchar nu2:7;
  };

struct _Maxim_TOD_Clock{ 
  uchar sec;
  uchar min;
  uchar hr;
  uchar day;
  uchar month;
  uchar yr;
  };



struct _I2C{ 	/* One byte of the VIA */
  uchar clock:1;
  uchar sin:1;
  uchar sout:1;
  uchar nu:5;
  };

#endif /* Flash_SK_IO_H */
#pragma Pop (List)


