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

TEST_CASE("lookup key that does not exist in ordered map throws out_of_range exception", "[at]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    REQUIRE_THROWS_AS(o_map.at(2), std::out_of_range);
}

TEST_CASE("insert <1, 2>, operator[] returns value of 2", "[square_brackets]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    REQUIRE(o_map[1] == 2);
}

TEST_CASE("insert<hello,world>, map[hello] returns value of world", "[square_brackets]") {
    ordered_map<std::string, std::string> o_map;
    o_map.insert("hello", "world");
    REQUIRE(o_map["hello"] == "world");
}

TEST_CASE("using operator[] on an empty map makes the size = 1", "[square_brackets]") {
    ordered_map<int, int> o_map;
    o_map[1] = 2;
    REQUIRE(o_map.size() == 1);
}

TEST_CASE("using operator[1] on a key that does not exist in the map assigns default value of type int", "[square_brackets]") {
    ordered_map<int, int> o_map;
    o_map[1];
    REQUIRE(o_map.at(1) == int());
}

TEST_CASE("using operator[hello] on a key that does not exist in the map assigns default value of type string", "[square_brackets]") {
    ordered_map<std::string, std::string> o_map;
    o_map["hello"];
    REQUIRE(o_map.at("hello") == std::string());
}


