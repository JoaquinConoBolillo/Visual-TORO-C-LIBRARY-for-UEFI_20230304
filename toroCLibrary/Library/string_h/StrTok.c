/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2022, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    StrTok.c

Abstract:

    Implementation of the Standard C function.
    Finds the next token in a string.

Author:

    Kilian Kegel

--*/
/*!
\copyright

    Torito C Library, Copyright (c) 2020, Kilian Kegel. All rights reserved.

\mainpage StrTok

\brief Implementation of the <em>StrTok</em> function

\file StrTok.c

*/
#include <CdeServices.h>

/**
Synopsis
    #include <string.h>
    char* strtok(char* pszStr, const char* pszSet);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l?view=msvc-160
Parameters
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l?view=msvc-160#parameters
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l?view=msvc-160#return-value
**/
static ROMPARM_WCSSTRTOK ROMPARM = {    
    /*fForceToDataSeg       */ 1 ,\
    /*fWide                 */ sizeof(char) > 1 ,\
};

char* strtok(char* pszStr, const char* pszSet) {

    CDE_APP_IF* pCdeAppIf = __cdeGetAppIf();

    return (char*)pCdeAppIf->pCdeServices->pWcsStrTok(pCdeAppIf, pszStr, pszSet, &pCdeAppIf->pStrtokStaticInternal, &ROMPARM);

}
