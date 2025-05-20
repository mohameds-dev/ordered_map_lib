#pragma once
#include "doubly_linked_list.hpp"
#include <unordered_map>

template <typename K, typename V>
class ordered_map {
private:
    DoublyLinkedList<V> _list;
    std::unordered_map<K, typename DoublyLinkedList<V>::Iterator> _map;
    int _size = 0;
public:
    ordered_map() {}
    void insert(const K& key, const V& value) {
        if (_map.find(key) == _map.end()) {
            _list.push_back(value);
            _map[key] = _list.back_iterator();
            _size++;
        }
        else {
            *_map.find(key)->second = value;
        }
    }

    unsigned int size() const {
        return _size;
    }

    V& at(const K& key) {
        return *_map[key];
    }

};