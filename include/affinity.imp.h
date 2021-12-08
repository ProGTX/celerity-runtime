#pragma once

#ifdef _WIN32

#include "platform_specific/affinity.win.h"

#else

#include "platform_specific/affinity.unix.h"

#endif