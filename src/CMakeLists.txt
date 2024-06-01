# Add current dir as src dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define executables
add_executable(mystery0 mystery0.cpp)
set_target_properties(mystery0 PROPERTIES OUTPUT_NAME "mystery0")

add_executable(mystery0_opt mystery0.cpp)
target_compile_options(mystery0_opt PRIVATE -O2)
set_target_properties(mystery0_opt PROPERTIES OUTPUT_NAME "mystery0_opt")
