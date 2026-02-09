#pragma once
#include <memory>
#include <vector>

namespace binary_search_tree {

template <typename T>
class binary_tree {
public:
    explicit binary_tree(const T& value) : _data(value) {}

    const T& data() const { return _data; }
    const std::unique_ptr<binary_tree>& left() const { return _left; }
    const std::unique_ptr<binary_tree>& right() const { return _right; }

    void insert(const T& value) {
        if (value <= _data) {
            if (_left) _left->insert(value);
            else _left = std::make_unique<binary_tree>(value);
        } else {
            if (_right) _right->insert(value);
            else _right = std::make_unique<binary_tree>(value);
        }
    }

    // Estrutura para suportar o loop: for (auto &x : *tree)
    struct Iterator {
        std::vector<T> elements;
        size_t index;

        const T& operator*() const { return elements[index]; }
        Iterator& operator++() { index++; return *this; }
        bool operator!=(const Iterator& other) const { return index != other.index; }
    };

    Iterator begin() const {
        std::vector<T> sorted;
        fill_inorder(sorted);
        return {sorted, 0};
    }

    Iterator end() const {
        std::vector<T> sorted;
        fill_inorder(sorted);
        return {sorted, sorted.size()};
    }

private:
    T _data;
    std::unique_ptr<binary_tree> _left;
    std::unique_ptr<binary_tree> _right;

    void fill_inorder(std::vector<T>& out) const {
        if (_left) _left->fill_inorder(out);
        out.push_back(_data);
        if (_right) _right->fill_inorder(out);
    }
};

} // namespace binary_search_tree