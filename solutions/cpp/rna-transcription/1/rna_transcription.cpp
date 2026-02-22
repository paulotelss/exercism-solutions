#include "rna_transcription.h"

namespace rna_transcription {

// Centralizamos a lógica de conversão aqui
char convert_nucleotide(char n) {
    switch (n) {
        case 'G': return 'C';
        case 'C': return 'G';
        case 'T': return 'A';
        case 'A': return 'U';
        default:  return n;
    }
}

// Implementação para char: Resolve o erro 'char == std::string'
char to_rna(char dna) {
    return convert_nucleotide(dna);
}

// Implementação para string: Resolve sequências completas
std::string to_rna(std::string_view dna) {
    std::string rna = "";
    for (char n : dna) {
        rna += convert_nucleotide(n);
    }
    return rna;
}

} // namespace rna_transcription