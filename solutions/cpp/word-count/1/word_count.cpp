#include "word_count.h"
#include <algorithm>
#include <cctype>

namespace word_count {

std::map<std::string, int> words(std::string const& input) {
    std::map<std::string, int> counts;
    std::string current_word;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];

        // Verificamos se o caractere é alfanumérico ou um apóstrofo de contração
        // O apóstrofo só conta se estiver entre duas letras/números (ex: that's)
        if (std::isalnum(c) || (c == '\'' && i > 0 && i + 1 < input.length() && 
            std::isalnum(input[i-1]) && std::isalnum(input[i+1]))) {
            
            current_word += std::tolower(c);
        } else {
            // Se encontramos um delimitador e temos uma palavra acumulada, salvamos
            if (!current_word.empty()) {
                counts[current_word]++;
                current_word.clear();
            }
        }
    }

    // Não esquecer da última palavra caso a string não termine em pontuação
    if (!current_word.empty()) {
        counts[current_word]++;
    }

    return counts;
}

} // namespace word_count