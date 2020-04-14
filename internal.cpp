#include "CustomMem.h"
#include "Nop.h"
#include "internal.h"

void LoadMemory() {
	Relocate(loadz, 0x1C40A5);
	Relocate(loadz, 0x3F7148);
	Relocate(loadz, 0xEEB3);
	Relocate(loadz, 0x2D28F7);
	Relocate(loadz, 0x2D313A);
	Relocate(loadz, 0x2C2377);
	Relocate(loadz, 0x404520);
	Relocate(loadz, 0x170EFB);
}

bool antibounce = false;
bool modfly = false;
bool noclip = false;
bool plog = false;
bool versionBypass = false;
bool resspam = false;

void OverlayUpdate() {
	LPVOID getPRoce = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + 0x3F7148);
	HANDLE internalHandleShit = GetCurrentProcess();

	char result[256];
	strcpy(result, "\n\n\n\n\n\n\n\n\n\n\n\n\n`3Growtopia Internal\n`2FPS: %d");
	if (antibounce) {
		strcat(result, "\n`4[F1] Antibounce: [ON]");
	}
	else
	{
		strcat(result, "\n`4[F1] Antibounce: [OFF]");
	}
	if (modfly) {
		strcat(result, "\n`6[F2] Modfly: [ON]");
	}
	else
	{
		strcat(result, "\n`6[F2] Modfly: [OFF]");
	}
	if (versionBypass) {
		strcat(result, "\n`9[F3] Version Bypass: [ON]");
	}
	else {
		strcat(result, "\n`9[F3] Version Bypass: [OFF]");
	}
	if (plog) {
		strcat(result, "\n`8[F4] Packet logging [ON]");
	}
	else {
		strcat(result, "\n`8[F4] Packet logging [OFF]");
	}
	WriteProcessMemory(internalHandleShit, getPRoce, result, sizeof(result), NULL);
}

void DoVersionBypass() {
	LPVOID getPRoce = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + 0x404520);
	HANDLE internalHandleShit = GetCurrentProcess();
	float game_version = 3.999000072;
	WriteProcessMemory(internalHandleShit, getPRoce, &game_version, sizeof(int), NULL);
}

void OverlayLoader() {
	BYTE bypass[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	memSpray(0xEEB3, bypass, sizeof(bypass));
	BYTE offsets[] = { 0x90, 0x90 };
	memSpray(0x1C40A5, offsets, sizeof(offsets));
}

void Loop() {
	while (1) {
		OverlayUpdate();
		if (GetAsyncKeyState(VK_F2)) {
			if (!modfly) {
				Sleep(100);
				memSpray(modflyop, onmodfly, sizeof(onmodfly));
				modfly = true;
			}
			else
			{
				Sleep(100);
				memSpray(modflyop, unmodfly, sizeof(unmodfly));
				modfly = false;
			}
		}
		if (GetAsyncKeyState(VK_F4)) {
			if (!plog) {
				Sleep(100);
				memSpray(logop, logbyte, sizeof(logbyte));
				plog = true;
			}
			else {
				Sleep(100);
				memSpray(logop, unlogbyte, sizeof(unlogbyte));
				plog = false;
			}
		}
		if (GetAsyncKeyState(VK_F3)) {
			Sleep(100);
			DoVersionBypass();
			versionBypass = true;
		}
		if (GetAsyncKeyState(VK_F1)) {
			if (!antibounce) {
				Sleep(100);
				memSpray(antibounceop, onantibounce, sizeof(onantibounce));
				antibounce = true;
			}
			else
			{
				Sleep(100);
				memSpray(antibounceop, unantibounce, sizeof(unantibounce));
				antibounce = false;
			}
		}
	}
}

void Internal::Loader() {
	LoadMemory();
	OverlayLoader();
	Loop();
}