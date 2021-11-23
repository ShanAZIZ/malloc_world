cmake_minimum_required(VERSION 3.20)
project(malloc_world C)

set(CMAKE_C_STANDARD 99)



include_directories(src/inventory
        src/map
        src/player
        src/items
        src/save
        src/move
        src/cli
        src/include
        src/monsters
        src/battles
        )


add_executable(malloc_world
        src/inventory/inventory.c
        src/battles/battles.c
        src/items/items.c
        src/player/player.c
        src/save/save.c
        src/map/map.c
        src/move/move.c
        src/cli/cli.c
        src/main.c
        src/monsters/monsters.c)

