cmake_minimum_required(VERSION 3.20)
project(malloc_world C)

set(CMAKE_C_STANDARD 11)

include_directories(src/items)
include_directories(src/player)

add_executable(malloc_world
        src/inventory/inventory.c
        src/inventory/inventory.h
        src/items/items.c
        src/items/items.h
        src/player/player.c
        src/player/player.h
        src/main.c
        src/pnj/pnj.c
        src/pnj/pnj.h
        )
