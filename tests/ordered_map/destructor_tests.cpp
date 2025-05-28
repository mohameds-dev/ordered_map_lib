#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"
#include "../tests_utils.hpp"
#include <algorithm>

TEST_CASE("destructor of an empty map does nothing", "[destructor]") {
    {
        OrderedMap<int, int> o_map;
    }
}

TEST_CASE("destructor of a non-empty map destroys the values", "[destructor]") {
    bool destroyed1 = false, destroyed2 = false, destroyed3 = false;
    {
        OrderedMap<int, DestructionFlag> o_map = {
            {1, DestructionFlag(&destroyed1)},
            {2, DestructionFlag(&destroyed2)},
            {3, DestructionFlag(&destroyed3)}
        };
    }
    REQUIRE((destroyed1 and destroyed2 and destroyed3));
}

TEST_CASE("destructor of a map with 100,000 values destroys the values", "[destructor]") {
    bool destroyed[100000] = {};

    {
        OrderedMap<int, DestructionFlag> o_map = {};
        for (int i = 0; i < 100000; i++)
            o_map.insert(i, DestructionFlag(&destroyed[i]));
    }

    bool all_destroyed = std::all_of(destroyed, destroyed + 100000, [](bool flag) { return flag; });
    REQUIRE(all_destroyed);
}
