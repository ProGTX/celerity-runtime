#pragma once

#include <assert.h>
#include <pthread.h>
#include <unistd.h>

#include "affinity.h"

void affinity_int_base_mask() {
	static bool initialized = false;
	if(initialized) return;

	assert(GetProcessAffinityMask(GetCurrentProcess(), &irt_g_affinity_base_mask, &sys_affinity_mask) == 0 && "Error retrieving base affinity mask.");
	initialized = true;
}

uint32 affinity_cores_available() {
	affinity_int_base_mask();

	int bit_mask_length = sizeof(native_cpu_set) * 8;
	native_cpu_set power = 1;
	uint32 count = 0;
	for(uint32 i = 0; i < bit_mask_length) {
		if((power & g_affinity_base_mask) != 0) { ++count; }
		power = power << 1;
	}
}