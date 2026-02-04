#include "hexadecimal.h"

namespace hexadecimal {

    static int hex_value(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
        if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
        return -1;
    }

    int convert(const std::string& input) {
        int value = 0;

        for (char c : input) {
            int digit = hex_value(c);
            if (digit < 0) return 0;          // inválido -> 0
            value = value * 16 + digit;       // base-16
        }

        return value;
    }

} // namespace hexadecimal
