cmake_minimum_required(VERSION 3.10)

project(SimpCL)

add_library(simpcl STATIC
    src/vector.c
    src/string.c
)

target_include_directories(simpcl PUBLIC include)

add_executable(Executable tests/vector_test.c)

target_link_libraries(Executable PRIVATE simpcl)