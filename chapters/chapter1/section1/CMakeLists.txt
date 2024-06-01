
cmake_minimum_required(VERSION 3.10)
project(Chapter1Section1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SOURCES "*.c")

add_executable(chapter1_section1 ${SOURCES})

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    add_compile_definitions(__x86_64__)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    add_compile_definitions(__aarch64__)
endif

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SOURCES "*.c")

add_executable(chapter1_section1 ${SOURCES})

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    add_compile_definitions(__x86_64__)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    add_compile_definitions(__aarch64__)
endif
