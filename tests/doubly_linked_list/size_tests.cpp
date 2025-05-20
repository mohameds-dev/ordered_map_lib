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

TEST_CASE("size is 100 after pushing 100 elements", "[size]") {
    DoublyLinkedList<int> list;
    for (int i = 0; i < 100; i++) {
        list.push_back(i);
    }
    REQUIRE(list.size() == 100);
}

TEST_CASE("size is 100000 after pushing 100000 elements", "[size]") {
    DoublyLinkedList<int> list;
    for (int i = 0; i < 100000; i++) {
        list.push_back(i);
    }
    REQUIRE(list.size() == 100000);
}

TEST_CASE("size is 1000,000 after pushing 1000,000 elements", "[size]") {
    DoublyLinkedList<int> list;
    int size = int(1e6);
    for (int i = 0; i < size; i++) {
        list.push_back(i);
    }
    REQUIRE(list.size() == size);
}






