
#include <catch2/catch.hpp>

#include <celerity.h>

#include "affinity.h"
#include "test_utils.h"

namespace celerity {
namespace detail {
	namespace utils {

		TEST_CASE("affinity check", "[utils]") {
			// REQUIRE_FALSE(runtime::is_initialized());

#ifdef _WIN32
			SECTION("in Windows") {
				DWORD_PTR cpu_mask = 1;
				SetProcessAffinityMask(GetCurrentProcess(), cpu_mask);
			}
#else
#include <sched.h>
			SECTION("in Posix") {
				cpu_set_t cpu_mask;
				CPU_ZERO(&cpu_mask);
				CPU_SET(0, &cpu_mask);
				pthread_setaffinity_np(pthread_self(), sizeof(cpu_mask), &cpu_mask);
			}
#endif
			auto cores = affinity_cores_available();
			REQUIRE(cores == 1);
		}

	} // namespace utils
} // namespace detail
} // namespace celerity