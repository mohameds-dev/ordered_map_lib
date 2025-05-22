#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"
#include <map>

TEST_CASE("empty ordered map has size 0", "[constructor]"){
    OrderedMap<int, int> o_map;
    REQUIRE(o_map.size() == 0);
}

TEST_CASE("ordered map constructed with initializer list has size 2", "[constructor]"){
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    REQUIRE(o_map.size() == 2);
}

TEST_CASE("ordered map with initializer list contains the given values", "[constructor]"){
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    REQUIRE(o_map.at(1) == 2);
    REQUIRE(o_map.at(3) == 4);
}

TEST_CASE("ordered map constructed with vector of pairs iterator contains the given values", "[constructor]"){
    std::vector<std::pair<const int, int>> vec = {{1, 2}, {3, 4}};
    OrderedMap<int, int> o_map(vec.begin(), vec.end());
    REQUIRE(o_map.at(1) == 2);
    REQUIRE(o_map.at(3) == 4);
}

TEST_CASE("ordered map constructed with map iterators contains the given values", "[constructor]"){
    std::map<const int, int> map = {{1, 2}, {3, 4}};
    OrderedMap<int, int> o_map(map.begin(), map.end());
    REQUIRE(o_map.at(1) == 2);
    REQUIRE(o_map.at(3) == 4);
}

