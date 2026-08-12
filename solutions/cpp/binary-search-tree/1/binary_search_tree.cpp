#include "binary_search_tree.h"

namespace binary_search_tree {

    void node::insert(int v) {
        auto& next = (v <= value) ? left : right;
        if (next) next->insert(v);
        else next = std::make_unique<node>(v);
    }

    void node::inorder(std::vector<int>& out) const {
        if (left) left->inorder(out);
        out.push_back(value);
        if (right) right->inorder(out);
    }

}
