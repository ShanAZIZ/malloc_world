cmake_minimum_required(VERSION 3.20)
project(malloc_world C)

set(CMAKE_C_STANDARD 99)

include_directories(src/map)

add_executable(malloc_world
        src/map/map.c
        src/main.c)
