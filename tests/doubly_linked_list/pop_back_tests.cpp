#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"


TEST_CASE("push_back 1, pop_back once, size = 0", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.pop_back();
    REQUIRE(list.size() == 0);
}

TEST_CASE("push_back 1, pop_back returns 1", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.pop_back() == 1);
}

TEST_CASE("push_back 1, 2, pop_back returns 2", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.pop_back() == 2);
}

TEST_CASE("pop_back on an empty list throws an exception", "[pop_back]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.pop_back(), std::out_of_range);
}


TEST_CASE("push_back 1, 2, pop_back once, size = 1", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    REQUIRE(list.size() == 1);
}

TEST_CASE("push_back 1, 2, 3, pop_back once, back return 2", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    REQUIRE(list.back() == 2);
}

TEST_CASE("push_back 1, 2, 3, pop_back twice, back return 1", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    list.pop_back();
    REQUIRE(list.back() == 1);
}

TEST_CASE("push_back 1, 2, 3, pop_back once, front return 1", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    REQUIRE(list.front() == 1);
}
