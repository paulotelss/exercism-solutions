#pragma once

#include <string>
#include <vector>

namespace anagram {

class Anagram {
public:
    explicit Anagram(const std::string& word);
    std::vector<std::string> matches(const std::vector<std::string>& candidates) const;

private:
    std::string base_word;
};

}
