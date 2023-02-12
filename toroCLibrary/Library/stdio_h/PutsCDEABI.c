/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    PutsCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Writes a string to stdout.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>
//
// stdio.h
//
#define EOF    (-1)
#define FILE void

extern __declspec(dllimport) size_t fwrite(const void* ptr, size_t size, size_t nelem, FILE* stream);
extern __declspec(dllimport) size_t strlen(const char* pszBuffer);

/** puts
Synopsis
    #include <stdio.h>
    int puts(const char *s);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/puts-putws?view=msvc-160&viewFallbackFrom=vs-2019
    The puts function writes the string pointed to by s to the stream pointed to by stdout,
    and appends a new-line character to the output. The terminating null character is not
    written.
Returns
    The puts function returns EOF if a write error occurs; otherwise it returns a nonnegative
    value.

    **/
static int putsCDEABI(const char* s) {
    size_t nRet = 0;
    char c = '\n';
    do {
        nRet = fwrite(s, 1, strlen(s), (FILE*)CDE_STDOUT);
        if (nRet == EOF)
            break;
        nRet = fwrite(&c, 1, 1, (FILE*)CDE_STDOUT);
    } while (0);

    fwrite(NULL, (size_t)EOF, 0, (FILE*)CDE_STDOUT);	//flush to stdout

    return nRet != EOF ? 0 : EOF;
}

MKCDEABI(puts);