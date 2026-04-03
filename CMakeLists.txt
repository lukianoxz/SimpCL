cmake_minimum_required(VERSION 3.10)

project(SimpCL)

set(COMPILE_TARGET_PATH "" CACHE STRING "Type here the path to file to compile: ")
set(COMPILE_TARGET "" CACHE STRING "Type here the file to compile: ")

add_library(simpcl STATIC
    src/vector.c
    src/string.c
    src/map.c
)

target_include_directories(simpcl PUBLIC include)

add_executable(Executable ${COMPILE_TARGET_PATH}${COMPILE_TARGET}.c)

target_link_libraries(Executable PRIVATE simpcl)