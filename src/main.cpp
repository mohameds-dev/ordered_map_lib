#include "ordered_map.hpp"
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    // Create an ordered map
    OrderedMap<std::string, int> map;

    // Insert key-value pairs
    map.insert("apple", 1);
    map.insert("banana", 2);
    map.insert("cherry", 3);

    // Access values
    int value = map["apple"];  // Returns 1

    // Iterate in insertion order
    for (const auto& pair : map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    return 0;
}
