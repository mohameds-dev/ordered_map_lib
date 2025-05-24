#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"
#include "../tests_utils.hpp"
#include <set>
TEST_CASE("Default constructor creates an empty list", "[constructor]") {
    DoublyLinkedList<int> list;
    REQUIRE(list.empty());
}

TEST_CASE("Constructor with initializer list {1, 2} creates a list with the elements in the initializer list", "[constructor]") {
    DoublyLinkedList<int> list = {1, 2};
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 2);
}

TEST_CASE("Constructor with initializer list {1, 2, 3, 4, 5} creates a list with the elements in the initializer list", "[constructor]") {
    DoublyLinkedList<int> list = {1, 2, 3, 4, 5};
    int value = 1;
    for (auto it = list.begin(); it != list.end(); ++it) {
        REQUIRE(*it == value++);
    }
}

TEST_CASE("Constructor with vector of size 10 creates a list with 10 elements", "[constructor]") {
    std::vector<int> vec(10);
    DoublyLinkedList<int> list(vec.begin(), vec.end());
    REQUIRE(list.size() == 10);
}

TEST_CASE("Constructor with vector {1, 2, 3, 4, 5} creates a list with the elements in the vector", "[constructor]") {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    DoublyLinkedList<int> list(vec.begin(), vec.end());
    
    auto vec_it = vec.begin();
    auto list_it = list.begin();

    while (vec_it != vec.end()) {
        REQUIRE(*list_it == *vec_it);
        ++vec_it; ++list_it;
    }
    REQUIRE(list_it == list.end());
    REQUIRE(vec_it == vec.end());
}

TEST_CASE("Constructor with set of strings creates a list with the elements in the set", "[constructor]") {
    std::set<std::string> set = {"hello", "world", "test"};
    DoublyLinkedList<std::string> list(set.begin(), set.end());
    
    auto set_it = set.begin();
    auto list_it = list.begin();

    while (set_it != set.end()) {
        REQUIRE(*list_it == *set_it);
        ++set_it; ++list_it;
    }
    REQUIRE(list_it == list.end());
    REQUIRE(set_it == set.end());
}
