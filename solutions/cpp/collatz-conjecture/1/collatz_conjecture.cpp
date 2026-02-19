#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

// Função auxiliar estática para recursão de cauda
static int count_steps(int n, int current_steps) {
    if (n == 1) return current_steps;

    // Se n for par: n / 2
    // Se n for ímpar: 3n + 1
    // A técnica de bitwise (n & 1) é usada para verificar se é ímpar
    if ((n & 1) == 0) {
        return count_steps(n / 2, current_steps + 1);
    } else {
        // Nota: Em sistemas reais, 3n + 1 pode causar overflow em ints de 32 bits
        // para números muito grandes. Para o Exercism, o int padrão costuma bastar.
        return count_steps(3 * n + 1, current_steps + 1);
    }
}

int steps(int n) {
    if (n <= 0) {
        throw std::domain_error("Only positive integers are allowed");
    }
    
    return count_steps(n, 0);
}

} // namespace collatz_conjecture