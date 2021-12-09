#pragma once

#ifdef _WIN32

#include "platform_specific/affinity.win.h"

#else

#include "platform_specific/affinity.unix.h"

#endif

// a priori we need 3 threads plus 1 for workers. This depends on the application invoking celerity.
constexpr static uint64_t min_cores_needed = 4;