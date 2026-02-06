#include "pangram.h"

#include <cctype>

namespace pangram {

    bool is_pangram(const std::string& text) {
        bool seen[26] = { false };
        int count = 0;

        for (unsigned char ch : text) {
            if (std::isalpha(ch)) {
                char lower = static_cast<char>(std::tolower(ch));
                int idx = lower - 'a';
                if (0 <= idx && idx < 26 && !seen[idx]) {
                    seen[idx] = true;
                    ++count;
                    if (count == 26) return true;
                }
            }
        }

        return count == 26;
    }

} // namespace pangram
