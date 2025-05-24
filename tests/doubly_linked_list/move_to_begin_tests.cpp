#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"
#include "../tests_utils.hpp"

TEST_CASE("move_to_front on an empty list throws an exception", "[move_to_front]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.move_to_begin(list.begin()), std::out_of_range);
}

TEST_CASE("push_back 1, 2,move_to_front with end iterator throws an exception", "[move_to_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE_THROWS_AS(list.move_to_begin(list.end()), std::out_of_range);
}

TEST_CASE("push_back 1, 2, move_to_front with begin iterator does nothing", "[move_to_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.move_to_begin(list.begin());
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 2);
}

TEST_CASE("push_back 1, 2, move_to_front with iterator to 2 moves 2 to front", "[move_to_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    auto it = list.end();
    list.move_to_begin(--it);
    REQUIRE(list.front() == 2);
    REQUIRE(list.back() == 1);
}

TEST_CASE("push_back 1, 2, 3, move_to_begin with iterator to 2 moves 2 to front", "[move_to_begin]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.begin();
    list.move_to_begin(++it);

    REQUIRE(list.front() == 2);
    REQUIRE(*++it == 1);
    REQUIRE(list.back() == 3);
}