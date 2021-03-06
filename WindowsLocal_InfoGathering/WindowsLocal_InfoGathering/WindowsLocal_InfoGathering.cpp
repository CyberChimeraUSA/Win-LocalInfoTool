// WindowsLocal_InfoGathering.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Main.h"
#include "SysInfo.h"
using namespace std;

int main()
{
	cout << "Local Windows Info Gathering Tool " << endl;
	SysInfo SysInfoAccess;


	while (1)
	{
		cout << "Select Your Option " << endl << endl;
		cout << "Option 1: SYSTEM_INFO" << endl;
		cout << "Option 2: HW_PROFILE_INFO " << endl;
		cout << "Option 3: GetCurrentProcessId " << endl;
		cout << "Option 4: GetComputerNameEx " << endl;
		cout << "Option 5: GetFirmwareType" << endl;

		string input;
		getline(cin, input);
		int result;

		try
		{
			//FIX-ME 
			//doesnt handle floating point, just rounds them
			//doesnt handle anything after digit or a character 
			//example 1z11 is equal to 1
		    std::size_t lastChar;
			result = std::stoi(input, &lastChar, 10);
			
		}
		catch (std::invalid_argument&)
		{
			cout << "invalid_argument " << endl;
			result = 0;
		}
		catch (std::out_of_range&)
		{
			cout << "out_of_range " << endl;
			result = 0;
		}
		
		switch (result) {
		case 0:
	
			break;
		case 1:
			cout << "SYSTEM_INFO " << endl <<endl;
			SysInfoAccess.general_SysInfo();
			break;
		case 2: 
			cout << "HW_PROFILE_INFO " << endl << endl;
			SysInfoAccess.general_CurrentHwProfile();
			break;
		case 3:
			cout << "GetCurrentProcessId " << endl << endl;
			cout << GetCurrentProcessId() << endl;
			break;
		case 4: 
			cout << "GetComputerNameEx " << endl <<endl;
			SysInfoAccess.general_ComputerNameInfo();
			break;
		case 5: 
			cout << "GetFirmwareType " << endl << endl;
			if (SysInfoAccess.general_FirmwareInfo() != 0)
				cout << "FirmwareType Query Error" << endl;
			break;

		default:
			cout << "Not a Valid Entry" << endl;
			break;
		}


	}

	

    return 0;
}

