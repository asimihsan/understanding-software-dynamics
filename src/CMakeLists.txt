# Add current dir as src dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define executables
add_executable(mystery0 mystery0.cpp)

# Specify target properties if needed
set_target_properties(mystery0 PROPERTIES OUTPUT_NAME "mystery0")

# Define optimized executable
add_executable(mystery0_opt mystery0.cpp)
target_compile_options(mystery0_opt PRIVATE -O2)

# Specify target properties for the optimized executable
set_target_properties(mystery0_opt PROPERTIES OUTPUT_NAME "mystery0_opt")
