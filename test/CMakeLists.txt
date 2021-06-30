set(MOCKS_DIR ${FCFS_ROOT}/mocks)
create_mock(${CMAKE_CURRENT_SOURCE_DIR}/events.h)

add_library(unity ${FCFS_UNITY_DIR}/src/unity.c)
target_include_directories(unity PUBLIC ${FCFS_UNITY_DIR}/src)

add_library(cmock ${FCFS_CMOCK_DIR}/src/cmock.c)
target_include_directories(cmock PUBLIC ${FCFS_CMOCK_DIR}/src ${FCFS_UNITY_DIR}/src)

add_executable(fcfs_test test.c ${MOCKS_DIR}/Mockevents.c)
target_include_directories(fcfs_test PRIVATE ${MOCKS_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${FCFS_LWRB_DIR}/src/include)
target_link_libraries(fcfs_test PRIVATE unity cmock fcfs)
add_sanitizers(fcfs_test)

add_test(fcfs_test_suite fcfs_test)

if(FCFS_WITH_COVERAGE)
    setup_target_for_coverage_lcov(
        NAME coverage
        EXECUTABLE ctest
        EXCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/*" "${FCFS_EXTERNAL_DIR}/*" "${MOCKS_DIR}/*")
endif(FCFS_WITH_COVERAGE)
