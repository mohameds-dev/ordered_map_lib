#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"

TEST_CASE("Canary test", "[canary]") {
    REQUIRE(true);
}

TEST_CASE("front on an empty list throws an exception", "[front]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
}

TEST_CASE("back on an empty list throws an exception", "[back]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}
