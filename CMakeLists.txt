cmake_minimum_required(VERSION 3.6)
project(cpplib)

set(SRC
    src/cpplib_lists.cc
    src/cpplib_stack.cc
    src/cpplib_string.cc)

set(TEST_SRC
    test/test_main.cc
    test/test_stack.cc
    test/test_helpers.cc
    test/test_string.cc
    test/test_array.cc
    test/test_vector.cc)

include_directories(./include/)

set(CMAKE_CXX_FLAGS "-Wall -Wshadow -std=c++14")

add_library(cpplib ${SRC})

add_executable(cpplib_tests ${TEST_SRC})
target_link_libraries(cpplib_tests cpplib)

