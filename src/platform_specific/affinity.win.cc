#ifdef _WIN32

#include <Windows.h>
#include <cassert.h>
#include <io.h>

#include "affinity.h"
#include "utils.h"

typedef DWORD_PTR native_cpu_set;

uint32_t affinity_cores_available() {
	native_cpu_set affinity_base_mask;
	native_cpu_set sys_affinity_mask; // not really needed
	assert(GetProcessAffinityMask(GetCurrentProcess(), &affinity_base_mask, &sys_affinity_mask) == 0 && "Error retrieving base affinity mask.");

	static uint32_t count = celerity::details::popcount(affinity_base_mask);

	return count;
}

#endif