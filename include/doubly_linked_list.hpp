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

    int size() const {
        return _size;
    }

    const T& front() const {
        if (!head) {
            throw std::out_of_range("List is empty");
        }

        return head->value;
    }

    const T& back() const {
        if (!tail) {
            throw std::out_of_range("List is empty");
        }
        return tail->value;
    }

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
        if (!head) {
            throw std::out_of_range("List is empty");
        }

        T popped_value = tail->value;

        if (tail == head.get()) {
            head.reset();
            tail = nullptr;
        } else {
            Node<T>* prev_node = tail->prev;
            prev_node->next.reset();
            tail = prev_node;
        }

        _size--;

        return popped_value;
    }

    void push_front(const T& value) {
        if (!head) {
            head = std::make_unique<Node<T>>(value, nullptr, nullptr);
            tail = head.get();
        }
        else {
            auto new_node = std::make_unique<Node<T>>(value, nullptr, std::move(head));
            new_node->next->prev = new_node.get();
            head = std::move(new_node);
        }

        _size++;
    }

    T pop_front() {
        if (!head) 
            throw std::out_of_range("List is empty");

        T popped_value = head->value;
        head = std::move(head->next);
        
        if (!head) 
            tail = nullptr;
        
        _size--;
        return popped_value;
    }

    void clear() {
        _size = 0;
        head.reset();
        tail = nullptr;
    }

    class Iterator {
        Node<T>* current_node_ptr;

        Iterator(Node<T>* a_current) : current_node_ptr(a_current) {}
        
        friend class DoublyLinkedList<T>;

    public:
        bool operator==(const Iterator& other) const {
            return current_node_ptr == other.current_node_ptr;
        }

        bool operator!=(const Iterator& other) const {
            return current_node_ptr != other.current_node_ptr;
        }

        T& operator*() const {
            return current_node_ptr->value;
        }

        Iterator& operator++() {
            if (current_node_ptr) {
                current_node_ptr = current_node_ptr->next.get();
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator initial_state_copy = *this;
            ++(*this);
            return initial_state_copy;
        }

    };

    Iterator begin() {
        return Iterator(head.get());
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};
