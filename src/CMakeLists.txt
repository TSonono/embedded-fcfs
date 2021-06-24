
# Build dependencies (lwrb)
add_library(lwrb ${LWRB_DIR}/src/lwrb/lwrb.c)
target_include_directories(lwrb PUBLIC ${LWRB_DIR}/src/include)
add_sanitizers(lwrb)

add_library(fcfs fcfs.c)
target_include_directories(fcfs PUBLIC ${CMAKE_SOURCE_DIR}/inc)
target_link_libraries(fcfs PRIVATE lwrb)
target_compile_options(fcfs PRIVATE -Werror -Wall -Wextra -Wpedantic -Wshadow -Wundef -Wconversion -std=c99)
add_sanitizers(fcfs)
