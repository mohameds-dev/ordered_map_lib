#pragma once
#include "doubly_linked_list.hpp"
#include <unordered_map>
#include <stdexcept>


template <typename KeyType, typename ValueType>
class OrderedMap {    
public:
    OrderedMap() {}

    OrderedMap(std::initializer_list<std::pair<const KeyType, ValueType>> init_list){
        for (const auto& pair : init_list) {
            insert(pair.first, pair.second);
        }
    }

    template <typename ParamIterator>
    OrderedMap(ParamIterator begin, ParamIterator end){
        for (auto it = begin; it != end; it++) {
            insert(it->first, it->second);
        }
    }

    ~OrderedMap() {
        clear();
    }

    void insert(const KeyType& key, const ValueType& value) {
        if (_map.find(key) == _map.end()) {
            _list.emplace_back(key, value);
            _map[key] = _list.back_iterator();
        }
        else {
            (*_map[key]).second = value;
        }
    }

    void insert(const KeyType& key, ValueType&& value) {
        if (_map.find(key) == _map.end()) {
            _list.emplace_back(key, std::move(value));
            _map[key] = _list.back_iterator();
        }
        else {
            (*_map[key]).second = std::move(value);
        }
    }

    size_t size() const {
        return _list.size();
    }

    bool empty() const {
        return _list.empty();
    }
    
    void clear() {
        _list.clear();
        _map.clear();
    }

    size_t erase(const KeyType& key) {
        if (empty()) return 0;
        
        auto it = _map.find(key);
        if (it != _map.end()) {
            _list.erase(it->second);
            _map.erase(it);
            return 1;
        }
        return 0;
    }

    ValueType& at(const KeyType& key) {
        if (_map.find(key) == _map.end()) {
            throw std::out_of_range("Key not found in ordered map");
        }
        return (*_map[key]).second;
    }

    ValueType& operator[](const KeyType& key) {
        if (_map.find(key) == _map.end()) {
            this->insert(key, ValueType{});
        }
        return (*_map[key]).second;
    }


    using ListIterator = typename DoublyLinkedList<std::pair<KeyType, ValueType>>::Iterator;
    class Iterator {
        ListIterator _it;

        public:
        Iterator(ListIterator it) : _it(it) {}

        std::pair<KeyType, ValueType>& operator*() {
            return *_it;
        }

        std::pair<KeyType, ValueType>* operator->() {
            return &(*_it);
        }

        Iterator& operator++() {
            _it++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator initial_state_copy = *this;
            _it++;
            return initial_state_copy;
        }

        Iterator& operator--() {
            --_it;
            return *this;
        }

        Iterator operator--(int) {
            Iterator initial_state_copy = *this;
            _it--;
            return initial_state_copy;
        }

        bool operator==(const Iterator& other) const {
            return _it == other._it;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
        
        
    };

    Iterator begin() {
        return Iterator(_list.begin());
    }

    Iterator end() {
        return Iterator(_list.end());
    }

    bool empty() {
        return _list.empty();
    }

    Iterator back_iterator() {
        if (empty()) {
            throw std::out_of_range("Map is empty");
        }
        return Iterator(_list.back_iterator());
    }

    Iterator find(const KeyType& key) {
        return _map.find(key) == _map.end() ? end() : Iterator(_map[key]);
    }

    void move_to_front(const KeyType& key) {
        if (_map.find(key) == _map.end()) {
            throw std::out_of_range("Key not found in ordered map");
        }
        _list.move_to_begin(_map[key]);
    }

    void move_to_back(const KeyType& key) {
        if (_map.find(key) == _map.end()) {
            throw std::out_of_range("Key not found in ordered map");
        }
        _list.move_to_end(_map[key]);
    }

private:

    DoublyLinkedList<std::pair<KeyType, ValueType>> _list;
    std::unordered_map<KeyType, ListIterator> _map;

};