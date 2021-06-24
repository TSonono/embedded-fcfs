add_executable(fcfs_test test.c)

add_sanitizers(fcfs_test)

add_test(fcfs_test_suite fcfs_test)

if(WITH_COVERAGE)
    setup_target_for_coverage_lcov(
        NAME coverage
        EXECUTABLE ctest
        EXCLUDE "${CMAKE_SOURCE_DIR}/src/*" "${EXTERNAL_DIR}/*")
endif(WITH_COVERAGE)
