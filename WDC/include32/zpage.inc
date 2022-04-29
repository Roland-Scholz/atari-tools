*:ts=8
*
* Copyright (C) 1998 by Zardoz Software, Inc.
*

;	Compiler zero-page configuration file
;
;	Each of the following items must be defined with the exception of
;	the 'Float' item if no floating point is used. The User Reg space
;	can be of any desired size. This space is used by the compiler to
;	hold automatic variables that would normally be located on the
;	pseudo-stack. Priority is especially given to pointers.
;
;	NOTE! Any changes made to this file must be reflected in the
;	WDC02CC.CFG file in the BIN directory and then the libraries
;	MUST be rebuilt. Also any files previously compiled MUST be
;	recompiled.
;

    .sttl " Zpage.inc "
; bgnpkhdr
;*******************************************************************************
; FILE_NAME:    zpage.inc
;
; TITLE:        Zero Page variables for the W65c02 'C' compiler
;
;  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
;               Copyright(C) 1980-2003
;               All rights reserved. Reproduction in any manner, 
;               in whole or in part, is strictly prohibited without
;               the prior written approval of R & C Services or 
;               Western Design Center.
;
;
; DESCRIPTION:  This File describes data type definitions used for the W65c02 'C' compiler.
;
; SPECIAL_CONSIDERATIONS:
;          None
;
; SHARED_DATA:
;          None.
;
; GLOBAL_MODULES:
;      
;      
;
; LOCAL_MODULES:  
;          None
;
; REVISION_HISTORY
;    Name            Date        Description
;  ------------     ----------   ---------------------------------------------
;  R. Greenthal     12/16/2003    Module created.
;
;
; 
;*******************************************************************************
;


	CHIP	65C02

	PAGE0

************* User Register Start and Count ******************************

	IF	USING_02
;	org	$00:0000	;Use it ALL
	org	$00:0020
	ELSEIF	USING_134
	org	$00:0040
	ENDIF

;**************************	
;16 byte User Register area
;**************************	
REGS	rmb	16		; User Register Count


************* Stack Register Start ***************************************

	

;**************************	
; 8 byte Stack Register area
;**************************	

VAL	rmb	2
SP	rmb	2
AFRAME
FRAME	rmb	2
LFRAME
PC	rmb	2


************* Compiler Register Start ************************************


;**************************	
; 20 byte tmp register area
;**************************	

R0	rmb	4
R1	rmb	4
R2	rmb	4
R3	rmb	4
R4	rmb	4


************* Work Register Start ****************************************


;**************************	
;12 byte zero page temporary area
;**************************	

TMP	rmb	12


************* Float Register Start ***************************************

;	org	$58

Exp0	rmb	2		; 11 byte area for FP0
Sign0	rmb	1		; must be in this order
FP0	rmb	8

Exp1	rmb	2		; 11 byte area for FP1
Sign1	rmb	1		; must be in this order
FP1	rmb	8

;
;	FLOATING POINT ERRORS
;
UNDER_FLOW	equ	1
OVER_FLOW	equ	2
DIV_BY_ZERO	equ	3
;

	ends

;*******************************************************************************
;                        End of File ZPAGE.INC
;*******************************************************************************

