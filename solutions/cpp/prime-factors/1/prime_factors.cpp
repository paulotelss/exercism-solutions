#include "prime_factors.h"

namespace prime_factors {

std::vector<long long> of(long long n) {
    std::vector<long long> factors;
    long long divisor = 2;

    // Fatoração por divisão tentativa
    while (divisor * divisor <= n) {
        while (n % divisor == 0) {
            factors.push_back(divisor);
            n /= divisor;
        }
        divisor++;
    }

    // Se n > 1, o que sobrou é o último fator primo
    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

} // namespace prime_factors