# Find GTest
find_package(GTest REQUIRED)

# Create test executable
add_executable(matrix_tests test_matrix.cpp)
target_link_libraries(matrix_tests GTest::gtest_main matrix_lib)
target_include_directories(matrix_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Add test
add_test(NAME matrix_tests COMMAND matrix_tests)
