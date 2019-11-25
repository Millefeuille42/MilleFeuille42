cmake_minimum_required(VERSION 3.13)
project(get_next_line)

set(GCC_COVERAGE_COMPILE_FLAGS "-D BUFFER_SIZE=17")
set(CMAKE_CXX_STANDARD 14)

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_executable(get_next_line get_next_line.c get_next_line_utils.c)