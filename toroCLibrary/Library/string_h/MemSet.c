/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    MemSet.c

Abstract:

    Implementation of the Standard C function.
    Sets buffers to a specified character.

Author:

    Kilian Kegel

--*/
#include <stddef.h>

/**

Synopsis
    #include <string.h>
    void *memset(void *s, int c, size_t n);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/memset-wmemset?view=msvc-160
    The memset function copies the value of c (converted to an unsigned char) into
    each of the first n characters of the object pointed to by s.
Returns
    The memset function returns the value of s.void *memset(void *s, int c, size_t n){

    @param[in]  void *s     buffer address
                int c       fill
                size_t n    number of characters

    @retval void *s

**/
void* memset(void* s, int c, size_t n) {
    unsigned char* p;
    size_t i;

    for (i = 0, p = (unsigned char*)s; i < n; i++)
        p[i] = (unsigned char)c;
    return s;
}
