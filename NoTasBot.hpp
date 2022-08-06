#ifndef NO_TASBOT_HPP
#define NO_TASBOT_HPP

#include <Windows.h>
#include <cstring>
#include <cstdint>

#include "NoTasBot_config.hpp"
#include "TasBot_v34-18_offsets.hpp"

constexpr SIZE_T NO_TASBOT_STACK_SIZE = 0x8C;

DWORD WINAPI RemoveTasBotLabel(void *instance);


#endif // !NO_TASBOT_H