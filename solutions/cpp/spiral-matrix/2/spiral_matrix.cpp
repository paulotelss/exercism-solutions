#include "spiral_matrix.h"

namespace spiral_matrix {

std::vector<std::vector<unsigned int>> spiral_matrix(unsigned int size) {
    if (size == 0) return {};

    // Inicializa a matriz com unsigned int
    std::vector<std::vector<unsigned int>> matrix(size, std::vector<unsigned int>(size, 0));

    int top = 0;
    int bottom = static_cast<int>(size) - 1;
    int left = 0;
    int right = static_cast<int>(size) - 1;
    unsigned int current_value = 1;

    while (current_value <= size * size) {
        // Direita
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = current_value++;
        }
        top++;

        // Baixo
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = current_value++;
        }
        right--;

        // Esquerda (apenas se ainda houver linhas)
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = current_value++;
            }
            bottom--;
        }

        // Cima (apenas se ainda houver colunas)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = current_value++;
            }
            left++;
        }
    }

    return matrix;
}

}  // namespace spiral_matrix