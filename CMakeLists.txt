cmake_minimum_required(VERSION 3.28)
project(MyC17Project C)

set(CMAKE_C_STANDARD 17)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories for source files
add_subdirectory(src)
