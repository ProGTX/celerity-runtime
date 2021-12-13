#pragma once


namespace celerity {
namespace detail {

#include <stdint.h>

	uint32_t affinity_cores_available();

	// a priori we need 3 threads plus 1 for workers. This depends on the application invoking celerity.
	constexpr static uint64_t min_cores_needed = 4;

} // namespace detail
} // namespace celerity