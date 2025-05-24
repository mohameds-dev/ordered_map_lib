#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"
#include "../tests_utils.hpp"

TEST_CASE("emplace_back one value in an empty list makes size = 1", "[emplace_back]") {
    DoublyLinkedList<int> list;
    list.emplace_back(1);
    REQUIRE(list.size() == 1);
}

TEST_CASE("emplace_back one pair in an empty list makes size = 1", "[emplace_back]") {
    DoublyLinkedList<std::pair<int, int>> list;
    list.emplace_back(1, 2);
    REQUIRE(list.size() == 1);
}
