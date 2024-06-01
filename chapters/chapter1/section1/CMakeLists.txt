project(Chapter1Section1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SOURCES "*.c")

add_executable(chapter1_section1 ${SOURCES})

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    add_compile_definitions(__x86_64__)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    add_compile_definitions(__aarch64__)
endif
