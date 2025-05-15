add_executable(test_math test_math.cpp)
target_link_libraries(test_math PRIVATE Catch2::Catch2WithMain)
add_test(NAME MathTests COMMAND test_math) 