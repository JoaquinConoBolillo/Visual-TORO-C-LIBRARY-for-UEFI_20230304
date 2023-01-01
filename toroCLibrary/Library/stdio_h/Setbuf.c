/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    Setbuf.c

Abstract:

    Implementation of the Standard C function.
    Controls stream buffering. 

Author:

    Kilian Kegel

--*/
#include <stdio.h>
/**

Synopsis
    #include <stdio.h>
    void setbuf(FILE * restrict stream,char * restrict buf);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/setbuf?view=msvc-160&viewFallbackFrom=vs-2019
    Except that it returns no value, the setbuf function is equivalent to the setvbuf
    function invoked with the values _IOFBF for mode and BUFSIZ for size, or (if buf
    is a null pointer), with the value _IONBF for mode.
Returns
    The setbuf function returns no value.

    NOTE MSFT:  1. wrong stream returns success(0) but nothing is done by setvbuf()
                2. wrong mode or size e.g. _IOLBF+_IONBF and -1 leads to return EOF
                3. stream has lower priority as mod and size
    NOTE TORO:  that behavior is implemented differently to MSFT:
                1. check stream, if wrong, return 0
                    then
                2. check the other parms, return 0/EOF as required

**/
void setbuf(FILE* stream, char* buf)
{

    setvbuf(stream, buf, NULL == buf ? _IONBF : _IOFBF, BUFSIZ);
}

