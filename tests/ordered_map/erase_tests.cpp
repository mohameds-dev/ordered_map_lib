#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"
#include "../tests_utils.hpp"

TEST_CASE("erase() on an empty map returns 0", "[erase]") {
    OrderedMap<int, int> o_map;
    REQUIRE(o_map.erase(1) == 0);
}

TEST_CASE("erase() on a non-empty map makes the size decrease by 1", "[erase]") {
    OrderedMap<int, int> o_map = {
        {1, 1},
        {2, 2},
        {3, 3}
    };
    o_map.erase(1);

    REQUIRE(o_map.size() == 2);
}

TEST_CASE("erase() an existing key returns 1", "[erase]") {
    OrderedMap<int, int> o_map = {
        {1, 1},
        {2, 2},
        {3, 3}
    };

    REQUIRE(o_map.erase(1) == 1);
}   

TEST_CASE("erase() a non-existing key returns 0", "[erase]") {
    OrderedMap<int, int> o_map = {
        {1, 1},
        {2, 2},
        {3, 3}
    };

    REQUIRE(o_map.erase(4) == 0);
}

TEST_CASE("erase() an existing key makes find() return end iterator", "[erase]") {
    OrderedMap<int, int> o_map = {
        {1, 1},
        {2, 2},
        {3, 3}
    };
    o_map.erase(1);

    REQUIRE(o_map.find(1) == o_map.end());
}

TEST_CASE("erase() a key leads to the destruction of the value", "[erase]") {
    bool destroyed = false;
    OrderedMap<int, DestructionFlag> o_map = {
        {1, DestructionFlag(&destroyed)}
    };
    o_map.erase(1);

    REQUIRE(destroyed);
}
