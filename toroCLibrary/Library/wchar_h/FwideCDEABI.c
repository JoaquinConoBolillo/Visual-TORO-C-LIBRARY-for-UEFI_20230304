/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    FwideCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Unimplemented.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>
//
// stdio.h
//
#define FILE void

/** fwide
Synopsis
    #include <wchar.h>
    int fwide(FILE *stream,int mode);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fwide?view=msvc-170#syntax
    NOTE: This function is NOT IMPLEMENTED by Microsoft
    http://www.open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf#page=381
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fwide?view=msvc-170#return-value
**/
static int fwideCDEABI(FILE* stream, int mode)
{
    return mode;
}

MKCDEABI(fwide);