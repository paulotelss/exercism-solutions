#include "say.h"

namespace say {

std::string in_english(long long n) {
    if (n < 0 || n > 999999999999LL) {
        throw std::domain_error("Número fora do limite.");
    }
    if (n == 0) return "zero";

    static const std::vector<std::string> units = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };

    static const std::vector<std::string> tens = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    // Removido o parâmetro 'self' que causou o erro de unused-parameter
    auto convert_below_1000 = [&](long long val) -> std::string {
        std::string res;
        if (val >= 100) {
            res += units[val / 100] + " hundred";
            val %= 100;
            if (val > 0) res += " ";
        }
        if (val >= 20) {
            res += tens[val / 10];
            if (val % 10 > 0) res += "-" + units[val % 10];
        } else if (val > 0) {
            res += units[val];
        }
        return res;
    };

    std::string result;
    struct Scale { long long divisor; std::string name; };
    static const std::vector<Scale> scales = {
        {1000000000LL, "billion"},
        {1000000LL, "million"},
        {1000LL, "thousand"},
        {1LL, ""}
    };

    for (const auto& s : scales) {
        long long chunk = n / s.divisor;
        if (chunk > 0) {
            std::string chunk_text = convert_below_1000(chunk);
            if (!result.empty()) result += " ";
            result += chunk_text;
            if (!s.name.empty()) result += " " + s.name;
        }
        n %= s.divisor;
    }

    return result;
}

} // namespace say