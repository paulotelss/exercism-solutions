#include "spiral_matrix.h"

namespace spiral_matrix {

    std::vector<std::vector<int>> spiral_matrix(int size) {
        if (size <= 0) return {};

        // Inicializa a matriz preenchida com zeros
        std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));

        int top = 0;
        int bottom = size - 1;
        int left = 0;
        int right = size - 1;
        int current_value = 1;

        while (current_value <= size * size) {
            // 1. Da esquerda para a direita (topo)
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = current_value++;
            }
            top++;

            // 2. De cima para baixo (direita)
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = current_value++;
            }
            right--;

            // 3. Da direita para a esquerda (baixo)
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = current_value++;
            }
            bottom--;

            // 4. De baixo para cima (esquerda)
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = current_value++;
            }
            left++;
        }

        return matrix;
    }

}  // namespace spiral_matrix