#include "alphametics.h"
#include <algorithm>
#include <vector>
#include <set>

namespace alphametics {

struct Letter {
    char c;
    long long weight = 0;
    bool can_be_zero = true;
};

// Backtracking otimizado usando os pesos calculados
bool backtrack(size_t idx, long long current_sum, std::vector<Letter>& letters, 
               bool used_digits[10], std::map<char, int>& result) {
    if (idx == letters.size()) {
        return current_sum == 0;
    }

    for (int digit = 0; digit <= 9; ++digit) {
        if (!used_digits[digit]) {
            if (digit == 0 && !letters[idx].can_be_zero) continue;

            used_digits[digit] = true;
            result[letters[idx].c] = digit;
            
            if (backtrack(idx + 1, current_sum + letters[idx].weight * digit, 
                          letters, used_digits, result)) {
                return true;
            }

            used_digits[digit] = false;
        }
    }
    return false;
}

std::optional<std::map<char, int>> solve(std::string puzzle) {
    std::map<char, long long> weight_map;
    std::set<char> leading_letters;
    std::set<char> all_chars;
    
    std::vector<std::string> words;
    std::string word;
    
    // Parser para identificar letras, palavras e quais não podem ser zero
    for (char c : puzzle) {
        if (std::isupper(c)) {
            word += c;
            all_chars.insert(c);
        } else if (!word.empty()) {
            words.push_back(word);
            leading_letters.insert(word[0]);
            word.clear();
        }
    }
    if (!word.empty()) {
        words.push_back(word);
        leading_letters.insert(word[0]);
    }

    // Atribuição de pesos: cada letra contribui conforme sua posição decimal
    // O último item (resultado da soma) entra com peso negativo
    for (size_t i = 0; i < words.size(); ++i) {
        long long mult = (i == words.size() - 1) ? -1 : 1;
        long long power = 1;
        for (int j = words[i].size() - 1; j >= 0; --j) {
            weight_map[words[i][j]] += (power * mult);
            power *= 10;
        }
    }

    std::vector<Letter> letters;
    for (char c : all_chars) {
        bool can_be_zero = (leading_letters.find(c) == leading_letters.end());
        // Regra especial: se a palavra tiver mais de um dígito, o primeiro não é zero
        // Mas se a palavra for apenas "A", ela poderia ser zero (raro, mas possível em lógica)
        // Os testes geralmente assumem leading digit != 0 para multi-digit numbers.
        letters.push_back({c, weight_map[c], can_be_zero});
    }

    // Heurística de ordenação: resolver primeiro as letras com maior impacto (peso)
    // Isso aumenta drasticamente a velocidade do pruning (poda) no backtracking
    std::sort(letters.begin(), letters.end(), [](const Letter& a, const Letter& b) {
        return std::abs(a.weight) > std::abs(b.weight);
    });

    std::map<char, int> result;
    bool used_digits[10] = {false};
    
    if (backtrack(0, 0, letters, used_digits, result)) {
        return result; // Retorna o map dentro do optional
    }

    return std::nullopt; // Indica que não há solução
}

}