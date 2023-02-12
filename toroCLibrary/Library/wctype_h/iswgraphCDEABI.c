/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    iswgraphCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.

Author:

    Kilian Kegel

--*/
#define _CTYPE_DISABLE_MACROS
#include <CdeServices.h>
//
// wchar.h
//
typedef unsigned short                wint_t;

extern __declspec(dllimport) int iswalnum(wint_t c);
extern __declspec(dllimport) int iswpunct(wint_t c);

/** Brief description of the function’s purpose.

Synopsis
    #include <wctype.h>
    int iswgraph(wint_t wc);
Description
    The iswgraph function tests for any wide character for which iswprint is true and
    iswspace is false

    @param[in] c character to test for isgraph

    @retval _ALPHA | ISDIGIT | ISPUNCT if matching letter

    @retval 0 if not

**/
static int iswgraphCDEABI(wint_t c) {

    int nRet0 = 0;

    nRet0 = iswalnum(c) | iswpunct(c);

    return nRet0;
}

MKCDEABI(iswgraph);