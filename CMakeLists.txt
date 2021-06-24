cmake_minimum_required(VERSION 3.4)
project(fcfs)

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
set(CMOCK_DIR ${EXTERNAL_DIR}/cmock)
set(UNITY_DIR ${CMOCK_DIR}/vendor/unity)
set(LWRB_DIR ${EXTERNAL_DIR}/lwrb/lwrb)

option(WITH_COVERAGE "Enable coverage output" Off)
option(BUILD_TESTS "Build the tests" Off)

set(CMAKE_MODULE_PATH "${EXTERNAL_DIR}/sanitizers-cmake/cmake;${EXTERNAL_DIR}/cmake-modules;${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

if(WITH_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif(WITH_COVERAGE)

find_package(Sanitizers)

enable_testing()

add_subdirectory(src)
if(BUILD_TESTS)
    include(cmake/cmock.cmake)
    add_subdirectory(test)
endif(BUILD_TESTS)
