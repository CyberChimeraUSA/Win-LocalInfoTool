#pragma once
#include <windows.h>
class SysInfo {

public: 
	int general_SysInfo(void);
	int general_CurrentHwProfile(void);
	int general_ComputerNameInfo(void);
	int general_FirmwareInfo(void);
private:
	//SystemInfo variables
	SYSTEM_INFO sSysInfo;

	DWORD     dwPageSize;
	LPVOID    lpMinimumApplicationAddress;
	LPVOID    lpMaximumApplicationAddress;
	DWORD_PTR dwActiveProcessorMask;
	DWORD     dwNumberOfProcessors;
	DWORD     dwProcessorType;
	DWORD     dwAllocationGranularity;
	WORD      wProcessorLevel;
	WORD      wProcessorRevision;
	//tagHW_PROFILE_INFO  variables
	HW_PROFILE_INFO hwInfo;
};

