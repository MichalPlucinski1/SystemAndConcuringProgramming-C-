cmake_minimum_required(VERSION 3.26)
project(lab5 C)

set(CMAKE_C_STANDARD 17)

add_executable(lab5 main.c
        semaphor.cpp)
add_executable(new_target semaphor.cpp)
