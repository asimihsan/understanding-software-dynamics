# Add current dir as src dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/instrumentation)

add_library(instrumentation instrumentation/instrumentation.cpp)

# Define executables
add_executable(mystery0 mystery0.c)
set_target_properties(mystery0 PROPERTIES OUTPUT_NAME "mystery0")
target_link_libraries(mystery0 PRIVATE instrumentation)

add_executable(mystery0_opt mystery0.c instrumentation/instrumentation.cpp)
target_compile_options(mystery0_opt PRIVATE -O2)
set_target_properties(mystery0_opt PROPERTIES OUTPUT_NAME "mystery0_opt")
target_link_libraries(mystery0_opt PRIVATE instrumentation)

add_executable(mystery0_unroll mystery0_unroll.c instrumentation/instrumentation.cpp)
set_target_properties(mystery0_unroll PROPERTIES OUTPUT_NAME "mystery0_unroll")
target_link_libraries(mystery0_unroll PRIVATE instrumentation)

add_executable(mystery0_unroll2 mystery0_unroll2.c instrumentation/instrumentation.cpp)
set_target_properties(mystery0_unroll2 PROPERTIES OUTPUT_NAME "mystery0_unroll2")
target_link_libraries(mystery0_unroll2 PRIVATE instrumentation)

add_executable(mystery0_unroll2_sums mystery0_unroll2_sums.c instrumentation/instrumentation.cpp)
set_target_properties(mystery0_unroll2_sums PROPERTIES OUTPUT_NAME "mystery0_unroll2_sums")
target_link_libraries(mystery0_unroll2_sums PRIVATE instrumentation)
