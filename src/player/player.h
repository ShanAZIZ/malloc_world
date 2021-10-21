#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

#ifndef MALLOC_WORLD_PLAYER_H
#define MALLOC_WORLD_PLAYER_H
#endif

/**
 * Struct Player
 */
typedef struct Player {
    int current_xp;
    int level;
    int current_hp;
    inventory* inventory;
} player;

/**
 * Initialise un joueur de debut de partie
 * @return
 */
player* initPlayer(item**);
inventory* getInventory(player* player);