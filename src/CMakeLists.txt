
# Build dependencies (lwrb)
add_library(lwrb ${LWRB_DIR}/src/lwrb/lwrb.c)
target_include_directories(lwrb PRIVATE ${LWRB_DIR}/src/include)
