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
    Inventory* inventory;
    int posX;
    int posY;
    int mapId;
} Player;


/**
 * Initialise un joueur de debut de partie
 * @return
 */

Player* initPlayer(Item**);
Inventory* getInventory(Player* player);

