cmake_minimum_required(VERSION 3.20)
project(malloc_world C)

set(CMAKE_C_STANDARD 99)


include_directories(src/inventory
        src/map
        src/player
        src/items
        src/save
        )


add_executable(malloc_world
        src/inventory/inventory.c
        src/items/items.c
        src/player/player.c
        src/map/map.c
        src/main.c
        src/save/save.c
        )
