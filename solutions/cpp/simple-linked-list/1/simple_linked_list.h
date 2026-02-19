#pragma once

#include <cstddef>
#include <memory>
#include <vector>

namespace simple_linked_list {

class List {
public:
    List() = default;
    ~List();

    // Impedimos cópias rasas para evitar problemas de memória
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    size_t size() const;
    void push(int data);
    int pop();
    void reverse();
    std::vector<int> as_vector() const;

private:
    struct Element {
        int data;
        std::unique_ptr<Element> next;
        Element(int val) : data(val), next(nullptr) {}
    };

    std::unique_ptr<Element> head{nullptr};
    size_t current_size{0};
};

}  // namespace simple_linked_list