#include "sieve.h"
#include <vector>

namespace sieve {

std::vector<int> primes(int limit) {
    if (limit < 2) return {};

    // Inicializamos todos como 'true' (não marcados)
    // Usamos limit + 1 para que os índices correspondam aos números reais
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    std::vector<int> result;

    for (int p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            // Se o número não está marcado, ele é primo
            result.push_back(p);

            // Marcamos os múltiplos de p começando de p * p
            // Usamos long long para evitar overflow se o limite for muito alto
            if (static_cast<long long>(p) * p <= limit) {
                for (int i = p * p; i <= limit; i += p) {
                    is_prime[i] = false;
                }
            }
        }
    }

    return result;
}

} // namespace sieve