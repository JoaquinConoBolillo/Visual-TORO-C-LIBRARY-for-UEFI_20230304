/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2024, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    VprintfCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Writes formatted output by using a pointer to a list of arguments.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>
#include <stdarg.h>

//
// stdio.h
//
#define FILE void
#define stdout (__acrt_iob_func(1))

extern FILE* __acrt_iob_func(unsigned i);
extern __declspec(dllimport) int vfprintf(FILE* stream, const char* pszFormat, va_list ap);

/**
Synopsis
    #include <stdio.h>
    int vprintf(const char* pszFormat, va_list ap);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l?view=msvc-160&viewFallbackFrom=vs-2019
Parameters
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l?view=msvc-160#parameters
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l?view=msvc-160#return-value
**/
static int vprintfCDEABI(const char* pszFormat, va_list ap) {

    return vfprintf(stdout, pszFormat, ap);
}

MKCDEABI(vprintf);