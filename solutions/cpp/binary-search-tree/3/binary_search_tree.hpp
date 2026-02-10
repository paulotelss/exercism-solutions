#pragma once

#include <memory>
#include <vector>

namespace binary_search_tree {

template <typename T>
class binary_tree {
    T value;
    std::unique_ptr<binary_tree> l{}, r{};

    void inorder(std::vector<T>& out) const {
        if (l) l->inorder(out);
        out.push_back(value);
        if (r) r->inorder(out);
    }

public:
    explicit binary_tree(const T& v) : value(v) {}

    void insert(const T& v) {
        if (v <= value) {
            if (l) l->insert(v);
            else l = std::make_unique<binary_tree>(v);
        } else {
            if (r) r->insert(v);
            else r = std::make_unique<binary_tree>(v);
        }
    }

    const T& data() const { return value; }
    std::unique_ptr<binary_tree>& left() { return l; }
    std::unique_ptr<binary_tree>& right() { return r; }

    auto begin() const {
        auto vec = std::make_shared<std::vector<T>>();
        inorder(*vec);
        return vec->begin();
    }

    auto end() const {
        auto vec = std::make_shared<std::vector<T>>();
        inorder(*vec);
        return vec->end();
    }
};

template <typename T>
std::unique_ptr<binary_tree<T>> make_tree(const std::vector<T>& values) {
    auto tree = std::make_unique<binary_tree<T>>(values.front());
    for (size_t i = 1; i < values.size(); ++i)
        tree->insert(values[i]);
    return tree;
}

} // namespace binary_search_tree
