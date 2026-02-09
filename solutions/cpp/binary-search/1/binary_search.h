#pragma once

#include <vector>
#include <stdexcept>

namespace binary_search {

	// Usamos size_t para índices, pois vetores podem ser muito grandes
	std::size_t find(const std::vector<int>& data, int target);

}  // namespace binary_search