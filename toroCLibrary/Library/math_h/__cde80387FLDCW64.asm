;/*++
;
;    toro C Library
;    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library
;
;    Copyright (c) 2017-2024, Kilian Kegel. All rights reserved.
;    SPDX-License-Identifier: GNU General Public License v3.0
;
;Module Name:
;
;    __cde80387FLDCW64.asm
;
;Abstract:
;
;    CDE internal math 80387 instruction FLDCW to load the control word.
;
;		double __cde80387FLDCW(double x)
;
;Author:
;
;    Kilian Kegel
;
;--*/

.code
__cde80387FLDCW proc
	
	local newcw:WORD

	mov newcw, ax

	FLDCW newcw

	ret

__cde80387FLDCW endp
end