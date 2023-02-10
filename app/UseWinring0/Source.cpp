#include <stdlib.h>
#include <stdio.h>
#include "DriverManage.h"
#include "DriverBinFile.h"
#include <windows.h>

// turn your windows to test mode !!!!!!!!!!!!!!!!!!!!
int main(int argc, char** argv)
{
	// "C:\\tiny\\xmrig-6.15.2-msvc-win64\\xmrig-6.15.2\\WinRing0x64.sys"
	// "E:\\github\\winring0\\x64\\WinRing0x64.sys"
	// "E:\\github\\winring0\\WinRing0_1_3_0\\release\\WinRing0x64.sys"
	// "E:\\download\\win_ring0-master\\gold_wring0_help\\release\\mem_sys\\WinRing0x64.sys"
	// "C:\\WinRing0x64.sys"
	// "C:\\winring0.sys"

	/*
	if (!Initialize(L"C:\\winring01.sys"))
	{
		Deinitialize();
		if (!Initialize(L"C:\\winring01.sys"))
		{
			printf("load driver fail\n");
			Deinitialize();
			return 0;
		}
	}
	*/

	
	SaveWinrig0binfile();
	if (!Initialize(wingring0_fullpath))
	{
		Deinitialize();
		if (!Initialize(wingring0_fullpath))
		{
			printf("load driver fail\n");
			Deinitialize();
			return 0;
		}
	}
	

	unsigned char data;

	data = ReadIoPortByte(0x82);
	printf("io 0x81 data is 0x%x\n", data);
	
	// windows10 must reverse memory
	/*
	unsigned long long  addr = 0x200000000;
	unsigned char data1[0x4000];
	data1[0] = 0x5a;
	WritePhysicalMemory(addr, &data1[0], 1, 1);

	
	if (!ReadPhysicalMemory(addr, &data1[0], 4096, 1))
	{
		printf("read physical mem fail\n");
	}
	printf("mem 0x200000000 data is 0x%x\n", data1[0]);
	*/

	

	unsigned int eax, ebx, ecx, edx;
	DWORD_PTR affity_mask, whichcore;
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	printf("now system cpu num is %d\n", sysInfo.dwNumberOfProcessors);

	/*
	for (unsigned long long kk = 0; kk < sysInfo.dwNumberOfProcessors; kk++)
	{
		whichcore = kk;
		affity_mask = shift << whichcore;
		
		HANDLE		hThread = NULL;
		unsigned long long 	mask = 0;
		hThread = GetCurrentThread();
		mask = SetThreadAffinityMask(hThread, affity_mask);
		Cpuid(1, (PDWORD)&eax, (PDWORD)&ebx, (PDWORD)&ecx, (PDWORD)&edx);

		if (((ebx >> 24) & 0xff) == 0x40)
		{
			printf("core num is %d  ebx is 0x%08X\n", kk, ebx);
		}
		SetThreadAffinityMask(hThread, mask);

	}
	*/

	whichcore = 32;
	affity_mask = 1ULL << whichcore;
	CpuidTx(1, (PDWORD)&eax, (PDWORD)&ebx, (PDWORD)&ecx, (PDWORD)&edx, affity_mask);
	if (((ebx >> 24) & 0xff) == 0x40)
	{
		printf("core num is %d  ebx is 0x%08X\n", whichcore, ebx);
	}
	


	Deinitialize();
	system("pause");
	return 0;
}