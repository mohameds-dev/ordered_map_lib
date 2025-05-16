#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"


TEST_CASE("begin iterator equals end iterator in empty list", "[begin, end]") {
    DoublyLinkedList<int> list;
    REQUIRE(list.begin() == list.end());
}

TEST_CASE("push_back 1, begin iterator does not equal end iterator", "[begin, end]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(!(list.begin() == list.end()));
}

TEST_CASE("begin iterator != end iterator returns false in an empty list", "[begin, end]") {
    DoublyLinkedList<int> list;
    REQUIRE(!(list.begin() != list.end()));
}

TEST_CASE("push_back 1, begin iterator != end iterator returns false", "[begin, end]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.begin() != list.end());
}

TEST_CASE("push_back 1, begin iterator dereferences to 1", "[begin]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(*list.begin() == 1);
}

TEST_CASE("push_back 2, begin iterator dereferences to 2", "[begin]") {
    DoublyLinkedList<int> list;
    list.push_back(2);
    REQUIRE(*list.begin() == 2);
}

TEST_CASE("push_back hello string, modify string by dereferencing begin, front returns modified string", "[begin]") {
    DoublyLinkedList<std::string> list;
    list.push_back("hello");
    auto &str = *list.begin();
    str[0] = 'H';
    REQUIRE(*list.begin() == "Hello");
}
