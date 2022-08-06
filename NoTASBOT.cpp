#include "NoTasBot.hpp"


DWORD WINAPI Remove_Label(void* instance)
{
	// Base address of TasBot dll
	static HANDLE tBotBase;

	// wait until TasBot dll is loaded
	do {
		tBotBase = GetModuleHandleA(TBOT_DLL);
	} while (!tBotBase);

	// Clear first and second labels
	strcpy(reinterpret_cast<char*>((reinterpret_cast<std::uintptr_t>(tBotBase) + TASBOT_LABEL_1)), "");
	strcpy(reinterpret_cast<char*>((reinterpret_cast<std::uintptr_t>(tBotBase) + TASBOT_LABEL_2)), "");

	CloseHandle(tBotBase);

	return 0;
}