cmake_minimum_required(VERSION 3.4)
project(fcfs)

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
set(CMOCK_DIR ${EXTERNAL_DIR}/cmock)
set(UNITY_DIR ${CMOCK_DIR}/vendor/unity)
set(LWRB_DIR ${EXTERNAL_DIR}/lwrb/lwrb)

option(WITH_COVERAGE "Enable coverage output" Off)
option(BUILD_TESTS "Build the tests" Off)
option(STACK_USAGE_32 "Build in 32-bit mode and get stack usage info" Off)

set(CMAKE_MODULE_PATH "${EXTERNAL_DIR}/sanitizers-cmake/cmake;${EXTERNAL_DIR}/cmake-modules;${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

if(WITH_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif(WITH_COVERAGE)

find_package(Sanitizers)

enable_testing()

if(STACK_USAGE_32)
    add_compile_options(-fstack-usage -m32)
endif(STACK_USAGE_32)

add_subdirectory(src)
if(BUILD_TESTS)
    include(cmake/cmock.cmake)
    add_subdirectory(test)
endif(BUILD_TESTS)
