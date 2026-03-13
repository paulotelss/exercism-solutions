#pragma once

#include <stdexcept>
#include <utility>

namespace queen_attack {

class chess_board {
public:
    // Construtor que recebe as posições (linha, coluna) de cada rainha
    chess_board(std::pair<int, int> white, std::pair<int, int> black);

    // Retorna a posição das rainhas
    std::pair<int, int> white() const { return white_pos; }
    std::pair<int, int> black() const { return black_pos; }

    // Verifica se uma pode atacar a outra
    bool can_attack() const;

private:
    std::pair<int, int> white_pos;
    std::pair<int, int> black_pos;
};

} // namespace queen_attack