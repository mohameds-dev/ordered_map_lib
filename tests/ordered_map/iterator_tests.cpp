#include <catch2/catch_test_macros.hpp>
#include "../include/ordered_map.hpp"

TEST_CASE("insert <1, 2>, begin iterator points to <1, 2>", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);

    REQUIRE(*o_map.begin() == std::make_pair(1, 2));
}

TEST_CASE("insert <1, 2>, <3, 4>, begin iterator points to <1, 2>", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);

    REQUIRE(*o_map.begin() == std::make_pair(1, 2));
}

TEST_CASE("insert <1, 2>, <3, 4>, using pre-increment (++it) on begin iterator makes it point to <3, 4>", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    o_map.insert(3, 4);

    auto it = o_map.begin();
    ++it;

    REQUIRE(*it == std::make_pair(3, 4));
}

TEST_CASE("insert <1, 2>, <3, 4>, using post-increment (it++) on begin iterator makes it point to <1, 2>", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);
    o_map.insert(3, 4);

    auto it = o_map.begin();
    it++;

    REQUIRE(*it == std::make_pair(3, 4));
}