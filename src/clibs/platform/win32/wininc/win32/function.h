/*
   Functions.h

   Declarations for all the Windows32 API Functions

   Copyright (C) 1996 Free Software Foundation, Inc.

   Author: Scott Christley <scottc@net-community.com>

   This file is part of the Windows32 API Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   If you are interested in a warranty or support for this source code,
   contact Scott Christley <scottc@net-community.com> for more information.
   
   You should have received a copy of the GNU Library General Public
   License along with this library; see the file COPYING.LIB.
   If not, write to the Free Software Foundation,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   -----------
   DAL 2003 - this file modified extensively for my compiler.  New
   definitions added as well.

*/

#ifndef _GNU_H_WINDOWS32_FUNCTIONS
#define _GNU_H_WINDOWS32_FUNCTIONS

/* Define the approprate declaration based upon UNICODE or ASCII */

/* UNICODE */
#ifdef UNICODE

#    define RegConnectRegistry RegConnectRegistryW
#    define RegCreateKey RegCreateKeyW
#    define RegCreateKeyEx RegCreateKeyExW
#    define RegDeleteKey RegDeleteKeyW
#    define RegDeleteValue RegDeleteValueW
#    define RegEnumKey RegEnumKeyW
#    define RegEnumKeyEx RegEnumKeyExW
#    define RegEnumValue RegEnumValueW
#    define RegLoadKey RegLoadKeyW
#    define RegOpenKey RegOpenKeyW
#    define RegOpenKeyEx RegOpenKeyExW
#    define RegQueryInfoKey RegQueryInfoKeyW
#    define RegQueryValue RegQueryValueW
#    define RegQueryMultipleValues RegQueryMultipleValuesW
#    define RegQueryValueEx RegQueryValueExW
#    define RegReplaceKey RegReplaceKeyW
#    define RegRestoreKey RegRestoreKeyW
#    define RegSaveKey RegSaveKeyW
#    define RegSetValue RegSetValueW
#    define RegSetValueEx RegSetValueExW
#    define AbortSystemShutdown AbortSystemShutdownW
#    define InitiateSystemShutdown InitiateSystemShutdownW
#    define RegUnLoadKey RegUnLoadKeyW
#    define SetProp SetPropW
#    define GetProp GetPropW
#    define RemoveProp RemovePropW
#    define EnumPropsEx EnumPropsExW
#    define EnumProps EnumPropsW
#    define SetWindowText SetWindowTextW
#    define GetWindowText GetWindowTextW
#    define GetWindowTextLength GetWindowTextLengthW
#    define MessageBox MessageBoxW
#    define MessageBoxEx MessageBoxExW
#    define MessageBoxIndirect MessageBoxIndirectW
#    define GetWindowLong GetWindowLongW
#    define SetWindowLong SetWindowLongW
#    define GetClassLong GetClassLongW
#    define SetClassLong SetClassLongW
#    define FindWindow FindWindowW
#    define FindWindowEx FindWindowExW
#    define GetClassName GetClassNameW
#    define SetWindowsHook SetWindowsHookW
#    define SetWindowsHookEx SetWindowsHookExW
#    define LoadBitmap LoadBitmapW
#    define LoadCursor LoadCursorW
#    define LoadCursorFromFile LoadCursorFromFileW
#    define LoadIcon LoadIconW
#    define LoadImage LoadImageW
#    define LoadString LoadStringW
#    define IsDialogMessage IsDialogMessageW
#    define DlgDirList DlgDirListW
#    define DlgDirSelectEx DlgDirSelectExW
#    define DlgDirListComboBox DlgDirListComboBoxW
#    define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#    define DefFrameProc DefFrameProcW
#    define DefMDIChildProc DefMDIChildProcW
#    define CreateMDIWindow CreateMDIWindowW
#    define WinHelp WinHelpW
#    define ChangeDisplaySettings ChangeDisplaySettingsW
#    define EnumDisplaySettings EnumDisplaySettingsW
#    define SystemParametersInfo SystemParametersInfoW
#    define AddFontResource AddFontResourceW
#    define AddFontResourceEx AddFontResourceExW
#    define CopyMetaFile CopyMetaFileW
#    define CreateDC CreateDCW
#    define CreateFontIndirect CreateFontIndirectW
#    define CreateFont CreateFontW
#    define CreateIC CreateICW
#    define CreateMetaFile CreateMetaFileW
#    define CreateScalableFontResource CreateScalableFontResourceW
#    define DeviceCapabilities DeviceCapabilitiesW
#    define EnumFontFamiliesEx EnumFontFamiliesExW
#    define EnumFontFamilies EnumFontFamiliesW
#    define EnumFonts EnumFontsW
#    define GetCharWidth GetCharWidthW
#    define GetCharWidth32 GetCharWidth32W
#    define GetCharWidthFloat GetCharWidthFloatW
#    define GetCharABCWidths GetCharABCWidthsW
#    define GetCharABCWidthsFloat GetCharABCWidthsFloatW
#    define GetGlyphOutline GetGlyphOutlineW
#    define GetMetaFile GetMetaFileW
#    define GetOutlineTextMetrics GetOutlineTextMetricsW
#    define GetTextExtentPoint GetTextExtentPointW
#    define GetTextExtentPoint32 GetTextExtentPoint32W
#    define GetTextExtentExPoint GetTextExtentExPointW
#    define GetCharacterPlacement GetCharacterPlacementW
#    define ResetDC ResetDCW
#    define RemoveFontResource RemoveFontResourceW
#    define RemoveFontResourceEx RemoveFontResourceExW
#    define CopyEnhMetaFile CopyEnhMetaFileW
#    define CreateEnhMetaFile CreateEnhMetaFileW
#    define GetEnhMetaFile GetEnhMetaFileW
#    define GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#    define GetTextMetrics GetTextMetricsW
#    define StartDoc StartDocW
#    define GetObject GetObjectW
#    define TextOut TextOutW
#    define ExtTextOut ExtTextOutW
#    define PolyTextOut PolyTextOutW
#    define GetTextFace GetTextFaceW
#    define GetKerningPairs GetKerningPairsW
#    define GetLogColorSpace GetLogColorSpaceW
#    define CreateColorSpace CreateColorSpaceW
#    define GetICMProfile GetICMProfileW
#    define SetICMProfile SetICMProfileW
#    define UpdateICMRegKey UpdateICMRegKeyW
#    define EnumICMProfiles EnumICMProfilesW
#    define CreatePropertySheetPage CreatePropertySheetPageW
#    define PropertySheet PropertySheetW
#    define ImageList_LoadImage ImageList_LoadImageW
#    define CreateStatusWindow CreateStatusWindowW
#    define DrawStatusText DrawStatusTextW
#    define DefWindowProc DefWindowProcW
#    define CallWindowProc CallWindowProcW
#    define RegisterClass RegisterClassW
#    define UnregisterClass UnregisterClassW
#    define GetClassInfo GetClassInfoW
#    define RegisterClassEx RegisterClassExW
#    define GetClassInfoEx GetClassInfoExW
#    define CreateWindowEx CreateWindowExW
#    define CreateWindow CreateWindowW
#    define CreateDialogParam CreateDialogParamW
#    define CreateDialogIndirectParam CreateDialogIndirectParamW
#    define CreateDialog CreateDialogW
#    define CreateDialogIndirect CreateDialogIndirectW
#    define DialogBoxParam DialogBoxParamW
#    define DialogBoxIndirectParam DialogBoxIndirectParamW
#    define DialogBox DialogBoxW
#    define DialogBoxIndirect DialogBoxIndirectW
#    define RegisterClipboardFormat RegisterClipboardFormatW
#    define SetDlgItemText SetDlgItemTextW
#    define GetDlgItemText GetDlgItemTextW
#    define SendDlgItemMessage SendDlgItemMessageW
#    define DefDlgProc DefDlgProcW
#    define CallMsgFilter CallMsgFilterW
#    define GetClipboardFormatName GetClipboardFormatNameW
#    define CharToOem CharToOemW
#    define OemToChar OemToCharW
#    define CharToOemBuff CharToOemBuffW
#    define OemToCharBuff OemToCharBuffW
#    define CharUpper CharUpperW
#    define CharUpperBuff CharUpperBuffW
#    define CharLower CharLowerW
#    define CharLowerBuff CharLowerBuffW
#    define CharNext CharNextW
#    define CharPrev CharPrevW
#    define IsCharAlpha IsCharAlphaW
#    define IsCharAlphaNumeric IsCharAlphaNumericW
#    define IsCharUpper IsCharUpperW
#    define IsCharLower IsCharLowerW
#    define GetKeyNameText GetKeyNameTextW
#    define VkKeyScan VkKeyScanW
#    define VkKeyScanEx VkKeyScanExW
#    define MapVirtualKey MapVirtualKeyW
#    define MapVirtualKeyEx MapVirtualKeyExW
#    define LoadAccelerators LoadAcceleratorsW
#    define CreateAcceleratorTable CreateAcceleratorTableW
#    define CopyAcceleratorTable CopyAcceleratorTableW
#    define TranslateAccelerator TranslateAcceleratorW
#    define LoadMenu LoadMenuW
#    define LoadMenuIndirect LoadMenuIndirectW
#    define ChangeMenu ChangeMenuW
#    define GetMenuString GetMenuStringW
#    define InsertMenu InsertMenuW
#    define AppendMenu AppendMenuW
#    define ModifyMenu ModifyMenuW
#    define InsertMenuItem InsertMenuItemW
#    define GetMenuItemInfo GetMenuItemInfoW
#    define SetMenuItemInfo SetMenuItemInfoW
#    define DrawText DrawTextW
#    define DrawTextEx DrawTextExW
#    define GrayString GrayStringW
#    define DrawState DrawStateW
#    define TabbedTextOut TabbedTextOutW
#    define GetTabbedTextExtent GetTabbedTextExtentW
#    define GetVersionEx GetVersionExW
#    define wvsprintf wvsprintfW
#    define wsprintf wsprintfW
#    define LoadKeyboardLayout LoadKeyboardLayoutW
#    define GetKeyboardLayoutName GetKeyboardLayoutNameW
#    define CreateDesktop CreateDesktopW
#    define OpenDesktop OpenDesktopW
#    define EnumDesktops EnumDesktopsW
#    define CreateWindowStation CreateWindowStationW
#    define OpenWindowStation OpenWindowStationW
#    define EnumWindowStations EnumWindowStationsW
#    define IsBadStringPtr IsBadStringPtrW
#    define LookupAccountSid LookupAccountSidW
#    define LookupAccountName LookupAccountNameW
#    define LookupPrivilegeValue LookupPrivilegeValueW
#    define LookupPrivilegeName LookupPrivilegeNameW
#    define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#    define BuildCommDCB BuildCommDCBW
#    define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#    define CommConfigDialog CommConfigDialogW
#    define GetDefaultCommConfig GetDefaultCommConfigW
#    define SetDefaultCommConfig SetDefaultCommConfigW
#    define GetComputerName GetComputerNameW
#    define SetComputerName SetComputerNameW
#    define GetUserName GetUserNameW
#    define CreateMailslot CreateMailslotW
#    define FormatMessage FormatMessageW
#    define GetEnvironmentStrings GetEnvironmentStringsW
#    define FreeEnvironmentStrings FreeEnvironmentStringsW
#    define lstrcmp lstrcmpW
#    define lstrcmpi lstrcmpiW
#    define lstrcpyn lstrcpynW
#    define lstrcpy lstrcpyW
#    define lstrcat lstrcatW
#    define lstrlen lstrlenW
#    define GetBinaryType GetBinaryTypeW
#    define GetShortPathName GetShortPathNameW
#    define SetFileSecurity SetFileSecurityW
#    define GetFileSecurity GetFileSecurityW
#    define FindFirstChangeNotification FindFirstChangeNotificationW
#    define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#    define ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#    define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#    define ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#    define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#    define OpenEventLog OpenEventLogW
#    define RegisterEventSource RegisterEventSourceW
#    define OpenBackupEventLog OpenBackupEventLogW
#    define ReadEventLog ReadEventLogW
#    define ReportEvent ReportEventW
#    define CreateProcess CreateProcessW
#    define FatalAppExit FatalAppExitW
#    define GetStartupInfo GetStartupInfoW
#    define GetEnvironmentVariable GetEnvironmentVariableW
#    define GetCommandLine GetCommandLineW
#    define SetEnvironmentVariable SetEnvironmentVariableW
#    define ExpandEnvironmentStrings ExpandEnvironmentStringsW
#    define OutputDebugString OutputDebugStringW
#    define FindResource FindResourceW
#    define FindResourceEx FindResourceExW
#    define EnumResourceTypes EnumResourceTypesW
#    define EnumResourceNames EnumResourceNamesW
#    define EnumResourceLanguages EnumResourceLanguagesW
#    define BeginUpdateResource BeginUpdateResourceW
#    define UpdateResource UpdateResourceW
#    define EndUpdateResource EndUpdateResourceW
#    define GlobalAddAtom GlobalAddAtomW
#    define GlobalFindAtom GlobalFindAtomW
#    define GlobalGetAtomName GlobalGetAtomNameW
#    define AddAtom AddAtomW
#    define FindAtom FindAtomW
#    define GetAtomName GetAtomNameW
#    define GetProfileInt GetProfileIntW
#    define GetProfileString GetProfileStringW
#    define WriteProfileString WriteProfileStringW
#    define GetProfileSection GetProfileSectionW
#    define WriteProfileSection WriteProfileSectionW
#    define GetPrivateProfileInt GetPrivateProfileIntW
#    define GetPrivateProfileString GetPrivateProfileStringW
#    define WritePrivateProfileString WritePrivateProfileStringW
#    define GetPrivateProfileSection GetPrivateProfileSectionW
#    define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
#    define WritePrivateProfileSection WritePrivateProfileSectionW
#    define GetDriveType GetDriveTypeW
#    define GetSystemDirectory GetSystemDirectoryW
#    define GetTempPath GetTempPathW
#    define GetTempFileName GetTempFileNameW
#    define GetWindowsDirectory GetWindowsDirectoryW
#    define SetCurrentDirectory SetCurrentDirectoryW
#    define GetCurrentDirectory GetCurrentDirectoryW
#    define GetDiskFreeSpace GetDiskFreeSpaceW
#    define CreateDirectory CreateDirectoryW
#    define CreateDirectoryEx CreateDirectoryExW
#    define RemoveDirectory RemoveDirectoryW
#    define GetFullPathName GetFullPathNameW
#    define DefineDosDevice DefineDosDeviceW
#    define QueryDosDevice QueryDosDeviceW
#    define CreateFile CreateFileW
#    define SetFileAttributes SetFileAttributesW
#    define GetFileAttributes GetFileAttributesW
#    define GetCompressedFileSize GetCompressedFileSizeW
#    define DeleteFile DeleteFileW
#    define FindFirstFile FindFirstFileW
#    define FindNextFile FindNextFileW
#    define SearchPath SearchPathW
#    define CopyFile CopyFileW
#    define MoveFile MoveFileW
#    define MoveFileEx MoveFileExW
#    define CreateNamedPipe CreateNamedPipeW
#    define GetNamedPipeHandleState GetNamedPipeHandleStateW
#    define CallNamedPipe CallNamedPipeW
#    define WaitNamedPipe WaitNamedPipeW
#    define SetVolumeLabel SetVolumeLabelW
#    define GetVolumeInformation GetVolumeInformationW
#    define ClearEventLog ClearEventLogW
#    define BackupEventLog BackupEventLogW
#    define CreateMutex CreateMutexW
#    define OpenMutex OpenMutexW
#    define CreateEvent CreateEventW
#    define OpenEvent OpenEventW
#    define CreateSemaphore CreateSemaphoreW
#    define OpenSemaphore OpenSemaphoreW
#    define CreateFileMapping CreateFileMappingW
#    define OpenFileMapping OpenFileMappingW
#    define GetLogicalDriveStrings GetLogicalDriveStringsW
#    define LoadLibrary LoadLibraryW
#    define LoadLibraryEx LoadLibraryExW
#    define GetModuleFileName GetModuleFileNameW
#    define GetModuleHandle GetModuleHandleW
#    define GetUserObjectInformation GetUserObjectInformationW
#    define SetUserObjectInformation SetUserObjectInformationW
#    define RegisterWindowMessage RegisterWindowMessageW
#    define GetMessage GetMessageW
#    define DispatchMessage DispatchMessageW
#    define PeekMessage PeekMessageW
#    define SendMessage SendMessageW
#    define SendMessageTimeout SendMessageTimeoutW
#    define SendNotifyMessage SendNotifyMessageW
#    define SendMessageCallback SendMessageCallbackW
#    define PostMessage PostMessageW
#    define PostThreadMessage PostThreadMessageW
#    define VerFindFile VerFindFileW
#    define VerInstallFile VerInstallFileW
#    define GetFileVersionInfoSize GetFileVersionInfoSizeW
#    define GetFileVersionInfo GetFileVersionInfoW
#    define VerLanguageName VerLanguageNameW
#    define VerQueryValue VerQueryValueW
#    define CompareString CompareStringW
#    define LCMapString LCMapStringW
#    define GetLocaleInfo GetLocaleInfoW
#    define SetLocaleInfo SetLocaleInfoW
#    define GetTimeFormat GetTimeFormatW
#    define GetDateFormat GetDateFormatW
#    define GetNumberFormat GetNumberFormatW
#    define GetCurrencyFormat GetCurrencyFormatW
#    define EnumCalendarInfo EnumCalendarInfoW
#    define EnumTimeFormats EnumTimeFormatsW
#    define FoldString FoldStringW
#    define EnumSystemCodePages EnumSystemCodePagesW
#    define EnumSystemLocales EnumSystemLocalesW
#    define GetStringTypeEx GetStringTypeExW
#    define EnumDateFormats EnumDateFormatsW
#    define GetConsoleTitle GetConsoleTitleW
#    define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferW
#    define SetConsoleTitle SetConsoleTitleW
#    define ReadConsole ReadConsoleW
#    define WriteConsole WriteConsoleW
#    define PeekConsoleInput PeekConsoleInputW
#    define ReadConsoleInput ReadConsoleInputW
#    define WriteConsoleInput WriteConsoleInputW
#    define ReadConsoleOutput ReadConsoleOutputW
#    define WriteConsoleOutput WriteConsoleOutputW
#    define ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#    define WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#    define FillConsoleOutputCharacter FillConsoleOutputCharacterW
#    define WNetGetProviderName WNetGetProviderNameW
#    define WNetGetNetworkInformation WNetGetNetworkInformationW
#    define WNetGetLastError WNetGetLastErrorW
#    define MultinetGetConnectionPerformance MultinetGetConnectionPerformanceW
#    define WNetConnectionDialog1 WNetConnectionDialog1W
#    define WNetDisconnectDialog1 WNetDisconnectDialog1W
#    define WNetOpenEnum WNetOpenEnumW
#    define WNetEnumResource WNetEnumResourceW
#    define WNetGetUniversalName WNetGetUniversalNameW
#    define WNetGetUser WNetGetUserW
#    define WNetAddConnection WNetAddConnectionW
#    define WNetAddConnection2 WNetAddConnection2W
#    define WNetAddConnection3 WNetAddConnection3W
#    define WNetCancelConnection WNetCancelConnectionW
#    define WNetCancelConnection2 WNetCancelConnection2W
#    define WNetGetConnection WNetGetConnectionW
#    define WNetUseConnection WNetUseConnectionW
#    define WNetSetConnection WNetSetConnectionW
#    define CreateService CreateServiceW
#    define ChangeServiceConfig ChangeServiceConfigW
#    define EnumDependentServices EnumDependentServicesW
#    define EnumServicesStatus EnumServicesStatusW
#    define GetServiceKeyName GetServiceKeyNameW
#    define GetServiceDisplayName GetServiceDisplayNameW
#    define OpenSCManager OpenSCManagerW
#    define OpenService OpenServiceW
#    define QueryServiceConfig QueryServiceConfigW
#    define QueryServiceLockStatus QueryServiceLockStatusW
#    define RegisterServiceCtrlHandler RegisterServiceCtrlHandlerW
#    define StartServiceCtrlDispatcher StartServiceCtrlDispatcherW
#    define StartService StartServiceW
#    define DragQueryFile DragQueryFileW
#    define ExtractAssociatedIcon ExtractAssociatedIconW
#    define DdeCreateStringHandle DdeCreateStringHandleW
#    define DdeInitialize DdeInitializeW
#    define DdeQueryString DdeQueryStringW
#    define LogonUser LogonUserW
#    define CreateProcessAsUser CreateProcessAsUserW
#    define PlaySound PlaySoundW
#    define wglUseFontBitmaps wglUseFontBitmapsW
#    define wglUseFontOutlines wglUseFontOutlinesW
#    define GetCPInfoEx GetCPInfoExW
#    define GetFileAttributesEx GetFileAttributesExW

#    define Process32First Process32FirstW
#    define Process32Next Process32NextW
#    define PROCESSENTRY32 PROCESSENTRY32W
#    define PPROCESSENTRY32 PPROCESSENTRY32W
#    define LPPROCESSENTRY32 LPPROCESSENTRY32W

/* ASCII */
#else

#    define RegConnectRegistry RegConnectRegistryA
#    define RegCreateKey RegCreateKeyA
#    define RegCreateKeyEx RegCreateKeyExA
#    define RegDeleteKey RegDeleteKeyA
#    define RegDeleteValue RegDeleteValueA
#    define RegEnumKey RegEnumKeyA
#    define RegEnumKeyEx RegEnumKeyExA
#    define RegEnumValue RegEnumValueA
#    define RegLoadKey RegLoadKeyA
#    define RegOpenKey RegOpenKeyA
#    define RegOpenKeyEx RegOpenKeyExA
#    define RegQueryInfoKey RegQueryInfoKeyA
#    define RegQueryValue RegQueryValueA
#    define RegQueryMultipleValues RegQueryMultipleValuesA
#    define RegQueryValueEx RegQueryValueExA
#    define RegReplaceKey RegReplaceKeyA
#    define RegRestoreKey RegRestoreKeyA
#    define RegSaveKey RegSaveKeyA
#    define RegSetValue RegSetValueA
#    define RegSetValueEx RegSetValueExA
#    define AbortSystemShutdown AbortSystemShutdownA
#    define InitiateSystemShutdown InitiateSystemShutdownA
#    define RegUnLoadKey RegUnLoadKeyA
#    define LoadIcon LoadIconA
#    define LoadImage LoadImageA
#    define LoadString LoadStringA
#    define IsDialogMessage IsDialogMessageA
#    define DlgDirList DlgDirListA
#    define DlgDirSelectEx DlgDirSelectExA
#    define DlgDirListComboBox DlgDirListComboBoxA
#    define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#    define DefFrameProc DefFrameProcA
#    define DefMDIChildProc DefMDIChildProcA
#    define CreateMDIWindow CreateMDIWindowA
#    define WinHelp WinHelpA
#    define ChangeDisplaySettings ChangeDisplaySettingsA
#    define EnumDisplaySettings EnumDisplaySettingsA
#    define SystemParametersInfo SystemParametersInfoA
#    define GetWindowLong GetWindowLongA
#    define SetWindowLong SetWindowLongA
#    define GetClassLong GetClassLongA
#    define SetClassLong SetClassLongA
#    define FindWindow FindWindowA
#    define FindWindowEx FindWindowExA
#    define GetClassName GetClassNameA
#    define SetWindowsHook SetWindowsHookA
#    define SetWindowsHookEx SetWindowsHookExA
#    define LoadBitmap LoadBitmapA
#    define LoadCursor LoadCursorA
#    define LoadCursorFromFile LoadCursorFromFileA
#    define SetProp SetPropA
#    define GetProp GetPropA
#    define RemoveProp RemovePropA
#    define EnumPropsEx EnumPropsExA
#    define EnumProps EnumPropsA
#    define SetWindowText SetWindowTextA
#    define GetWindowText GetWindowTextA
#    define GetWindowTextLength GetWindowTextLengthA
#    define MessageBox MessageBoxA
#    define MessageBoxEx MessageBoxExA
#    define MessageBoxIndirect MessageBoxIndirectA
#    define AddFontResource AddFontResourceA
#    define AddFontResourceEx AddFontResourceExA
#    define CopyMetaFile CopyMetaFileA
#    define CreateDC CreateDCA
#    define CreateFontIndirect CreateFontIndirectA
#    define CreateFont CreateFontA
#    define CreateIC CreateICA
#    define CreateMetaFile CreateMetaFileA
#    define CreateScalableFontResource CreateScalableFontResourceA
#    define DeviceCapabilities DeviceCapabilitiesA
#    define EnumFontFamiliesEx EnumFontFamiliesExA
#    define EnumFontFamilies EnumFontFamiliesA
#    define EnumFonts EnumFontsA
#    define GetCharWidth GetCharWidthA
#    define GetCharWidth32 GetCharWidth32A
#    define GetCharWidthFloat GetCharWidthFloatA
#    define GetCharABCWidths GetCharABCWidthsA
#    define GetCharABCWidthsFloat GetCharABCWidthsFloatA
#    define GetGlyphOutline GetGlyphOutlineA
#    define GetMetaFile GetMetaFileA
#    define GetOutlineTextMetrics GetOutlineTextMetricsA
#    define GetTextExtentPoint GetTextExtentPointA
#    define GetTextExtentPoint32 GetTextExtentPoint32A
#    define GetTextExtentExPoint GetTextExtentExPointA
#    define GetCharacterPlacement GetCharacterPlacementA
#    define ResetDC ResetDCA
#    define RemoveFontResource RemoveFontResourceA
#    define RemoveFontResourceEx RemoveFontResourceExA
#    define CopyEnhMetaFile CopyEnhMetaFileA
#    define CreateEnhMetaFile CreateEnhMetaFileA
#    define GetEnhMetaFile GetEnhMetaFileA
#    define GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#    define GetTextMetrics GetTextMetricsA
#    define StartDoc StartDocA
#    define GetObject GetObjectA
#    define TextOut TextOutA
#    define ExtTextOut ExtTextOutA
#    define PolyTextOut PolyTextOutA
#    define GetTextFace GetTextFaceA
#    define GetKerningPairs GetKerningPairsA
#    define GetLogColorSpace GetLogColorSpaceA
#    define CreateColorSpace CreateColorSpaceA
#    define GetICMProfile GetICMProfileA
#    define SetICMProfile SetICMProfileA
#    define UpdateICMRegKey UpdateICMRegKeyA
#    define EnumICMProfiles EnumICMProfilesA
#    define CreatePropertySheetPage CreatePropertySheetPageA
#    define PropertySheet PropertySheetA
#    define ImageList_LoadImage ImageList_LoadImageA
#    define CreateStatusWindow CreateStatusWindowA
#    define DrawStatusText DrawStatusTextA
#    define DefWindowProc DefWindowProcA
#    define CallWindowProc CallWindowProcA
#    define RegisterClass RegisterClassA
#    define UnregisterClass UnregisterClassA
#    define GetClassInfo GetClassInfoA
#    define RegisterClassEx RegisterClassExA
#    define GetClassInfoEx GetClassInfoExA
#    define CreateWindowEx CreateWindowExA
#    define CreateWindow CreateWindowA
#    define CreateDialogParam CreateDialogParamA
#    define CreateDialogIndirectParam CreateDialogIndirectParamA
#    define CreateDialog CreateDialogA
#    define CreateDialogIndirect CreateDialogIndirectA
#    define DialogBoxParam DialogBoxParamA
#    define DialogBoxIndirectParam DialogBoxIndirectParamA
#    define DialogBox DialogBoxA
#    define DialogBoxIndirect DialogBoxIndirectA
#    define RegisterClipboardFormat RegisterClipboardFormatA
#    define SetDlgItemText SetDlgItemTextA
#    define GetDlgItemText GetDlgItemTextA
#    define SendDlgItemMessage SendDlgItemMessageA
#    define DefDlgProc DefDlgProcA
#    define CallMsgFilter CallMsgFilterA
#    define GetClipboardFormatName GetClipboardFormatNameA
#    define CharToOem CharToOemA
#    define OemToChar OemToCharA
#    define CharToOemBuff CharToOemBuffA
#    define OemToCharBuff OemToCharBuffA
#    define CharUpper CharUpperA
#    define CharUpperBuff CharUpperBuffA
#    define CharLower CharLowerA
#    define CharLowerBuff CharLowerBuffA
#    define CharNext CharNextA
#    define CharPrev CharPrevA
#    define IsCharAlpha IsCharAlphaA
#    define IsCharAlphaNumeric IsCharAlphaNumericA
#    define IsCharUpper IsCharUpperA
#    define IsCharLower IsCharLowerA
#    define GetKeyNameText GetKeyNameTextA
#    define VkKeyScan VkKeyScanA
#    define VkKeyScanEx VkKeyScanExA
#    define MapVirtualKey MapVirtualKeyA
#    define MapVirtualKeyEx MapVirtualKeyExA
#    define LoadAccelerators LoadAcceleratorsA
#    define CreateAcceleratorTable CreateAcceleratorTableA
#    define CopyAcceleratorTable CopyAcceleratorTableA
#    define TranslateAccelerator TranslateAcceleratorA
#    define LoadMenu LoadMenuA
#    define LoadMenuIndirect LoadMenuIndirectA
#    define ChangeMenu ChangeMenuA
#    define GetMenuString GetMenuStringA
#    define InsertMenu InsertMenuA
#    define AppendMenu AppendMenuA
#    define ModifyMenu ModifyMenuA
#    define InsertMenuItem InsertMenuItemA
#    define GetMenuItemInfo GetMenuItemInfoA
#    define SetMenuItemInfo SetMenuItemInfoA
#    define DrawText DrawTextA
#    define DrawTextEx DrawTextExA
#    define GrayString GrayStringA
#    define DrawState DrawStateA
#    define TabbedTextOut TabbedTextOutA
#    define GetTabbedTextExtent GetTabbedTextExtentA
#    define GetVersionEx GetVersionExA
#    define wvsprintf wvsprintfA
#    define wsprintf wsprintfA
#    define LoadKeyboardLayout LoadKeyboardLayoutA
#    define GetKeyboardLayoutName GetKeyboardLayoutNameA
#    define CreateDesktop CreateDesktopA
#    define OpenDesktop OpenDesktopA
#    define EnumDesktops EnumDesktopsA
#    define CreateWindowStation CreateWindowStationA
#    define OpenWindowStation OpenWindowStationA
#    define EnumWindowStations EnumWindowStationsA
#    define IsBadStringPtr IsBadStringPtrA
#    define LookupAccountSid LookupAccountSidA
#    define LookupAccountName LookupAccountNameA
#    define LookupPrivilegeValue LookupPrivilegeValueA
#    define LookupPrivilegeName LookupPrivilegeNameA
#    define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#    define BuildCommDCB BuildCommDCBA
#    define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#    define CommConfigDialog CommConfigDialogA
#    define GetDefaultCommConfig GetDefaultCommConfigA
#    define SetDefaultCommConfig SetDefaultCommConfigA
#    define GetComputerName GetComputerNameA
#    define SetComputerName SetComputerNameA
#    define GetUserName GetUserNameA
#    define CreateMailslot CreateMailslotA
#    define FormatMessage FormatMessageA
#    define GetEnvironmentStrings GetEnvironmentStringsA
#    define FreeEnvironmentStrings FreeEnvironmentStringsA
#    define lstrcmp lstrcmpA
#    define lstrcmpi lstrcmpiA
#    define lstrcpyn lstrcpynA
#    define lstrcpy lstrcpyA
#    define lstrcat lstrcatA
#    define lstrlen lstrlenA
#    define GetBinaryType GetBinaryTypeA
#    define GetShortPathName GetShortPathNameA
#    define SetFileSecurity SetFileSecurityA
#    define GetFileSecurity GetFileSecurityA
#    define FindFirstChangeNotification FindFirstChangeNotificationA
#    define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#    define ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#    define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#    define ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#    define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#    define OpenEventLog OpenEventLogA
#    define RegisterEventSource RegisterEventSourceA
#    define OpenBackupEventLog OpenBackupEventLogA
#    define ReadEventLog ReadEventLogA
#    define ReportEvent ReportEventA
#    define CreateProcess CreateProcessA
#    define FatalAppExit FatalAppExitA
#    define GetStartupInfo GetStartupInfoA
#    define GetCommandLine GetCommandLineA
#    define GetEnvironmentVariable GetEnvironmentVariableA
#    define SetEnvironmentVariable SetEnvironmentVariableA
#    define ExpandEnvironmentStrings ExpandEnvironmentStringsA
#    define OutputDebugString OutputDebugStringA
#    define FindResource FindResourceA
#    define FindResourceEx FindResourceExA
#    define EnumResourceTypes EnumResourceTypesA
#    define EnumResourceNames EnumResourceNamesA
#    define EnumResourceLanguages EnumResourceLanguagesA
#    define BeginUpdateResource BeginUpdateResourceA
#    define UpdateResource UpdateResourceA
#    define EndUpdateResource EndUpdateResourceA
#    define GlobalAddAtom GlobalAddAtomA
#    define GlobalFindAtom GlobalFindAtomA
#    define GlobalGetAtomName GlobalGetAtomNameA
#    define AddAtom AddAtomA
#    define FindAtom FindAtomA
#    define GetProfileInt GetProfileIntA
#    define GetAtomName GetAtomNameA
#    define GetProfileString GetProfileStringA
#    define WriteProfileString WriteProfileStringA
#    define GetProfileSection GetProfileSectionA
#    define WriteProfileSection WriteProfileSectionA
#    define GetPrivateProfileInt GetPrivateProfileIntA
#    define GetPrivateProfileString GetPrivateProfileStringA
#    define WritePrivateProfileString WritePrivateProfileStringA
#    define GetPrivateProfileSection GetPrivateProfileSectionA
#    define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
#    define WritePrivateProfileSection WritePrivateProfileSectionA
#    define GetDriveType GetDriveTypeA
#    define GetSystemDirectory GetSystemDirectoryA
#    define GetTempPath GetTempPathA
#    define GetTempFileName GetTempFileNameA
#    define GetWindowsDirectory GetWindowsDirectoryA
#    define SetCurrentDirectory SetCurrentDirectoryA
#    define GetCurrentDirectory GetCurrentDirectoryA
#    define GetDiskFreeSpace GetDiskFreeSpaceA
#    define CreateDirectory CreateDirectoryA
#    define CreateDirectoryEx CreateDirectoryExA
#    define RemoveDirectory RemoveDirectoryA
#    define GetFullPathName GetFullPathNameA
#    define DefineDosDevice DefineDosDeviceA
#    define QueryDosDevice QueryDosDeviceA
#    define CreateFile CreateFileA
#    define SetFileAttributes SetFileAttributesA
#    define GetFileAttributes GetFileAttributesA
#    define GetCompressedFileSize GetCompressedFileSizeA
#    define DeleteFile DeleteFileA
#    define FindFirstFile FindFirstFileA
#    define FindNextFile FindNextFileA
#    define SearchPath SearchPathA
#    define CopyFile CopyFileA
#    define MoveFile MoveFileA
#    define MoveFileEx MoveFileExA
#    define CreateNamedPipe CreateNamedPipeA
#    define GetNamedPipeHandleState GetNamedPipeHandleStateA
#    define CallNamedPipe CallNamedPipeA
#    define WaitNamedPipe WaitNamedPipeA
#    define SetVolumeLabel SetVolumeLabelA
#    define GetVolumeInformation GetVolumeInformationA
#    define ClearEventLog ClearEventLogA
#    define BackupEventLog BackupEventLogA
#    define CreateMutex CreateMutexA
#    define OpenMutex OpenMutexA
#    define CreateEvent CreateEventA
#    define OpenEvent OpenEventA
#    define CreateSemaphore CreateSemaphoreA
#    define OpenSemaphore OpenSemaphoreA
#    define CreateFileMapping CreateFileMappingA
#    define OpenFileMapping OpenFileMappingA
#    define GetLogicalDriveStrings GetLogicalDriveStringsA
#    define LoadLibrary LoadLibraryA
#    define LoadLibraryEx LoadLibraryExA
#    define GetModuleFileName GetModuleFileNameA
#    define GetModuleHandle GetModuleHandleA
#    define GetUserObjectInformation GetUserObjectInformationA
#    define SetUserObjectInformation SetUserObjectInformationA
#    define RegisterWindowMessage RegisterWindowMessageA
#    define GetMessage GetMessageA
#    define DispatchMessage DispatchMessageA
#    define PeekMessage PeekMessageA
#    define SendMessage SendMessageA
#    define SendMessageTimeout SendMessageTimeoutA
#    define SendNotifyMessage SendNotifyMessageA
#    define SendMessageCallback SendMessageCallbackA
#    define PostMessage PostMessageA
#    define PostThreadMessage PostThreadMessageA
#    define VerFindFile VerFindFileA
#    define VerInstallFile VerInstallFileA
#    define GetFileVersionInfoSize GetFileVersionInfoSizeA
#    define GetFileVersionInfo GetFileVersionInfoA
#    define VerLanguageName VerLanguageNameA
#    define VerQueryValue VerQueryValueA
#    define CompareString CompareStringA
#    define LCMapString LCMapStringA
#    define GetLocaleInfo GetLocaleInfoA
#    define SetLocaleInfo SetLocaleInfoA
#    define GetTimeFormat GetTimeFormatA
#    define GetDateFormat GetDateFormatA
#    define GetNumberFormat GetNumberFormatA
#    define GetCurrencyFormat GetCurrencyFormatA
#    define EnumCalendarInfo EnumCalendarInfoA
#    define EnumTimeFormats EnumTimeFormatsA
#    define FoldString FoldStringA
#    define EnumSystemCodePages EnumSystemCodePagesA
#    define EnumSystemLocales EnumSystemLocalesA
#    define GetStringTypeEx GetStringTypeExA
#    define EnumDateFormats EnumDateFormatsA
#    define GetConsoleTitle GetConsoleTitleA
#    define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferA
#    define SetConsoleTitle SetConsoleTitleA
#    define ReadConsole ReadConsoleA
#    define WriteConsole WriteConsoleA
#    define PeekConsoleInput PeekConsoleInputA
#    define ReadConsoleInput ReadConsoleInputA
#    define WriteConsoleInput WriteConsoleInputA
#    define ReadConsoleOutput ReadConsoleOutputA
#    define WriteConsoleOutput WriteConsoleOutputA
#    define ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#    define WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#    define FillConsoleOutputCharacter FillConsoleOutputCharacterA
#    define MultinetGetConnectionPerformance MultinetGetConnectionPerformanceA
#    define WNetGetLastError WNetGetLastErrorA
#    define WNetGetProviderName WNetGetProviderNameA
#    define WNetGetNetworkInformation WNetGetNetworkInformationA
#    define WNetConnectionDialog1 WNetConnectionDialog1A
#    define WNetDisconnectDialog1 WNetDisconnectDialog1A
#    define WNetOpenEnum WNetOpenEnumA
#    define WNetEnumResource WNetEnumResourceA
#    define WNetGetUniversalName WNetGetUniversalNameA
#    define WNetGetUser WNetGetUserA
#    define WNetAddConnection WNetAddConnectionA
#    define WNetAddConnection2 WNetAddConnection2A
#    define WNetAddConnection3 WNetAddConnection3A
#    define WNetCancelConnection WNetCancelConnectionA
#    define WNetCancelConnection2 WNetCancelConnection2A
#    define WNetGetConnection WNetGetConnectionA
#    define WNetUseConnection WNetUseConnectionA
#    define WNetSetConnection WNetSetConnectionA
#    define OpenService OpenServiceA
#    define QueryServiceConfig QueryServiceConfigA
#    define QueryServiceLockStatus QueryServiceLockStatusA
#    define RegisterServiceCtrlHandler RegisterServiceCtrlHandlerA
#    define StartServiceCtrlDispatcher StartServiceCtrlDispatcherA
#    define StartService StartServiceA
#    define ChangeServiceConfig ChangeServiceConfigA
#    define CreateService CreateServiceA
#    define EnumDependentServices EnumDependentServicesA
#    define EnumServicesStatus EnumServicesStatusA
#    define GetServiceKeyName GetServiceKeyNameA
#    define GetServiceDisplayName GetServiceDisplayNameA
#    define OpenSCManager OpenSCManagerA
#    define DragQueryFile DragQueryFileA
#    define ExtractAssociatedIcon ExtractAssociatedIconA
#    define DdeCreateStringHandle DdeCreateStringHandleA
#    define DdeInitialize DdeInitializeA
#    define DdeQueryString DdeQueryStringA
#    define LogonUser LogonUserA
#    define CreateProcessAsUser CreateProcessAsUserA
#    define PlaySound PlaySoundA
#    define wglUseFontBitmaps wglUseFontBitmapsA
#    define wglUseFontOutlines wglUseFontOutlinesA
#    define GetCPInfoEx GetCPInfoExA
#    define GetFileAttributesEx GetFileAttributesExA

#endif /* UNICODE and ASCII defines */

#include <win32/commonfu.h>

#ifndef UNICODE_ONLY
#    include <win32/unicodef.h>
#endif /* !UNICODE_ONLY */

#ifndef ANSI_ONLY
#    include <win32/asciifun.h>
#endif /* !ANSI_ONLY */

#endif /* _GNU_H_WINDOWS32_FUNCTIONS */
