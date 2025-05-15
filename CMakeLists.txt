cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_library(myproject src/doubly_linked_list.cpp)
target_include_directories(myproject PUBLIC include)

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
add_executable(tests tests/test_doubly_linked_list.cpp)
target_link_libraries(tests PRIVATE myproject Catch2::Catch2WithMain)

# Register tests
include(CTest)
include(Catch)
catch_discover_tests(tests)