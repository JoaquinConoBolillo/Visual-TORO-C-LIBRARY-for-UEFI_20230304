/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2021, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    Ldiv.c

Abstract:

    Implementation of the Standard C function.
    Computes the quotient and the remainder of two integer values.

Author:

    Kilian Kegel

--*/
#include <stdlib.h>

/**

Synopsis
    #include <stdlib.h>
    ldiv_t ldiv(long number, long denom);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/div?view=msvc-160&viewFallbackFrom=vs-2019
Parameters
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/div?view=msvc-160#parameters
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/div?view=msvc-160#return-value
**/
ldiv_t ldiv(long number, long denom) {
    ldiv_t r;

    r.quot = number / denom;
    r.rem = number % denom;
    return r;
}