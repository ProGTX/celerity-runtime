#include <cassert>

#include <Windows.h>

#include "affinity.h"
#include "utils.h"

namespace celerity {
namespace detail {

	uint32_t affinity_cores_available() {
		using native_cpu_set = DWORD_PTR;
		auto get_affinity = []() {
			native_cpu_set affinity_base_mask;
			[[maybe_unused]] native_cpu_set sys_affinity_mask;
			auto base_mask_error = GetProcessAffinityMask(GetCurrentProcess(), &affinity_base_mask, &sys_affinity_mask);
			assert(base_mask_error == 0 && "Error retrieving base affinity mask.");
			return celerity::detail::util::popcount(affinity_base_mask);
		};
		static uint32_t count = get_affinity();
		return count;
	}

} // namespace detail
} // namespace celerity