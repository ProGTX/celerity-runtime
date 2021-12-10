
#ifdef __linux__

#include <cassert>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>

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
		auto get_affinity = []() {
			cpu_set_t affinity_base_mask;
			assert(pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &affinity_base_mask) == 0 && "Error retrieving base affinity mask.");
			return affinity_counter(affinity_base_mask);
		};
		static auto count = get_affinity();
		return count;
	}

} // namespace detail
} // namespace celerity

#endif