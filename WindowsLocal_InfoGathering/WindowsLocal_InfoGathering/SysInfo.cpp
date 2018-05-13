
#include "stdafx.h"
#include "Main.h"
#include "SysInfo.h"
using namespace std;

int SysInfo::general_SysInfo(void)
{
	GetSystemInfo(&sSysInfo);
#if 1
	cout <<"dwPageSize: "                  << sSysInfo.dwPageSize << endl;
	cout <<"lpMinimumApplicationAddress: " << sSysInfo.lpMinimumApplicationAddress << endl;
	cout <<"lpMaximumApplicationAddress: " << sSysInfo.lpMaximumApplicationAddress << endl;
	cout <<"dwActiveProcessorMask: "       << sSysInfo.dwActiveProcessorMask << endl;
	cout <<"dwNumberOfProcessors: "        << sSysInfo.dwNumberOfProcessors << endl;
	cout <<"dwProcessorType: "             << sSysInfo.dwProcessorType << endl;
	cout <<"dwAllocationGranularity: "     << sSysInfo.dwAllocationGranularity << endl;
	cout <<"wProcessorLevel: "             << sSysInfo.wProcessorLevel << endl;
	cout <<"wProcessorRevision: "          << sSysInfo.wProcessorRevision << endl;
#endif


	return 0;
}

int SysInfo::general_CurrentHwProfile(void)
{
	HW_PROFILE_INFO   HwProfInfo;

	if (!GetCurrentHwProfile(&HwProfInfo))
	{
		_tprintf(TEXT("GetCurrentHwProfile failed with error %lx\n"),
			GetLastError());
		return 1;
	}
	_tprintf(TEXT("DockInfo = %d\n"), HwProfInfo.dwDockInfo);
	_tprintf(TEXT("Profile Guid = %s\n"), HwProfInfo.szHwProfileGuid);
	_tprintf(TEXT("Friendly Name = %s\n"), HwProfInfo.szHwProfileName);

	return 0;
}

int SysInfo::general_FirmwareInfo(void)
{
	/*
	typedef enum _FIRMWARE_TYPE {
	FirmwareTypeUnknown  = 0,
	FirmwareTypeBios     = 1,
	FirmwareTypeUefi     = 2,
	FirmwareTypeMax      = 3
	} FIRMWARE_TYPE, *PFIRMWARE_TYPE;
	*/
	FIRMWARE_TYPE test1;
	if (GetFirmwareType(&test1) != 0)
	{
		if (GetFirmwareType(&test1) == 0)
		  cout <<"Unknown Type" << GetFirmwareType(&test1) << endl;
		else if (GetFirmwareType(&test1) == 1)
			cout << "BIOS Type" << GetFirmwareType(&test1) << endl;
		else if (GetFirmwareType(&test1) == 2)
			cout << "UEFI Type" << GetFirmwareType(&test1) << endl;
		else if (GetFirmwareType(&test1) == 3)
			cout << "Mas Type" << GetFirmwareType(&test1) << endl;
		return 0;
	}
	else
		return 1;
	
}

int SysInfo::general_ComputerNameInfo(void)
{
	TCHAR buffer[256] = TEXT("");
	TCHAR szDescription[8][32] = { TEXT("NetBIOS"),
		TEXT("DNS hostname"),
		TEXT("DNS domain"),
		TEXT("DNS fully-qualified"),
		TEXT("Physical NetBIOS"),
		TEXT("Physical DNS hostname"),
		TEXT("Physical DNS domain"),
		TEXT("Physical DNS fully-qualified") };
	int cnf = 0;
	DWORD dwSize = sizeof(buffer);

	for (cnf = 0; cnf < ComputerNameMax; cnf++)
	{
		if (!GetComputerNameEx((COMPUTER_NAME_FORMAT)cnf, buffer, &dwSize))
		{
			_tprintf(TEXT("GetComputerNameEx failed (%d)\n"), GetLastError());
			return 1;
		}
		else _tprintf(TEXT("%s: %s\n"), szDescription[cnf], buffer);

		dwSize = _countof(buffer);
		ZeroMemory(buffer, dwSize);
	}
	return 0;
}