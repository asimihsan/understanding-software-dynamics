cmake_minimum_required(VERSION 3.10)
project(MyCProject VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(my_c_project ${SOURCES})

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    add_compile_definitions(__x86_64__)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    add_compile_definitions(__aarch64__)
endif
