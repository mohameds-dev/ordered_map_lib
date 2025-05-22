#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"

TEST_CASE("size is 0 when map is empty", "[size]") {
    OrderedMap<int, int> map;
    REQUIRE(map.size() == 0);
}

TEST_CASE("size is 1 after inserting one element", "[size]") {
    OrderedMap<int, int> map;
    map.insert(1, 2);
    REQUIRE(map.size() == 1);
}

TEST_CASE("size is 2 after inserting two elements", "[size]") {
    OrderedMap<int, int> map;
    map.insert(1, 2);
    map.insert(3, 4);
    REQUIRE(map.size() == 2);
}

TEST_CASE("size is 100,000 after inserting 100,000 elements", "[size]") {
    OrderedMap<int, int> map;
    int size = int(1e5);
    for (int i = 0; i < size; i++) {
        map.insert(i, i);
    }
    REQUIRE(map.size() == size);
}

TEST_CASE("empty() returns true when map is empty", "[empty]") {
    OrderedMap<int, int> map;
    REQUIRE(map.empty());
}

TEST_CASE("empty() returns false when map is not empty", "[empty]") {
    OrderedMap<int, int> map;
    map.insert(1, 2);
    REQUIRE(!map.empty());
}
