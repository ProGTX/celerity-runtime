#ifdef _WIN32

#include <Windows.h>
#include <cassert.h>
#include <io.h>

#include "affinity.h"
#include "utils.h"

namespace celerity {
namespace detail {

	uint32_t affinity_cores_available() {
		using native_cpu_set = DWORD_PTR;
		auto get_affinity = []() {
			native_cpu_set affinity_base_mask;
			native_cpu_set sys_affinity_mask; // not really needed
			assert(GetProcessAffinityMask(GetCurrentProcess(), &affinity_base_mask, &sys_affinity_mask) == 0 && "Error retrieving base affinity mask.");
			return celerity::details::popcount(affinity_base_mask);
		};
		static uint32_t count = get_affinity();
		return count;
	}

} // namespace detail
} // namespace celerity
#endif