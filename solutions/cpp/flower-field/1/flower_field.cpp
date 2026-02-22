#include "flower_field.h"

namespace flower_field {

std::vector<std::string> annotate(const std::vector<std::string>& garden) {
    if (garden.empty()) return {};
    int rows = garden.size();
    int cols = garden[0].size();
    if (cols == 0) return {""};

    // Técnica: Linearização com Padding
    // Criei um vetor plano com uma borda extra de segurança (sentinelas)
    // Isso elimina todos os "if (x > 0 && x < max)" dentro do loop
    std::vector<int> grid((rows + 2) * (cols + 2), 0);

    // Passo 1: Marcar a influência das flores
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (garden[r][c] == '*') {
                // Quando achamos uma flor, incrementamos todos os 8 vizinhos
                // usando offsets fixos na nossa grade linearizada
                for (int dr : {-1, 0, 1}) {
                    for (int dc : {-1, 0, 1}) {
                        if (dr == 0 && dc == 0) continue;
                        grid[(r + 1 + dr) * (cols + 2) + (c + 1 + dc)]++;
                    }
                }
            }
        }
    }

    // Passo 2: Reconstruir o tabuleiro original
    std::vector<std::string> result = garden;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (result[r][c] != '*') {
                int count = grid[(r + 1) * (cols + 2) + (c + 1)];
                if (count > 0) {
                    result[r][c] = '0' + count;
                }
            }
        }
    }

    return result;
}

} // namespace flower_field