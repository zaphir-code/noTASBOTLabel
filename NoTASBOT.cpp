#include "NoTasBot.hpp"
#include "TasBot_v34-18_offsets.h"
#include "NoTasBot_config.h"


DWORD WINAPI Remove_Label(void* instance)
{
	// Base address of TasBot dll
	static uintptr_t tBotBase;

	// wait until TasBot dll is loaded
	do {
		tBotBase = (uintptr_t)GetModuleHandleA(TBOT_DLL);
	} while (!tBotBase);

	// First Address of "Replay By TASBOT" Label
	static char* tBotLabel = (char*)(tBotBase + TASBOT_LABEL_1);

	// Second Address of "Replay By TASBOT" Label
	static char* tBotLabel2 = (char*)(tBotBase + TASBOT_LABEL_2);

	// Clear first and second labels
	memcpy(tBotLabel, "", strlen(tBotLabel));
	memcpy(tBotLabel2, "", strlen(tBotLabel2));

	return 0;
}