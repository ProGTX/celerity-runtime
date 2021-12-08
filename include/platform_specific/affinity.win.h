#pragma once

#include <cassert.h>
#include <pthread.h>
#include <unistd.h>

#include "affinity.h"

void affinity_int_base_mask() {
	static bool initialized = false;
	if(initialized) return;

	native_cpu_set sys_affinity_mask; // not really needed
	assert(GetProcessAffinityMask(GetCurrentProcess(), &g_affinity_base_mask, &sys_affinity_mask) == 0 && "Error retrieving base affinity mask.");
	initialized = true;
}

uint32_t affinity_cores_available() {
	affinity_int_base_mask();

	int bit_mask_length = sizeof(native_cpu_set) * 8;
	native_cpu_set power = 1;
	uint32_t count = 0;
	for(uint32_t i = 0; i < bit_mask_length; i++) {
		if((power & g_affinity_base_mask) != 0) { ++count; }
		power = power << 1;
	}
	return count;
}