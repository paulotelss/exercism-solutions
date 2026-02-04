#pragma once

#include <string>
#include <vector>

namespace anagram {

class anagram {
public:
    explicit anagram(const std::string& word);
    std::vector<std::string> matches(const std::vector<std::string>& candidates) const;

private:
    std::string base_word;
    std::string base_lower;
    std::string base_norm;
};

} // namespace anagram
