#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"
#include <stdexcept>
#include "../tests_utils.hpp"

TEST_CASE("Canary test", "[canary]") {
    REQUIRE(true);
}

TEST_CASE("front on an empty list throws an exception", "[front]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
}

TEST_CASE("front on a list with one element returns the element", "[front]") {
    DoublyLinkedList<int> list = {1};
    REQUIRE(list.front() == 1);
}

TEST_CASE("front on a list with {1, 2} returns 1", "[front]") {
    DoublyLinkedList<int> list = {1, 2};
    REQUIRE(list.front() == 1);
}

TEST_CASE("front on a list with a MoveCopyFlag element returns the element without copying it", "[front]") {
    DoublyLinkedList<MoveCopyFlag> list;
    list.push_back(MoveCopyFlag());
    REQUIRE(list.front().state == "default, moved");
}

TEST_CASE("front on a list constructed with initializer list of MoveCopyFlag returns the element copied once", "[front]") {
    DoublyLinkedList<MoveCopyFlag> list = {MoveCopyFlag()};
    REQUIRE(list.front().state == "default, copied");
}

TEST_CASE("back on an empty list throws an exception", "[back]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}
