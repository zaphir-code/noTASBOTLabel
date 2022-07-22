#include "NoTASBOT.h"

DWORD WINAPI Main_Thread(LPVOID instance)
{
	MessageBoxA(NULL, "Test messadsge", "Test label", MB_OK);
	DWORD tBotBase = (DWORD)GetModuleHandleA("tBot.dll");
	char(*tBotLabel)[16] = (char(*)[16])(tBotBase + 0x24B568);
	char(*tBotLabel2)[16] = (char(*)[16])(tBotBase + 0x24B59C);
	memcpy(tBotLabel, "", strlen((LPCSTR)tBotLabel));
	memcpy(tBotLabel2, "", strlen((LPCSTR)tBotLabel2));
	MessageBoxA(NULL, (LPCSTR)tBotLabel, "Test", MB_OK);
	return 0;
}
DWORD APIENTRY DllMain(
	HMODULE hModule,
	DWORD dwReason,
	LPVOID lpReserved
)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		HANDLE threadHandle = CreateThread(NULL, 0, Main_Thread, NULL, 0, NULL);
		if (threadHandle) CloseHandle(threadHandle);
	}
	return TRUE;
}
