#pragma once
#include <memory>
#include <stdexcept>


template <typename T>
struct Node {
    T value;
    std::unique_ptr<Node> next;
    Node* prev;

    template<typename U>
    Node(U&& a_value, Node* a_prev, std::unique_ptr<Node> a_next)
        : value(std::forward<U>(a_value)), prev(a_prev), next(std::move(a_next)) {}
};

template <typename T>
class DoublyLinkedList {
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    int _size;


    template<typename U>
    void push_back_internal(U&& value) {
        auto new_node = std::make_unique<Node<T>>(std::forward<U>(value), tail, nullptr);
        if (!head) {
            head = std::move(new_node);
            tail = head.get();
        } else {
            tail->next = std::move(new_node);
            tail->next->prev = tail;
            tail = tail->next.get();
        }
        ++_size;
    }

    template<typename U>
    void push_front_internal(U&& value) {
        auto new_node = std::make_unique<Node<T>>(std::forward<U>(value), nullptr, std::move(head));
        if (new_node->next) {
            new_node->next->prev = new_node.get();
        }
        else {
            tail = new_node.get();
        }
        head = std::move(new_node);
        _size++;
    }
    
    T erase_middle_node(Node<T>* node) {
        T value = node->value;
        node->next->prev = node->prev;
        node->prev->next = std::move(node->next);
        _size--;
        return value;
    }

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

    

    void push_back(T&& value) {
        push_back_internal(std::move(value));
    }

    void push_back(const T& value) {
        push_back_internal(value);
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

    void push_front(T&& value) {
        push_front_internal(std::move(value));
    }

    void push_front(const T& value) {
        push_front_internal(value);
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
        DoublyLinkedList<T>* list_ptr;

        Iterator(Node<T>* a_current, DoublyLinkedList<T>* a_list_ptr) : current_node_ptr(a_current), list_ptr(a_list_ptr) {}
        
        friend class DoublyLinkedList<T>;

    public:
        Iterator() : current_node_ptr(nullptr), list_ptr(nullptr) {}
        
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
            if (current_node_ptr == nullptr) {
                current_node_ptr = list_ptr->tail;
            }
            else if (current_node_ptr) {
                current_node_ptr = current_node_ptr->prev;
            }
            return *this;
        }
    };

    Iterator begin() {
        return Iterator(head.get(), this);
    }

    Iterator end() {
        return Iterator(nullptr, this);
    }

    Iterator back_iterator() {
        return Iterator(tail, this);
    }


    Iterator erase(Iterator it) {
        if (empty()) throw std::out_of_range("List is empty");
        if (it == end()) throw std::out_of_range("Invalid iterator");

        Iterator target_it = it++;

        target_it == begin() ? pop_front() : 
        target_it == back_iterator() ? pop_back() : 
        erase_middle_node(target_it.current_node_ptr);
        
        return it;
    }

    void move_to_begin(Iterator it) {
        if (empty()) throw std::out_of_range("List is empty");
        if (it == end()) throw std::out_of_range("Invalid iterator");
        if (it == begin()) return;

        if (it == back_iterator()) {
            push_front(pop_back());
        }
        else {
            push_front(erase_middle_node(it.current_node_ptr));
        }
    }

};
