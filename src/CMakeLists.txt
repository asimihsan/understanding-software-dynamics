# Add current dir as src dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define executables
add_executable(main main.c)

# Specify target properties if needed
set_target_properties(main PROPERTIES OUTPUT_NAME "main")
