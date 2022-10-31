cmake_minimum_required(VERSION 3.6)
project(cpplib)

set(SRC
    src/cpplib_lists.cpp
    src/cpplib_stack.cpp)

set(TEST_SRC
    test/test_main.cpp
    test/test_stack.cpp)

include_directories(./include/)

add_library(cpplib ${SRC})

add_executable(cpplib_tests ${TEST_SRC})
target_link_libraries(cpplib_tests cpplib)

