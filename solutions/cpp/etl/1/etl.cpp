#include "etl.h"

#include <cctype>

namespace etl {

    std::map<char, int> transform(const std::map<int, std::vector<std::string>>& old) {
        std::map<char, int> out;

        for (const auto& [score, letters] : old) {
            for (const auto& s : letters) {
                if (s.empty()) continue;

                unsigned char uc = static_cast<unsigned char>(s[0]);
                char lower = static_cast<char>(std::tolower(uc));
                out[lower] = score;
            }
        }

        return out;
    }

    std::map<char, int> transform(const std::map<int, std::vector<char>>& old) {
        std::map<char, int> out;

        for (const auto& [score, letters] : old) {
            for (unsigned char uc : letters) {
                if (!std::isalpha(uc)) continue;

                char lower = static_cast<char>(std::tolower(uc));
                out[lower] = score;
            }
        }

        return out;
    }

} // namespace etl
