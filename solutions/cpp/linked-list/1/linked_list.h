#pragma once

#include <stdexcept>

namespace linked_list {

template <typename T>
class List {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        Node(T val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    // Destrutor para limpar a memória da rota ao destruir a lista
    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Impede cópias acidentais para evitar double-free de ponteiros
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    size_t count() const {
        return size;
    }

    // Adiciona uma estação ao final da rota
    void push(T value) {
        Node* new_node = new Node(value);
        if (!tail) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
    }

    // Remove e retorna a última estação da rota
    T pop() {
        if (!tail) {
            throw std::runtime_error("Lista vazia");
        }
        Node* old_tail = tail;
        T val = old_tail->value;

        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; // A lista ficou vazia
        }

        delete old_tail;
        size--;
        return val;
    }

    // Remove e retorna a primeira estação da rota
    T shift() {
        if (!head) {
            throw std::runtime_error("Lista vazia");
        }
        Node* old_head = head;
        T val = old_head->value;

        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // A lista ficou vazia
        }

        delete old_head;
        size--;
        return val;
    }

    // Adiciona uma estação no início da rota
    void unshift(T value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }

    // Remove a primeira ocorrência de uma estação fechada na rota
    bool erase(T value) {
        Node* current = head;
        while (current) {
            if (current->value == value) {
                // Ajusta o ponteiro do nó anterior
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next; // Era o head
                }

                // Ajusta o ponteiro do próximo nó
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev; // Era o tail
                }

                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

} // namespace linked_list