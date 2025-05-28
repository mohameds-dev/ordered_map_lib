#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"
#include "../tests_utils.hpp"

TEST_CASE("clear on an empty map does nothing and empty returns true", "[clear]") {
    OrderedMap<int, int> o_map;
    o_map.clear();
    REQUIRE(o_map.empty());
}

TEST_CASE("clear on a non-empty map clears the map and empty returns true", "[clear]") {
    OrderedMap<int, int> o_map;
    o_map.insert(1, 1);
    o_map.clear();
    REQUIRE(o_map.empty());
}
