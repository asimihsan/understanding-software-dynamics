# Add current dir as src dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define executables
add_executable(mystery0 mystery0.cc)

# Specify target properties if needed
set_target_properties(mystery0 PROPERTIES OUTPUT_NAME "mystery0")
