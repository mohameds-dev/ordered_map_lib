cmake_minimum_required(VERSION 3.10)
project(ordered_map LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_library(ordered_map src/doubly_linked_list.cpp)
target_include_directories(ordered_map PUBLIC include)

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
  tests/doubly_linked_list/front_and_back.cpp
  tests/doubly_linked_list/iterator_tests.cpp
  tests/doubly_linked_list/pop_back_tests.cpp
  tests/doubly_linked_list/pop_front_tests.cpp
  tests/doubly_linked_list/push_back_tests.cpp
  tests/doubly_linked_list/push_front_tests.cpp
)
target_link_libraries(tests PRIVATE ordered_map Catch2::Catch2WithMain)

# Register tests
include(CTest)
include(Catch)
catch_discover_tests(tests)