#pragma once
#include <memory>


template <typename T>
struct Node {
    T value;
    std::unique_ptr<Node> next;
    Node* prev;

    Node(const T& val, Node* p, std::unique_ptr<Node> n)
        : value(val), prev(p), next(std::move(n)) {}
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
        Node<T>* temp = tail;
        tail = tail->prev;
        return temp->value;
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
