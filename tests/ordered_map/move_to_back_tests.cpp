#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"
#include "../tests_utils.hpp"

TEST_CASE("move_to_back() on an empty map throws an exception", "[move_to_back]") {
    OrderedMap<int, int> o_map;
    REQUIRE_THROWS_AS(o_map.move_to_back(1), std::out_of_range);
}

TEST_CASE("move_to_back() given key not in map throws an exception", "[move_to_back]") {
    OrderedMap<int, int> o_map = {{1, 1}, {2, 2}};
    REQUIRE_THROWS_AS(o_map.move_to_back(3), std::out_of_range);
}

TEST_CASE("map containing two entries {1, 1}, {2, 2}, move_to_back(1) makes {1, 1} at the back and {2, 2} at the front", "[move_to_back]") {
    OrderedMap<int, int> o_map = {{1, 1}, {2, 2}};
    o_map.move_to_back(1);
    
    auto it = o_map.begin();
    REQUIRE(it->first == 2);
    ++it;
    REQUIRE(it->first == 1);
}

TEST_CASE("map containing three entries {1, 1}, {2, 2}, {3, 3}, move_to_back(2) makes {2, 2} at the back and {1, 1} and {3, 3} at the front", "[move_to_back]") {
    OrderedMap<int, int> o_map = {
        {1, 1},
        {2, 2},
        {3, 3}
    };
    o_map.move_to_back(2);
    
    auto it = o_map.begin();
    REQUIRE(it->first == 1);
    ++it;
    REQUIRE(it->first == 3);
    ++it;
    REQUIRE(it->first == 2);
}

