#include "anagram.h"

#include <algorithm>
#include <cctype>

namespace anagram {

static std::string to_lower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return result;
}

static std::string normalize(const std::string& s) {
    std::string result = to_lower(s);
    std::sort(result.begin(), result.end());
    return result;
}

anagram::anagram(const std::string& word)
    : base_word(word),
      base_lower(to_lower(word)),
      base_norm(normalize(word)) {}

std::vector<std::string>
anagram::matches(const std::vector<std::string>& candidates) const {
    std::vector<std::string> result;

    for (const auto& c : candidates) {
        if (to_lower(c) == base_lower) continue;
        if (normalize(c) == base_norm) result.push_back(c);
    }

    return result;
}

} // namespace anagram
