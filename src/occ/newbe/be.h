/*
    Software License Agreement (BSD License)
    
    Copyright (c) 1997-2011, David Lindauer, (LADSoft).
    All rights reserved.
    
    Redistribution and use of this software in source and binary forms, 
    with or without modification, are permitted provided that the following 
    conditions are met:
    
    * Redistributions of source code must retain the above
      copyright notice, this list of conditions and the
      following disclaimer.
    
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the
      following disclaimer in the documentation and/or other
      materials provided with the distribution.
    
    * Neither the name of LADSoft nor the names of its
      contributors may be used to endorse or promote products
      derived from this software without specific prior
      written permission of LADSoft.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER 
    OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
    OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "compiler.h"

#define live(mask, reg) (mask & (1 << reg))

/*
 *      code generation structures and constants
 */

/* address mode specifications */
#ifdef XXXXX
#define F_VOL   1      /* need volitile operand */
#define F_NOVALUE 2    /* dont need result value */
#define F_DREG  4       /* data register direct mode allowed */
#define F_AREG  8       /* address register direct mode allowed */
#define F_MEM   16       /* memory alterable modes allowed */
#define F_IMMED 32      /* immediate mode allowed */
#define F_ALT   (F_DREG | F_AREG | F_MEM)       /* alterable modes */
#define F_DALT  (F_DREG | F_MEM)       /* data alterable modes */
#define F_FREG  64  	/* FP register */
#define F_INDX  128	/* indexed memory alterable mode allowed */
#define F_ALL   (F_ALT | F_IMMED | F_REG | F_INDX)      /* all modes allowed */
#define F_NOBIT 256	/* Don't get the bit val, get the address */
#define F_DEST 512	/* Is going to be used as a destination */
#define F_AXDX 1024  /* longlong in dx,ax */
#define F_NOREUSE 2048 /* don't reuse the register */
#endif

#define OPE_MATH 1
#define OPE_ARPL 2
#define OPE_BOUND 3
#define OPE_BITSCAN 4
#define OPE_BIT 5
#define OPE_CALL 6
#define OPE_INCDEC 7
#define OPE_RM 8
#define OPE_ENTER 9
#define OPE_IMUL 10
#define OPE_IN 11
#define OPE_IMM8 12
#define OPE_RELBRA 13
#define OPE_RELBR8 14
#define OPE_JMP 15
#define OPE_REGRM 16
#define OPE_LOADSEG 17
#define OPE_LGDT 18
#define OPE_LIDT 19
#define OPE_RM16 20
#define OPE_MOV 21
#define OPE_MOVSX 22
#define OPE_OUT 23
#define OPE_PUSHPOP 24
#define OPE_SHIFT 25
#define OPE_RET 26
#define OPE_SET 27
#define OPE_SHLD 28
#define OPE_TEST 29
#define OPE_XCHG 30
#define OPE_FMATH 31
#define OPE_FMATHP 32
#define OPE_FMATHI 33
#define OPE_FCOM 34
#define OPE_FREG 35
#define OPE_FICOM 36
#define OPE_FILD 37
#define OPE_FIST 38
#define OPE_FLD 39
#define OPE_FST 40
#define OPE_FSTP 41
#define OPE_FUCOM 42
#define OPE_FXCH 43
#define OPE_MN 44
#define OPE_M16 45
#define OPE_CMPS 46
#define OPE_INS 47
#define OPE_LODS 48
#define OPE_MOVS 49
#define OPE_OUTS 50
#define OPE_SCAS 51
#define OPE_STOS 52
#define OPE_XLAT 53
#define OPE_REG32 54

#define MAX_SEGS browseseg + 1 

enum e_op
{
    op_reserved, op_line, op_blockstart, op_blockend, op_varstart, op_funcstart, op_funcend, op_void, 
    op_comment, op_label, op_funclabel, op_seq,
        op_genword, op_dd, op_aaa, op_aad, op_aam,
        op_aas, op_add, op_adc, op_and, op_arpl, op_bound, op_bsf, op_bsr,
        op_bswap, op_btc, op_bt, op_btr, op_bts, op_call, op_cbw, op_cwde,
        op_cwd, op_cdq, op_clc, op_cld, op_cli, op_clts, op_cmc, op_cmp,
        op_cmpxchg, op_cmpxchg8b,
        op_cmps, op_cmpsb, op_cmpsw, op_cmpsd, op_daa, op_das, op_dec, op_div,
        op_enter, op_hlt, op_idiv, op_imul, op_in, op_inc, op_ins, op_insb,
        op_insw, op_insd, op_int, op_int3, op_into, op_invd, op_iret, op_iretd,
        op_jecxz, op_ja, op_jnbe, op_jae, op_jnb, op_jnc, op_jb, op_jc, op_jnae,
        op_jbe, op_jna, op_je, op_jz, op_jg, op_jnle, op_jl, op_jnge, op_jge,
        op_jnl, op_jle, op_jng, op_jne, op_jnz, op_jo, op_jno, op_jp, op_jnp,
        op_jpe, op_jpo, op_js, op_jns, op_jmp, op_lahf, op_lar, op_lds, op_les,
        op_lfs, op_lgs, op_lss, op_lea, op_leave, op_lfence, op_lgdt, op_lidt, op_lldt,
        op_lmsw, op_lock, op_lods, op_lodsb, op_lodsw, op_lodsd, op_loop,
        op_loope, op_loopz, op_loopne, op_loopnz, op_lsl, op_ltr, op_mfence, op_mov,
        op_movs, op_movsb, op_movsw, op_movsd, op_movsx, op_movzx, op_mul,
        op_neg, op_not, op_nop, op_or, op_out, op_outs, op_outsb, op_outsw,
        op_outsd, op_pop, op_popa, op_popad, op_popf, op_popfd, op_push,
        op_pusha, op_pushad, op_pushf, op_pushfd, op_rcl, op_rcr, 
        op_rdmsr, op_rdpmc, op_rdtsc,
        op_rol, op_ror, op_rep, op_repne, op_repe, op_repnz, op_repz, op_ret,
        op_retf, op_sahf, op_sal, op_sar, op_shl, op_shr, op_sbb, op_scas,
        op_scasb, op_scasw, op_scasd, op_seta, op_setnbe, op_setae, op_setnb,
        op_setnc, op_setb, op_setc, op_setnae, op_setbe, op_setna, op_sete,
        op_setz, op_setg, op_setnle, op_setl, op_setnge, op_setge, op_setnl,
        op_setle, op_setng, op_setne, op_setnz, op_seto, op_setno, op_setp,
        op_setnp, op_setpe, op_setpo, op_sets, op_setns, op_sfence, op_sgdt, op_sidt,
        op_sldt, op_smsw, op_shld, op_shrd, op_stc, op_std, op_sti, op_stos,
        op_stosb, op_stosw, op_stosd, op_str, op_sub, op_test, op_verr, op_verw,
        op_wait, op_wbinvd, op_wrmsr, op_xchg, op_xlat, op_xlatb, op_xor, op_f2xm1,
        op_fabs, op_fadd, op_faddp, op_fiadd, op_fchs, op_fclex, op_fnclex,
        op_fcom, op_fcomp, op_fcompp, op_fcos, op_fdecstp, op_fdiv, op_fdivp,
        op_fidiv, op_fdivr, op_fdivrp, op_fidivr, op_ffre, op_ficom, op_ficomp,
        op_fild, op_fincstp, op_finit, op_fninit, op_fist, op_fistp, op_fld,
        op_fldz, op_fldpi, op_fld1, op_fld2t, op_fld2e, op_fldlg2, op_fldln2,
        op_fldcw, op_fldenv, op_fmul, op_fmulp, op_fimul, op_fpatan, op_fprem,
        op_fprem1, op_fptan, op_frndint, op_frstor, op_fsave, op_fnsave,
        op_fscale, op_fsin, op_fsincos, op_fsqrt, op_fst, op_fstp, op_fstcw,
        op_fstsw, op_fnstcw, op_fnstsw, op_fstenv, op_fsntenv, op_fsub,
        op_fsubp, op_fisub, op_fsubr, op_fsubrp, op_fisubr, op_ftst, op_fucom,
        op_fucomp, op_fucompp, op_fwait, op_fxam, op_fxch, op_fxtract, op_fyl2x,
        op_fyl2xp1
};
enum e_asmw
{
    akw_byte, akw_word, akw_dword, akw_fword, akw_qword, akw_tbyte, akw_offset,
        akw_ptr
};

enum e_am
{
    am_none, am_axdx, am_dreg, am_freg, am_frfr, am_cfreg, am_screg, am_sdreg, am_streg,
        am_seg, am_indisp, am_indispscale, am_fconst, am_direct, am_immed,
        am_ext, am_segoffs, 
    /* these MUST be in this order, and last!!! */
    am_stackedtemp, am_stackedtempaddr
};

enum fconst
{
    fczero, fcone, fcmone
};

/*      addressing mode structure       */

struct amode
{
    enum e_am mode;
    char preg;
    char sreg;
    char tempflag;
    char scale;
    char length;
    char addrlen;
    enum
    {
        e_default, e_cs, e_ds, e_es, e_fs, e_gs, e_ss
    } seg;
    EXPRESSION *offset;
    int liveRegs;
    int keepesp : 1;
};

/*      output code structure   */

struct ocode
{
    struct ocode *fwd,  *back;
    enum e_op opcode;
    struct amode *oper1,  *oper2,  *oper3;
    int address;
    int size;
    int blocknum;
    UBYTE outbuf[16];
    char diag;
    char noopt;
    char resolved;
    UBYTE addroffset;
    UBYTE outlen;
    UBYTE branched;
    UBYTE resobyte;
};

/* Used for fixup gen */
typedef struct dl
{
    struct dl *next;
    char *string;
    int offset;
    short type;
} DATALINK;

#define AMODE struct amode
#define OCODE struct ocode

#define FLOAT printf("codegen-Floating point not implemented in push/pop\n");
/* 386 register set */
#define EAX 0
#define ECX 1
#define EDX 2
#define EBX 3
#define ESP 4
#define EBP 5
#define ESI 6
#define EDI 7
#define EIP 8

#define AL 0
#define CL 1
#define DL 2
#define BL 3
#define CS 1
#define DS 2
#define ES 3
#define FS 4
#define GS 5
#define SS 6

#define OP_CODEONLY 0
#define OP_WREG02 1
#define OP_ACCREG02 2
#define OP_SEG35 3
#define OP_REGRMREG 4
#define OP_RM 5
#define OP_RMSHIFT 6
#define OP_REGRM 7
#define OP_WORDREGRM 8
#define OP_INTR 9
#define OP_SHORTBRANCH 10
#define OP_RMIMM 11
#define OP_ACCIMM 12
#define OP_ABSACC 13
#define OP_RMIMMSIGNED 14
#define OP_ACCIMMB3 15
#define OP_SEGRMSEG 16
#define OP_RET 17
#define OP_SEGBRANCH 18
#define OP_ESC 19
#define OP_BRANCH 20
#define OP_ACCDX 21
#define OP_DXACC 22
#define OP_PORTACCPORT 23
#define OP_ACCABS 24
#define OP_IMM 25
#define OP_ENTER 26
#define OP_INSWORDSIZE 27
#define OP_REGMOD 28
#define OP_NOSTRICTRM  29
#define OP_RMSHIFTB3 30
#define OP_IMUL 31
#define OP_386REG 32
#define OP_REGRMSHIFT 33
#define OP_PUSHW 34
#define OP_FLOATRM 35
#define OP_FLOATMATHP 36
#define OP_FLOATMATH 37
#define OP_FARRM 38
#define OP_WORDRMREG 39
#define OP_RMREG 40
#define OP_BITNUM 41
#define OP_MIXEDREGRM 42
#define OP_CBW  43
#define OP_REG02  44
#define OP_BYTERMREG  45
#define OP_FLOATNOPTR  46
#define OP_AX	 47
#define OP_BSWAP  48
#define OP_FST  49
#define OP_FLD  50
#define OP_FBLD  51
#define OP_FILD  52
#define OP_FIST  53
#define OP_FREG  54
#define OP_FREGMAYBE  55
#define OP_FLOATIMATH  56
#define OP_INSDWORDSIZE  57
#define OP_CMPS  58
#define OP_INS  59
#define OP_LODS  60
#define OP_MOVS  61
#define OP_OUTS  62
#define OP_SCAS  63
#define OP_STOS  64
#define OP_REG03 65

typedef struct _opcode
{
    short ocoperands;
    short ocvalue;
    short ocflags;
} OPCODE;

#define OCAlwaysword	0x2000
#define OCprefixfwait   0x1000
#define OCprefix0F	0x800
#define OCtwobyte	0x200
#define OCsystem 	0x100
#define OCfloatmask	0x0f0
#define OCfloatshift	4
#define OCprocmask	0x0f

typedef struct muldiv
{
    struct muldiv *next;
    long value;
    FPF floatvalue;
    int size;
    int label;
} MULDIV;

#define BR_LONG 1
#define BR_SHORT 2
typedef struct
{
    int address;
    int seg;
} LABEL;

typedef struct fixup
{
    struct fixup *next;
    int address;
    enum mode
    {
        fm_label, fm_symbol, fm_rellabel, fm_relsymbol, fm_threadlocal
    } fmode;
    SYMBOL *sym, *base;
    int label;
} FIXUP;


/*-------------------------------------------------------------------------*/


typedef struct emitlist
{
    struct emitlist *next;
    int filled, lastfilled;
    int address;
    UBYTE data[65536];
    FIXUP *fixups,  *lastfixup;
} EMIT_LIST;

typedef struct _attribdata
{
    struct _attribdata *next;
    enum e_adtype { e_ad_linedata, e_ad_blockdata, e_ad_funcdata, e_ad_vardata } type;
    union
    {
        LINEDATA *ld;
        SYMBOL *sp;
    } v;
    int address;
    int start;
} ATTRIBDATA;
typedef struct
{
    int curbase;
    int curlast;
    EMIT_LIST *first;
    EMIT_LIST *last;
    ATTRIBDATA *attriblist;
    ATTRIBDATA *attribtail;
} EMIT_TAB;

typedef struct _virtual_list
{
    struct _virtual_list *next;
    SYMBOL *sp;
    EMIT_TAB *seg;
    int data;
} VIRTUAL_LIST;

typedef struct _dbgblock
{
    struct _dbgblock *next;
    struct _dbgblock *parent;
    struct _dbgblock *child;
    HASHREC *syms;
    int startlab;
    int endlab;
} DBGBLOCK;

enum asmTypes { pa_nasm, pa_fasm, pa_masm, pa_tasm} ; 

enum omf_type
{
    THEADR = 0x80,  /* module header */
    COMENT = 0x88,  /* comment record */

    LINNUM = 0x95,  /* line number record */
    LNAMES = 0x96,  /* list of names */

    SEGDEF = 0x99,  /* segment definition */
    GRPDEF = 0x9A,  /* group definition */
    EXTDEF = 0x8C,  /* external definition */
    PUBDEF = 0x91,  /* public definition */
    COMDEF = 0xB0,  /* common definition */

    LEDATA16 = 0xA0,
    LEDATA = 0xA1,  /* logical enumerated data */
    FIXUPP = 0x9D,  /* fixups (relocations) */
    LIDATA16 = 0xA2, 
    LIDATA = 0xA3, 

    MODEND = 0x8A /* module end */
};

#define REG_MAX 32

#define R_EAX 0
#define R_ECX 1
#define R_EDX 2
#define R_EAXEDX 8
#define R_EDXECX 10
#define R_AL 16
#define R_CL  17
#define R_AX 24
#define R_CX 25

#include "be.p"
