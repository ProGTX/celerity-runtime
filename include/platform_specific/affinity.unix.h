#pragma once

#include <cassert>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>

#include "affinity.h"

void affinity_int_base_mask() {
	static bool initialized = false;
	if(initialized) return;

	assert(pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &g_affinity_base_mask) == 0 && "Error retrieving base affinity mask.");
	initialized = true;
}

uint32_t affinity_cores_available() {
	affinity_int_base_mask();
	uint32_t count = 0;
	for(auto i = 0; i < CPU_SETSIZE; i++) {
		if(CPU_ISSET(i, &g_affinity_base_mask)) { ++count; }
	}
	return count;
}