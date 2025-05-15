#pragma once

// implement node with template type
template <typename T>
struct Node {
    T value;
    Node* prev;
    Node* next;
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int _size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), _size(0) {}


    void push_back(const T& value){
        if (head == nullptr) {
            head = new Node<T>{value, nullptr, nullptr};
            tail = head;
        }
        else {
            tail->next = new Node<T>{value, tail, nullptr};
            tail = tail->next;
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
