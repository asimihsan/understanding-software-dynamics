cmake_minimum_required(VERSION 3.8)
project(UnderstandingSoftwareDynamics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories for source files
add_subdirectory(src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
