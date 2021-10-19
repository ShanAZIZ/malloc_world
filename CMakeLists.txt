cmake_minimum_required(VERSION 3.20)
project(malloc_world C)

set(CMAKE_C_STANDARD 11)

include_directories(src/items)
include_directories(src/player)

add_executable(malloc_world
        src/items/items.c
        src/player/player.c
        src/main.c src/pnj/pnj.c)
