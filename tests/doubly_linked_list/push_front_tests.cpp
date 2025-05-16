#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"



TEST_CASE("push_front 1, size = 1", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    REQUIRE(list.size() == 1);
}

TEST_CASE("push_front 1, 2, size = 2", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    REQUIRE(list.size() == 2);
}

TEST_CASE("push_front 1, front returns 1", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    REQUIRE(list.front() == 1);
}

TEST_CASE("push_front 1, 2 and front returns 2", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    REQUIRE(list.front() == 2);
}

TEST_CASE("push_front 1, 2, push_back 3, back is 3", "[push_front, push_back]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_back(3);
    REQUIRE(list.back() == 3);
}

TEST_CASE("push_back 1, push_front 2, pop_back twice, size is 0", "[push_back, push_front, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_front(2);
    list.pop_back();
    list.pop_back();
    REQUIRE(list.size() == 0);
}
