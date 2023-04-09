/*++

    toro C Library
    https://github.com/KilianKegel/toro-C-Library#toro-c-library-formerly-known-as-torito-c-library

    Copyright (c) 2017-2023, Kilian Kegel. All rights reserved.
    SPDX-License-Identifier: GNU General Public License v3.0

Module Name:

    _osifUefiShellCmdExec.c

Abstract:

    OS interface (osif) to run a command on system shell

Author:

    Kilian Kegel

--*/
#define OS_EFI
#define _INC_STDDEF         // exclude MSFT STDDEF.H, that conflicts with errno
#include <CdeServices.h>
#include <cde.h>
//
// wchar.h
//
extern __declspec(dllimport) int wcsncmp(const wchar_t* pszDst, const wchar_t* pszSrc, size_t count);

//
// string.h
//
extern __declspec(dllimport) size_t strlen(const char* pszBuffer);

#include <Protocol\SimpleFileSystem.h>
#include <CdeServices.h>
#include <Protocol\Shell.h>
#include "Protocol\DevicePathToText.h"
# define ELC(x)/*ELementCount*/ (sizeof(x) / sizeof(x[0]))

extern EFI_SHELL_PROTOCOL* pEfiShellProtocol;
extern EFI_SYSTEM_TABLE* _cdegST;

EFI_TEXT_CLEAR_SCREEN   pConIOClr;
EFI_TEXT_STRING         pConIOPutStr;
EFI_ALLOCATE_POOL       pAllocPool;
EFI_IMAGE_START         pStartImage;

static EFI_STATUS EFIAPI myConIOClr(IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This) {

    return EFI_SUCCESS;
}


static enum STATE {
    AWAITING_UEFISHELL1,/*   checked: L"UEFI Interactive Shell v"           */
    AWAITING_UEFISHELL2,/*notchecked: L"UDK2018..."                         */
    AWAITING_UEFISHELL3,/*notchecked: L"UEFI v2."                           */
    AWAITING_MAPPINGTBL,/*   checked: L"Mapping tabl"                       */
    AWAITING_ALIAS0,    /*   checked: L"Alias(s)"                           */
    AWAITING_ALIAS1,    /*notchecked: L"HD0b0" / L"BLK0:" + L"PciRoot..."   */
    AWAITING_DRIVENAME0,/*   checked: L"     FS" / L"     BLK"              */
    STOP_WAITING,
}state;

static EFI_STATUS EFIAPI myConIOPutStr(IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, IN CHAR16* String) {
    EFI_STATUS Status = EFI_SUCCESS;
    static wchar_t wcsSHELL[] = { L"UEFI Interactive Shell v" };
    static wchar_t wcsMAP[] = { L"Mapping table" };
    static wchar_t wcsALIAS[] = { L"Alias(s)" };
    static wchar_t wcsBLK[] = { 0x20,0x20,0x20,0x20,0x20,0x42,0x4C,0x4B/*L"BLK"*/,0 };
    static wchar_t wcsBLK2[] = { 0x20,0x20,0x20,0x20,0x42,0x4C,0x4B/*L"BLK"*/,0 };
    static wchar_t wcsFS[] = { 0x20,0x20,0x20,0x20,0x20,0x20,0x46,0x53/*L"FS"*/,0 };
    static wchar_t wcsFS2[] = { 0x20,0x20,0x20,0x20,0x20,0x46,0x53/*L"FS"*/,0 };

    switch (state) {
    case AWAITING_UEFISHELL1:
        if (0 == wcsncmp(wcsSHELL, String, ELC(wcsSHELL) - 1))
            state = AWAITING_UEFISHELL2;
        else
            state = STOP_WAITING;
        break;
    case AWAITING_UEFISHELL2:
        state = AWAITING_UEFISHELL3;
        break;
    case AWAITING_UEFISHELL3:
        state = AWAITING_MAPPINGTBL;
        break;
    case AWAITING_MAPPINGTBL:
        if (0 == wcsncmp(wcsMAP, String, ELC(wcsMAP) - 1))
            state = AWAITING_ALIAS0;
        else
            state = STOP_WAITING;
        break;
    case AWAITING_ALIAS0:
        if (0 == wcsncmp(wcsALIAS, String, ELC(wcsALIAS) - 1))
            state = AWAITING_ALIAS1;
        break;
    case AWAITING_ALIAS1:
        state = AWAITING_DRIVENAME0;
        break;
    case AWAITING_DRIVENAME0:
        if (
            0 == wcsncmp(wcsBLK, String, ELC(wcsBLK) - 1) || \
            0 == wcsncmp(wcsBLK2, String, ELC(wcsBLK2) - 1) || \
            0 == wcsncmp(wcsFS, String, ELC(wcsFS) - 1) || \
            0 == wcsncmp(wcsFS2, String, ELC(wcsFS2) - 1))
            state = AWAITING_ALIAS0;
        else
            state = STOP_WAITING;
        break;
    }

    if (STOP_WAITING == state) {
        Status = pConIOPutStr(This, String);
    }

    return Status;
}

/** _osifCmdExec() - run command on system shell

Synopsis
    #include <CdeServices.h>
    int _osifUefiShellCmdExec(CDE_APP_IF* pCdeAppIf, char* szCommand);
Description
    Run command on system shell
Parameters
    CDE_APP_IF* pCdeAppIf   - application interface
    char* szCommand         - command to run
Returns
    return value of the command
**/
int _osifUefiShellCmdExec(CDE_APP_IF* pCdeAppIf, char* szCommand) {
    EFI_STATUS nRetStatus = 0;
    EFI_STATUS Status = 0;
    static wchar_t wcsCommand[CDE_SLASHCEXTENDETCOMMAND_LEN];
    size_t i;
    size_t len = strlen(szCommand);

    do {

        if (CDE_SLASHCEXTENDETCOMMAND_LEN < 1 + len) {

        }

        // ----- convert from char to wchar string

        for (i = 0; i < len + 1; i++)
            wcsCommand[i] = (0xFF) & (wchar_t)szCommand[i];

        //CDEMOFINE((MFNINF(1) "wcsCommand->\"%S\", &pCdeAppIf->DriverParm.BsDriverParm.ImageHandle -> %p, pCdeAppIf->DriverParm.BsDriverParm.ImageHandle->%X\n",&wcsCommand[0],&pCdeAppIf->DriverParm.BsDriverParm.ImageHandle,pCdeAppIf->DriverParm.BsDriverParm.ImageHandle));
        if (1) {

            pConIOClr = _cdegST->ConOut->ClearScreen;
            pConIOPutStr = _cdegST->ConOut->OutputString;

            _cdegST->ConOut->ClearScreen = myConIOClr;
            _cdegST->ConOut->OutputString = myConIOPutStr;

            state = AWAITING_UEFISHELL1;
        }

        Status = pEfiShellProtocol->Execute(&pCdeAppIf->DriverParm.BsDriverParm.ImageHandle, wcsCommand, NULL, &nRetStatus);

        if (1) {

            _cdegST->ConOut->ClearScreen = pConIOClr;
            _cdegST->ConOut->OutputString = pConIOPutStr;
        }

    } while (0);

    return (int)nRetStatus;
}