//-----------------------------------------------------------------------------
//     Author : hiyohiyo
//       Mail : hiyohiyo@crystalmark.info
//        Web : http://openlibsys.org/
//    License : The modified BSD license
//
//                          Copyright 2007 OpenLibSys.org. All rights reserved.
//-----------------------------------------------------------------------------
// for WinRing0 1.3.x

#pragma once
#include <Windows.h>


//DWORD_PTR X64 is 64 bit, X86 is 32 bit

#define _PHYSICAL_MEMORY_SUPPORT

extern HANDLE gHandle;

extern BOOL gIsNT;
extern BOOL gIsCpuid;
extern BOOL gIsMsr;
extern BOOL gIsTsc;


extern DWORD gDriverType;

#ifdef __cplusplus    
extern "C" {
#endif

// get core num
DWORD WINAPI GetCoreNum();

//-----------------------------------------------------------------------------
// GetDriverVersion
// Device Driver Version, defined OLS_DRIVER_VERSION
// major version
// minor version
// revision
// release/build
//-----------------------------------------------------------------------------
DWORD WINAPI GetDriverVersion(PBYTE major, PBYTE minor, PBYTE revision, PBYTE release);

//-----------------------------------------------------------------------------
// GetDriverType 
// Device Driver Type, defined OLS_DRIVER_TYPE_****
//-----------------------------------------------------------------------------
DWORD WINAPI GetDriverType();


/******************************************************************************
**
** CPU
**
******************************************************************************/

//-----------------------------------------------------------------------------
// IsCpuid
// TRUE: support CPUID instruction, FALSE: not support CPUID instruction
//-----------------------------------------------------------------------------
BOOL WINAPI IsCpuid();

//-----------------------------------------------------------------------------
// IsMsr
// TRUE: support MSR(Model-Specific Register), FALSE: not support MSR
//-----------------------------------------------------------------------------
BOOL WINAPI IsMsr();

//-----------------------------------------------------------------------------
// IsTsc
// TRUE: support TSC(Time Stamp Counter), FALSE: not support TSC
//-----------------------------------------------------------------------------
BOOL WINAPI IsTsc();

//-----------------------------------------------------------------------------
// Rdmsr
// TRUE: success, FALSE: failure
// MSR index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI Rdmsr(DWORD index, PDWORD eax, PDWORD edx);

//-----------------------------------------------------------------------------
// RdmsrTx
// TRUE: success, FALSE: failure
// MSR index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL 
WINAPI RdmsrTx(DWORD index, PDWORD eax, PDWORD edx, DWORD_PTR threadAffinityMask);

//
// group is numanode
//
BOOL WINAPI RdmsrTxGroup(DWORD index, PDWORD eax, PDWORD edx, DWORD_PTR threadAffinityMask, WORD group);


//-----------------------------------------------------------------------------
// RdmsrPx
// TRUE: success, FALSE: failure
// MSR index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI RdmsrPx(DWORD index, PDWORD eax, PDWORD edx, DWORD_PTR processAffinityMask);

//-----------------------------------------------------------------------------
// Wrmsr
// TRUE: success, FALSE: failure
// MSR index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI Wrmsr(DWORD index, DWORD eax, DWORD edx);

//-----------------------------------------------------------------------------
// WrmsrTx
// TRUE: success, FALSE: failure
// MSR index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI WrmsrTx(DWORD index, DWORD eax,	DWORD edx, DWORD_PTR threadAffinityMask);

//
BOOL WINAPI WrmsrTxGroup(DWORD index, DWORD eax, DWORD edx, DWORD_PTR threadAffinityMask, WORD group);

//-----------------------------------------------------------------------------
// WrmsrPx
// TRUE: success, FALSE: failure
// MSR index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI WrmsrPx(DWORD index, DWORD eax, DWORD edx, DWORD_PTR processAffinityMask);

//-----------------------------------------------------------------------------
// Rdpmc
// TRUE: success, FALSE: failure
// PMC index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI Rdpmc(DWORD index, PDWORD eax, PDWORD edx);

//-----------------------------------------------------------------------------
// RdmsrTx
// TRUE: success, FALSE: failure
// PMC index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI RdpmcTx(DWORD index, PDWORD eax, PDWORD edx, DWORD_PTR threadAffinityMask);

//
BOOL WINAPI RdpmcTxGroup(DWORD index, PDWORD eax, PDWORD edx, DWORD_PTR threadAffinityMask, WORD group);

//-----------------------------------------------------------------------------
// RdmsrPx
// TRUE: success, FALSE: failure
// PMC index
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI RdpmcPx(DWORD index, PDWORD eax, PDWORD edx, DWORD_PTR processAffinityMask);

//-----------------------------------------------------------------------------
// Cpuid
// TRUE: success, FALSE: failure
// CPUID index
//-----------------------------------------------------------------------------
BOOL WINAPI Cpuid(DWORD index, PDWORD eax, PDWORD ebx, PDWORD ecx, PDWORD edx);

//-----------------------------------------------------------------------------
// CpuidTx
// TRUE: success, FALSE: failure
// CPUID index
//-----------------------------------------------------------------------------
BOOL WINAPI CpuidTx(DWORD index, PDWORD eax, PDWORD ebx, PDWORD ecx, PDWORD edx,DWORD_PTR threadAffinityMask);

//
BOOL WINAPI CpuidTxGroup(DWORD index, PDWORD eax, PDWORD ebx, PDWORD ecx, PDWORD edx, DWORD_PTR threadAffinityMask, WORD group);

//-----------------------------------------------------------------------------
// CpuidPx
// TRUE: success, FALSE: failure
// CPUID index
//-----------------------------------------------------------------------------
BOOL WINAPI CpuidPx(DWORD index, PDWORD eax, PDWORD ebx, PDWORD ecx, PDWORD edx, DWORD_PTR processAffinityMask);

//-----------------------------------------------------------------------------
// Rdtsc
// TRUE: success, FALSE: failure
// bit  0-31
// bit 32-63
//-----------------------------------------------------------------------------
BOOL WINAPI Rdtsc(PDWORD eax, PDWORD edx);

//-----------------------------------------------------------------------------
// RdmsrTx
// TRUE: success, FALSE: failure
//-----------------------------------------------------------------------------
BOOL WINAPI RdtscTx(PDWORD eax,	PDWORD edx,	DWORD_PTR threadAffinityMask);

//
BOOL WINAPI RdtscTxGroup(PDWORD eax, PDWORD edx, DWORD_PTR threadAffinityMask, WORD group);

//-----------------------------------------------------------------------------
// RdmsrPx
//-----------------------------------------------------------------------------
BOOL WINAPI RdtscPx(PDWORD eax, PDWORD edx,	DWORD_PTR processAffinityMask);

//-----------------------------------------------------------------------------
// Hlt
// TRUE: success, FALSE: failure
//-----------------------------------------------------------------------------
BOOL WINAPI Hlt();

//-----------------------------------------------------------------------------
// HltTx
//-----------------------------------------------------------------------------
BOOL WINAPI HltTx(DWORD_PTR threadAffinityMask);

//
BOOL WINAPI HltTxGroup(DWORD_PTR threadAffinityMask, WORD group);
//-----------------------------------------------------------------------------
// HltPx
//-----------------------------------------------------------------------------
BOOL WINAPI HltTx(DWORD_PTR processAffinityMask);

/******************************************************************************
**
** I/O
**
******************************************************************************/

//-----------------------------------------------------------------------------
// ReadIoPortByte
//-----------------------------------------------------------------------------
BYTE WINAPI ReadIoPortByte(WORD port);

//-----------------------------------------------------------------------------
// ReadIoPortWord
//-----------------------------------------------------------------------------
WORD WINAPI ReadIoPortWord(WORD port);

//-----------------------------------------------------------------------------
// ReadIoPortDword
//-----------------------------------------------------------------------------
DWORD WINAPI ReadIoPortDword(WORD port);

//-----------------------------------------------------------------------------
// ReadIoPortByteEx
// TRUE: success, FALSE: failure
//-----------------------------------------------------------------------------
BOOL WINAPI ReadIoPortByteEx(WORD port,	PBYTE value);
//-----------------------------------------------------------------------------
// ReadIoPortWordEx
// TRUE: success, FALSE: failure
//-----------------------------------------------------------------------------
BOOL WINAPI ReadIoPortWordEx(WORD port, PWORD value);
//-----------------------------------------------------------------------------
// ReadIoPortDwordEx
// TRUE: success, FALSE: failure
//-----------------------------------------------------------------------------
BOOL WINAPI ReadIoPortDwordEx(WORD port, PDWORD value);

//-----------------------------------------------------------------------------
// WriteIoPortByte
//-----------------------------------------------------------------------------
VOID WINAPI WriteIoPortByte(WORD port, BYTE value);

//-----------------------------------------------------------------------------
// WriteIoPortDword
//-----------------------------------------------------------------------------
VOID WINAPI WriteIoPortDword(WORD port,	DWORD value);


//-----------------------------------------------------------------------------
// WriteIoPortWord
//-----------------------------------------------------------------------------
VOID WINAPI WriteIoPortWord(WORD port, WORD value);

//-----------------------------------------------------------------------------
// WriteIoPortByteEx
// TRUE: success, FALSE: failure
//-----------------------------------------------------------------------------
BOOL WINAPI WriteIoPortByteEx(WORD port, BYTE value);

//-----------------------------------------------------------------------------
// WriteIoPortWordEx
// TRUE: success, FALSE: failure
//-----------------------------------------------------------------------------
BOOL WINAPI WriteIoPortWordEx(WORD port, WORD value);


//-----------------------------------------------------------------------------
// WriteIoPortDwordEx
// TRUE: success, FALSE: failure
//-----------------------------------------------------------------------------
BOOL WINAPI WriteIoPortDwordEx(WORD port, DWORD value);

/******************************************************************************
**
** PCI
**
******************************************************************************/
// pciAddress
//  0- 2: Function Number
//  3- 7: Device Number
//  8-15: PCI Bus Number
// 16-31: Reserved
// 0xFFFFFFFF : Error

//-----------------------------------------------------------------------------
// SetPciMaxBusNo
// Max PCI Bus to Scan
//-----------------------------------------------------------------------------
VOID WINAPI SetPciMaxBusIndex(BYTE max);

//-----------------------------------------------------------------------------
// ReadPciConfigByte
// PCI Device Address
// Configuration Address 0-255
// Read Value
//-----------------------------------------------------------------------------
BYTE WINAPI ReadPciConfigByte(DWORD pciAddress,	BYTE regAddress);

//-----------------------------------------------------------------------------
// ReadPciConfigWord
// Read Value
// PCI Device Address
// Configuration Address 0-255
//-----------------------------------------------------------------------------
WORD WINAPI ReadPciConfigWord(DWORD pciAddress, BYTE regAddress);

//-----------------------------------------------------------------------------
// ReadPciConfigDword
// Read Value
// PCI Device Address
// Configuration Address 0-255
//-----------------------------------------------------------------------------
DWORD WINAPI ReadPciConfigDword(DWORD pciAddress, BYTE regAddress);

//-----------------------------------------------------------------------------
// ReadPciConfigByteEx
// TRUE: success, FALSE: failure
// PCI Device Address
// Configuration Address 0-whatever
// Read Value
//-----------------------------------------------------------------------------
BOOL WINAPI ReadPciConfigByteEx(DWORD pciAddress, DWORD regAddress,	PBYTE value);

//-----------------------------------------------------------------------------
// ReadPciConfigWordEx
// TRUE: success, FALSE: failure
// PCI Device Address
// Configuration Address 0-whatever
// Read Value
//-----------------------------------------------------------------------------
BOOL WINAPI ReadPciConfigWordEx(DWORD pciAddress, DWORD regAddress,	PWORD value);

//-----------------------------------------------------------------------------
// ReadPciConfigDwordEx
// TRUE: success, FALSE: failure
// PCI Device Address
// Configuration Address 0-whatever
// Read Value
//-----------------------------------------------------------------------------
BOOL WINAPI ReadPciConfigDwordEx(DWORD pciAddress, DWORD regAddress, PDWORD value);

//-----------------------------------------------------------------------------
// WritePciConfigByte
// PCI Device Address
// Configuration Address 0-255
// Write Value
//-----------------------------------------------------------------------------
VOID WINAPI WritePciConfigByte(DWORD pciAddress, BYTE regAddress, BYTE value);

//-----------------------------------------------------------------------------
// WritePciConfigWord
//-----------------------------------------------------------------------------
VOID WINAPI WritePciConfigWord(DWORD pciAddress, BYTE regAddress, WORD value);

//-----------------------------------------------------------------------------
// WritePciConfigDword
//-----------------------------------------------------------------------------
VOID WINAPI WritePciConfigDword(DWORD pciAddress, BYTE regAddress,DWORD value);

//-----------------------------------------------------------------------------
// WritePciConfigByteEx
// TRUE: success, FALSE: failure
// PCI Device Address
// Configuration Address 0-whatever
// Write Value
//-----------------------------------------------------------------------------
BOOL WINAPI WritePciConfigByteEx(DWORD pciAddress, DWORD regAddress, BYTE value);

//-----------------------------------------------------------------------------
// WritePciConfigWordEx
//-----------------------------------------------------------------------------
BOOL WINAPI WritePciConfigWordEx(DWORD pciAddress, DWORD regAddress,WORD value);

//-----------------------------------------------------------------------------
// WritePciConfigDwordEx
//-----------------------------------------------------------------------------
BOOL WINAPI WritePciConfigDwordEx(DWORD pciAddress,	DWORD regAddress, DWORD value);

//-----------------------------------------------------------------------------
// FindPciDeviceById
// pciAddress, 0xFFFFFFFF: failure
// Vendor ID
// Device ID
// Index
//-----------------------------------------------------------------------------
DWORD WINAPI FindPciDeviceById(WORD vendorId, WORD deviceId, BYTE index);

//-----------------------------------------------------------------------------
// FindPciDeviceByClass
// pciAddress, 0xFFFFFFFF: failure
// Base Class
// Sub Class
// Program Interface
// Index
//-----------------------------------------------------------------------------
DWORD WINAPI FindPciDeviceByClass(BYTE baseClass, BYTE subClass, BYTE programIf, BYTE index);

/******************************************************************************
**
** Memory (Special API)
**
******************************************************************************/


//-----------------------------------------------------------------------------
// ReadDmiMemory
// Read size(byte), 0: failure
// Buffer
// Count
// Unit Size (BYTE, WORD, DWORD)
//-----------------------------------------------------------------------------
DWORD WINAPI ReadDmiMemory(PBYTE buffer, DWORD count,	DWORD unitSize);

//-----------------------------------------------------------------------------
// ReadPhysicalMemory
// Read size(byte), 0: failure
// Physical Memory Address
// Buffer
// Count
// Unit Size (BYTE, WORD, DWORD)
//-----------------------------------------------------------------------------
DWORD WINAPI ReadPhysicalMemory(DWORD_PTR address, PBYTE buffer, DWORD count,	DWORD unitSize);

//-----------------------------------------------------------------------------
// WritePhysicalMemory
// Write size(byte), 0: failure
// Physical Memory Address
// Buffer
// Count
// Unit Size (BYTE, WORD, DWORD)
//-----------------------------------------------------------------------------
DWORD WINAPI WritePhysicalMemory(DWORD_PTR address,	PBYTE buffer, DWORD count, DWORD unitSize);



#ifdef __cplusplus
}
#endif