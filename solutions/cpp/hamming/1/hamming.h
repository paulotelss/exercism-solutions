#pragma once

#include <string>
#include <string_view>

namespace hamming {
    // Calcula a diferença entre duas strings de mesmo comprimento
    int compute(std::string_view strand1, std::string_view strand2);
}