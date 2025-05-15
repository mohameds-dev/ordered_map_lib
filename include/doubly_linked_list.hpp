#pragma once
#include <memory>


template <typename T>
struct Node {
    T value;
    std::unique_ptr<Node> next;
    Node* prev;

    Node(const T& a_value, Node* a_prev, std::unique_ptr<Node> a_next)
        : value(a_value), prev(a_prev), next(std::move(a_next)) {}
};

template <typename T>
class DoublyLinkedList {
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    int _size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), _size(0) {}

    void push_back(const T& value) {
        if (!head) {
            head = std::make_unique<Node<T>>(value, nullptr, nullptr);
            tail = head.get();
        } else {
            tail->next = std::make_unique<Node<T>>(value, tail, nullptr);
            tail = tail->next.get();
        }

        _size++;
    }

    T pop_back() {
        T popped_value = tail->value;

        Node<T>* prev_node = tail->prev;
        prev_node->next.reset();
        tail = prev_node;

        _size--;

        return popped_value;
    }

    int size() const {
        return _size;
    }

    T front() const {
        return head->value;
    }

    T back() const {
        return tail->value;
    }
};
