#include <Windows.h>
#include <iostream>
#include  "internal.h"

using namespace std;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Internal::Loader, hModule, 0, 0);
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}