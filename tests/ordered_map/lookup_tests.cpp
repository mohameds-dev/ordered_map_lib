#include "ordered_map.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("insert <1, 2>, key 1 returns value of 2", "[at]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    REQUIRE(o_map.at(1) == 2);
}

TEST_CASE("insert <hello, world>, key hello returns value of world", "[at]") {
    ordered_map<std::string, std::string> o_map;
    o_map.insert("hello", "world");
    REQUIRE(o_map.at("hello") == "world");
}

TEST_CASE("insert <hello, world>, <hello, there>, key hello returns value of there", "[at]") {
    ordered_map<std::string, std::string> o_map;
    o_map.insert("hello", "world");
    o_map.insert("hello", "there");
    REQUIRE(o_map.at("hello") == "there");
}