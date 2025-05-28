#include <catch2/catch_test_macros.hpp>
#include "../include/ordered_map.hpp"
#include <stdexcept>


TEST_CASE("dereferencing end() in a non-empty map throws an exception", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}};

    REQUIRE_THROWS_AS(*o_map.end(), std::out_of_range);
}

TEST_CASE("dereferencing begin() in an empty map throws an exception", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map;

    REQUIRE_THROWS_AS(*o_map.begin(), std::out_of_range);
}



TEST_CASE("map containing 1 entry {1, 2}, dereferencing begin() returns {1, 2}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}};

    REQUIRE(*o_map.begin() == std::make_pair(1, 2));
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, dereferencing begin() returns {1, 2}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};

    REQUIRE(*o_map.begin() == std::make_pair(1, 2));
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, using pre-increment (++it) on begin iterator makes it point to {3, 4}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    auto it = o_map.begin();
    ++it;

    REQUIRE(*it == std::make_pair(3, 4));
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, using post-increment (it++) on begin iterator makes it point to {3, 4}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    auto it = o_map.begin();
    it++;

    REQUIRE(*it == std::make_pair(3, 4));
}

TEST_CASE("map is empty, begin == end returns true", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map;

    REQUIRE(o_map.begin() == o_map.end());
}

TEST_CASE("map containing 1 entry {1, 2}, begin == end returns false", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}};

    REQUIRE(!(o_map.begin() == o_map.end()));
}

TEST_CASE("map is empty, begin != end returns false", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map;

    REQUIRE(!(o_map.begin() != o_map.end()));
}

TEST_CASE("map containing 1 entry {1, 2}, begin != end returns true", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}};

    REQUIRE(o_map.begin() != o_map.end());
}

TEST_CASE("map containing 3 entries {1, 2}, {2, 3}, {3, 4}, using for-loop with begin and end iterators to iterate over map yields correct results in order", "[ordered_map_iterator]") {
    std::vector<std::pair<int, int>> expected_results = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    OrderedMap<int, int> o_map(expected_results.begin(), expected_results.end());


    int i = 0;
    for (auto it = o_map.begin(); it != o_map.end(); it++) {
        REQUIRE(*it == expected_results[i++]);
    }

    REQUIRE(i == expected_results.size());
}

TEST_CASE("using for-each loop yields correct results in order", "[ordered_map_iterator]") {
    std::vector<std::pair<int, int>> expected_results = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    OrderedMap<int, int> o_map(expected_results.begin(), expected_results.end());
    int i = 0;
    for (auto& pair : o_map) {
        REQUIRE(pair == expected_results[i++]);
    }
}

TEST_CASE("back_iterator() throws out_of_range when map is empty", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map;

    REQUIRE_THROWS_AS(o_map.back_iterator(), std::out_of_range);
}

TEST_CASE("map containing 1 entry {1, 2}, back_iterator points to {1, 2}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}};

    REQUIRE(*o_map.back_iterator() == std::make_pair(1, 2));
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, back_iterator points to {3, 4}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};

    REQUIRE(*o_map.back_iterator() == std::make_pair(3, 4));
}

TEST_CASE("using post-increment operator on end iterator in a non-empty map throws an exception", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}};
    auto it = o_map.end();
    REQUIRE_THROWS_AS(it++, std::out_of_range);
}

TEST_CASE("using pre-increment operator on begin iterator in an empty map throws an exception", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map;
    auto it = o_map.begin();
    REQUIRE_THROWS_AS(++it, std::out_of_range);
}

TEST_CASE("using pre-decrement operator on end iterator in an empty map throws an exception", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map;
    auto it = o_map.end();
    REQUIRE_THROWS_AS(--it, std::out_of_range);
}

TEST_CASE("using post-decrement operator on end() in an empty map throws an exception", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map;
    auto it = o_map.end();
    REQUIRE_THROWS_AS(it--, std::out_of_range);
}

TEST_CASE("map containing 1 entry {1, 2}, using pre-decrement operator on end() points to {1, 2}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}};
    auto it = o_map.end();
    --it;

    REQUIRE(*it == std::make_pair(1, 2));
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, using pre-decrement operator on end() twice points to {1, 2}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    auto it = o_map.end();
    --it;
    --it;

    REQUIRE(*it == std::make_pair(1, 2));
}

TEST_CASE("map containing 1 entry {1, 2}, using post-decrement operator on end() points to {1, 2}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}};
    auto it = o_map.end();
    it--;

    REQUIRE(*it == std::make_pair(1, 2));
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, using post-decrement operator on end() twice points to {1, 2}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    auto it = o_map.end();
    it--;
    it--;

    REQUIRE(*it == std::make_pair(1, 2));
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, post-decrement operator on end() returns end() iterator", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    auto it = o_map.end();
    auto copied_it = it--;

    REQUIRE(copied_it == o_map.end());
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, post-decrement operator on end() returns different object", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    auto it = o_map.end();
    auto copied_it = it--;

    REQUIRE(copied_it != it);
}

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, pre-decrement operator on end() returns iterator pointing to {3, 4}", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    auto it = o_map.end();
    auto copied_it = --it;

    REQUIRE(*copied_it == std::make_pair(3, 4));
}   

TEST_CASE("map containing 2 entries {1, 2}, {3, 4}, pre-decrement operator on end() returns same initial object", "[ordered_map_iterator]") {
    OrderedMap<int, int> o_map = {{1, 2}, {3, 4}};
    auto it = o_map.end();
    auto copied_it = --it;

    REQUIRE(copied_it == it);
}
