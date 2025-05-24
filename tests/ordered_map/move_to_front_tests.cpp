#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"
#include "../tests_utils.hpp"

TEST_CASE("move_to_front on an empty map throws an exception", "[move_to_front]") {
    OrderedMap<int, int> o_map;
    REQUIRE_THROWS_AS(o_map.move_to_front(1), std::out_of_range);
}

TEST_CASE("move_to_front on a map with one element has the same element at the front", "[move_to_front]") {
    OrderedMap<int, int> o_map;
    o_map.insert(1, 0);
    o_map.move_to_front(1);
    REQUIRE(o_map.begin()->first == 1);
}

TEST_CASE("move_to_front on a map with two elements moves the element to the front", "[move_to_front]") {
    OrderedMap<int, int> o_map;
    o_map.insert(1, 0);
    o_map.insert(2, 0);
    o_map.move_to_front(2);
    
    REQUIRE(o_map.begin()->first == 2);
}

TEST_CASE("move_to_front does not copy the value", "[move_to_front]") {
    OrderedMap<int, MoveCopyFlag> o_map;
    o_map.insert(1, MoveCopyFlag());
    o_map.insert(2, MoveCopyFlag());
    o_map.move_to_front(2);

    REQUIRE(o_map.begin()->second.state == "default, moved");
}

TEST_CASE("map with 5 strings, move_to_front reverses the order of the elements") {
    OrderedMap<std::string, int> o_map = {
        {"a", 0},
        {"b", 0},
        {"c", 0},
        {"d", 0},
        {"e", 0}
    };
    
    auto it = o_map.begin();
    while (it != o_map.end()) {
        o_map.move_to_front((it++)->first);
    }
    
    it = o_map.begin();
    REQUIRE((it++)->first == "e");
    REQUIRE((it++)->first == "d");
    REQUIRE((it++)->first == "c");
    REQUIRE((it++)->first == "b");
    REQUIRE((it++)->first == "a");
}


