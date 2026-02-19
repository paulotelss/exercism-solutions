#include "simple_linked_list.h"
#include <stdexcept>

namespace simple_linked_list {

// Destrutor iterativo para evitar estouro de pilha na desalocação recursiva do unique_ptr
List::~List() {
    while (head) {
        head = std::move(head->next);
    }
}

size_t List::size() const {
    return current_size;
}

void List::push(int data) {
    auto new_node = std::make_unique<Element>(data);
    new_node->next = std::move(head);
    head = std::move(new_node);
    current_size++;
}

int List::pop() {
    if (!head) {
        throw std::runtime_error("Empty list");
    }
    int data = head->data;
    head = std::move(head->next);
    current_size--;
    return data;
}

void List::reverse() {
    std::unique_ptr<Element> prev = nullptr;
    auto current = std::move(head);

    while (current) {
        auto next = std::move(current->next);
        current->next = std::move(prev);
        prev = std::move(current);
        current = std::move(next);
    }
    head = std::move(prev);
}

std::vector<int> List::as_vector() const {
    std::vector<int> result;
    Element* current = head.get();
    while (current) {
        result.push_back(current->data);
        current = current->next.get();
    }
    return result;
}

}  // namespace simple_linked_list