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

TEST_CASE("insert <1, 2>, key 1 returns value of 2", "[insert, at]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    REQUIRE(o_map.at(1) == 2);
}

TEST_CASE("insert <hello, world>, key hello returns value of world", "[insert, at]") {
    ordered_map<std::string, std::string> o_map;
    o_map.insert("hello", "world");
    REQUIRE(o_map.at("hello") == "world");
}

TEST_CASE("insert <hello, world>, <hello, there>, key hello returns value of there", "[insert, at]") {
    ordered_map<std::string, std::string> o_map;
    o_map.insert("hello", "world");
    o_map.insert("hello", "there");
    REQUIRE(o_map.at("hello") == "there");
}










