#include "isogram.h"

#include <cctype>
#include <unordered_set>

namespace isogram {

    bool is_isogram(const std::string& phrase) {
        std::unordered_set<char> seen;

        for (unsigned char uc : phrase) {
            if (!std::isalpha(uc)) continue;

            char lower = static_cast<char>(std::tolower(uc));

            if (seen.count(lower)) return false;
            seen.insert(lower);
        }

        return true;
    }

} // namespace isogram
