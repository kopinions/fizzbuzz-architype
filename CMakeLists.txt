cmake_minimum_required(VERSION 3.12)
project(fizzbuzz)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.10.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
    include_directories(${googletest_SOURCE_DIR}/googletest/include)
endif()

include(GoogleTest)
include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -std=gnu++17")

enable_testing()

macro(gtest TESTNAME)
    file(GLOB TEST_SRC "${CMAKE_CURRENT_LIST_DIR}/../src/*.cpp")
    add_executable(${TESTNAME} ${ARGN} ${TEST_SRC})
    target_link_libraries(${TESTNAME} PUBLIC gtest gmock gtest_main)

    gtest_discover_tests(${TESTNAME}
            TEST_PREFIX "${TESTNAME}."
            PROPERTIES FOLDER "tests")
endmacro()
#gtest(TestStudent TestStudent.cpp)
add_subdirectory(src)
add_subdirectory(tests)

add_executable(game main.cpp src/Student.cpp include/Student.h src/Teacher.cpp include/Teacher.h)