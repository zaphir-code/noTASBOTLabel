#include "NoTASBOT.hpp"

DWORD APIENTRY DllMain(
	HMODULE hModule,
	DWORD dwReason,
	LPVOID lpReserved
)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		const static HANDLE threadHandle = CreateThread(NULL, NO_TASBOT_STACK_SIZE, Remove_Label, NULL, 0, NULL);
		if (threadHandle) CloseHandle(threadHandle);
	}
	return true;
}