
add_library(unity ${UNITY_DIR}/src/unity.c)
target_include_directories(unity PUBLIC ${UNITY_DIR}/src)

add_executable(fcfs_test test.c)
target_link_libraries(fcfs_test PRIVATE unity fcfs)
add_sanitizers(fcfs_test)

add_test(fcfs_test_suite fcfs_test)

if(WITH_COVERAGE)
    setup_target_for_coverage_lcov(
        NAME coverage
        EXECUTABLE ctest
        EXCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/*" "${EXTERNAL_DIR}/*")
endif(WITH_COVERAGE)
