cmake_minimum_required(VERSION 3.20)
project(malloc_world C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")

set(CMAKE_C_STANDARD 99)

include_directories(
        src/include
        )


add_executable(malloc_world
        src/inventory.c
        src/battles.c
        src/items.c
        src/player.c
        src/save.c
        src/map.c
        src/move.c
        src/cli.c
        src/main.c
        src/monsters.c
        src/pnj.c
        src/structures.c
        )

