#include <stdlib.h>
#include <stdio.h>
#include "DriverManage.h"
#include "DriverBinFile.h"

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
	if (!Initialize(L"C:\\winring0.sys"))
	{
		Deinitialize();
		if (!Initialize(L"C:\\winring0.sys"))
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
	
	unsigned char data1[0x4000];
	unsigned long long  addr = 0x200000000;
	if (!ReadPhysicalMemory(addr, &data1[0], 4096, 1))
	{
		printf("read physical mem fail\n");
	}
	printf("mem 0x200000000 data is 0x%x\n", data1[0]);

	data1[0] = 0xaa;
	WritePhysicalMemory(addr, &data1[0], 1, 1);

	Deinitialize();

	return 0;
}