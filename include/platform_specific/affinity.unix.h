#pragma once

#include <cassert>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>

typedef cpu_set_t native_cpu_set;

uint32_t affinity_cores_available() {
	native_cpu_set affinity_base_mask;
	assert(pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &affinity_base_mask) == 0 && "Error retrieving base affinity mask.");

	uint32_t count = 0;
	for(auto i = 0; i < CPU_SETSIZE; i++) {
		if(CPU_ISSET(i, &affinity_base_mask)) { ++count; }
	}
	return count;
}