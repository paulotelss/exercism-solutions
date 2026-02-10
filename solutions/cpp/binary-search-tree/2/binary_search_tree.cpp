#include <memory>
#include <vector>
#include <iterator>

namespace binary_search_tree {

template <typename T>
class binary_tree {
    T value;
    std::unique_ptr<binary_tree<T>> l{};
    std::unique_ptr<binary_tree<T>> r{};

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
    std::unique_ptr<binary_tree<T>>& left() { return l; }
    std::unique_ptr<binary_tree<T>>& right() { return r; }

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

} // namespace binary_search_tree
