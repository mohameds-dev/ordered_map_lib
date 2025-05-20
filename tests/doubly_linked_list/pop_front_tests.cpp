#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"


TEST_CASE("push_back 1, 2, pop_front once, size is 1", "[pop_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    REQUIRE(list.size() == 1);
}

TEST_CASE("push_front 1, pop_front returns 1", "[pop_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    REQUIRE(list.pop_front() == 1);
}

TEST_CASE("push_front 1, 2, pop_front returns 2", "[pop_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    REQUIRE(list.pop_front() == 2);
}

TEST_CASE("push_back 1, 2, 3, pop_front once, front is 2", "[pop_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    REQUIRE(list.front() == 2);
}


TEST_CASE("pop_front on an empty list throws an exception", "[pop_front]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.pop_front(), std::out_of_range);
}

TEST_CASE("pop_front clears tail when list becomes empty", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(42);
    list.pop_front();
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}

TEST_CASE("push_back 1, pop_back, push_front 2, pop front returns 2", "[pop_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.pop_back();
    list.push_front(2);
    REQUIRE(list.pop_front() == 2);
}