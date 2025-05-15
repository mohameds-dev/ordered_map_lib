#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"

TEST_CASE("Canary test", "[canary]") {
    REQUIRE(true);
}

TEST_CASE("Test push_back one value in an empty list makes size = 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.size() == 1);
}

TEST_CASE("Test push_back two values in an empty list makes size = 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.size() == 2);
}

TEST_CASE("Test push_back 1, 2 and front returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.front() == 1);
}

TEST_CASE("Test push_back 2, 1 and front returns 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    REQUIRE(list.front() == 2);
}

TEST_CASE("Test push_back 1, 2 and back returns 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.back() == 2);
}

TEST_CASE("Test push_back 2, 1 and back returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    REQUIRE(list.back() == 1);
}

TEST_CASE("Test push_back 1, pop_back once, size = 0", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.pop_back();
    REQUIRE(list.size() == 0);
}

TEST_CASE("Test push_back 1, pop_back returns 1", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.pop_back() == 1);
}

TEST_CASE("Test push_back 1, 2, pop_back returns 2", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.pop_back() == 2);
}

TEST_CASE("Test pop_back on an empty list throws an exception", "[pop_back]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS(list.pop_back());
}

TEST_CASE("Test front on an empty list throws an exception", "[front]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS(list.front());
}

TEST_CASE("Test back on an empty list throws an exception", "[back]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS(list.back());
}

TEST_CASE("Test push_back 1, 2, pop_back once, size = 1", "[push_back, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    REQUIRE(list.size() == 1);
}

TEST_CASE("Test push_back 1, 2, 3, pop_back once, back return 2", "[push_back, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    REQUIRE(list.back() == 2);
}

TEST_CASE("Test push_back 1, 2, 3, pop_back twice, back return 1", "[push_back, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    list.pop_back();
    REQUIRE(list.back() == 1);
}

TEST_CASE("Test push_back 1, 2, 3, pop_back once, front return 1", "[push_back, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    REQUIRE(list.front() == 1);
}

TEST_CASE("Test push_front 1, size = 1", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    REQUIRE(list.size() == 1);
}

TEST_CASE("Test push_front 1, 2, size = 2", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    REQUIRE(list.size() == 2);
}

TEST_CASE("Test push_front 1, front returns 1", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    REQUIRE(list.front() == 1);
}

TEST_CASE("Test push_front 1, 2 and front returns 2", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    REQUIRE(list.front() == 2);
}

TEST_CASE("Test push_front 1, 2, push_back 3, back is 3", "[push_front, push_back]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_back(3);
    REQUIRE(list.back() == 3);
}

TEST_CASE("Test push_back 1, push_front 2, pop_back twice, size is 0", "[push_back, push_front, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_front(2);
    list.pop_back();
    list.pop_back();
    REQUIRE(list.size() == 0);
}

