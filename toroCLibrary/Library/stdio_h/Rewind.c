/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    Rewind.c

Abstract:

    Implementation of the Standard C function.
    Repositions the file pointer to the beginning of a file.

Author:

    Kilian Kegel

--*/
#include <stdio.h>

/** 
Synopsis
    #include <stdio.h>
    void rewind(FILE *stream);
Description
    https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/rewind?view=msvc-160&viewFallbackFrom=vs-2019
    The rewind function  sets  the  file  position  indicator  for  the  stream  pointed  to  by
    stream to the beginning of the file.  It is equivalent to (void)fseek(stream, 0L, SEEK_SET)
    except that the error indicator for the stream is also cleared.
Returns
    The rewind function returns no value.

**/
extern int fsetpos(FILE* stream, const fpos_t* pos);
void rewind(FILE* stream) {
    fpos_t pos = (fpos_t)0;
    //todo: Add clear error indicator

    fsetpos(stream, &pos);
    return;
}