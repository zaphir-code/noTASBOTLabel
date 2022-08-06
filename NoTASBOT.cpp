#include "NoTasBot.hpp"

static inline void CleanStringByOffset(const void *pBaseAddr, const std::uintptr_t offset) {
	std::strcpy(reinterpret_cast<char *>((reinterpret_cast<std::uintptr_t>(pBaseAddr) + offset)), "");
}

DWORD WINAPI RemoveTasBotLabel(void *instance)
{
	// Base address of TasBot dll
	HANDLE TasBot_Base;

	// wait until TasBot dll is loaded
	do {
		TasBot_Base = GetModuleHandleA(TASBOT_DLL);
	} while (!TasBot_Base);

	CleanStringByOffset(TasBot_Base, TASBOT_LABEL_1);
	CleanStringByOffset(TasBot_Base, TASBOT_LABEL_2);

	CloseHandle(TasBot_Base);

	return 0;
}