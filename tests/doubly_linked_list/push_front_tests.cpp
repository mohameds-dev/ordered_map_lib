#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"
#include "../tests_utils.hpp"


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

TEST_CASE("push_front 1, 2, push_back 3, back is 3", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_back(3);
    REQUIRE(list.back() == 3);
}

TEST_CASE("push_back 1, push_front 2, pop_back twice, size is 0", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_front(2);
    list.pop_back();
    list.pop_back();
    REQUIRE(list.size() == 0);
}

TEST_CASE("using move with push_front does not copy the value", "[push_front]") {
    DoublyLinkedList<MoveCopyFlag> list;
    auto object = MoveCopyFlag();
    list.push_front(std::move(object));

    REQUIRE(list.front().state == "default, moved");
}

TEST_CASE("passing variable by value to push_front copies the value", "[push_front]") {
    DoublyLinkedList<MoveCopyFlag> list;
    auto object = MoveCopyFlag();
    list.push_front(object);
    REQUIRE(list.front().state == "default, copied");
}