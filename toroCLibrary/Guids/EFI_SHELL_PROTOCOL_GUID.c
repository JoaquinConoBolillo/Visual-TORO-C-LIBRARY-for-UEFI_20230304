/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    EFI_SHELL_PROTOCOL_GUID.c

Abstract:

    Definition of EFI_SHELL_PROTOCOL_GUID

Author:

    Kilian Kegel

--*/
#define OS_EFI
#include <uefi.h>
#include <Protocol\Shell.h>

EFI_GUID _gCdeEfiShellProtocolGuid = EFI_SHELL_PROTOCOL_GUID;
