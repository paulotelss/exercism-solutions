#pragma once

#include <string>
#include <map>
#include <string_view>

namespace nucleotide_count {
    // A função que o teste "CATCH2_INTERNAL_TEST_0" está procurando
    std::map<char, int> count(std::string_view dna);
}