#pragma once

#include <vector>
#include <algorithm>

namespace arcade {

class HighScores {
public:
    explicit HighScores(std::vector<int> scores) : scores_list(std::move(scores)) {}

    std::vector<int> list_scores() const { 
        return scores_list; 
    }

    int latest_score() const { 
        return scores_list.back(); 
    }

    int personal_best() const {
        if (scores_list.empty()) return 0;
        return *std::max_element(scores_list.begin(), scores_list.end());
    }

    std::vector<int> top_three() const;

private:
    std::vector<int> scores_list;
};

}  // namespace arcade