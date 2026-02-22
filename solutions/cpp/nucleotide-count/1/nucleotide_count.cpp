#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

std::map<char, int> count(std::string_view dna) {
    // Inicializamos o mapa com os 4 nucleotídeos zerados (Requisito implícito)
    std::map<char, int> counts = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    for (char n : dna) {
        // Usamos counts.find para validar se o caractere é uma das chaves permitidas
        auto it = counts.find(n);
        if (it == counts.end()) {
            // Se não for A, C, G ou T, o teste espera uma exceção
            throw std::invalid_argument("Invalid nucleotide");
        }
        it->second++;
    }

    return counts;
}

} // namespace nucleotide_count