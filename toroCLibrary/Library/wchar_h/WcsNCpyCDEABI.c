/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2024, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    WcsNCpyCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Copy characters of one wide string to another

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>

/**
Synopsis
    #include <wchar.h>
    int wcsncmp(const wchar_t* pszDst, const wchar_t* pszSrc, size_t count);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l?view=msvc-160
Parameters
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l?view=msvc-160#parameters
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l?view=msvc-160#return-value
**/
static wchar_t* wcsncpyCDEABI(wchar_t* pszDst, const wchar_t* pszSrc, size_t n) {
    CDE_APP_IF* pCdeAppIf = __cdeGetAppIf();

    return (wchar_t*)pCdeAppIf->pCdeServices->pMemStrxCpy(WID + BOZ, pszDst, pszSrc, n);

}

MKCDEABI(wcsncpy);