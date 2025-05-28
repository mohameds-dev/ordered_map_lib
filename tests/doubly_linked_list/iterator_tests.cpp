#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"


TEST_CASE("begin iterator equals end iterator in empty list", "[iterator]") {
    DoublyLinkedList<int> list;
    REQUIRE(list.begin() == list.end());
}

TEST_CASE("list contains {1}, begin iterator does not equal end iterator", "[iterator]") {
    DoublyLinkedList<int> list = {1};
    REQUIRE(!(list.begin() == list.end()));
}

TEST_CASE("begin iterator != end iterator returns false in an empty list", "[iterator]") {
    DoublyLinkedList<int> list;
    REQUIRE(!(list.begin() != list.end()));
}

TEST_CASE("list contains {1}, begin iterator != end iterator returns false", "[iterator]") {
    DoublyLinkedList<int> list = {1};

    REQUIRE(list.begin() != list.end());
}

TEST_CASE("dereferencing end iterator throws an exception", "[iterator]") {
    DoublyLinkedList<int> list;
    auto it = list.end();

    REQUIRE_THROWS_AS(*it, std::out_of_range);
}

TEST_CASE("dereferencing begin iterator in an empty list throws an exception", "[iterator]") {
    DoublyLinkedList<int> list;
    auto it = list.begin();

    REQUIRE_THROWS_AS(*it, std::out_of_range);
}

TEST_CASE("list contains {1}, begin iterator dereferences to 1", "[begin]") {
    DoublyLinkedList<int> list = {1};

    REQUIRE(*list.begin() == 1);
}

TEST_CASE("list contains {2}, begin iterator dereferences to 2", "[begin]") {
    DoublyLinkedList<int> list = {2};

    REQUIRE(*list.begin() == 2);
}

TEST_CASE("list contains {hello}, modify string by dereferencing begin, front returns modified string", "[begin]") {
    DoublyLinkedList<std::string> list = {"hello"};
    auto &str = *list.begin();
    str[0] = 'H';

    REQUIRE(*list.begin() == "Hello");
}

TEST_CASE("using pre-decrement operator on end() in an empty list throws an exception", "[iterator]") {
    DoublyLinkedList<int> list;
    auto it = list.end();

    REQUIRE_THROWS_AS(--it, std::out_of_range);
}

TEST_CASE("using post-decrement operator on end() in an empty list throws an exception", "[iterator]") {
    DoublyLinkedList<int> list;
    auto it = list.end();

    REQUIRE_THROWS_AS(it--, std::out_of_range);
}

TEST_CASE("using pre-increment operator on end() in a non-empty list throws an exception", "[iterator]") {
    DoublyLinkedList<int> list = {1};
    auto it = list.end();

    REQUIRE_THROWS_AS(++it, std::out_of_range);
}


TEST_CASE("using pre-increment operator on begin() in an empty list throws an exception", "[iterator]") {
    DoublyLinkedList<int> list;
    auto it = list.begin();
    REQUIRE_THROWS_AS(++it, std::out_of_range);
}

TEST_CASE("using post-increment operator on begin() in an empty list throws an exception", "[iterator]") {
    DoublyLinkedList<int> list;
    auto it = list.begin();
    REQUIRE_THROWS_AS(it++, std::out_of_range);
}

TEST_CASE("list contains {1, 2}, using pre-increment (++it) on begin iterator to reach 2", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2};
    auto it = list.begin();
    ++it;
    
    REQUIRE(*it == 2);
}

TEST_CASE("list contains {1, 2, 3}, using pre-increment (++it) twice on begin iterator to reach 3", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    auto it = list.begin();
    ++it;
    ++it;

    REQUIRE(*it == 3);
}

TEST_CASE("list contains {1, 2}, copy the iterator after using pre-increment (++it) on begin iterator to reach 2", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2};
    auto it = list.begin();
    auto copied_it = ++it;
    
    REQUIRE(*copied_it == 2);
}

TEST_CASE("list contains {1, 2}, using post-increment (it++) on begin iterator to reach 2", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2};
    auto it = list.begin();
    it++;
    
    REQUIRE(*it == 2);
}

TEST_CASE("list contains {1, 2, 3}, using post-increment (it++) on begin iterator twice to reach 3", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    auto it = list.begin();
    it++;
    it++;


    REQUIRE(*it == 3);
}

TEST_CASE("list contains {1, 2}, copy the iterator after using post-increment (it++) on begin iterator", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2};
    auto it = list.begin();
    auto copied_it = it++;

    REQUIRE(*copied_it == 1);
}

TEST_CASE("list contains {1, 2, 3}, iterate using for-loop with post-increment (it++) on begin iterator", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    int counter = 1;
    
    for (auto it = list.begin(); it != list.end(); it++) {
        REQUIRE(*it == counter);
        counter++;
    }
}

TEST_CASE("list contains {1, 2, 3}, iterate using for-loop with pre-increment (++it) on begin iterator", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    int counter = 1;

    for (auto it = list.begin(); it != list.end(); ++it) {
        REQUIRE(*it == counter);
        counter++;
    }
}

TEST_CASE("list contains {1, 2, 3}, iterate using for-loop with for-each syntax", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    int counter = 1;

    for (auto it : list) {
        REQUIRE(it == counter);
        counter++;
    }
}

TEST_CASE("list contains {1}, dereferencing back iterator returns 1", "[back_iterator]") {
    DoublyLinkedList<int> list = {1};
    auto it = list.back_iterator();

    REQUIRE(*it == 1);
}

TEST_CASE("list contains {1, 2}, dereferencing back iterator returns 2", "[back_iterator]") {
    DoublyLinkedList<int> list = {1, 2};
    auto it = list.back_iterator();

    REQUIRE(*it == 2);
}

TEST_CASE("list contains {1, 2, 3}, using pre-decrement (--it) on end iterator points to 3", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    auto it = list.end();
    --it;

    REQUIRE(*it == 3);
}

TEST_CASE("list contains {1, 2, 3}, using post-decrement (it--) on end iterator points to 3", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    auto it = list.end();
    it--;

    REQUIRE(*it == 3);
}

TEST_CASE("list contains {1, 2, 3}, using pre-decrement (--it) on end iterator points to 2", "[iterator]") {
    DoublyLinkedList<int> list = {1, 2, 3};
    auto it = list.end();
    --it;
    --it;

    REQUIRE(*it == 2);
}
