/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    iswspaceCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.

Author:

    Kilian Kegel

--*/
#define _CTYPE_DISABLE_MACROS
#include <_wctype.h>
#include <CdeServices.h>
//
// wctype.
//
typedef unsigned short                wint_t;
#define _SPACE   0x08

extern char _cdeChkIsWxTbl(ISWX_TRUTH_TABLE* pIswxTbl, wint_t c);

extern ISWX_TRUTH_TABLE __cdeIswspace_dflt_tbl[];
static ISWX_TRUTH_TABLE* gpTBLiswspace = __cdeIswspace_dflt_tbl;

/** Brief description of the function’s purpose.

Synopsis
    #include <wctype.h>
    int iswspace(wint_t wc);
Description
    The iswspace function tests for any wide character that corresponds to a locale-specific
    set of white-space wide characters for which none of iswalnum, iswgraph, or
    iswpunct is true.


@param[in] c character to test

@retval _SPACE if upcase letter

@retval 0 if not

**/
static int iswspaceCDEABI(wint_t c) {

    return _SPACE * _cdeChkIsWxTbl(gpTBLiswspace, c);
}

MKCDEABI(iswspace);