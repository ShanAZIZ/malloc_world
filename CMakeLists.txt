cmake_minimum_required(VERSION 3.20)
project(malloc_world C)

set(CMAKE_C_STANDARD 99)


include_directories(src/inventory)


add_executable(malloc_world
        src/inventory/inventory.c
        src/inventory/inventory.h
        src/battles/battles.c
        src/battles/battles.h
        src/items/items.c
        src/items/items.h
        src/player/player.c
        src/player/player.h
        src/map/map.c
        src/main.c src/move/move.h src/move/move.c)

        src/monsters/monsters.c
        src/monsters/monsters.h