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

TEST_CASE("iterator (begin == end) is true when map is empty", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;

    REQUIRE(o_map.begin() == o_map.end());
}

TEST_CASE("iterator (begin == end) is false when map is not empty", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);

    REQUIRE(!(o_map.begin() == o_map.end()));
}

TEST_CASE("iterator (begin != end) is false when map is empty", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;

    REQUIRE(!(o_map.begin() != o_map.end()));
}

TEST_CASE("iterator (begin != end) is true when map is not empty", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);

    REQUIRE(o_map.begin() != o_map.end());
}

TEST_CASE("using for-loop with begin and end iterators to iterate over map yields correct results in order", "[ordered_map_iterator]") {
    std::vector<std::pair<int, int>> expected_results = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    ordered_map<int, int> o_map;
    for (const auto& pair : expected_results) {
        o_map.insert(pair.first, pair.second);
    }

    int i = 0;
    for (auto it = o_map.begin(); it != o_map.end(); it++) {
        REQUIRE(*it == expected_results[i]);
        i++;
    }
}

TEST_CASE("using for-each loop yields correct results in order", "[ordered_map_iterator]") {
    std::vector<std::pair<int, int>> expected_results = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    ordered_map<int, int> o_map;
    for (const auto& pair : expected_results) {
        o_map.insert(pair.first, pair.second);
    }

    int i = 0;
    for (auto& pair : o_map) {
        REQUIRE(pair == expected_results[i]);
        i++;
    }
}

TEST_CASE("back_iterator() throws out_of_range when map is empty", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;

    REQUIRE_THROWS_AS(o_map.back_iterator(), std::out_of_range);
}

TEST_CASE("insert <1, 2>, back_iterator points to <1, 2>", "[ordered_map_iterator]") {
    ordered_map<int, int> o_map;
    o_map.insert(1, 2);

    REQUIRE(*o_map.back_iterator() == std::make_pair(1, 2));
}

