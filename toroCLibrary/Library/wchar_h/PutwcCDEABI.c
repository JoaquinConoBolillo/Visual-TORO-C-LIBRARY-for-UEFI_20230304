/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    PutwcCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Writes a wide character to a stream.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>
//
// stdio.h
//
#define FILE void
//
// wchar.h
//
typedef unsigned short wint_t;

extern __declspec(dllimport) wint_t fputwc(wchar_t c, FILE* stream);

/** fputc
Synopsis
    #include <stdio.h>
    #include <wchar.h>
    wint_t putwc(wchar_t c, FILE *stream);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/putc-putwc?view=msvc-160&viewFallbackFrom=vs-2019
    http://www.open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf#page=382
    The putwc function is equivalent to fputwc, except that if it is implemented as a
    macro, it may evaluate stream more than once, so that argument should never be an
    expression with side effects.
Returns
    The putwc function returns the wide character written, or WEOF.

**/
static wint_t putwcCDEABI(wchar_t c, FILE* stream) {
    return fputwc(c, stream);
}

MKCDEABI(putwc);