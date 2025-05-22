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

TEST_CASE("ordered map constructed with vector of pairs iterator maintains order", "[constructor]"){
    std::vector<std::pair<const std::string, int >> vec;
    for (int i = 0; i < 1000; i++) {
        vec.push_back({std::to_string(i), i});
    }
    
    OrderedMap<std::string, int> o_map(vec.begin(), vec.end());
    
    auto it_map = o_map.begin();
    auto it_vec = vec.begin();
    while (it_map != o_map.end() && it_vec != vec.end()) {
        REQUIRE(it_map->first == it_vec->first);
        REQUIRE(it_map->second == it_vec->second);
        it_map++;
        it_vec++;
    }
    REQUIRE(it_map == o_map.end());
    REQUIRE(it_vec == vec.end());
}

TEST_CASE("ordered map constructed with map iterators contains the given values", "[constructor]"){
    std::map<const int, int> map = {{1, 2}, {3, 4}};
    OrderedMap<int, int> o_map(map.begin(), map.end());
    REQUIRE(o_map.at(1) == 2);
    REQUIRE(o_map.at(3) == 4);
}

