cmake_minimum_required(VERSION 3.0)
project(fcfs)

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
set(UNITY_DIR ${EXTERNAL_DIR}/Unity)
set(LWRB_DIR ${EXTERNAL_DIR}/lwrb/lwrb)

set(CMAKE_MODULE_PATH "${EXTERNAL_DIR}/sanitizers-cmake/cmake;${EXTERNAL_DIR}/cmake-modules" ${CMAKE_MODULE_PATH})

if(WITH_COVERAGE)
    find_program(LLVMCOV_PATH llvm-cov)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        if(LLVMCOV_PATH)
            set(GCOV_PATH "${CMAKE_CURRENT_SOURCE_DIR}/llvm-cov.sh")
        endif(LLVMCOV_PATH)
    endif()
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif(WITH_COVERAGE)

find_package(Sanitizers)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
