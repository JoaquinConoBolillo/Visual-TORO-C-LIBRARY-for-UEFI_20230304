;/*++
;
;    toro C Library
;    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library
;
;    Copyright (c) 2017-2024, Kilian Kegel. All rights reserved.
;    SPDX-License-Identifier: GNU General Public License v3.0 only
;
;Module Name:
;
;    __chkstk64.asm
;
;Abstract:
;
;   Microsoft specific helper function
;   https://docs.microsoft.com/en-us/windows/win32/devnotes/-win32-chkstk
;   Adjusted for CDE usage.
;
;--*/
    public ___chkstk
    public ___cdeChkStkAddr
    .model flat
    .data

    ;
    ; NOTE: __chkstkWindows is filled here by the Windows64 _MainEntryPointWinNT
    ;
___cdeChkStkAddr dword 0         
    
    .code

___chkstk proc

    cmp [___cdeChkStkAddr], 0
    je  exit
    jmp [___cdeChkStkAddr]
exit:
    ret

___chkstk endp

end