#include "doubly_linked_list.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("calling erase on an empty list throws an exception", "[erase]") {
    DoublyLinkedList<int> list;
    REQUIRE_THROWS_AS(list.erase(list.begin()), std::out_of_range);
}

TEST_CASE("push_back 1, call erase on end throws an exception", "[erase]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE_THROWS_AS(list.erase(list.end()), std::out_of_range);
}

TEST_CASE("push_back 1, call erase on begin returns end iterator", "[erase]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    REQUIRE(list.erase(list.begin()) == list.end());
}

TEST_CASE("push_back 1, call erase on begin makes the list empty", "[erase]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.erase(list.begin());
    REQUIRE(list.empty());
}

TEST_CASE("push_back 1, 2, call erase on begin makes the front equal 2", "[erase]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.erase(list.begin());
    REQUIRE(list.front() == 2);
}

TEST_CASE("push_back 1, 2, call erase on back_iterator makes back equal 1", "[erase]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.erase(list.back_iterator());
    REQUIRE(list.back() == 1);
}

TEST_CASE("push_back 1, 2, call erase on begin returns iterator to 2", "[erase]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    auto it = list.erase(list.begin());
    REQUIRE(*it == 2);
}

TEST_CASE("push_back 1, 2, 3, call erase on second element makes list size = 2", "[erase]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.begin(); list.erase(++it);

    REQUIRE(list.size() == 2);
}

TEST_CASE("push_back 1, 2, 3, call erase on second element front = 1, back = 3", "[erase]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.begin(); list.erase(++it);
    
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 3);
}

TEST_CASE("push_back 10,000 elements, erase all elements", "[erase]") {
    DoublyLinkedList<int> list;
    for (int i = 0; i < 10000; i++) {
        list.push_back(i);
    }

    auto it = list.begin();
    while (it != list.end()) {
        it = list.erase(it);
    }

    REQUIRE(list.empty());
}

TEST_CASE("push_back 10,000 elements, erase every other element", "[erase]") {
    DoublyLinkedList<int> list;
    for (int i = 0; i < 10000; i++) {
        list.push_back(i);
    }

    auto it = list.begin();
    while (it != list.end()) {
        it = list.erase(it);
        if (it != list.end()) {
            it++;
        }
    }

    REQUIRE(list.size() == 5000);
}

