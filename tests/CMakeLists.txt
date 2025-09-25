# Пытаемся найти GTest, но если не найдем - просто пропускаем тесты
find_package(GTest QUIET)

if(GTest_FOUND)
    message(STATUS "GTest found, building tests")
    add_executable(matrix_tests test_matrix.cpp)
    target_link_libraries(matrix_tests PRIVATE GTest::gtest_main matrix_lib)
    target_include_directories(matrix_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
    add_test(NAME matrix_tests COMMAND matrix_tests)
else()
    message(WARNING "GTest not found, skipping tests")
endif()
