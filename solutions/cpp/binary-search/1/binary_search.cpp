#include "binary_search.h"

namespace binary_search {

    std::size_t find(const std::vector<int>& data, int target) {
        if (data.empty()) {
            throw std::domain_error("Lista vazia");
        }

        int left = 0;
        int right = static_cast<int>(data.size()) - 1;

        while (left <= right) {
            // Calculamos o meio assim para evitar overflow em listas gigantescas
            int mid = left + (right - left) / 2;

            if (data[mid] == target) {
                return static_cast<std::size_t>(mid);
            }

            if (data[mid] < target) {
                // O alvo está na metade direita
                left = mid + 1;
            }
            else {
                // O alvo está na metade esquerda
                right = mid - 1;
            }
        }

        // Se o loop terminar sem retornar, o item não existe
        throw std::domain_error("Item não encontrado");
    }

}  // namespace binary_search