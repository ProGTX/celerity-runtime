#include "affinity.h"
#include "logger.h"

namespace celerity {
namespace detail {

	void available_cores_check(std::shared_ptr<logger> log) {
		uint32_t cores;
		if((cores = affinity_cores_available()) < min_cores_needed) {
			log->warn(fmt::format("Too few cores available. Recomended: {}; available: {}", min_cores_needed, cores));
		}
	}

} // namespace detail
} // namespace celerity
