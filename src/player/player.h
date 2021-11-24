#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

#ifndef MALLOC_WORLD_PLAYER_H
#define MALLOC_WORLD_PLAYER_H
#endif

/**
 * Struct Player
 */


/**
 * Initialise un joueur de debut de partie
 * @return
 */
Player* initPlayer(Item**);
Inventory* getInventory(Player* player);