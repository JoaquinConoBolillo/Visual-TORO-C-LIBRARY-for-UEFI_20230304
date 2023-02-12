/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    FflushCDEABI.c

Abstract:

    Import Library version

    Implementation of the Standard C function.
    Flushes a stream.

Author:

    Kilian Kegel

--*/
#include <CdeServices.h>

#define EOF    (-1)
#define FILE void

extern int __cdeIsFilePointer(void* stream);
extern int __cdeOnErrSet_errno(CDE_STATUS Status, int Error);
extern void* __cdeGetIOBuffer(unsigned i);
extern __declspec(dllimport) size_t fwrite(const void* ptr, size_t size, size_t nelem, FILE* stream);

/*
Synopsis
    #include <stdio.h>
    int fflush(FILE *stream);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fflush?view=msvc-160&viewFallbackFrom=vs-2019
    Ifstream points to an output stream or an update stream in which the most recent
    operation was not input, the fflush function causes any unwritten data for that stream
    to be delivered to the host environment to be written to the file; otherwise, the behavior is
    undefined.
    Ifstream is a null pointer, the fflush function performs this flushing action on all
    streams for which the behavior is defined above.
Returns
    The fflush function sets the error indicator for the stream and returns EOF if a write
    error occurs, otherwise it returns zero.
*/
static int fflushCDEABI(FILE* stream)
{
    CDEFILE* pCdeFile;
    CDE_APP_IF* pCdeAppIf = __cdeGetAppIf();

    int nRet = EOF;
    int j;
    int cde_filev_max = 0;

    if (NULL != stream)
    {
        // set parameters to flush one file
        cde_filev_max = 1;
        pCdeFile = (CDEFILE*)stream;

    }
    else // NULL == pCdeFile
    {
        // set parameters to flush all files
        cde_filev_max = pCdeAppIf->cIob;
        pCdeFile = (CDEFILE*)__cdeGetIOBuffer(0);
    }

    for (j = 0; j < cde_filev_max; pCdeFile = (CDEFILE*)__cdeGetIOBuffer(++j))
    {
        if ((TRUE == pCdeFile->fRsv) &&
            (pCdeFile->openmode & (O_WRONLY | O_APPEND | O_CREAT | O_RDWR | O_APPEND)) &&
            (pCdeFile->bdirty && !pCdeFile->bclean)
            )
        {
            fwrite(NULL, (size_t)EOF, 0, (void*)pCdeFile);    // NULL,EOF,0,stream == flush parameter
        }
    }
    //TODO: Add Error
    nRet = 0;
    //TODO: Add errno
    return nRet;
}

MKCDEABI(fflush);