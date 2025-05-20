#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"

TEST_CASE("empty ordered map has size 0", "[insert]") {
    ordered_map<int, int> o_map;
    REQUIRE(o_map.size() == 0);
}

TEST_CASE("inserting <1, 2> into an empty ordered map", "[insert]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    REQUIRE(o_map.size() == 1);
}

TEST_CASE("insert <1, 2> and <1, 3>, size = 1", "[insert]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    o_map.insert(1, 3);
    REQUIRE(o_map.size() == 1);
}

TEST_CASE("insert <1, 2> and <2, 3>, size = 2", "[insert]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    o_map.insert(2, 3);
    REQUIRE(o_map.size() == 2);
}

TEST_CASE("insert <1, 2>, key 1 returns value of 2", "[insert]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    REQUIRE(o_map.at(1) == 2);
}









