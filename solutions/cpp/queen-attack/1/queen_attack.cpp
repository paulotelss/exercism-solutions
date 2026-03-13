#include "queen_attack.h"
#include <cmath>

namespace queen_attack {

chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black) 
    : white_pos(white), black_pos(black) {
    
    // Validação de domínio: Rainhas na mesma posição
    if (white == black) {
        throw std::domain_error("As rainhas não podem ocupar a mesma casa.");
    }

    // Validação de limites do tabuleiro (0-7)
    auto is_off_board = [](std::pair<int, int> p) {
        return p.first < 0 || p.first >= 8 || p.second < 0 || p.second >= 8;
    };

    if (is_off_board(white) || is_off_board(black)) {
        throw std::domain_error("As rainhas devem estar dentro do tabuleiro 8x8.");
    }
}

bool chess_board::can_attack() const {
    int dr = std::abs(white_pos.first - black_pos.first);   // Diferença de linhas
    int dc = std::abs(white_pos.second - black_pos.second); // Diferença de colunas

    // 1. Mesma linha (dr == 0)
    // 2. Mesma coluna (dc == 0)
    // 3. Mesma diagonal: em um quadrado, a distância vertical é igual à horizontal
    return (dr == 0 || dc == 0 || dr == dc);
}

} // namespace queen_attack