#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"

TEST_CASE("Canary test", "[canary]") {
    REQUIRE(true);
}

TEST_CASE("push_back one value in an empty list makes size = 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.size() == 1);
}

TEST_CASE("push_back two values in an empty list makes size = 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.size() == 2);
}

TEST_CASE("push_back 1 and front returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.front() == 1);
}

TEST_CASE("push_back 1, 2 and front returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.front() == 1);
}

TEST_CASE("push_back 2, 1 and front returns 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    REQUIRE(list.front() == 2);
}

TEST_CASE("push_back 1, and back returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.back() == 1);
}

TEST_CASE("push_back 1, 2 and back returns 2", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.back() == 2);
}

TEST_CASE("push_back 2, 1 and back returns 1", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    REQUIRE(list.back() == 1);
}

TEST_CASE("push_back 1, pop_back once, size = 0", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.pop_back();
    REQUIRE(list.size() == 0);
}

TEST_CASE("push_back 1, pop_back returns 1", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.pop_back() == 1);
}

TEST_CASE("push_back 1, 2, pop_back returns 2", "[pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.pop_back() == 2);
}

TEST_CASE("pop_back on an empty list throws an exception", "[pop_back]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.pop_back(), std::out_of_range);
}

TEST_CASE("front on an empty list throws an exception", "[front]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
}

TEST_CASE("back on an empty list throws an exception", "[back]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}

TEST_CASE("push_back 1, 2, pop_back once, size = 1", "[push_back, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    REQUIRE(list.size() == 1);
}

TEST_CASE("push_back 1, 2, 3, pop_back once, back return 2", "[push_back, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    REQUIRE(list.back() == 2);
}

TEST_CASE("push_back 1, 2, 3, pop_back twice, back return 1", "[push_back, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    list.pop_back();
    REQUIRE(list.back() == 1);
}

TEST_CASE("push_back 1, 2, 3, pop_back once, front return 1", "[push_back, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    REQUIRE(list.front() == 1);
}

TEST_CASE("push_front 1, size = 1", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    REQUIRE(list.size() == 1);
}

TEST_CASE("push_front 1, 2, size = 2", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    REQUIRE(list.size() == 2);
}

TEST_CASE("push_front 1, front returns 1", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    REQUIRE(list.front() == 1);
}

TEST_CASE("push_front 1, 2 and front returns 2", "[push_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    REQUIRE(list.front() == 2);
}

TEST_CASE("push_front 1, 2, push_back 3, back is 3", "[push_front, push_back]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_back(3);
    REQUIRE(list.back() == 3);
}

TEST_CASE("push_back 1, push_front 2, pop_back twice, size is 0", "[push_back, push_front, pop_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_front(2);
    list.pop_back();
    list.pop_back();
    REQUIRE(list.size() == 0);
}

TEST_CASE("push_back 1, 2, pop_front once, size is 1", "[push_back, pop_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    REQUIRE(list.size() == 1);
}

TEST_CASE("push_front 1, pop_front returns 1", "[push_front, pop_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    REQUIRE(list.pop_front() == 1);
}

TEST_CASE("push_front 1, 2, pop_front returns 2", "[push_front, pop_front]") {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    REQUIRE(list.pop_front() == 2);
}

TEST_CASE("push_back 1, 2, 3, pop_front once, front is 2", "[push_back, pop_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    REQUIRE(list.front() == 2);
}

TEST_CASE("pop_front on an empty list throws an exception", "[pop_front]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.pop_front(), std::out_of_range);
}

TEST_CASE("pop_front clears tail when list becomes empty") {
    DoublyLinkedList<int> list;
    list.push_back(42);
    list.pop_front();
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}

TEST_CASE("push_back 1, pop_back, push_front 2, pop front returns 2", "[push_back, pop_back, push_front, pop_front]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.pop_back();
    list.push_front(2);
    REQUIRE(list.pop_front() == 2);
}

TEST_CASE("begin iterator equals end iterator in empty list", "[begin, end]") {
    DoublyLinkedList<int> list;
    REQUIRE(list.begin() == list.end());
}

TEST_CASE("push_back 1, begin iterator does not equal end iterator", "[begin, end]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(!(list.begin() == list.end()));
}

TEST_CASE("begin iterator != end iterator returns false in an empty list", "[begin, end]") {
    DoublyLinkedList<int> list;
    REQUIRE(!(list.begin() != list.end()));
}

TEST_CASE("push_back 1, begin iterator != end iterator returns false", "[begin, end]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.begin() != list.end());
}

TEST_CASE("push_back 1, begin iterator dereferences to 1", "[begin]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(*list.begin() == 1);
}

TEST_CASE("push_back 2, begin iterator dereferences to 2", "[begin]") {
    DoublyLinkedList<int> list;
    list.push_back(2);
    REQUIRE(*list.begin() == 2);
}

TEST_CASE("push_back hello string, modify string by dereferencing begin, front returns modified string", "[begin]") {
    DoublyLinkedList<std::string> list;
    list.push_back("hello");
    auto &str = *list.begin();
    str[0] = 'H';
    REQUIRE(*list.begin() == "Hello");
}
