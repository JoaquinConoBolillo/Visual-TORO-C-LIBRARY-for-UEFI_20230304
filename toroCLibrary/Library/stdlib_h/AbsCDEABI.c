/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2024, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    AbsCDEABS.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Sends a signal to the executing program.

Author:

    Kilian Kegel

--*/

#include <CdeServices.h>

static int absCDEABI(int i) {
    return i < 0 ? -i : i;
}

MKCDEABI(abs);