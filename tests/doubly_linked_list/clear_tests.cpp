#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"
#include <stdexcept>

TEST_CASE("calling clear method on a non-empty list makes size = 0", "[clear]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    REQUIRE(list.size() == 0);
}

TEST_CASE("calling clear on a non-empty list then accessing the front throws an error", "[clear]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.clear();
    REQUIRE_THROWS_AS(list.front(), std::out_of_range);
}

TEST_CASE("calling clear on a non-empty list then accessing the back throws an error", "[clear]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.clear();
    REQUIRE_THROWS_AS(list.back(), std::out_of_range);
}


class TestClass {
public:
    bool *ref;

    TestClass(bool *a_ref) : ref(a_ref) {}
    ~TestClass() { (*ref) = true; }
};

TEST_CASE("calling clear on a list of custom class objects makes the destructor called", "[clear]") {
    class TestClass {
    public:
        bool *ref;

        TestClass(bool *a_ref) : ref(a_ref) {}
        ~TestClass() { (*ref) = true; }
    };
    
    DoublyLinkedList<TestClass> list;
    bool deletion_flag = false;
    list.push_back(TestClass(&deletion_flag));
    list.clear();
    REQUIRE(deletion_flag == true);
}

TEST_CASE("calling clear after pushing 100 elements makes size = 0", "[size]") {
    DoublyLinkedList<int> list;
    for (int i = 0; i < 100; i++) {
        list.push_back(i);
    }
    REQUIRE(list.size() == 100);
    list.clear();
    REQUIRE(list.size() == 0);
}
