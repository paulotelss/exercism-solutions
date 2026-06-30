#include "series.h"
#include <stdexcept>

namespace series {

std::vector<std::string> slice(const std::string& digits, int n) {
    // Validações obrigatórias de contorno (guard clauses)
    if (n <= 0) {
        throw std::domain_error("O tamanho da fatia deve ser maior que zero.");
    }
    if (digits.empty()) {
        throw std::domain_error("A string de dígitos não pode estar vazia.");
    }
    if (static_cast<size_t>(n) > digits.length()) {
        throw std::domain_error("O tamanho da fatia não pode ser maior que o tamanho da string.");
    }

    std::vector<std::string> result;
    
    // O limite do loop garante que a janela não ultrapasse o fim da string
    // digits.length() - n é a última posição válida para iniciar uma fatia
    size_t last_start_index = digits.length() - n;

    for (size_t i = 0; i <= last_start_index; ++i) {
        result.push_back(digits.substr(i, n));
    }

    return result;
}

} // namespace series