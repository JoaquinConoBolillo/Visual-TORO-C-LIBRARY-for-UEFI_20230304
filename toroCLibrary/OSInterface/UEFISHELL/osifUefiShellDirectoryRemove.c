/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    _osifUefiShellDirectoryRemove.c

Abstract:

    OS interface (osif) to remove a directory
    NYI not yet implemented

Author:

    Kilian Kegel

--*/
#define OS_EFI//parameter for CdeServices.h
#include <CdeServices.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int _osifUefiShellDirectoryRemove(IN CDE_APP_IF* pCdeAppIf, const char* strDirectoryName)
{
    return 0;
}