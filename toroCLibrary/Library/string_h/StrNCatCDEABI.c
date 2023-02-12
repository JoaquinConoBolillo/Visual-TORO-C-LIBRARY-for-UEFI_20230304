/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    StrNCatCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Appends characters of a string

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>

extern __declspec(dllimport) size_t strlen(const char* pszBuffer);
extern __declspec(dllimport) char* strncpy(char* pszDst, const char* pszSrc, size_t n);

/**
Synopsis
    #include <string.h>
    size_t strlen(const char* pszBuffer) ;
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l?view=msvc-160
Parameters
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l?view=msvc-160#parameters
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l?view=msvc-160#return-value
**/
static char* strncatCDEABI(char* s1, const char* s2, size_t n) {
    size_t size1 = strlen(s1);
    size_t size2 = strlen(s2);
    size_t i = size2 < n ? size2 : n;

    strncpy(&s1[size1], s2, i);
    s1[size1 + i] = 0;

    return s1;
}

MKCDEABI(strncat);