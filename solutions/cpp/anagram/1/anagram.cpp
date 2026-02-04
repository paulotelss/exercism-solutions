#include "anagram.h"

#include <algorithm>
#include <cctype>

namespace anagram {

static std::string to_lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return s;
}

static std::string normalize(const std::string& s) {
    std::string r = to_lower(s);
    std::sort(r.begin(), r.end());
    return r;
}

Anagram::Anagram(const std::string& word)
    : base_word(word) {}

std::vector<std::string> Anagram::matches(const std::vector<std::string>& candidates) const {
    std::vector<std::string> result;

    std::string base_lower = to_lower(base_word);
    std::string base_norm = normalize(base_word);

    for (const auto& c : candidates) {
        if (to_lower(c) == base_lower) continue;
        if (normalize(c) == base_norm) result.push_back(c);
    }

    return result;
}

}
