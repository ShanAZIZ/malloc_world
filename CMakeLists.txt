cmake_minimum_required(VERSION 3.16.3)
project(malloc_world C)

set(CMAKE_C_STANDARD 99)

include_directories(src/items)

add_executable(malloc_world
        src/inventory/inventory.c
        src/inventory/inventory.h
        src/items/items.c
        src/items/items.h
        src/player/player.c
        src/player/player.h
        src/pnj/pnj.c
        src/pnj/pnj.h
        src/main.c
        )
