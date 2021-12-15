
#include <cassert>
#include <cstdint>

#include <pthread.h>
#include <sched.h>

#include "affinity.h"

namespace celerity {
namespace detail {

	uint32_t affinity_counter(const cpu_set_t& base_mask) {
		auto count = 0;
		for(auto i = 0; i < CPU_SETSIZE; i++) {
			if(CPU_ISSET(i, &base_mask)) { ++count; }
		}
		return count;
	}

	uint32_t affinity_cores_available() {
		cpu_set_t affinity_base_mask;
		const auto base_mask_error = pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &affinity_base_mask);
		assert(base_mask_error == 0 && "Error retrieving base affinity mask.");
		return affinity_counter(affinity_base_mask);
	}

} // namespace detail
} // namespace celerity