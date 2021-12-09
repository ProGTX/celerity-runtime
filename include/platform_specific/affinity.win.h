#pragma once

#include <Windows.h>
#include <cassert.h>
#include <io.h>

typedef DWORD_PTR native_cpu_set;

uint32_t affinity_cores_available() {
	native_cpu_set affinity_base_mask;
	native_cpu_set sys_affinity_mask; // not really needed
	assert(GetProcessAffinityMask(GetCurrentProcess(), &affinity_base_mask, &sys_affinity_mask) == 0 && "Error retrieving base affinity mask.");

	int bit_mask_length = sizeof(native_cpu_set) * 8;
	native_cpu_set power = 1;
	uint32_t count = 0;
	for(uint32_t i = 0; i < bit_mask_length; i++) {
		if((power & affinity_base_mask) != 0) { ++count; }
		power = power << 1;
	}
	return count;
}