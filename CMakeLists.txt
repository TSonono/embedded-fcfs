cmake_minimum_required(VERSION 3.4)
project(fcfs)

set(FCFS_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(FCFS_EXTERNAL_DIR ${FCFS_ROOT}/external)
set(FCFS_CMOCK_DIR ${FCFS_EXTERNAL_DIR}/cmock)
set(FCFS_UNITY_DIR ${FCFS_CMOCK_DIR}/vendor/unity)
set(FCFS_LWRB_DIR ${FCFS_EXTERNAL_DIR}/lwrb/lwrb)

option(FCFS_WITH_COVERAGE "Enable coverage output" Off)
option(FCFS_BUILD_TESTS "Build the tests" Off)
option(STACK_USAGE_32 "Build in 32-bit mode and get stack usage info" Off)

set(CMAKE_MODULE_PATH "${FCFS_EXTERNAL_DIR}/sanitizers-cmake/cmake;${FCFS_EXTERNAL_DIR}/cmake-modules;${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

if(FCFS_WITH_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif(FCFS_WITH_COVERAGE)

find_package(Sanitizers)

enable_testing()

if(STACK_USAGE_32)
    add_compile_options(-fstack-usage -m32)
endif(STACK_USAGE_32)

add_subdirectory(src)
if(FCFS_BUILD_TESTS)
    include(cmake/cmock.cmake)
    add_subdirectory(test)
endif(FCFS_BUILD_TESTS)
