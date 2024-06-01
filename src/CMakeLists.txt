# Add current dir as src dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(instrumentation instrumentation.cpp)

# Define executables
add_executable(mystery0 mystery0.c)
set_target_properties(mystery0 PROPERTIES OUTPUT_NAME "mystery0")
target_link_libraries(mystery0 PRIVATE instrumentation)

add_executable(mystery0_opt mystery0.c instrumentation.cpp)
target_compile_options(mystery0_opt PRIVATE -O2)
set_target_properties(mystery0_opt PROPERTIES OUTPUT_NAME "mystery0_opt")
target_link_libraries(mystery0_opt PRIVATE instrumentation)
