/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2025, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    _gCdeCfgCmdLnParmPoolMemRetain.c

Abstract:

    Runtimeswitch.
    Retain pool allocated memory at process runtime
    (Reason for this proceeding was, that shell was crashed on process' exit() -- so keep pool memory)
    
    NOTE:   This is the default setting. It could be overwritten at runtime or overloaded
            with a linked .OBJ module that provides unsigned char _gCdeCfgCmdLnParmPoolMemRetain = 0

Author:

    Kilian Kegel

--*/
unsigned char _gCdeCfgCmdLnParmPoolMemRetain = 1;