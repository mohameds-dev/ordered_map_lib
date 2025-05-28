#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"
#include "../tests_utils.hpp"

TEST_CASE("move_to_end() on an empty list throws an exception", "[move_to_end]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.move_to_end(list.begin()), std::out_of_range);
}

TEST_CASE("move_to_end() given end iterator throws an exception", "[move_to_end]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    REQUIRE_THROWS_AS(list.move_to_end(list.end()), std::out_of_range);
}

TEST_CASE("list containing {1, 2}, move_to_end on begin iterator moves 1 to back", "[move_to_end]") {
    DoublyLinkedList<int> list = {1, 2};
    list.move_to_end(list.begin());
    REQUIRE(list.front() == 2);
    REQUIRE(list.back() == 1);
}

TEST_CASE("list containing {1, 2, 3}, move_to_end on iterator to 2 makes front 1 and back 2", "[move_to_end]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    auto it = list.begin();
    ++it;
    list.move_to_end(it);

    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 2);
}

TEST_CASE("list containing 2 MoveCopyFlag objects, move_to_end on begin iterator moves object to back untouched", "[move_to_end]") {
    DoublyLinkedList<MoveCopyFlag> list = {MoveCopyFlag(), MoveCopyFlag()};
    list.move_to_end(list.begin());

    REQUIRE(list.front().state == "default, copied");
    REQUIRE(list.back().state == "default, copied");
}
