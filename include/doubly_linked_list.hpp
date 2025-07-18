#pragma once
#include <memory>
#include <stdexcept>


template <typename T>
struct Node {
    T value;
    std::unique_ptr<Node> next;
    Node* prev;

    template<typename U>
    Node(Node* a_prev, std::unique_ptr<Node> a_next, U&& a_value)
        : value(std::forward<U>(a_value)), prev(a_prev), next(std::move(a_next)) {}

    template <typename... Args>
    Node(Node* a_prev, std::unique_ptr<Node> a_next, Args&&... args)
        : value(std::forward<Args>(args)...), prev(a_prev), next(std::move(a_next)) {}

};

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), _size(0) {}

    DoublyLinkedList(std::initializer_list<T> init_list) : DoublyLinkedList() {
        for (const auto& value : init_list) push_back(value);
    }

    template <typename ParamIterator>
    DoublyLinkedList(ParamIterator begin, ParamIterator end) : DoublyLinkedList() {
        for (auto it = begin; it != end; it++) {
            push_back(*it);
        }
    }

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
        raise_exception_if_empty();

        T popped_value = std::move(tail->value);

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
        raise_exception_if_empty();

        T popped_value = std::move(head->value);
        head = std::move(head->next);
        
        if (!head) 
            tail = nullptr;
        
        _size--;
        return popped_value;
    }

    void clear() {
        while(!empty()) pop_back();
    }

    bool empty() const {
        return !head;
    }

    class Iterator {
    public:
        Iterator() : current_node_ptr(nullptr), list_ptr(nullptr) {}
        
        bool operator==(const Iterator& other) const {
            return current_node_ptr == other.current_node_ptr;
        }

        bool operator!=(const Iterator& other) const {
            return current_node_ptr != other.current_node_ptr;
        }

        T& operator*() const {
            raise_exception_if_empty();

            if (*this == list_ptr->end())
                throw std::out_of_range("end iterator unexpectedly dereferenced");

            return current_node_ptr->value;
        }

        Iterator& operator++() {
            raise_exception_if_empty();

            if (*this == list_ptr->end())
                throw std::out_of_range("called ++ on end iterator");

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
            raise_exception_if_empty();

            if (*this == list_ptr->begin())
                throw std::out_of_range("called -- on begin iterator");
                
            if (current_node_ptr == nullptr) {
                current_node_ptr = list_ptr->tail;
            }
            else if (current_node_ptr) {
                current_node_ptr = current_node_ptr->prev;
            }
            return *this;
        }

        Iterator operator--(int) {
            Iterator initial_state_copy = *this;
            --(*this);
            return initial_state_copy;
        }

        private:
        void raise_exception_if_empty() const {
            if (list_ptr->empty())
                throw std::out_of_range("Container is empty");
        }

        Node<T>* current_node_ptr;
        DoublyLinkedList<T>* list_ptr;
        Iterator(Node<T>* a_current, DoublyLinkedList<T>* a_list_ptr) : current_node_ptr(a_current), list_ptr(a_list_ptr) {}
        friend class DoublyLinkedList<T>;
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
        raise_exception_if_empty();
        if (it == end()) throw std::out_of_range("erase called on end iterator");

        Iterator target_it = it++;

        target_it == begin() ? pop_front() : 
        target_it == back_iterator() ? pop_back() : 
        erase_middle_node(target_it.current_node_ptr);
        
        return it;
    }

    void move_to_begin(Iterator it) {
        raise_exception_if_empty();
        if (it == end()) throw std::out_of_range("move_to_begin called on end iterator");
        if (it == begin()) return;

        auto extracted = extract_node_and_link_prev_with_next(it.current_node_ptr);
        emplace_node_at_head(std::move(extracted));
    }

    void move_to_end(Iterator it) {
        raise_exception_if_empty();
        if (it == end()) throw std::out_of_range("move_to_end called on end iterator");

        auto extracted = extract_node_and_link_prev_with_next(it.current_node_ptr);
        emplace_node_at_tail(std::move(extracted));
    }

    template <typename... Args>
    void emplace_back(Args&&... args) {
        auto new_node = std::make_unique<Node<T>>(tail, nullptr, std::forward<Args>(args)...);
        link_new_back_node(std::move(new_node));
    }

private:
    void link_new_back_node(std::unique_ptr<Node<T>> new_node) {
        if (empty()) {
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
    void push_back_internal(U&& value) {
        auto new_node = std::make_unique<Node<T>>(tail, nullptr, std::forward<U>(value));
        link_new_back_node(std::move(new_node));
    }

    template<typename U>
    void push_front_internal(U&& value) {
        auto new_node = std::make_unique<Node<T>>(nullptr, std::move(head), std::forward<U>(value));
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
        T value = std::move(node->value);
        node->next->prev = node->prev;
        node->prev->next = std::move(node->next);
        _size--;
        return value;
    }

    std::unique_ptr<Node<T>> extract_node_and_link_prev_with_next(Node<T>* node) {
        std::unique_ptr<Node<T>> extracted;
        
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        
        if (node->prev) {
            extracted = std::move(node->prev->next);
            node->prev->next = std::move(node->next);
        } else {
            extracted = std::move(head);
            head = std::move(node->next);
        }

        return extracted;
    }

    void emplace_node_at_head(std::unique_ptr<Node<T>> node){
        node->next = std::move(head);
        if (node->next) node->next->prev = node.get();
        head = std::move(node);
    }

    void emplace_node_at_tail(std::unique_ptr<Node<T>> node){
        node->prev = tail;
        tail = node.get();
        node->prev->next = std::move(node);
    }

    void raise_exception_if_empty() const {
        if (empty())
            throw std::out_of_range("Container is empty");
    }

    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    int _size;
};
