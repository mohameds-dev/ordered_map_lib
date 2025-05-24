#include "ordered_map.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("calling find on an empty map returns end()", "[find]") {
    OrderedMap<int, int> o_map;
    REQUIRE(o_map.find(1) == o_map.end());
}

TEST_CASE("calling find with a key that does not exist returns end()", "[find]") {
    OrderedMap<int, int> o_map;
    o_map.insert(1, 2);
    REQUIRE(o_map.find(2) == o_map.end());
}

TEST_CASE("calling find with a key that exists returns an iterator to the key", "[find]") {
    OrderedMap<int, int> o_map;
    o_map.insert(1, 2);
    auto it = o_map.find(1);

    REQUIRE(*it == std::make_pair(1, 2));
}



