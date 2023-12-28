/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2024, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    strtoumaxCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Converts strings to an integer value of the largest supported unsigned integer type.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>

extern __declspec(dllimport) unsigned long long strtoull(const char* s, char** endptr, int base);

/**

Synopsis
    #include <inttypes.h>
    uintmax_t strtoumax(const char* strSource, char** endptr, int base);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strtoumax-strtoumax-l-wcstoumax-wcstoumax-l
    https://www.open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf#page=212
    The strtoimax and strtoumax functions are equivalent to the strtol, strtoll,
    strtoul, and strtoull functions, except that the initial portion of the string is
    converted to intmax_t and uintmax_t representation, respectively
Paramaters
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strtoumax-strtoumax-l-wcstoumax-wcstoumax-l#parameters
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strtoumax-strtoumax-l-wcstoumax-wcstoumax-l#return-value

**/
static uintmax_t strtoumaxCDEABI(const char* strSource, char** endptr, int base) 
{
    return strtoull(strSource, endptr, base);
}

MKCDEABI(strtoumax);