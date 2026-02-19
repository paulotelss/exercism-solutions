#include "high_scores.h"

namespace arcade {

std::vector<int> HighScores::top_three() const {
    // Calcula quantos elementos pegar (máximo 3)
    size_t count = std::min(scores_list.size(), size_t{3});
    std::vector<int> result(count);

    // partial_sort_copy: preenche o vetor destino com os maiores elementos
    // sem alterar o vetor original (imutabilidade).
    std::partial_sort_copy(scores_list.begin(), scores_list.end(),
                           result.begin(), result.end(),
                           std::greater<int>());

    return result;
}

}  // namespace arcade