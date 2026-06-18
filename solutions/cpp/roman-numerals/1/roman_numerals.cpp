#include "roman_numerals.h"
#include <vector>

namespace roman_numerals {

std::string convert(int number) {
    // Estrutura de dados emparelhada ordenando dos maiores valores para os menores
    // Inclui os símbolos tradicionais e as regras de subtração especial
    const std::vector<std::pair<int, std::string>> roman_mapping = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };

    std::string result = "";

    // Abordagem Greedy (Gananciosa)
    for (const auto& mapping : roman_mapping) {
        while (number >= mapping.first) {
            result += mapping.second;
            number -= mapping.first;
        }
    }

    return result;
}

} // namespace roman_numerals