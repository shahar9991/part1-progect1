cmake_minimum_required(VERSION 3.14)
project("PART1-PROJECT1") # Replace “MyCalc” with your repo name
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
googletest
URL
https://github.com/google/googletest/archive/03597a01ee50ed
33e9dfd640b249b4be3799d395.zip
)
enable_testing()
set(SOURCE_FILES
src/HashGenerator2.cpp # this is where the code we want to test
src/FalsePositive.cpp # this is where the code we want to test
src/BloomFilter2.cpp # this is where the code we want to test
src/URLsHandler1.cpp # this is where the code we want to test
src/ArgsHandler1.cpp # this is where the code we want to test

)
set(TEST_FILES
        # this is the main for tests
        # this file contain the tests
        # this file contain the tests
tests/test_BloomFilter.cpp # this file contain the tests
        src/sockets.cpp # this file contain the tests



)
add_executable(CalcTests ${TEST_FILES})
# Link Google Test to the test executable
target_link_libraries(CalcTests PRIVATE gtest gtest_main pthread)
# Include the source directory for tests
target_include_directories(CalcTests PRIVATE src)
include(GoogleTest)
gtest_discover_tests(CalcTests)
