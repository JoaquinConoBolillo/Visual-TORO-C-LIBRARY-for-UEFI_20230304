/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2025, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    fmod.c

Abstract:

    Implementation of the Standard C function.
    Calculates the floating-point remainder.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>
#include <math.h>

//extern double modf(double x, double* intptr);
extern double __cdecl __cde80387FPREM(double x, double y);

/**

Synopsis
    #include <math.h>
    double fmod(double x);
Description
    https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fmod-fmodf
Parameters
    https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fmod-fmodf#parameters
Returns
    https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fmod-fmodf#return-value

**/
double __cdecl fmod(double x, double y)
{
    CDEDOUBLE dRet, * py = (void*)&y;

    dRet.dbl = x;

    do
    {
        if (0.0 == y || -0.0 == y)
        {
            if (0x7FF == dRet.member.exp) {
                if (0 == dRet.member.mant)
                    dRet.member.mant |= 0x0008000000000000ULL;
                break;
            }
        }

        if (0x7FF == py->member.exp && 0Ull != py->member.mant) {
            dRet.dbl = y;
            break;
        }

        if (INFINITY == x || -INFINITY == x) {
            dRet.member.exp = 0x7FF;
            dRet.member.mant = 0x0008000000000000;
            break;
        }

        if (0.0 == y || -0.0 == y) {
            dRet.member.exp = 0x7FF;
            dRet.member.mant = 0x0008000000000000;
            dRet.uint64 = 0x7FF8000000000000ULL;
            break;
        }

        if (0x7FF == dRet.member.exp && 0ULL != dRet.member.mant)
            break;

        dRet.dbl = __cde80387FPREM(x, y);

    } while (0);

    return dRet.dbl;
}
