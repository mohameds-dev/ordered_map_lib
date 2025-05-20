#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"

TEST_CASE("size is 0 when list is empty", "[size]") {
    DoublyLinkedList<int> list;
    REQUIRE(list.size() == 0);
}

TEST_CASE("size is 1 after pushing one element", "[size]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.size() == 1);
}

TEST_CASE("size is 2 after pushing two elements", "[size]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.size() == 2);
}

TEST_CASE("empty() returns true when list is empty", "[empty]") {
    DoublyLinkedList<int> list;
    REQUIRE(list.empty());
}

TEST_CASE("empty() returns false when list is not empty", "[empty]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(!list.empty());
}
    






