cmake_minimum_required(VERSION 3.10)
project(ordered_map_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create an INTERFACE library since this is header-only
add_library(ordered_map_lib INTERFACE)
target_include_directories(ordered_map_lib INTERFACE include)

# Enable testing
enable_testing()

# Find or fetch Catch2
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(catch2)

# Add test executable
add_executable(
  tests
  tests/doubly_linked_list/size_tests.cpp
  tests/doubly_linked_list/front_and_back.cpp
  tests/doubly_linked_list/iterator_tests.cpp
  tests/doubly_linked_list/pop_back_tests.cpp
  tests/doubly_linked_list/pop_front_tests.cpp
  tests/doubly_linked_list/push_back_tests.cpp
  tests/doubly_linked_list/push_front_tests.cpp
  tests/doubly_linked_list/constructor_tests.cpp
  tests/doubly_linked_list/clear_tests.cpp
  tests/doubly_linked_list/erase_tests.cpp
  tests/doubly_linked_list/move_to_begin_tests.cpp
  tests/doubly_linked_list/emplace_back_tests.cpp
  tests/ordered_map/size_tests.cpp
  tests/ordered_map/insertion_tests.cpp
  tests/ordered_map/lookup_tests.cpp
  tests/ordered_map/iterator_tests.cpp
  tests/ordered_map/constructor_tests.cpp
  tests/ordered_map/find_tests.cpp
  tests/ordered_map/clear_tests.cpp
  tests/ordered_map/move_to_front_tests.cpp
)
target_link_libraries(tests PRIVATE ordered_map_lib Catch2::Catch2WithMain)

# Register tests
include(CTest)
include(Catch)
catch_discover_tests(tests)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE ordered_map_lib)