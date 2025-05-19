#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"


TEST_CASE("push_back one value in an empty list makes size = 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.size() == 1);
}

TEST_CASE("push_back two values in an empty list makes size = 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.size() == 2);
}

TEST_CASE("push_back 1 and front returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.front() == 1);
}

TEST_CASE("push_back 1, 2 and front returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.front() == 1);
}


TEST_CASE("push_back 2, 1 and front returns 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    REQUIRE(list.front() == 2);
}


TEST_CASE("push_back 1, and back returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.back() == 1);
}

TEST_CASE("push_back 1, 2 and back returns 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.back() == 2);
}


TEST_CASE("push_back 2, 1 and back returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    REQUIRE(list.back() == 1);
}
