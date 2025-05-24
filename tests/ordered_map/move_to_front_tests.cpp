#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"
#include "../tests_utils.hpp"

TEST_CASE("move_to_front on an empty map throws an exception", "[move_to_front]") {
    OrderedMap<int, int> map;
    REQUIRE_THROWS_AS(map.move_to_front(1), std::out_of_range);
}

TEST_CASE("move_to_front on a map with one element has the same element at the front", "[move_to_front]") {
    OrderedMap<int, int> map;
    map.insert(1, 0);
    map.move_to_front(1);
    REQUIRE(map.begin()->first == 1);
}

TEST_CASE("move_to_front on a map with two elements moves the element to the front", "[move_to_front]") {
    OrderedMap<int, int> map;
    map.insert(1, 0);
    map.insert(2, 0);
    map.move_to_front(2);
    REQUIRE(map.begin()->first == 2);
}



