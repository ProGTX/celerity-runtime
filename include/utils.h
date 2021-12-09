#pragma once

#include <type_traits>

namespace celerity {
namespace detail {

	template <typename BITMASK>
	constexpr inline uint32_t popcount(const BITMASK bit_mask) noexcept {
		static_assert(std::is_integral_v<BITMASK> && std::is_unsigned_v<BITMASK>);

		uint32_t counter = 0;
		for(auto b = bit_mask; b; b >>= 1) {
			counter += b & 1;
		}
		return counter;
	}

} // namespace detail
} // namespace celerity
