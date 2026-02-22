#pragma once

#include <string>
#include <string_view>

namespace rna_transcription {
    // Versão para sequências (strings)
    std::string to_rna(std::string_view dna);

    // Versão específica para um único caractere (o que o teste exige)
    char to_rna(char dna);
}