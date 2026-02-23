#include "nth_prime.h"
#include <vector>
#include <stdexcept>
#include <cmath>

namespace nth_prime {

unsigned int nth(unsigned int n) {
    if (n == 0) {
        throw std::domain_error("Não existe o 0-ésimo primo.");
    }

    // Estimativa do limite superior usando a aproximação de Rosser:
    // p_n < n * (log n + log log n) para n >= 6
    unsigned int limit;
    if (n < 6) {
        limit = 15; // Suficiente para os primeiros 5 primos
    } else {
        double fn = static_cast<double>(n);
        limit = static_cast<unsigned int>(fn * (std::log(fn) + std::log(std::log(fn))));
    }

    // Crivo de Eratóstenes usando std::vector<bool> (que é otimizado para bitset)
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    unsigned int count = 0;
    for (unsigned int p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            count++;
            if (count == n) return p;

            // Otimização: Começamos a marcar do quadrado de p
            if (static_cast<long long>(p) * p <= limit) {
                for (unsigned int i = p * p; i <= limit; i += p)
                    is_prime[i] = false;
            }
        }
    }

    throw std::runtime_error("Limite excedido.");
}

} // namespace nth_prime