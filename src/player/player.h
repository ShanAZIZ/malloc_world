#include <stdio.h>
#include <stdlib.h>
#include "../inventory/inventory.h"

#ifndef MALLOC_WORLD_PLAYER_H
#define MALLOC_WORLD_PLAYER_H

/**
 * Struct Player
 */
typedef struct Player {
    int current_xp;
    int level;
    int current_hp;
    Inventory* inventory;
} Player;

/**
 * Initialise un joueur de debut de partie
 * @return
 */
Player* initPlayer(Item**);
Inventory* getInventory(Player* player);

#endif