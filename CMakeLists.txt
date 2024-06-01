cmake_minimum_required(VERSION 3.28)
project(UnderstandingSoftwareDynamics CXX)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories for source files
add_subdirectory(src)
