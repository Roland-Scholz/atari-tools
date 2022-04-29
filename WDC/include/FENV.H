/*******************************************************************************
* FILE NAME:   FENV.h
*
* TITLE:       These function prototypes and data type definitions for the Floating Point Exceptions (FPE).
*
*  DATA_RIGHTS: Western Design Center and R & C Services Proprietary
*               Copyright(C) 1980-2004
*               All rights reserved. Reproduction in any manner, 
*               in whole or in part, is strictly prohibited without
*               the prior written approval of R & C Services or 
*               Western Design Center.
*
* DESCRIPTION: This file describes function prototypes and data type
*              definitions used for Floating Point Exceptions (FPE).
*
*
* SPECIAL CONSIDERATIONS:
*	        This is just Templates for REAL Hardware Math Coprocesser
*               The User Must enhance the existing code to mesh with their
*               Math Coprocesser interrupt vectors and registers.
*
* AUTHOR:      R. Greenthal
*
*
* CREATION DATE:  March 27,2004
*
* REVISION HISTORY
*    Name           Date         Description
*    ------------   ----------   ----------------------------------------------
*    R. Greenthal   03/15/2004   Initial
*                   0x/xx/2004	 Added 
*
*******************************************************************************
*/

#ifndef _FENV_H
#define _FENV_H



/*
 *=========================== CONSTANTS & MACROS ===============================
 */


/*  fexcept_t: a type for representing the floating-point exception flags
    collectively, including any status associated with the flags. */


#define FE_DENORM_OP     0x02    /* 80x87, Not mentioned by NCEG */
#define FE_STACK_FLT     0x40    /* 80x87, Not mentioned by NCEG */
#define FE_ALL_EXCEPT    ( FE_INEXACT  | FE_DIVBYZERO | FE_UNDERFLOW | FE_OVERFLOW | FE_INVALID   | FE_DENORM_OP )
#define FE_FLTPREC       0x000
#define FE_INVALIDPREC   0x100
#define FE_DBLPREC       0x200
#define FE_LDBLPREC      0x300


/**********************************/
/* Floating-Point Exception Flags */
/**********************************/
#define  FE_INEXACT        0x02000000     /* inexact */
#define  FE_DIVBYZERO      0x04000000     /* divide-by-zero */
#define  FE_UNDERFLOW      0x08000000     /* underflow */
#define  FE_OVERFLOW       0x10000000     /* overflow */
#define  FE_INVALID        0x20000000     /* invalid */


/****************************/
/* Rounding Direction Modes */
/****************************/
#define  FE_TONEAREST      0x00000000 
#define  FE_TOWARDZERO     0x00000001 
#define  FE_UPWARD         0x00000002 
#define  FE_DOWNWARD       0x00000003
#define  FE_DFL_ENV        &_FE_DFL_ENV   /* pointer to default environment*/


/*
 *============================= FUNCTION CALL PROTOTYPES ============================
 */

typedef unsigned char ftrap_t;			// This may need resizing!

/**********************************/
/* Data Types                     */
/**********************************/
struct __fenv {
  unsigned long control;
  unsigned long status;
  unsigned long tags;
  unsigned long ip_offset;
  unsigned long opcode;
  unsigned long data_offset;
  unsigned long op_sel;
};
typedef struct __fenv fenv_t;


struct __fexcept {
         int excepts;
         void *code_address;
         void *data_address;
};
typedef struct __fexcept fexcept_t;


/* These may be like your FPE Vectors */
struct fptraps {
  ftrap_t invalid;
  ftrap_t stack_flt;
  ftrap_t denorm_op;
  ftrap_t divbyzero;
  ftrap_t overflow;
  ftrap_t underflow;
  ftrap_t inexact;
  int trap_invalid;
  int trap_stack_flt;
};



/* A place to keep the unmasked "sticky" bits. */
extern int sticky;


extern fenv_t __default_fp_env;

/************************************************************/
/* Definition of pointer to IEEE default environment object */
/************************************************************/
extern fenv_t _FE_DFL_ENV;         // default environment object 



/*******************************************************************************
*	        This is just Templates for REAL Hardware Math Coprocesser
*               The User Must enhance the existing code to mesh with their
*               Math Coprocesser interrupt vectors and registers.
********************************************************************************/
/*  fenv_t: a type for representing the entire floating-point environment. */
/*  fenv_t is not defined in detail by NCEG.
    For Linux, we use the FPU environment:  */



/*
 These eleven functions were defined in C99, and describe the handling of
 floating point rounding and exceptions (overflow, zero-divide etc.). 
*/

/*******************************************************/
/* Functions Controlling the Floating-Point Exceptions */
/*******************************************************/
void feclearexcept(int excepts);
void fegetexceptflag(fexcept_t *flagp, int excepts);
void feraiseexcept(int excepts);
void fesetexceptflag(const fexcept_t *flagp, int excepts);
int fetestexcept(int excepts); 


/**************************************/
/* Controlling the Rounding Direction */
/**************************************/
int fegetround(void);
int fesetround(int rounding_mode); 


/**********************************************/
/* Controlling the Floating-Point Environment */
/**********************************************/
void fegetenv (fenv_t *envp);
int feholdexcept (fenv_t *envp);
void fesetenv (const fenv_t *envp);
void feupdateenv (const fenv_t *envp);



/*******************************************************/
/*******************************************************/
/*             Extra                                   */
/* Functions Controlling the Floating-Point Precision  */
/*******************************************************/
/*******************************************************/

int fegetprecision(void);
int fesetprecision(int prec);

int fegetvector(ftrap_t *trap, int except);
int fesetvector(ftrap_t *trap, int except);
int fegettraps(void);
int fedisabletraps(int excepts);
int feenabletraps(int excepts);

int __sigfpe_abort(char *s, void *p);
void __set_sticky(int bits);



#endif /* End of _FENV_H */

/**************************************
	End of File FENV.H
***************************************/
