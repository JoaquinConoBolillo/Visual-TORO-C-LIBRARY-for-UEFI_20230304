/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2024, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    WcsCatCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Appends a wide string.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>

extern __declspec(dllimport) wchar_t* wcscpy(wchar_t* pszDst, const wchar_t* pszSrc);
extern __declspec(dllimport) size_t wcslen(const wchar_t* pszBuffer);

/**
Synopsis
    #include <wchar.h>
    wchar_t* wcscat(wchar_t* s1, const wchar_t* s2);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strcat-wcscat-mbscat?view=msvc-160
Parameters
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strcat-wcscat-mbscat?view=msvc-160#parameters
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strcat-wcscat-mbscat?view=msvc-160#return-value
**/
static wchar_t* wcscatCDEABI(wchar_t* s1, const wchar_t* s2) {
    wcscpy(&s1[wcslen(s1)], s2);
    return s1;
}

MKCDEABI(wcscat);