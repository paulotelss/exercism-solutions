#include "armstrong_numbers.h"

#include <vector>

namespace armstrong_numbers {

    static int ipow(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; ++i) result *= base;
        return result;
    }

    bool is_armstrong_number(int number) {
        if (number < 0) return false; // por segurança (não costuma cair em testes)

        // Extrai dígitos (sem usar pow double, evitando erro de precisão)
        std::vector<int> digits;

        if (number == 0) {
            digits.push_back(0);
        }
        else {
            int n = number;
            while (n > 0) {
                digits.push_back(n % 10);
                n /= 10;
            }
        }

        const int k = static_cast<int>(digits.size());

        int sum = 0;
        for (int d : digits) {
            sum += ipow(d, k);
        }

        return sum == number;
    }

} // namespace armstrong_numbers
