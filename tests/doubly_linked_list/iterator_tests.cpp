#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"


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

TEST_CASE("push_back 1, 2, using pre-increment (++it) on begin iterator to reach 2", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    auto it = list.begin();
    ++it;
    
    REQUIRE(*it == 2);
}

TEST_CASE("push_back 1, 2, 3, using pre-increment (++it) twice on begin iterator to reach 2", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.begin();
    ++it;
    ++it;

    REQUIRE(*it == 3);
}

TEST_CASE("push_back 1, 2, copy the iterator after using pre-increment (++it) on begin iterator to reach 2", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    auto it = list.begin();
    auto copied_it = ++it;
    
    REQUIRE(*copied_it == 2);
}


TEST_CASE("push_back 1, 2, using post-increment (it++) on begin iterator to reach 2", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    auto it = list.begin();
    it++;
    
    REQUIRE(*it == 2);
}

TEST_CASE("push_back 1, 2, 3, using post-increment (it++) on begin iterator to reach 2", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.begin();
    it++;

    REQUIRE(*it == 2);
}

TEST_CASE("push_back 1, 2, copy the iterator after using post-increment (it++) on begin iterator", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    auto it = list.begin();
    auto copied_it = it++;

    REQUIRE(*copied_it == 1);
}

TEST_CASE("push back 1, 2, 3, iterate using for-loop with post-increment (it++) on begin iterator", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int counter = 1;
    
    for (auto it = list.begin(); it != list.end(); it++) {
        REQUIRE(*it == counter);
        counter++;
    }
}

TEST_CASE("push back 1, 2, 3, iterate using for-loop with pre-increment (++it) on begin iterator", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int counter = 1;

    for (auto it = list.begin(); it != list.end(); ++it) {
        REQUIRE(*it == counter);
        counter++;
    }
}

TEST_CASE("push back 1, 2, 3, iterate using for-loop with for-each syntax", "[iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int counter = 1;

    for (auto it : list) {
        REQUIRE(it == counter);
        counter++;
    }
}

TEST_CASE("push_back 1, dereferencing back iterator returns 1", "[back_iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    auto it = list.back_iterator();

    REQUIRE(*it == 1);
}

TEST_CASE("push_back 1, 2, dereferencing back iterator returns 2", "[back_iterator]") {
    DoublyLinkedList<int> list;
    list.push_back(1); list.push_back(2);
    auto it = list.back_iterator();

    REQUIRE(*it == 2);
}

