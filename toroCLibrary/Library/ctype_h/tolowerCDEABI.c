/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    tolowerCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>

extern __declspec(dllimport) int isupper(int c);

/** Brief description of the function’s purpose.

Synopsis
    #include <ctype.h>
    int tolower(int c);
Description
    The tolower function converts an uppercase letter to a corresponding lowercase letter.
Returns
    If the argument is a character for which isupper is true and there are one or more
    corresponding characters, as specified by the current locale, for which islower is true,
    the tolower function returns one of the corresponding characters (always the same one
    for any giv en locale); otherwise, the argument is returned unchanged.

    The function returns the corresponding lowercase letter if one exists and
    if isupper(c); otherwise, it returns c.

    @param[in] c character to test for upcase

    @retval ISUPPER if upcase letter

    @retval 0 if not

**/
static int tolowerCDEABI(int c)
{
    return isupper(c) ? 'a' + c - 'A' : c;
}

MKCDEABI(tolower);