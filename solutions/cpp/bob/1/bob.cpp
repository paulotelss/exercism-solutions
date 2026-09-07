#include "bob.h"
#include <cctype>

namespace bob {

std::string hey(const std::string& input) {
    // 1. Limpeza de espaços em branco no final da string (trailing whitespace)
    size_t last_char = input.find_last_not_of(" \t\n\r");

    // Se a string contiver apenas espaços em branco, é considerada silêncio
    if (last_char == std::string::npos) {
        return "Fine. Be that way!";
    }

    std::string trimmed = input.substr(0, last_char + 1);

    // 2. Análise da frase: Presença de letras, verificação de caixa alta e ponto de interrogação
    bool is_question = (trimmed.back() == '?');
    bool has_letters = false;
    bool is_yelling = true;

    for (char ch : trimmed) {
        unsigned char uc = static_cast<unsigned char>(ch);
        if (std::isalpha(uc)) {
            has_letters = true;
            if (std::islower(uc)) {
                is_yelling = false; // Se tiver pelo menos uma letra minúscula, não é grito
            }
        }
    }

    // Só é considerado grito se houver pelo menos uma letra alfabética na frase
    bool yelling = has_letters && is_yelling;

    // 3. Aplicação das regras de resposta do Bob
    if (yelling && is_question) {
        return "Calm down, I know what I'm doing!";
    }
    if (yelling) {
        return "Whoa, chill out!";
    }
    if (is_question) {
        return "Sure.";
    }

    return "Whatever.";
}

} // namespace bob