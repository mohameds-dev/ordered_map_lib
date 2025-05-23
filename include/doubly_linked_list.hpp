#pragma once
#include <memory>
#include <stdexcept>


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
    ~DoublyLinkedList() {
        clear();
    }

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
        } else {
            auto new_node = std::make_unique<Node<T>>(value, nullptr, std::move(head));
            new_node->next->prev = new_node.get();
            head = std::move(new_node);
        }
        _size++;
    }

    T pop_front() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }

        T popped_value = head->value;
        head = std::move(head->next);
        
        if (!head) 
            tail = nullptr;
        
        _size--;
        return popped_value;
    }

    void clear() {
        while(size() > 0) {
            pop_back();
        }
    }

    bool empty() const {
        return _size == 0;
    }

    class Iterator {
        Node<T>* current_node_ptr;

        Iterator(Node<T>* a_current) : current_node_ptr(a_current) {}
        
        friend class DoublyLinkedList<T>;

    public:
        Iterator() : current_node_ptr(nullptr) {}
        
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

        Iterator& operator--() {
            if (current_node_ptr) {
                current_node_ptr = current_node_ptr->prev;
            }
            return *this;
        }
    };

    Iterator begin() {
        return Iterator(head.get());
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator back_iterator() {
        return Iterator(tail);
    }
};
