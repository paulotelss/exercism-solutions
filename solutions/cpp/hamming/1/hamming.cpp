#include "hamming.h"
#include <stdexcept>
#include <numeric>

namespace hamming {

int compute(std::string_view strand1, std::string_view strand2) {
    // Validação de comprimento: requisito essencial da Distância de Hamming
    if (strand1.length() != strand2.length()) {
        throw std::domain_error("As sequências devem ter o mesmo comprimento.");
    }

    // Usamos o inner_product de forma não convencional:
    // 0: Valor inicial da contagem
    // std::plus<>(): Operação de soma para acumular os erros
    // std::not_equal_to<>(): Compara os caracteres; retorna 1 se forem diferentes
    return std::inner_product(strand1.begin(), strand1.end(), 
                              strand2.begin(), 0, 
                              std::plus<int>(), 
                              std::not_equal_to<char>());
}

} // namespace hamming