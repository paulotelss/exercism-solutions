#include "acronym.h"
#include <cctype>

namespace acronym {

std::string acronym(const std::string& phrase) {
    std::string result = "";
    bool new_word = true;

    for (char ch : phrase) {
        // Hífens e espaços marcam o início de uma nova palavra
        if (ch == ' ' || ch == '-') {
            new_word = true;
        } 
        // Se for uma letra e estivermos no início de uma palavra
        else if (std::isalpha(static_cast<unsigned char>(ch)) && new_word) {
            result += static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
            new_word = false; // Já capturamos a primeira letra desta palavra
        }
    }

    return result;
}

} // namespace acronym