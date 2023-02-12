/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    Div.c

Abstract:

    Implementation of the Standard C function.
    Computes the quotient and the remainder of two integer values.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>
//
// stdlib.h
//
typedef struct _div_t
{
    int quot;
    int rem;
} div_t;

/**

Synopsis
    #include <stdlib.h>
    div_t div(int number, int denom);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/div?view=msvc-160&viewFallbackFrom=vs-2019  
Parameters
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/div?view=msvc-160#parameters
Returns
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/div?view=msvc-160#return-value
**/
static div_t divCDEABI(int number, int denom) {
    div_t r;

    r.quot = number / denom;
    r.rem = number % denom;
    return r;
}

MKCDEABI(div);