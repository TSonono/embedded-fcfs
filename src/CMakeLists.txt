
# Build dependencies (lwrb)
add_library(lwrb ${FCFS_LWRB_DIR}/src/lwrb/lwrb.c)
target_include_directories(lwrb PUBLIC ${FCFS_LWRB_DIR}/src/include)
add_sanitizers(lwrb)

add_library(fcfs fcfs.c)
target_include_directories(fcfs PUBLIC ${FCFS_ROOT}/inc)
target_link_libraries(fcfs PRIVATE lwrb)
target_compile_options(fcfs PRIVATE -Werror -Wall -Wextra -Wpedantic -Wshadow -Wundef -Wconversion -std=c99)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(fcfs PRIVATE -g3 -ggdb)
endif()

add_sanitizers(fcfs)
