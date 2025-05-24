#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"
#include "../tests_utils.hpp"

TEST_CASE("move_to_front on an empty list throws an exception", "[move_to_front]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.move_to_begin(list.begin()), std::out_of_range);
}

TEST_CASE("list with 1, 2, move_to_front with end iterator throws an exception", "[move_to_front]") {
    DoublyLinkedList<int> list = {1, 2};
    REQUIRE_THROWS_AS(list.move_to_begin(list.end()), std::out_of_range);
}

TEST_CASE("list with 1, 2, move_to_front with begin iterator does nothing", "[move_to_front]") {
    DoublyLinkedList<int> list = {1, 2};
    list.move_to_begin(list.begin());
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 2);
}

TEST_CASE("list with 1, 2, move_to_front with iterator to 2 moves 2 to front", "[move_to_front]") {
    DoublyLinkedList<int> list = {1, 2};
    auto it = list.end();
    list.move_to_begin(--it);
    REQUIRE(list.front() == 2);
    REQUIRE(list.back() == 1);
}

TEST_CASE("list with 1, 2, 3, move_to_begin with iterator to 2 moves 2 to front", "[move_to_begin]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    auto it = list.begin();
    list.move_to_begin(++it);

    REQUIRE(list.front() == 2);
    REQUIRE(*++it == 1);
    REQUIRE(list.back() == 3);
}

TEST_CASE("list with 2 MoveCopyFlag elements, move_to_begin with iterator to 1st does nothing, no additional move or copy", "[move_to_begin]") {
    DoublyLinkedList<MoveCopyFlag> list;
    list.push_back(MoveCopyFlag());
    list.push_back(MoveCopyFlag());
    auto it = list.begin();
    list.move_to_begin(it);
    REQUIRE(list.front().state == "default, moved");
    REQUIRE(list.back().state == "default, moved");
}

TEST_CASE("list with 2 MoveCopyFlag elements constructed with move, move_to_begin with iterator to 2nd moves it to front with no additional move or copy", "[move_to_begin]") {
    DoublyLinkedList<MoveCopyFlag> list;
    list.push_back(MoveCopyFlag());
    list.push_back(MoveCopyFlag());
    auto it = list.begin();
    auto it_to_second_element = ++it;
    list.move_to_begin(it_to_second_element);
    
    REQUIRE(list.front().state == "default, moved");
}

TEST_CASE("list with 5 MoveCopyFlag elements copied via initializer list, move_to_begin with iterator to 3rd moves it to front with no additional move or copy", "[move_to_begin]") {
    DoublyLinkedList<MoveCopyFlag> list = {
        MoveCopyFlag(),
        MoveCopyFlag(),
        MoveCopyFlag(),
        MoveCopyFlag(),
        MoveCopyFlag()
    };
    auto it = list.begin(); ++it; ++it;
    list.move_to_begin(it);
    REQUIRE(list.front().state == "default, copied");
}

TEST_CASE("list with 5 strings, reversed using move_to_begin", "[move_to_begin]") {
    DoublyLinkedList<std::string> list = {"a", "b", "c", "d", "e"};
    auto it = list.begin();
    while(it != list.end()) {
        list.move_to_begin(it++);
    }
    
    it = list.begin();
    REQUIRE(*it++ == "e");
    REQUIRE(*it++ == "d");
    REQUIRE(*it++ == "c");
    REQUIRE(*it++ == "b");
    REQUIRE(*it++ == "a");
}

