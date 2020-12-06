cmake_minimum_required(VERSION 3.19)
project(new C)

set(CMAKE_C_STANDARD 99)

add_executable(new get_next_line.c get_next_line.h main.c get_next_line_utils.c)