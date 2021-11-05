/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2021, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    _cdeWcsStrPbrkSpn.c

Abstract:

    CDE internal worker function for all of the str/wcs--pbrk/spn()-family

Author:

    Kilian Kegel

--*/

#include <CdeServices.h>
#include <stdio.h>

unsigned int _strlen(const char* pszBuffer);
unsigned int _wcslen(const short* pszBuffer);
#define STRLEN(pszStr) (PRESET_WID ? _wcslen((short*)pszStr) : _strlen(pszStr))

void* _cdeWcsStrPbrkSpn(
    IN signed preset,
    IN void* pszStr,
    IN const void* pszSet
) {
    signed c1, c2;
    wchar_t* pStr16 = pszStr;
    char* pStr8 = pszStr;
    unsigned i, iOnBreak = (unsigned)-1;
    void* pRet;
    int j;

    unsigned char fBreak = 0;
    signed  xcrement = PRESET_TDN ? -1 : 1;//increment vs decrement

    i = PRESET_TDN ? STRLEN(pszStr) - 1 : 0;

    for (pStr16 = &pStr16[i], \
        pStr8 = &pStr8[i]; \

        fBreak == 0; \

        i += xcrement, \
        pStr16 = &pStr16[xcrement], \
        pStr8 = &pStr8[xcrement])
    {

        //c1 = (i == (unsigned)-1 ? '\0' : (PRESET_WID ? *pStr16 : *pStr8));
        if (i == (unsigned)EOF)
            c1 = EOF;
        else
            if (PRESET_WID)
                c1 = *pStr16;
            else
                c1 = *pStr8;

        if (c1 == '\0' || c1 == EOF) {
            fBreak = 1;
            iOnBreak = i;
            break;
        }

        c2 = PRESET_WID ? ((wchar_t*)pszSet)[0] : ((unsigned char*)pszSet)[0];

        for (j = 0; c2; c2 = PRESET_WID ? ((wchar_t*)pszSet)[++j] : ((unsigned char*)pszSet)[++j]) {

            fBreak = (c1 == c2);
            if (fBreak)
                break;

        }
        fBreak = (PRESET_INV ? (!fBreak) : fBreak);
        iOnBreak = i;
    }

    if ((fBreak && iOnBreak != (unsigned)EOF)) {
        if (PRESET_WID)
            pRet = &((wchar_t*)pszStr)[iOnBreak];
        else
            pRet = &((char*)pszStr)[iOnBreak];
    }
    else
        pRet = NULL;

    return pRet;/*((fBreak && iOnBreak != (unsigned)-1)? (PRESET_WID ? &((wchar_t*)pStr16)[iOnBreak] : (wchar_t*)&((unsigned char*)pStr8)[iOnBreak]) : NULL);*/

}