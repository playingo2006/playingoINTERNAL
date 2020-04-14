#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <regex>
#include <cstdlib>

void Relocate(BYTE* offsets, long addr) {

	HWND hwnd = FindWindowA(NULL, "Growtopia");
	LPVOID entry = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + addr);
	DWORD procID;
	HANDLE OpenProce = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
	OpenProce;
	HANDLE a = GetCurrentProcess();
	DWORD oldProtect = 0;
	DWORD OLDPROTECT;
	VirtualProtectEx(a, entry, sizeof(offsets), PAGE_EXECUTE_READWRITE, &OLDPROTECT);
}

void memSpray(long address, BYTE* offsets, int len) {
	LPVOID entry = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + address);
	HANDLE a = GetCurrentProcess();
	WriteProcessMemory(a, entry, offsets, len, NULL);

}