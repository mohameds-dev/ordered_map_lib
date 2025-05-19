#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"


TEST_CASE("calling clear method on a non-empty list makes size = 0", "[clear]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    REQUIRE(list.size() == 0);
}

TEST_CASE("calling clear on a non-empty list then accessing the front throws an error", "[clear]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.clear();
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
}

TEST_CASE("calling clear on a non-empty list then accessing the back throws an error", "[clear]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.clear();
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}

