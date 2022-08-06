#include "NoTasBot.hpp"

DWORD APIENTRY DllMain(
	HMODULE hModule,
	DWORD dwReason,
	LPVOID lpReserved
)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		const auto threadHandle = CreateThread(NULL, NO_TASBOT_STACK_SIZE, RemoveTasBotLabel, NULL, 0, NULL);
		if (threadHandle) CloseHandle(threadHandle);
	}
	return true;
}